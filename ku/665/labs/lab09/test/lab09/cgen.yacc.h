/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BT = 258,
     BR = 259,
     GLOBAL = 260,
     LOCAL = 261,
     PARAM = 262,
     FORMAL = 263,
     ALLOC = 264,
     LOCALLOC = 265,
     FUNC = 266,
     FEND = 267,
     BGNSTMT = 268,
     ASSIGN = 269,
     FEQ = 270,
     FNE = 271,
     FLE = 272,
     FGE = 273,
     FLT = 274,
     FGT = 275,
     FASSIGN = 276,
     FADD = 277,
     FSUB = 278,
     FMUL = 279,
     FDIV = 280,
     FDEREF = 281,
     FCONV = 282,
     FCALL = 283,
     FARG = 284,
     FRET = 285,
     FIDX = 286,
     IEQ = 287,
     INE = 288,
     ILE = 289,
     IGE = 290,
     ILT = 291,
     IGT = 292,
     IASSIGN = 293,
     IOR = 294,
     IAND = 295,
     IXOR = 296,
     ISHL = 297,
     ISHR = 298,
     IADD = 299,
     ISUB = 300,
     IMUL = 301,
     IDIV = 302,
     IMOD = 303,
     IINV = 304,
     IDEREF = 305,
     ICONV = 306,
     ICALL = 307,
     IARG = 308,
     IRET = 309,
     IIDX = 310,
     INT = 311,
     ID = 312,
     STR = 313
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 10 "cgen.y"

    char* id;
    char* str;
    long long intval;
    struct function_t *func;
    struct arg_t *arg;
    struct local_t *loc;
    struct temp_t *tmp;



/* Line 2068 of yacc.c  */
#line 120 "cgen.yacc.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif



#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



