/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
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
#include "Fixed.class.hpp"

Fixed::Fixed(void)
: _result(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs)
        this->_result = rhs.getRawBits();
    return (*this);
}

std::ostream& operator<<(std::ostream& out, Fixed const& in)
{
    out << "The value of _result is : " << in.getRawBits();
    return (out);
}

int Fixed::getRawBits(void) const { return this->_result; }

void Fixed::setRawBits(int const raw) { this->_result = raw; }

std::string Fixed::toString(void) const
{
    std::ostringstream oss;
    oss << "Fixed(_result=" << _result << ")";
    return (oss.str());
}
