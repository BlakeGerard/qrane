/*
Qrane
Filename: Argument.cc
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

#include "qrane_argument.hh"
#include <limits>

namespace qrane {

    Argument::Argument() {
        this->reg_ = std::string("undefined");
        this->index_ = std::numeric_limits<qubit_id>::max();
    }

    Argument::Argument(std::string reg) {
        this->reg_ = reg;
        this->index_ = std::numeric_limits<qubit_id>::max();
    }

    Argument::Argument(std::string reg, qubit_id index) {
        this->reg_ = reg;
        this->index_ = index;
    }

    std::string Argument::reg() const {
        return this->reg_;
    }

    qubit_id Argument::index() const {
        return this->index_;
    }

    std::string Argument::to_string() const {
        std::ostringstream strm;
        strm << reg_ << "[" << index_ << "]";
        return strm.str();
    }
}