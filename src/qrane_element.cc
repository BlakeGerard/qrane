/*
Qrane
Filename: Element.cc
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

#include "qrane_element.hh"

namespace qrane {
    Element::Element(element_variant_e type) {
        this->variant_ = type;
    }

    element_variant_e Element::statement_type() const {
        return this->variant_;
    }

    bool Element::is_decl() const {
        return this->variant_ == element_variant_e::DECL;
    }

    bool Element::is_reg() const {
        return this->variant_ == element_variant_e::REG;
    }

    bool Element::is_qop() const {
        return this->variant_ == element_variant_e::QOP;
    }
}