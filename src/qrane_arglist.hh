/*
Qrane
Filename: qrane_arglist.hh
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

#ifndef QRANE_ARGLIST
#define QRANE_ARGLIST

#include "qrane_argument.hh"
#include <iostream>
#include <string>
#include <vector>

class qrane_arglist {

public:
  enum arglist_type { IDLIST = 0, MIXED };

  qrane_arglist();
  virtual ~qrane_arglist();
  void set_type(arglist_type type);
  virtual void add_id(std::string id) {}
  virtual void add_argument(qrane_argument *arg) {}

  virtual std::size_t size() = 0;
  virtual int get_arg_index_val(int index) = 0;

protected:
  arglist_type type;
};

class qrane_idlist : public qrane_arglist {
protected:
  std::vector<std::string> idlist;

public:
  qrane_idlist();
  ~qrane_idlist();
  void add_id(std::string id);
  std::size_t size();
  int get_arg_index_val(int index);
};

class qrane_mixedlist : public qrane_arglist {

protected:
  std::vector<qrane_argument *> arglist;

public:
  qrane_mixedlist();
  ~qrane_mixedlist();
  void add_argument(qrane_argument *arg);
  std::vector<qrane_argument *> get_arglist();
  qrane_argument *get_first_control();
  qrane_argument *get_target();
  std::size_t size();
  int get_arg_index_val(int index);
};

#endif