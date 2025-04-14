/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:21:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/12 10:21:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Fixed.hpp"
#include "class/Point.hpp"

static Fixed fxAbs(Fixed value) { return ((value < 0) ? value * Fixed(-1): value); }

static Fixed calculateArea(const Point& p1, const Point& p2, const Point& p3)
{
    Fixed part1 = p1.getX() * (p2.getY() - p3.getY());
    Fixed part2 = p2.getX() * (p3.getY() - p1.getY());
    Fixed part3 = p3.getX() * (p1.getY() - p2.getY());
    Fixed area = Fixed(0.5f) * (part1 + part2 + part3);
    return (fxAbs(area));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Calculate the area of the main triangle
    Fixed areaABC = calculateArea(a, b, c);
    std::cout << "Main triangle area = " << areaABC << std::endl;
    if (areaABC == Fixed(0))
    {
        std::cout << "Main triangle has zero area" << std::endl;
        return false;
    }
    // Calculate the areas of the three triangles formed with the point
    Fixed areaPAB = calculateArea(point, a, b);
    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaPCA = calculateArea(point, c, a);
    if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
    {
        std::cout << "Point is on an edge or vertex" << std::endl;
        return false;
    }
    Fixed sumAreas = areaPAB + areaPBC + areaPCA;

    Fixed diff = fxAbs(sumAreas - areaABC);
    std::cout << "Difference = " << diff << std::endl;
    // Using a small epsilon value for comparison
    bool isInside = (diff < Fixed(0.1f));
    return isInside;
}
