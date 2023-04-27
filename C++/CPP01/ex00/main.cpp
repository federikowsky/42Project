/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:12:27 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/16 17:29:43 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string name;

    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;
    Zombie zombi1(name);
    zombi1.announce();

    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;
    Zombie *zombie1 = new Zombie(name);
    zombie1->announce();
    delete zombie1;
    randomChump("ZombieRandom");

    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;
    Zombie *zombie2 = newZombie(name);
    zombie2->announce();
    delete zombie2;

    return (0);
}
