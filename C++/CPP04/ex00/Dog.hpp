/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:38:01 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:46:54 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string.h>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{

public:
    Dog();
    Dog(std::string name);
    Dog &operator=(const Dog &stats);
    void makeSound(void) const;
    Dog(const Dog &copy);
    ~Dog();
};

#endif