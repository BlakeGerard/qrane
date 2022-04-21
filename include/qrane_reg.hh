/*
    Project: qrane
    Filename: Reg.hh
    Author: Blake Gerard
    Description:
        A Reg represents a register of physical (qu)bits mapped to their
        logical counterparts. Internally, an instance of Reg maintains
        an std::map from qubit_id -> qubit_id, where the keys are physical
        qubits in the device and values are their corresponding logical qubits.
        This is done to make register permutation easy.
*/

#ifndef QRANE_REG_H
#define QRANE_REG_H

#include <map>

#include "qrane_element.hh"
#include "qrane_shared.hh"

namespace qrane {

    enum reg_variant_e {
        QREG,
        CREG,
    };

    typedef std::map<qubit_id, qubit_id> reg_variant_t;

    class Reg : public Element {

        private:
            reg_variant_e variant_;
            std::string device_;
            std::string name_;
            reg_variant_t reg_;

        public: 

            // Constructors
            Reg();
            Reg(element_variant_e element_variant, reg_variant_e reg_variant, 
                std::string device, std::string name);
            Reg(element_variant_e element_variant, reg_variant_e reg_variant, 
                std::string device, std::string name, unsigned int size);
            Reg(element_variant_e element_variant, reg_variant_e reg_variant,
                std::string device, std::string name, qubit_id start, qubit_id stop);
            Reg(element_variant_e element_variant, reg_variant_e reg_variant,
                std::string device, std::string name, std::initializer_list<qubit_id> reg);
                
            // Static functions
            static Reg trivial_layout(unsigned int size);
            static Reg read_from_edge_list_file(std::string mapping_path);
            
            // Operator overloads
            qubit_id operator[](unsigned int index) const;
            bool operator==(const Reg& rhs) const;

            // Iterators
            reg_variant_t::iterator begin();
            reg_variant_t::iterator end();
            reg_variant_t::const_iterator begin() const;
            reg_variant_t::const_iterator end() const;

            // Accessors
            qubit_id at(qubit_id) const;
            std::string name() const;
            unsigned int size() const;
            std::string to_string() const;
            bool count(qubit_id id) const;
            bool is_qreg() const;
            bool is_creg() const;

            // Mutators
            void insert(qubit_id id);
            void insert(qubit_id physical, qubit_id logical);
            void permute_register(qubit_id lhs, qubit_id rhs);

            // Printing
            void print_current_mapping();
    };
}

#endif