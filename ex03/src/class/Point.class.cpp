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
	std::cout << "Default Point constructor called" << std::endl;
	return;
}

Point::Point(float const x, float const y)
: _x(x)
, _y(y)
{
	std::cout << "Parametric Point constructor called" << std::endl;
	return;
}

Point::Point(Point const& src)
{
	std::cout << "Copy Point constructor called" << std::endl;
	*this = src;
	return;
}

Point::~Point(void)
{
	std::cout << "Point destructor called" << std::endl;
	return;
}

Point & Point::operator=(Point const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & out, Point const & in)
{
	out << "The value of _x is : " << in.getX();
	out << "The value of _y is : " << in.getY();
	return (out);
}

int Point::getX(void) const { return (_x); }
int Point::getY(void) const { return (_y); }

std::string Point::toString(void) const
{
	std::ostringstream oss;
	oss << "Point(_x=" << _x << "_y=" << _y << " )";
	return (oss.str());
}
