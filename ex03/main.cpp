/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:29:58 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/12 08:31:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "src/class/Point.class.hpp"

void runTest(
    const Point& a, const Point& b, const Point& c, const Point& point, const std::string& testName)
{
    std::cout << "\n===== " << testName << " =====" << std::endl;
    std::cout << "Triangle vertices:" << std::endl;
    std::cout << "A: {" << a.getX() << ", " << a.getY() << "}" << std::endl;
    std::cout << "B: {" << b.getX() << ", " << b.getY() << "}" << std::endl;
    std::cout << "C: {" << c.getX() << ", " << c.getY() << "}" << std::endl;

    std::cout << "Point to check: {" << point.getX() << ", " << point.getY() << "}" << std::endl;

    bool isInside = bsp(a, b, c, point);
    std::cout << "Result: The point is " << (isInside ? "INSIDE" : "OUTSIDE") << " the triangle."
              << std::endl;
}

int main(void)
{
    // Define the vertices of the triangle for all tests
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    // Test 1: Point clearly inside the triangle
    Point inside(2.5f, 2.5f);
    runTest(a, b, c, inside, "Test 1: Point Inside Triangle");

    // Test 2: Point clearly outside the triangle
    Point outside(6.0f, 6.0f);
    runTest(a, b, c, outside, "Test 2: Point Outside Triangle");

    // Test 3: Point on an edge of the triangle
    Point onEdge(2.5f, 0.0f);  // Point on the edge between A and B
    runTest(a, b, c, onEdge, "Test 3: Point On Edge");

    // Test 4: Point at a vertex of the triangle
    Point atVertex(0.0f, 0.0f);  // Point at vertex A
    runTest(a, b, c, atVertex, "Test 4: Point At Vertex");

    // Test 5: Point very close to an edge but still inside
    Point closeToEdge(2.5f, 0.1f);  // Very close to the edge between A and B
    runTest(a, b, c, closeToEdge, "Test 5: Point Close To Edge");

    return (0);
}
