/*
Qrane
Filename: qrane_exp.cc
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

#include <string>
#include "qrane_exp.hh"

qrane_exp::qrane_exp() {};
qrane_exp::~qrane_exp() {};

template <typename T>
qrane_value<T>::qrane_value(T value) {
    this->value = value;
};

template <typename T>
qrane_value<T>::~qrane_value() {};

template class qrane_value<double>;
template class qrane_value<int>;
template class qrane_value<std::string>;

qrane_binaryop::qrane_binaryop() {};
qrane_binaryop::~qrane_binaryop() {
    delete lhs;
    delete rhs;
};

void qrane_binaryop::set_binaryop_type(binaryop_type type) {
    this->type = type;
};

void qrane_binaryop::set_lhs(qrane_exp* lhs) {
    this->lhs = lhs;
};

void qrane_binaryop::set_rhs(qrane_exp* rhs) {
    this->rhs = rhs;
};

qrane_unaryop::qrane_unaryop() {};
qrane_unaryop::~qrane_unaryop() {
    delete arg;
};

void qrane_unaryop::set_unaryop_type(unaryop_type type) {
    this->type = type;
};

void qrane_unaryop::set_arg(qrane_exp* arg) {
    this->arg = arg;
};