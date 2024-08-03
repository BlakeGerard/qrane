/*
Qrane
Filename: Qop.hpp
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

#ifndef QRANE_QOP_HPP
#define QRANE_QOP_HPP

#include "qrane_argument.hpp"
#include "qrane_element.hpp"
#include "qrane_parameter.hpp"
#include "qrane_shared.hpp"
#include <vector>

namespace qrane {

enum qop_variant_e { GATE, MEASURE, RESET, OPAQUE, BARRIER };

class Qop : public Element {

public:
  // Constructors
  Qop();
  Qop(element_variant_e element_variant, qop_variant_e qop_variant, int id,
      std::string name);
  Qop(element_variant_e element_variant, qop_variant_e qop_variant, int id,
      std::string name, std::vector<std::shared_ptr<Argument>> args);
  Qop(element_variant_e element_variant, qop_variant_e qop_variant, int id,
      std::string name, std::vector<std::shared_ptr<Parameter>>,
      std::vector<std::shared_ptr<Argument>> args);

  // Static functions
  static std::shared_ptr<Qop> make_unassigned_2Q_gate(std::string name,
                                                      std::string reg_name,
                                                      qubit_id arg0,
                                                      qubit_id arg1);

  // Operator overloads
  bool operator==(const Qop &rhs);

  // Accessors
  std::string name() const;
  std::string to_string() const;
  unsigned int num_params() const;
  unsigned int num_args() const;
  bool is_1Q_gate() const;
  bool is_2Q_gate() const;
  std::shared_ptr<Parameter> param(unsigned int index);
  std::shared_ptr<Argument> arg(unsigned int index);
  std::vector<std::shared_ptr<Parameter>> parameters();
  std::vector<std::shared_ptr<Argument>> arguments();
  int id() const { return id_; }

private:
  qop_variant_e variant_;
  int id_;
  std::string name_;
  std::vector<std::shared_ptr<Parameter>> params_;
  std::vector<std::shared_ptr<Argument>> args_;
};
} // namespace qrane

#endif
