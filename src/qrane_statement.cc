/*
Qrane
Filename: qrane_statement.cc
Creation date: July 2, 2020
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

#include "qrane_statement.hh"

qrane_statement::qrane_statement() {};
qrane_statement::~qrane_statement() {};

void qrane_statement::set_statement_type(statement_type stmt_type) {
  this->stmt_type = stmt_type;
};

qrane_statement::statement_type qrane_statement::get_statement_type() {
  return this->stmt_type;
};

void qrane_statement::print_type() {
  switch (stmt_type) {
  case DECL:
    std::cout << "Declaration" << std::endl;
    break;
  case QOP:
    std::cout << "Quantum Operation" << std::endl;
    break;
  case QREG:
    std::cout << "qreg" << std::endl;
    break;
  }
};