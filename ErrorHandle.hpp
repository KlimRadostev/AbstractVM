// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ErrorHandle.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/09/02 20:44:27 by kradoste          #+#    #+#             //
/*   Updated: 2020/02/01 21:29:32 by kradoste         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef ERRORHANDLE_HPP
# define ERRORHANDLE_HPP

struct			HandleError
{
	struct ZeroDivisor : public std::exception
	{ const char	*what(void) const throw() {return ("You cannot have a 0 divisor");} };
	struct Underflow : public std::exception
	{ const char	*what(void) const throw() {return ("This number Underflows the type");} };
	struct Overflow : public std::exception
	{ const char	*what(void) const throw() {return ("This number Overflows the type");} };
	struct TooFewArgs : public std::exception
	{ const char	*what(void) const throw() {return ("Too few arguments to do action");} };
	struct NotPrintable : public std::exception
	{ const char	*what(void) const throw() {return ("Argument has to be a char/int8");} };
	struct NotAsserted : public std::exception
	{ const char	*what(void) const throw() {return ("Argument isn't asserted");} };
	struct SyntaxError : public std::exception
	{ const char	*what(void) const throw() {return ("Syntax Error");} };
	struct TypeError : public std::exception
	{ const char	*what(void) const throw() {return ("Make sure type has good syntax");} };
	struct ValueError : public std::exception
	{ const char	*what(void) const throw() {return ("value has to be a valid number");} };
	struct NoArguments : public std::exception
	{ const char	*what(void) const throw() {return ("There are no arguments in the stack");} };
};

#endif
