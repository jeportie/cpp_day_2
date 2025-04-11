/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:44:33 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/11 13:44:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

# include <iostream>

class Point
{
public:
	Point(void);
	Point(int const fooNb);
	Point(Point const & src);
	~Point(void);

	Point & operator=(Point const & rhs);

	int getFoo(void) const;
	std::string toString(void) const; // serialise class to string

private:
	int _foo;
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream & out, Point const & in);

#endif  // ************************************************** POINT_CLASS_HPP //
