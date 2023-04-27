#include "Cat.hpp"


Cat::Cat()
{
    std::cout << "Cat costructor called " << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}


Cat::Cat(const Cat &copy)
{
    *this = copy;
}



Cat &Cat::operator=( const Cat &stats )
{
    this->type = stats.type;

    this->brain = new Brain( *stats.brain );

    return (*this);
}

Cat:: ~Cat()
{
    std::cout << "Cat Destructor called " << std::endl;
    delete brain;
}

void    Cat::makeSound() const
{
        std::cout << "Meoow" << std::endl;
}