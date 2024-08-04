/*
Qrane
Filename: qrane_statement.hh
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

#ifndef QRANE_STATEMENT
#define QRANE_STATEMENT

#include <string>
#include <stdlib.h>
#include <iostream>
#include "qrane_explist.hh"
#include "qrane_argument.hh"
#include "qrane_arglist.hh"

class qrane_statement {

    public:
        enum statement_type {
            DECL = 0,
            QOP, 
            QREG
        };
        qrane_statement();
        virtual ~qrane_statement();
        void set_statement_type(statement_type type);
        statement_type get_statement_type();

        void print_type();

        virtual void set_if_condition(std::string if_id, int if_nnint) {}
        virtual void set_idlist(qrane_idlist* idlist) {}
    
    protected:
        statement_type stmt_type;
};

#endif