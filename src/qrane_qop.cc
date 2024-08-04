/*
Qrane
Filename: qrane_qop.cc
Creation date: June 30, 2020
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

#include "qrane_qop.hh"
#include <sstream>

/* QOP */
qrane_qop::~qrane_qop() {};

void qrane_qop::set_qop_type(qop_type type) { this->t_qop = type; };

qrane_qop::qop_type qrane_qop::get_qop_type() { return this->t_qop; };

void qrane_qop::set_dim1_qop_num(unsigned int val) {
  this->dim1_qop_num = val;
};

unsigned int qrane_qop::get_dim1_qop_num() { return this->dim1_qop_num; }

void qrane_qop::set_if_condition(std::string id, int nninteger) {
  this->if_id = id;
  this->if_nnint = nninteger;
};

/* U */
qrane_u::qrane_u() {};

qrane_u::~qrane_u() {
  delete explist;
  delete arglist;
};

void qrane_u::set_explist(qrane_explist *explist) { this->explist = explist; };

void qrane_u::set_arglist(qrane_arglist *arglist) { this->arglist = arglist; };

qrane_arglist *qrane_u::get_arglist() { return this->arglist; };

unsigned long qrane_u::get_first_arg_index() {
  return ((qrane_mixedlist *)arglist)->get_first_control()->get_index();
};

unsigned long qrane_u::get_target_index() {
  return ((qrane_mixedlist *)arglist)->get_target()->get_index();
};

std::string qrane_u::get_id() { return std::string("U"); };

std::size_t qrane_u::num_args() const { return 1; };

unsigned int qrane_u::at(int index) const {
  return this->arglist->get_arg_index_val(index);
};

std::string qrane_u::to_str() {
  std::ostringstream strm;

  strm << "U";
  for (std::size_t i = 0; i < arglist->size(); ++i) {
    strm << "q[" << arglist->get_arg_index_val(i) << "]";
    if (i != arglist->size() - 1) {
      strm << ",";
    } else {
      // strm << ";";
    }
  }
  return strm.str();
};

/* CX */
qrane_cx::qrane_cx() {};

qrane_cx::~qrane_cx() { delete arglist; };

void qrane_cx::set_arglist(qrane_arglist *arglist) { this->arglist = arglist; };

qrane_arglist *qrane_cx::get_arglist() { return this->arglist; }

unsigned long qrane_cx::get_first_arg_index() {
  return ((qrane_mixedlist *)arglist)->get_first_control()->get_index();
};

unsigned long qrane_cx::get_target_index() {
  return ((qrane_mixedlist *)arglist)->get_target()->get_index();
};

std::string qrane_cx::get_id() { return std::string("CX"); };

std::size_t qrane_cx::num_args() const { return 2; };

unsigned int qrane_cx::at(int index) const {
  return this->arglist->get_arg_index_val(index);
};

std::string qrane_cx::to_str() {
  std::ostringstream strm;

  strm << "CX";
  for (std::size_t i = 0; i < arglist->size(); ++i) {
    strm << "q[" << arglist->get_arg_index_val(i) << "]";
    if (i != arglist->size() - 1) {
      strm << ",";
    } else {
      // strm << ";";
    }
  }
  return strm.str();
};

/* CUSTOM */
qrane_custom::qrane_custom() {};

qrane_custom::~qrane_custom() {
  delete explist;
  delete arglist;
};

void qrane_custom::set_id(std::string id) { this->id = id; };

void qrane_custom::set_explist(qrane_explist *explist) {
  this->explist = explist;
};

void qrane_custom::set_arglist(qrane_arglist *arglist) {
  this->arglist = arglist;
};

qrane_arglist *qrane_custom::get_arglist() { return this->arglist; };

unsigned long qrane_custom::get_first_arg_index() {
  return ((qrane_mixedlist *)arglist)->get_first_control()->get_index();
};

unsigned long qrane_custom::get_target_index() {
  return ((qrane_mixedlist *)arglist)->get_target()->get_index();
};

std::string qrane_custom::get_id() { return this->id; };

std::size_t qrane_custom::num_args() const { return this->arglist->size(); };

unsigned int qrane_custom::at(int index) const {
  return this->arglist->get_arg_index_val(index);
};

std::string qrane_custom::to_str() {
  std::ostringstream strm;

  strm << id; //<< " ";
  for (std::size_t i = 0; i < arglist->size(); ++i) {
    strm << "q[" << arglist->get_arg_index_val(i) << "]";
    if (i != arglist->size() - 1) {
      strm << ",";
    } else {
      // strm << ";";
    }
  }
  return strm.str();
};

/* MEASURE */
qrane_measure::qrane_measure() {};

qrane_measure::~qrane_measure() { delete arglist; };

void qrane_measure::set_arglist(qrane_arglist *arglist) {
  this->arglist = arglist;
}

qrane_arglist *qrane_measure::get_arglist() { return this->arglist; };

unsigned long qrane_measure::get_first_arg_index() {
  return ((qrane_mixedlist *)arglist)->get_first_control()->get_index();
};

unsigned long qrane_measure::get_target_index() {
  return ((qrane_mixedlist *)arglist)->get_target()->get_index();
};

std::string qrane_measure::get_id() { return std::string("measure"); };

std::size_t qrane_measure::num_args() const { return this->arglist->size(); };

unsigned int qrane_measure::at(int index) const {
  return this->arglist->get_arg_index_val(index);
};

std::string qrane_measure::to_str() {
  std::ostringstream strm;

  strm << "measure ";
  for (std::size_t i = 0; i < arglist->size(); ++i) {
    strm << "q[" << arglist->get_arg_index_val(i) << "]";
    if (i != arglist->size() - 1) {
      strm << ",";
    } else {
      strm << ";";
    }
  }
  return strm.str();
};

/* RESET */
qrane_reset::qrane_reset() {};

qrane_reset::~qrane_reset() { delete arglist; };

void qrane_reset::set_arglist(qrane_arglist *arglist) {
  this->arglist = arglist;
};

qrane_arglist *qrane_reset::get_arglist() { return this->arglist; };

unsigned long qrane_reset::get_first_arg_index() {
  return ((qrane_mixedlist *)arglist)->get_first_control()->get_index();
};

unsigned long qrane_reset::get_target_index() {
  return ((qrane_mixedlist *)arglist)->get_target()->get_index();
};

std::string qrane_reset::get_id() { return std::string("reset"); };

std::size_t qrane_reset::num_args() const { return this->arglist->size(); };

unsigned int qrane_reset::at(int index) const {
  return this->arglist->get_arg_index_val(index);
};

std::string qrane_reset::to_str() {
  std::ostringstream strm;

  strm << "reset ";
  for (std::size_t i = 0; i < arglist->size(); ++i) {
    strm << "q[" << arglist->get_arg_index_val(i) << "]";
    if (i != arglist->size() - 1) {
      strm << ",";
    } else {
      strm << ";";
    }
  }
  return strm.str();
};
