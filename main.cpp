// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/08/06 16:55:17 by kradoste          #+#    #+#             //
/*   Updated: 2020/02/01 21:24:49 by kradoste         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include <string>
#include <iostream>
#include <fstream>

#include "createOperand.hpp"
#include "parser.hpp"
#include "lexer.hpp"
#include "ErrorHandle.hpp"

std::string	ero(int x) {return ("line " + std::to_string(x) + " : ERROR | ");}

void		readData(std::istream &in)
{
	Parser	y;
	Creator	z;
	int		c = 1;

	for (std::string line; std::getline(in, line) && line != ";;" && line != "exit";)
	{
		try {
			Lexer	x;
			
			x.get_Tokens(line);
			
			if (x.get_token() < 2)
				y.general_parse(x.get_token(), z.createOperand(x.get_type(), x.get_string()));
			else if (x.get_token() < 10)
				y.general_parse(x.get_token(), NULL);
		}
		catch (HandleError::ZeroDivisor &e) {std::cout << ero(c) << e.what() << std::endl;}
		catch (HandleError::Underflow &e) {std::cout << ero(c) << e.what() << std::endl;}
		catch (HandleError::Overflow &e) {std::cout << ero(c) << e.what() << std::endl;}
		catch (HandleError::TooFewArgs &e) {std::cout << ero(c) << e.what() << std::endl;}
		catch (HandleError::NotPrintable &e) {std::cout << ero(c) << e.what() << std::endl;}
		catch (HandleError::NotAsserted &e) {std::cout << ero(c) << e.what() << std::endl;}
		catch (HandleError::SyntaxError &e) {std::cout << ero(c) << e.what() << std::endl;}
		catch (HandleError::TypeError &e) {std::cout << ero(c) << e.what() << std::endl;}
		catch (HandleError::ValueError &e) {std::cout << ero(c) << e.what() << std::endl;}
		catch (HandleError::NoArguments &e) {std::cout << ero(c) << e.what() << std::endl;}
		c++;
	}
}

int			main(int ac, char **argv)
{
	if (ac > 2)
		std::cout << "ERROR : you either only write an argument or go into stdin::\n";
	else if (ac == 2)
	{
		std::ifstream	infile(argv[1]);
		if (infile)
			readData(infile);
		else
			std::cout << "ERROR : Not a valid file name\n";
	}
	else
		readData(std::cin);
	return (0);
}

