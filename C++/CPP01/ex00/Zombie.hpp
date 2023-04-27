/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:08:24 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/16 17:23:43 by fefilipp         ###   ########.fr       */
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
    ~Zombie();
    void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif