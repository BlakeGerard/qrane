/*
Qrane
Filename: qrane_arglist.cc
Creation date: July 2, 2020
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

#include "qrane_arglist.hh"

/* ANYLIST */
qrane_arglist::qrane_arglist() {};

qrane_arglist::~qrane_arglist() {};

void qrane_arglist::set_type(arglist_type type) {
    this->type = type;
};

/* IDLIST */
qrane_idlist::qrane_idlist() {};
qrane_idlist::~qrane_idlist() {
    
};

void qrane_idlist::add_id(std::string id) {
    this->idlist.push_back(id);
};

std::size_t qrane_idlist::size() {
    return this->idlist.size();
}

// TERRIBLE CODE. FIND SOMETHING BETTER LATER
int qrane_idlist::get_arg_index_val(int index) {
    return 0;
};

/* MIXEDLIST */
qrane_mixedlist::qrane_mixedlist() {};
qrane_mixedlist::~qrane_mixedlist() {
    for (auto arg : arglist) {
        delete arg;
    }
    arglist.clear();
};

void qrane_mixedlist::add_argument(qrane_argument* arg) {
    this->arglist.push_back(arg);
};

std::vector<qrane_argument*> qrane_mixedlist::get_arglist() {
    return this->arglist;
};

qrane_argument* qrane_mixedlist::get_first_control() {
    return this->arglist.front();
};

qrane_argument* qrane_mixedlist::get_target() {
    return this->arglist.back();
};

std::size_t qrane_mixedlist::size() {
    return this->arglist.size();
}

int qrane_mixedlist::get_arg_index_val(int index) {
    return this->arglist.at(index)->get_index();
};

