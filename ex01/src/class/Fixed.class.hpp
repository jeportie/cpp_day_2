/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:05:55 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/11 07:33:16 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
public:
	// Default and copy constructors
	Fixed(void);
	Fixed(Fixed const & src);

	// Int and float constructors
	Fixed(const int value);
	Fixed(const float value);

	~Fixed(void);

	Fixed & operator=(Fixed const & rhs);

	// Getter and Setter for the raw bits.
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Conversion methods
	float	toFloat(void) const;
	int		toInt(void) const;

	// Serialisation as string
	std::string	toString(void) const; // serialise class to string

private:
	int					_result;
	static const int	_fractBits = 8;
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream & out, Fixed const & in);

#endif  // ************************************************** FIXED_CLASS_HPP //
