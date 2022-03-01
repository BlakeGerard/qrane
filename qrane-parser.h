// A Bison parser, made by GNU Bison 3.3.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file qrane-parser.h
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_QRANE_PARSER_H_INCLUDED
# define YY_YY_QRANE_PARSER_H_INCLUDED
// //                    "%code requires" blocks.
#line 17 "qrane-parser.y" // lalr1.cc:401

    #ifndef YY_NULLPTR
    #define YY_NULLPTR 0
    #endif

    #ifdef _QRANE_DEBUG_
    #define _D_(x) cout << x << endl
    #else
    #define _D_(x) 
    #endif

    #include "qrane_general.hh"

#line 62 "qrane-parser.h" // lalr1.cc:401

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 178 "qrane-parser.h" // lalr1.cc:401



  /// A Bison parser.
  class qrane_parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YYASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // T_REAL
      char dummy1[sizeof (double)];

      // T_NNINTEGER
      char dummy2[sizeof (int)];

      // anylist
      // mixedlist
      char dummy3[sizeof (qrane_arglist*)];

      // argument
      char dummy4[sizeof (qrane_argument*)];

      // decl
      // gatedecl
      char dummy5[sizeof (qrane_decl*)];

      // exp
      char dummy6[sizeof (qrane_exp*)];

      // unaryop
      char dummy7[sizeof (qrane_exp::unaryop_type)];

      // explist
      char dummy8[sizeof (qrane_explist*)];

      // idlist
      char dummy9[sizeof (qrane_idlist*)];

      // mainprogram
      char dummy10[sizeof (qrane_mainprogram*)];

      // qop
      // uop
      char dummy11[sizeof (qrane_qop*)];

      // statement
      char dummy12[sizeof (qrane_statement*)];

      // program
      // goplist
      char dummy13[sizeof (qrane_stmtlist*)];

      // T_ID
      char dummy14[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        T_EOF = 0,
        T_OPENQASM = 258,
        T_QREG = 259,
        T_CREG = 260,
        T_GATE_CUSTOM = 261,
        T_OPAQUE = 262,
        T_BARRIER = 263,
        T_MEASURE = 264,
        T_RESET = 265,
        T_U = 266,
        T_CX = 267,
        T_IF = 268,
        T_LPAR = 269,
        T_RPAR = 270,
        T_LCUR = 271,
        T_RCUR = 272,
        T_LBRA = 273,
        T_RBRA = 274,
        T_COMMA = 275,
        T_SEMICOLON = 276,
        T_ARROW = 277,
        T_ADD = 278,
        T_SUB = 279,
        T_MUL = 280,
        T_DIV = 281,
        T_CARROT = 282,
        T_EQLTY = 283,
        T_PI = 284,
        T_SIN = 285,
        T_COS = 286,
        T_TAN = 287,
        T_EXP = 288,
        T_LN = 289,
        T_SQRT = 290,
        T_ID = 291,
        T_REAL = 292,
        T_NNINTEGER = 293
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_arglist*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_arglist*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_argument*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_argument*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_decl*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_decl*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_exp*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_exp*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_exp::unaryop_type&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_exp::unaryop_type& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_explist*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_explist*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_idlist*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_idlist*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_mainprogram*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_mainprogram*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_qop*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_qop*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_statement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_statement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, qrane_stmtlist*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const qrane_stmtlist*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 37: // T_REAL
        value.template destroy< double > ();
        break;

      case 38: // T_NNINTEGER
        value.template destroy< int > ();
        break;

      case 48: // anylist
      case 50: // mixedlist
        value.template destroy< qrane_arglist* > ();
        break;

      case 51: // argument
        value.template destroy< qrane_argument* > ();
        break;

      case 43: // decl
      case 44: // gatedecl
        value.template destroy< qrane_decl* > ();
        break;

      case 53: // exp
        value.template destroy< qrane_exp* > ();
        break;

      case 54: // unaryop
        value.template destroy< qrane_exp::unaryop_type > ();
        break;

      case 52: // explist
        value.template destroy< qrane_explist* > ();
        break;

      case 49: // idlist
        value.template destroy< qrane_idlist* > ();
        break;

      case 40: // mainprogram
        value.template destroy< qrane_mainprogram* > ();
        break;

      case 46: // qop
      case 47: // uop
        value.template destroy< qrane_qop* > ();
        break;

      case 42: // statement
        value.template destroy< qrane_statement* > ();
        break;

      case 41: // program
      case 45: // goplist
        value.template destroy< qrane_stmtlist* > ();
        break;

      case 36: // T_ID
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The token.
      token_type token () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YYASSERT (tok == token::T_EOF || tok == token::T_OPENQASM || tok == token::T_QREG || tok == token::T_CREG || tok == token::T_GATE_CUSTOM || tok == token::T_OPAQUE || tok == token::T_BARRIER || tok == token::T_MEASURE || tok == token::T_RESET || tok == token::T_U || tok == token::T_CX || tok == token::T_IF || tok == token::T_LPAR || tok == token::T_RPAR || tok == token::T_LCUR || tok == token::T_RCUR || tok == token::T_LBRA || tok == token::T_RBRA || tok == token::T_COMMA || tok == token::T_SEMICOLON || tok == token::T_ARROW || tok == token::T_ADD || tok == token::T_SUB || tok == token::T_MUL || tok == token::T_DIV || tok == token::T_CARROT || tok == token::T_EQLTY || tok == token::T_PI || tok == token::T_SIN || tok == token::T_COS || tok == token::T_TAN || tok == token::T_EXP || tok == token::T_LN || tok == token::T_SQRT);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YYASSERT (tok == token::T_EOF || tok == token::T_OPENQASM || tok == token::T_QREG || tok == token::T_CREG || tok == token::T_GATE_CUSTOM || tok == token::T_OPAQUE || tok == token::T_BARRIER || tok == token::T_MEASURE || tok == token::T_RESET || tok == token::T_U || tok == token::T_CX || tok == token::T_IF || tok == token::T_LPAR || tok == token::T_RPAR || tok == token::T_LCUR || tok == token::T_RCUR || tok == token::T_LBRA || tok == token::T_RBRA || tok == token::T_COMMA || tok == token::T_SEMICOLON || tok == token::T_ARROW || tok == token::T_ADD || tok == token::T_SUB || tok == token::T_MUL || tok == token::T_DIV || tok == token::T_CARROT || tok == token::T_EQLTY || tok == token::T_PI || tok == token::T_SIN || tok == token::T_COS || tok == token::T_TAN || tok == token::T_EXP || tok == token::T_LN || tok == token::T_SQRT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::T_REAL);
      }
#else
      symbol_type (int tok, const double& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::T_REAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::T_NNINTEGER);
      }
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::T_NNINTEGER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::T_ID);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::T_ID);
      }
#endif
    };

    /// Build a parser object.
    qrane_parser (qrane_mainprogram* mainprogram_yyarg);
    virtual ~qrane_parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_EOF (location_type l)
      {
        return symbol_type (token::T_EOF, std::move (l));
      }
#else
      static
      symbol_type
      make_T_EOF (const location_type& l)
      {
        return symbol_type (token::T_EOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_OPENQASM (location_type l)
      {
        return symbol_type (token::T_OPENQASM, std::move (l));
      }
#else
      static
      symbol_type
      make_T_OPENQASM (const location_type& l)
      {
        return symbol_type (token::T_OPENQASM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_QREG (location_type l)
      {
        return symbol_type (token::T_QREG, std::move (l));
      }
#else
      static
      symbol_type
      make_T_QREG (const location_type& l)
      {
        return symbol_type (token::T_QREG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_CREG (location_type l)
      {
        return symbol_type (token::T_CREG, std::move (l));
      }
#else
      static
      symbol_type
      make_T_CREG (const location_type& l)
      {
        return symbol_type (token::T_CREG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_GATE_CUSTOM (location_type l)
      {
        return symbol_type (token::T_GATE_CUSTOM, std::move (l));
      }
#else
      static
      symbol_type
      make_T_GATE_CUSTOM (const location_type& l)
      {
        return symbol_type (token::T_GATE_CUSTOM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_OPAQUE (location_type l)
      {
        return symbol_type (token::T_OPAQUE, std::move (l));
      }
#else
      static
      symbol_type
      make_T_OPAQUE (const location_type& l)
      {
        return symbol_type (token::T_OPAQUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_BARRIER (location_type l)
      {
        return symbol_type (token::T_BARRIER, std::move (l));
      }
#else
      static
      symbol_type
      make_T_BARRIER (const location_type& l)
      {
        return symbol_type (token::T_BARRIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_MEASURE (location_type l)
      {
        return symbol_type (token::T_MEASURE, std::move (l));
      }
#else
      static
      symbol_type
      make_T_MEASURE (const location_type& l)
      {
        return symbol_type (token::T_MEASURE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_RESET (location_type l)
      {
        return symbol_type (token::T_RESET, std::move (l));
      }
#else
      static
      symbol_type
      make_T_RESET (const location_type& l)
      {
        return symbol_type (token::T_RESET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_U (location_type l)
      {
        return symbol_type (token::T_U, std::move (l));
      }
#else
      static
      symbol_type
      make_T_U (const location_type& l)
      {
        return symbol_type (token::T_U, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_CX (location_type l)
      {
        return symbol_type (token::T_CX, std::move (l));
      }
#else
      static
      symbol_type
      make_T_CX (const location_type& l)
      {
        return symbol_type (token::T_CX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_IF (location_type l)
      {
        return symbol_type (token::T_IF, std::move (l));
      }
#else
      static
      symbol_type
      make_T_IF (const location_type& l)
      {
        return symbol_type (token::T_IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_LPAR (location_type l)
      {
        return symbol_type (token::T_LPAR, std::move (l));
      }
#else
      static
      symbol_type
      make_T_LPAR (const location_type& l)
      {
        return symbol_type (token::T_LPAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_RPAR (location_type l)
      {
        return symbol_type (token::T_RPAR, std::move (l));
      }
#else
      static
      symbol_type
      make_T_RPAR (const location_type& l)
      {
        return symbol_type (token::T_RPAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_LCUR (location_type l)
      {
        return symbol_type (token::T_LCUR, std::move (l));
      }
#else
      static
      symbol_type
      make_T_LCUR (const location_type& l)
      {
        return symbol_type (token::T_LCUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_RCUR (location_type l)
      {
        return symbol_type (token::T_RCUR, std::move (l));
      }
#else
      static
      symbol_type
      make_T_RCUR (const location_type& l)
      {
        return symbol_type (token::T_RCUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_LBRA (location_type l)
      {
        return symbol_type (token::T_LBRA, std::move (l));
      }
#else
      static
      symbol_type
      make_T_LBRA (const location_type& l)
      {
        return symbol_type (token::T_LBRA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_RBRA (location_type l)
      {
        return symbol_type (token::T_RBRA, std::move (l));
      }
#else
      static
      symbol_type
      make_T_RBRA (const location_type& l)
      {
        return symbol_type (token::T_RBRA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_COMMA (location_type l)
      {
        return symbol_type (token::T_COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_T_COMMA (const location_type& l)
      {
        return symbol_type (token::T_COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_SEMICOLON (location_type l)
      {
        return symbol_type (token::T_SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_T_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::T_SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_ARROW (location_type l)
      {
        return symbol_type (token::T_ARROW, std::move (l));
      }
#else
      static
      symbol_type
      make_T_ARROW (const location_type& l)
      {
        return symbol_type (token::T_ARROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_ADD (location_type l)
      {
        return symbol_type (token::T_ADD, std::move (l));
      }
#else
      static
      symbol_type
      make_T_ADD (const location_type& l)
      {
        return symbol_type (token::T_ADD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_SUB (location_type l)
      {
        return symbol_type (token::T_SUB, std::move (l));
      }
#else
      static
      symbol_type
      make_T_SUB (const location_type& l)
      {
        return symbol_type (token::T_SUB, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_MUL (location_type l)
      {
        return symbol_type (token::T_MUL, std::move (l));
      }
#else
      static
      symbol_type
      make_T_MUL (const location_type& l)
      {
        return symbol_type (token::T_MUL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_DIV (location_type l)
      {
        return symbol_type (token::T_DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_T_DIV (const location_type& l)
      {
        return symbol_type (token::T_DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_CARROT (location_type l)
      {
        return symbol_type (token::T_CARROT, std::move (l));
      }
#else
      static
      symbol_type
      make_T_CARROT (const location_type& l)
      {
        return symbol_type (token::T_CARROT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_EQLTY (location_type l)
      {
        return symbol_type (token::T_EQLTY, std::move (l));
      }
#else
      static
      symbol_type
      make_T_EQLTY (const location_type& l)
      {
        return symbol_type (token::T_EQLTY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_PI (location_type l)
      {
        return symbol_type (token::T_PI, std::move (l));
      }
#else
      static
      symbol_type
      make_T_PI (const location_type& l)
      {
        return symbol_type (token::T_PI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_SIN (location_type l)
      {
        return symbol_type (token::T_SIN, std::move (l));
      }
#else
      static
      symbol_type
      make_T_SIN (const location_type& l)
      {
        return symbol_type (token::T_SIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_COS (location_type l)
      {
        return symbol_type (token::T_COS, std::move (l));
      }
#else
      static
      symbol_type
      make_T_COS (const location_type& l)
      {
        return symbol_type (token::T_COS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_TAN (location_type l)
      {
        return symbol_type (token::T_TAN, std::move (l));
      }
#else
      static
      symbol_type
      make_T_TAN (const location_type& l)
      {
        return symbol_type (token::T_TAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_EXP (location_type l)
      {
        return symbol_type (token::T_EXP, std::move (l));
      }
#else
      static
      symbol_type
      make_T_EXP (const location_type& l)
      {
        return symbol_type (token::T_EXP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_LN (location_type l)
      {
        return symbol_type (token::T_LN, std::move (l));
      }
#else
      static
      symbol_type
      make_T_LN (const location_type& l)
      {
        return symbol_type (token::T_LN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_SQRT (location_type l)
      {
        return symbol_type (token::T_SQRT, std::move (l));
      }
#else
      static
      symbol_type
      make_T_SQRT (const location_type& l)
      {
        return symbol_type (token::T_SQRT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_ID (std::string v, location_type l)
      {
        return symbol_type (token::T_ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_T_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_REAL (double v, location_type l)
      {
        return symbol_type (token::T_REAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_T_REAL (const double& v, const location_type& l)
      {
        return symbol_type (token::T_REAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_NNINTEGER (int v, location_type l)
      {
        return symbol_type (token::T_NNINTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_T_NNINTEGER (const int& v, const location_type& l)
      {
        return symbol_type (token::T_NNINTEGER, v, l);
      }
#endif


  private:
    /// This class is not copyable.
    qrane_parser (const qrane_parser&);
    qrane_parser& operator= (const qrane_parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const signed char yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const unsigned char yytable_[];

  static const short yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (size_type i)
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (int i)
      {
        return operator[] (size_type (i));
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (size_type i) const
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (int i) const
      {
        return operator[] (size_type (i));
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (int n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      size_type
      size () const YY_NOEXCEPT
      {
        return seq_.size ();
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, int range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (int i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        int range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 199,     ///< Last index in yytable_.
      yynnts_ = 16,  ///< Number of nonterminal symbols.
      yyfinal_ = 4, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 39  ///< Number of tokens.
    };


    // User arguments.
    qrane_mainprogram* mainprogram;
  };

  inline
  qrane_parser::token_number_type
  qrane_parser::yytranslate_ (token_type t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
    };
    const unsigned user_token_number_max_ = 293;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  qrane_parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 37: // T_REAL
        value.move< double > (std::move (that.value));
        break;

      case 38: // T_NNINTEGER
        value.move< int > (std::move (that.value));
        break;

      case 48: // anylist
      case 50: // mixedlist
        value.move< qrane_arglist* > (std::move (that.value));
        break;

      case 51: // argument
        value.move< qrane_argument* > (std::move (that.value));
        break;

      case 43: // decl
      case 44: // gatedecl
        value.move< qrane_decl* > (std::move (that.value));
        break;

      case 53: // exp
        value.move< qrane_exp* > (std::move (that.value));
        break;

      case 54: // unaryop
        value.move< qrane_exp::unaryop_type > (std::move (that.value));
        break;

      case 52: // explist
        value.move< qrane_explist* > (std::move (that.value));
        break;

      case 49: // idlist
        value.move< qrane_idlist* > (std::move (that.value));
        break;

      case 40: // mainprogram
        value.move< qrane_mainprogram* > (std::move (that.value));
        break;

      case 46: // qop
      case 47: // uop
        value.move< qrane_qop* > (std::move (that.value));
        break;

      case 42: // statement
        value.move< qrane_statement* > (std::move (that.value));
        break;

      case 41: // program
      case 45: // goplist
        value.move< qrane_stmtlist* > (std::move (that.value));
        break;

      case 36: // T_ID
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  qrane_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 37: // T_REAL
        value.copy< double > (YY_MOVE (that.value));
        break;

      case 38: // T_NNINTEGER
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 48: // anylist
      case 50: // mixedlist
        value.copy< qrane_arglist* > (YY_MOVE (that.value));
        break;

      case 51: // argument
        value.copy< qrane_argument* > (YY_MOVE (that.value));
        break;

      case 43: // decl
      case 44: // gatedecl
        value.copy< qrane_decl* > (YY_MOVE (that.value));
        break;

      case 53: // exp
        value.copy< qrane_exp* > (YY_MOVE (that.value));
        break;

      case 54: // unaryop
        value.copy< qrane_exp::unaryop_type > (YY_MOVE (that.value));
        break;

      case 52: // explist
        value.copy< qrane_explist* > (YY_MOVE (that.value));
        break;

      case 49: // idlist
        value.copy< qrane_idlist* > (YY_MOVE (that.value));
        break;

      case 40: // mainprogram
        value.copy< qrane_mainprogram* > (YY_MOVE (that.value));
        break;

      case 46: // qop
      case 47: // uop
        value.copy< qrane_qop* > (YY_MOVE (that.value));
        break;

      case 42: // statement
        value.copy< qrane_statement* > (YY_MOVE (that.value));
        break;

      case 41: // program
      case 45: // goplist
        value.copy< qrane_stmtlist* > (YY_MOVE (that.value));
        break;

      case 36: // T_ID
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  qrane_parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  qrane_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 37: // T_REAL
        value.move< double > (YY_MOVE (s.value));
        break;

      case 38: // T_NNINTEGER
        value.move< int > (YY_MOVE (s.value));
        break;

      case 48: // anylist
      case 50: // mixedlist
        value.move< qrane_arglist* > (YY_MOVE (s.value));
        break;

      case 51: // argument
        value.move< qrane_argument* > (YY_MOVE (s.value));
        break;

      case 43: // decl
      case 44: // gatedecl
        value.move< qrane_decl* > (YY_MOVE (s.value));
        break;

      case 53: // exp
        value.move< qrane_exp* > (YY_MOVE (s.value));
        break;

      case 54: // unaryop
        value.move< qrane_exp::unaryop_type > (YY_MOVE (s.value));
        break;

      case 52: // explist
        value.move< qrane_explist* > (YY_MOVE (s.value));
        break;

      case 49: // idlist
        value.move< qrane_idlist* > (YY_MOVE (s.value));
        break;

      case 40: // mainprogram
        value.move< qrane_mainprogram* > (YY_MOVE (s.value));
        break;

      case 46: // qop
      case 47: // uop
        value.move< qrane_qop* > (YY_MOVE (s.value));
        break;

      case 42: // statement
        value.move< qrane_statement* > (YY_MOVE (s.value));
        break;

      case 41: // program
      case 45: // goplist
        value.move< qrane_stmtlist* > (YY_MOVE (s.value));
        break;

      case 36: // T_ID
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  qrane_parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  qrane_parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  qrane_parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  qrane_parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  qrane_parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  qrane_parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  qrane_parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

  inline
  qrane_parser::token_type
  qrane_parser::by_type::token () const YY_NOEXCEPT
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
    };
    return token_type (yytoken_number_[type]);
  }


} // yy
#line 2219 "qrane-parser.h" // lalr1.cc:401




#endif // !YY_YY_QRANE_PARSER_H_INCLUDED
