/*
Qrane
Filename: Decl.hh
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

#ifndef QRANE_DECL_H
#define QRANE_DECL_H

#include "qrane_argument.hh"
#include "qrane_parameter.hh"
#include "qrane_element.hh"

namespace qrane {

    enum decl_variant_e {
        GATE
    };

    class Decl : public Element {

        public:
            Decl(element_variant_e element_variant, decl_variant_e  decl_variant, std::string name);
            Decl(element_variant_e element_variant, decl_variant_e  decl_variant, std::string name, 
                std::vector<std::shared_ptr<Argument>> args);
            Decl(element_variant_e element_variant, decl_variant_e  decl_variant, std::string name,
                std::vector<std::shared_ptr<Parameter>> params, 
                std::vector<std::shared_ptr<Argument>> args);
            std::string name();
            void set_statementlist(std::vector<std::shared_ptr<Element>> elements);
            std::string to_string();

        private:
            decl_variant_e variant_;
            std::string name_;
            std::vector<std::shared_ptr<Parameter>> params_;
            std::vector<std::shared_ptr<Argument>> args_;
            std::vector<std::shared_ptr<Element>> elements_;
    };
}

#endif