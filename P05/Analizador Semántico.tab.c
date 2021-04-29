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
#line 1 "Analizador Semántico.y" /* yacc.c:339  */

    #include "Analizador Semántico.h"
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern void yyerror(const char *str);
    extern FILE *yyin;
    extern int yylineno;


#line 79 "Analizador Semántico.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Analizador Semántico.tab.h".  */
#ifndef YY_YY_ANALIZADOR_SEM_NTICO_TAB_H_INCLUDED
# define YY_YY_ANALIZADOR_SEM_NTICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    BOOL_VAR = 283,
    INT_VAR = 284,
    FLOAT_VAR = 285,
    CHAR_VAR = 286,
    LIST = 287,
    STRING = 288,
    ID = 289,
    LEFT_BRACK = 290,
    RIGHT_BRACK = 291,
    COLON = 292,
    DEFAULT = 293,
    LOGIC_OR = 294,
    LOGIC_AND = 295,
    BIT_OR = 296,
    XOR = 297,
    BIT_AND = 298,
    EQ_NEQ = 299,
    VALUE_COMP = 300,
    ADD_SUB = 301,
    MULT = 302,
    LIST_HEAD = 303,
    LIST_BIN = 304,
    NOT = 305,
    LIST_UNARY = 306,
    L_DECR = 307,
    L_INCR = 308
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

/* Copy the second part of user declarations.  */

#line 184 "Analizador Semántico.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    40,    38,    45,    47,    44,    51,    50,
      55,    56,    58,    57,    62,    63,    65,    66,    68,    69,
      71,    73,    77,    76,    80,    82,    83,    84,    85,    87,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   100,
     102,   103,   103,   105,   105,   109,   108,   114,   113,   117,
     119,   123,   122,   127,   126,   130,   133,   136,   139,   142,
     144,   146,   148,   149,   150,   152,   154,   156,   158,   161,
     163,   165,   167,   169,   171,   173,   175,   177,   179,   181,
     183,   185,   187,   189,   191,   193,   195,   197,   199,   201,
     202,   203,   204,   205,   206,   208,   210,   212,   215,   218,
     220,   223,   225,   228,   231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "OPEN_BLOCK", "END_BLOCK",
  "SEMICOLON", "COMMA", "LEFT_PAR", "RIGHT_PAR", "ASSIGN", "IF", "ELSE",
  "WHILE", "VAR", "ENDVAR", "SWITCH", "CASE", "BREAK", "RETURN",
  "ELEM_TYPE", "READ", "WRITE", "INCR", "DECR", "AHEADBACK", "UNARY_OP",
  "TERNARY", "BOOL_VAR", "INT_VAR", "FLOAT_VAR", "CHAR_VAR", "LIST",
  "STRING", "ID", "LEFT_BRACK", "RIGHT_BRACK", "COLON", "DEFAULT",
  "LOGIC_OR", "LOGIC_AND", "BIT_OR", "XOR", "BIT_AND", "EQ_NEQ",
  "VALUE_COMP", "ADD_SUB", "MULT", "LIST_HEAD", "LIST_BIN", "NOT",
  "LIST_UNARY", "L_DECR", "L_INCR", "$accept", "Programa", "$@1", "$@2",
  "Bloque", "$@3", "$@4", "$@5", "Declar_de_subprogs", "Declar_subprog",
  "$@6", "Cabecera_programa", "Variables_locales",
  "Cuerpo_declar_variables", "Lista_identificador", "Cabecera_subprog",
  "$@7", "Lista_parametros", "Parametros", "Sentencias", "Sentencia",
  "$@8", "$@9", "Sentencia_asignacion", "$@10", "Sentencia_if", "$@11",
  "Sentencia_if2", "Sentencia_else", "$@12", "Sentencia_while", "$@13",
  "Sentencia_while2", "Sentencia_entrada", "Sentencia_salida",
  "Sentencia_return", "Sentencia_switch", "Sentencia_break",
  "Bloque_switch", "Sentencias_case", "Lista_expresiones_o_cadena",
  "Expresion", "Constantes", "Const_elem", "Const_lista", "Funcion",
  "Cabecera_func", "Lista_expresiones", "Tipo", "Ident", "IdFun", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -153

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-153)))

#define YYTABLE_NINF -105

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -153,    33,    65,  -153,    10,  -153,     2,  -153,    35,     5,
    -153,    79,    61,  -153,     1,  -153,    54,    77,  -153,     5,
     -13,  -153,  -153,    93,   175,    34,  -153,  -153,  -153,  -153,
     175,  -153,    69,  -153,     8,   195,  -153,    79,  -153,  -153,
    -153,  -153,    74,  -153,   105,   104,   139,    78,    16,  -153,
      78,  -153,  -153,   100,   108,  -153,  -153,  -153,  -153,  -153,
    -153,    92,  -153,   110,   175,  -153,    89,    -6,  -153,  -153,
    -153,   139,  -153,  -153,  -153,  -153,   115,   139,   139,   139,
     139,   247,  -153,  -153,  -153,  -153,    85,  -153,   120,   123,
    -153,    95,   335,   127,   126,  -153,   129,  -153,   132,   133,
       5,  -153,  -153,   107,   139,   109,   140,   286,   335,    22,
      82,    82,    82,  -153,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,  -153,    52,  -153,  -153,
    -153,   131,  -153,   139,   139,  -153,   139,    56,   214,  -153,
     297,    79,  -153,  -153,   139,  -153,   324,    82,   362,   371,
     398,   405,   411,   103,     7,    75,    82,    82,  -153,  -153,
     335,   335,   335,   259,  -153,  -153,    79,    -6,   335,   139,
     144,   145,  -153,    -6,  -153,    82,   233,  -153,   233,  -153,
    -153,   146,  -153,  -153,  -153,   233,  -153
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,   101,     0,     3,     0,     0,
     102,     0,     0,    28,     0,    26,     0,     8,     4,     0,
       0,    15,    29,     0,     0,     0,    25,    17,    24,    31,
       0,    12,     0,    14,     0,    41,    10,     0,    22,    19,
       6,    16,     0,     9,     0,     0,     0,     0,     0,   103,
       0,    32,    30,     0,     0,    33,    34,    35,    36,    37,
      40,    45,    13,     0,     0,    21,     0,    64,    59,    60,
      88,     0,    92,    91,    94,    93,   103,     0,     0,     0,
       0,     0,    87,    89,    90,    86,     0,    85,     0,     0,
      68,     0,    67,     0,     0,    42,     0,    44,     0,     0,
       0,    31,    18,     0,     0,     0,     0,     0,   100,     0,
      76,    70,    82,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,     0,    98,    56,
      57,     0,    38,     0,     0,    39,     0,     0,    41,    20,
       0,     0,    61,    69,     0,    95,     0,    83,    71,    72,
      74,    73,    75,    79,    80,    77,    78,    81,    96,    66,
      65,    47,    53,     0,    23,     7,     0,    64,    99,     0,
       0,     0,    46,    64,    63,    84,    41,    48,    41,    54,
      62,    49,    55,    51,    50,    41,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,  -153,   -11,  -153,  -153,  -153,   -25,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,   -16,   136,    62,
    -121,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -152,
    -153,   -44,  -153,  -153,  -153,  -153,  -153,    71,    18,   -34,
    -153
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    11,    51,    23,    64,    24,    29,    30,
      37,     7,    34,    41,    66,    31,    63,    14,    15,    35,
      52,    53,    54,    55,    99,    95,   170,   177,   184,   185,
      97,   171,   179,    56,    57,    58,    59,    60,    68,   106,
      91,   108,    82,    83,    84,    85,    86,   109,    16,    87,
      88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    61,    81,    25,    92,    36,    13,     5,    20,    39,
      21,   104,   -27,    89,   -27,   174,    93,    70,     9,     6,
       8,   180,    10,    40,    71,     5,    62,   107,     5,   144,
     114,   115,   105,     3,   110,   111,   112,     6,    12,   101,
       6,    20,    32,    33,    72,    73,    74,    75,    32,    90,
      76,    77,    42,   123,   124,   181,   125,   182,   145,   144,
     140,   158,    78,    20,   186,   164,    79,    80,     4,    19,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    32,    17,   137,     5,    70,   160,    22,   161,
     162,    -5,   163,    71,   126,   102,   103,     6,   114,   115,
     168,   130,   131,    38,    61,   114,   115,    27,    65,    67,
      69,    94,    49,    72,    73,    74,    75,    98,   100,    76,
      77,    96,   124,  -104,   125,   175,   114,   115,   128,   129,
     167,    78,    70,   132,   133,    79,    80,   134,   135,    71,
      70,   139,    61,   136,    61,   142,   141,    71,   122,   123,
     124,    61,   125,   176,   178,   173,    26,   127,   183,    72,
      73,    74,    75,   138,   159,    76,    77,    72,    73,    74,
      75,     0,     0,    76,    77,     0,    28,    78,     0,   -11,
     -11,    79,    80,     0,     0,    78,   -11,     0,   -11,    79,
      80,   -11,     0,   -11,   -11,     5,   -11,   -11,     0,    17,
      43,     0,     0,     0,     0,     0,     0,     6,   -43,   -11,
       0,    44,     0,    45,    46,     0,    47,    48,    17,   165,
       0,     0,     0,   -11,     0,     0,     0,   -43,     0,    49,
      44,     0,    45,    46,     0,    47,    48,    17,     0,     0,
       0,     0,     0,    50,     0,     0,   -43,     0,    49,    44,
       0,    45,    46,   113,    47,    48,     0,     0,     0,     0,
       0,     0,    50,     0,     0,   172,     0,    49,     0,     0,
     114,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   143,   125,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   166,   125,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,   114,   115,     0,
       0,   169,     0,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,   114,   115,     0,     0,     0,
       0,     0,     0,     0,   114,   115,     0,     0,     0,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   114,   115,     0,     0,     0,     0,     0,   114,   115,
       0,     0,     0,     0,   114,   115,     0,     0,     0,     0,
     119,   120,   121,   122,   123,   124,     0,   125,   120,   121,
     122,   123,   124,     0,   125,   121,   122,   123,   124,     0,
     125
};

static const yytype_int16 yycheck[] =
{
      11,    35,    46,    19,    48,    30,     1,    20,     7,     1,
       9,    17,     7,    47,     9,   167,    50,     1,     8,    32,
       2,   173,    20,    15,     8,    20,    37,    71,    20,     7,
      23,    24,    38,     0,    78,    79,    80,    32,     3,    64,
      32,     7,    24,     9,    28,    29,    30,    31,    30,    33,
      34,    35,    34,    46,    47,   176,    49,   178,    36,     7,
     104,     9,    46,     7,   185,     9,    50,    51,     3,     8,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    64,     4,   100,    20,     1,   131,    34,   133,
     134,    14,   136,     8,     9,     6,     7,    32,    23,    24,
     144,     6,     7,    34,   138,    23,    24,    14,    34,     4,
       6,    11,    34,    28,    29,    30,    31,    25,     8,    34,
      35,    13,    47,     8,    49,   169,    23,    24,     8,     6,
     141,    46,     1,     6,     8,    50,    51,     8,     6,     8,
       1,    34,   176,    10,   178,     5,    37,     8,    45,    46,
      47,   185,    49,     9,     9,   166,    20,    86,    12,    28,
      29,    30,    31,   101,    33,    34,    35,    28,    29,    30,
      31,    -1,    -1,    34,    35,    -1,     1,    46,    -1,     4,
       5,    50,    51,    -1,    -1,    46,    11,    -1,    13,    50,
      51,    16,    -1,    18,    19,    20,    21,    22,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    32,    13,    34,
      -1,    16,    -1,    18,    19,    -1,    21,    22,     4,     5,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    13,    -1,    34,
      16,    -1,    18,    19,    -1,    21,    22,     4,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    13,    -1,    34,    16,
      -1,    18,    19,     6,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,     6,    -1,    34,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    23,    24,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     9,    49,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    37,    49,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    23,    24,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    -1,    49,    43,    44,
      45,    46,    47,    -1,    49,    44,    45,    46,    47,    -1,
      49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    56,     0,     3,    20,    32,    65,   102,     8,
      20,    57,     3,     1,    71,    72,   102,     4,    58,     8,
       7,     9,    34,    59,    61,    71,    72,    14,     1,    62,
      63,    69,   102,     9,    66,    73,    62,    64,    34,     1,
      15,    67,   102,     5,    16,    18,    19,    21,    22,    34,
      48,    58,    74,    75,    76,    77,    87,    88,    89,    90,
      91,   103,    58,    70,    60,    34,    68,     4,    92,     6,
       1,     8,    28,    29,    30,    31,    34,    35,    46,    50,
      51,    95,    96,    97,    98,    99,   100,   103,   104,   103,
      33,    94,    95,   103,    11,    79,    13,    84,    25,    78,
       8,    62,     6,     7,    17,    38,    93,    95,    95,   101,
      95,    95,    95,     6,    23,    24,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    49,     9,   101,     8,     6,
       6,     7,     6,     8,     8,     6,    10,    71,    73,    34,
      95,    37,     5,     9,     7,    36,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,     9,    33,
      95,    95,    95,    95,     9,     5,    37,    58,    95,    27,
      80,    85,     6,    58,    93,    95,     9,    81,     9,    86,
      93,    74,    74,    12,    82,    83,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    56,    57,    55,    59,    60,    58,    61,    58,
      62,    62,    64,    63,    65,    65,    66,    66,    67,    67,
      68,    68,    70,    69,    69,    71,    71,    71,    71,    72,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    74,    76,    74,    78,    77,    80,    79,    81,
      81,    83,    82,    85,    84,    86,    87,    88,    89,    90,
      91,    92,    93,    93,    93,    94,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    97,    97,    97,    97,    98,    99,    99,   100,   101,
     101,   102,   102,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     4,     0,     0,     9,     0,     5,
       2,     0,     0,     3,     5,     4,     2,     0,     3,     1,
       3,     1,     0,     6,     1,     3,     1,     0,     1,     2,
       2,     0,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     0,     2,     0,     2,     0,     5,     0,     5,     2,
       3,     0,     3,     0,     5,     2,     3,     3,     3,     2,
       2,     3,     5,     4,     0,     3,     3,     1,     1,     3,
       2,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     2,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     2,     3,
       1,     1,     2,     1,     1
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
#line 38 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_GeneraFichero(); }
#line 1463 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 40 "Analizador Semántico.y" /* yacc.c:1646  */
    { mainVar = 1; }
#line 1469 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 42 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_CerrarFichero(); }
#line 1475 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 45 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaMARCA(); }
#line 1481 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 47 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_Cabecera(mainVar); GCI_InicioBloque(); mainVar = 0; }
#line 1487 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 49 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_FinBloque(); TS_VaciarENTRADAS(); }
#line 1493 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 51 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaMARCA(); GCI_Cabecera(mainVar); GCI_InicioBloque(); mainVar = 0;}
#line 1499 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 53 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_FinBloque(); TS_VaciarENTRADAS(); }
#line 1505 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "Analizador Semántico.y" /* yacc.c:1646  */
    { subProg = 1; }
#line 1511 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "Analizador Semántico.y" /* yacc.c:1646  */
    { subProg = 0; }
#line 1517 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 72 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaID((yyvsp[0])); }
#line 1523 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 74 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaID((yyvsp[0])); }
#line 1529 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 77 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaSUBPROG((yyvsp[0])); }
#line 1535 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 88 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaPARAMF((yyvsp[0])); }
#line 1541 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 99 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_CheckLista((yyvsp[-1])); }
#line 1547 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 101 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_CheckLista((yyvsp[-2])); }
#line 1553 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 103 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaMARCA(); GCI_InicioBloque(); GCI_InsertarDescriptor(0); isif = 1; }
#line 1559 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 105 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaMARCA(); GCI_InicioBloque(); GCI_InsertarDescriptor(1); isif = 2; }
#line 1565 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 109 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_InicioBloque(); }
#line 1571 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 111 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_MismoTipo((yyvsp[-4]), (yyvsp[-1])); GCI_Asignacion((yyvsp[-4]), (yyvsp[-1])); GCI_FinBloque(); }
#line 1577 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 114 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_CheckBooleano((yyvsp[0])); GCI_Condicion((yyvsp[0])); }
#line 1583 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 118 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_FinBloque(); GCI_Else(1); }
#line 1589 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 120 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_FinBloque(); GCI_Salida(); }
#line 1595 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 123 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_Else(0); }
#line 1601 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 127 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_CheckBooleano((yyvsp[0])); GCI_Condicion((yyvsp[0])); }
#line 1607 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 131 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_Loopback(); GCI_FinBloque(); GCI_Salida(); }
#line 1613 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 134 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_Read((yyvsp[-1])); }
#line 1619 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 137 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_WriteNewline(); }
#line 1625 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 140 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_TipoRetorno((yyvsp[-1])); }
#line 1631 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 153 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_Write((yyvsp[0]), 0); }
#line 1637 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 155 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_Write((yyvsp[0]), 1); }
#line 1643 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 157 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_Write((yyvsp[0]), 0); }
#line 1649 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 159 "Analizador Semántico.y" /* yacc.c:1646  */
    { GCI_Write((yyvsp[0]), 1); }
#line 1655 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 162 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1661 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 164 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarBoolUnario((yyvsp[-1]), (yyvsp[0])); }
#line 1667 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 166 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarBoolBinario((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1673 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 168 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarBoolBinario((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1679 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 170 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarBoolBinario((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1685 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 172 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarBoolBinario((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1691 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 174 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarBoolBinario((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1697 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 176 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarNumUnario((yyvsp[-1]), (yyvsp[0])); }
#line 1703 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 178 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarNumBinario((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1709 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 180 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarNumBinario((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1715 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 182 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarComp((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1721 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 184 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarComp((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1727 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 186 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarListBinario((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1733 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 188 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarListUnario((yyvsp[-1]), (yyvsp[0])); }
#line 1739 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 190 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarListBinario((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1745 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 192 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_AsignarListTernario((yyvsp[-4]), (yyvsp[-2]),   (yyvsp[0])); }
#line 1751 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 194 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1757 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 196 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1763 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 198 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1769 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 211 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_CheckFunc((yyvsp[-2])); nparams = 0; }
#line 1775 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 213 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_CheckFunc((yyvsp[-1])); nparams = 0; }
#line 1781 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 216 "Analizador Semántico.y" /* yacc.c:1646  */
    { func = (yyvsp[-1]); }
#line 1787 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 219 "Analizador Semántico.y" /* yacc.c:1646  */
    { nparams++; TS_CheckParam((yyvsp[0]));  }
#line 1793 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 221 "Analizador Semántico.y" /* yacc.c:1646  */
    { nparams++; TS_CheckParam((yyvsp[0])); }
#line 1799 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 224 "Analizador Semántico.y" /* yacc.c:1646  */
    { tipoTmp = (yyvsp[0]).tipo; list = 0; }
#line 1805 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 226 "Analizador Semántico.y" /* yacc.c:1646  */
    { tipoTmp = (yyvsp[0]).tipo; list = 1; }
#line 1811 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 229 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_BuscarID((yyvsp[0]));}
#line 1817 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 232 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_BuscarFunc((yyvsp[0])); }
#line 1823 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;


#line 1827 "Analizador Semántico.tab.c" /* yacc.c:1646  */
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
#line 234 "Analizador Semántico.y" /* yacc.c:1906  */

void yyerror(const char *str) {
    printf("\nError sintáctico en la línea %d: %s\n", yylineno, str);
}

int main (int argc, char** argv) {

    // Si no se envía un argumento (fichero) da error
	if (argc <= 1) {

        printf("\nError al ejecutar la aplicación...\n");
        printf("Uso: %s nombre_fichero_fuente\n", argv[0]);

		exit(-1);

	}

    // Abrimos el fichero 
    yyin = fopen(argv[1], "r");

    // Si "yyin" es nulo no se ha podido abrir
    if (yyin == NULL) {

        printf ("\nError al abrir el fichero %s\n", argv[1]);

        exit (-2);

    }

    printf("Leyendo %s\n", argv[1]);
    // Llamamos al analizador léxico para comenzar el análisis

    // Ejecutamos hasta que terminemos de analizar todo el archivo
    do {
        yyparse();
    } while (!feof(yyin));

	exit(1);

}
