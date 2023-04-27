/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:38:17 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 19:38:17 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string.h>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
    WrongCat();
    WrongCat &operator=(const WrongCat &stats);
    WrongCat(const WrongCat &copy);
    ~WrongCat();
};

#endif