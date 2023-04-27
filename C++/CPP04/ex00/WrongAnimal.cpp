/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:38:09 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:38:09 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called " << std::endl;
}


WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
}

std::string WrongAnimal::getType(void) const
{
    return this->type;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &stats )
{
    this->type = stats.type;
    return (*this);
}

WrongAnimal:: ~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called " << std::endl;

}

void    WrongAnimal::makeSound() const
{
    if(this->getType() == "WrongCat")
    {
        std::cout << "Surely not a Meoow" << std::endl;
    }
}