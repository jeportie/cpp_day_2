/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:44:33 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/11 16:51:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(float const x, float const y);
	Point(const Point& src);
	~Point(void);

	Point& operator=(const Point& rhs);

	Fixed getX(void) const;
	Fixed getY(void) const;

	std::string toString(void) const; // serialise class to string

private:
	Fixed const _x;
	Fixed const _y;
};

// Overload operator<< for output streaming
std::ostream& operator<<(std::ostream& out, const Point& in);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif  // ************************************************** POINT_HPP //
