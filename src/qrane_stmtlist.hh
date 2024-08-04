/*
Qrane
Filename: qrane_nodelist.hh
Creation date: June 22, 2020
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

#ifndef QRANE_STMTLIST
#define QRANE_STMTLIST

#include "qrane_qop.hh"
#include "qrane_statement.hh"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

class qrane_stmtlist {
private:
  std::vector<qrane_statement *> stmts;

public:
  ~qrane_stmtlist();
  void set_stmts(std::vector<qrane_statement *> given);
  void add_statement(qrane_statement *statement);
  std::vector<qrane_statement *> get_stmts();
  std::vector<qrane_statement *> get_qops();
  std::vector<qrane_statement *> get_1Q_gates();
  std::vector<qrane_statement *> get_2Q_gates();
  std::vector<qrane_statement *> get_qregs();
  std::vector<unsigned long> get_qops_first_argument_indices();
};

#endif
