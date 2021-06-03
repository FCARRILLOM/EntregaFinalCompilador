/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     programa = 258,
     principal = 259,
     si = 260,
     entonces = 261,
     sino = 262,
     mientras = 263,
     hacer = 264,
     desde = 265,
     hasta = 266,
     clase = 267,
     hereda = 268,
     atributos = 269,
     metodos = 270,
     variables = 271,
     funcion = 272,
     lee = 273,
     escribe = 274,
     regresa = 275,
     n_void = 276,
     n_int = 277,
     n_float = 278,
     n_char = 279,
     asignador = 280,
     mas = 281,
     menos = 282,
     divi = 283,
     mult = 284,
     op_and = 285,
     op_or = 286,
     op_rel = 287,
     punto_coma = 288,
     dos_puntos = 289,
     coma = 290,
     punto = 291,
     flecha = 292,
     l_paren = 293,
     r_paren = 294,
     l_brace = 295,
     r_brace = 296,
     l_bracket = 297,
     r_bracket = 298,
     cte_int = 299,
     cte_float = 300,
     cte_char = 301,
     cte_string = 302,
     id_ = 303
   };
#endif
/* Tokens.  */
#define programa 258
#define principal 259
#define si 260
#define entonces 261
#define sino 262
#define mientras 263
#define hacer 264
#define desde 265
#define hasta 266
#define clase 267
#define hereda 268
#define atributos 269
#define metodos 270
#define variables 271
#define funcion 272
#define lee 273
#define escribe 274
#define regresa 275
#define n_void 276
#define n_int 277
#define n_float 278
#define n_char 279
#define asignador 280
#define mas 281
#define menos 282
#define divi 283
#define mult 284
#define op_and 285
#define op_or 286
#define op_rel 287
#define punto_coma 288
#define dos_puntos 289
#define coma 290
#define punto 291
#define flecha 292
#define l_paren 293
#define r_paren 294
#define l_brace 295
#define r_brace 296
#define l_bracket 297
#define r_bracket 298
#define cte_int 299
#define cte_float 300
#define cte_char 301
#define cte_string 302
#define id_ 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "mylang.y"
{
  int intval;
  char charval;
  float floatval;
  char* strval;
}
/* Line 1529 of yacc.c.  */
#line 152 "mylang.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

