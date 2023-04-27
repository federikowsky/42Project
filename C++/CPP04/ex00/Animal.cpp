/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:37:53 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:38:42 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called " << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
}

std::string Animal::getType(void) const
{
    return this->type;
}

Animal &Animal::operator=(const Animal &stats)
{
    this->type = stats.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called " << std::endl;
}

void Animal::makeSound() const
{

    std::cout << "strange verse" << std::endl;
}