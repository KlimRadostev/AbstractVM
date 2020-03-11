// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   createOperand.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/08/26 21:19:15 by kradoste          #+#    #+#             //
/*   Updated: 2020/02/01 21:33:07 by kradoste         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "createOperand.hpp"
#include "Operand.hpp"
#include "ErrorHandle.hpp"

IOperand const * Creator::createInt8( std::string const & value ) const
{
	long double		xx = stold(value);
	if (xx > std::numeric_limits<signed char>::max())
		throw HandleError::Overflow();
	if (xx < std::numeric_limits<signed char>::min())
		throw HandleError::Underflow();
	long long int	x = xx;
	return (new Operand<int8_t>(x, Int8, std::to_string(x)));
}

IOperand const * Creator::createInt16( std::string const & value ) const
{
	long double		xx = stold(value);
	if (xx > std::numeric_limits<int16_t>::max())
		throw HandleError::Overflow();
	if (xx < std::numeric_limits<int16_t>::min())
		throw HandleError::Underflow();
	long long int	x = xx;
	return (new Operand<int16_t>(x, Int16, std::to_string(x)));
}

IOperand const * Creator::createInt32( std::string const & value ) const
{
	long double		xx = stold(value);
	if (xx > std::numeric_limits<int32_t>::max())
		throw HandleError::Overflow();
	if (xx < std::numeric_limits<int32_t>::min())
		throw HandleError::Underflow();
	long long int	x = xx;
	return (new Operand<int32_t>(x, Int32, std::to_string(x)));
}

IOperand const * Creator::createFloat( std::string const & value ) const
{
	long double		xx = stold(value);
	if (xx > std::numeric_limits<float>::max())
		throw HandleError::Overflow();
	if (xx < std::numeric_limits<float>::min())
		throw HandleError::Underflow();
	return (new Operand<float>(xx, Float, std::to_string(xx)));
}

IOperand const * Creator::createDouble( std::string const & value ) const
{
	long double xx = stold(value);
	if (xx > std::numeric_limits<double>::max())
		throw HandleError::Overflow();
	if (xx < std::numeric_limits<double>::min())
		throw HandleError::Underflow();
	return (new Operand<double>(xx, Double, std::to_string(xx)));
}

IOperand const * Creator::createOperand( eOperandType type, std::string const & value ) const
{
	if (type == Int8)
		return (Creator::createInt8(value));
	else if (type == Int16)
		return (Creator::createInt16(value));
	else if (type == Int32)
		return (Creator::createInt32(value));
	else if (type == Float)
		return (Creator::createFloat(value));
	else if (type == Double)
		return (Creator::createDouble(value));
	return NULL;
}
