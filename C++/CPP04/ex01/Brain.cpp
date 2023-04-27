#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain costructor called " << std::endl;
}


Brain::Brain(const Brain &copy)
{
    *this = copy;
}

Brain &Brain::operator=( const Brain &stats )
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = stats.ideas[i];
    return (*this);
}

Brain:: ~Brain()
{
    std::cout << "Brain Destructor called " << std::endl;
}
