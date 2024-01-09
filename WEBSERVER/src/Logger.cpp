#include "../include/Logger.hpp"

void logMsg(const char *color, const char *msg, ...)
{
    char output[8192];
    va_list args;
    va_start(args, msg);
    vsnprintf(output, 8192, msg, args);
    if (!strcmp(color, RED))
        std::cerr << color << output << "\nerrno: " << errno << " - " << strerror(errno) << RESET << std::endl;
    else
        std::cout << color << output << RESET << std::endl;
    va_end(args);
}