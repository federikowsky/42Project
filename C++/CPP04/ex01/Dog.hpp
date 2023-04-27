#ifndef DOG_HPP
#define DOG_HPP

#include <string.h>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:

        Dog();
        Dog(std::string name);
        Dog    &operator=(const Dog &stats);
        void            makeSound(void) const;
        Dog(const Dog &copy);
        ~Dog();

};

#endif