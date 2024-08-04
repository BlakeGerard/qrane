/*
Qrane
Filename: qrane_argument.hh
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

#ifndef QRANE_ARGUMENT
#define QRANE_ARGUMENT

#include <string>

class qrane_argument {

protected:
  std::string id;
  unsigned long index;

public:
  qrane_argument(std::string id);
  qrane_argument(std::string id, unsigned long index);
  qrane_argument();
  ~qrane_argument();
  std::string get_id();
  unsigned long get_index();
};

#endif