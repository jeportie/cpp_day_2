/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:44:44 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/11 13:44:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <ostream>
# include <sstream>
# include "Point.class.hpp"

Point::Point(void)
: _foo(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Point::Point(int const fooNb)
: _foo(0)
{
	std::cout << "Parametric constructor called" << std::endl;
	return;
}

Point::Point(Point const& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Point::~Point(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Point & Point::operator=(Point const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_foo = rhs.getFoo();
	return (*this);
}

std::ostream & operator<<(std::ostream & out, Point const & in)
{
	out << "The value of _foo is : " << in.getFoo();
	return (out);
}

int Point::getFoo(void) const { return (_foo); }

std::string Point::toString(void) const
{
	std::ostringstream oss;
	oss << "Point(_foo=" << _foo << ")";
	return (oss.str());
}
