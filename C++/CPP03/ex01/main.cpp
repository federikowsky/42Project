/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:07:59 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:08:02 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap obj("luca");
    ClapTrap obj1;
    obj1 = obj;
    obj1.attack("giovanni");
    obj1.attack("giovanni");
    obj1.attack("giovanni");
    obj1.attack("giovanni");
    obj1.attack("giovanni");
    obj1.attack("giovanni");
    obj1.attack("giovanni");
    obj1.attack("giovanni");
    obj1.beRepaired(1);
    obj1.takeDamage(11);
    obj1.attack("kaka");
    return (0);
}