/*
Qrane
Filename: qrane_exp.hh
Creation date: June 28, 2020
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

#ifndef QRANE_EXP
#define QRANE_EXP

class qrane_exp {

  public:

    enum binaryop_type {
      ADD = 0,
      SUB,
      MUL,
      DIV,
      CAR
    };

    enum unaryop_type {
      SIN = 0,
      COS,
      TAN,
      EXP,
      LN,
      SQRT,
      NEG,
      PAR
    };

    qrane_exp();
    virtual ~qrane_exp();
    virtual void set_unaryop_type(unaryop_type type) {}
    virtual void set_arg(qrane_exp* arg) {}
    virtual void set_binaryop_type(binaryop_type type) {}
    virtual void set_lhs(qrane_exp* lhs) {}
    virtual void set_rhs(qrane_exp* rhs) {}
};

template <typename T>
class qrane_value : public qrane_exp {

  protected:
    T value;

  public:
    qrane_value(T value);
    ~qrane_value();
};

class qrane_binaryop : public qrane_exp {

  protected:
    binaryop_type type;
    qrane_exp* lhs;
    qrane_exp* rhs;
  
  public:
    qrane_binaryop();
    ~qrane_binaryop();
    void set_binaryop_type(binaryop_type type);
    void set_lhs(qrane_exp* lhs);
    void set_rhs(qrane_exp* rhs);
};

class qrane_unaryop : public qrane_exp {

  protected:
    unaryop_type type;
    qrane_exp* arg;

  public:
    qrane_unaryop();
    ~qrane_unaryop();
    void set_unaryop_type(unaryop_type type);
    void set_arg(qrane_exp* arg);

};

#endif