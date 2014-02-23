/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "be10092011.y" /* yacc.c:339  */

#include <stdio.h>
#define CHAR (1<<0) 
#define INT (1<<1) 
#define FLOAT (1<<2) 
#define DOUBLE (1<<3) 
#define LONG (1<<4) 
#define LONG2 (1<<5) 
#define SHORT (1<<6) 
#define SIGNED (1<<7) 
#define UNSIGNED (1<<8) 
#define AUTO (1<<9) 
#define REGISTER (1<<10) 
#define STATIC (1<<11) 
#define EXTERN (1<<12) 

#line 83 "be10092011.tab.c" /* yacc.c:339  */

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
    KW_auto = 258,
    KW_double = 259,
    KW_int = 260,
    KW_struct = 261,
    KW_break = 262,
    KW_else = 263,
    KW_long = 264,
    KW_switch = 265,
    KW_case = 266,
    KW_enum = 267,
    KW_register = 268,
    KW_typedef = 269,
    KW_char = 270,
    KW_extern = 271,
    KW_return = 272,
    KW_union = 273,
    KW_const = 274,
    KW_float = 275,
    KW_short = 276,
    KW_unsigned = 277,
    KW_continue = 278,
    KW_for = 279,
    KW_signed = 280,
    KW_void = 281,
    KW_default = 282,
    KW_goto = 283,
    KW_sizeof = 284,
    KW_volatile = 285,
    KW_do = 286,
    KW_if = 287,
    KW_static = 288,
    KW_while = 289,
    OP_PLUS = 290,
    OP_MINUS = 291,
    OP_STAR = 292,
    OP_AMP = 293,
    OP_COMP = 294,
    OP_NEGATE = 295,
    OP_DIV = 296,
    OP_MOD = 297,
    OP_LT = 298,
    OP_GT = 299,
    OP_BITOR = 300,
    OP_BITXOR = 301,
    OP_ASSIGN = 302,
    OP_COMMA = 303,
    OP_DOT = 304,
    OP_QUES = 305,
    OP_INCR = 306,
    OP_DECR = 307,
    OP_LSHIFT = 308,
    OP_RSHIFT = 309,
    OP_LTE = 310,
    OP_GTE = 311,
    OP_EQ = 312,
    OP_NEQ = 313,
    OP_LOGAND = 314,
    OP_LOGOR = 315,
    OP_PLUSEQ = 316,
    OP_DIVEQ = 317,
    OP_MODEQ = 318,
    OP_MINUSEQ = 319,
    OP_MULEQ = 320,
    OP_LSHIFTEQ = 321,
    OP_RSHIFTEQ = 322,
    OP_OREQ = 323,
    OP_ANDEQ = 324,
    OP_XOREQ = 325,
    OP_DEREF = 326,
    OP_ELLIPSIS = 327,
    PUNC_OPBRACE = 328,
    PUNC_CLOSEBRACE = 329,
    PUNC_OPSQRBKT = 330,
    PUNC_CLOSESQRBKT = 331,
    PUNC_OPBKT = 332,
    PUNC_CLOSEBKT = 333,
    PUNC_SEMICOLON = 334,
    PUNC_COLON = 335,
    IDENTIFIER = 336,
    NUMBER = 337,
    REAL_NUMBER = 338,
    EXP_NUMBER = 339,
    CHAR_CONSTANT = 340,
    STRING_CONSTANT = 341
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "be10092011.y" /* yacc.c:355  */

int intVal;

#line 211 "be10092011.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 226 "be10092011.tab.c" /* yacc.c:358  */

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1685

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  376

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    23,    23,    24,    27,    28,    31,    32,    33,    34,
      37,    38,    41,    42,    45,    53,    56,   109,   112,   113,
     116,   117,   118,   119,   120,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   137,   138,   141,   142,
     143,   146,   147,   150,   151,   154,   155,   158,   159,   162,
     165,   166,   167,   168,   171,   172,   175,   176,   177,   180,
     181,   182,   185,   186,   189,   190,   193,   194,   197,   198,
     199,   200,   201,   202,   203,   206,   207,   208,   209,   212,
     213,   216,   217,   220,   221,   224,   225,   226,   229,   230,
     233,   234,   235,   238,   239,   242,   243,   246,   247,   248,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   263,
     264,   265,   266,   267,   268,   271,   272,   273,   276,   277,
     280,   281,   282,   283,   286,   287,   290,   291,   292,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   307,
     308,   309,   310,   311,   314,   315,   318,   319,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   335,
     336,   339,   342,   343,   346,   347,   350,   351,   353,   354,
     357,   358,   361,   362,   363,   366,   367,   368,   369,   370,
     373,   374,   375,   378,   379,   380,   383,   384,   385,   386,
     389,   390,   393,   394,   395,   396,   397,   398,   401,   402,
     403,   404,   405,   406,   409,   410,   411,   412,   413,   414,
     415,   416,   419,   420,   421,   422,   425,   426,   430,   431,
     432,   433
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_auto", "KW_double", "KW_int",
  "KW_struct", "KW_break", "KW_else", "KW_long", "KW_switch", "KW_case",
  "KW_enum", "KW_register", "KW_typedef", "KW_char", "KW_extern",
  "KW_return", "KW_union", "KW_const", "KW_float", "KW_short",
  "KW_unsigned", "KW_continue", "KW_for", "KW_signed", "KW_void",
  "KW_default", "KW_goto", "KW_sizeof", "KW_volatile", "KW_do", "KW_if",
  "KW_static", "KW_while", "OP_PLUS", "OP_MINUS", "OP_STAR", "OP_AMP",
  "OP_COMP", "OP_NEGATE", "OP_DIV", "OP_MOD", "OP_LT", "OP_GT", "OP_BITOR",
  "OP_BITXOR", "OP_ASSIGN", "OP_COMMA", "OP_DOT", "OP_QUES", "OP_INCR",
  "OP_DECR", "OP_LSHIFT", "OP_RSHIFT", "OP_LTE", "OP_GTE", "OP_EQ",
  "OP_NEQ", "OP_LOGAND", "OP_LOGOR", "OP_PLUSEQ", "OP_DIVEQ", "OP_MODEQ",
  "OP_MINUSEQ", "OP_MULEQ", "OP_LSHIFTEQ", "OP_RSHIFTEQ", "OP_OREQ",
  "OP_ANDEQ", "OP_XOREQ", "OP_DEREF", "OP_ELLIPSIS", "PUNC_OPBRACE",
  "PUNC_CLOSEBRACE", "PUNC_OPSQRBKT", "PUNC_CLOSESQRBKT", "PUNC_OPBKT",
  "PUNC_CLOSEBKT", "PUNC_SEMICOLON", "PUNC_COLON", "IDENTIFIER", "NUMBER",
  "REAL_NUMBER", "EXP_NUMBER", "CHAR_CONSTANT", "STRING_CONSTANT",
  "$accept", "translation-unit", "external-declaration",
  "function-definition", "declaration", "declaration-list",
  "declaration-specifiers", "storage-class-specifier", "type-specifier",
  "type-qualifier", "struct-or-union-specifier", "struct-or-union",
  "struct-declaration-list", "init-declarator-list", "init-declarator",
  "struct-declaration", "specifier-qualifier-list",
  "struct-declarator-list", "struct-declarator", "enum-specifier",
  "enumerator-list", "enumerator", "declarator", "direct-declarator",
  "pointer", "type-qualifier-list", "parameter-type-list",
  "parameter-list", "parameter-declaration", "identifier-list",
  "initializer", "initializer-list", "type-name", "abstract-declarator",
  "direct-abstract-declarator", "statement", "labeled-statement",
  "expression-statement", "compound-statement", "statement-list",
  "selection-statement", "iteration-statement", "jump-statement",
  "expression", "assignment-expression", "assignment-operator",
  "conditional-expression", "constant-expression", "logical-OR-expression",
  "logical-AND-expression", "inclusive-OR-expression",
  "exclusive-OR-expression", "AND-expression", "equality-expression",
  "relational-expression", "shift-expression", "additive-expression",
  "multiplicative-expression", "cast-expression", "unary-expression",
  "unary-operator", "postfix-expression", "primary-expression",
  "argument-expression-list", "constant", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
};
# endif

#define YYPACT_NINF -220

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-220)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     818,  -220,  -220,  -220,  -220,  -220,    69,  -220,  -220,  -220,
    -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,
     132,    -3,  -220,   523,  -220,  -220,  -220,     2,  1652,  1652,
    1652,  -220,    93,  -220,  1000,   140,     7,   -49,   -31,  -220,
    -220,   132,   -29,  -220,  -220,  -220,   -34,  -220,   964,  -220,
    -220,  -220,   695,    56,   315,  -220,  1000,     2,  -220,  1058,
     854,   140,   107,   -24,  -220,   -49,  -220,  -220,  -220,    -3,
    -220,  1116,  1000,  -220,   695,   695,   440,  -220,   -25,   695,
     -35,   106,  1492,  1134,   148,   130,   139,   157,  1550,   734,
     152,   167,  -220,  -220,  -220,  -220,  -220,  -220,  1568,  1568,
    -220,   482,  -220,   171,  -220,  -220,  -220,  -220,  -220,   399,
    -220,  -220,  -220,  -220,   574,  -220,  -220,  -220,   -26,  -220,
    -220,   113,   188,   207,   208,   215,    91,   124,    11,   189,
     168,  -220,   236,  1492,   307,  -220,  -220,  -220,  -220,   211,
    -220,  -220,  -220,   179,  -220,  -220,  -220,    36,   181,   212,
    -220,    -7,  1492,   -49,  -220,    13,  -220,  1116,  -220,  -220,
    -220,  -220,  -220,  -220,  -220,  1492,    19,  -220,   182,   624,
    -220,  1492,   191,  -220,    20,  -220,   194,   734,   195,   482,
    -220,   243,  1492,  1492,  1492,  -220,  -220,   -18,   202,    -1,
     734,  -220,   654,  -220,  -220,  1492,  -220,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  -220,  -220,  -220,  -220,
    -220,  -220,  -220,  -220,  -220,  -220,  -220,  1492,  -220,   203,
    -220,  -220,   204,  1492,  1192,  -220,  1210,   775,  -220,   100,
    -220,   141,  -220,  1035,   213,  -220,  -220,  -220,  -220,  -220,
      87,  -220,   -25,  -220,  1492,  -220,    58,   734,  -220,  1228,
    -220,  -220,   210,   231,    66,    67,   888,   145,  -220,  1492,
    -220,  -220,  -220,  -220,   -10,   188,   207,   208,   215,    91,
     124,   124,    11,    11,    11,    11,   189,   189,   168,   168,
    -220,  -220,  -220,  -220,  -220,  -220,    62,  -220,  -220,    68,
    -220,   233,  -220,   232,   234,   141,  1286,   924,  -220,  -220,
    -220,  1040,  -220,  -220,  -220,   734,  -220,  1304,    49,  -220,
    1492,   734,   734,  -220,  1492,  -220,  1492,  -220,  -220,  -220,
    -220,  -220,   237,  -220,   238,  -220,  -220,  -220,  1362,    53,
    1380,    75,   281,  -220,  -220,  -220,  -220,  -220,   734,    77,
    1398,  1456,    64,   235,   734,  -220,   734,   734,    78,   734,
      79,  1474,  -220,  -220,  -220,  -220,   734,  -220,   734,   734,
      86,  -220,  -220,  -220,   734,  -220
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    31,    28,    41,    29,     0,    21,    24,    26,
      23,    42,    36,    30,    27,    33,    32,    25,    37,    22,
      76,     0,    68,     0,     2,     4,     5,     0,    15,    17,
      19,    34,     0,    35,     0,    67,     0,     0,    61,    79,
      78,    75,     0,     1,     3,    11,     0,    45,    47,    14,
      16,    18,     0,    40,     0,    12,     0,     0,     9,     0,
       0,    66,    64,     0,    62,     0,    80,    77,    69,     0,
      10,     0,     0,     7,    51,    53,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,   201,   199,   198,   202,   203,     0,     0,
     123,     0,   119,   212,   218,   220,   221,   219,   214,     0,
     124,   109,   110,   111,     0,   112,   113,   114,     0,   144,
     146,   159,   162,   164,   166,   168,   170,   172,   175,   180,
     183,   186,   190,     0,   192,   204,   213,    13,     8,    47,
      71,   212,   161,     0,   190,    74,    88,    87,     0,    81,
      83,     0,     0,     0,    60,     0,    46,     0,    48,    90,
       6,    50,    52,    39,    44,     0,     0,    54,    56,     0,
     141,     0,     0,   143,     0,   140,     0,     0,     0,     0,
     196,     0,     0,     0,     0,   193,   194,    96,     0,     0,
       0,   122,     0,   121,   125,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   152,   150,   151,
     153,   149,   154,   155,   158,   156,   157,     0,   195,     0,
     210,   211,     0,     0,     0,    70,     0,     0,    85,    97,
      86,    99,    72,     0,     0,    73,    65,    63,    59,    93,
       0,    58,     0,    49,     0,    38,     0,     0,   142,     0,
     117,   139,     0,     0,     0,     0,     0,    97,    95,     0,
     215,   115,   120,   145,     0,   163,   165,   167,   169,   171,
     173,   174,   176,   177,   178,   179,   181,   182,   184,   185,
     187,   188,   189,   147,   208,   209,     0,   207,   216,     0,
     104,     0,   108,     0,     0,    98,     0,     0,    82,    84,
      89,     0,    91,    55,    57,     0,   116,     0,     0,   197,
       0,     0,     0,   191,     0,   205,     0,   206,   103,   107,
     100,   102,     0,   106,     0,    92,    94,   128,     0,     0,
       0,     0,   126,   129,   160,   217,   101,   105,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,   130,   127,   137,   136,     0,   134,     0,     0,
       0,   135,   133,   132,     0,   131
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -220,  -220,   292,  -220,    10,   128,     0,  -220,   -39,   216,
    -220,  -220,   244,  -220,   288,   -69,   -58,  -220,   108,  -220,
     296,   209,    -6,   -33,   -16,  -220,   -59,  -220,   120,  -220,
    -152,  -220,   185,  -129,  -219,   -87,  -220,  -220,    46,   256,
    -220,  -220,  -220,   -75,   -62,  -220,   -28,   -76,  -220,   170,
     172,   169,   173,   174,    29,     6,    30,    -8,  -122,   -13,
    -220,  -220,  -220,  -220,  -220
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    55,    56,    57,    28,    29,    30,
      31,    32,    76,    46,    47,    77,    78,   166,   167,    33,
      63,    64,    34,    35,    36,    41,   303,   149,   150,   151,
     158,   250,   188,   304,   241,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   227,   120,   143,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   299,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      27,   148,   181,    61,    40,   249,   172,   164,   174,   159,
      26,   228,    20,    74,    69,    42,   161,   162,   240,    20,
     305,    48,   195,    27,   153,    67,   189,   194,    49,    50,
      51,   142,    62,    26,    20,    74,    74,    74,   195,    20,
      74,   244,    65,   187,   170,    70,   144,   195,   305,    68,
     154,   139,    21,   196,   142,   165,    22,   236,   268,   266,
     147,   153,    74,   139,   209,   210,   137,   252,   195,   144,
     324,   245,   168,    20,    21,   180,   246,   270,    22,    21,
      58,    45,   137,    22,    21,   185,   186,   248,    22,   251,
     260,   290,   291,   292,    73,   159,   256,   195,   253,   258,
     164,   195,   138,   271,   189,   194,   195,   264,   265,   189,
     195,   236,   195,   237,   195,   195,   326,    22,   160,   137,
     144,   187,   274,   195,   142,   195,   195,   195,   340,    79,
      74,   239,   350,   273,   195,   311,   315,   142,   325,   144,
      74,   238,    37,   361,   321,   322,   327,   323,   203,   204,
      38,    12,   144,   353,   152,   356,   366,   368,   296,   336,
     301,   312,    18,   197,   374,   293,    52,   205,   206,    20,
     316,   267,   298,   198,    53,   236,    72,   237,   314,   207,
     208,    22,   109,   171,   318,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   288,   289,   213,    61,   176,   142,   214,
     215,   282,   283,   284,   285,    59,   306,    60,   307,   177,
     236,   239,   266,   144,   211,   212,   142,   175,   337,   182,
     332,    42,   280,   281,   342,   343,    39,   147,   178,   286,
     287,   144,   339,   147,   183,   341,   168,   199,   334,   159,
     267,   190,   200,   202,   201,   235,   144,    66,    71,   242,
     243,   355,   254,   349,   345,   352,   147,   363,    75,   364,
     365,   257,   367,   259,   261,   358,   360,   263,   142,   371,
     269,   372,   373,   216,   294,   295,   370,   375,   319,   354,
      75,    75,    75,   144,   310,    75,   344,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   147,   320,   328,
     329,   144,   330,   346,   362,    44,   347,    75,     1,     2,
       3,     4,    80,   169,     5,    81,    82,     6,     7,     8,
       9,    10,    83,    11,    12,    13,    14,    15,    84,    85,
      16,    17,    86,    87,    88,    18,    89,    90,    19,    91,
      92,    93,    94,    95,    96,    97,   229,   156,   230,   231,
     313,   155,   247,   309,   262,   192,    98,    99,   275,   277,
       0,   276,     0,     0,   278,     0,   279,     0,   232,     0,
       0,     0,   233,     0,   234,    75,     0,     0,    54,   100,
       0,     0,   101,     0,   102,    75,   103,   104,   105,   106,
     107,   108,     1,     2,     3,     4,    80,     0,     5,    81,
      82,     6,     7,     8,     9,    10,    83,    11,    12,    13,
      14,    15,    84,    85,    16,    17,    86,    87,    88,    18,
      89,    90,    19,    91,    92,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     2,     3,     4,     0,     0,     5,
      98,    99,     6,     0,     0,     9,     0,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,    54,   191,     0,     0,   101,     0,   102,     0,
     103,   104,   105,   106,   107,   108,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     9,     0,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     0,
       0,    88,    18,     0,   163,     0,     0,    92,    93,    94,
      95,    96,    97,    43,     0,     0,     1,     2,     3,     4,
       0,     0,     5,    98,    99,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,     0,    18,     0,     0,    19,     0,     0,   101,
      20,     0,     0,   141,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    81,    82,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,    84,    85,     0,
      21,    86,    87,    88,    22,    89,    90,     0,    91,    92,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,     0,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     0,     0,     9,
       0,     0,    11,    12,    13,    14,    15,    54,   193,    16,
      17,   101,     0,   102,    18,   103,   104,   105,   106,   107,
     108,    80,     0,     0,    81,    82,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,    84,    85,     0,
       0,    86,    87,    88,     0,    89,    90,     0,    91,    92,
      93,    94,    95,    96,    97,     0,     0,     0,   255,     2,
       3,     4,     0,     0,     5,    98,    99,     6,     0,     0,
       9,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,    54,   272,     0,
       0,   101,     0,   102,     0,   103,   104,   105,   106,   107,
     108,    80,     0,     0,    81,    82,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,    84,    85,     0,
       0,    86,    87,    88,     0,    89,    90,     0,    91,    92,
      93,    94,    95,    96,    97,     0,     0,     0,     1,     2,
       3,     4,     0,     0,     5,    98,    99,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,    54,    19,     0,
       0,   101,    20,   102,     0,   103,   104,   105,   106,   107,
     108,     1,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,    18,     0,
     236,    19,   237,   302,     0,    20,    22,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,     0,
       0,     1,     2,     3,     4,    21,     0,     5,     0,    22,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,    18,     0,
       0,    19,     0,     0,     0,    20,     0,     1,     2,     3,
       4,     0,   145,     5,     0,   146,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,     0,
       0,     0,     0,   236,     0,   266,   302,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,     0,
       0,     0,   333,     1,     2,     3,     4,     0,     0,     5,
       0,    71,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,     0,     0,    54,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,    19,    88,
       0,     0,     0,    54,     0,    92,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,    98,    99,    92,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,   308,     0,    98,
      99,     0,     0,   157,   335,     0,     0,   101,     0,     0,
       0,   141,   104,   105,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,   140,   101,     0,     0,     0,   141,
     104,   105,   106,   107,   108,    88,     0,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,    98,    99,    92,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,     0,     0,   157,
       0,     0,     0,   101,     0,     0,     0,   141,   104,   105,
     106,   107,   108,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,   173,     0,   141,   104,   105,   106,   107,
     108,    88,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,    98,    99,    92,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,    98,    99,    92,    93,    94,    95,    96,    97,   101,
     297,     0,     0,   141,   104,   105,   106,   107,   108,    98,
      99,     0,     0,     0,     0,     0,   300,   101,     0,     0,
       0,   141,   104,   105,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,     0,   101,     0,   317,     0,   141,
     104,   105,   106,   107,   108,    88,     0,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,    98,    99,    92,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,     0,     0,     0,
       0,     0,   331,   101,     0,     0,     0,   141,   104,   105,
     106,   107,   108,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,   338,     0,   141,   104,   105,   106,   107,
     108,    88,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,    98,    99,    92,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,    98,    99,    92,    93,    94,    95,    96,    97,   101,
     348,     0,     0,   141,   104,   105,   106,   107,   108,    98,
      99,     0,     0,     0,     0,     0,     0,   101,     0,   351,
       0,   141,   104,   105,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   357,     0,     0,   141,
     104,   105,   106,   107,   108,    88,     0,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,    98,    99,    92,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,    98,    99,    92,    93,    94,
      95,    96,    97,   101,   359,     0,     0,   141,   104,   105,
     106,   107,   108,    98,    99,     0,     0,     0,     0,     0,
       0,   101,   369,     0,     0,   141,   104,   105,   106,   107,
     108,     0,     0,     0,     0,     0,     0,     0,     0,   101,
       0,     0,     0,   141,   104,   105,   106,   107,   108,    88,
       0,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,    98,    99,    92,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      99,     0,     0,     0,     0,     0,     0,   179,     0,     0,
       0,   141,   104,   105,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,     0,   184,     0,     0,     0,   141,
     104,   105,   106,   107,   108,     1,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     0,
       0,     0,    18,     0,     0,    19
};

static const yytype_int16 yycheck[] =
{
       0,    60,    89,    36,    20,   157,    82,    76,    83,    71,
       0,   133,    37,    52,    48,    21,    74,    75,   147,    37,
     239,    27,    48,    23,    48,    41,   101,   114,    28,    29,
      30,    59,    81,    23,    37,    74,    75,    76,    48,    37,
      79,    48,    73,   101,    79,    79,    59,    48,   267,    78,
      74,    57,    77,    79,    82,    80,    81,    75,   187,    77,
      60,    48,   101,    69,    53,    54,    56,    48,    48,    82,
      80,    78,    78,    37,    77,    88,   152,    78,    81,    77,
      34,    79,    72,    81,    77,    98,    99,    74,    81,   165,
     177,   213,   214,   215,    48,   157,   171,    48,    79,    79,
     169,    48,    56,   190,   179,   192,    48,   182,   183,   184,
      48,    75,    48,    77,    48,    48,    48,    81,    72,   109,
     133,   179,   197,    48,   152,    48,    48,    48,    79,    73,
     169,   147,    79,   195,    48,    48,    78,   165,    76,   152,
     179,   147,    73,    79,    78,    78,    78,   269,    57,    58,
      81,    19,   165,    78,    47,    78,    78,    78,   233,   311,
     236,    74,    30,    50,    78,   227,    73,    43,    44,    37,
     257,   187,   234,    60,    81,    75,    48,    77,   254,    55,
      56,    81,    54,    77,   259,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   211,   212,    37,   239,    77,   236,    41,
      42,   205,   206,   207,   208,    75,    75,    77,    77,    80,
      75,   237,    77,   236,    35,    36,   254,    79,   315,    77,
     306,   237,   203,   204,   321,   322,    20,   237,    81,   209,
     210,   254,   317,   243,    77,   320,   252,    59,   307,   311,
     266,    80,    45,    38,    46,    76,   269,    41,    47,    78,
      48,   348,    80,   338,   326,   340,   266,   354,    52,   356,
     357,    80,   359,    79,    79,   350,   351,    34,   306,   366,
      78,   368,   369,    47,    81,    81,   361,   374,    78,     8,
      74,    75,    76,   306,    81,    79,   324,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,   307,    77,    76,
      78,   324,    78,    76,    79,    23,    78,   101,     3,     4,
       5,     6,     7,    79,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    49,    69,    51,    52,
     252,    65,   153,   243,   179,   109,    51,    52,   198,   200,
      -1,   199,    -1,    -1,   201,    -1,   202,    -1,    71,    -1,
      -1,    -1,    75,    -1,    77,   169,    -1,    -1,    73,    74,
      -1,    -1,    77,    -1,    79,   179,    81,    82,    83,    84,
      85,    86,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,     9,
      51,    52,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    73,    74,    -1,    -1,    77,    -1,    79,    -1,
      81,    82,    83,    84,    85,    86,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    29,    30,    -1,    74,    -1,    -1,    35,    36,    37,
      38,    39,    40,     0,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    51,    52,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,    77,
      37,    -1,    -1,    81,    82,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      77,    27,    28,    29,    81,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,
      -1,    -1,    18,    19,    20,    21,    22,    73,    74,    25,
      26,    77,    -1,    79,    30,    81,    82,    83,    84,    85,
      86,     7,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    74,     4,
       5,     6,    -1,    -1,     9,    51,    52,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    73,    74,    -1,
      -1,    77,    -1,    79,    -1,    81,    82,    83,    84,    85,
      86,     7,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    51,    52,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    73,    33,    -1,
      -1,    77,    37,    79,    -1,    81,    82,    83,    84,    85,
      86,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      75,    33,    77,    78,    -1,    37,    81,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,     3,     4,     5,     6,    77,    -1,     9,    -1,    81,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    37,    -1,     3,     4,     5,
       6,    -1,    78,     9,    -1,    81,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    77,    78,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    78,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    47,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    73,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    29,
      -1,    -1,    -1,    73,    -1,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    51,    52,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    51,
      52,    -1,    -1,    73,    74,    -1,    -1,    77,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    29,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    51,    52,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    73,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    82,    83,    84,    85,
      86,    29,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    51,    52,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    51,    52,    35,    36,    37,    38,    39,    40,    77,
      78,    -1,    -1,    81,    82,    83,    84,    85,    86,    51,
      52,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      82,    83,    84,    85,    86,    29,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    51,    52,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    76,    77,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    82,    83,    84,    85,
      86,    29,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    51,    52,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    51,    52,    35,    36,    37,    38,    39,    40,    77,
      78,    -1,    -1,    81,    82,    83,    84,    85,    86,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    81,
      82,    83,    84,    85,    86,    29,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    51,    52,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    51,    52,    35,    36,    37,
      38,    39,    40,    77,    78,    -1,    -1,    81,    82,    83,
      84,    85,    86,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    86,    29,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    51,    52,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    12,    13,    14,    15,
      16,    18,    19,    20,    21,    22,    25,    26,    30,    33,
      37,    77,    81,    88,    89,    90,    91,    93,    94,    95,
      96,    97,    98,   106,   109,   110,   111,    73,    81,    96,
     111,   112,   109,     0,    89,    79,   100,   101,   109,    93,
      93,    93,    73,    81,    73,    91,    92,    93,   125,    75,
      77,   110,    81,   107,   108,    73,    96,   111,    78,    48,
      79,    47,    92,   125,    95,    96,    99,   102,   103,    73,
       7,    10,    11,    17,    23,    24,    27,    28,    29,    31,
      32,    34,    35,    36,    37,    38,    39,    40,    51,    52,
      74,    77,    79,    81,    82,    83,    84,    85,    86,    92,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     133,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   151,    91,   125,   109,
      76,    81,   133,   134,   146,    78,    81,    93,   113,   114,
     115,   116,    47,    48,    74,   107,   101,    73,   117,   131,
     125,   103,   103,    74,   102,    80,   104,   105,   109,    99,
      79,    77,   134,    79,   130,    79,    77,    80,    81,    77,
     146,   122,    77,    77,    77,   146,   146,   103,   119,   130,
      80,    74,   126,    74,   122,    48,    79,    50,    60,    59,
      45,    46,    38,    57,    58,    43,    44,    55,    56,    53,
      54,    35,    36,    37,    41,    42,    47,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,   132,   145,    49,
      51,    52,    71,    75,    77,    76,    75,    77,   109,   111,
     120,   121,    78,    48,    48,    78,   134,   108,    74,   117,
     118,   134,    48,    79,    80,    74,   130,    80,    79,    79,
     122,    79,   119,    34,   130,   130,    77,   111,   120,    78,
      78,   122,    74,   131,   130,   136,   137,   138,   139,   140,
     141,   141,   142,   142,   142,   142,   143,   143,   144,   144,
     145,   145,   145,   131,    81,    81,   130,    78,   131,   150,
      76,   134,    78,   113,   120,   121,    75,    77,    72,   115,
      81,    48,    74,   105,   134,    78,   122,    79,   130,    78,
      77,    78,    78,   145,    80,    76,    48,    78,    76,    78,
      78,    76,   134,    78,   113,    74,   117,   122,    79,   130,
      79,   130,   122,   122,   133,   131,    76,    78,    78,   130,
      79,    79,   130,    78,     8,   122,    78,    78,   130,    78,
     130,    79,    79,   122,   122,   122,    78,   122,    78,    78,
     130,   122,   122,   122,    78,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    89,    89,    90,    90,    90,    90,
      91,    91,    92,    92,    93,    93,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    97,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     103,   103,   103,   103,   104,   104,   105,   105,   105,   106,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   111,   111,   111,   111,   112,
     112,   113,   113,   114,   114,   115,   115,   115,   116,   116,
     117,   117,   117,   118,   118,   119,   119,   120,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   122,   123,   123,   123,   124,   124,
     125,   125,   125,   125,   126,   126,   127,   127,   127,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   133,
     133,   134,   135,   135,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   140,   140,   141,   141,   141,   141,   141,
     142,   142,   142,   143,   143,   143,   144,   144,   144,   144,
     145,   145,   146,   146,   146,   146,   146,   146,   147,   147,
     147,   147,   147,   147,   148,   148,   148,   148,   148,   148,
     148,   148,   149,   149,   149,   149,   150,   150,   151,   151,
     151,   151
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     4,     3,     3,     2,
       3,     2,     1,     2,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       2,     1,     1,     1,     2,     1,     3,     1,     3,     3,
       2,     1,     2,     1,     1,     3,     1,     3,     2,     5,
       4,     2,     1,     3,     1,     3,     2,     1,     1,     3,
       4,     3,     4,     4,     3,     2,     1,     3,     2,     1,
       2,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       1,     3,     4,     1,     3,     2,     1,     1,     2,     1,
       3,     4,     3,     3,     2,     4,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     1,
       4,     3,     3,     2,     1,     2,     5,     7,     5,     5,
       7,    10,     9,     9,     8,     9,     8,     8,     7,     3,
       2,     2,     3,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     4,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     3,     3,
       2,     2,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1
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
#line 23 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttranslation-unit ->  external-declaration \n");}
#line 1869 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 24 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttranslation-unit ->  translation-unit external-declaration \n");}
#line 1875 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 27 "be10092011.y" /* yacc.c:1646  */
    {printf("\texternal-declaration ->  function-definition \n");}
#line 1881 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 28 "be10092011.y" /* yacc.c:1646  */
    {printf("\texternal-declaration ->  declaration \n");}
#line 1887 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 31 "be10092011.y" /* yacc.c:1646  */
    {printf("\tfunction-definition ->  declaration-specifiers declarator declaration-list compound-statement \n");}
#line 1893 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 32 "be10092011.y" /* yacc.c:1646  */
    {printf("\tfunction-definition ->  declaration-specifiers declarator compound-statement \n");}
#line 1899 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 33 "be10092011.y" /* yacc.c:1646  */
    {printf("\tfunction-definition ->  declarator declaration-list compound-statement \n");}
#line 1905 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 34 "be10092011.y" /* yacc.c:1646  */
    {printf("\tfunction-definition ->  declarator compound-statement \n");}
#line 1911 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 37 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdeclaration ->  declaration-specifiers init-declarator-list PUNC_SEMICOLON \n");}
#line 1917 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 38 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdeclaration ->  declaration-specifiers PUNC_SEMICOLON \n");}
#line 1923 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 41 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdeclaration-list ->  declaration \n");}
#line 1929 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 42 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdeclaration-list ->  declaration-list declaration \n");}
#line 1935 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 45 "be10092011.y" /* yacc.c:1646  */
    {int DS;printf("\tdeclaration-specifiers ->  storage-class-specifier declaration-specifiers \n");
DS = STATIC+REGISTER+AUTO+EXTERN;
if((DS & (yyvsp[0].intVal)) && (DS & (yyvsp[-1].intVal))){
	yyerror();
	YYERROR;
}
(yyval.intVal) = (yyvsp[-1].intVal) | (yyvsp[0].intVal);
}
#line 1948 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 53 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdeclaration-specifiers ->  storage-class-specifier \n");
(yyval.intVal) = (yyvsp[0].intVal);
}
#line 1956 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 56 "be10092011.y" /* yacc.c:1646  */
    {int DS;printf("\tdeclaration-specifiers ->  type-specifier declaration-specifiers \n");
DS = CHAR + DOUBLE + INT + FLOAT;
if((DS & (yyvsp[0].intVal)) && (DS & (yyvsp[-1].intVal))){
	if((LONG & (yyvsp[-1].intVal)) && (LONG & (yyvsp[0].intVal))){
		if(((DS & (yyvsp[0].intVal)) == INT) ^ ((DS & (yyvsp[-1].intVal)) == INT)){
			if((DS & (yyvsp[0].intVal)) == INT) (yyvsp[0].intVal) ^= INT; else (yyvsp[-1].intVal) ^= INT;
		}else{
			yyerror(); YYERROR;
		}
	}else
	{yyerror();
	YYERROR;}
}
if((LONG & (yyvsp[-1].intVal)) && (LONG & (yyvsp[0].intVal))){
	if((LONG2 & (yyvsp[-1].intVal)) || (LONG2 & (yyvsp[0].intVal))){yyerror(); YYERROR;}
	(yyvsp[-1].intVal) |= LONG2;
}
if(((yyvsp[-1].intVal) & SIGNED) && ((yyvsp[0].intVal) & SIGNED)){yyerror(); YYERROR;}
if(((yyvsp[-1].intVal) & UNSIGNED) && ((yyvsp[0].intVal) & UNSIGNED)){yyerror(); YYERROR;}
if(((yyvsp[-1].intVal) & SHORT) && ((yyvsp[0].intVal) & SHORT)){yyerror(); YYERROR;}
(yyval.intVal) = (yyvsp[-1].intVal) + (yyvsp[0].intVal);
if(((yyval.intVal) & SIGNED) && ((yyval.intVal) & UNSIGNED)){yyerror(); YYERROR;}
if((yyval.intVal) & CHAR){
	if(((yyval.intVal) & LONG) || ((yyval.intVal) & SHORT)){yyerror(); YYERROR;}
	if(((yyval.intVal) & (~(SIGNED | UNSIGNED | CHAR | STATIC | AUTO | EXTERN | REGISTER)))){
		yyerror();
		YYERROR;
	}
}
if ((yyval.intVal) & FLOAT){
DS = AUTO|EXTERN|STATIC|REGISTER;
if(((yyval.intVal) ^ FLOAT)&(~DS)){
		yyerror(); YYERROR;
	}
}

if((yyval.intVal) & DOUBLE){
DS = AUTO|EXTERN|STATIC|REGISTER;
	if(((yyval.intVal) ^ DOUBLE)&(~(DS|LONG))){
		yyerror(); YYERROR;
	}
}
if((yyval.intVal) & DOUBLE){
int tmp = (yyval.intVal);
DS = AUTO|EXTERN|STATIC|REGISTER;
(yyval.intVal) &= (~DS);
(yyval.intVal) ^= INT;
	if(((yyval.intVal) & SIGNED) && ((yyval.intVal) & UNSIGNED)){yyerror(); YYERROR;};
	if(((yyval.intVal) & SHORT) && ((yyval.intVal) & LONG)){yyerror(); YYERROR;};
}


}
#line 2014 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 109 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdeclaration-specifiers ->  type-specifier \n");
(yyval.intVal) = (yyvsp[0].intVal);
}
#line 2022 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 112 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdeclaration-specifiers ->  type-qualifier declaration-specifiers \n");}
#line 2028 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 113 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdeclaration-specifiers ->  type-qualifier \n");}
#line 2034 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstorage-class-specifier ->  KW_auto \n"); (yyval.intVal) = AUTO;}
#line 2040 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstorage-class-specifier ->  KW_register \n"); (yyval.intVal) = REGISTER;}
#line 2046 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstorage-class-specifier ->  KW_static \n"); (yyval.intVal) = STATIC;}
#line 2052 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 119 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstorage-class-specifier ->  KW_extern \n"); (yyval.intVal) = EXTERN;}
#line 2058 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstorage-class-specifier ->  KW_typedef \n");}
#line 2064 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 123 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  KW_void \n");}
#line 2070 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 124 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  KW_char \n");(yyval.intVal) = CHAR;}
#line 2076 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 125 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  KW_short \n"); (yyval.intVal) = SHORT;}
#line 2082 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 126 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  KW_int \n"); (yyval.intVal) = INT;}
#line 2088 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 127 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  KW_long \n"); (yyval.intVal) = LONG;}
#line 2094 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 128 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  KW_float \n"); (yyval.intVal) = FLOAT;}
#line 2100 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 129 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  KW_double \n"); (yyval.intVal) = DOUBLE;}
#line 2106 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 130 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  KW_signed \n"); (yyval.intVal) = SIGNED;}
#line 2112 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 131 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  KW_unsigned \n"); (yyval.intVal) = UNSIGNED;}
#line 2118 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 132 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  struct-or-union-specifier \n");}
#line 2124 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 133 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-specifier ->  enum-specifier \n");}
#line 2130 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 137 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-qualifier ->  KW_const \n");}
#line 2136 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 138 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-qualifier ->  KW_volatile \n");}
#line 2142 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 141 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-or-union-specifier ->  struct-or-union IDENTIFIER PUNC_OPBRACE struct-declaration-list PUNC_CLOSEBRACE \n");}
#line 2148 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 142 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-or-union-specifier ->  struct-or-union PUNC_OPBRACE struct-declaration-list PUNC_CLOSEBRACE \n");}
#line 2154 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 143 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-or-union-specifier ->  struct-or-union IDENTIFIER \n");}
#line 2160 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 146 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-or-union ->  KW_struct \n");}
#line 2166 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 147 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-or-union ->  KW_union \n");}
#line 2172 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 150 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-declaration-list ->  struct-declaration \n");}
#line 2178 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 151 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-declaration-list ->  struct-declaration-list struct-declaration \n");}
#line 2184 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 154 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinit-declarator-list ->  init-declarator \n");}
#line 2190 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 155 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinit-declarator-list ->  init-declarator-list OP_COMMA init-declarator \n");}
#line 2196 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 158 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinit-declarator ->  declarator \n");}
#line 2202 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 159 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinit-declarator ->  declarator OP_ASSIGN initializer \n");}
#line 2208 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 162 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-declaration ->  specifier-qualifier-list struct-declarator-list PUNC_SEMICOLON \n");}
#line 2214 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 165 "be10092011.y" /* yacc.c:1646  */
    {printf("\tspecifier-qualifier-list ->  type-specifier specifier-qualifier-list \n");}
#line 2220 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 166 "be10092011.y" /* yacc.c:1646  */
    {printf("\tspecifier-qualifier-list ->  type-specifier \n");}
#line 2226 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 167 "be10092011.y" /* yacc.c:1646  */
    {printf("\tspecifier-qualifier-list ->  type-qualifier specifier-qualifier-list \n");}
#line 2232 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 168 "be10092011.y" /* yacc.c:1646  */
    {printf("\tspecifier-qualifier-list ->  type-qualifier \n");}
#line 2238 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 171 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-declarator-list ->  struct-declarator \n");}
#line 2244 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 172 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-declarator-list ->  struct-declarator-list OP_COMMA struct-declarator \n");}
#line 2250 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 175 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-declarator ->  declarator \n");}
#line 2256 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 176 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-declarator ->  declarator PUNC_COLON constant-expression \n");}
#line 2262 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 177 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstruct-declarator ->  PUNC_COLON constant-expression \n");}
#line 2268 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 180 "be10092011.y" /* yacc.c:1646  */
    {printf("\tenum-specifier ->  KW_enum IDENTIFIER PUNC_OPBRACE enumerator-list PUNC_CLOSEBRACE \n");}
#line 2274 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 181 "be10092011.y" /* yacc.c:1646  */
    {printf("\tenum-specifier ->  KW_enum PUNC_OPBRACE enumerator-list PUNC_CLOSEBRACE \n");}
#line 2280 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 182 "be10092011.y" /* yacc.c:1646  */
    {printf("\tenum-specifier ->  KW_enum IDENTIFIER \n");}
#line 2286 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 185 "be10092011.y" /* yacc.c:1646  */
    {printf("\tenumerator-list ->  enumerator \n");}
#line 2292 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 186 "be10092011.y" /* yacc.c:1646  */
    {printf("\tenumerator-list ->  enumerator-list OP_COMMA enumerator \n");}
#line 2298 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 189 "be10092011.y" /* yacc.c:1646  */
    {printf("\tenumerator ->  IDENTIFIER \n");}
#line 2304 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 190 "be10092011.y" /* yacc.c:1646  */
    {printf("\tenumerator ->  IDENTIFIER OP_ASSIGN constant-expression \n");}
#line 2310 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 193 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdeclarator ->  pointer direct-declarator \n");}
#line 2316 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 194 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdeclarator ->  direct-declarator \n");}
#line 2322 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 197 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-declarator ->  IDENTIFIER \n");}
#line 2328 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 198 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-declarator ->  PUNC_OPBKT declarator PUNC_CLOSEBKT \n");}
#line 2334 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 199 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-declarator ->  direct-declarator PUNC_OPSQRBKT constant-expression PUNC_CLOSESQRBKT \n");}
#line 2340 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 200 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-declarator ->  direct-declarator PUNC_OPSQRBKT PUNC_CLOSESQRBKT \n");}
#line 2346 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 201 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-declarator ->  direct-declarator PUNC_OPBKT parameter-type-list PUNC_CLOSEBKT \n");}
#line 2352 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 202 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-declarator ->  direct-declarator PUNC_OPBKT identifier-list PUNC_CLOSEBKT \n");}
#line 2358 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 203 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-declarator ->  direct-declarator PUNC_OPBKT PUNC_CLOSEBKT \n");}
#line 2364 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 206 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpointer ->  OP_STAR type-qualifier-list \n");}
#line 2370 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 207 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpointer ->  OP_STAR \n");}
#line 2376 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 208 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpointer ->  OP_STAR type-qualifier-list pointer \n");}
#line 2382 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 209 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpointer ->  OP_STAR pointer \n");}
#line 2388 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 212 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-qualifier-list ->  type-qualifier \n");}
#line 2394 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 213 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-qualifier-list ->  type-qualifier-list type-qualifier \n");}
#line 2400 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 216 "be10092011.y" /* yacc.c:1646  */
    {printf("\tparameter-type-list ->  parameter-list \n");}
#line 2406 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 217 "be10092011.y" /* yacc.c:1646  */
    {printf("\tparameter-type-list ->  parameter-list OP_COMMA OP_ELLIPSIS \n");}
#line 2412 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 220 "be10092011.y" /* yacc.c:1646  */
    {printf("\tparameter-list ->  parameter-declaration \n");}
#line 2418 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 221 "be10092011.y" /* yacc.c:1646  */
    {printf("\tparameter-list ->  parameter-list OP_COMMA parameter-declaration \n");}
#line 2424 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 224 "be10092011.y" /* yacc.c:1646  */
    {printf("\tparameter-declaration ->  declaration-specifiers declarator \n");}
#line 2430 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 225 "be10092011.y" /* yacc.c:1646  */
    {printf("\tparameter-declaration ->  declaration-specifiers abstract-declarator \n");}
#line 2436 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 226 "be10092011.y" /* yacc.c:1646  */
    {printf("\tparameter-declaration ->  declaration-specifiers \n");}
#line 2442 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 229 "be10092011.y" /* yacc.c:1646  */
    {printf("\tidentifier-list ->  IDENTIFIER \n");}
#line 2448 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 230 "be10092011.y" /* yacc.c:1646  */
    {printf("\tidentifier-list ->  identifier-list OP_COMMA IDENTIFIER \n");}
#line 2454 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 233 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinitializer ->  assignment-expression \n");}
#line 2460 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 234 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinitializer ->  PUNC_OPBRACE initializer-list PUNC_CLOSEBRACE \n");}
#line 2466 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 235 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinitializer ->  PUNC_OPBRACE initializer-list OP_COMMA PUNC_CLOSEBRACE \n");}
#line 2472 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 238 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinitializer-list ->  initializer \n");}
#line 2478 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 239 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinitializer-list ->  initializer-list OP_COMMA initializer \n");}
#line 2484 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 242 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-name ->  specifier-qualifier-list abstract-declarator \n");}
#line 2490 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 243 "be10092011.y" /* yacc.c:1646  */
    {printf("\ttype-name ->  specifier-qualifier-list \n");}
#line 2496 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 246 "be10092011.y" /* yacc.c:1646  */
    {printf("\tabstract-declarator ->  pointer \n");}
#line 2502 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 247 "be10092011.y" /* yacc.c:1646  */
    {printf("\tabstract-declarator ->  pointer direct-abstract-declarator \n");}
#line 2508 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 248 "be10092011.y" /* yacc.c:1646  */
    {printf("\tabstract-declarator ->  direct-abstract-declarator \n");}
#line 2514 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 251 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-abstract-declarator ->  PUNC_OPBKT abstract-declarator PUNC_CLOSEBKT \n");}
#line 2520 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 252 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-abstract-declarator ->  direct-abstract-declarator PUNC_OPSQRBKT constant-expression PUNC_CLOSESQRBKT \n");}
#line 2526 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 253 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-abstract-declarator ->  direct-abstract-declarator PUNC_OPSQRBKT PUNC_CLOSESQRBKT \n");}
#line 2532 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 254 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-abstract-declarator ->  PUNC_OPSQRBKT constant-expression PUNC_CLOSESQRBKT \n");}
#line 2538 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 255 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-abstract-declarator ->  PUNC_OPSQRBKT PUNC_CLOSESQRBKT \n");}
#line 2544 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 256 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-abstract-declarator ->  direct-abstract-declarator PUNC_OPBKT parameter-type-list PUNC_CLOSEBKT \n");}
#line 2550 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 257 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-abstract-declarator ->  direct-abstract-declarator PUNC_OPBKT PUNC_CLOSEBKT \n");}
#line 2556 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 258 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-abstract-declarator ->  PUNC_OPBKT parameter-type-list PUNC_CLOSEBKT \n");}
#line 2562 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 259 "be10092011.y" /* yacc.c:1646  */
    {printf("\tdirect-abstract-declarator ->  PUNC_OPBKT PUNC_CLOSEBKT \n");}
#line 2568 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 263 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstatement ->  labeled-statement \n");}
#line 2574 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 264 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstatement ->  expression-statement \n");}
#line 2580 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 265 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstatement ->  compound-statement \n");}
#line 2586 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 266 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstatement ->  selection-statement \n");}
#line 2592 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 267 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstatement ->  iteration-statement \n");}
#line 2598 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 268 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstatement ->  jump-statement \n");}
#line 2604 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 271 "be10092011.y" /* yacc.c:1646  */
    {printf("\tlabeled-statement ->  IDENTIFIER PUNC_COLON statement \n");}
#line 2610 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 272 "be10092011.y" /* yacc.c:1646  */
    {printf("\tlabeled-statement ->  KW_case constant-expression PUNC_COLON statement \n");}
#line 2616 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 273 "be10092011.y" /* yacc.c:1646  */
    {printf("\tlabeled-statement ->  KW_default PUNC_COLON statement \n");}
#line 2622 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 276 "be10092011.y" /* yacc.c:1646  */
    {printf("\texpression-statement ->  expression PUNC_SEMICOLON \n");}
#line 2628 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 277 "be10092011.y" /* yacc.c:1646  */
    {printf("\texpression-statement ->  PUNC_SEMICOLON \n");}
#line 2634 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 280 "be10092011.y" /* yacc.c:1646  */
    {printf("\tcompound-statement ->  PUNC_OPBRACE declaration-list statement-list PUNC_CLOSEBRACE \n");}
#line 2640 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 281 "be10092011.y" /* yacc.c:1646  */
    {printf("\tcompound-statement ->  PUNC_OPBRACE statement-list PUNC_CLOSEBRACE \n");}
#line 2646 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 282 "be10092011.y" /* yacc.c:1646  */
    {printf("\tcompound-statement ->  PUNC_OPBRACE declaration-list PUNC_CLOSEBRACE \n");}
#line 2652 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 283 "be10092011.y" /* yacc.c:1646  */
    {printf("\tcompound-statement ->  PUNC_OPBRACE PUNC_CLOSEBRACE \n");}
#line 2658 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 286 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstatement-list ->  statement \n");}
#line 2664 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 287 "be10092011.y" /* yacc.c:1646  */
    {printf("\tstatement-list ->  statement-list statement \n");}
#line 2670 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 290 "be10092011.y" /* yacc.c:1646  */
    {printf("\tselection-statement ->  KW_if PUNC_OPBKT expression PUNC_CLOSEBKT statement \n");}
#line 2676 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 291 "be10092011.y" /* yacc.c:1646  */
    {printf("\tselection-statement ->  KW_if PUNC_OPBKT expression PUNC_CLOSEBKT statement KW_else statement \n");}
#line 2682 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 292 "be10092011.y" /* yacc.c:1646  */
    {printf("\tselection-statement ->  KW_switch PUNC_OPBKT expression PUNC_CLOSEBKT statement \n");}
#line 2688 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 295 "be10092011.y" /* yacc.c:1646  */
    {printf("\titeration-statement ->  KW_while PUNC_OPBKT expression PUNC_CLOSEBKT statement \n");}
#line 2694 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 296 "be10092011.y" /* yacc.c:1646  */
    {printf("\titeration-statement ->  KW_do statement KW_while PUNC_OPBKT expression PUNC_CLOSEBKT PUNC_SEMICOLON \n");}
#line 2700 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 297 "be10092011.y" /* yacc.c:1646  */
    {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
#line 2706 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 298 "be10092011.y" /* yacc.c:1646  */
    {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
#line 2712 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 299 "be10092011.y" /* yacc.c:1646  */
    {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
#line 2718 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 300 "be10092011.y" /* yacc.c:1646  */
    {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
#line 2724 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 301 "be10092011.y" /* yacc.c:1646  */
    {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
#line 2730 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 302 "be10092011.y" /* yacc.c:1646  */
    {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
#line 2736 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 303 "be10092011.y" /* yacc.c:1646  */
    {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON PUNC_SEMICOLON expression PUNC_CLOSEBKT statement \n");}
#line 2742 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 304 "be10092011.y" /* yacc.c:1646  */
    {printf("\titeration-statement ->  KW_for PUNC_OPBKT PUNC_SEMICOLON PUNC_SEMICOLON PUNC_SEMICOLON PUNC_CLOSEBKT statement \n");}
#line 2748 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 307 "be10092011.y" /* yacc.c:1646  */
    {printf("\tjump-statement ->  KW_goto IDENTIFIER PUNC_SEMICOLON \n");}
#line 2754 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 308 "be10092011.y" /* yacc.c:1646  */
    {printf("\tjump-statement ->  KW_continue PUNC_SEMICOLON \n");}
#line 2760 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 309 "be10092011.y" /* yacc.c:1646  */
    {printf("\tjump-statement ->  KW_break PUNC_SEMICOLON \n");}
#line 2766 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 310 "be10092011.y" /* yacc.c:1646  */
    {printf("\tjump-statement ->  KW_return expression PUNC_SEMICOLON \n");}
#line 2772 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 311 "be10092011.y" /* yacc.c:1646  */
    {printf("\tjump-statement ->  KW_return PUNC_SEMICOLON \n");}
#line 2778 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 314 "be10092011.y" /* yacc.c:1646  */
    {printf("\texpression ->  assignment-expression \n");}
#line 2784 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 315 "be10092011.y" /* yacc.c:1646  */
    {printf("\texpression ->  expression OP_COMMA assignment-expression \n");}
#line 2790 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 318 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-expression ->  conditional-expression \n");}
#line 2796 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 319 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-expression ->  unary-expression assignment-operator assignment-expression \n");}
#line 2802 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 322 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_ASSIGN \n");}
#line 2808 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 323 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_MULEQ \n");}
#line 2814 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 324 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_DIVEQ \n");}
#line 2820 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 325 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_MODEQ \n");}
#line 2826 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 326 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_PLUSEQ \n");}
#line 2832 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 327 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_MINUSEQ \n");}
#line 2838 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 328 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_LSHIFTEQ \n");}
#line 2844 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 329 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_RSHIFTEQ \n");}
#line 2850 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 330 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_ANDEQ \n");}
#line 2856 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 331 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_XOREQ \n");}
#line 2862 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 332 "be10092011.y" /* yacc.c:1646  */
    {printf("\tassignment-operator ->  OP_OREQ \n");}
#line 2868 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 335 "be10092011.y" /* yacc.c:1646  */
    {printf("\tconditional-expression ->  logical-OR-expression \n");}
#line 2874 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 336 "be10092011.y" /* yacc.c:1646  */
    {printf("\tconditional-expression ->  logical-OR-expression OP_QUES expression PUNC_COLON conditional-expression \n");}
#line 2880 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 339 "be10092011.y" /* yacc.c:1646  */
    {printf("\tconstant-expression ->  conditional-expression \n");}
#line 2886 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 342 "be10092011.y" /* yacc.c:1646  */
    {printf("\tlogical-OR-expression ->  logical-AND-expression \n");}
#line 2892 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 343 "be10092011.y" /* yacc.c:1646  */
    {printf("\tlogical-OR-expression ->  logical-OR-expression OP_LOGOR logical-AND-expression \n");}
#line 2898 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 346 "be10092011.y" /* yacc.c:1646  */
    {printf("\tlogical-AND-expression ->  inclusive-OR-expression \n");}
#line 2904 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 347 "be10092011.y" /* yacc.c:1646  */
    {printf("\tlogical-AND-expression ->  logical-AND-expression OP_LOGAND inclusive-OR-expression \n");}
#line 2910 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 350 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinclusive-OR-expression ->  exclusive-OR-expression \n");}
#line 2916 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 351 "be10092011.y" /* yacc.c:1646  */
    {printf("\tinclusive-OR-expression ->  inclusive-OR-expression OP_BITOR exclusive-OR-expression \n");}
#line 2922 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 353 "be10092011.y" /* yacc.c:1646  */
    {printf("\texclusive-OR-expression ->  AND-expression \n");}
#line 2928 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 354 "be10092011.y" /* yacc.c:1646  */
    {printf("\texclusive-OR-expression ->  exclusive-OR-expression OP_BITXOR AND-expression \n");}
#line 2934 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 357 "be10092011.y" /* yacc.c:1646  */
    {printf("\tAND-expression ->  equality-expression \n");}
#line 2940 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 358 "be10092011.y" /* yacc.c:1646  */
    {printf("\tAND-expression ->  AND-expression OP_AMP equality-expression \n");}
#line 2946 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 361 "be10092011.y" /* yacc.c:1646  */
    {printf("\tequality-expression ->  relational-expression \n");}
#line 2952 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 362 "be10092011.y" /* yacc.c:1646  */
    {printf("\tequality-expression ->  equality-expression OP_EQ relational-expression \n");}
#line 2958 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 363 "be10092011.y" /* yacc.c:1646  */
    {printf("\tequality-expression ->  equality-expression OP_NEQ relational-expression \n");}
#line 2964 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 366 "be10092011.y" /* yacc.c:1646  */
    {printf("\trelational-expression ->  shift-expression \n");}
#line 2970 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 367 "be10092011.y" /* yacc.c:1646  */
    {printf("\trelational-expression ->  relational-expression OP_LT shift-expression \n");}
#line 2976 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 368 "be10092011.y" /* yacc.c:1646  */
    {printf("\trelational-expression ->  relational-expression OP_GT shift-expression \n");}
#line 2982 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 369 "be10092011.y" /* yacc.c:1646  */
    {printf("\trelational-expression ->  relational-expression OP_LTE shift-expression \n");}
#line 2988 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 370 "be10092011.y" /* yacc.c:1646  */
    {printf("\trelational-expression ->  relational-expression OP_GTE shift-expression \n");}
#line 2994 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 373 "be10092011.y" /* yacc.c:1646  */
    {printf("\tshift-expression ->  additive-expression \n");}
#line 3000 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 374 "be10092011.y" /* yacc.c:1646  */
    {printf("\tshift-expression ->  shift-expression OP_LSHIFT additive-expression \n");}
#line 3006 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 375 "be10092011.y" /* yacc.c:1646  */
    {printf("\tshift-expression ->  shift-expression OP_RSHIFT additive-expression \n");}
#line 3012 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 378 "be10092011.y" /* yacc.c:1646  */
    {printf("\tadditive-expression ->  multiplicative-expression \n");}
#line 3018 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 379 "be10092011.y" /* yacc.c:1646  */
    {printf("\tadditive-expression ->  additive-expression OP_PLUS multiplicative-expression \n");}
#line 3024 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 380 "be10092011.y" /* yacc.c:1646  */
    {printf("\tadditive-expression ->  additive-expression OP_MINUS multiplicative-expression \n");}
#line 3030 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 383 "be10092011.y" /* yacc.c:1646  */
    {printf("\tmultiplicative-expression ->  cast-expression \n");}
#line 3036 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 384 "be10092011.y" /* yacc.c:1646  */
    {printf("\tmultiplicative-expression ->  multiplicative-expression OP_STAR cast-expression \n");}
#line 3042 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 385 "be10092011.y" /* yacc.c:1646  */
    {printf("\tmultiplicative-expression ->  multiplicative-expression OP_DIV cast-expression \n");}
#line 3048 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 386 "be10092011.y" /* yacc.c:1646  */
    {printf("\tmultiplicative-expression ->  multiplicative-expression OP_MOD cast-expression \n");}
#line 3054 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 389 "be10092011.y" /* yacc.c:1646  */
    {printf("\tcast-expression ->  unary-expression \n");}
#line 3060 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 390 "be10092011.y" /* yacc.c:1646  */
    {printf("\tcast-expression ->  PUNC_OPBKT type-name PUNC_CLOSEBKT cast-expression \n");}
#line 3066 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 393 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-expression ->  postfix-expression \n");}
#line 3072 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 394 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-expression ->  OP_INCR unary-expression \n");}
#line 3078 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 395 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-expression ->  OP_DECR unary-expression \n");}
#line 3084 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 396 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-expression ->  unary-operator cast-expression \n");}
#line 3090 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 397 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-expression ->  KW_sizeof unary-expression \n");}
#line 3096 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 398 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-expression ->  KW_sizeof PUNC_OPBKT type-name PUNC_CLOSEBKT \n");}
#line 3102 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 401 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-operator ->  OP_AMP \n");}
#line 3108 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 402 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-operator ->  OP_STAR \n");}
#line 3114 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 403 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-operator ->  OP_PLUS \n");}
#line 3120 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 404 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-operator ->  OP_MINUS \n");}
#line 3126 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 405 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-operator ->  OP_COMP \n");}
#line 3132 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 406 "be10092011.y" /* yacc.c:1646  */
    {printf("\tunary-operator ->  OP_NEGATE \n");}
#line 3138 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 409 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpostfix-expression ->  primary-expression \n");}
#line 3144 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 410 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpostfix-expression ->  postfix-expression PUNC_OPSQRBKT expression PUNC_CLOSESQRBKT \n");}
#line 3150 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 411 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpostfix-expression ->  postfix-expression PUNC_OPBKT argument-expression-list PUNC_CLOSEBKT \n");}
#line 3156 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 412 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpostfix-expression ->  postfix-expression PUNC_OPBKT PUNC_CLOSEBKT \n");}
#line 3162 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 413 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpostfix-expression ->  postfix-expression OP_DOT IDENTIFIER \n");}
#line 3168 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 414 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpostfix-expression ->  postfix-expression OP_DEREF IDENTIFIER \n");}
#line 3174 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 415 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpostfix-expression ->  postfix-expression OP_INCR \n");}
#line 3180 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 416 "be10092011.y" /* yacc.c:1646  */
    {printf("\tpostfix-expression ->  postfix-expression OP_DECR \n");}
#line 3186 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 419 "be10092011.y" /* yacc.c:1646  */
    {printf("\tprimary-expression ->  IDENTIFIER \n");}
#line 3192 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 420 "be10092011.y" /* yacc.c:1646  */
    {printf("\tprimary-expression ->  constant \n");}
#line 3198 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 421 "be10092011.y" /* yacc.c:1646  */
    {printf("\tprimary-expression ->  STRING_CONSTANT \n");}
#line 3204 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 422 "be10092011.y" /* yacc.c:1646  */
    {printf("\tprimary-expression ->  PUNC_OPBKT expression PUNC_CLOSEBKT \n");}
#line 3210 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 425 "be10092011.y" /* yacc.c:1646  */
    {printf("\targument-expression-list ->  assignment-expression \n");}
#line 3216 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 426 "be10092011.y" /* yacc.c:1646  */
    {printf("\targument-expression-list ->  argument-expression-list OP_COMMA assignment-expression \n");}
#line 3222 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 430 "be10092011.y" /* yacc.c:1646  */
    {printf("\tconstant ->  NUMBER \n");}
#line 3228 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 431 "be10092011.y" /* yacc.c:1646  */
    {printf("\tconstant ->  CHAR_CONSTANT \n");}
#line 3234 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 432 "be10092011.y" /* yacc.c:1646  */
    {printf("\tconstant ->  REAL_NUMBER \n");}
#line 3240 "be10092011.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 433 "be10092011.y" /* yacc.c:1646  */
    {printf("\tconstant ->  EXP_NUMBER \n");}
#line 3246 "be10092011.tab.c" /* yacc.c:1646  */
    break;


#line 3250 "be10092011.tab.c" /* yacc.c:1646  */
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
#line 437 "be10092011.y" /* yacc.c:1906  */

#include "lex.yy.c"

int yyerror()
{
	printf("Error at line %d\n", line_no);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Enter filename to be Compiled\n");
		return -1;
	}
	yyin = fopen(argv[1], "r");
	yyparse();
	return 0;
}
