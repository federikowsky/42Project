/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:00:59 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 16:07:06 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string type);
    ~Weapon();

    const std::string& getType();    
    void setType(std::string type);
};

#endif