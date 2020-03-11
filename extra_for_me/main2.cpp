// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main2.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/08/26 23:48:35 by kradoste          #+#    #+#             //
//   Updated: 2019/09/04 15:30:31 by kradoste         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <string>
#include <iostream>
#include <fstream>

#include "createOperand.hpp"
#include "parser.hpp"
#include "lexer.hpp"
#include "ErrorHandle.hpp"

int main()
{
	std::string line = "push float()";

	Parser y;
	Creator z;
	Lexer x;
 	x.get_Tokens(line);
	if (x.get_token() < 2)
	{
		std::cout << x.get_token() << ", " << x.get_type() << ", " << x.get_string() << std::endl;
		y.general_parse(x.get_token(), z.createOperand(x.get_type(), x.get_string()));
	}
	else if (x.get_token() < 9)
	{
		std::cout << x.get_token() << std::endl;
		y.general_parse(x.get_token(), NULL);
	}
	return (0);
}
