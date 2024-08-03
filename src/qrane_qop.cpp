#include "qrane_qop.hpp"

namespace qrane {

Qop::Qop() : Element(element_variant_e::QOP) {
  variant_ = qop_variant_e::GATE;
  name_ = std::string("DEFAULT_QOP");
}

Qop::Qop(element_variant_e statement_type, qop_variant_e qop_type,
         std::string name)
    : Element(statement_type) {
  variant_ = qop_type;
  name_ = name;
}

Qop::Qop(element_variant_e statement_type, qop_variant_e qop_type,
         std::string name, std::vector<std::shared_ptr<Argument>> args)
    : Element(statement_type) {
  variant_ = qop_type;
  name_ = name;
  args_ = args;
}

Qop::Qop(element_variant_e element_variant_e, qop_variant_e qop_variant_e,
         std::string name, std::vector<std::shared_ptr<Parameter>> params,
         std::vector<std::shared_ptr<Argument>> args)
    : Element(element_variant_e) {
  variant_ = qop_variant_e;
  name_ = name;
  params_ = params;
  args_ = args;
}

std::string Qop::name() const { return name_; }

unsigned int Qop::num_params() const { return params_.size(); }

unsigned int Qop::num_args() const { return args_.size(); }

std::shared_ptr<Parameter> Qop::param(unsigned int index) {
  return params_.at(index);
}

std::shared_ptr<Argument> Qop::arg(unsigned int index) {
  return args_.at(index);
}

std::vector<std::shared_ptr<Parameter>> Qop::parameters() { return params_; }

std::vector<std::shared_ptr<Argument>> Qop::arguments() { return args_; }

/*
        Equality operator overload. This does NOT check for qop_id equality.
*/
bool Qop::operator==(const Qop &rhs) {
  bool c0 = variant_ == rhs.variant_;
  bool c1 = name_ == rhs.name_;
  bool c2 = params_ == rhs.params_;
  bool c3 = args_ == rhs.args_;
  return c0 && c1 && c2 && c3;
}

std::shared_ptr<Qop> Qop::make_unassigned_2Q_gate(std::string name,
                                                  std::string reg_name,
                                                  qubit_id arg0,
                                                  qubit_id arg1) {
  auto q_arg0 = std::make_shared<Argument>(reg_name, arg0);
  auto q_arg1 = std::make_shared<Argument>(reg_name, arg1);
  auto ret = Qop(element_variant_e::QOP, qop_variant_e::GATE, -1, name,
                 {q_arg0, q_arg1});
  return std::make_shared<Qop>(ret);
}

bool Qop::is_1Q_gate() const { return args_.size() == 1; }

bool Qop::is_2Q_gate() const { return args_.size() == 2; }

std::string Qop::to_string() const {
  std::ostringstream strm;
  unsigned int ctr;

  strm << name_;
  if (num_params()) {
    ctr = 0;
    strm << "(";
    for (const auto &param : params_) {
      strm << param->to_string();
      if (ctr != num_params() - 1) {
        strm << ", ";
      }
      ++ctr;
    }
    strm << ")";
  }
  strm << " ";
  if (num_args()) {
    ctr = 0;
    for (const auto &arg : args_) {
      strm << arg->to_string();
      if (ctr != num_args() - 1) {
        strm << ", ";
      }
      ++ctr;
    }
    strm << ";";
  }
  return strm.str();
}
} // namespace qrane
