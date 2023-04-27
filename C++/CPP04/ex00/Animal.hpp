/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:37:51 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:46:58 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string.h>
#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    std::string getType(void) const;
    virtual void makeSound(void) const;
    Animal();
    Animal(std::string name);
    Animal &operator=(const Animal &stats);
    Animal(const Animal &copy);
    virtual ~Animal();
};

#endif