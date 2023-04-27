/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:37:55 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:38:38 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << this->type << " constructor called " << std::endl;
}

Cat::Cat(const Cat &copy)
{
    *this = copy;
}

Cat &Cat::operator=(const Cat &stats)
{
    this->type = stats.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << this->type << " destructor called " << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meoow" << std::endl;
}