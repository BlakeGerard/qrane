/*
Qrane
Filename: Decl.cc
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

#include "qrane_decl.hpp"

namespace qrane {

Decl::Decl(element_variant_e element_variant, decl_variant_e decl_type, 
	std::string name) : Element(element_variant) {
	variant_ = decl_type;
	name_ = name;
	params_ = std::vector<std::shared_ptr<Parameter>>();
	args_ = std::vector<std::shared_ptr<Argument>>();
	elements_ = std::vector<std::shared_ptr<Element>>();
}

Decl::Decl(element_variant_e element_variant, decl_variant_e decl_type, 
	std::string name, std::vector<std::shared_ptr<Argument>> args) : Element(element_variant) {
	variant_ = decl_type;
	name_ = name;
	params_ = std::vector<std::shared_ptr<Parameter>>();
	args_ = args;
	elements_ = std::vector<std::shared_ptr<Element>>();
}

Decl::Decl(element_variant_e element_variant, decl_variant_e decl_type, 
	std::string name, std::vector<std::shared_ptr<Parameter>> params, 
	std::vector<std::shared_ptr<Argument>> args) : Element(element_variant) {
	variant_ = decl_type;
	name_ = name;
	params_ = params;
	args_ = args;
	elements_ = std::vector<std::shared_ptr<Element>>();
}

void Decl::set_elements(std::vector<std::shared_ptr<Element>> elements) {
	elements_ = elements;
}

std::string Decl::name() const {
	return name_;
}

std::string Decl::to_string() const {
	return std::string("decl " + name_);
}
}