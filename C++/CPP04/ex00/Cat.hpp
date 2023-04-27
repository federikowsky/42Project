/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:37:57 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:38:35 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string.h>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{

public:
    Cat();
    Cat &operator=(const Cat &stats);
    void makeSound(void) const;
    Cat(const Cat &copy);
    ~Cat();
};

#endif