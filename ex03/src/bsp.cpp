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

#include "class/Point.class.hpp"

static Fixed calculateArea(const Point& p1, const Point& p2, const Point& p3)
{
    // Calculate each part of the formula separately for clarity
    Fixed part1 = p1.getX() * (p2.getY() - p3.getY());
    Fixed part2 = p2.getX() * (p3.getY() - p1.getY());
    Fixed part3 = p3.getX() * (p1.getY() - p2.getY());
    
    // Sum the parts and multiply by 0.5
    Fixed area = Fixed(0.5f) * (part1 + part2 + part3);
    
    // Take the absolute value since area can't be negative
    if (area < Fixed(0))
        area = area * Fixed(-1);
    return area;
}

/*
 * BSP (Binary Space Partitioning) function to determine if a point is inside a triangle.
 * The approach:
 * 1. Calculate the area of the main triangle (a, b, c)
 * 2. Calculate the areas of three triangles formed by the point and two vertices:
 *    - Triangle (point, a, b)
 *    - Triangle (point, b, c)
 *    - Triangle (point, c, a)
 * 3. If any of these areas is zero, the point lies on an edge -> return false
 * 4. If the point is inside, the sum of these three areas equals the main triangle area
 */

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

    // Due to floating-point precision, we need to check if the difference is very small
    Fixed diff = sumAreas - areaABC;
    if (diff < Fixed(0))
        diff = diff * Fixed(-1); // Take absolute value
    std::cout << "Difference = " << diff << std::endl;

    // Using a small epsilon value for comparison
    bool isInside = (diff < Fixed(0.1f));
    return isInside;
}
