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
     VOID = 258,
     INT = 259,
     BYTE = 260,
     B = 261,
     BOOL = 262,
     OR = 263,
     AND = 264,
     NOT = 265,
     TRUE = 266,
     FALSE = 267,
     RETURN = 268,
     IF = 269,
     ELSE = 270,
     WHILE = 271,
     BREAK = 272,
     CONTINUE = 273,
     PRECOND = 274,
     SC = 275,
     COMMA = 276,
     LPAREN = 277,
     RPAREN = 278,
     LBRACE = 279,
     RBRACE = 280,
     ASSIGN = 281,
     RELOP = 282,
     BINOP = 283,
     ID = 284,
     NUM = 285,
     STRING = 286,
     EF = 287
   };
#endif
/* Tokens.  */
#define VOID 258
#define INT 259
#define BYTE 260
#define B 261
#define BOOL 262
#define OR 263
#define AND 264
#define NOT 265
#define TRUE 266
#define FALSE 267
#define RETURN 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define BREAK 272
#define CONTINUE 273
#define PRECOND 274
#define SC 275
#define COMMA 276
#define LPAREN 277
#define RPAREN 278
#define LBRACE 279
#define RBRACE 280
#define ASSIGN 281
#define RELOP 282
#define BINOP 283
#define ID 284
#define NUM 285
#define STRING 286
#define EF 287




/* Copy the first part of user declarations.  */
#line 1 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"

    #include "parser.h"


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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 174 "/Users/miki/Desktop/Compilation/hw5/parser.tab.cpp"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    11,    12,    24,    26,
      28,    29,    31,    33,    37,    40,    41,    44,    45,    51,
      53,    56,    58,    60,    64,    68,    71,    74,    76,    79,
      83,    84,    91,    96,    97,    98,   107,   108,   113,   117,
     123,   128,   131,   134,   138,   141,   144,   149,   153,   155,
     159,   161,   163,   165,   169,   173,   175,   177,   179,   182,
     184,   186,   188,   191,   196,   201,   205,   206
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    32,    -1,    -1,    36,    35,    -1,
      -1,    -1,    39,    29,    22,    37,    40,    23,    43,    24,
      38,    46,    25,    -1,    60,    -1,     3,    -1,    -1,    41,
      -1,    42,    -1,    42,    21,    41,    -1,    60,    29,    -1,
      -1,    43,    44,    -1,    -1,    19,    22,    61,    45,    23,
      -1,    47,    -1,    46,    47,    -1,    48,    -1,    49,    -1,
      52,    62,    56,    -1,    52,    62,    48,    -1,    53,    48,
      -1,    50,    48,    -1,    56,    -1,    53,    49,    -1,    50,
      62,    49,    -1,    -1,    16,    51,    22,    62,    61,    23,
      -1,    14,    22,    61,    23,    -1,    -1,    -1,    52,    62,
      49,    63,    54,    15,    55,    62,    -1,    -1,    24,    57,
      46,    25,    -1,    60,    29,    20,    -1,    60,    29,    26,
      61,    20,    -1,    29,    26,    61,    20,    -1,    58,    20,
      -1,    13,    20,    -1,    13,    61,    20,    -1,    17,    20,
      -1,    18,    20,    -1,    29,    22,    59,    23,    -1,    29,
      22,    23,    -1,    61,    -1,    61,    21,    59,    -1,     4,
      -1,     5,    -1,     7,    -1,    22,    61,    23,    -1,    61,
      28,    61,    -1,    29,    -1,    58,    -1,    30,    -1,    30,
       6,    -1,    31,    -1,    11,    -1,    12,    -1,    10,    61,
      -1,    61,     9,    62,    61,    -1,    61,     8,    62,    61,
      -1,    61,    27,    61,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    41,    42,    46,    47,    46,    55,    58,
      63,    65,    74,    80,    90,    98,    99,   106,   106,   110,
     111,   114,   115,   118,   128,   138,   146,   161,   162,   170,
     185,   185,   195,   202,   202,   202,   216,   216,   219,   222,
     231,   237,   239,   245,   251,   257,   261,   268,   277,   284,
     296,   299,   302,   306,   309,   320,   328,   331,   339,   345,
     348,   351,   354,   360,   367,   374,   382,   383
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "BYTE", "B", "BOOL", "OR",
  "AND", "NOT", "TRUE", "FALSE", "RETURN", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "PRECOND", "SC", "COMMA", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "ASSIGN", "RELOP", "BINOP", "ID", "NUM", "STRING", "EF",
  "$accept", "Program", "Funcs", "FuncDecl", "@1", "@2", "RetType",
  "Formals", "FormalsList", "FormalDecl", "PreConditions", "PreCondition",
  "@3", "Statements", "Statement", "Open_statement", "Closed_statement",
  "While_Start", "@4", "If_Start", "If_Else", "@5", "@6",
  "Simple_statement", "@7", "Call", "ExpList", "Type", "Exp", "M", "N", 0
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
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    37,    38,    36,    39,    39,
      40,    40,    41,    41,    42,    43,    43,    45,    44,    46,
      46,    47,    47,    48,    48,    48,    48,    49,    49,    49,
      51,    50,    52,    54,    55,    53,    57,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    58,    58,    59,    59,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     0,    11,     1,     1,
       0,     1,     1,     3,     2,     0,     2,     0,     5,     1,
       2,     1,     1,     3,     3,     2,     2,     1,     2,     3,
       0,     6,     4,     0,     0,     8,     0,     4,     3,     5,
       4,     2,     2,     3,     2,     2,     4,     3,     1,     3,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     1,
       1,     1,     2,     4,     4,     3,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     9,    50,    51,    52,     0,     0,     3,     0,     8,
       1,     2,     4,     0,     5,    10,     0,    11,    12,     0,
      15,     0,    14,     0,    13,     0,     6,    16,     0,     0,
       0,    60,    61,     0,    55,    57,    59,    56,    17,     0,
       0,    30,     0,     0,    36,     0,     0,    19,    21,    22,
      66,    66,     0,    27,     0,     0,    62,     0,     0,    58,
      66,    66,     0,     0,     0,    42,     0,     0,     0,    44,
      45,     0,     0,     7,    20,    26,     0,     0,     0,     0,
      25,    28,    41,     0,    53,    47,     0,    48,     0,     0,
      65,    54,    18,    43,     0,    66,     0,     0,    29,    66,
      66,     0,    24,    67,    23,    38,     0,    46,     0,    64,
      63,    32,     0,    37,    40,     0,    33,     0,    49,     0,
       0,    39,    31,    34,    66,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    15,    29,     8,    16,    17,    18,
      23,    27,    64,    46,    47,    48,    49,    50,    68,    51,
      52,   120,   124,    53,    71,    37,    86,    55,    87,    78,
     116
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -72
static const yytype_int16 yypact[] =
{
      92,   -72,   -72,   -72,   -72,    19,    -7,    92,    14,   -72,
     -72,   -72,   -72,    12,   -72,    34,    28,   -72,    33,    39,
     -72,    34,   -72,    -8,   -72,    49,   -72,   -72,   170,   133,
     170,   -72,   -72,   170,    51,    72,   -72,   -72,    81,   143,
      65,   -72,    73,    78,   -72,    -4,    87,   -72,   -72,   -72,
      44,   -72,   133,   -72,    90,    84,    48,     1,   148,   -72,
     -72,   -72,   170,   170,    95,   -72,   167,   170,    97,   -72,
     -72,   133,   170,   -72,   -72,   -72,    44,    44,   133,   133,
     -72,   -72,   -72,    -5,   -72,   -72,    98,   175,   170,   170,
      79,   -72,   -72,   -72,   181,   -72,   110,   197,   -72,   -72,
     -72,   133,   -72,   -72,   105,   -72,   170,   -72,   170,    -1,
      48,   -72,   170,   -72,   -72,   133,   -72,   202,   -72,   204,
     107,   -72,   -72,   -72,   -72,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   118,   -72,   -72,   -72,   -72,   -72,   108,   -72,
     -72,   -72,   -72,    60,   -44,     5,   -32,   -45,   -72,   -71,
     -13,   -72,   -72,    53,   -72,   -29,    22,    59,   -27,   -47,
     -72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int8 yytable[] =
{
      54,    38,    74,    56,    79,    76,    57,   100,    61,    60,
      61,    25,    66,    88,    89,   105,    26,    54,    58,    10,
      81,   106,    72,    54,    84,    11,    62,    63,    62,    63,
     100,    76,    76,    99,    14,    90,    91,    77,     2,     3,
      94,     4,    54,    13,   100,    97,    98,   103,   112,    54,
      54,    20,    74,   115,    21,    75,    99,    80,    40,     9,
      41,   109,   110,    77,    77,   101,     9,    54,    22,    81,
      99,    28,    54,    58,    19,    62,    63,   125,    59,   117,
      19,    75,    80,   103,   102,   119,    54,    67,   101,    60,
      61,     2,     3,    69,     4,     1,     2,     3,    70,     4,
      39,    40,   101,    41,    42,    43,   -28,    63,    62,    63,
      82,    44,    73,    83,     2,     3,    45,     4,    92,    95,
     -27,   107,   123,    39,    40,    12,    41,    42,    43,    24,
     118,    96,   104,     0,    44,   113,     0,     2,     3,    45,
       4,     0,     0,     0,     0,     0,    39,    40,     0,    41,
      42,    43,     0,    30,    31,    32,     0,    44,    30,    31,
      32,     0,    45,    65,     0,    33,     0,     0,     0,     0,
      33,    85,    34,    35,    36,    60,    61,    34,    35,    36,
      30,    31,    32,    60,    61,     0,     0,    93,     0,    60,
      61,     0,    33,     0,    62,    63,   108,     0,     0,    34,
      35,    36,    62,    63,   111,    60,    61,     0,    62,    63,
      60,    61,    60,    61,     0,     0,     0,   114,     0,     0,
       0,     0,   121,     0,    62,    63,     0,   122,     0,    62,
      63,    62,    63
};

static const yytype_int8 yycheck[] =
{
      29,    28,    46,    30,    51,    50,    33,    78,     9,     8,
       9,    19,    39,    60,    61,    20,    24,    46,    22,     0,
      52,    26,    26,    52,    23,    32,    27,    28,    27,    28,
     101,    76,    77,    78,    22,    62,    63,    50,     4,     5,
      67,     7,    71,    29,   115,    72,    78,    79,    95,    78,
      79,    23,    96,   100,    21,    50,   101,    52,    14,     0,
      16,    88,    89,    76,    77,    78,     7,    96,    29,   101,
     115,    22,   101,    22,    15,    27,    28,   124,     6,   106,
      21,    76,    77,   115,    79,   112,   115,    22,   101,     8,
       9,     4,     5,    20,     7,     3,     4,     5,    20,     7,
      13,    14,   115,    16,    17,    18,    27,    28,    27,    28,
      20,    24,    25,    29,     4,     5,    29,     7,    23,    22,
      15,    23,    15,    13,    14,     7,    16,    17,    18,    21,
     108,    71,    79,    -1,    24,    25,    -1,     4,     5,    29,
       7,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    16,
      17,    18,    -1,    10,    11,    12,    -1,    24,    10,    11,
      12,    -1,    29,    20,    -1,    22,    -1,    -1,    -1,    -1,
      22,    23,    29,    30,    31,     8,     9,    29,    30,    31,
      10,    11,    12,     8,     9,    -1,    -1,    20,    -1,     8,
       9,    -1,    22,    -1,    27,    28,    21,    -1,    -1,    29,
      30,    31,    27,    28,    23,     8,     9,    -1,    27,    28,
       8,     9,     8,     9,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    20,    -1,    27,    28,    -1,    23,    -1,    27,
      28,    27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,    34,    35,    36,    39,    60,
       0,    32,    35,    29,    22,    37,    40,    41,    42,    60,
      23,    21,    29,    43,    41,    19,    24,    44,    22,    38,
      10,    11,    12,    22,    29,    30,    31,    58,    61,    13,
      14,    16,    17,    18,    24,    29,    46,    47,    48,    49,
      50,    52,    53,    56,    58,    60,    61,    61,    22,     6,
       8,     9,    27,    28,    45,    20,    61,    22,    51,    20,
      20,    57,    26,    25,    47,    48,    50,    53,    62,    62,
      48,    49,    20,    29,    23,    23,    59,    61,    62,    62,
      61,    61,    23,    20,    61,    22,    46,    61,    49,    50,
      52,    53,    48,    49,    56,    20,    26,    23,    21,    61,
      61,    23,    62,    25,    20,    62,    63,    61,    59,    61,
      54,    20,    23,    15,    55,    62
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
#line 38 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { deriveProgramAndExit(); ;}
    break;

  case 5:
#line 46 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {parser.newScope(true);;}
    break;

  case 6:
#line 47 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                parser.setCurrentReturnType((yyvsp[(1) - (8)]));
                parser.addFunctionDeclaration((yyvsp[(1) - (8)]), (yyvsp[(2) - (8)]), (yyvsp[(5) - (8)]));
            ;}
    break;

  case 7:
#line 52 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { parser.exitScope(true, (yyvsp[(2) - (11)]), (yyvsp[(7) - (11)])); ;}
    break;

  case 8:
#line 56 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = new Type(static_cast<Type*>((yyvsp[(1) - (1)]))->type); ;}
    break;

  case 9:
#line 59 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = new Type(VOID); ;}
    break;

  case 10:
#line 63 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = new TypesList(); ;}
    break;

  case 11:
#line 66 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
            (yyval) = new TypesList();
            vector<int>& params = static_cast<TypesList*>((yyval))->params;
            vector<int>& params_other = static_cast<TypesList*>((yyvsp[(1) - (1)]))->params;
            params = params_other;
		;}
    break;

  case 12:
#line 75 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                (yyval) = new TypesList();
                Type* t = static_cast<Type*>((yyvsp[(1) - (1)]));
                static_cast<TypesList*>((yyval))->params.push_back(t->type);
            ;}
    break;

  case 13:
#line 81 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                (yyval) = new TypesList();
                vector<int>& params = static_cast<TypesList*>((yyval))->params;
                vector<int>& params_other = static_cast<TypesList*>((yyvsp[(3) - (3)]))->params;
                params.push_back(static_cast<Type*>((yyvsp[(1) - (3)]))->type);
                params.insert(params.end(), params_other.begin(), params_other.end());
			;}
    break;

  case 14:
#line 91 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                parser.tryAddVariable((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), true);
                (yyval) = new Type(static_cast<Type*>((yyvsp[(1) - (2)]))->type);
	        ;}
    break;

  case 15:
#line 98 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = new Preconditions(0); ;}
    break;

  case 16:
#line 100 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
				    int num = static_cast<Preconditions*>((yyvsp[(1) - (2)]))->preconditions_num;
				    (yyval) = new Preconditions(num + 1);
				;}
    break;

  case 17:
#line 106 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {parser.verifyType((yyvsp[(3) - (3)]), BOOL);;}
    break;

  case 18:
#line 107 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {(yyval) = new Preconditions(0);;}
    break;

  case 23:
#line 119 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    string after_if_label = code_buffer->genLabel();
                    string label_true = dynamic_cast<Label*>((yyvsp[(2) - (3)]))->label;
                    Type* t = dynamic_cast<Type*>((yyvsp[(1) - (3)]));
                    code_buffer->bpatch(t->true_list, label_true);
                    code_buffer->bpatch(t->false_list, after_if_label);
                    parser.exitScope(false, NULL, NULL);
                ;}
    break;

  case 24:
#line 129 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    string after_if_label = code_buffer->genLabel();
                    string label_true = dynamic_cast<Label*>((yyvsp[(2) - (3)]))->label;
                    Type* t = dynamic_cast<Type*>((yyvsp[(1) - (3)]));
                    code_buffer->bpatch(t->true_list, label_true);
                    code_buffer->bpatch(t->false_list, after_if_label);
                    parser.exitScope(false, NULL, NULL);
                ;}
    break;

  case 25:
#line 139 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    Type *t = dynamic_cast<Type*>((yyvsp[(1) - (2)]));
                    string exit_label = code_buffer->genLabel();
                    code_buffer->bpatch(t->exit_list, exit_label);
                    parser.exitScope(false, NULL, NULL);
                ;}
    break;

  case 26:
#line 147 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    parser.outWhile();
                    parser.exitScope(false, NULL, NULL);
                    while_start* ws = dynamic_cast<while_start*>((yyvsp[(1) - (2)]));
                    string exp_evaluation_label = dynamic_cast<Label*>(ws->v[0])->label;
                    Type* exp = dynamic_cast<Type*>(ws->v[1]);
                    string label_true = dynamic_cast<Label*>((yyvsp[(2) - (2)]))->label;
                    code_buffer->bpatch(exp->true_list, label_true);
                    code_buffer->emit("j " + exp_evaluation_label);
                    string after_while = code_buffer->genLabel();
                    code_buffer->bpatch(exp->false_list, after_while);
                ;}
    break;

  case 28:
#line 163 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    Type *t = dynamic_cast<Type*>((yyvsp[(1) - (2)]));
                    string exit_label = code_buffer->genLabel();
                    code_buffer->bpatch(t->exit_list, exit_label);
                    parser.exitScope(false, NULL, NULL);
                ;}
    break;

  case 29:
#line 171 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    parser.outWhile();
                    parser.exitScope(false, NULL, NULL);
                    while_start* ws = dynamic_cast<while_start*>((yyvsp[(1) - (3)]));
                    string exp_evaluation_label = dynamic_cast<Label*>(ws->v[0])->label;
                    Type* exp = dynamic_cast<Type*>(ws->v[1]);
                    string label_true = dynamic_cast<Label*>((yyvsp[(2) - (3)]))->label;
                    code_buffer->bpatch(exp->true_list, label_true);
                    code_buffer->emit("j " + exp_evaluation_label);
                    string after_while = code_buffer->genLabel();
                    code_buffer->bpatch(exp->false_list, after_while);
                ;}
    break;

  case 30:
#line 185 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { parser.inWhile(); ;}
    break;

  case 31:
#line 186 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
    parser.verifyType((yyvsp[(5) - (6)]), BOOL);
    parser.newScope(false);
    while_start* ws = new while_start();
    ws->v.push_back((yyvsp[(4) - (6)]));
    ws->v.push_back((yyvsp[(5) - (6)]));
    (yyval) = ws;
;}
    break;

  case 32:
#line 196 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
    parser.verifyType((yyvsp[(3) - (4)]), BOOL);
    parser.newScope(false);
    (yyval) = (yyvsp[(3) - (4)]);
;}
    break;

  case 33:
#line 202 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {parser.exitScope(false, NULL, NULL);;}
    break;

  case 34:
#line 202 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { parser.newScope(false); ;}
    break;

  case 35:
#line 203 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
    string label_true = dynamic_cast<Label*>((yyvsp[(2) - (8)]))->label;
    string label_false = dynamic_cast<Label*>((yyvsp[(8) - (8)]))->label;
    Type* if_exp = dynamic_cast<Type*>((yyvsp[(1) - (8)]));
    code_buffer->bpatch(if_exp->true_list, label_true);
    code_buffer->bpatch(if_exp->false_list, label_false);

    int exit_address = dynamic_cast<Num*>((yyvsp[(4) - (8)]))->val;
    (yyval) = new Type();
    Type* t = dynamic_cast<Type*>((yyval));
    t->exit_list.push_back(exit_address);
;}
    break;

  case 36:
#line 216 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { parser.newScope(false); ;}
    break;

  case 37:
#line 217 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { parser.exitScope(false, NULL, NULL); ;}
    break;

  case 38:
#line 220 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { parser.tryAddVariable((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), false); ;}
    break;

  case 39:
#line 223 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    Type* expType = dynamic_cast<Type*>((yyvsp[(4) - (5)]));
                    Type *t1 = dynamic_cast<Type*>((yyvsp[(1) - (5)]));
                    parser.verifyType((yyvsp[(1) - (5)]), expType->type);
                    parser.tryAddVariable((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), false);
                    wrapper.doAssignOp((yyvsp[(4) - (5)]), (yyvsp[(2) - (5)]), t1->type);
                ;}
    break;

  case 40:
#line 232 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    parser.verifyIdType((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
                    parser.verifyVariableDefined((yyvsp[(1) - (4)]));
                    wrapper.doAssignOp((yyvsp[(3) - (4)]), (yyvsp[(1) - (4)]), parser.getVariableType((yyvsp[(1) - (4)])))
                ;}
    break;

  case 42:
#line 240 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    parser.verifyReturn(VOID);
                    int type = static_cast<int>(VOID);
                ;}
    break;

  case 43:
#line 246 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    int type = static_cast<Type*>((yyvsp[(2) - (3)]))->type;
                    parser.verifyReturn(type);
                ;}
    break;

  case 44:
#line 252 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                    parser.verifyBreak();
                    (yyval) = new Type(static_cast<int>(VOID));
                ;}
    break;

  case 45:
#line 258 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { parser.verifyContinue(); ;}
    break;

  case 46:
#line 262 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
                parser.verifyFunctionDefined((yyvsp[(1) - (4)]));
                (yyval) = new Type(parser.getFunctionReturnType((yyvsp[(1) - (4)])));
                parser.verifyRightParams((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
            ;}
    break;

  case 47:
#line 269 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
		        parser.verifyFunctionDefined((yyvsp[(1) - (3)]));
		        (yyval) = new Type(parser.getFunctionReturnType((yyvsp[(1) - (3)])));
		        TypesList* empty = new TypesList();
                parser.verifyRightParams((yyvsp[(1) - (3)]), empty);
		    ;}
    break;

  case 48:
#line 278 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
            int type = static_cast<Type*>((yyvsp[(1) - (1)]))->type;
            vector<int> v;
            v.push_back(type);
            (yyval) = new TypesList(v);
        ;}
    break;

  case 49:
#line 285 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
            int type = static_cast<Type*>((yyvsp[(1) - (3)]))->type;
            vector<int> v1;
            v1.push_back(type);
            (yyval) = new TypesList(v1);
            vector<int>& v = static_cast<TypesList*>((yyval))->params;
            vector<int>& exp = static_cast<TypesList*>((yyvsp[(3) - (3)]))->params;
            v.insert(v.end(), exp.begin(), exp.end());
		;}
    break;

  case 50:
#line 297 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = new Type(INT); ;}
    break;

  case 51:
#line 300 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = new Type(BYTE); ;}
    break;

  case 52:
#line 303 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = new Type(BOOL); ;}
    break;

  case 53:
#line 307 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = (yyvsp[(2) - (3)]) ;}
    break;

  case 54:
#line 310 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
        int t1 = parser.verifyTypes((yyvsp[(1) - (3)]), 3, NUM, BYTE, INT);
        int t2 = parser.verifyTypes((yyvsp[(3) - (3)]), 3, NUM, BYTE, INT);

        // Try NUM precision first, retreat to byte if both are BYTE
        int preciseType = t1 == NUM ? NUM : (t2 == NUM ? NUM : BYTE);

        (yyval) = wrapper.binop(preciseType, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]));
    ;}
    break;

  case 55:
#line 321 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
        parser.verifyVariableDefined((yyvsp[(1) - (1)]));
        Id* id = static_cast<Id*>((yyvsp[(1) - (1)]));
        wrapper.assignRegisterToID((yyvsp[(1) - (1)]));
        (yyval) = new Type(parser.getVariableType((yyvsp[(1) - (1)])), id->type.reg);
    ;}
    break;

  case 56:
#line 329 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 57:
#line 332 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
        (yyval) = new Type(NUM);
        int num = dynamic_cast<Num*>((yyvsp[(1) - (1)]))->val;
        Type* dest = static_cast<Type*>((yyval));
        dest->reg = utils.intToString(num);
    ;}
    break;

  case 58:
#line 340 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
	    parser.verifyByteSize((yyvsp[(1) - (2)]));
	    (yyval) = new Type(BYTE);
	;}
    break;

  case 59:
#line 346 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = new Type(STRING); ;}
    break;

  case 60:
#line 349 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = wrapper.boolTrue(); ;}
    break;

  case 61:
#line 352 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = wrapper.boolFalse(); ;}
    break;

  case 62:
#line 355 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
    	parser.verifyType((yyvsp[(2) - (2)]), BOOL);
        (yyval) = wrapper.boolNot((yyvsp[(2) - (2)]));
    ;}
    break;

  case 63:
#line 361 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
	    parser.verifyType((yyvsp[(1) - (4)]), BOOL);
	    parser.verifyType((yyvsp[(3) - (4)]), BOOL);
        (yyval) = wrapper.boolAnd((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]), (yyvsp[(3) - (4)]));
    ;}
    break;

  case 64:
#line 368 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
	    parser.verifyType((yyvsp[(1) - (4)]), BOOL);
     	parser.verifyType((yyvsp[(3) - (4)]), BOOL);
        (yyval) = wrapper.boolOr((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]), (yyvsp[(3) - (4)]));
    ;}
    break;

  case 65:
#line 375 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    {
	    parser.verifyTypes((yyvsp[(1) - (3)]), 3, NUM, BYTE, INT);
	    parser.verifyTypes((yyvsp[(3) - (3)]), 3, NUM, BYTE, INT);
        (yyval) = wrapper.relop((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]));
	;}
    break;

  case 66:
#line 382 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = new Label(code_buffer->genLabel()); ;}
    break;

  case 67:
#line 383 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"
    { (yyval) = new Num(code_buffer->emit("j ")); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1957 "/Users/miki/Desktop/Compilation/hw5/parser.tab.cpp"
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


#line 386 "/Users/miki/Desktop/Compilation/hw5/parser.ypp"


