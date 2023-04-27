#ifndef CAT_HPP
#define CAT_HPP

#include <string.h>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat &operator=(const Cat &stats);
        void            makeSound(void) const;
        Cat(const Cat &copy);
        ~Cat();

};

#endif