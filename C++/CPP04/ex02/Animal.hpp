#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string.h>
#include <iostream>

class Animal
{
    protected:
        std::string type;
        
    public:
        std::string     getType(void) const;
        virtual void            makeSound(void) const = 0;
        Animal();
        Animal(std::string name);
        Animal    &operator=(const Animal &stats);
        Animal(const Animal &copy);
        virtual ~Animal();

};

#endif