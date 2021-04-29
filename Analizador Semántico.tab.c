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

#line 78 "Analizador Semántico.tab.c" /* yacc.c:339  */

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

/* Copy the second part of user declarations.  */

#line 182 "Analizador Semántico.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   490

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    37,    37,    38,    38,    45,    45,    49,    50,    51,
      51,    53,    54,    55,    56,    57,    58,    59,    60,    62,
      61,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    89,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151
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
  "TERNARY", "BIN_TER", "BOOL_VAR", "INT_VAR", "FLOAT_VAR", "CHAR_VAR",
  "LIST", "STRING", "ID", "LEFT_BRACK", "RIGHT_BRACK", "COLON", "DEFAULT",
  "LOGIC_OR", "LOGIC_AND", "BIT_OR", "XOR", "BIT_AND", "EQ_NEQ",
  "VALUE_COMP", "ADD_SUB", "MULT", "MULT_OPS", "LIST_HEAD", "L_DECR",
  "L_INCR", "$accept", "Programa", "Bloque", "$@1", "$@2",
  "Declar_de_subprogs", "Declar_subprog", "$@3", "Cabecera_programa",
  "Variables_locales", "Cuerpo_declar_variables", "Lista_identificador",
  "Cabecera_subprog", "$@4", "Lista_parametros", "Parametros",
  "Sentencias", "Sentencia", "Sentencia_asignacion", "@5", "Sentencia_if",
  "Sentencia_while", "Sentencia_entrada", "Sentencia_salida",
  "Sentencia_return", "Sentencia_switch", "Sentencia_break",
  "Bloque_switch", "Sentencias_case", "Lista_expresiones_o_cadena",
  "Expresion", "Constantes", "Constante_lista", "Lista_int", "Lista_bool",
  "Lista_float", "Lista_char", "Funcion", "Lista_expresiones", "Tipo", YY_NULLPTR
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
     305,   306,   307
};
# endif

#define YYPACT_NINF -178

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define YYTABLE_NINF -25

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,    13,  -178,   -12,    50,    24,    57,     0,  -178,  -178,
      39,  -178,    71,  -178,    56,  -178,    29,    82,    94,     0,
     -15,  -178,  -178,  -178,  -178,  -178,    94,  -178,    65,    97,
    -178,    34,   192,  -178,    24,  -178,  -178,  -178,    94,  -178,
      68,  -178,   103,   122,   133,   160,   159,    11,    11,   130,
     134,    -8,   148,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,   171,  -178,  -178,   129,   159,   159,
      80,  -178,  -178,  -178,   159,   159,  -178,  -178,  -178,  -178,
     176,   143,   159,   159,    28,  -178,  -178,  -178,  -178,   135,
     373,   144,   162,   180,   181,   186,   187,   194,   203,     0,
     213,  -178,   177,   258,   299,   159,   182,   214,   309,    85,
     159,  -178,  -178,  -178,  -178,   215,   216,     7,    20,    25,
      41,    85,    85,  -178,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,  -178,   123,  -178,
    -178,  -178,  -178,  -178,  -178,   159,  -178,   116,  -178,  -178,
     234,   234,   336,    24,  -178,  -178,   373,   125,   212,  -178,
     195,   222,   201,   227,   208,   235,   211,   238,   363,    85,
      85,   400,   408,   435,   441,   153,   115,   287,    98,    85,
      85,  -178,   373,   248,  -178,   228,  -178,    24,    80,   159,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
     159,  -178,   234,    80,  -178,   373,    85,  -178,  -178
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   105,     0,     0,     0,     0,     0,   106,     1,
       5,     2,     0,    25,     0,    23,     0,     0,     0,     0,
       0,    12,    26,    14,    21,    28,     0,     9,     0,     0,
      22,     0,     0,     7,     0,    19,    11,    16,     0,    13,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,     0,    29,    27,    30,    42,    43,    31,    32,
      33,    34,    41,    10,     0,    28,    18,     0,     0,     0,
      57,    52,    53,    83,     0,     0,    85,    84,    87,    86,
      79,     0,     0,     0,     0,    81,    82,    80,    61,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,    63,
       0,    96,    94,    98,   100,     0,     0,     0,     0,     0,
       0,    69,    70,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,    50,
      37,    38,    35,    36,    40,     0,    39,     0,     4,    17,
       0,     0,     0,     0,    54,    62,   104,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      74,    64,    65,    67,    66,    68,    75,    76,    71,    72,
      73,    59,    58,     0,    20,    46,    48,     0,    57,     0,
     102,   101,    93,    88,    95,    89,    97,    90,    99,    91,
       0,    45,     0,    57,    56,   103,    78,    47,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,    -5,  -178,  -178,   -16,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,    -6,   226,   184,  -147,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -177,   217,
     -44,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    53,    17,    18,    25,    26,    34,     5,    31,
      39,    67,    27,    64,    14,    15,    32,    54,    55,    97,
      56,    57,    58,    59,    60,    61,    62,    71,   107,    89,
      90,    85,    86,   117,   118,   119,   120,    87,   157,    16
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,    13,    84,   185,   186,     2,     1,   -24,     8,   -24,
      33,   204,    73,    29,   160,    94,    95,    96,     3,    74,
       2,     7,    65,     2,   103,   104,   208,   162,    10,    63,
     108,   109,   164,     3,   123,    37,     3,    75,   121,   122,
      76,    77,    78,    79,   161,    88,    80,    81,   166,    38,
       9,   124,   125,    -3,     2,   207,   126,   163,    82,    83,
      12,   152,   165,    20,    22,    21,   156,     3,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   167,    19,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   147,   182,    24,    23,   105,    -8,    -8,
      35,   183,     6,    66,    20,    -8,    36,    -8,   124,   125,
      -8,    68,    -8,    -8,     2,    -8,    -8,    -8,    -8,   106,
      28,   124,   125,    20,    73,   184,   126,     3,    28,    -8,
      69,    74,   189,    40,   190,   101,   102,    70,   124,   125,
      28,   137,   138,   126,    -8,   205,   135,   136,   188,    75,
     139,   138,    76,    77,    78,    79,   206,   181,    80,    81,
      73,   133,   134,   135,   136,    92,    72,    74,   140,    93,
      82,    83,   111,   112,   113,   114,   124,   125,   115,    99,
     116,   126,   203,    98,   110,    75,   141,   142,    76,    77,
      78,    79,   143,   144,    80,    81,    10,    41,   132,   133,
     134,   135,   136,    42,   145,    43,    82,    83,    44,   146,
      45,    46,   149,    47,    48,    49,    50,    10,   148,   154,
     153,   191,   159,   158,    42,   192,    43,    51,   193,    44,
     194,    45,    46,   195,    47,    48,    49,    50,    10,   196,
     202,   197,    52,   198,   199,    42,    30,    43,    51,   100,
      44,     0,    45,    46,   201,    47,    48,    49,    50,     0,
       0,     0,     0,    52,     0,    91,     0,   150,     0,    51,
       0,   124,   125,     0,     0,     0,   126,     0,     0,     0,
       0,   124,   125,     0,    52,     0,   126,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   151,     0,
     124,   125,     0,     0,     0,   126,     0,     0,   155,     0,
       0,     0,   124,   125,     0,     0,     0,   126,     0,     0,
       0,     0,   124,   125,   134,   135,   136,   126,     0,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   124,
     125,     0,     0,     0,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   124,   125,     0,     0,
     200,   126,     0,     0,     0,     0,   124,   125,     0,     0,
       0,   126,     0,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   124,   125,     0,     0,     0,   126,     0,
       0,   124,   125,     0,     0,     0,   126,     0,     0,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     129,   130,   131,   132,   133,   134,   135,   136,   124,   125,
       0,     0,     0,   126,   124,   125,     0,     0,     0,   126,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   131,
     132,   133,   134,   135,   136,   131,   132,   133,   134,   135,
     136
};

static const yytype_int16 yycheck[] =
{
       5,     1,    46,   150,   151,    20,     3,     7,    20,     9,
      26,   188,     1,    19,     7,    23,    24,    25,    33,     8,
      20,     8,    38,    20,    68,    69,   203,     7,     4,    34,
      74,    75,     7,    33,     6,     1,    33,    26,    82,    83,
      29,    30,    31,    32,    37,    34,    35,    36,     7,    15,
       0,    23,    24,    14,    20,   202,    28,    37,    47,    48,
       3,   105,    37,     7,    35,     9,   110,    33,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    37,     8,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,    99,   138,     1,    14,    17,     4,     5,
      35,   145,     0,    35,     7,    11,     9,    13,    23,    24,
      16,     8,    18,    19,    20,    21,    22,    23,    24,    39,
      18,    23,    24,     7,     1,     9,    28,    33,    26,    35,
       8,     8,     7,    31,     9,     6,     7,     4,    23,    24,
      38,     6,     7,    28,    50,   189,    48,    49,   153,    26,
       6,     7,    29,    30,    31,    32,   200,    34,    35,    36,
       1,    46,    47,    48,    49,    35,     6,     8,     6,    35,
      47,    48,    29,    30,    31,    32,    23,    24,    35,     8,
      37,    28,   187,    35,     8,    26,     6,     6,    29,    30,
      31,    32,     6,     6,    35,    36,     4,     5,    45,    46,
      47,    48,    49,    11,    10,    13,    47,    48,    16,     6,
      18,    19,    35,    21,    22,    23,    24,     4,     5,     5,
      38,     9,     6,     8,    11,    30,    13,    35,     6,    16,
      29,    18,    19,     6,    21,    22,    23,    24,     4,    31,
      12,     6,    50,    32,     6,    11,    20,    13,    35,    65,
      16,    -1,    18,    19,     6,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    50,    -1,    48,    -1,     9,    -1,    35,
      -1,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    23,    24,    -1,    50,    -1,    28,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     9,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,     9,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    23,    24,    47,    48,    49,    28,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    23,
      24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    23,    24,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    28,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    23,    24,    -1,    -1,    -1,    28,    -1,
      -1,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      42,    43,    44,    45,    46,    47,    48,    49,    23,    24,
      -1,    -1,    -1,    28,    23,    24,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    44,    45,    46,    47,    48,
      49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    20,    33,    54,    61,    92,     8,    20,     0,
       4,    55,     3,     1,    67,    68,    92,    56,    57,     8,
       7,     9,    35,    14,     1,    58,    59,    65,    92,    67,
      68,    62,    69,    58,    60,    35,     9,     1,    15,    63,
      92,     5,    11,    13,    16,    18,    19,    21,    22,    23,
      24,    35,    50,    55,    70,    71,    73,    74,    75,    76,
      77,    78,    79,    55,    66,    58,    35,    64,     8,     8,
       4,    80,     6,     1,     8,    26,    29,    30,    31,    32,
      35,    36,    47,    48,    83,    84,    85,    90,    34,    82,
      83,    82,    35,    35,    23,    24,    25,    72,    35,     8,
      69,     6,     7,    83,    83,    17,    39,    81,    83,    83,
       8,    29,    30,    31,    32,    35,    37,    86,    87,    88,
      89,    83,    83,     6,    23,    24,    28,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,     6,     7,     6,
       6,     6,     6,     6,     6,    10,     6,    67,     5,    35,
       9,     9,    83,    38,     5,     9,    83,    91,     8,     6,
       7,    37,     7,    37,     7,    37,     7,    37,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    34,    83,    83,     9,    70,    70,    38,    55,     7,
       9,     9,    30,     6,    29,     6,    31,     6,    32,     6,
      27,     6,    12,    55,    81,    83,    83,    70,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    56,    55,    57,    55,    58,    58,    60,
      59,    61,    61,    62,    62,    63,    63,    64,    64,    66,
      65,    65,    67,    67,    67,    67,    68,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    72,    71,    73,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    81,    81,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    84,    85,    85,
      85,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    89,    90,    91,    91,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     8,     0,     5,     2,     0,     0,
       3,     5,     4,     2,     0,     3,     1,     3,     1,     0,
       6,     1,     3,     1,     0,     1,     2,     2,     0,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     0,     5,     5,     7,     5,     3,
       3,     3,     2,     2,     3,     5,     4,     0,     3,     3,
       1,     1,     3,     2,     3,     3,     3,     3,     3,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     4,     3,     1,     1,     2
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
        case 3:
#line 38 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaMARCA(); }
#line 1467 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 44 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_VaciarENTRADAS(); }
#line 1473 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 45 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaMARCA(); }
#line 1479 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 48 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_VaciarENTRADAS(); }
#line 1485 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 51 "Analizador Semántico.y" /* yacc.c:1646  */
    { subProg = 1; }
#line 1491 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 52 "Analizador Semántico.y" /* yacc.c:1646  */
    { subProg = 0; }
#line 1497 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 59 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaID((yyvsp[0])); }
#line 1503 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 60 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaID((yyvsp[0])); }
#line 1509 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 62 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaSUBPROG((yyvsp[0])); }
#line 1515 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 71 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_InsertaPARAMF((yyvsp[0])); }
#line 1521 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 89 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_BuscarID((yyvsp[0])); }
#line 1527 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 90 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_TypeCondition((yyvsp[-4]), (yyvsp[-2])); }
#line 1533 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 91 "Analizador Semántico.y" /* yacc.c:1646  */
    { TS_BoolCondition((yyvsp[-2])); }
#line 1539 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 92 "Analizador Semántico.y" /* yacc.c:1646  */
    {TS_BoolCondition((yyvsp[-4]));}
#line 1545 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 109 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpBoolBin((yyvsp[-2]), (yyvsp[0])); }
#line 1551 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 110 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpBoolBin((yyvsp[-2]), (yyvsp[0])); }
#line 1557 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 111 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpBoolBin((yyvsp[-2]), (yyvsp[0])); }
#line 1563 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 112 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpBoolBin((yyvsp[-2]), (yyvsp[0])); }
#line 1569 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 113 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpBoolBin((yyvsp[-2]), (yyvsp[0])); }
#line 1575 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 114 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpNumUnary((yyvsp[0])); }
#line 1581 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 115 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpBoolUnary((yyvsp[0])); }
#line 1587 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 116 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpNumBin((yyvsp[-2]), (yyvsp[0])); }
#line 1593 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 117 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpNumBin((yyvsp[-2]), (yyvsp[0])); }
#line 1599 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 118 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpNumBin((yyvsp[-2]), (yyvsp[0])); }
#line 1605 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 119 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpNumBin((yyvsp[-2]), (yyvsp[0])); }
#line 1611 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 120 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpComp((yyvsp[-2]), (yyvsp[0])); }
#line 1617 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 121 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_OpComp((yyvsp[-2]), (yyvsp[0])); }
#line 1623 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 124 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_BuscarID((yyvsp[0])); }
#line 1629 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 126 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval).atrib = (yyvsp[0]).atrib; (yyval).lexema = (yyvsp[0]).lexema; (yyval).tipo = (yyvsp[0]).tipo; }
#line 1635 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 146 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_BuscarID((yyvsp[-2])); }
#line 1641 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 147 "Analizador Semántico.y" /* yacc.c:1646  */
    { (yyval) = TS_BuscarID((yyvsp[-3])); }
#line 1647 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 150 "Analizador Semántico.y" /* yacc.c:1646  */
    {tipoTmp = (yyvsp[0]).tipo; }
#line 1653 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 151 "Analizador Semántico.y" /* yacc.c:1646  */
    {tipoTmp = lista;   }
#line 1659 "Analizador Semántico.tab.c" /* yacc.c:1646  */
    break;


#line 1663 "Analizador Semántico.tab.c" /* yacc.c:1646  */
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
#line 152 "Analizador Semántico.y" /* yacc.c:1906  */

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
