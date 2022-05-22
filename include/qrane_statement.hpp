/*
Qrane
Filename: qrane_statement.hpp
Creation date: June 30, 2020
Copyright (C) 2020
*/

#ifndef QRANE_STATEMENT_HPP
#define QRANE_STATEMENT_HPP

#include <string>
#include <cstdlib>
#include <sstream>
#include <map>
#include <assert.h>

#include "isl/ctx.h"
#include "isl/space.h"
#include "isl/set.h"
#include "isl/union_set.h"
#include "isl/id.h"
#include "isl/val.h"
#include "isl/mat.h"
#include "isl/vec.h"
#include "isl/map.h"

#include "qrane_qop.hpp"
#include "qrane_shared.hpp"

namespace qrane {

enum lex_type_e {
    LEX_POS = 0,
    LEX_NEG,
    LEX_SUBSET,
	LEX_REMOVE,
    LEX_SINGLE
};

class Statement {

public:
            
	// Construcors
    Statement();
    ~Statement();
    Statement(isl_ctx* ctx, unsigned int domain_num,
              const std::map<qop_id, std::shared_ptr<Qop>>& qops_list, std::vector<qop_id>& qop_ids);
    Statement(Statement const& rhs);

    // Operator overloads
    Statement& operator=(Statement const& rhs);

    // Mutators
	void add_component_qops(const std::vector<qop_id>& qop_ids);
    void raise_dimensionality();
    void set_dimensionality(unsigned int dim);
    void back_substitution(isl_ctx* ctx);
    void set_domain(isl_set* new_domain);
    void set_access_mat(isl_mat* mat);
           
    // Accessors
    __isl_give isl_set* lexmin() const;
    __isl_give isl_set* lexmax() const;
    __isl_give isl_set* domain_copy() const;
    __isl_give isl_mat* access_mat_copy() const;
    std::string domain_string() const;
    unsigned int card() const;
    unsigned int dim() const;
	qop_id time_space_min() const;
    qop_id time_space_max() const;
    int get_coefficient(unsigned int arg, unsigned int dim) const;

private:
	statement_id id_;									// Unique Statement id
    std::string op_;									// Quantum operation name
    int args_;											// Number of argument to the operation
    unsigned int dim_;									// Statement dimensionality
    unsigned int card_;									// Statement cardinality
    lex_type_e lex_;									// Statement lexicographic order
	std::vector<qop_id> qops_;	            			// Tracks all qops in this domain

    isl_set* domain_;
    isl_mat* access_mat_;
    
	void build_affine_list_from_qop_ids(const std::map<qop_id, std::shared_ptr<Qop>>& qops, std::vector<qop_id>& qop_ids);
    __isl_keep void build_local_domain(__isl_keep isl_ctx* ctx);
};
}

#endif