#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdarg.h>
#include <string.h>

#define ORANGE  "\x1b[38;5;208m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define GREY    "\x1B[90m"

void logMsg(const char *color, const char *msg, ...);

#endif