// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   createOperand.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/08/25 23:52:15 by kradoste          #+#    #+#             //
//   Updated: 2019/09/03 13:20:21 by kradoste         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CREATEOPERAND_HPP
# define CREATEOPERAND_HPP

#include "IOperand.hpp"

class	Creator {
private:
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;	
public:
	IOperand const * createOperand(eOperandType type, std::string const &value) const;
};

#endif
