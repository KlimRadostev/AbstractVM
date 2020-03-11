// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   lexer.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/09/04 01:50:02 by kradoste          #+#    #+#             //
//   Updated: 2020/01/27 20:07:30 by kradoste         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "lexer.hpp"
#include "ErrorHandle.hpp"

///////////////////
#include <iostream>
///////////////////

#include <string>
#include <cstring>
#include <ctype.h>

Lexer::Lexer() {}
Lexer::~Lexer() {}

static bool	is_number(const std::string &s)
{
	char	cstr[s.size() + 1];
	strcpy(cstr, s.c_str());

	int key = 0;
	int	i = 0;
	if (cstr[i] == '-' || cstr[i] == '+')
		i++;
	while (cstr[i] && (isdigit(cstr[i]) || cstr[i] == '.'))
	{
		if (cstr[i] == '.') key++;
		i++;
	} 
	return !cstr[i] && key < 2;
}

void	Lexer::get_Tokens(std::string line)
{
	std::string	cmp[] = {"pop", "dump", "print", "add", "sub", "mul", "div", "mod"};
	std::string cmp1[] = {"int8", "int16", "int32", "float", "double"};
	int	x = -1;

	while (line != cmp[++x] && x < 8) {}
	if (line == cmp[x])
		this->_token = Tokenizer(x + 2);
	else if (!line.compare(0, 1, ";"))
		this->_token = Tokenizer(10);
	else if (!line.compare(0, 4, "push"))
		this->_token = Tokenizer(0);
	else if (!line.compare(0, 6, "assert"))
		this->_token = Tokenizer(1);
	else
		throw HandleError::SyntaxError();
	if (this->_token < 2)
	{
		std::string delimiter = " ";
		line.erase(0, line.find(delimiter) + delimiter.length());
		delimiter = "(";
		
		std::string token = line.substr(0, line.find(delimiter));
		x = -1;
		while (token != cmp1[++x] && x < 5) {}
		if (token == cmp1[x])
			this->_type = eOperandType(x);
		else
			throw HandleError::TypeError();
		line.erase(0, line.find(delimiter) + delimiter.length());
		delimiter = ")";
		token = line.substr(0, line.find(delimiter));
		if (token.empty())
			this->_value = "0";
		else if (is_number(token))
			this->_value = token;
		else
			throw HandleError::ValueError();
		line.erase(0, line.find(delimiter) + delimiter.length());
		if (!line.empty())
			throw HandleError::SyntaxError();
	}
}
