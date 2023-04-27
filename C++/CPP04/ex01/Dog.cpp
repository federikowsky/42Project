#include "Dog.hpp"
Dog::Dog()
{
    std::cout << "Dog costructor called " << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}


Dog::Dog(const Dog &copy)
{
    *this = copy;
}



Dog &Dog::operator=( const Dog &stats )
{
    this->type = stats.type;

    this->brain = new Brain( *stats.brain );

    return (*this);
}

Dog:: ~Dog()
{
    std::cout << "Dog Destructor called " << std::endl;
    delete brain;
}

void    Dog::makeSound() const
{
        std::cout << "Bau" << std::endl;
}