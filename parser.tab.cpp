/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:339  */

    #include "parser.h"

#line 70 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_CYGDRIVE_C_USERS_GILAD_CLIONPROJECTS_COMPI5_PARSER_TAB_HPP_INCLUDED
# define YY_YY_CYGDRIVE_C_USERS_GILAD_CLIONPROJECTS_COMPI5_PARSER_TAB_HPP_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CYGDRIVE_C_USERS_GILAD_CLIONPROJECTS_COMPI5_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 154 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  113

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    47,    50,    65,    65,    65,    75,    78,
      83,    85,    94,   100,   110,   118,   119,   126,   126,   130,
     137,   148,   155,   164,   173,   182,   193,   204,   205,   216,
     227,   227,   236,   239,   250,   260,   261,   269,   277,   283,
     288,   295,   304,   311,   323,   326,   329,   333,   336,   353,
     361,   364,   372,   378,   381,   384,   387,   392,   398,   404,
     413,   415,   415,   415,   418,   418
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "BYTE", "B", "BOOL", "OR",
  "AND", "NOT", "TRUE", "FALSE", "RETURN", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "PRECOND", "SC", "COMMA", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "ASSIGN", "RELOP", "BINOP", "ID", "NUM", "STRING", "EF",
  "$accept", "Program", "Funcs", "FuncDecl", "$@1", "@2", "RetType",
  "Formals", "FormalsList", "FormalDecl", "PreConditions", "PreCondition",
  "$@3", "Statements", "Statement", "Open_statement", "Closed_statement",
  "Simple_statement", "$@4", "Call", "ExpList", "Type", "Exp", "If_Start",
  "If_Else", "$@5", "$@6", "While_Start", "$@7", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -28

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-28)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      75,   -46,   -46,   -46,   -46,    42,    -1,    75,    18,   -46,
     -46,   -46,   -46,    40,   -46,   160,    45,   -46,    48,    52,
     -46,   160,   -46,    -9,   -46,    63,   -46,   -46,    97,    82,
      97,   -46,   -46,    97,    88,   106,   -46,   -46,   133,    26,
      93,   -46,    54,    77,   -46,    68,    36,   -46,   -46,   -46,
     -46,   105,   100,    82,    82,    82,   -15,    -2,    91,   -46,
      97,    97,    97,    97,   112,   -46,    96,    97,   116,   -46,
     -46,    82,    97,   -46,   -46,   -46,   -12,   -46,   -46,   132,
     -46,   -46,   -46,   -46,   -46,   -46,   126,   109,    -5,   -15,
      31,   -46,   -46,   -46,   123,    97,    59,   125,   -46,    97,
     141,   -46,    97,   -46,   131,   -46,   -46,   135,   -46,   -46,
     -46,   -46,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     9,    44,    45,    46,     0,     0,     3,     0,     8,
       1,     2,     4,     0,     5,    10,     0,    11,    12,     0,
      15,     0,    14,     0,    13,     0,     6,    16,     0,     0,
       0,    54,    55,     0,    49,    51,    53,    50,    17,     0,
       0,    64,     0,     0,    30,     0,     0,    19,    21,    22,
      27,     0,     0,     0,     0,     0,    56,     0,     0,    52,
       0,     0,     0,     0,     0,    36,     0,     0,     0,    38,
      39,     0,     0,     7,    20,    35,     0,    24,    61,    23,
      25,    28,    26,    29,    47,    41,     0,    42,    58,    57,
      59,    48,    18,    37,     0,     0,     0,     0,    32,     0,
       0,    40,     0,    60,     0,    31,    34,     0,    62,    43,
      65,    33,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   150,   -46,   -46,   -46,   -46,   -46,   127,   -46,
     -46,   -46,   -46,    95,   -45,   -36,    38,   115,   -46,   -26,
      67,     9,   -28,   -46,   -46,   -46,   -46,   -46,   -46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    15,    29,     8,    16,    17,    18,
      23,    27,    64,    46,    47,    48,    49,    50,    71,    37,
      86,    52,    87,    53,    54,   100,   112,    55,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      38,    74,    56,    51,    61,    57,    60,    61,    98,     9,
      25,    66,    62,    63,    99,    26,     9,    77,    80,    82,
      51,    84,    62,    63,    19,    62,    63,    51,    51,    51,
      19,    11,    88,    89,    90,    91,    30,    31,    32,    94,
       2,     3,    10,     4,    97,    51,    65,    13,    33,    39,
      40,    74,    41,    42,    43,    34,    35,    36,   -28,    63,
      44,    73,    14,     2,     3,    45,     4,   104,    20,    21,
      51,   107,    39,    40,    69,    41,    42,    43,     1,     2,
       3,    22,     4,    44,   105,    28,     2,     3,    45,     4,
      58,    78,    81,    83,    72,    39,    40,    70,    41,    42,
      43,    30,    31,    32,    60,    61,    44,    30,    31,    32,
      58,    45,    59,    33,    85,    67,    93,    60,    61,    33,
      34,    35,    36,    62,    63,    75,    34,    35,    36,    76,
     102,    60,    61,    60,    61,    92,    62,    63,    95,    60,
      61,    60,    61,    60,    61,   106,   103,   -27,    24,   101,
      62,    63,    62,    63,   110,   111,   108,    12,    62,    63,
      62,    63,    62,    63,     2,     3,    96,     4,    79,   109
};

static const yytype_uint8 yycheck[] =
{
      28,    46,    30,    29,     9,    33,     8,     9,    20,     0,
      19,    39,    27,    28,    26,    24,     7,    53,    54,    55,
      46,    23,    27,    28,    15,    27,    28,    53,    54,    55,
      21,    32,    60,    61,    62,    63,    10,    11,    12,    67,
       4,     5,     0,     7,    72,    71,    20,    29,    22,    13,
      14,    96,    16,    17,    18,    29,    30,    31,    27,    28,
      24,    25,    22,     4,     5,    29,     7,    95,    23,    21,
      96,    99,    13,    14,    20,    16,    17,    18,     3,     4,
       5,    29,     7,    24,    25,    22,     4,     5,    29,     7,
      22,    53,    54,    55,    26,    13,    14,    20,    16,    17,
      18,    10,    11,    12,     8,     9,    24,    10,    11,    12,
      22,    29,     6,    22,    23,    22,    20,     8,     9,    22,
      29,    30,    31,    27,    28,    20,    29,    30,    31,    29,
      21,     8,     9,     8,     9,    23,    27,    28,    22,     8,
       9,     8,     9,     8,     9,    20,    23,    15,    21,    23,
      27,    28,    27,    28,    23,    20,    15,     7,    27,    28,
      27,    28,    27,    28,     4,     5,    71,     7,    53,   102
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,    34,    35,    36,    39,    54,
       0,    32,    35,    29,    22,    37,    40,    41,    42,    54,
      23,    21,    29,    43,    41,    19,    24,    44,    22,    38,
      10,    11,    12,    22,    29,    30,    31,    52,    55,    13,
      14,    16,    17,    18,    24,    29,    46,    47,    48,    49,
      50,    52,    54,    56,    57,    60,    55,    55,    22,     6,
       8,     9,    27,    28,    45,    20,    55,    22,    61,    20,
      20,    51,    26,    25,    47,    20,    29,    48,    49,    50,
      48,    49,    48,    49,    23,    23,    53,    55,    55,    55,
      55,    55,    23,    20,    55,    22,    46,    55,    20,    26,
      58,    23,    21,    23,    55,    25,    20,    55,    15,    53,
      23,    20,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    37,    38,    36,    39,    39,
      40,    40,    41,    41,    42,    43,    43,    45,    44,    46,
      46,    47,    47,    48,    48,    48,    48,    49,    49,    49,
      51,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      52,    52,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    58,    59,    57,    61,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     0,    11,     1,     1,
       0,     1,     1,     3,     2,     0,     2,     0,     5,     1,
       2,     1,     1,     2,     2,     2,     2,     1,     2,     2,
       0,     4,     3,     5,     4,     2,     2,     3,     2,     2,
       4,     3,     1,     3,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     1,     1,     2,     3,     3,     3,
       4,     0,     0,     5,     0,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 39 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
         verifyMainFunction();
         exit_last_scope();
         exit(0);
        }
#line 1323 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
         (yyval) = new PrecondList();
        }
#line 1331 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 51 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
		 PrecondList* p = dynamic_cast<PrecondList*>((yyvsp[-1]));
		 vector<int>& pv = p->preconditions_nums;
         (yyval) = new PrecondList();
         PrecondList* t = dynamic_cast<PrecondList*>((yyval));
         vector<int>& tv = t->preconditions_nums;
         tv.insert(tv.end(), pv.begin(), pv.end());
         PrecondList* p2 = dynamic_cast<PrecondList*>((yyvsp[0]));
         vector<int>& pv2 = p2->preconditions_nums;
         tv.insert(tv.end(), pv2.begin(), pv2.end());
		}
#line 1347 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 65 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {new_scope();}
#line 1353 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 65 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                current_return_type = dynamic_cast<Type*>((yyvsp[-7]))->type;
                addFunctionDeclaration((yyvsp[-7]), (yyvsp[-6]), (yyvsp[-3]));
                (yyval) = (yyvsp[-1]);
            }
#line 1363 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 70 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                exit_scope(true, (yyvsp[-9]), (yyvsp[-4]));
            }
#line 1371 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 76 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = new Type(static_cast<Type*>((yyvsp[0]))->type); }
#line 1377 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 79 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = new Type(VOID); }
#line 1383 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 83 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = new TypesList(); }
#line 1389 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 86 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
            (yyval) = new TypesList();
            vector<int>& params = static_cast<TypesList*>((yyval))->params;
            vector<int>& params_other = static_cast<TypesList*>((yyvsp[0]))->params;
            params = params_other;
		}
#line 1400 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 95 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                (yyval) = new TypesList();
                Type* t = static_cast<Type*>((yyvsp[0]));
                static_cast<TypesList*>((yyval))->params.push_back(t->type);
            }
#line 1410 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 101 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                (yyval) = new TypesList();
                vector<int>& params = static_cast<TypesList*>((yyval))->params;
                vector<int>& params_other = static_cast<TypesList*>((yyvsp[0]))->params;
                params.push_back(static_cast<Type*>((yyvsp[-2]))->type);
                params.insert(params.end(), params_other.begin(), params_other.end());
			}
#line 1422 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 111 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                tryAddVariable((yyvsp[-1]), (yyvsp[0]), true);
                (yyval) = new Type(static_cast<Type*>((yyvsp[-1]))->type);
	        }
#line 1431 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 118 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {(yyval) = new Preconditions(0);}
#line 1437 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 120 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
				 int num = static_cast<Preconditions*>((yyvsp[-1]))->preconditions_num;
				 (yyval) = new Preconditions(num + 1);
				}
#line 1446 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 126 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {verifyType((yyvsp[0]), BOOL);}
#line 1452 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 127 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {(yyval) = new Preconditions(0);}
#line 1458 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 131 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                TypesList* t = dynamic_cast<TypesList*>((yyvsp[0]));
                if(t != NULL){
                    (yyval) = new TypesList(t->params);
                }
            }
#line 1469 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 138 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    TypesList* t1 = dynamic_cast<TypesList*>((yyvsp[-1]));
                    TypesList* t2 = dynamic_cast<TypesList*>((yyvsp[0]));
                    if(t1 != NULL || t2 != NULL){
                        (yyval) = new TypesList();
                        concatenate_params(dynamic_cast<TypesList*>((yyval))->params, t1, t2);
                    }
                }
#line 1482 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 149 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                TypesList* t = dynamic_cast<TypesList*>((yyvsp[0]));
                if(t != NULL){
                    (yyval) = new TypesList(t->params);
                }
           }
#line 1493 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 156 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                TypesList* t = dynamic_cast<TypesList*>((yyvsp[0]));
                if(t != NULL){
                    (yyval) = new TypesList(t->params);
                }
           }
#line 1504 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 165 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    TypesList* t = dynamic_cast<TypesList*>((yyvsp[0]));
                    if(t != NULL){
                        (yyval) = new TypesList(t->params);
                    }
                    exit_scope(false, NULL, NULL);
                }
#line 1516 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 174 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    TypesList* t = dynamic_cast<TypesList*>((yyvsp[0]));
                    if(t != NULL){
                        (yyval) = new TypesList(t->params);
                    }
                    exit_scope(false, NULL, NULL);
                }
#line 1528 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 183 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    TypesList* t1 = dynamic_cast<TypesList*>((yyvsp[-1]));
                    TypesList* t2 = dynamic_cast<TypesList*>((yyvsp[0]));
                    if(t1 != NULL || t2 != NULL){
                        (yyval) = new TypesList();
                        concatenate_params(dynamic_cast<TypesList*>((yyval))->params, t1, t2);
                    }
                    exit_scope(false, NULL, NULL);
                }
#line 1542 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 194 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    in_while--;
                    TypesList* t = dynamic_cast<TypesList*>((yyvsp[0]));
                    if(t != NULL){
                        (yyval) = new TypesList(t->params);
                    }
                    exit_scope(false, NULL, NULL);
                }
#line 1555 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 206 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    TypesList* t1 = dynamic_cast<TypesList*>((yyvsp[-1]));
                    TypesList* t2 = dynamic_cast<TypesList*>((yyvsp[0]));
                    if(t1 != NULL || t2 != NULL){
                        (yyval) = new TypesList();
                        concatenate_params(dynamic_cast<TypesList*>((yyval))->params, t1, t2);
                    }
                    exit_scope(false, NULL, NULL);
                  }
#line 1569 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 217 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    in_while--;
                    TypesList* t1 = dynamic_cast<TypesList*>((yyvsp[0]));
                    if(t1 != NULL){
                         (yyval) = new TypesList(t1->params);
                    }
                    exit_scope(false, NULL, NULL);
                  }
#line 1582 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 227 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {new_scope();}
#line 1588 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 228 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                   TypesList* t = dynamic_cast<TypesList*>((yyvsp[-1]));
                   if(t != NULL){
                        (yyval) = new TypesList(t->params);
                   }
                   exit_scope(false, NULL, NULL);
                  }
#line 1600 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 237 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {tryAddVariable((yyvsp[-2]), (yyvsp[-1]), false);}
#line 1606 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 240 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    Type *t = dynamic_cast<Type*>((yyvsp[-1]));
                    verifyType((yyvsp[-4]), t->type);
                    tryAddVariable((yyvsp[-4]), (yyvsp[-3]), false);
                    get_ID_reg((yyvsp[-3]));
                    Id* id = static_cast<Id*>((yyvsp[-3]));
                    string dest = id->type.reg;
                    move_data(dest, t->reg);
                  }
#line 1620 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 251 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    verifyIdType((yyvsp[-3]), (yyvsp[-1]));
                    verifyVariableDefined((yyvsp[-3]));
                    get_ID_reg((yyvsp[-3]));
                    Id* id = static_cast<Id*>((yyvsp[-3]));
                    string dest = id->type.reg;
                    Type* t = static_cast<Type*>((yyvsp[-1]));
                    move_data(dest, t->reg);
                }
#line 1634 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 262 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    verifyReturn(VOID);
                    int type = static_cast<int>(VOID);
                    vector<int> v;
                    v.push_back(type);
                    (yyval) = new TypesList(v);
                }
#line 1646 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 270 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    int type = static_cast<Type*>((yyvsp[-1]))->type;
                    verifyReturn(type);
                    vector<int> v;
                    v.push_back(type);
                    (yyval) = new TypesList(v);
                }
#line 1658 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 278 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                    verifyBreak();
                    (yyval) = new Type(static_cast<int>(VOID));
                }
#line 1667 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 284 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { verifyContinue(); }
#line 1673 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 289 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
                verifyFunctionDefined((yyvsp[-3]));
                (yyval) = new Type(getFunctionReturnType((yyvsp[-3])));
                verifyRightParams((yyvsp[-3]), (yyvsp[-1]));
            }
#line 1683 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 296 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
		        verifyFunctionDefined((yyvsp[-2]));
		        (yyval) = new Type(getFunctionReturnType((yyvsp[-2])));
		        TypesList* empty = new TypesList();
                verifyRightParams((yyvsp[-2]), empty);
		    }
#line 1694 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 305 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
            int type = static_cast<Type*>((yyvsp[0]))->type;
            vector<int> v;
            v.push_back(type);
            (yyval) = new TypesList(v);
        }
#line 1705 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 312 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
            int type = static_cast<Type*>((yyvsp[-2]))->type;
            vector<int> v1;
            v1.push_back(type);
            (yyval) = new TypesList(v1);
            vector<int>& v = static_cast<TypesList*>((yyval))->params;
            vector<int>& exp = static_cast<TypesList*>((yyvsp[0]))->params;
            v.insert(v.end(), exp.begin(), exp.end());
		}
#line 1719 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 324 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = new Type(INT); }
#line 1725 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 327 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = new Type(BYTE); }
#line 1731 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 330 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = new Type(BOOL); }
#line 1737 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 334 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = new Type(static_cast<Type*>((yyvsp[-1]))->type); }
#line 1743 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 337 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
        int t1 = verifyTypes((yyvsp[-2]), 3, NUM, BYTE, INT);
        int t2 = verifyTypes((yyvsp[0]), 3, NUM, BYTE, INT);

        // Try NUM precision first, retreat to byte if both are BYTE
        int preciseType = t1 == NUM ? NUM : (t2 == NUM ? NUM : BYTE);
        (yyval) = new Type(preciseType);

        Type* dest = static_cast<Type*>((yyval));
        Type* Rsrc = static_cast<Type*>((yyvsp[-2]));
        Type* src = static_cast<Type*>((yyvsp[0]));
        dest->reg = get_free_register();
        string binops = static_cast<Binop*>((yyvsp[-1]))->op;
        binop(dest, Rsrc, src, binops);
    }
#line 1763 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 354 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
        verifyVariableDefined((yyvsp[0]));
        Id* id = static_cast<Id*>((yyvsp[0]));
        get_ID_reg((yyvsp[0]));
        (yyval) = new Type(getVariableType((yyvsp[0])), id->type.reg);
    }
#line 1774 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 362 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1780 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 365 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
      (yyval) = new Type(NUM);
      int num = dynamic_cast<Num*>((yyvsp[0]))->val;
      Type* dest = static_cast<Type*>((yyval));
      dest->reg = int_to_string(num);
    }
#line 1791 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 373 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
	    verifyByteSize((yyvsp[-1]));
	    (yyval) = new Type(BYTE);
	}
#line 1800 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 379 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = new Type(STRING); }
#line 1806 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 382 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = new Type(BOOL); }
#line 1812 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 385 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = new Type(BOOL); }
#line 1818 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 388 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
    	verifyType((yyvsp[0]), BOOL);
        (yyval) = new Type(BOOL);
    }
#line 1827 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 393 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
	    verifyType((yyvsp[-2]), BOOL);
	    verifyType((yyvsp[0]), BOOL);
        (yyval) = new Type(BOOL);
    }
#line 1837 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 399 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
	    verifyType((yyvsp[-2]), BOOL);
     	verifyType((yyvsp[0]), BOOL);
        (yyval) = new Type(BOOL);
    }
#line 1847 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 405 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {
	    verifyTypes((yyvsp[-2]), 3, NUM, BYTE, INT);
	    verifyTypes((yyvsp[0]), 3, NUM, BYTE, INT);
	    (yyval) = new Type(BOOL);
	}
#line 1857 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 413 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {verifyType((yyvsp[-1]), BOOL); new_scope();}
#line 1863 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 415 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {exit_scope(false, NULL, NULL);}
#line 1869 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 415 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {new_scope();}
#line 1875 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 416 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-3]); }
#line 1881 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 418 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {in_while++;}
#line 1887 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 418 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1646  */
    {verifyType((yyvsp[-1]), BOOL); new_scope();}
#line 1893 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1897 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 420 "/cygdrive/c/Users/Gilad/ClionProjects/Compi5/parser.ypp" /* yacc.c:1906  */

