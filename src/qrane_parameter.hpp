/*
Qrane
Filename: qrane_parameter.hpp
Creation date: June 28, 2020
Copyright (C) 2020

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QRANE_PARAMETER_HPP
#define QRANE_PARAMETER_HPP

#include <memory>
#include <string>
#include <sstream>

namespace qrane {

enum binary_expr_e {
	ADD,
	SUB,
	MUL,
	DIV,
	CAR
};

enum unary_expr_e {
	SIN,
	COS,
	TAN,
	EXP,
	LN,
	SQRT,
	NEG,
	PAR
};

class Parameter {

public:
	virtual std::string to_string() const = 0;
};

template <class T>
class ParameterValue : public Parameter {

public:
	ParameterValue(T value);
	std::string to_string() const;

protected:
	T value_;
};

class BinaryExpr : public Parameter {

public:
	BinaryExpr(binary_expr_e type, std::string op, 
			   std::shared_ptr<Parameter> lhs, std::shared_ptr<Parameter> rhs);
	void set_type(binary_expr_e type);
	void set_lhs(std::shared_ptr<Parameter> lhs);
	void set_rhs(std::shared_ptr<Parameter> rhs);
	std::string to_string() const;

protected:
	binary_expr_e type_;
	std::string op_;
	std::shared_ptr<Parameter> lhs_;
	std::shared_ptr<Parameter> rhs_;
};

class UnaryExpr : public Parameter {

public:
	UnaryExpr(unary_expr_e type, std::string op, 
			  std::shared_ptr<Parameter> arg);
	void set_type(unary_expr_e type);
	void set_arg(std::shared_ptr<Parameter> arg);
	std::string to_string() const;

protected:
	unary_expr_e type_;
	std::string op_;
	std::shared_ptr<Parameter> arg_;
};
}

#endif