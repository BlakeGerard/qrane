/*
Qrane
Filename: qrane_domain.hh
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

#ifndef QRANE_DOMAIN
#define QRANE_DOMAIN

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

#include "qrane_qop.hh"
#include "qrane_shared.hh"

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
            statement_id id_;
            std::string op_name_;
            int num_args_;
            unsigned int dim_;
            unsigned int card_;
            lex_type_e lex_;
            std::vector<statement_id> sub_statements_;			// Tracks all domain_nums within this domain
            std::vector<qop_id> component_qops_;	            // Tracks all global_ids within this domain
            std::vector<std::pair<int, int>> affine_list_;
            isl_set* domain_;
            isl_mat* access_mat_;

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
            void build_affine_list_from_qop_ids(const std::map<qop_id, std::shared_ptr<Qop>>& qops, std::vector<qop_id>& qop_ids);
            __isl_keep void build_local_domain(__isl_keep isl_ctx* ctx);
    };
}

#endif