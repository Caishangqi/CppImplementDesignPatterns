#include "Logger.hpp"
/**
* Client Code: Logger Singleton Usage
 *
 * The desired Log Level is set which also instantiates the Logger class; the
 * log() methods can then be invoked e.g. via lambdas within different threads.
 */
int main(int argc, char* argv[])
{
    std::cout << "// // Logger Singleton ////\n";
    Logger::level(Logger::Level::Info);
    std::thread t1(
        [] { Logger::log("This is just a simple development check."); });
    std::thread t2(
        [] { Logger::log("Here are some extra details.", Logger::Level::Info); });
    std::thread t3([]
    {
        Logger::log("Be careful with this potential issue.",
                    Logger::Level::Warn);
    });
    std::thread t4([]
    {
        Logger::log("A major problem has caused a fatal stoppage.",
                    Logger::Level::Error);
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return EXIT_SUCCESS;
}
