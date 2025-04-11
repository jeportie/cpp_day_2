/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:32:56 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/11 16:58:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Point.class.hpp"

// Function to calculate the area of a triangle given its vertices
static Fixed calculateArea(const Point& p1, const Point& p2, const Point& p3)
{
    return Fixed(0.5f)	* ((p1.getX() * (p2.getY() - p3.getY()))
						+ (p2.getX() * (p3.getY() - p1.getY()))
						+ (p3.getX() * (p1.getY() - p2.getY())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Calculate the area of the main triangle
    Fixed areaABC = calculateArea(a, b, c);

    // Calculate the area of the triangles formed with the point
    Fixed areaPAB = calculateArea(point, a, b);
    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaPCA = calculateArea(point, c, a);

    // Check if the point is inside the triangle
    if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
        return false; // Point is on the edge or vertex

    return (areaABC == (areaPAB + areaPBC + areaPCA));
}
