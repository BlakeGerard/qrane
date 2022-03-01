// A Bison parser, made by GNU Bison 3.3.

// Skeleton implementation for Bison LALR(1) parsers in C++

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "qrane-parser.h"


// Unqualified %code blocks.
#line 31 "qrane-parser.y" // lalr1.cc:435

    #define _USE_MATH_DEFINES

    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <math.h>
    #include <cmath>
    #include <string.h>
    #include <cstddef>
    #include <string>
    #include <vector>
    #include <map>
    #include <string>
    #include <iostream>

    // Declare Flex/Bison variables and functions
    extern yy::qrane_parser::symbol_type yylex();
    extern char *yytext;
    extern yy::location loc;

    // Keep track of each qop's number in the sequence
    bool qreg_decl_seen = false;
    int dim1_qop_num = -1;
    unsigned int domain_nums = -1;

#line 72 "qrane-parser.c" // lalr1.cc:435


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 167 "qrane-parser.c" // lalr1.cc:510

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  qrane_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  qrane_parser::qrane_parser (qrane_mainprogram* mainprogram_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      mainprogram (mainprogram_yyarg)
  {}

  qrane_parser::~qrane_parser ()
  {}

  qrane_parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  qrane_parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  qrane_parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  qrane_parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  qrane_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  qrane_parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  qrane_parser::symbol_number_type
  qrane_parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  qrane_parser::stack_symbol_type::stack_symbol_type ()
  {}

  qrane_parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 37: // T_REAL
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 38: // T_NNINTEGER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 48: // anylist
      case 50: // mixedlist
        value.YY_MOVE_OR_COPY< qrane_arglist* > (YY_MOVE (that.value));
        break;

      case 51: // argument
        value.YY_MOVE_OR_COPY< qrane_argument* > (YY_MOVE (that.value));
        break;

      case 43: // decl
      case 44: // gatedecl
        value.YY_MOVE_OR_COPY< qrane_decl* > (YY_MOVE (that.value));
        break;

      case 53: // exp
        value.YY_MOVE_OR_COPY< qrane_exp* > (YY_MOVE (that.value));
        break;

      case 54: // unaryop
        value.YY_MOVE_OR_COPY< qrane_exp::unaryop_type > (YY_MOVE (that.value));
        break;

      case 52: // explist
        value.YY_MOVE_OR_COPY< qrane_explist* > (YY_MOVE (that.value));
        break;

      case 49: // idlist
        value.YY_MOVE_OR_COPY< qrane_idlist* > (YY_MOVE (that.value));
        break;

      case 40: // mainprogram
        value.YY_MOVE_OR_COPY< qrane_mainprogram* > (YY_MOVE (that.value));
        break;

      case 46: // qop
      case 47: // uop
        value.YY_MOVE_OR_COPY< qrane_qop* > (YY_MOVE (that.value));
        break;

      case 42: // statement
        value.YY_MOVE_OR_COPY< qrane_statement* > (YY_MOVE (that.value));
        break;

      case 41: // program
      case 45: // goplist
        value.YY_MOVE_OR_COPY< qrane_stmtlist* > (YY_MOVE (that.value));
        break;

      case 36: // T_ID
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  qrane_parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 37: // T_REAL
        value.move< double > (YY_MOVE (that.value));
        break;

      case 38: // T_NNINTEGER
        value.move< int > (YY_MOVE (that.value));
        break;

      case 48: // anylist
      case 50: // mixedlist
        value.move< qrane_arglist* > (YY_MOVE (that.value));
        break;

      case 51: // argument
        value.move< qrane_argument* > (YY_MOVE (that.value));
        break;

      case 43: // decl
      case 44: // gatedecl
        value.move< qrane_decl* > (YY_MOVE (that.value));
        break;

      case 53: // exp
        value.move< qrane_exp* > (YY_MOVE (that.value));
        break;

      case 54: // unaryop
        value.move< qrane_exp::unaryop_type > (YY_MOVE (that.value));
        break;

      case 52: // explist
        value.move< qrane_explist* > (YY_MOVE (that.value));
        break;

      case 49: // idlist
        value.move< qrane_idlist* > (YY_MOVE (that.value));
        break;

      case 40: // mainprogram
        value.move< qrane_mainprogram* > (YY_MOVE (that.value));
        break;

      case 46: // qop
      case 47: // uop
        value.move< qrane_qop* > (YY_MOVE (that.value));
        break;

      case 42: // statement
        value.move< qrane_statement* > (YY_MOVE (that.value));
        break;

      case 41: // program
      case 45: // goplist
        value.move< qrane_stmtlist* > (YY_MOVE (that.value));
        break;

      case 36: // T_ID
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  qrane_parser::stack_symbol_type&
  qrane_parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 37: // T_REAL
        value.move< double > (that.value);
        break;

      case 38: // T_NNINTEGER
        value.move< int > (that.value);
        break;

      case 48: // anylist
      case 50: // mixedlist
        value.move< qrane_arglist* > (that.value);
        break;

      case 51: // argument
        value.move< qrane_argument* > (that.value);
        break;

      case 43: // decl
      case 44: // gatedecl
        value.move< qrane_decl* > (that.value);
        break;

      case 53: // exp
        value.move< qrane_exp* > (that.value);
        break;

      case 54: // unaryop
        value.move< qrane_exp::unaryop_type > (that.value);
        break;

      case 52: // explist
        value.move< qrane_explist* > (that.value);
        break;

      case 49: // idlist
        value.move< qrane_idlist* > (that.value);
        break;

      case 40: // mainprogram
        value.move< qrane_mainprogram* > (that.value);
        break;

      case 46: // qop
      case 47: // uop
        value.move< qrane_qop* > (that.value);
        break;

      case 42: // statement
        value.move< qrane_statement* > (that.value);
        break;

      case 41: // program
      case 45: // goplist
        value.move< qrane_stmtlist* > (that.value);
        break;

      case 36: // T_ID
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  qrane_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  qrane_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  qrane_parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  qrane_parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  qrane_parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  qrane_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  qrane_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  qrane_parser::debug_level_type
  qrane_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  qrane_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  qrane_parser::state_type
  qrane_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  qrane_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  qrane_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  qrane_parser::operator() ()
  {
    return parse ();
  }

  int
  qrane_parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 37: // T_REAL
        yylhs.value.emplace< double > ();
        break;

      case 38: // T_NNINTEGER
        yylhs.value.emplace< int > ();
        break;

      case 48: // anylist
      case 50: // mixedlist
        yylhs.value.emplace< qrane_arglist* > ();
        break;

      case 51: // argument
        yylhs.value.emplace< qrane_argument* > ();
        break;

      case 43: // decl
      case 44: // gatedecl
        yylhs.value.emplace< qrane_decl* > ();
        break;

      case 53: // exp
        yylhs.value.emplace< qrane_exp* > ();
        break;

      case 54: // unaryop
        yylhs.value.emplace< qrane_exp::unaryop_type > ();
        break;

      case 52: // explist
        yylhs.value.emplace< qrane_explist* > ();
        break;

      case 49: // idlist
        yylhs.value.emplace< qrane_idlist* > ();
        break;

      case 40: // mainprogram
        yylhs.value.emplace< qrane_mainprogram* > ();
        break;

      case 46: // qop
      case 47: // uop
        yylhs.value.emplace< qrane_qop* > ();
        break;

      case 42: // statement
        yylhs.value.emplace< qrane_statement* > ();
        break;

      case 41: // program
      case 45: // goplist
        yylhs.value.emplace< qrane_stmtlist* > ();
        break;

      case 36: // T_ID
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 125 "qrane-parser.y" // lalr1.cc:919
    {
                mainprogram->add_stmtlist(yystack_[0].value.as < qrane_stmtlist* > ());
            }
#line 819 "qrane-parser.c" // lalr1.cc:919
    break;

  case 3:
#line 130 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_stmtlist* > () = new qrane_stmtlist();
            yylhs.value.as < qrane_stmtlist* > ()->add_statement(yystack_[0].value.as < qrane_statement* > ());
        }
#line 828 "qrane-parser.c" // lalr1.cc:919
    break;

  case 4:
#line 135 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_stmtlist* > () = yystack_[1].value.as < qrane_stmtlist* > ();
            yylhs.value.as < qrane_stmtlist* > ()->add_statement(yystack_[0].value.as < qrane_statement* > ());
        }
#line 837 "qrane-parser.c" // lalr1.cc:919
    break;

  case 5:
#line 141 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_statement* > () = yystack_[0].value.as < qrane_decl* > ();
          }
#line 845 "qrane-parser.c" // lalr1.cc:919
    break;

  case 6:
#line 145 "qrane-parser.y" // lalr1.cc:919
    {
            yystack_[2].value.as < qrane_decl* > ()->set_goplist(yystack_[1].value.as < qrane_stmtlist* > ());
            yylhs.value.as < qrane_statement* > () = yystack_[2].value.as < qrane_decl* > ();
          }
#line 854 "qrane-parser.c" // lalr1.cc:919
    break;

  case 7:
#line 150 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_statement* > () = yystack_[1].value.as < qrane_decl* > ();
          }
#line 862 "qrane-parser.c" // lalr1.cc:919
    break;

  case 8:
#line 154 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_decl *opaque = new qrane_opaque();
            opaque->set_statement_type(qrane_statement::statement_type::DECL);
            opaque->set_decl_type(qrane_decl::decl_type::OPAQUE);
            opaque->set_id(yystack_[2].value.as < std::string > ());
            opaque->set_paramlist(new qrane_idlist());
            opaque->set_arglist(yystack_[1].value.as < qrane_idlist* > ());
            yylhs.value.as < qrane_statement* > () = opaque;
          }
#line 876 "qrane-parser.c" // lalr1.cc:919
    break;

  case 9:
#line 164 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_decl *opaque = new qrane_opaque();
            opaque->set_statement_type(qrane_statement::statement_type::DECL);
            opaque->set_decl_type(qrane_decl::decl_type::OPAQUE);
            opaque->set_id(yystack_[4].value.as < std::string > ());
            opaque->set_paramlist(new qrane_idlist());
            opaque->set_arglist(yystack_[1].value.as < qrane_idlist* > ());
            yylhs.value.as < qrane_statement* > () = opaque;
          }
#line 890 "qrane-parser.c" // lalr1.cc:919
    break;

  case 10:
#line 174 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_decl *opaque = new qrane_opaque();
            opaque->set_statement_type(qrane_statement::statement_type::DECL);
            opaque->set_decl_type(qrane_decl::decl_type::OPAQUE);
            opaque->set_id(yystack_[5].value.as < std::string > ());
            opaque->set_paramlist(yystack_[3].value.as < qrane_idlist* > ());
            opaque->set_arglist(yystack_[1].value.as < qrane_idlist* > ());
            yylhs.value.as < qrane_statement* > () = opaque;
          }
#line 904 "qrane-parser.c" // lalr1.cc:919
    break;

  case 11:
#line 184 "qrane-parser.y" // lalr1.cc:919
    {
              yylhs.value.as < qrane_statement* > () = yystack_[0].value.as < qrane_qop* > ();
              //mainprogram->parse_iteration_domains_online($$, domain_nums);
          }
#line 913 "qrane-parser.c" // lalr1.cc:919
    break;

  case 12:
#line 189 "qrane-parser.y" // lalr1.cc:919
    {
              yylhs.value.as < qrane_statement* > () = yystack_[0].value.as < qrane_qop* > ();
              yylhs.value.as < qrane_statement* > ()->set_if_condition(yystack_[4].value.as < std::string > (), yystack_[2].value.as < int > ());
          }
#line 922 "qrane-parser.c" // lalr1.cc:919
    break;

  case 13:
#line 194 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_decl *barrier = new qrane_barrier();
            barrier->set_statement_type(qrane_statement::statement_type::DECL);
            barrier->set_decl_type(qrane_decl::decl_type::BARRIER);
            barrier->set_arglist(yystack_[1].value.as < qrane_arglist* > ());
            yylhs.value.as < qrane_statement* > () = barrier;
          }
#line 934 "qrane-parser.c" // lalr1.cc:919
    break;

  case 14:
#line 203 "qrane-parser.y" // lalr1.cc:919
    {
         mainprogram->qreg_seen = true;
		 mainprogram->qreg_size = yystack_[2].value.as < int > ();
         qrane_decl *qreg = new qrane_qreg();
         qreg->set_statement_type(qrane_statement::statement_type::QREG);
         qreg->set_decl_type(qrane_decl::decl_type::QREG);
         qreg->set_id(yystack_[4].value.as < std::string > ());
         qreg->set_size(yystack_[2].value.as < int > ());
         yylhs.value.as < qrane_decl* > () = qreg;
     }
#line 949 "qrane-parser.c" // lalr1.cc:919
    break;

  case 15:
#line 214 "qrane-parser.y" // lalr1.cc:919
    {
         qrane_decl *creg = new qrane_creg();
         creg->set_statement_type(qrane_statement::statement_type::DECL);
         creg->set_decl_type(qrane_decl::decl_type::CREG);
         creg->set_id(yystack_[4].value.as < std::string > ());
         creg->set_size(yystack_[2].value.as < int > ());
         yylhs.value.as < qrane_decl* > () = creg;
     }
#line 962 "qrane-parser.c" // lalr1.cc:919
    break;

  case 16:
#line 224 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_gatedecl *gate = new qrane_gatedecl();
            gate->set_statement_type(qrane_statement::statement_type::DECL);
            gate->set_decl_type(qrane_decl::decl_type::GATE);
            gate->set_id(yystack_[2].value.as < std::string > ());
            gate->set_arglist(yystack_[1].value.as < qrane_idlist* > ());
            gate->set_paramlist(new qrane_idlist());
            gate->set_goplist(new qrane_stmtlist());
            yylhs.value.as < qrane_decl* > () = gate;
         }
#line 977 "qrane-parser.c" // lalr1.cc:919
    break;

  case 17:
#line 235 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_gatedecl *gate = new qrane_gatedecl();
            gate->set_statement_type(qrane_statement::statement_type::DECL);
            gate->set_decl_type(qrane_decl::decl_type::GATE);
            gate->set_id(yystack_[4].value.as < std::string > ());
            gate->set_arglist(yystack_[1].value.as < qrane_idlist* > ());
            gate->set_paramlist(new qrane_idlist());
            gate->set_goplist(new qrane_stmtlist());
            yylhs.value.as < qrane_decl* > () = gate;
         }
#line 992 "qrane-parser.c" // lalr1.cc:919
    break;

  case 18:
#line 246 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_gatedecl *gate = new qrane_gatedecl();
            gate->set_statement_type(qrane_statement::statement_type::DECL);
            gate->set_decl_type(qrane_decl::decl_type::GATE);
            gate->set_id(yystack_[5].value.as < std::string > ());
            gate->set_paramlist(yystack_[3].value.as < qrane_idlist* > ());
            gate->set_arglist(yystack_[1].value.as < qrane_idlist* > ());
            gate->set_goplist(new qrane_stmtlist());
            yylhs.value.as < qrane_decl* > () = gate;
         }
#line 1007 "qrane-parser.c" // lalr1.cc:919
    break;

  case 19:
#line 258 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_stmtlist* > () = new qrane_stmtlist();
            yylhs.value.as < qrane_stmtlist* > ()->add_statement(yystack_[0].value.as < qrane_qop* > ()); 
        }
#line 1016 "qrane-parser.c" // lalr1.cc:919
    break;

  case 20:
#line 263 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_stmtlist* > () = new qrane_stmtlist();
            qrane_decl* barrier = new qrane_barrier();
            barrier->set_statement_type(qrane_statement::statement_type::DECL);
            barrier->set_decl_type(qrane_decl::decl_type::BARRIER);
            barrier->set_idlist(yystack_[1].value.as < qrane_idlist* > ());
            yylhs.value.as < qrane_stmtlist* > ()->add_statement(barrier);
        }
#line 1029 "qrane-parser.c" // lalr1.cc:919
    break;

  case 21:
#line 272 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_stmtlist* > () = yystack_[1].value.as < qrane_stmtlist* > ();
            yylhs.value.as < qrane_stmtlist* > ()->add_statement(yystack_[0].value.as < qrane_qop* > ());
        }
#line 1038 "qrane-parser.c" // lalr1.cc:919
    break;

  case 22:
#line 277 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_stmtlist* > () = yystack_[3].value.as < qrane_stmtlist* > ();
            qrane_decl* barrier = new qrane_barrier();
            barrier->set_statement_type(qrane_statement::statement_type::DECL);
            barrier->set_decl_type(qrane_decl::decl_type::BARRIER);
            barrier->set_idlist(yystack_[1].value.as < qrane_idlist* > ());
            yylhs.value.as < qrane_stmtlist* > ()->add_statement(barrier);
        }
#line 1051 "qrane-parser.c" // lalr1.cc:919
    break;

  case 23:
#line 287 "qrane-parser.y" // lalr1.cc:919
    {
        yylhs.value.as < qrane_qop* > () = yystack_[0].value.as < qrane_qop* > ();
    }
#line 1059 "qrane-parser.c" // lalr1.cc:919
    break;

  case 24:
#line 291 "qrane-parser.y" // lalr1.cc:919
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *measure = new qrane_measure();
        measure->set_statement_type(qrane_statement::statement_type::QOP);
        measure->set_qop_type(qrane_qop::qop_type::MEASURE);
        //measure->set_dim1_qop_num(dim1_qop_num); 
		measure->set_dim1_qop_num(mainprogram->get_num_qops());      
        
        qrane_arglist *arglist = new qrane_mixedlist();
        arglist->add_argument(yystack_[3].value.as < qrane_argument* > ());
        arglist->add_argument(yystack_[1].value.as < qrane_argument* > ());
        measure->set_arglist(arglist);
        yylhs.value.as < qrane_qop* > () = measure;
    }
#line 1079 "qrane-parser.c" // lalr1.cc:919
    break;

  case 25:
#line 307 "qrane-parser.y" // lalr1.cc:919
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *reset = new qrane_reset();
        reset->set_statement_type(qrane_statement::statement_type::QOP);           
        reset->set_qop_type(qrane_qop::qop_type::RESET);
        //reset->set_dim1_qop_num(dim1_qop_num);
		reset->set_dim1_qop_num(mainprogram->get_num_qops());

        qrane_arglist *arglist = new qrane_mixedlist();
        arglist->add_argument(yystack_[1].value.as < qrane_argument* > ());
        reset->set_arglist(arglist);
        yylhs.value.as < qrane_qop* > () = reset;
    }
#line 1098 "qrane-parser.c" // lalr1.cc:919
    break;

  case 26:
#line 323 "qrane-parser.y" // lalr1.cc:919
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if (mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *u = new qrane_u();
        u->set_statement_type(qrane_statement::statement_type::QOP);                       
        u->set_qop_type(qrane_qop::qop_type::U);
        //u->set_dim1_qop_num(dim1_qop_num);
		u->set_dim1_qop_num(mainprogram->get_num_qops());
        u->set_explist(yystack_[3].value.as < qrane_explist* > ());

        qrane_arglist *arglist = new qrane_mixedlist();
        arglist->add_argument(yystack_[1].value.as < qrane_argument* > ());
        u->set_arglist(arglist);
        yylhs.value.as < qrane_qop* > () = u;
    }
#line 1118 "qrane-parser.c" // lalr1.cc:919
    break;

  case 27:
#line 339 "qrane-parser.y" // lalr1.cc:919
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *cx = new qrane_cx();
        cx->set_statement_type(qrane_statement::statement_type::QOP);
        cx->set_qop_type(qrane_qop::qop_type::CX);
        //cx->set_dim1_qop_num(dim1_qop_num);
		cx->set_dim1_qop_num(mainprogram->get_num_qops());

        qrane_arglist *arglist = new qrane_mixedlist();
        arglist->add_argument(yystack_[3].value.as < qrane_argument* > ());
        arglist->add_argument(yystack_[1].value.as < qrane_argument* > ());
        cx->set_arglist(arglist);
        yylhs.value.as < qrane_qop* > () = cx;
    }
#line 1138 "qrane-parser.c" // lalr1.cc:919
    break;

  case 28:
#line 355 "qrane-parser.y" // lalr1.cc:919
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *custom = new qrane_custom();
        custom->set_statement_type(qrane_statement::statement_type::QOP);
        custom->set_qop_type(qrane_qop::qop_type::CUSTOM);
        //custom->set_dim1_qop_num(dim1_qop_num);
		custom->set_dim1_qop_num(mainprogram->get_num_qops());
        custom->set_id(yystack_[2].value.as < std::string > ());
        custom->set_explist(new qrane_explist());
        custom->set_arglist(yystack_[1].value.as < qrane_arglist* > ());
        yylhs.value.as < qrane_qop* > () = custom;
    }
#line 1156 "qrane-parser.c" // lalr1.cc:919
    break;

  case 29:
#line 369 "qrane-parser.y" // lalr1.cc:919
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *custom = new qrane_custom();
        custom->set_statement_type(qrane_statement::statement_type::QOP);
        custom->set_qop_type(qrane_qop::qop_type::CUSTOM);
        //custom->set_dim1_qop_num(dim1_qop_num);
		custom->set_dim1_qop_num(mainprogram->get_num_qops());
        custom->set_id(yystack_[4].value.as < std::string > ());
        custom->set_explist(new qrane_explist());
        custom->set_arglist(yystack_[1].value.as < qrane_arglist* > ());
        yylhs.value.as < qrane_qop* > () = custom;
    }
#line 1174 "qrane-parser.c" // lalr1.cc:919
    break;

  case 30:
#line 383 "qrane-parser.y" // lalr1.cc:919
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *custom = new qrane_custom();
        custom->set_statement_type(qrane_statement::statement_type::QOP);
        custom->set_qop_type(qrane_qop::qop_type::CUSTOM);
        //custom->set_dim1_qop_num(dim1_qop_num);
		custom->set_dim1_qop_num(mainprogram->get_num_qops());
        custom->set_id(yystack_[5].value.as < std::string > ());
        custom->set_explist(yystack_[3].value.as < qrane_explist* > ());
        custom->set_arglist(yystack_[1].value.as < qrane_arglist* > ());
        yylhs.value.as < qrane_qop* > () = custom;
    }
#line 1192 "qrane-parser.c" // lalr1.cc:919
    break;

  case 31:
#line 397 "qrane-parser.y" // lalr1.cc:919
    { yylhs.value.as < qrane_arglist* > () = yystack_[0].value.as < qrane_idlist* > (); }
#line 1198 "qrane-parser.c" // lalr1.cc:919
    break;

  case 32:
#line 398 "qrane-parser.y" // lalr1.cc:919
    { yylhs.value.as < qrane_arglist* > () = yystack_[0].value.as < qrane_arglist* > (); }
#line 1204 "qrane-parser.c" // lalr1.cc:919
    break;

  case 33:
#line 401 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_idlist* idlist = new qrane_idlist();
            idlist->set_type(qrane_arglist::arglist_type::IDLIST);
            idlist->add_id(yystack_[0].value.as < std::string > ());
            yylhs.value.as < qrane_idlist* > () = idlist;
       }
#line 1215 "qrane-parser.c" // lalr1.cc:919
    break;

  case 34:
#line 408 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_idlist* > () = yystack_[2].value.as < qrane_idlist* > ();
            yylhs.value.as < qrane_idlist* > ()->add_id(yystack_[0].value.as < std::string > ());
       }
#line 1224 "qrane-parser.c" // lalr1.cc:919
    break;

  case 35:
#line 414 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_arglist* mixedlist = new qrane_mixedlist();
            qrane_argument* arg = new qrane_argument(yystack_[3].value.as < std::string > (), yystack_[1].value.as < int > ());
            mixedlist->set_type(qrane_arglist::arglist_type::MIXED);
            mixedlist->add_argument(arg);
            yylhs.value.as < qrane_arglist* > () = mixedlist;
          }
#line 1236 "qrane-parser.c" // lalr1.cc:919
    break;

  case 36:
#line 422 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_argument* arg = new qrane_argument(yystack_[0].value.as < std::string > ());

            yylhs.value.as < qrane_arglist* > () = yystack_[2].value.as < qrane_arglist* > ();
            yylhs.value.as < qrane_arglist* > ()->add_argument(arg);
          }
#line 1247 "qrane-parser.c" // lalr1.cc:919
    break;

  case 37:
#line 429 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_argument* arg = new qrane_argument(yystack_[3].value.as < std::string > (), yystack_[1].value.as < int > ());

            yylhs.value.as < qrane_arglist* > () = yystack_[5].value.as < qrane_arglist* > ();
            yylhs.value.as < qrane_arglist* > ()->add_argument(arg);
          }
#line 1258 "qrane-parser.c" // lalr1.cc:919
    break;

  case 38:
#line 436 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_arglist* > () = yystack_[5].value.as < qrane_idlist* > ();
            yylhs.value.as < qrane_arglist* > ()->add_id(yystack_[3].value.as < std::string > ());
          }
#line 1267 "qrane-parser.c" // lalr1.cc:919
    break;

  case 39:
#line 442 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_argument* arg = new qrane_argument(yystack_[0].value.as < std::string > ());
            yylhs.value.as < qrane_argument* > () = arg;
         }
#line 1276 "qrane-parser.c" // lalr1.cc:919
    break;

  case 40:
#line 447 "qrane-parser.y" // lalr1.cc:919
    {
            qrane_argument* arg = new qrane_argument(yystack_[3].value.as < std::string > (), yystack_[1].value.as < int > ());
            yylhs.value.as < qrane_argument* > () = arg;
         }
#line 1285 "qrane-parser.c" // lalr1.cc:919
    break;

  case 41:
#line 453 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_explist* > () = new qrane_explist();
            yylhs.value.as < qrane_explist* > ()->add_exp(yystack_[0].value.as < qrane_exp* > ());
        }
#line 1294 "qrane-parser.c" // lalr1.cc:919
    break;

  case 42:
#line 458 "qrane-parser.y" // lalr1.cc:919
    {
            yylhs.value.as < qrane_explist* > () = yystack_[2].value.as < qrane_explist* > ();
            yylhs.value.as < qrane_explist* > ()->add_exp(yystack_[0].value.as < qrane_exp* > ());
        }
#line 1303 "qrane-parser.c" // lalr1.cc:919
    break;

  case 43:
#line 464 "qrane-parser.y" // lalr1.cc:919
    { 
         qrane_exp* real = new qrane_value<double>(yystack_[0].value.as < double > ());
         yylhs.value.as < qrane_exp* > () = real;
    }
#line 1312 "qrane-parser.c" // lalr1.cc:919
    break;

  case 44:
#line 469 "qrane-parser.y" // lalr1.cc:919
    { 
         qrane_exp* nninteger = new qrane_value<int>(yystack_[0].value.as < int > ());
         yylhs.value.as < qrane_exp* > () = nninteger;
    }
#line 1321 "qrane-parser.c" // lalr1.cc:919
    break;

  case 45:
#line 474 "qrane-parser.y" // lalr1.cc:919
    { 
         qrane_exp* pi = new qrane_value<double>(double(M_PI));
         yylhs.value.as < qrane_exp* > () = pi;
    }
#line 1330 "qrane-parser.c" // lalr1.cc:919
    break;

  case 46:
#line 479 "qrane-parser.y" // lalr1.cc:919
    { 
         qrane_exp* id = new qrane_value<std::string>(yystack_[0].value.as < std::string > ());
         yylhs.value.as < qrane_exp* > () = id;
    }
#line 1339 "qrane-parser.c" // lalr1.cc:919
    break;

  case 47:
#line 484 "qrane-parser.y" // lalr1.cc:919
    { 
        qrane_exp* binaryop = new qrane_binaryop();
        binaryop->set_binaryop_type(qrane_exp::binaryop_type::ADD);
        binaryop->set_lhs(yystack_[2].value.as < qrane_exp* > ());
        binaryop->set_rhs(yystack_[0].value.as < qrane_exp* > ());
        yylhs.value.as < qrane_exp* > () = binaryop;
    }
#line 1351 "qrane-parser.c" // lalr1.cc:919
    break;

  case 48:
#line 492 "qrane-parser.y" // lalr1.cc:919
    {
        qrane_exp* binaryop = new qrane_binaryop();
        binaryop->set_binaryop_type(qrane_exp::binaryop_type::SUB);
        binaryop->set_lhs(yystack_[2].value.as < qrane_exp* > ());
        binaryop->set_rhs(yystack_[0].value.as < qrane_exp* > ());
        yylhs.value.as < qrane_exp* > () = binaryop;
    }
#line 1363 "qrane-parser.c" // lalr1.cc:919
    break;

  case 49:
#line 500 "qrane-parser.y" // lalr1.cc:919
    { 
        qrane_exp* binaryop = new qrane_binaryop();
        binaryop->set_binaryop_type(qrane_exp::binaryop_type::MUL);
        binaryop->set_lhs(yystack_[2].value.as < qrane_exp* > ());
        binaryop->set_rhs(yystack_[0].value.as < qrane_exp* > ());
        yylhs.value.as < qrane_exp* > () = binaryop;
    }
#line 1375 "qrane-parser.c" // lalr1.cc:919
    break;

  case 50:
#line 508 "qrane-parser.y" // lalr1.cc:919
    {
        qrane_exp* binaryop = new qrane_binaryop();
        binaryop->set_binaryop_type(qrane_exp::binaryop_type::DIV);
        binaryop->set_lhs(yystack_[2].value.as < qrane_exp* > ());
        binaryop->set_rhs(yystack_[0].value.as < qrane_exp* > ());
        yylhs.value.as < qrane_exp* > () = binaryop;
    }
#line 1387 "qrane-parser.c" // lalr1.cc:919
    break;

  case 51:
#line 516 "qrane-parser.y" // lalr1.cc:919
    { 
        qrane_exp* unaryop = new qrane_unaryop();
        unaryop->set_unaryop_type(qrane_exp::unaryop_type::NEG);
        unaryop->set_arg(yystack_[0].value.as < qrane_exp* > ());
        yylhs.value.as < qrane_exp* > () = unaryop;
    }
#line 1398 "qrane-parser.c" // lalr1.cc:919
    break;

  case 52:
#line 523 "qrane-parser.y" // lalr1.cc:919
    { 
        qrane_exp* binaryop = new qrane_binaryop();
        binaryop->set_binaryop_type(qrane_exp::binaryop_type::CAR);
        binaryop->set_lhs(yystack_[2].value.as < qrane_exp* > ());
        binaryop->set_rhs(yystack_[0].value.as < qrane_exp* > ());
        yylhs.value.as < qrane_exp* > () = binaryop;
    }
#line 1410 "qrane-parser.c" // lalr1.cc:919
    break;

  case 53:
#line 531 "qrane-parser.y" // lalr1.cc:919
    {
        qrane_exp* unaryop = new qrane_unaryop();
        unaryop->set_unaryop_type(qrane_exp::unaryop_type::PAR);
        unaryop->set_arg(yystack_[1].value.as < qrane_exp* > ());
        yylhs.value.as < qrane_exp* > () = unaryop;
    }
#line 1421 "qrane-parser.c" // lalr1.cc:919
    break;

  case 54:
#line 538 "qrane-parser.y" // lalr1.cc:919
    { 
        qrane_exp* unaryop = new qrane_unaryop();
        unaryop->set_unaryop_type(yystack_[3].value.as < qrane_exp::unaryop_type > ());
        unaryop->set_arg(yystack_[1].value.as < qrane_exp* > ());
        yylhs.value.as < qrane_exp* > () = unaryop;
    }
#line 1432 "qrane-parser.c" // lalr1.cc:919
    break;

  case 55:
#line 545 "qrane-parser.y" // lalr1.cc:919
    { yylhs.value.as < qrane_exp::unaryop_type > () = qrane_exp::unaryop_type::SIN;  }
#line 1438 "qrane-parser.c" // lalr1.cc:919
    break;

  case 56:
#line 546 "qrane-parser.y" // lalr1.cc:919
    { yylhs.value.as < qrane_exp::unaryop_type > () = qrane_exp::unaryop_type::COS;  }
#line 1444 "qrane-parser.c" // lalr1.cc:919
    break;

  case 57:
#line 547 "qrane-parser.y" // lalr1.cc:919
    { yylhs.value.as < qrane_exp::unaryop_type > () = qrane_exp::unaryop_type::TAN;  }
#line 1450 "qrane-parser.c" // lalr1.cc:919
    break;

  case 58:
#line 548 "qrane-parser.y" // lalr1.cc:919
    { yylhs.value.as < qrane_exp::unaryop_type > () = qrane_exp::unaryop_type::EXP;  }
#line 1456 "qrane-parser.c" // lalr1.cc:919
    break;

  case 59:
#line 549 "qrane-parser.y" // lalr1.cc:919
    { yylhs.value.as < qrane_exp::unaryop_type > () = qrane_exp::unaryop_type::LN;   }
#line 1462 "qrane-parser.c" // lalr1.cc:919
    break;

  case 60:
#line 550 "qrane-parser.y" // lalr1.cc:919
    { yylhs.value.as < qrane_exp::unaryop_type > () = qrane_exp::unaryop_type::SQRT; }
#line 1468 "qrane-parser.c" // lalr1.cc:919
    break;


#line 1472 "qrane-parser.c" // lalr1.cc:919
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  qrane_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  qrane_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char qrane_parser::yypact_ninf_ = -34;

  const signed char qrane_parser::yytable_ninf_ = -1;

  const short
  qrane_parser::yypact_[] =
  {
       5,   -31,    22,    31,   -34,    24,   110,   111,   112,   113,
     114,   115,   115,    80,   115,   131,     3,    24,   -34,   -34,
       2,   -34,   -34,   134,   135,     4,     6,   136,   137,   139,
     140,   138,   133,   141,   102,   143,   125,    77,   144,   -34,
     128,   -34,    38,   -34,   119,   129,     8,   -34,    25,    12,
      59,   130,   -34,   142,   145,   132,   115,   -34,   102,   102,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -11,    94,   152,   115,   146,   114,    -8,   -34,   107,   128,
     -34,   -34,   150,   153,   128,    -4,   -34,   147,   128,    36,
     -34,   154,   157,   158,   160,   156,    58,    78,   115,   102,
     102,   102,   102,   102,   102,   102,   159,   148,   161,   114,
     -34,   109,   163,   164,    37,   128,   -34,   121,   128,   -34,
     149,   151,   -34,   -34,   -34,   167,    94,    98,    78,    60,
     165,   -34,    73,   -34,   175,   -34,   170,   -34,   -34,   -34,
     -34,    42,   -34,   123,   174,   176,   -34,   -34,    66,   -34,
     -34,   -34,   -34,   -34,   -34
  };

  const unsigned char
  qrane_parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     5,
       0,    11,    23,     0,     0,     0,     0,    33,     0,    31,
      32,    39,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     7,     0,    19,     0,     0,     0,    33,     0,     0,
       0,     0,    13,     0,     0,     0,     0,    25,     0,     0,
      45,    55,    56,    57,    58,    59,    60,    46,    43,    44,
       0,    41,     0,     0,     0,     0,     0,    28,     0,     0,
       6,    21,     0,     0,     0,     0,    16,     0,     0,     0,
       8,     0,    34,    36,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,    34,     0,     0,    35,
       0,     0,    40,    24,    53,     0,    42,    47,    48,    49,
      50,    52,     0,    27,     0,    29,     0,    22,    14,    15,
      17,     0,     9,     0,     0,     0,    26,    54,     0,    30,
      18,    10,    38,    37,    12
  };

  const short
  qrane_parser::yypgoto_[] =
  {
     -34,   -34,   -34,   177,   -34,   -34,   -34,    48,    23,   -14,
     -25,   -34,    -9,   162,   -33,   -34
  };

  const signed char
  qrane_parser::yydefgoto_[] =
  {
      -1,     2,    17,    18,    19,    20,    42,    21,    22,    28,
      29,    30,    32,    70,    71,    72
  };

  const unsigned char
  qrane_parser::yytable_[] =
  {
      48,    50,    38,    33,    98,    35,     3,   109,     1,    99,
      40,   115,    99,    13,    14,    78,    87,    37,    46,    41,
      49,    85,     4,    84,    89,    96,    97,    88,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    27,
      47,    86,    47,    43,    47,    87,    79,    95,    47,    13,
      14,   118,     5,   140,   111,    80,    87,    87,   150,   114,
      16,   108,    87,   117,   106,    81,   126,   127,   128,   129,
     130,   131,   132,   124,    16,    11,    12,    13,    14,    87,
      90,   100,   101,   102,   103,   104,   103,   104,   147,   125,
     141,    58,    75,   143,    34,   136,   100,   101,   102,   103,
     104,    59,    16,   102,   103,   104,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    58,   100,   101,   102,
     103,   104,   101,   102,   103,   104,    59,    87,   110,    87,
     137,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    87,   142,    87,   151,    36,    23,    24,    25,    26,
      27,    31,    44,    45,    51,    56,    55,    82,    52,    53,
      54,    74,    57,    73,    47,    77,   105,    83,    91,   112,
      94,     0,   113,   119,   107,   120,   121,   123,    92,   122,
     133,    93,   135,   116,   138,   139,   134,   144,   146,   145,
     148,   149,   104,   152,    39,   153,   154,     0,     0,    76
  };

  const short
  qrane_parser::yycheck_[] =
  {
      25,    26,    16,    12,    15,    14,    37,    15,     3,    20,
       8,    15,    20,    11,    12,    40,    20,    14,    14,    17,
      14,    46,     0,    15,    49,    58,    59,    15,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    36,    36,
      36,    16,    36,    20,    36,    20,     8,    56,    36,    11,
      12,    15,    21,    16,    79,    17,    20,    20,    16,    84,
      36,    75,    20,    88,    73,    42,    99,   100,   101,   102,
     103,   104,   105,    15,    36,     9,    10,    11,    12,    20,
      21,    23,    24,    25,    26,    27,    26,    27,    15,    98,
     115,    14,    15,   118,    14,   109,    23,    24,    25,    26,
      27,    24,    36,    25,    26,    27,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    14,    23,    24,    25,
      26,    27,    24,    25,    26,    27,    24,    20,    21,    20,
      21,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    20,    21,    20,    21,    14,    36,    36,    36,    36,
      36,    36,    18,    18,    18,    22,    18,    38,    21,    20,
      20,    36,    21,    20,    36,    21,    14,    38,    38,    19,
      38,    -1,    19,    19,    28,    18,    18,    21,    36,    19,
      21,    36,    21,    36,    21,    21,    38,    38,    21,    38,
      15,    21,    27,    19,    17,    19,   148,    -1,    -1,    37
  };

  const unsigned char
  qrane_parser::yystos_[] =
  {
       0,     3,    40,    37,     0,    21,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    36,    41,    42,    43,
      44,    46,    47,    36,    36,    36,    36,    36,    48,    49,
      50,    36,    51,    51,    14,    51,    14,    14,    48,    42,
       8,    17,    45,    47,    18,    18,    14,    36,    49,    14,
      49,    18,    21,    20,    20,    18,    22,    21,    14,    24,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      52,    53,    54,    20,    36,    15,    52,    21,    49,     8,
      17,    47,    38,    38,    15,    49,    16,    20,    15,    49,
      21,    38,    36,    36,    38,    51,    53,    53,    15,    20,
      23,    24,    25,    26,    27,    14,    51,    28,    48,    15,
      21,    49,    19,    19,    49,    15,    36,    49,    15,    19,
      18,    18,    19,    21,    15,    51,    53,    53,    53,    53,
      53,    53,    53,    21,    38,    21,    48,    21,    21,    21,
      16,    49,    21,    49,    38,    38,    21,    15,    15,    21,
      16,    21,    19,    19,    46
  };

  const unsigned char
  qrane_parser::yyr1_[] =
  {
       0,    39,    40,    41,    41,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    43,    43,    44,    44,    44,    45,
      45,    45,    45,    46,    46,    46,    47,    47,    47,    47,
      47,    48,    48,    49,    49,    50,    50,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    54,    54,
      54
  };

  const unsigned char
  qrane_parser::yyr2_[] =
  {
       0,     2,     4,     1,     2,     1,     3,     2,     4,     6,
       7,     1,     7,     3,     6,     6,     4,     6,     7,     1,
       3,     2,     4,     1,     5,     3,     6,     5,     3,     5,
       6,     1,     1,     1,     3,     4,     3,     6,     6,     1,
       4,     1,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     2,     3,     3,     4,     1,     1,     1,     1,     1,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const qrane_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "T_OPENQASM", "T_QREG",
  "T_CREG", "T_GATE_CUSTOM", "T_OPAQUE", "T_BARRIER", "T_MEASURE",
  "T_RESET", "T_U", "T_CX", "T_IF", "\"(\"", "\")\"", "\"{\"", "\"}\"",
  "\"[\"", "\"]\"", "\",\"", "\";\"", "\"->\"", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"^\"", "\"==\"", "T_PI", "T_SIN", "T_COS", "T_TAN", "T_EXP",
  "T_LN", "T_SQRT", "T_ID", "T_REAL", "T_NNINTEGER", "$accept",
  "mainprogram", "program", "statement", "decl", "gatedecl", "goplist",
  "qop", "uop", "anylist", "idlist", "mixedlist", "argument", "explist",
  "exp", "unaryop", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  qrane_parser::yyrline_[] =
  {
       0,   124,   124,   129,   134,   140,   144,   149,   153,   163,
     173,   183,   188,   193,   202,   213,   223,   234,   245,   257,
     262,   271,   276,   286,   290,   306,   322,   338,   354,   368,
     382,   397,   398,   400,   407,   413,   421,   428,   435,   441,
     446,   452,   457,   463,   468,   473,   478,   483,   491,   499,
     507,   515,   522,   530,   537,   545,   546,   547,   548,   549,
     550
  };

  // Print the state stack on the debug stream.
  void
  qrane_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  qrane_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1960 "qrane-parser.c" // lalr1.cc:1242
#line 552 "qrane-parser.y" // lalr1.cc:1243


void yy::qrane_parser::error (const yy::location & l, const std::string & s) {
	std::cerr << "Qrane parsing error at " << l << " : " << s << std::endl;
}
