/*
Qrane
Filename: qrane_argument.hpp
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

#ifndef QRANE_ARGUMENT_HPP
#define QRANE_ARGUMENT_HPP

#include "qrane_shared.hpp"
#include <string>
#include <sstream>

namespace qrane {

class Argument {

public:
	Argument();
	Argument(std::string reg);
	Argument(std::string reg, qubit_id index);
	std::string reg() const;
	qubit_id index() const;
	std::string to_string() const;

private:
	std::string reg_;
	qubit_id index_;
};
}

#endif