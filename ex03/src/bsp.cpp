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

/*
 * Calculate the area of a triangle using the formula:
 * Area = 1/2 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
 * This is derived from the cross product and gives the area of the triangle.
 */
static Fixed calculateArea(const Point& p1, const Point& p2, const Point& p3)
{
    // Use toFloat() to avoid precision issues with Fixed-point arithmetic
    float x1 = p1.getX().toFloat();
    float y1 = p1.getY().toFloat();
    float x2 = p2.getX().toFloat();
    float y2 = p2.getY().toFloat();
    float x3 = p3.getX().toFloat();
    float y3 = p3.getY().toFloat();
    
    // Calculate each part of the formula separately for clarity
    float part1 = x1 * (y2 - y3);
    float part2 = x2 * (y3 - y1);
    float part3 = x3 * (y1 - y2);
    
    // Calculate the area using floating-point arithmetic for better precision
    float floatArea = 0.5f * (part1 + part2 + part3);
    
    // Take the absolute value
    if (floatArea < 0)
        floatArea = -floatArea;
    
    // Convert back to Fixed
    Fixed area(floatArea);
    std::cout << "area = " << area << std::endl;
    
    return area;
}

/*
 * BSP (Binary Space Partitioning) function to determine if a point is inside a triangle.
 * 
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

    std::cout << "areaABC = " << areaABC << std::endl;
    
    // If the main triangle has zero area, it's not a valid triangle
    if (areaABC == Fixed(0))
        return false;
    
    // Calculate the areas of the three triangles formed with the point
    Fixed areaPAB = calculateArea(point, a, b);
    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaPCA = calculateArea(point, c, a);

    // If any of the areas is zero, the point is on an edge
    if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
        return false;
    
    // Calculate the sum of the three areas
    Fixed sumAreas = areaPAB + areaPBC + areaPCA;
    std::cout << "sumAreas = " << sumAreas << std::endl;
    
    // Due to floating-point precision, we need to check if the difference is very small
    // rather than checking for exact equality
    Fixed diff = sumAreas - areaABC;
    if (diff < Fixed(0))
        diff = diff * Fixed(-1); // Take absolute value
    
    std::cout << "areaPAB = " << areaPAB << std::endl;
    std::cout << "areaPBC = " << areaPBC << std::endl;
    std::cout << "areaPCA = " << areaPCA << std::endl;
    std::cout << "diff = " << diff << std::endl;
    
    // The point is inside if the sum of the three areas is approximately equal to the main area
    // Using a small epsilon value for comparison
    return (diff < Fixed(0.01f));
}
