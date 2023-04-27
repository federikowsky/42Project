#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

int main()
{
    Animal *obj[10];
    std::cout << " " << std::endl;
    std::cout << "  CALLING CAT CONSTRUCTION " << std::endl;
    std::cout << " " << std::endl;
    for(int i = 0; i < 10 ; i++)
    {
        if(i < 5)
            obj[i] = new Cat();
        else if (i == 5)
        {
            std::cout << " " << std::endl;
            std::cout << "  CALLING DOG CONSTRUCTION " << std::endl;
            std::cout << " " << std::endl;
            obj[i] = new Dog();
        }
        else
            obj[i] = new Dog();
    }
    std::cout << " " << std::endl;
    std::cout << "  CALLING DESTRUCTION " << std::endl;
    std::cout << " " << std::endl;
    for(int j = 0; j < 10 ; j++)
    {
        delete obj[j];
    }
    return (0);
}