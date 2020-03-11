// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Operand.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/08/25 23:50:51 by kradoste          #+#    #+#             //
//   Updated: 2020/01/22 16:14:52 by kradoste         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "IOperand.hpp"
#include "createOperand.hpp"
#include "ErrorHandle.hpp"

template<typename X, typename Y, typename Z>
static void	dooperation(X &val, Y const &val1, Z const &val2, char c)
{
	if (c == '+')
		val = val1 + val2;
	else if (c == '-')
		val = val1 - val2;
	else if (c == '*')
		val = val1 * val2;
	else if (c == '/')
		val = val1 / val2;
	else if (c == '%')
		val = (long long int)val1 % (long long int)val2;
}

template<typename T>
class		Operand : public IOperand
{
private:
    T               _val;
    eOperandType    _type;
	std::string     _s;
	Creator			_x;

public:
    Operand<T>() {}
    Operand<T>(T pass, eOperandType type, std::string s) : _val(pass), _type(type), _s(s) {}
    ~Operand<T>() {}
	
    eOperandType        getType() const {return (_type);}
	std::string const   &toString() const {return (_s);}
    int					getPrecision() const { return (_type); }

	IOperand const		*operatorforall(IOperand const &rhs, char c) const
		{
            eOperandType    e = (this->_type >= rhs.getType() ? this->_type : rhs.getType());
			std::string     str;

            if (e < Float)
			{
				int val;
                ::dooperation(val, this->_val, stoi(rhs.toString()), c);
				str = std::to_string(val);
				return (this->_x.createOperand(e, str));
			}
            else
 			{
				double val;
				::dooperation(val, stod(rhs.toString()), stod(toString()), c);
				str = std::to_string(val);
				return (this->_x.createOperand(e, str));
			}
        }
    IOperand const      *operator+(IOperand const &rhs) const
		{ return (operatorforall(rhs, '+')); }
	IOperand const      *operator-(IOperand const &rhs) const
		{ return (operatorforall(rhs, '-')); }
	IOperand const      *operator*(IOperand const &rhs) const
		{ return (operatorforall(rhs, '*')); }
	IOperand const      *operator/(IOperand const &rhs) const
		{
			if (rhs.toString() != "0")
				return (operatorforall(rhs, '/'));
			else
				throw HandleError::ZeroDivisor();
		}
	IOperand const      *operator%(IOperand const &rhs) const
		{
			if (rhs.toString() != "0")
				return (operatorforall(rhs, '%'));
			else
				throw HandleError::ZeroDivisor();
		}
};

#endif
