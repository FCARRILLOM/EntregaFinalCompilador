/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "mylang.y"

#include <iostream>
#include <string>

extern int yylex();
extern int lineno;
void yyerror(char*s);

#include "TablaSimbolos.h"
#include "Quad.h"
#include "MapaMemoria.h"
#include "TablasDatos.h"
 
TablasDatos tablasDatos;
MapaMemoria mapa;

Quad quad(tablasDatos, mapa);
TablaSimbolos tabla(tablasDatos, tablasDatos.funcDir, tablasDatos.clasesDir, quad, mapa);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "mylang.y"
{
  int intval;
  char charval;
  float floatval;
  char* strval;
}
/* Line 193 of yacc.c.  */
#line 220 "mylang.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 233 "mylang.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNRULES -- Number of states.  */
#define YYNSTATES  270

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    18,    21,    22,    24,    26,
      28,    29,    30,    42,    45,    46,    49,    50,    53,    54,
      57,    60,    62,    63,    64,    70,    71,    76,    77,    78,
      85,    86,    87,    91,    92,    95,    96,    98,   100,   102,
     104,   106,   109,   111,   112,   113,   114,   115,   116,   132,
     134,   135,   137,   139,   140,   146,   147,   150,   151,   152,
     153,   154,   163,   166,   167,   168,   175,   176,   179,   180,
     181,   182,   183,   193,   196,   197,   198,   202,   203,   206,
     207,   208,   219,   220,   226,   227,   228,   229,   240,   241,
     242,   243,   257,   263,   266,   269,   270,   272,   274,   280,
     281,   285,   288,   289,   290,   297,   299,   300,   304,   305,
     309,   310,   311,   315,   316,   320,   321,   324,   327,   328,
     330,   331,   335,   336,   340,   341,   345,   346,   347,   351,
     352,   356,   357,   361,   362,   363,   368,   370,   371,   375,
     377,   379,   380,   381,   388,   389,   392,   393,   396,   397,
     400,   403,   404,   405,   410,   411,   413,   415,   417,   420,
     421,   423,   425,   427,   429,   431,   433,   435
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      50,     0,    -1,    -1,    -1,     3,    48,    51,    33,    53,
       4,    38,    39,    52,    40,   160,    41,    -1,    54,    53,
      -1,    -1,    55,    -1,    61,    -1,    76,    -1,    -1,    -1,
      12,    48,    56,    58,    33,    40,    59,    60,    41,    57,
      33,    -1,    13,    48,    -1,    -1,    14,    62,    -1,    -1,
      15,    76,    -1,    -1,    16,    62,    -1,    64,    63,    -1,
      62,    -1,    -1,    -1,    75,    65,    34,    66,    33,    -1,
      -1,    48,    67,    68,    73,    -1,    -1,    -1,    42,    69,
      44,    70,    71,    43,    -1,    -1,    -1,    35,    72,    44,
      -1,    -1,    35,    66,    -1,    -1,    22,    -1,    23,    -1,
      24,    -1,    74,    -1,    48,    -1,    78,    77,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    84,    48,    79,
      38,    80,    85,    81,    39,    33,    83,    82,    40,   160,
      41,    -1,    61,    -1,    -1,    74,    -1,    21,    -1,    -1,
      74,    34,    48,    86,    87,    -1,    -1,    35,    85,    -1,
      -1,    -1,    -1,    -1,    48,    89,    92,    25,    90,   125,
      91,    33,    -1,    36,    48,    -1,    -1,    -1,    42,    93,
     125,    94,    95,    43,    -1,    -1,    35,   125,    -1,    -1,
      -1,    -1,    -1,    48,    97,   100,    38,    98,   101,    39,
      99,    33,    -1,    37,    48,    -1,    -1,    -1,   125,   102,
     103,    -1,    -1,    35,   101,    -1,    -1,    -1,     5,    38,
     125,    39,   105,     6,    40,   160,    41,   106,    -1,    -1,
       7,   107,    40,   160,    41,    -1,    -1,    -1,    -1,     8,
     109,    38,   125,    39,   110,     9,    40,   160,    41,    -1,
      -1,    -1,    -1,    10,    48,    25,   125,   112,    11,   125,
     113,     9,   114,    40,   160,    41,    -1,    19,    38,   116,
      39,    33,    -1,   118,   117,    -1,    35,   116,    -1,    -1,
      47,    -1,   125,    -1,    18,    38,   120,    39,    33,    -1,
      -1,    48,   121,   122,    -1,    35,   120,    -1,    -1,    -1,
      20,    38,   125,    39,   124,    33,    -1,   126,    -1,    -1,
     130,   127,   128,    -1,    -1,    31,   129,   125,    -1,    -1,
      -1,   134,   131,   132,    -1,    -1,    30,   133,   130,    -1,
      -1,   137,   135,    -1,   136,   137,    -1,    -1,    32,    -1,
      -1,   142,   138,   139,    -1,    -1,    26,   140,   137,    -1,
      -1,    27,   141,   137,    -1,    -1,    -1,   147,   143,   144,
      -1,    -1,    29,   145,   142,    -1,    -1,    28,   146,   142,
      -1,    -1,    -1,    38,   148,   126,    39,    -1,   159,    -1,
      -1,    48,   149,   150,    -1,   154,    -1,   155,    -1,    -1,
      -1,    42,   151,   125,   152,   153,    43,    -1,    -1,    35,
     125,    -1,    -1,    36,    48,    -1,    -1,   156,   157,    -1,
      37,    48,    -1,    -1,    -1,    38,   158,   101,    39,    -1,
      -1,    44,    -1,    45,    -1,    46,    -1,   161,   160,    -1,
      -1,    88,    -1,    96,    -1,   119,    -1,   115,    -1,   104,
      -1,   108,    -1,   111,    -1,   123,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    44,    43,    47,    48,    50,    51,    52,
      54,    54,    54,    56,    57,    59,    60,    62,    63,    65,
      67,    69,    70,    72,    72,    74,    74,    76,    76,    76,
      77,    79,    79,    80,    82,    83,    85,    86,    87,    89,
      90,    92,    94,    95,    97,    97,    98,    99,    97,   101,
     102,   104,   105,   107,   107,   108,   110,   111,   113,   113,
     114,   113,   116,   117,   117,   117,   119,   121,   122,   124,
     124,   125,   124,   127,   128,   130,   130,   131,   133,   134,
     136,   136,   138,   138,   139,   141,   141,   141,   144,   144,
     144,   144,   147,   149,   151,   152,   154,   155,   157,   159,
     159,   161,   162,   164,   164,   166,   168,   168,   170,   170,
     171,   173,   173,   175,   175,   176,   178,   180,   181,   183,
     185,   185,   187,   187,   188,   188,   189,   191,   191,   193,
     193,   194,   194,   195,   197,   197,   198,   199,   199,   201,
     202,   203,   203,   203,   205,   207,   208,   210,   211,   213,
     215,   216,   218,   218,   220,   222,   223,   224,   226,   227,
     229,   230,   231,   232,   233,   234,   235,   236
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "programa", "principal", "si",
  "entonces", "sino", "mientras", "hacer", "desde", "hasta", "clase",
  "hereda", "atributos", "metodos", "variables", "funcion", "lee",
  "escribe", "regresa", "n_void", "n_int", "n_float", "n_char",
  "asignador", "mas", "menos", "divi", "mult", "op_and", "op_or", "op_rel",
  "punto_coma", "dos_puntos", "coma", "punto", "flecha", "l_paren",
  "r_paren", "l_brace", "r_brace", "l_bracket", "r_bracket", "cte_int",
  "cte_float", "cte_char", "cte_string", "id_", "$accept", "PROGRAMA",
  "@1", "@2", "DECLARACIONES", "DECLARACION", "CLASE", "@3", "@4",
  "HEREDA", "ATRIBUTOS", "METODOS", "VARIABLES", "VARS", "VARS_", "VAR",
  "@5", "VAR_IDS", "@6", "ARR", "@7", "@8", "ARR_", "@9", "VAR_IDS_",
  "TIPO_SIMPLE", "TIPO_VAR", "FUNCIONES", "FUNCIONES_", "FUNCION", "@10",
  "@11", "@12", "@13", "FUNC_VARIABLES", "TIPO_RET", "PARAMETROS", "@14",
  "PARAMETROS_", "ASIGNACION", "@15", "@16", "@17", "ASIG", "@18", "@19",
  "ASIG_", "LLAMADA_VOID", "@20", "@21", "@22", "VOID_ATTR", "FUNC_PARAM",
  "@23", "FUNC_PARAM_", "DECISION", "@24", "DECISION_", "@25",
  "CONDICIONAL", "@26", "@27", "NOCONDICIONAL", "@28", "@29", "@30",
  "ESCRITURA", "PRINTABLE", "PRINTABLE_", "E", "LECTURA", "READABLE",
  "@31", "READABLE_", "RETORNO", "@32", "EXP", "EXP_Q", "@33", "EXP_",
  "@34", "T_EXP", "@35", "T_EXP_", "@36", "G_EXP", "G_EXP_", "OPER_REL",
  "M_EXP", "@37", "M_EXP_", "@38", "@39", "T", "@40", "T_", "@41", "@42",
  "F", "@43", "@44", "ID_A", "@45", "@46", "ID_ARR", "ID_ATTR",
  "ID_METHOD", "FLECHA", "LLAMADA_RET", "@47", "CTE", "ESTATUTOS",
  "ESTATUTO", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    51,    52,    50,    53,    53,    54,    54,    54,
      56,    57,    55,    58,    58,    59,    59,    60,    60,    61,
      62,    63,    63,    65,    64,    67,    66,    69,    70,    68,
      68,    72,    71,    71,    73,    73,    74,    74,    74,    75,
      75,    76,    77,    77,    79,    80,    81,    82,    78,    83,
      83,    84,    84,    86,    85,    85,    87,    87,    89,    90,
      91,    88,    92,    93,    94,    92,    92,    95,    95,    97,
      98,    99,    96,   100,   100,   102,   101,   101,   103,   103,
     105,   104,   107,   106,   106,   109,   110,   108,   112,   113,
     114,   111,   115,   116,   117,   117,   118,   118,   119,   121,
     120,   122,   122,   124,   123,   125,   127,   126,   129,   128,
     128,   131,   130,   133,   132,   132,   134,   135,   135,   136,
     138,   137,   140,   139,   141,   139,   139,   143,   142,   145,
     144,   146,   144,   144,   148,   147,   147,   149,   147,   150,
     150,   151,   152,   150,   150,   153,   153,   154,   154,   155,
     156,   156,   158,   157,   157,   159,   159,   159,   160,   160,
     161,   161,   161,   161,   161,   161,   161,   161
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,    12,     2,     0,     1,     1,     1,
       0,     0,    11,     2,     0,     2,     0,     2,     0,     2,
       2,     1,     0,     0,     5,     0,     4,     0,     0,     6,
       0,     0,     3,     0,     2,     0,     1,     1,     1,     1,
       1,     2,     1,     0,     0,     0,     0,     0,    15,     1,
       0,     1,     1,     0,     5,     0,     2,     0,     0,     0,
       0,     8,     2,     0,     0,     6,     0,     2,     0,     0,
       0,     0,     9,     2,     0,     0,     3,     0,     2,     0,
       0,    10,     0,     5,     0,     0,     0,    10,     0,     0,
       0,    13,     5,     2,     2,     0,     1,     1,     5,     0,
       3,     2,     0,     0,     6,     1,     0,     3,     0,     3,
       0,     0,     3,     0,     3,     0,     2,     2,     0,     1,
       0,     3,     0,     3,     0,     3,     0,     0,     3,     0,
       3,     0,     3,     0,     0,     4,     1,     0,     3,     1,
       1,     0,     0,     6,     0,     2,     0,     2,     0,     2,
       2,     0,     0,     4,     0,     1,     1,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,     0,     0,
       0,     6,     7,     8,     9,    43,    10,    36,    37,    38,
      40,    19,    22,    39,    23,    52,    51,     0,     0,     5,
      42,    41,    14,    21,    20,     0,    44,     0,     0,     0,
       0,     0,     3,    13,     0,    25,     0,    45,     0,    16,
      30,    24,    55,   159,     0,    18,    27,    35,     0,    46,
       0,    85,     0,     0,     0,     0,    58,   160,   161,   164,
     165,   166,   163,   162,   167,     0,   159,    15,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    74,     4,   158,    17,    11,    28,    34,    53,
       0,   134,   155,   156,   157,   137,     0,   105,   106,   111,
     118,   120,   127,   136,     0,     0,    99,     0,    96,     0,
      95,    97,     0,     0,    63,     0,     0,     0,     0,    33,
      57,    50,     0,   144,    80,   110,   115,   119,   116,     0,
     126,   133,     0,    88,   102,     0,     0,     0,    93,   103,
      62,     0,    59,    73,    70,    12,    31,     0,    55,    54,
      49,    47,     0,     0,     0,   141,   138,   139,   140,   154,
       0,   108,   107,   113,   112,   117,   122,   124,   121,   131,
     129,   128,    86,     0,     0,   100,    98,    92,    94,     0,
      64,     0,    77,     0,    29,    56,     0,   135,   147,   150,
       0,   152,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   104,    68,    60,     0,    75,    32,   159,
     142,    77,   159,   109,   114,   123,   125,   132,   130,     0,
      89,     0,     0,     0,    71,    79,     0,   146,     0,     0,
     159,     0,    67,    65,    61,     0,    77,    76,    48,     0,
       0,   153,    84,     0,    90,    72,    78,   145,   143,    82,
      81,    87,     0,     0,   159,   159,     0,     0,    91,    83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    48,    10,    11,    12,    32,   128,    39,
      55,    79,    13,    21,    34,    22,    35,    46,    50,    57,
      80,   129,   157,   193,    82,    23,    24,    14,    31,    15,
      41,    52,    84,   196,   161,    27,    59,   130,   159,    67,
      91,   191,   233,   125,   151,   214,   232,    68,    92,   192,
     245,   127,   216,   235,   247,    69,   170,   260,   263,    70,
      86,   210,    71,   183,   241,   262,    72,   119,   148,   120,
      73,   117,   144,   185,    74,   189,   217,   107,   135,   172,
     204,   108,   136,   174,   205,   109,   138,   139,   110,   140,
     178,   206,   207,   111,   141,   181,   209,   208,   112,   132,
     133,   166,   200,   237,   250,   167,   168,   169,   202,   221,
     113,    75,    76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -214
static const yytype_int16 yypact[] =
{
       8,   -32,    32,  -214,  -214,     5,    37,   -13,    -9,    34,
      47,    37,  -214,  -214,  -214,    42,  -214,  -214,  -214,  -214,
    -214,  -214,    -9,  -214,  -214,  -214,  -214,    16,    35,  -214,
    -214,  -214,    61,  -214,  -214,    41,  -214,    40,    28,    44,
      30,    43,  -214,  -214,    45,  -214,    49,  -214,    46,    66,
      48,  -214,    38,     2,    -9,    68,  -214,    52,    50,  -214,
      51,  -214,    53,    54,    55,    56,   -19,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,    57,     2,  -214,    42,    58,
      59,    30,  -214,    60,    63,    -4,    62,    70,    64,   -21,
      -4,     1,    67,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
      72,  -214,  -214,  -214,  -214,  -214,    71,  -214,  -214,  -214,
      65,  -214,  -214,  -214,    -4,    -4,  -214,    74,  -214,    75,
      76,  -214,    78,    73,  -214,    81,    77,    80,    82,    84,
      87,    93,    -4,    10,  -214,    92,    94,  -214,  -214,    -4,
      39,     0,    89,  -214,    91,    96,    97,   -21,  -214,  -214,
    -214,    -4,  -214,  -214,  -214,  -214,  -214,    88,    38,  -214,
    -214,  -214,    95,    85,    90,  -214,  -214,  -214,  -214,    98,
     126,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,   124,    64,  -214,  -214,  -214,  -214,   104,
    -214,    -4,    -4,   100,  -214,  -214,    99,  -214,  -214,  -214,
      -4,  -214,  -214,   101,    -4,    -4,    -4,    -4,    -4,    -4,
      79,    -4,  -214,  -214,   105,  -214,   103,  -214,  -214,     2,
    -214,    -4,     2,  -214,  -214,  -214,  -214,  -214,  -214,   108,
    -214,    -4,   102,   116,  -214,   115,   111,   118,   117,   113,
       2,   146,  -214,  -214,  -214,   125,    -4,  -214,  -214,    -4,
     114,  -214,   152,   119,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,   121,   122,     2,     2,   127,   128,  -214,  -214
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,  -214,   155,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,   -40,   -18,  -214,  -214,  -214,    15,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,    -7,  -214,    -6,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,     9,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -213,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,    23,  -214,  -214,
    -214,   -12,  -214,  -214,  -214,  -214,   -84,    31,  -214,  -214,
    -214,   -34,  -214,  -214,  -214,  -214,  -214,  -214,  -136,  -214,
    -214,  -214,  -214,  -140,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,   -76,  -214
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -152
static const yytype_int16 yytable[] =
{
      94,   106,    26,   175,    33,   121,   122,    60,   238,    30,
      61,     1,    62,    17,    18,    19,     3,   101,   -69,   -69,
      63,    64,    65,   102,   103,   104,   118,   105,   179,   180,
     142,   143,     4,   256,   101,    16,    77,   123,     6,    20,
     102,   103,   104,   124,   105,    58,   163,   164,  -151,     7,
      66,    28,   165,     8,     9,    25,    17,    18,    19,     9,
      17,    18,    19,   121,    36,   176,   177,   190,   227,   228,
     225,   226,    95,    37,    38,    40,    43,    44,    45,    42,
      54,    47,    51,    78,    83,    49,    53,    81,   229,    85,
      56,   160,    88,    89,    90,   115,    98,   137,    93,    96,
     114,    87,   100,    97,   126,   131,   152,   215,    99,     8,
     134,   147,   116,   145,   146,   155,   220,   149,   154,   156,
     223,   150,   158,   171,   173,   153,   184,   230,   182,   186,
     187,   194,   203,   198,   197,   211,   201,   213,   199,   219,
     231,   222,   234,   236,   218,   243,   239,   242,   240,   244,
     246,    58,   248,   249,   252,   254,   251,   258,   255,   259,
     261,   264,   265,   162,   253,   257,    29,   195,   268,   269,
     188,   224,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   266,   267
};

static const yytype_int16 yycheck[] =
{
      76,    85,     9,   139,    22,    89,    90,     5,   221,    15,
       8,     3,    10,    22,    23,    24,    48,    38,    37,    38,
      18,    19,    20,    44,    45,    46,    47,    48,    28,    29,
     114,   115,     0,   246,    38,    48,    54,    36,    33,    48,
      44,    45,    46,    42,    48,    52,    36,    37,    38,    12,
      48,     4,    42,    16,    17,    21,    22,    23,    24,    17,
      22,    23,    24,   147,    48,    26,    27,   151,   208,   209,
     206,   207,    78,    38,    13,    34,    48,    33,    48,    39,
      14,    38,    33,    15,    34,    40,    40,    35,     9,    38,
      42,   131,    38,    38,    38,    25,    81,    32,    41,    41,
      38,    48,    39,    44,    37,    33,    25,   191,    48,    16,
      39,    35,    48,    39,    39,    33,   200,    39,    38,    35,
     204,    48,    35,    31,    30,    48,    35,   211,    39,    33,
      33,    43,     6,    48,    39,    11,    38,    33,    48,    40,
      35,    40,    39,   219,    44,    43,   222,   231,    40,    33,
      35,   158,    41,    35,    41,     9,    39,    43,    33,     7,
      41,    40,    40,   132,   240,   249,    11,   158,    41,    41,
     147,   205,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,    48,     0,    51,    33,    12,    16,    17,
      53,    54,    55,    61,    76,    78,    48,    22,    23,    24,
      48,    62,    64,    74,    75,    21,    74,    84,     4,    53,
      76,    77,    56,    62,    63,    65,    48,    38,    13,    58,
      34,    79,    39,    48,    33,    48,    66,    38,    52,    40,
      67,    33,    80,    40,    14,    59,    42,    68,    74,    85,
       5,     8,    10,    18,    19,    20,    48,    88,    96,   104,
     108,   111,   115,   119,   123,   160,   161,    62,    15,    60,
      69,    35,    73,    34,    81,    38,   109,    48,    38,    38,
      38,    89,    97,    41,   160,    76,    41,    44,    66,    48,
      39,    38,    44,    45,    46,    48,   125,   126,   130,   134,
     137,   142,   147,   159,    38,    25,    48,   120,    47,   116,
     118,   125,   125,    36,    42,    92,    37,   100,    57,    70,
      86,    33,   148,   149,    39,   127,   131,    32,   135,   136,
     138,   143,   125,   125,   121,    39,    39,    35,   117,    39,
      48,    93,    25,    48,    38,    33,    35,    71,    35,    87,
      61,    83,   126,    36,    37,    42,   150,   154,   155,   156,
     105,    31,   128,    30,   132,   137,    26,    27,   139,    28,
      29,   144,    39,   112,    35,   122,    33,    33,   116,   124,
     125,    90,    98,    72,    43,    85,    82,    39,    48,    48,
     151,    38,   157,     6,   129,   133,   140,   141,   146,   145,
     110,    11,   120,    33,    94,   125,   101,   125,    44,    40,
     125,   158,    40,   125,   130,   137,   137,   142,   142,     9,
     125,    35,    95,    91,    39,   102,   160,   152,   101,   160,
      40,   113,   125,    43,    33,    99,    35,   103,    41,    35,
     153,    39,    41,   160,     9,    33,   101,   125,    43,     7,
     106,    41,   114,   107,    40,    40,   160,   160,    41,    41
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 43 "mylang.y"
    { quad.savePrincipalLoc(); tabla.addPrincipalFunc((yyvsp[(2) - (2)].strval)); ;}
    break;

  case 3:
#line 44 "mylang.y"
    { quad.addGotoPrincipalLoc(); ;}
    break;

  case 4:
#line 45 "mylang.y"
    { tabla.saveTempsUsed(); quad.clearQuad(); ;}
    break;

  case 8:
#line 51 "mylang.y"
    { tabla.saveGlobalVars(); ;}
    break;

  case 10:
#line 54 "mylang.y"
    { tabla.addClass((yyvsp[(2) - (2)].strval)) ;}
    break;

  case 11:
#line 54 "mylang.y"
    { tabla.endCurrentClassDeclaration(); ;}
    break;

  case 15:
#line 59 "mylang.y"
    { tabla.addVarsToClass(); ;}
    break;

  case 23:
#line 72 "mylang.y"
    { tabla.saveCurrentVarType((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 25:
#line 74 "mylang.y"
    { tabla.addVarToList((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 27:
#line 76 "mylang.y"
    { tabla.addFirstArrNode(); ;}
    break;

  case 28:
#line 76 "mylang.y"
    { tabla.storeDimSize((yyvsp[(3) - (3)].intval)); ;}
    break;

  case 29:
#line 76 "mylang.y"
    { tabla.endArrNode(); ;}
    break;

  case 31:
#line 79 "mylang.y"
    { tabla.addArrNode(); ;}
    break;

  case 32:
#line 79 "mylang.y"
    { tabla.storeDimSize((yyvsp[(3) - (3)].intval)); ;}
    break;

  case 44:
#line 97 "mylang.y"
    { tabla.createFunc((yyvsp[(3) - (3)].strval), (yyvsp[(2) - (3)].strval)); tabla.addFuncGlobalVar(); ;}
    break;

  case 45:
#line 97 "mylang.y"
    { tabla.initParameterVars(); ;}
    break;

  case 46:
#line 98 "mylang.y"
    { tabla.addParameterVarsToDir(); ;}
    break;

  case 47:
#line 99 "mylang.y"
    { tabla.addCurrLVarsToDir(); tabla.addFuncCont(); ;}
    break;

  case 48:
#line 99 "mylang.y"
    { tabla.addEndFunc(); ;}
    break;

  case 53:
#line 107 "mylang.y"
    { tabla.addParameterVar((yyvsp[(3) - (3)].strval), (yyvsp[(1) - (3)].strval)); ;}
    break;

  case 58:
#line 113 "mylang.y"
    { quad.addOperand((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 59:
#line 113 "mylang.y"
    { quad.addOperatorAsig((yyvsp[(4) - (4)].strval)); ;}
    break;

  case 60:
#line 114 "mylang.y"
    { quad.removeFromStackAssign(); ;}
    break;

  case 62:
#line 116 "mylang.y"
    { quad.checkValidAttribute((yyvsp[(2) - (2)].strval)); ;}
    break;

  case 63:
#line 117 "mylang.y"
    { quad.verifyArrayDimensions(); ;}
    break;

  case 64:
#line 117 "mylang.y"
    { quad.getArrayDimensionResult(); ;}
    break;

  case 65:
#line 118 "mylang.y"
    { quad.addArrayQuads(); ;}
    break;

  case 67:
#line 121 "mylang.y"
    { quad.getArrayDimensionResult(); ;}
    break;

  case 69:
#line 124 "mylang.y"
    { quad.addOperand((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 70:
#line 124 "mylang.y"
    { tabla.verifyVoidFunction(); tabla.generateEra(); ;}
    break;

  case 71:
#line 125 "mylang.y"
    { tabla.verifyLastParam(); tabla.addGoSub(); ;}
    break;

  case 73:
#line 127 "mylang.y"
    { quad.checkValidVoidMethod((yyvsp[(2) - (2)].strval)); ;}
    break;

  case 75:
#line 130 "mylang.y"
    { tabla.verifyParameterType(); tabla.moveToNextParam(); ;}
    break;

  case 80:
#line 136 "mylang.y"
    { quad.addGotoIf(); ;}
    break;

  case 81:
#line 136 "mylang.y"
    { quad.addDecisionEnd(); ;}
    break;

  case 82:
#line 138 "mylang.y"
    { quad.addGotoElse(); ;}
    break;

  case 85:
#line 141 "mylang.y"
    { quad.addWhileCheckpoint(); ;}
    break;

  case 86:
#line 141 "mylang.y"
    { quad.addGotoWhile(); ;}
    break;

  case 87:
#line 142 "mylang.y"
    { quad.addConditionalEnd(); ;}
    break;

  case 88:
#line 144 "mylang.y"
    { quad.addLoopCounter((yyvsp[(2) - (4)].strval)); ;}
    break;

  case 89:
#line 144 "mylang.y"
    { quad.addLoopLimit(); ;}
    break;

  case 90:
#line 144 "mylang.y"
    { quad.addGotoFor(); ;}
    break;

  case 91:
#line 145 "mylang.y"
    { quad.addNonConditionalEnd((yyvsp[(2) - (13)].strval)); ;}
    break;

  case 96:
#line 154 "mylang.y"
    { quad.addWriteStr((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 97:
#line 155 "mylang.y"
    { quad.addWriteExp(); ;}
    break;

  case 99:
#line 159 "mylang.y"
    { quad.addRead((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 103:
#line 164 "mylang.y"
    { tabla.saveReturnValue(); ;}
    break;

  case 106:
#line 168 "mylang.y"
    { quad.removeFromStackOr(); ;}
    break;

  case 108:
#line 170 "mylang.y"
    { quad.addOperatorOr((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 111:
#line 173 "mylang.y"
    { quad.removeFromStackAnd(); ;}
    break;

  case 113:
#line 175 "mylang.y"
    { quad.addOperatorAnd((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 117:
#line 180 "mylang.y"
    { quad.removeFromStackRel(); ;}
    break;

  case 119:
#line 183 "mylang.y"
    { quad.addOperatorRel((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 120:
#line 185 "mylang.y"
    { quad.removeFromStackPlusMinus(); ;}
    break;

  case 122:
#line 187 "mylang.y"
    { quad.addOperatorPlusMinus((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 124:
#line 188 "mylang.y"
    { quad.addOperatorPlusMinus((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 127:
#line 191 "mylang.y"
    { quad.removeFromStackMultDiv(); ;}
    break;

  case 129:
#line 193 "mylang.y"
    { quad.addOperatorMultDiv((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 131:
#line 194 "mylang.y"
    { quad.addOperatorMultDiv((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 134:
#line 197 "mylang.y"
    { quad.addFalseBottom(); ;}
    break;

  case 135:
#line 197 "mylang.y"
    { quad.removeFalseBottom(); ;}
    break;

  case 137:
#line 199 "mylang.y"
    { quad.addOperand((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 141:
#line 203 "mylang.y"
    { quad.verifyArrayDimensions(); ;}
    break;

  case 142:
#line 203 "mylang.y"
    { quad.getArrayDimensionResult(); ;}
    break;

  case 143:
#line 204 "mylang.y"
    { quad.addArrayQuads(); ;}
    break;

  case 145:
#line 207 "mylang.y"
    { quad.getArrayDimensionResult(); ;}
    break;

  case 147:
#line 210 "mylang.y"
    { quad.checkValidAttribute((yyvsp[(2) - (2)].strval)); ;}
    break;

  case 150:
#line 215 "mylang.y"
    { quad.checkValidMethod((yyvsp[(2) - (2)].strval)); ;}
    break;

  case 152:
#line 218 "mylang.y"
    { tabla.verifyFunction(); tabla.generateEra(); ;}
    break;

  case 153:
#line 219 "mylang.y"
    { tabla.verifyLastParam(); tabla.addGoSub(); tabla.addReturnValue(); ;}
    break;

  case 155:
#line 222 "mylang.y"
    { quad.addConstOperand(std::to_string((yyvsp[(1) - (1)].intval)), "int"); ;}
    break;

  case 156:
#line 223 "mylang.y"
    { quad.addConstOperand(std::to_string((yyvsp[(1) - (1)].floatval)), "float"); ;}
    break;

  case 157:
#line 224 "mylang.y"
    { quad.addConstOperand((yyvsp[(1) - (1)].strval), "char"); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2051 "mylang.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 239 "mylang.y"
 

int main() {
	yyparse();
}

void yyerror(char* s) {
	std::cout << "Syntax error on line " << lineno << std::endl;
}

