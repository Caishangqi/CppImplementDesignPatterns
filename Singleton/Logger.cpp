#include "Logger.hpp"
#include <string>
/**
 * Static members of the Logger class need to be defined outside of the class
 * itself.
 */
std::mutex    Logger::m_mutex;
std::ostream& Logger::m_os{std::cout};
std::size_t   Logger::m_count{0};
Logger::Level Logger::m_level{Logger::Level::Debug};

void Logger::level(Logger::Level level)
{
    std::lock_guard<std::mutex> lock(Logger::m_mutex);
    instance().m_level = level;
}


/**
 * Thread-Safe Log Method
 *
 * If the message level is at or above the threshold level of the Logger
 * Singleton, then the counter is incremented and the message is printed.
 * Otherwise, the message is ignored and the counter remains as is.
 *
 * Note again the usage of RAII for mutex locking/unlocking should this method
 * be called in a thread.
 */
void Logger::log(std::string const& message, Level level)
{
    std::lock_guard<std::mutex> lock(Logger::m_mutex);
    if (static_cast<int>(level) < static_cast<int>(instance().m_level))
        return;
    instance().m_os << ++instance().m_count << '\t' << to_string(level) << "\n\t" << message << '\n';
}

/**
 * c.f. Scott Meyers' Singleton
 *
 * The instance() method creates a local static instance of the Logger class,
 * which is guaranteed thread-safe initialisation without manual thread
 * synchronisation. Note that this does not guarantee the thread safety of other
 * members; the RAII (Resource Acquistion Is Initialisation) principle should be
 * used to lock and unlock the mutex.
 *
 * Note that there will be a performance penalty each time this method is called
 * as there will be a check to see if the instance has already been initialised.
 */
Logger& Logger::instance()
{
    static Logger instance;
    return instance;
}

Logger::Logger()
{
    std::cout << "****\tLOGGER\tSTART UP\t****" << '\n';
}

Logger::~Logger()
{
    std::cout << "****\tLOGGER\tSHUT DOWN\t****" << '\n';
}
