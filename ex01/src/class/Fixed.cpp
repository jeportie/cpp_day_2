/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:05:40 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/11 07:46:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <sstream>
#include <cmath>
#include "Fixed.hpp"

/* ~~~~ CONSTRUCTORS / DESTRUCTOR ~~~~ */
Fixed::Fixed(void)
: _result(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_result = value << _fractBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_result = roundf(value * (1 << _fractBits));
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

// Overloaded assignement operator
Fixed& Fixed::operator=(Fixed const& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_result = rhs.getRawBits();
    return (*this);
}

/* ~~~~ CLASS METHODS ~~~~ */

int Fixed::getRawBits(void) const { return this->_result; }

void Fixed::setRawBits(int const raw) { this->_result = raw; }

float Fixed::toFloat(void) const
{
	float recasted = (float)this->_result;

	return (recasted / (1 << _fractBits));
}

int Fixed::toInt(void) const { return (this->_result >> _fractBits); }

// Serialise the Fixed object as a string
std::string Fixed::toString(void) const
{
    std::ostringstream oss;
    oss << "Fixed(_result=" << _result << ",value=" << toFloat() << ")";
    return (oss.str());
}

// Overload operator<< to output the value as float.
std::ostream& operator<<(std::ostream& out, Fixed const& in)
{
    out << in.toFloat();
    return (out);
}
