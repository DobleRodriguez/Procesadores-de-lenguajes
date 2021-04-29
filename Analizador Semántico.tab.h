/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_ANALIZADOR_SEM_NTICO_TAB_H_INCLUDED
# define YY_YY_ANALIZADOR_SEM_NTICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAIN = 258,
    OPEN_BLOCK = 259,
    END_BLOCK = 260,
    SEMICOLON = 261,
    COMMA = 262,
    LEFT_PAR = 263,
    RIGHT_PAR = 264,
    ASSIGN = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    VAR = 269,
    ENDVAR = 270,
    SWITCH = 271,
    CASE = 272,
    BREAK = 273,
    RETURN = 274,
    ELEM_TYPE = 275,
    READ = 276,
    WRITE = 277,
    INCR = 278,
    DECR = 279,
    AHEADBACK = 280,
    UNARY_OP = 281,
    TERNARY = 282,
    BIN_TER = 283,
    BOOL_VAR = 284,
    INT_VAR = 285,
    FLOAT_VAR = 286,
    CHAR_VAR = 287,
    LIST = 288,
    STRING = 289,
    ID = 290,
    LEFT_BRACK = 291,
    RIGHT_BRACK = 292,
    COLON = 293,
    DEFAULT = 294,
    LOGIC_OR = 295,
    LOGIC_AND = 296,
    BIT_OR = 297,
    XOR = 298,
    BIT_AND = 299,
    EQ_NEQ = 300,
    VALUE_COMP = 301,
    ADD_SUB = 302,
    MULT = 303,
    MULT_OPS = 304,
    LIST_HEAD = 305,
    L_DECR = 306,
    L_INCR = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALIZADOR_SEM_NTICO_TAB_H_INCLUDED  */
