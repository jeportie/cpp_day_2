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
#include <cmath>
#include "Fixed.class.hpp"

/* ~~~~ CONSTRUCTORS / DESTRUCTOR ~~~~ */
Fixed::Fixed(void)
: _result(0)
{
	if (LOGS)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src)
{
	if (LOGS)
		std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int value)
{
	if (LOGS)
		std::cout << "Int constructor called" << std::endl;
    this->_result = value << _fractBits;
}

Fixed::Fixed(const float value)
{
	if (LOGS)
		std::cout << "Float constructor called" << std::endl;
    this->_result = roundf(value * (1 << _fractBits));
}

Fixed::~Fixed(void)
{
	if (LOGS)
		std::cout << "Destructor called" << std::endl;
}

/* ~~~~~~~~~~ ASSIGNEMENT OVERLOAD ~~~~~~~~~~ */
Fixed& Fixed::operator=(Fixed const& rhs)
{
	if (LOGS)
		std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs)
        this->_result = rhs.getRawBits();
    return (*this);
}

/* ~~~~~~~~~~ COMPARISON OVERLOADS ~~~~~~~~~~ */
bool Fixed::operator>(Fixed const& rhs) const
{
	if (LOGS)
		std::cout << "Is bigger than operator called" << std::endl;
    return (this->_result > rhs._result);
}

bool Fixed::operator<(Fixed const& rhs) const
{
	if (LOGS)
		std::cout << "Is smaller than operator called" << std::endl;
    return (this->_result < rhs._result);
}

bool Fixed::operator>=(Fixed const& rhs) const
{
	if (LOGS)
		std::cout << "Is bigger or equal than operator called" << std::endl;
    return (this->_result >= rhs._result);
}

bool Fixed::operator<=(Fixed const& rhs) const
{
	if (LOGS)
		std::cout << "Is smaller or equal than operator called" << std::endl;
    return (this->_result <= rhs._result);
}

bool Fixed::operator==(Fixed const& rhs) const
{
	if (LOGS)
		std::cout << "Is equal operator called" << std::endl;
    return (this->_result == rhs._result);
}

bool Fixed::operator!=(Fixed const& rhs) const
{
	if (LOGS)
		std::cout << "Is not equal operator called" << std::endl;
    return (this->_result != rhs._result);
}

/* ~~~~~~~~~~ ARITHMETIC OVERLOADS ~~~~~~~~~~ */
Fixed Fixed::operator+(Fixed const& rhs) const
{
    Fixed result;

	if (LOGS)
		std::cout << "Addition operator called" << std::endl;
    result._result = this->_result + rhs._result;
    return (result);
}

Fixed Fixed::operator-(Fixed const& rhs) const
{
    Fixed result;

	if (LOGS)
		std::cout << "Substraction operator called" << std::endl;
    result._result = this->_result - rhs._result;
    return (result);
}

Fixed Fixed::operator*(Fixed const& rhs) const
{
    Fixed result;

	if (LOGS)
		std::cout << "Multiplication operator called" << std::endl;
    result._result = (this->_result * rhs._result) / (1 << _fractBits);
    return (result);
}

Fixed Fixed::operator/(Fixed const& rhs) const
{
    Fixed result;

	if (LOGS)
		std::cout << "Divions operator called" << std::endl;
    if (rhs._result == 0)
    {
        std::cerr << "Division by zero!" << std::endl;
        return (Fixed());
    }
    result._result = (this->_result << _fractBits) / rhs._result;
    return (result);
}

/* ~~~~~~~~~~ INC/DECREMENTATION OVERLOADS ~~~~~~~~~~ */
Fixed& Fixed::operator++(void)
{
	if (LOGS)
		std::cout << "Pre_increment operator called" << std::endl;
    ++this->_result;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp;

	if (LOGS)
		std::cout << "Post_increment operator called" << std::endl;
    tmp = *this;
    ++this->_result;
    return (tmp);
}

Fixed& Fixed::operator--(void)
{
	if (LOGS)
		std::cout << "Pre_decrement operator called" << std::endl;
    --this->_result;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp;

	if (LOGS)
		std::cout << "Post_decrement operator called" << std::endl;
    tmp = *this;
    --this->_result;
    return (tmp);
}

/* ~~~~ CLASS METHODS ~~~~ */
int Fixed::getRawBits(void) const { return this->_result; }

void Fixed::setRawBits(int const raw) { this->_result = raw; }

float Fixed::toFloat(void) const { return (static_cast<float>(this->_result) / (1 << _fractBits)); }

int Fixed::toInt(void) const { return this->_result >> _fractBits; }

/* ~~~~ SURCHARGED MEMBER METHODS ~~~~ */
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a._result < b._result) ? a : b; }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a._result < b._result) ? a : b; }

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a._result > b._result) ? a : b; }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a._result > b._result) ? a : b; }

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
