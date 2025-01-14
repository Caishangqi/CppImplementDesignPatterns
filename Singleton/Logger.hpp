#pragma once
#include <mutex>
#include <iostream>
/**
 * The Logger Singleton Class
 *
 * In this (zero handle objects) implementation of the Scott Meyers' Singleton,
 * the constructor and destructor are private methods and the move/copy
 * constructors and assignment operations are explicitly deleted. In essence,
 * the program itself cannot directly create an instance of the Logger class,
 * and instead the static instance() member function must be used to access it.
 *
 * The public API of this Logger has two main callbacks: (1) set the level of
 * the Logger; and (2) log a message at given level. For convenience, these two
 * client-facing methods wrap around the instance() member function in a thread-
 * safe fashion. An integral counter member is also included to demonstrate that
 * the message ordering is preserved.
 *
 * Note the final keyword specifier prevents inheritance, that is, it is not
 * possible to extend this Logger Singleton and override its class methods.
 */
class Logger final
{
public:
    /**
     * Various levels for the log messages can be labelled here; the choice of the
     * level member establishes a threshold below which log messages are ignored.
     */
    enum class Level: unsigned
    {
        Debug = 0,
        Info = 1,
        Warn = 2,
        Error = 3,
        /* ... */
    };

public:
    /**
     * The Public API of this Logger
     *
     * Note that both of these methods must be implemented in a thread-safe
     * manner, hence the mutex as a static member.
     */
    static void level(Level);
    static void log(std::string const&, Level level = Level::Debug);

public:
    /**
     * Prevention of Copy and Move Construction
     */
    Logger(Logger const&) = delete;
    Logger(Logger&&)      = delete;

    /**
     * Prevention of Copy and Move Assigment Operations
     */
    Logger& operator=(Logger const&) = delete;
    Logger& operator=(Logger&&)      = delete;

    /**
     * Public Instantiator Method
     *
     * In a typical Singleton, this static member function would enable access to
     * the Singleton. In this implementation of a Logger class, it is called
     * inside of the bodies of the public API methods.
     */
    static Logger& instance();

private:
    /**
     * Private Constructor and Destructor
     */
    Logger();
    ~Logger();

private:
    static std::mutex    m_mutex;
    static std::ostream& m_os;
    static std::size_t   m_count;
    static Level         m_level;
};

/**
 * Enumeration-to-String Helper Function
 *
 * This implementation is naive but nonetheless useful for distinguishing the
 * different kinds of log messages.
 */
inline std::string to_string(Logger::Level level)
{
    switch (level)
    {
    case Logger::Level::Debug:
        return "[DEBUG]";
    case Logger::Level::Info:
        return "[INFO]";
    case Logger::Level::Warn:
        return "[WARNING]";
    case Logger::Level::Error:
        return "[ERROR]";
    /* ... */
    default:
        return "[LEVEL]";
    }
}
