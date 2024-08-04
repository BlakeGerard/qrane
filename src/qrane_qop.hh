/*
Qrane
Filename: qrane_qop.hh
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

#ifndef QRANE_QOP
#define QRANE_QOP

#include <string>
#include <stdlib.h>
#include <iostream>
#include "qrane_statement.hh"
#include "qrane_explist.hh"
#include "qrane_arglist.hh"
#include "qrane_argument.hh"
//#include "include/qrane_statement.hh"
//#include "include/qrane_explist.hh"
//#include "include/qrane_arglist.hh"
//#include "include/qrane_argument.hh"

class qrane_qop : public qrane_statement {

    public:

        enum qop_type {
            U = 0,
            CX,
            CUSTOM,
            MEASURE,
            RESET
        };

        virtual ~qrane_qop();

        void set_qop_type(qop_type type);
        qop_type get_qop_type();
        void set_dim1_qop_num(unsigned int val);
        unsigned int get_dim1_qop_num();
        void set_if_condition(std::string id, int nninteger);

        // Virtual set methods
        virtual void set_explist(qrane_explist* explist) {}
        virtual void set_argument(qrane_argument* argument) {}
        virtual void set_argument1(qrane_argument* argument1) {}
        virtual void set_argument2(qrane_argument* argument2) {}
        virtual void set_id(std::string id) {}
        virtual void set_arglist(qrane_arglist* arglist) {}

        // Virtual get methods
        virtual std::string get_id() = 0;
		virtual std::string to_str() = 0;
        virtual qrane_arglist* get_arglist() = 0;
        virtual unsigned long get_first_arg_index() = 0;
        virtual unsigned long get_target_index() = 0;
        virtual std::size_t num_args() const = 0;
        virtual unsigned int at(int index) const = 0; 
    
    protected:
        qop_type t_qop;
        unsigned int dim1_qop_num;

        // This is just for catching if statements, 
        bool conditional;
        std::string if_id;
        int if_nnint;
};

class qrane_u : public qrane_qop {
    protected:
        qrane_explist* explist;
        qrane_arglist* arglist;

    public:
        qrane_u();
        ~qrane_u();
        void set_explist(qrane_explist* explist);
        void set_arglist(qrane_arglist* arglist);

        qrane_arglist* get_arglist();
        unsigned long get_first_arg_index();
        unsigned long get_target_index();
        std::string get_id();
		std::string to_str();
        std::size_t num_args() const;
        unsigned int at(int index) const;
};

class qrane_cx : public qrane_qop {
    protected:
        qrane_arglist* arglist;

    public:
        qrane_cx();
        ~qrane_cx();
        void set_arglist(qrane_arglist* arglist);

        qrane_arglist* get_arglist();
        unsigned long get_first_arg_index();
        unsigned long get_target_index();
        std::string get_id();
        std::size_t num_args() const;
		std::string to_str();
        unsigned int at(int index) const;
};

class qrane_custom : public qrane_qop {
    protected:
        std::string id;
        qrane_explist* explist;
        qrane_arglist* arglist;

    public:
        qrane_custom();
        ~qrane_custom();
        void set_id(std::string id);
        void set_explist(qrane_explist* explist);
        void set_arglist(qrane_arglist* arglist);

        qrane_arglist* get_arglist();
        unsigned long get_first_arg_index();
        unsigned long get_target_index();
        std::string get_id();
        std::size_t num_args() const;
		std::string to_str();
        unsigned int at(int index) const;
};

class qrane_measure : public qrane_qop {
    protected:
        qrane_arglist* arglist;

    public:
        qrane_measure();
        ~qrane_measure();
        void set_arglist(qrane_arglist* arglist);

        qrane_arglist* get_arglist();
        unsigned long get_first_arg_index();
        unsigned long get_target_index();
        std::string get_id();
        std::size_t num_args() const;
		std::string to_str();
        unsigned int at(int index) const;
};

class qrane_reset : public qrane_qop {
    protected:
        qrane_arglist* arglist;

    public:
        qrane_reset();
        ~qrane_reset();
        void set_arglist(qrane_arglist* arglist);

        qrane_arglist* get_arglist();
        unsigned long get_first_arg_index();
        unsigned long get_target_index();
        std::string get_id();
        std::size_t num_args() const;
		std::string to_str();
        unsigned int at(int index) const;
};

#endif