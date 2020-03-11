// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   parser.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/09/03 20:45:01 by kradoste          #+#    #+#             //
//   Updated: 2019/09/04 14:01:59 by kradoste         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSER_HPP
# define PARSER_HPP

#include "IOperand.hpp"
#include <list>

class	Parser
{
private:
	std::list<IOperand const *>	_ls;
	void	do_op(char op);

	void	push(IOperand const *xx);
	void	asserter(IOperand const *xx);

	void	pop();
	void	dump();
	void	print();

	void	add();
	void	sub();
	void	mul();
	void	div();
	void	mod();

public:
	Parser();
	~Parser();

	void	general_parse(int x, IOperand const *xx);
};

#endif
