/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:43:26 by fefilipp          #+#    #+#             */
/*   Updated: 2023/03/30 18:39:29 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPoint = 0;
}

Fixed::Fixed(int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = value << this->_fractionalBits;
}

Fixed::Fixed(float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = roundf(value * (1 << this->_fractionalBits));
}


Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_fixedPoint = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPoint = raw;
}

int Fixed::toInt(void) const
{
    return this->_fixedPoint >> this->_fractionalBits;
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixedPoint / (1 << this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

