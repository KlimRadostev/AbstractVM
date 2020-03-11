// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   lexer.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/09/04 00:26:04 by kradoste          #+#    #+#             //
//   Updated: 2019/09/04 05:40:40 by kradoste         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LEXER_HPP
# define LEXER_HPP

#include <string>
#include "IOperand.hpp"

enum	Tokenizer {push, asserter, pop, dump, print, add, sub, mul, div, mod, comment};

class Lexer
{
private:
	Tokenizer		_token;
	eOperandType	_type;
	std::string		_value;

public:
	Lexer();
	~Lexer();

	void			get_Tokens(std::string line);
	Tokenizer		get_token() { return (this->_token); }
	eOperandType	get_type() { return (this->_type); }
	std::string		get_string() { return (this->_value); }
};

#endif
