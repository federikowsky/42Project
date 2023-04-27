/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:07:59 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:26:09 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap obj1("simo");

    ScavTrap obj2;
    obj2 = obj1;
    obj2.attack("Alex");
    obj2.guardGate();

}