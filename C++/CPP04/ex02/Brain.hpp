#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string.h>
#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(std::string name);
        Brain    &operator=(const Brain &stats);
        Brain(const Brain &copy);
        ~Brain();

};

#endif