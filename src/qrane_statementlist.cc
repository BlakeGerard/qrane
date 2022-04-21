/*
Qrane
Filename: qrane_statementlist.cc
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

#include <algorithm>
#include "qrane_statementlist.hh"

qrane_statementlist::qrane_statementlist() {
    this->statements = std::vector<std::shared_ptr<qrane_statement>>();
};

/*
    Initialize an empty statementlist and reserve size elements.
    Does NOT initialize with default elements.
*/
qrane_statementlist::qrane_statementlist(unsigned int size) {
    this->statements = std::vector<std::shared_ptr<qrane_statement>>(size);
    //this->statements = std::vector<std::shared_ptr<qrane_statement>>();
    //this->statements.reserve(size);
};

qrane_statementlist::qrane_statementlist(qrane_statementlist_const_iterator first,
                                         qrane_statementlist_const_iterator last) {
    this->statements = std::vector<std::shared_ptr<qrane_statement>>(first, last);
};

void qrane_statementlist::append(std::shared_ptr<qrane_statement> statement) {
    this->statements.push_back(statement);
};

void qrane_statementlist::insert(qrane_statementlist_iterator position, 
    qrane_statementlist_iterator begin, qrane_statementlist_iterator end) {
    this->statements.insert(position, begin, end);
};


std::shared_ptr<qrane_statement> qrane_statementlist::at(unsigned int index) {
    return this->statements.at(index);
};

qrane_statementlist qrane_statementlist::get_statements() {
    qrane_statementlist ret = qrane_statementlist(this->statements.size());
    for (auto stmt : this->statements) {
        ret.append(stmt);
    }
    return ret;
};

qrane_statementlist qrane_statementlist::get_qops() {
    qrane_statementlist ret = qrane_statementlist();
    for (auto stmt : this->statements) {
        if (stmt->is_qop()) {
            ret.append(stmt);
        }
    }
    return ret;
};

qrane_statementlist qrane_statementlist::get_registers() {
    qrane_statementlist ret = qrane_statementlist();
    for (auto stmt : this->statements) {
        if (stmt->is_reg()) {
            ret.append(stmt);
        }
    }
    return ret;
};

qrane_statementlist qrane_statementlist::get_1Q_gates() {
    qrane_statementlist ret = qrane_statementlist();
    for (auto stmt : this->statements) {
        if (stmt->is_qop()) {
            if (std::dynamic_pointer_cast<qrane_qop>(stmt)->is_1Q_gate()) {
                ret.append(stmt);
            }
        }
    }
    return ret;
};

qrane_statementlist qrane_statementlist::get_2Q_gates() {
    qrane_statementlist ret = qrane_statementlist();
    for (auto stmt : this->statements) {
        if (stmt->is_qop()) {
            if (std::dynamic_pointer_cast<qrane_qop>(stmt)->is_2Q_gate()) {
                ret.append(stmt);
            }
        }
    }
    return ret;
};

std::queue<std::shared_ptr<qrane_statement>> qrane_statementlist::get_statements_in_queue() {
    auto ret = std::queue<std::shared_ptr<qrane_statement>>();
    for (const auto& statement : this->statements) {
        ret.push(statement);
    };
    return ret;
}

bool qrane_statementlist::empty() const {
    return this->statements.empty();
};

unsigned int qrane_statementlist::size() const {
    return this->statements.size();
};

void qrane_statementlist::resize(unsigned int size) {
    this->statements.resize(size);
};

void qrane_statementlist::clear() {
    this->statements.clear();
};

void qrane_statementlist::reverse() {
    std::reverse(begin(), end());
};

qrane_statementlist_const_iterator 
    qrane_statementlist::cbegin() const {
        return this->statements.cbegin();
};

qrane_statementlist_const_iterator 
    qrane_statementlist::cend() const {
        return this->statements.cend();
};

qrane_statementlist_iterator qrane_statementlist::begin() {
    return this->statements.begin();
};

qrane_statementlist_iterator qrane_statementlist::end() {
    return this->statements.end();
};
  