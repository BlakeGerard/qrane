/*
Qrane
Filename: Statement.cc
Creation date: July 18, 2020
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

#include <algorithm>

#include "barvinok/isl.h"
#include "isl/aff.h"

#include "qrane_statement.hpp"
#include "qrane_utils.hpp"


namespace qrane {

	Statement::Statement() {
		domain_ = nullptr;
		access_mat_ = nullptr;
	}

	Statement::~Statement() {
	}

	Statement::Statement(Statement const& rhs) {
		id_ = rhs.id_;
		op_name_ = rhs.op_name_;
		num_args_ = rhs.num_args_;
		dim_ = rhs.dim_;
		card_ = rhs.card_;
		lex_ = rhs.lex_;
		affine_list_ = rhs.affine_list_;
		sub_statements_ = rhs.sub_statements_;
		component_qops_ = rhs.component_qops_;
		domain_ = isl_set_copy(rhs.domain_);
		access_mat_ = isl_mat_copy(rhs.access_mat_);
	}

	Statement& Statement::operator=(Statement const& rhs) {
		id_ = rhs.id_;
		op_name_ = rhs.op_name_;
		num_args_ = rhs.num_args_;
		dim_ = rhs.dim_;
		card_ = rhs.card_;
		lex_ = rhs.lex_;
		affine_list_ = rhs.affine_list_;
		sub_statements_ = rhs.sub_statements_;
		component_qops_ = rhs.component_qops_;
		domain_ = isl_set_copy(rhs.domain_);
		access_mat_ = isl_mat_copy(rhs.access_mat_);
		return *this;
	}

	/*
		This is the main one
	*/
	Statement::Statement(isl_ctx* ctx, unsigned int id_,
						 const std::map<qop_id, std::shared_ptr<Qop>>& qops, std::vector<qop_id>& qop_ids) {
		id_ = id_;
		op_name_ = qops.at(qop_ids[0])->name();
		num_args_ = qops.at(qop_ids[0])->num_args();
		dim_ = 1;
		card_ = qop_ids.size();
		
		component_qops_ = std::move(qop_ids);
		
		if (component_qops_.size() == 1) { lex_ = LEX_SINGLE; }
		else if (component_qops_[1] - component_qops_[0] > 0) { lex_ = LEX_POS; }
		else if (component_qops_[1] - component_qops_[0] < 0) { lex_ = LEX_NEG; }
		else { assert(false); }
		
		domain_ = nullptr;
		access_mat_ = nullptr;

		build_affine_list_from_qop_ids(qops, qop_ids);
		build_local_domain(ctx);
	}

	/*
		This is the main one
	*/
	void Statement::build_affine_list_from_qop_ids(const std::map<qop_id, std::shared_ptr<Qop>>& qops, std::vector<qop_id>& qop_ids) {
		if (card_ == 1) {
			for (const auto& arg : qops.at(qop_ids[0])->arguments()) { 
				affine_list_.push_back(std::make_pair(0, arg->index())); 
			}
		} else {
			auto op_0_args = qops.at(qop_ids[0])->arguments();
			auto op_1_args = qops.at(qop_ids[1])->arguments();

			int x1 = 0;
			int x2 = 1;
			int y1, y2;
			float m, b;
		
			for (int i = 0; i < num_args_; ++i) {
				y1 = op_0_args.at(i)->index();
				y2 = op_1_args.at(i)->index();
				m = float(y2 - y1) / float(x2 - x1);
				b = float(y1) - m * float(x1);
				affine_list_.push_back(std::pair<int, int>(m, b));
			}
		}
	}

	void Statement::raise_dimensionality() {
		dim_ += 1;
	}

	void Statement::set_dimensionality(unsigned int dim) {
		dim_ = dim;
	}

	void Statement::set_domain(isl_set* new_domain) {
		domain_ = new_domain;
	}

	void Statement::set_access_mat(isl_mat* mat) {
		access_mat_ = mat;
	}

	void Statement::add_component_qops(const std::vector<qop_id>& qop_ids) {
		component_qops_.insert(component_qops_.end(), qop_ids.begin(), qop_ids.end());
	}

	/*
		This is only used to initialize local_domain for the
		one-dimensional case.
	*/
	__isl_keep void Statement::build_local_domain(isl_ctx* ctx) {
		isl_val* v;
		isl_id* id;
		isl_multi_aff* ma;
		isl_aff* var, *cst;
		isl_basic_set* bset;
		isl_space* spc = isl_space_unit(ctx);

		std::string id_string = std::string("S");
		id_string.append(std::to_string(id_));
		id = isl_id_alloc(ctx, id_string.c_str(), nullptr);
		spc = isl_space_add_named_tuple_id_ui(spc, id, 1);
		ma = isl_multi_aff_identity_on_domain_space(isl_space_copy(spc));
		var = isl_multi_aff_get_at(ma, 0);
		v = isl_val_int_from_ui(ctx, 0);
		cst = isl_aff_val_on_domain_space(isl_space_copy(spc), v);
		bset = isl_aff_ge_basic_set(isl_aff_copy(var), cst);

		v = isl_val_int_from_ui(ctx, card_ - 1);
		cst = isl_aff_val_on_domain_space(spc, v);
		bset = isl_basic_set_intersect(bset, isl_aff_le_basic_set(var, cst));
		bset = isl_basic_set_preimage_multi_aff(bset, ma);
		domain_ = isl_set_from_basic_set(bset);

		int rows = card_;
		int cols = dim_ + 2 * (num_args_); // 1 column for i and 2 columns per arg(1 offset and 1 value)

		access_mat_ = isl_mat_alloc(ctx, rows, cols);
		for (int row = rows; row-- > 0;) {
			int val = -1*row+(rows-1); // This just means the last row has point 0, second to last has point 1, etc.
			access_mat_ = isl_mat_set_element_si(access_mat_, row, cols-1, val);
			for (int ctr = num_args_; ctr-- > 0;) {
				int index = 2*ctr;
				int fnct = -1*ctr+(num_args_-1);
				access_mat_ = isl_mat_set_element_si(access_mat_, row, index+1, 1);
				access_mat_ = isl_mat_set_element_si(access_mat_, row, index, affine_list_[fnct].first * val + affine_list_[fnct].second);
			}	
		}
	}

	__isl_give isl_set* Statement::lexmin() const {
		return isl_set_lexmin(isl_set_copy(domain_));
	}

	__isl_give isl_set* Statement::lexmax() const {
		return isl_set_lexmax(isl_set_copy(domain_));
	}

	__isl_give isl_set* Statement::domain_copy() const {
		return isl_set_copy(domain_);
	}

	__isl_give isl_mat* Statement::access_mat_copy() const {
		return isl_mat_copy(access_mat_);
	}

	std::string Statement::domain_string() const {
		return std::string(isl_set_to_str(isl_set_copy(domain_)));
	}

	unsigned int Statement::card() const {
		return component_qops_.size();
	}

	unsigned int Statement::dim() const {
		return dim_;
	}

	qop_id Statement::time_space_min() const {
		return *std::min_element(component_qops_.begin(), component_qops_.end());
	}
			
	qop_id Statement::time_space_max() const {
		return *std::max_element(component_qops_.begin(), component_qops_.end());
	}

	void Statement::back_substitution(isl_ctx* ctx) {
		access_mat_ = isl_mat_row_basis(access_mat_);
		access_mat_ = utils::back_substitute_isl_mat(ctx, access_mat_, num_args_, dim_);
	}

	int Statement::get_coefficient(unsigned int arg, unsigned int dim) const {
		isl_val* val = isl_mat_get_element_val(access_mat_, arg, dim);
		return isl_val_get_num_si(val);
	}
}
