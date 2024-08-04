/*
Qrane
Filename: qrane_stmtlist.cc
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

#include "qrane_stmtlist.hh"

qrane_stmtlist::~qrane_stmtlist() {
  for (auto stmt : stmts) {
    delete stmt;
  }
  stmts.clear();
};

void qrane_stmtlist::set_stmts(std::vector<qrane_statement *> given) {
  this->stmts = given;
}

void qrane_stmtlist::add_statement(qrane_statement *statement) {
  this->stmts.push_back(statement);
};

std::vector<qrane_statement *> qrane_stmtlist::get_stmts() {
  return this->stmts;
};

std::vector<qrane_statement *> qrane_stmtlist::get_qops() {
  std::vector<qrane_statement *> qops = std::vector<qrane_statement *>();
  for (qrane_statement *stmt : stmts) {
    if (stmt->get_statement_type() == qrane_statement::statement_type::QOP) {
      qops.push_back(stmt);
    }
  }
  return qops;
};

std::vector<qrane_statement *> qrane_stmtlist::get_1Q_gates() {
  std::vector<qrane_statement *> qops = std::vector<qrane_statement *>();
  for (qrane_statement *stmt : stmts) {
    if (stmt->get_statement_type() == qrane_statement::statement_type::QOP) {
      if (((qrane_qop *)stmt)->num_args() == 1) {
        qops.push_back(stmt);
      }
    }
  }
  return qops;
};

std::vector<qrane_statement *> qrane_stmtlist::get_2Q_gates() {
  std::vector<qrane_statement *> qops = std::vector<qrane_statement *>();
  for (qrane_statement *stmt : stmts) {
    if (stmt->get_statement_type() == qrane_statement::statement_type::QOP) {
      if (((qrane_qop *)stmt)->num_args() == 2) {
        qops.push_back(stmt);
      }
    }
  }
  return qops;
};

std::vector<qrane_statement *> qrane_stmtlist::get_qregs() {
  std::vector<qrane_statement *> qregs = std::vector<qrane_statement *>();
  for (qrane_statement *stmt : stmts) {
    if (stmt->get_statement_type() == qrane_statement::statement_type::QREG) {
      qregs.push_back(stmt);
    }
  }
  return qregs;
};

/*
std::vector<unsigned long> qrane_stmtlist::get_qops_first_argument_indices() {
    std::vector<unsigned long> indices = std::vector<unsigned long>();
    std::vector<qrane_statement*> qops = this->get_qops();

    for (int i = 0; i < (int) qops.size(); ++i) {

        qrane_qop* qop = (qrane_qop*) stmts[i];
        std::cout << qop->get_first_arg_index() << std::endl;
        indices.push_back(qop->get_first_arg_index());
    }

    return indices;
};
*/
