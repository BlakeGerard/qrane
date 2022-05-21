/*
Qrane
Filename: qrane_statement.hh
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

#ifndef QRANE_ELEMENT_H
#define QRANE_ELEMENT_H

#include <string>

namespace qrane {
    enum element_variant_e {
        DECL,
        REG,
        QOP
    };

    class Element {

        private:
            element_variant_e variant_;

        public:
            Element(element_variant_e variant);
            element_variant_e statement_type() const;
            bool is_decl() const;
            bool is_reg() const;
            bool is_qop() const;
            virtual std::string to_string() const = 0;
    };
}

#endif