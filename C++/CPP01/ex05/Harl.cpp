/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:40:06 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 17:31:19 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "DEBUG" << std::endl;
}

void Harl::info( void )
{
    std::cout << "INFO" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "WARNING" << std::endl;
}

void Harl::error( void )
{
    std::cout << "ERROR" << std::endl;
}

void Harl::complain( std::string level )
{
    void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"debug", "info", "warning", "error"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            (this->*f[i])();
    }
}

