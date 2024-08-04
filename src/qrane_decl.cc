/*
Qrane
Filename: qrane_decl.cc
Creation date: July 1, 2020
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

#include "qrane_decl.hh"

qrane_decl::qrane_decl() {};
qrane_decl::~qrane_decl() {};

void qrane_decl::set_decl_type(decl_type t_decl) { this->t_decl = t_decl; };

qrane_decl::decl_type qrane_decl::get_decl_type() { return this->t_decl; };

qrane_qreg::qrane_qreg() {};
qrane_qreg::~qrane_qreg() {};

void qrane_qreg::set_id(std::string id) { this->id = id; };

void qrane_qreg::set_size(int nninteger) { this->size = nninteger; };

std::string qrane_qreg::get_id() { return this->id; };

int qrane_qreg::get_size() { return this->size; }

qrane_creg::qrane_creg() {};
qrane_creg::~qrane_creg() {};

void qrane_creg::set_id(std::string id) { this->id = id; };

void qrane_creg::set_size(int nninteger) { this->size = nninteger; };

std::string qrane_creg::get_id() { return this->id; };

int qrane_creg::get_size() { return this->size; }

qrane_gatedecl::qrane_gatedecl() {};

qrane_gatedecl::~qrane_gatedecl() {
  delete paramlist;
  delete arglist;
  delete goplist;
};

void qrane_gatedecl::set_id(std::string id) { this->id = id; };

void qrane_gatedecl::set_paramlist(qrane_idlist *paramlist) {
  this->paramlist = paramlist;
};

void qrane_gatedecl::set_arglist(qrane_idlist *arglist) {
  this->arglist = arglist;
};

void qrane_gatedecl::set_goplist(qrane_stmtlist *goplist) {
  this->goplist = goplist;
};

std::string qrane_gatedecl::get_id() { return this->id; };

int qrane_gatedecl::get_size() { return this->arglist->size(); }

qrane_opaque::qrane_opaque() {};
qrane_opaque::~qrane_opaque() {
  delete paramlist;
  delete arglist;
};

void qrane_opaque::set_id(std::string id) { this->id = id; };

void qrane_opaque::set_paramlist(qrane_idlist *paramlist) {
  this->paramlist = paramlist;
};

void qrane_opaque::set_arglist(qrane_idlist *arglist) {
  this->arglist = arglist;
};

std::string qrane_opaque::get_id() { return this->id; };

int qrane_opaque::get_size() { return this->arglist->size(); }

qrane_barrier::qrane_barrier() {};
qrane_barrier::~qrane_barrier() { delete arglist; };

void qrane_barrier::set_arglist(qrane_arglist *arglist) {
  this->arglist = arglist;
};

std::string qrane_barrier::get_id() { return std::string("barrier"); };

int qrane_barrier::get_size() { return this->arglist->size(); }
