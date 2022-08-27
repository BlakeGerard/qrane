/*
    Project: qrane
    Filename: Reg.hpp
    Author: Blake Gerard
    Description:
        A Reg represents a register of physical (qu)bits mapped to their
        logical counterparts. Internally, an instance of Reg maintains
        an std::map from qubit_id -> qubit_id, where the keys are physical
        qubits in the device and values are their corresponding logical qubits.
        This is done to make register permutation easy.
*/

#ifndef QRANE_REG_HPP
#define QRANE_REG_HPP

#include "qrane_element.hpp"
#include "qrane_shared.hpp"
#include <map>

namespace qrane {

enum reg_variant_e {
	QREG,
	CREG,
};

typedef std::map<qubit_id, qubit_id> reg_t;

class Reg : public Element {

public: 
	Reg();
	Reg(element_variant_e element_variant, reg_variant_e reg_variant, 
		std::string device, std::string name);
	Reg(element_variant_e element_variant, reg_variant_e reg_variant, 
		std::string device, std::string name, unsigned int size);
	Reg(element_variant_e element_variant, reg_variant_e reg_variant,
		std::string device, std::string name, qubit_id start, qubit_id stop);
	Reg(element_variant_e element_variant, reg_variant_e reg_variant,
		std::string device, std::string name, std::initializer_list<qubit_id> reg);
		
	static Reg trivial_layout(unsigned int size);
	static Reg read_from_edge_list_file(std::string mapping_path);
	
	qubit_id operator[](unsigned int index) const;
	bool operator==(const Reg& rhs) const;
	qubit_id at(qubit_id) const;
	std::string name() const;
	unsigned int size() const;
	bool count(qubit_id id) const;
	bool is_qreg() const;
	bool is_creg() const;
	std::string to_string() const;
	void print_current_mapping();

	void insert(qubit_id id);
	void insert(qubit_id physical, qubit_id logical);
	void permute_register(qubit_id lhs, qubit_id rhs);

	reg_t::iterator begin();
	reg_t::iterator end();
	reg_t::const_iterator begin() const;
	reg_t::const_iterator end() const;

private:
	reg_variant_e variant_;
	std::string device_;
	std::string name_;
	reg_t reg_;
};
}

#endif
