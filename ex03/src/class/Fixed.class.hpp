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

# define LOGS 0

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

	// Assignement overload
	Fixed&	operator=(Fixed const & rhs);

	// Comparison overloads
	bool	 operator>(Fixed const & rhs) const;
	bool	 operator<(Fixed const & rhs) const;
	bool	 operator>=(Fixed const & rhs) const;
	bool	 operator<=(Fixed const & rhs) const;
	bool	 operator==(Fixed const & rhs) const;
	bool	 operator!=(Fixed const & rhs) const;

	// Arithmetic overloads
	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;

	// Inc/Decrementation overloads
	Fixed&	operator++(void); // Pre
 	Fixed	operator++(int);  // Post
	Fixed&	operator--(void);
	Fixed	operator--(int);

	// Getter and Setter for the raw bits.
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Conversion methods
	float	toFloat(void) const;
	int		toInt(void) const;

	// Static member functions for min and max
	static			Fixed& min(Fixed& a, Fixed& b);
	static const	Fixed& min(const Fixed& a, const Fixed& b);
	static			Fixed& max(Fixed& a, Fixed& b);
	static const	Fixed& max(const Fixed& a, const Fixed& b);

	// Serialisation as string
	std::string	toString(void) const; // serialise class to string

private:
	int					_result;
	static const int	_fractBits = 8;
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream & out, Fixed const & in);

#endif  // ************************************************** FIXED_CLASS_HPP //
