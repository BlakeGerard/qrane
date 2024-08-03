/*
Qrane
Filename: Parameter.cc
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

#include "qrane_parameter.hpp"

namespace qrane {

template class ParameterValue<double>;
template class ParameterValue<int>;
template class ParameterValue<std::string>;

template <class T> ParameterValue<T>::ParameterValue(T value) {
  value_ = value;
}

template <class T> std::string ParameterValue<T>::to_string() const {
  std::ostringstream strm;
  strm << value_;
  return strm.str();
}

BinaryExpr::BinaryExpr(binary_expr_e type, std::string op,
                       std::shared_ptr<Parameter> lhs,
                       std::shared_ptr<Parameter> rhs) {
  type_ = type;
  op_ = op;
  lhs_ = lhs;
  rhs_ = rhs;
}

void BinaryExpr::set_type(binary_expr_e type) { type_ = type; }

void BinaryExpr::set_lhs(std::shared_ptr<Parameter> lhs) { lhs_ = lhs; }

void BinaryExpr::set_rhs(std::shared_ptr<Parameter> rhs) { rhs_ = rhs; }

std::string BinaryExpr::to_string() const {
  std::ostringstream strm;
  strm << lhs_->to_string() << " " << op_ << " " << rhs_->to_string();
  return strm.str();
}

UnaryExpr::UnaryExpr(unary_expr_e type, std::string op,
                     std::shared_ptr<Parameter> arg) {
  type_ = type;
  op_ = op;
  arg_ = arg;
}

void UnaryExpr::set_type(unary_expr_e type) { type_ = type; }

void UnaryExpr::set_arg(std::shared_ptr<Parameter> arg) { arg_ = arg; }

std::string UnaryExpr::to_string() const {
  std::ostringstream strm;
  strm << op_ << " " << arg_->to_string();
  return strm.str();
}
} // namespace qrane
