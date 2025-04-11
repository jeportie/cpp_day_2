/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:40:48 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/11 16:41:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "src/class/Point.class.hpp"

int main(void)
{
    // Define the vertices of the triangle
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    // Define the point to check
    Point point(2.5f, 2.0f);

    // Check if the point is inside the triangle
    bool isInside = bsp(a, b, c, point);

    // Output the result
    std::cout << "The point is " << (isInside ? "inside" : "outside") << " the triangle." << std::endl;

	return (0);
}
