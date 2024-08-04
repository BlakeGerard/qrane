/*
Qrane
Filename: qrane_decl.hh
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

#ifndef QRANE_DECL
#define QRANE_DECL

#include "qrane_arglist.hh"
#include "qrane_statement.hh"
#include "qrane_stmtlist.hh"
#include <iostream>
#include <stdlib.h>
#include <string>

class qrane_decl : public qrane_statement {

public:
  enum decl_type { QREG = 0, CREG, GATE, OPAQUE, BARRIER };

  qrane_decl();
  virtual ~qrane_decl();
  void set_decl_type(decl_type t_decl);
  decl_type get_decl_type();
  virtual void set_size(int nninteger) {}
  virtual void set_id(std::string id) {}
  virtual void set_idlist(qrane_idlist *idlist) {}
  virtual void set_arglist(qrane_arglist *arglist) {}
  virtual void set_paramlist(qrane_arglist *paramlist) {}
  virtual void set_goplist(qrane_stmtlist *goplist) {}

protected:
  decl_type t_decl;
};

class qrane_qreg : public qrane_decl {

protected:
  std::string id;
  int size;

public:
  qrane_qreg();
  ~qrane_qreg();
  void set_id(std::string id);
  void set_size(int nninteger);
  std::string get_id();
  int get_size();
};

class qrane_creg : public qrane_decl {

protected:
  std::string id;
  int size;

public:
  qrane_creg();
  ~qrane_creg();
  void set_id(std::string id);
  void set_size(int nninteger);
  std::string get_id();
  int get_size();
};

class qrane_gatedecl : public qrane_decl {

protected:
  std::string id;
  qrane_idlist *paramlist;
  qrane_idlist *arglist;
  qrane_stmtlist *goplist;

public:
  qrane_gatedecl();
  ~qrane_gatedecl();
  void set_id(std::string id);
  void set_arglist(qrane_idlist *idlist);
  void set_paramlist(qrane_idlist *paramlist);
  void set_goplist(qrane_stmtlist *goplist);
  std::string get_id();
  int get_size();
};

class qrane_opaque : public qrane_decl {

protected:
  std::string id;
  qrane_idlist *paramlist;
  qrane_idlist *arglist;

public:
  qrane_opaque();
  ~qrane_opaque();
  void set_id(std::string);
  void set_paramlist(qrane_idlist *paramlist);
  void set_arglist(qrane_idlist *idlist);
  std::string get_id();
  int get_size();
};

class qrane_barrier : public qrane_decl {

protected:
  qrane_arglist *arglist;

public:
  qrane_barrier();
  ~qrane_barrier();
  void set_arglist(qrane_arglist *arglist);
  std::string get_id();
  int get_size();
};

#endif