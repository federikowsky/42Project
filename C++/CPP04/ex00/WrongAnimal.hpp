/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:38:11 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:38:11 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string.h>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
        
    public:
        std::string     getType(void) const;
        void            makeSound(void) const;
        WrongAnimal();
        WrongAnimal(std::string name);
        WrongAnimal    &operator=(const WrongAnimal &stats);
        WrongAnimal(const WrongAnimal &copy);
        virtual ~WrongAnimal();

};

#endif