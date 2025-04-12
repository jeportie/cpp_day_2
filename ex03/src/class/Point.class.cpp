/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:44:44 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/11 16:52:55 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <ostream>
# include <sstream>
# include "Point.class.hpp"

Point::Point(void)
: _x(0)
, _y(0)
{
	if (LOGS)
		std::cout << "Default Point constructor called" << std::endl;
	return;
}

Point::Point(float const x, float const y)
: _x(x)
, _y(y)
{
	if (LOGS)
		std::cout << "Parametric Point constructor called" << std::endl;
	return;
}

Point::Point(Point const& src)
{
	if (LOGS)
		std::cout << "Copy Point constructor called" << std::endl;
	*this = src;
	return;
}

Point::~Point(void)
{
	if (LOGS)
		std::cout << "Point destructor called" << std::endl;
	return;
}

Point & Point::operator=(Point const & rhs) // Since _x and _y are const, no modif possible
{
	if (LOGS)
		std::cout << "Assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

std::ostream & operator<<(std::ostream & out, Point const & in)
{
	out << "The value of _x is : " << in.getX() << std::endl;
	out << "The value of _y is : " << in.getY() << std::endl;
	return (out);
}

Fixed Point::getX(void) const { return (_x); }
Fixed Point::getY(void) const { return (_y); }

std::string Point::toString(void) const
{
	std::ostringstream oss;
	oss << "Point(_x=" << _x << ", _y=" << _y << ")";
	return (oss.str());
}
