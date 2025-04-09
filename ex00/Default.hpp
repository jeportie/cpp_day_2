/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Default.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:07:48 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/09 10:30:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_HPP
# define DEFAULT_HPP

# include <iostream>
# include <string>

class Default
{
public:
	Default(void);
	Default(Default const & src);
	~Default(void);

	Default &	operator=(Default const & rhs);

	int	getFoo(void) const;

private:
	int	_foo;
};

// Overload operator<< for output streaming
std::ostream &	operator<<(std::ostream & out, Default const & in);
// Overload operator+ for string concatenation
std::string operator+(std::string const & lhs, Default const & rhs);

#endif  // ****************************************************** DEFAULT_HPP //
