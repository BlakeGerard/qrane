/*
qrane_domain::qrane_domain(unsigned int domain_num, qrane_qop* qop) {
    local_domain = nullptr;
    access_mat = nullptr;
    this->domain_num = domain_num;
    this->gate_id = qop->get_id();
    this->args = qop->num_args();
    this->dimensionality = 1;
    this->consumed = 0;
	this->is_mergee = false;

    // Set the base index to 
    if (BASE_MODE == 0) { base = args - 1; } else { base = 0; }

    component_qops = std::vector<unsigned int>();
    component_qops.push_back(qop->get_dim1_qop_num());

    this->stmt_count = 1;

    recent.reserve(args);
    for (int i = 0; i < args; ++i) {
        recent.push_back(qop->at(i));
    }

    affine_list.reserve(args);
    //strides.reserve(args);
    
    //set_strides(qop);
    build_singleton_affine_list(qop);
};
*/

/*
__isl_keep qrane_domain::qrane_domain(__isl_keep isl_ctx* ctx, unsigned int domain_num, std::string gate_id, unsigned int num_args,
									  const function_identifier f_id, const function_neighbors neighbors, const qasm_ops_list qop_list) {
	local_domain = nullptr;
	access_mat = nullptr;
	this->domain_num = domain_num;
	this->gate_id = gate_id;
	this->args = num_args;
	this->dimensionality = 1;
	this->consumed = 0;
	this->stmt_count = neighbors.size();
	this->is_mergee = false;
	if (BASE_MODE == 0) { base = args - 1; } else { base = 0; }

	this->component_qops.insert(component_qops.end(), neighbors.begin(), neighbors.end());
	build_affine_list_from_points(neighbors, qop_list);
	build_local_domain(ctx);
	build_local_schedule(ctx);
}
*/

/*
void qrane_domain::build_singleton_affine_list(qrane_qop* qop) {
    for (std::size_t i = 0; i < qop->num_args(); ++i) {
        affine_list.push_back(std::pair<int, int>(0, qop->at(i)));
    }
};

void qrane_domain::build_affine_list_from_function_identifier(const function_identifier f_id, const qrane_qop* starting_point) {
    for (std::size_t i = 0; i < f_id.size(); ++i) {
        affine_list.push_back(std::pair<int, int>(f_id[i].second, starting_point->at(i)));
    }
};
*/

/*
void qrane_domain::build_affine_list_from_points(const function_neighbors qops, const qasm_ops_list qop_list) {
	function_neighbors::iterator it = qops.begin();
	auto find_lambda = [](const qop_identifier& id, unsigned int global) { return std::get<QOP_NUM_GLOBAL>(id) == global; };
	if (qops.size() == 1) {
		qop_identifier op_0 = *(std::find_if(qop_list.begin(), qop_list.end(), std::bind(find_lambda, std::placeholders::_1, *it)));
		std::vector<int> op_0_args = std::get<ARGS>(op_0);
		for (int i = 0; i < args; ++i) {
        	affine_list.push_back(std::pair<int, int>(0, op_0_args[i]));
		}
	} else {
		qop_identifier op_0 = *(std::find_if(qop_list.begin(), qop_list.end(), std::bind(find_lambda, std::placeholders::_1, *it)));
		std::advance(it, 1);
		qop_identifier op_1 = *(std::find_if(qop_list.begin(), qop_list.end(), std::bind(find_lambda, std::placeholders::_1, *it)));

		std::vector<int> op_0_args = std::get<ARGS>(op_0);
		std::vector<int> op_1_args = std::get<ARGS>(op_1);

		int x1 = 0;
    	int x2 = 1;
		int y1, y2;
		float m, b;
	
		for (int i = 0; i < args; ++i) {
    		y1 = op_0_args[i];
			y2 = op_1_args[i];
    		m = (y2 - y1) / (x2 - x1);
        	b = y1 - m*x1;
        	affine_list.push_back(std::pair<int, int>(m, b));
		}
	}
};
*/


/*
bool qrane_domain::build_affine_list(qrane_qop* qop) {
    bool ret = true;
    int x1 = 0;
    int x2 = 1;
    int y1, y2;
    int m, b;

    for (std::size_t i = 0; i < qop->num_args(); ++i) {
        y1 = recent[i];
        y2 = qop->at(i);
        m = (y2 - y1) / (x2 - x1);
        b = y1 - m*x1;
        affine_list[i].first = m;
        affine_list[i].second = b;
    }
    return ret;
}
*/

/*
void qrane_domain::set_strides(qrane_qop* qop) {

    if (stmt_count < 2) {
        for (std::size_t i = 0; i < qop->num_args(); ++i) {
            strides.push_back(0);
        }
    } else {
        strides.clear();
        for (std::size_t i = 0; i < qop->num_args(); ++i) {
            strides.push_back(qop->at(i) - recent[i]);
        }
    }
};
*/

/*
    Criteria for adding a new qop to this domain:
    1. The gate ids must match.
    2. If the ids match and the domain only has 1 statement, 
       then we approve the qop and build the domain elements.
    3. If the domain has two or more qops, then approval also 
       requires that linearity can be maintained between the
       arguments of the current qops in the domain and the new one.
bool qrane_domain::check_qop_belongs_in_domain(qrane_qop* qop) {
    bool ret;

    if (this->stmt_count < 2) {
        ret = initialize_domain_elements(qop);

    } else {
        ret = check_rw_linearity(qop);
        if (ret) { update_domain_elements(qop); }
    }
    return ret;
}
*/
/*
bool qrane_domain::initialize_domain_elements(qrane_qop* qop) {
    bool ret = true;

    // First we need to check if any arguments are the same.
    // This breaks linearity and is an immediate disqualification.
    for (std::size_t i = 0; i < qop->num_args(); ++i) {
        if (qop->at(i) == recent[i]) {
            ret = false;
            return ret;
        }
    }   

    stmt_count += 1;                                                                    // Increment the statement count
    //set_strides(qop);                                                           // Rebuild the strides between equivalent arguments of each qop                                                        // Set the is_scaled flag based on strides
    component_qops.push_back(qop->get_dim1_qop_num());
    build_affine_list(qop);

    for (std::size_t i = 0; i < qop->num_args(); ++i) {
        recent[i] = qop->at(i);
    }
    return ret;
};

void qrane_domain::update_domain_elements(qrane_qop* qop) {
    for (std::size_t i = 0; i < qop->num_args(); ++i) {
        recent[i] = qop->at(i);
    }
    stmt_count += 1;
    component_qops.push_back(qop->get_dim1_qop_num());
}
*/

/*
bool qrane_domain::check_rw_linearity(qrane_qop* qop) {
    for (int i = 0; i < args; ++i) {
        if (qop->at(i) != recent[i] + strides[i]) {
            return false;
        }
    }
    return true;
};
*/