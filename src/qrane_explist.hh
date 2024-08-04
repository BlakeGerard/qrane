/*
Qrane
Filename: qrane_explist.hh
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

#ifndef QRANE_EXPLIST
#define QRANE_EXPLIST

#include "qrane_exp.hh"
#include <vector>

class qrane_explist {

protected:
  std::vector<qrane_exp *> explist;

public:
  qrane_explist();
  ~qrane_explist();
  void add_exp(qrane_exp *exp);
};

#endif