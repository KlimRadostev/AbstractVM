// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/09/03 20:53:38 by kradoste          #+#    #+#             //
/*   Updated: 2020/02/01 21:24:09 by kradoste         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "parser.hpp"
#include "ErrorHandle.hpp"

#include <iostream>

Parser::Parser() {};
Parser::~Parser() {};

void	Parser::push(IOperand const *xx)
{ this->_ls.push_front(xx); }
void	Parser::asserter(IOperand const *xx)
{
	std::list<IOperand const *>::iterator	lit = this->_ls.begin();
	if (*lit)
		if ((*lit)->toString() == xx->toString() && (*lit)->getType() == xx->getType())
			return ;
		else
			throw HandleError::NotAsserted();
	else
		throw HandleError::NoArguments();
}

void	Parser::pop()
{
	if (this->_ls.size() >= 1)
		this->_ls.pop_front();
	else
		throw HandleError::NoArguments();
}
void	Parser::dump()
{
	std::list<IOperand const *>::iterator	lit = this->_ls.begin();
	std::list<IOperand const *>::iterator	lite = this->_ls.end();
	while (lit != lite)
	{
		std::cout << (*lit)->toString() << std::endl;
		++lit;
	}
}
void	Parser::print()
{
	std::list<IOperand const *>::iterator	lit = this->_ls.begin();
	if (*lit)
		if ((*lit)->getType() == 0)
			std::cout << static_cast<char>(stoi((*lit)->toString())) << std::endl;
		else
			throw HandleError::NotPrintable();
	else
		throw HandleError::NoArguments();
}

static IOperand const	*equ(IOperand const *tmp0, IOperand const *tmp2, char c)
{
	if (c == '+')
		return (*tmp1 + *tmp2);
	else if (c == '-')
		return (*tmp1 - *tmp2);
	else if (c == '*')
		return (*tmp1 * *tmp2);
	else if (c == '/')
		return (*tmp1 / *tmp2);
	else
		return (*tmp1 % *tmp2);
}
void	Parser::add()
{ do_op('+'); }
void	Parser::sub()
{ do_op('-'); }
void	Parser::mul()
{ do_op('*'); }
void	Parser::div()
{ do_op('/'); }
void	Parser::mod()
{ do_op('%'); }
void	Parser::do_op(char op)
{
	if (this->_ls.size() >= 2)
	{
		std::list<IOperand const *>::iterator lit = this->_ls.begin();
		IOperand const *tmp = *lit;
		++lit;
		IOperand const *tmp1 = *lit;
		this->_ls.pop_front();
		this->_ls.pop_front();
		tmp = equ(tmp, tmp1, op);
		this->_ls.push_front(tmp);
		delete tmp1;
		delete tmp;
	}
	else
		throw HandleError::TooFewArgs();
}

void	Parser::general_parse(int x, IOperand const *xx)
{
	switch (x)
	{
	case 0: this->push(xx); break;
	case 1: this->asserter(xx); break;
	case 2: this->pop(); break;
	case 3: this->dump(); break;
	case 4: this->print(); break;
	case 5: this->add(); break;
	case 6: this->sub(); break;
	case 7: this->mul(); break;
	case 8: this->div(); break;
	case 9: this->mod(); break;
	}
}
