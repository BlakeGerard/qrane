/*
Qrane
Filename: Reg.cc
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

#include "qrane_reg.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

namespace qrane {

Reg::Reg() : Element(element_variant_e::REG) {
	variant_ = reg_variant_e::QREG;
	device_ = std::string("qreg");
	name_ = std::string("DEFAULT_QREG");
};

/*
	Construct an empty register.
*/
Reg::Reg(element_variant_e element_variant, reg_variant_e reg_variant, 
	std::string device, std::string name) : Element(element_variant) {
	variant_ = reg_variant;
	device_ = device;
	name_ = name;
	reg_ = reg_t();
};

/*
	Construct a register populated with indices
	in the range [0, size - 1].
*/
Reg::Reg(element_variant_e element_variant, reg_variant_e reg_variant, 
	std::string device, std::string name, unsigned int size) : Element(element_variant) {
	variant_ = reg_variant;
	device_ = device;
	name_ = name;
	reg_ = reg_t();

	qubit_id id = 0;
	for (; id < size;) {
		reg_.insert(std::make_pair(id, id));
		++id;
	}
};

/*
	Create a register from an initializer_list.
*/
Reg::Reg(element_variant_e element_variant, reg_variant_e reg_variant,
	std::string device, std::string name, 
	std::initializer_list<qubit_id> reg) : Element(element_variant) {
	variant_ = reg_variant;
	device_ = device;
	name_ = name;
	reg_ = reg_t();

	for (const auto& id : reg) {
		reg_.insert(std::make_pair(id, id));
	}
};

/*
	Construct a register populated with indices
	in the range [incl_start, incl_stop].
*/
Reg::Reg(element_variant_e element_variant, reg_variant_e reg_variant, 
	std::string device, std::string name, 
	qop_id start, qop_id stop) : Element(element_variant) {
	variant_ = reg_variant;
	device_ = device;
	name_ = name;
	reg_ = reg_variant_t();

	qubit_id id = start;
	for (; id <= stop;) {
		reg_.insert(std::make_pair(id, id));
		++id;
	}
}

Reg Reg::trivial_layout(unsigned int size) {
	return Reg(element_variant_e::REG, reg_variant_e::QREG, "qreg", "q", size);
}

Reg Reg::read_from_edge_list_file(std::string mapping_path) {
	Reg ret = Reg();
	std::ifstream in_strm;
	std::string line, lhs, rhs;

	in_strm.open(mapping_path, std::ios_base::in);
	if (in_strm.is_open()) {
		while(std::getline(in_strm, line)) {
			if (line == "") { continue; }
			auto space = line.find(" ");
			lhs = line.substr(0, space);
			rhs = line.substr(space+1);
			auto lhs_id = std::stoi(lhs);
			auto rhs_id = std::stoi(rhs);
			ret.insert(lhs_id, rhs_id);
		}
		in_strm.close();
	} else {
		std::cout << "Unable to open mapping file. Returning empty Reg.\n";
	}
	return ret;
};

qubit_id Reg::operator[](unsigned int index) const {
	return reg_.at(index);
};

bool Reg::operator==(const Reg& rhs) const {
	for (const auto& entry : reg_) {
		if (!rhs.reg_.count(entry.first)) {
			return false;
		}
		if (entry.second != rhs.reg_.at(entry.first)) {
			return false;
		}
	}
	return variant_ == rhs.variant_;
};

qubit_id Reg::at(qubit_id id) const {
	return reg_.at(id);
}

std::string Reg::name() const {
	return name_;
}

unsigned int Reg::size() const {
	return reg_.size();
}

bool Reg::count(qubit_id id) const {
	return reg_.count(id);
};

bool Reg::is_qreg() const {
	return variant_ == reg_variant_e::QREG;
};

bool Reg::is_creg() const {
	return variant_ == reg_variant_e::CREG;
};

std::string Reg::to_string() const {
	std::ostringstream strm;
	strm << device_ << " " << name_ << "[" << reg_.size() << "];";
	return strm.str();
};

void Reg::print_current_mapping() {
	std::ostringstream strm;
	strm << "{ ";
	for (const auto& entry : reg_) {
		strm << "q[" << entry.first << "] -> l[" << entry.second << "], ";
	}
	strm.seekp(-2, std::ios_base::end); // Revert before the trailing ','
	strm << "}" << std::endl;
	std::cout << strm.str();
};

void Reg::insert(qubit_id id) {
	reg_.insert(std::make_pair(id, id));
}

void Reg::insert(qubit_id physical, qubit_id logical) {
	reg_.insert(std::make_pair(physical, logical));
}

void Reg::permute_register(qubit_id lhs, qubit_id rhs) {
	qubit_id temp;
	if (reg_.count(lhs) && reg_.count(rhs)) {
		temp = reg_[lhs];
		reg_[lhs] = reg_[rhs];
		reg_[rhs] = temp;
	}
};

reg_variant_t::iterator Reg::begin() {
	return reg_.begin();
};

reg_variant_t::iterator Reg::end() {
	return reg_.end();
};

reg_variant_t::const_iterator Reg::begin() const {
	return reg_.cbegin();
};

reg_variant_t::const_iterator Reg::end() const {
	return reg_.cend();
};

}