/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:27:56 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:28:13 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(FragTrap const &src);
    ~FragTrap(void);
    FragTrap &operator=(FragTrap const &src);
    void attack(std::string const &target);
    void highFivesGuys(void);
};

#endif