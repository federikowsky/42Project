/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:08:24 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 15:45:28 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string.h>
#include <iostream>

class Zombie
{
private:
    std::string _name;

public:
    Zombie(std::string name);
    Zombie();
    ~Zombie();
    void announce(void);
    void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif