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
#line 1 "grammar.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string>
	#include <string.h>
	#include <cstdlib>
	#include <iostream>
	#include <map>
	#include <vector>
	#include "MemoryItem.h"
	#include "AsmInstruction.h"
	#include "Adder.h"
	#include "Substractor.h"
	#include "Multiplier.h"
	#include "Divider.h"
	#include <fstream>
	#include <bitset>
	#include <regex>
	#include <algorithm>
	extern "C" int yylex();
	extern "C" int yyparse();
	void yyerror (char const *);
	extern int yylineno;
	extern char* yytext;
	long long memory_pointer = 0;
	int valueTakenFromIdentifier = 0;
	int storeArrayValueInTemporaryVariable(std::string name, std::string index, int place);
	int storeAccumulatorInArray(std::string name, std::string index);
	int findVariableInMemory(std::string name);
	int loadTableElementToAccumulator(std::string name, std::string index);
	int determineAndExecuteExpressionOperation(std::string arg1, std::string arg2, std::string oper,int gte);
	int copyValueFromAnotherIdentifier(std::string from, std::string to);
	int assignValueToIdentifier(std::string name, long long value);
	int constructValueToRegister(long long value);
	void undefinedVariableError(std::string varName);
	void typeMismatchError(std::string varName);
	int storeIdentifier(std::string name);
	void printAsmInstructions();
	int readToIdentifier(std::string name);
	int initializeIdentifier(std::string name, int tab, long long size);
	void printAsmInstructions();
	int writeNumber(long long number);
	int writeIdentifier(std::string name);
	void immutableError(std::string varName);
	void uninitializedVariableError(std::string varName);
	int loadFromMemory(std::string name);
	std::map<std::string, MemoryItem*> memoryMap;
	std::vector<AsmInstruction*> asmInstrunctions;
	std::stack<int> jzeroLinePointerStack;
	std::stack<int> whileConditionPointerStack;
	std::stack<int> whileJumpPointerStack;
	std::stack<int> forCounterDeepStack;
	std::vector<string> initializedVars;
	std::vector<string> immutableVars;
	struct Value {
    bool isArray;
    bool isNumber;
    bool isVariable;
		bool isResult;
    string num;
    string name;
		string index;
	};
	#define OPERATION_STORING_PLACE 1
	#define ARRAY_BUFFER_STORING_PLACE_1 2
	#define ARRAY_BUFFER_STORING_PLACE_2 3
	#define ARRAY_BUFFER_STORING_PLACE_3 4
	std::string ARRAY_TEMP_VAR_1 = "A1";
	std::string ARRAY_TEMP_VAR_2 = "A2";
	std::string ARRAY_TEMP_VAR_3 = "A3";
	int for_var_counter = 0;
	#define TEMP_ACC_PLACE 8

#line 139 "grammar.tab.c" /* yacc.c:339  */

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
   by #include "grammar.tab.h".  */
#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
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
    num = 258,
    PID = 259,
    VAR = 260,
    T_BEGIN = 261,
    END = 262,
    IF = 263,
    ELSE = 264,
    ENDIF = 265,
    THEN = 266,
    WHILE = 267,
    DO = 268,
    ENDWHILE = 269,
    FOR = 270,
    FROM = 271,
    TO = 272,
    ENDFOR = 273,
    DOWNTO = 274,
    READ = 275,
    WRITE = 276,
    SKIP = 277,
    T_ADD = 278,
    T_MIN = 279,
    T_MUL = 280,
    T_DIV = 281,
    T_MOD = 282,
    T_EQ = 283,
    T_NEQ = 284,
    T_RGT = 285,
    T_RGE = 286,
    T_LGE = 287,
    T_LGT = 288,
    T_ASG = 289,
    T_EL = 290,
    T_LBR = 291,
    T_RBR = 292,
    ERR = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 73 "grammar.y" /* yacc.c:355  */

	char* string;
	int integer;
	struct Value* value;
	//Identifier* identifier;
	//Command* command;

#line 226 "grammar.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "grammar.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  91

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,     2,     2,
       2,     2,    28,    24,     2,    26,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    45,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    25,
      27,    29,    31,    33,    34,    35,    36,    37,    38,    39,
      40,    42,    44,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   131,   135,   139,   141,   142,   144,   218,
     222,   218,   225,   227,   225,   240,   240,   323,   323,   418,
     432,   452,   452,   466,   473,   474,   511,   548,   585,   622,
     661,   711,   761,   792,   823,   854,   886,   897,   899,   908,
     918
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "num", "\"identifier\"", "VAR",
  "T_BEGIN", "END", "IF", "ELSE", "ENDIF", "THEN", "WHILE", "DO",
  "ENDWHILE", "FOR", "FROM", "TO", "ENDFOR", "DOWNTO", "READ", "WRITE",
  "SKIP", "T_ADD", "'+'", "T_MIN", "'-'", "T_MUL", "'*'", "T_DIV", "'/'",
  "T_MOD", "'%'", "\"=\"", "\"<>\"", "\"<\"", "\"<=\"", "\">=\"", "\">\"",
  "\":=\"", "T_EL", "';'", "T_LBR", "'['", "T_RBR", "']'", "ERR",
  "$accept", "program", "vdeclarations", "commands", "command", "$@1",
  "$@2", "$@3", "$@4", "$@5", "$@6", "innerIf", "$@7", "expression",
  "condition", "value", "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,   279,    45,   280,    42,   281,
      47,   282,    37,   283,   284,   285,   286,   287,   288,   289,
     290,    59,   291,    91,   292,    93,   293
};
# endif

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -47,     4,    -1,   -47,   -32,   116,    46,    11,    20,
     -47,    50,    51,    20,     5,   -47,    30,    15,    41,   -47,
     -47,    -4,   -47,    20,    54,    35,    42,   -47,   -47,    20,
     -47,    39,    40,    60,    20,    20,    20,    20,    20,    20,
     -47,    20,   -47,   -47,    55,   115,   -47,   -47,   116,   -47,
     -47,   -47,   -47,   -47,   -47,    78,    -3,   -47,    20,    20,
      20,    20,    20,   116,   116,    20,    20,   -47,   -47,   -47,
     -47,   -47,    38,     7,    83,    84,   -47,   -47,   -47,   -47,
     -47,   -47,   116,   116,   116,    31,    86,   101,   -47,   -47,
     -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     1,     3,     0,     0,    38,     0,
      12,     0,     0,     0,     0,     7,     0,     0,     0,    36,
       9,     0,    37,     0,     0,     0,     0,     2,     6,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,    19,    20,     0,    24,    40,    39,     0,    30,
      31,    32,    34,    35,    33,     0,     0,     8,     0,     0,
       0,     0,     0,    10,     0,     0,     0,    25,    26,    27,
      28,    29,     0,     0,     0,     0,    21,    23,    11,    14,
      15,    17,     0,     0,     0,     0,     0,     0,    22,    16,
      18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   -47,   -46,   -13,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,    76,    27,    -6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    14,    15,    33,    72,    23,    55,    83,
      84,    78,    82,    44,    20,    21,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    28,    63,     5,     4,     6,    25,     1,    16,     8,
       7,     8,    27,     9,    65,     9,    66,    10,    73,    10,
      11,    79,    11,    19,     8,    12,    13,    12,    13,    34,
      35,    36,    37,    38,    39,     8,    85,    86,    87,     9,
      26,    88,    16,    10,    31,    32,    11,    76,    77,    17,
      28,    12,    13,    18,    24,     8,    45,    16,    16,    30,
      28,    49,    50,    51,    52,    53,    54,    16,    56,    29,
      41,    48,    28,    28,    28,    42,    16,    16,    16,    16,
      16,    16,    43,    46,    47,    67,    68,    69,    70,    71,
       8,    64,    74,    75,     9,    57,    80,    81,    10,    40,
       0,    11,     0,     0,    89,     8,    12,    13,     0,     9,
       0,     0,     0,    10,     0,     0,    11,     0,     0,    90,
       8,    12,    13,     0,     9,     0,     0,     0,    10,     0,
       0,    11,     0,     0,     0,     0,    12,    13,    58,     0,
      59,     0,    60,     0,    61,     0,    62
};

static const yytype_int8 yycheck[] =
{
       6,    14,    48,     4,     0,     6,    12,     5,    14,     4,
      42,     4,     7,     8,    17,     8,    19,    12,    64,    12,
      15,    14,    15,     3,     4,    20,    21,    20,    21,    33,
      34,    35,    36,    37,    38,     4,    82,    83,    84,     8,
      13,    10,    48,    12,     3,     4,    15,     9,    10,     3,
      63,    20,    21,    42,     4,     4,    29,    63,    64,    44,
      73,    34,    35,    36,    37,    38,    39,    73,    41,    39,
      16,    11,    85,    86,    87,    40,    82,    83,    84,    85,
      86,    87,    40,    44,    44,    58,    59,    60,    61,    62,
       4,    13,    65,    66,     8,    40,    13,    13,    12,    23,
      -1,    15,    -1,    -1,    18,     4,    20,    21,    -1,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    18,
       4,    20,    21,    -1,     8,    -1,    -1,    -1,    12,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    23,    -1,
      25,    -1,    27,    -1,    29,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    48,    49,     0,     4,     6,    42,     4,     8,
      12,    15,    20,    21,    50,    51,    63,     3,    42,     3,
      61,    62,    63,    54,     4,    63,    62,     7,    51,    39,
      44,     3,     4,    52,    33,    34,    35,    36,    37,    38,
      61,    16,    40,    40,    60,    62,    44,    44,    11,    62,
      62,    62,    62,    62,    62,    55,    62,    40,    23,    25,
      27,    29,    31,    50,    13,    17,    19,    62,    62,    62,
      62,    62,    53,    50,    62,    62,     9,    10,    58,    14,
      13,    13,    59,    56,    57,    50,    50,    50,    10,    18,
      18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    51,    52,
      53,    51,    54,    55,    51,    56,    51,    57,    51,    51,
      51,    59,    58,    58,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    63,
      63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     5,     0,     2,     1,     4,     0,
       0,     7,     0,     0,     7,     0,    10,     0,    10,     3,
       3,     0,     4,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     4,
       4
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
#line 126 "grammar.y" /* yacc.c:1646  */
    {
								asmInstrunctions.push_back(new AsmInstruction("HALT"));
								printAsmInstructions();
								}
#line 1395 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 131 "grammar.y" /* yacc.c:1646  */
    {
								if(initializeIdentifier((yyvsp[0].string),0,1))
										return 1;
								}
#line 1404 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 135 "grammar.y" /* yacc.c:1646  */
    {
								if(initializeIdentifier((yyvsp[-3].string),1,atoll((yyvsp[-1].string))))
									return 1;
							}
#line 1413 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 144 "grammar.y" /* yacc.c:1646  */
    {
									//printf("debug exp: %s \n", $3);
									if((yyvsp[-3].value)->isVariable == true)
									{
										if((yyvsp[-1].value)->isNumber)
										{
											if(assignValueToIdentifier((yyvsp[-3].value)->name, stoll((yyvsp[-1].value)->num)))
												return 1;
										}
										else if((yyvsp[-1].value)->isResult)
										{
											//printf("debug identifier %s \n", $1);
											int place = findVariableInMemory((yyvsp[-3].value)->name);
											if(place == -1)
												return 1;
											asmInstrunctions.push_back(new AsmInstruction("STORE", place));
										}
										else if((yyvsp[-1].value)->isArray)
										{
											if(loadTableElementToAccumulator((yyvsp[-1].value)->name, (yyvsp[-1].value)->index))
												return 1;
											int place = findVariableInMemory((yyvsp[-3].value)->name);
											if(place == -1)
												return 1;
											asmInstrunctions.push_back(new AsmInstruction("STORE", place));
										}
										else if((yyvsp[-1].value)->isVariable)
										{
											//printf("debug identifier %s \n", $1);
											if(copyValueFromAnotherIdentifier((yyvsp[-1].value)->name, (yyvsp[-3].value)->name))
												return 1;
										}
										if(find(immutableVars.begin(), immutableVars.end(), (yyvsp[-3].value)->name) != immutableVars.end())
										{
											immutableError((yyvsp[-3].value)->name);
											return 1;
										}
										initializedVars.push_back((yyvsp[-3].value)->name);
									}
									else
									{
										//puts("chuuiiichuj");
										if((yyvsp[-1].value)->isNumber)
										{
											//puts("chuuiiichuj1");
											constructValueToRegister(stoll((yyvsp[-1].value)->num));
											if(storeAccumulatorInArray((yyvsp[-3].value)->name, (yyvsp[-3].value)->index))
												return 1;
											//puts("chuuujjj2");
										}
										else if((yyvsp[-1].value)->isResult)
										{
											if(storeAccumulatorInArray((yyvsp[-3].value)->name, (yyvsp[-3].value)->index))
												return 1;
										}
										else if((yyvsp[-1].value)->isArray)
										{
											if(loadTableElementToAccumulator((yyvsp[-1].value)->name, (yyvsp[-1].value)->index))
												return 1;
											if(storeAccumulatorInArray((yyvsp[-3].value)->name, (yyvsp[-3].value)->index))
												return 1;
										}
										else if((yyvsp[-1].value)->isVariable)
										{
											int place = findVariableInMemory((yyvsp[-1].value)->name);
											if(place == -1)
												return 1;
											asmInstrunctions.push_back(new AsmInstruction("LOAD", place));
											if(storeAccumulatorInArray((yyvsp[-3].value)->name, (yyvsp[-3].value)->index))
												return 1;
										}
									}

								}
#line 1492 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 218 "grammar.y" /* yacc.c:1646  */
    {
								//printf("pushneem wlasnie: %d",asmInstrunctions.size());
								jzeroLinePointerStack.push(asmInstrunctions.size());
							  asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));
							}
#line 1502 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 222 "grammar.y" /* yacc.c:1646  */
    {

							}
#line 1510 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 225 "grammar.y" /* yacc.c:1646  */
    {
								whileConditionPointerStack.push(asmInstrunctions.size());
							}
#line 1518 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 227 "grammar.y" /* yacc.c:1646  */
    {
								whileJumpPointerStack.push(asmInstrunctions.size());
								asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));

							}
#line 1528 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 231 "grammar.y" /* yacc.c:1646  */
    {
								int whileConditionStart = whileConditionPointerStack.top();
								whileConditionPointerStack.pop();
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								asmInstrunctions.push_back(new AsmInstruction("JZERO", whileConditionStart));
								int whileJump = whileJumpPointerStack.top();
								whileJumpPointerStack.pop();
								asmInstrunctions[whileJump]->arg = asmInstrunctions.size();
							}
#line 1542 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 240 "grammar.y" /* yacc.c:1646  */
    {
								//zastoruj iterator
								immutableVars.push_back((yyvsp[-5].string));
								if(initializeIdentifier((yyvsp[-5].string),0,1))
									return 1;
								//wczytaj value1 do akumulatora
								if((yyvsp[-3].value)->isVariable)
								{
									int p = findVariableInMemory((yyvsp[-3].value)->name);
									if(p == -1)
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("LOAD", p));
								}
								else if((yyvsp[-3].value)->isArray)
								{
									if(loadTableElementToAccumulator((yyvsp[-3].value)->name, (yyvsp[-3].value)->index))
										return 1;
								}
								else if((yyvsp[-3].value)->isNumber)
								{
									constructValueToRegister(stoll((yyvsp[-3].value)->num));
								}
								int iterAddress = findVariableInMemory((yyvsp[-5].string));
								asmInstrunctions.push_back(new AsmInstruction("STORE", iterAddress));
								initializedVars.push_back((yyvsp[-5].string));
								//teraz mamy już value1 w zmiennej i, co więcej jest zainicjalizowana
								//zrobmy jeszcze value2 do zmiennej Cx, gdzie x to counter (zeby nie bylo kolizji)
								if(initializeIdentifier("C"+to_string(for_var_counter),0,1))
									return 1;
								if((yyvsp[-1].value)->isVariable)
								{
									int p = findVariableInMemory((yyvsp[-1].value)->name);
									if(p == -1)
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("LOAD", p));
								}
								else if((yyvsp[-1].value)->isArray)
								{
									if(loadTableElementToAccumulator((yyvsp[-1].value)->name, (yyvsp[-1].value)->index))
										return 1;
								}
								else if((yyvsp[-1].value)->isNumber)
								{
									//puts("chhhuuujjj");
									constructValueToRegister(stoll((yyvsp[-1].value)->num));
								}
								int p = findVariableInMemory("C"+to_string(for_var_counter));
								asmInstrunctions.push_back(new AsmInstruction("STORE", p));
								initializedVars.push_back("C"+to_string(for_var_counter));
								//mamy zastorowane Tx, teraz trzeba zrobić warunek

								whileConditionPointerStack.push(asmInstrunctions.size());
								//condition right greater equals: i <= val2
								if(determineAndExecuteExpressionOperation("C"+to_string(for_var_counter),(yyvsp[-5].string),"-",1))
									return 1;

								whileJumpPointerStack.push(asmInstrunctions.size());
								asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));
								for_var_counter++;
							}
#line 1607 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 300 "grammar.y" /* yacc.c:1646  */
    {
								int iterAddress = findVariableInMemory((yyvsp[-8].string));
								asmInstrunctions.push_back(new AsmInstruction("LOAD", iterAddress));
								asmInstrunctions.push_back(new AsmInstruction("INC"));
								asmInstrunctions.push_back(new AsmInstruction("STORE", iterAddress));
								int whileConditionStart = whileConditionPointerStack.top();
								whileConditionPointerStack.pop();
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								asmInstrunctions.push_back(new AsmInstruction("JZERO", whileConditionStart));
								int whileJump = whileJumpPointerStack.top();
								whileJumpPointerStack.pop();
								asmInstrunctions[whileJump]->arg = asmInstrunctions.size();
								//usunac ze zmiennych Tx oraz iterator
								vector<string>::iterator it1 = find(initializedVars.begin(), initializedVars.end(), (yyvsp[-8].string));
								initializedVars.erase(it1);
								it1 = find(immutableVars.begin(), immutableVars.end(), (yyvsp[-8].string));
								immutableVars.erase(it1);

								map<string, MemoryItem*>::iterator it2 = memoryMap.find((yyvsp[-8].string));
  							memoryMap.erase(it2);
							  memoryMap.erase ("C"+to_string(for_var_counter-1));
								for_var_counter--;
							}
#line 1635 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 323 "grammar.y" /* yacc.c:1646  */
    {
								//zastoruj iterator
								immutableVars.push_back((yyvsp[-5].string));
								if(initializeIdentifier((yyvsp[-5].string),0,1))
									return 1;
								//wczytaj value1 do akumulatora
								if((yyvsp[-3].value)->isVariable)
								{
									int p = findVariableInMemory((yyvsp[-3].value)->name);
									if(p == -1)
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("LOAD", p));
								}
								else if((yyvsp[-3].value)->isArray)
								{
									if(loadTableElementToAccumulator((yyvsp[-3].value)->name, (yyvsp[-3].value)->index))
										return 1;
								}
								else if((yyvsp[-3].value)->isNumber)
								{
									constructValueToRegister(stoll((yyvsp[-3].value)->num));
								}
								int iterAddress = findVariableInMemory((yyvsp[-5].string));
								asmInstrunctions.push_back(new AsmInstruction("STORE", iterAddress));
								initializedVars.push_back((yyvsp[-5].string));
								//teraz mamy już value1 w zmiennej i, co więcej jest zainicjalizowana
								//zrobmy jeszcze value2 do zmiennej Cx, gdzie x to counter (zeby nie bylo kolizji)
								if(initializeIdentifier("C"+to_string(for_var_counter),0,1))
									return 1;
								if((yyvsp[-1].value)->isVariable)
								{
									int p = findVariableInMemory((yyvsp[-1].value)->name);
									if(p == -1)
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("LOAD", p));
								}
								else if((yyvsp[-1].value)->isArray)
								{
									if(loadTableElementToAccumulator((yyvsp[-1].value)->name, (yyvsp[-1].value)->index))
										return 1;
								}
								else if((yyvsp[-1].value)->isNumber)
								{
									constructValueToRegister(stoll((yyvsp[-1].value)->num));
								}
								int p = findVariableInMemory("C"+to_string(for_var_counter));
								asmInstrunctions.push_back(new AsmInstruction("STORE", p));
								initializedVars.push_back("K"+to_string(for_var_counter));
								//mamy zastorowane Tx, teraz trzeba zrobić warunek

								//condition right greater equals: i + 1  > val2
								// k = a-b
								if(initializeIdentifier("K"+to_string(for_var_counter),0,1))
								{
									return 1;
								}
								asmInstrunctions.push_back(new AsmInstruction("LOAD", iterAddress));
								asmInstrunctions.push_back(new AsmInstruction("INC"));
								asmInstrunctions.push_back(new AsmInstruction("SUB", p));
								int p1 = findVariableInMemory("K"+to_string(for_var_counter));
								asmInstrunctions.push_back(new AsmInstruction("STORE", p1));
								whileConditionPointerStack.push(asmInstrunctions.size());
								if(determineAndExecuteExpressionOperation("K"+to_string(for_var_counter),to_string(0),"-",0))
									return 1;

								whileJumpPointerStack.push(asmInstrunctions.size());
								asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));
								for_var_counter++;
							}
#line 1709 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 391 "grammar.y" /* yacc.c:1646  */
    {
								int iterAddress = findVariableInMemory((yyvsp[-8].string));
								int p1 = findVariableInMemory("K"+to_string(for_var_counter-1));
								asmInstrunctions.push_back(new AsmInstruction("LOAD", iterAddress));
								asmInstrunctions.push_back(new AsmInstruction("DEC"));
								asmInstrunctions.push_back(new AsmInstruction("STORE", iterAddress));
								asmInstrunctions.push_back(new AsmInstruction("LOAD", p1));
								asmInstrunctions.push_back(new AsmInstruction("DEC"));
								asmInstrunctions.push_back(new AsmInstruction("STORE", p1));
								int whileConditionStart = whileConditionPointerStack.top();
								whileConditionPointerStack.pop();
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								asmInstrunctions.push_back(new AsmInstruction("JZERO", whileConditionStart));
								int whileJump = whileJumpPointerStack.top();
								whileJumpPointerStack.pop();
								asmInstrunctions[whileJump]->arg = asmInstrunctions.size();
								//usunac ze zmiennych Tx oraz iterator
								vector<string>::iterator it1 = find(initializedVars.begin(), initializedVars.end(), (yyvsp[-8].string));
								initializedVars.erase(it1);
								map<string, MemoryItem*>::iterator it2 = memoryMap.find((yyvsp[-8].string));
								memoryMap.erase(it2);
							  memoryMap.erase ("K"+to_string(for_var_counter-1));
							  memoryMap.erase ("C"+to_string(for_var_counter-1));
								it1 = find(immutableVars.begin(), immutableVars.end(), (yyvsp[-8].string));
								immutableVars.erase(it1);
								for_var_counter--;
							}
#line 1741 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 418 "grammar.y" /* yacc.c:1646  */
    {
							//wydrukuj GET i STORE pod komorka pamieci memoryMap.find(identifier)
								if((yyvsp[-1].value)->isVariable)
								{
									if(readToIdentifier((yyvsp[-1].value)->name))
										return 1;
								}
								else
								{
									asmInstrunctions.push_back(new AsmInstruction("GET"));
									if(storeAccumulatorInArray((yyvsp[-1].value)->name,(yyvsp[-1].value)->index))
										return 1;
								}
							}
#line 1760 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 432 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-1].value)->isNumber)
								{
									if(writeNumber(stoll((yyvsp[-1].value)->num)))
										return 1;
								}
								else if((yyvsp[-1].value)->isVariable)
								{
									if(writeIdentifier((yyvsp[-1].value)->name))
										return 1;
								}
								else
								{
									if(loadTableElementToAccumulator((yyvsp[-1].value)->name, (yyvsp[-1].value)->index))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("PUT"));
								}

							}
#line 1784 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 452 "grammar.y" /* yacc.c:1646  */
    {
								int jzero = jzeroLinePointerStack.top();
								jzeroLinePointerStack.pop();
								//printf("scionglem wlasnie: %d",jzero);
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								jzeroLinePointerStack.push(asmInstrunctions.size());
								asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));
								asmInstrunctions[jzero]->arg = asmInstrunctions.size();
							}
#line 1798 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 460 "grammar.y" /* yacc.c:1646  */
    {
								int jzero = jzeroLinePointerStack.top();
								jzeroLinePointerStack.pop();
								//printf("scionglem wlasnie: %d",jzero);
								asmInstrunctions[jzero]->arg = asmInstrunctions.size();
							}
#line 1809 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 466 "grammar.y" /* yacc.c:1646  */
    {
								int jzero = jzeroLinePointerStack.top();
								jzeroLinePointerStack.pop();
								//printf("scionglem wlasnie: %d",jzero);
								asmInstrunctions[jzero]->arg = asmInstrunctions.size();
							}
#line 1820 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 473 "grammar.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value);}
#line 1826 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 474 "grammar.y" /* yacc.c:1646  */
    {
								//printf("debug value>num :%s + %s\n",$1, $3);
								//std::cout <<"name: "<< $1->name<<" array: "<< $1->isArray <<endl;
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2) || storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"+",0))
										return 1;
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,ARRAY_TEMP_VAR_2,"+",0))
										return 1;
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,(yyvsp[0].value)->name,"+",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,(yyvsp[0].value)->name,"+",0))
										return 1;
								}
								Value* newValue = new Value;
								newValue->isArray = false;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = true;
								(yyval.value) = newValue;
							}
#line 1868 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 511 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"-",0))
										return 1;
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,(yyvsp[0].value)->name,"-",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,(yyvsp[0].value)->name,"-",0))
										return 1;
								}
								Value* newValue = new Value;
								newValue->isArray = false;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = true;
								(yyval.value) = newValue;
							}
#line 1910 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 548 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"*",0))
										return 1;
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,ARRAY_TEMP_VAR_2,"*",0))
										return 1;
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,(yyvsp[0].value)->name,"*",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,(yyvsp[0].value)->name,"*",0))
										return 1;
								}
								Value* newValue = new Value;
								newValue->isArray = false;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = true;
								(yyval.value) = newValue;
							}
#line 1952 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 585 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"/",0))
										return 1;
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,ARRAY_TEMP_VAR_2,"/",0))
										return 1;
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,(yyvsp[0].value)->name,"/",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,(yyvsp[0].value)->name,"/",0))
										return 1;
								}
								Value* newValue = new Value;
								newValue->isArray = false;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = true;
								(yyval.value) = newValue;
							}
#line 1994 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 622 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"/",0))
										return 1;
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,ARRAY_TEMP_VAR_2,"/",0))
										return 1;
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,(yyvsp[0].value)->name,"/",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,(yyvsp[0].value)->name,"/",0))
										return 1;
								}
								asmInstrunctions.push_back(new AsmInstruction("LOAD", 9));
								Value* newValue = new Value;
								newValue->isArray = false;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = true;
								(yyval.value) = newValue;
							}
#line 2037 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 661 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_3,ARRAY_TEMP_VAR_1,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2, (yyvsp[-2].value)->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,(yyvsp[0].value)->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation((yyvsp[0].value)->name, ARRAY_TEMP_VAR_2,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,(yyvsp[0].value)->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation((yyvsp[0].value)->name,(yyvsp[-2].value)->name,"-", 0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								constructValueToRegister(1);
								asmInstrunctions.push_back(new AsmInstruction("SUB", 5));
								asmInstrunctions.push_back(new AsmInstruction("SUB", 6));
							}
#line 2092 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 711 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_3,ARRAY_TEMP_VAR_1,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2, (yyvsp[-2].value)->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,(yyvsp[0].value)->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation((yyvsp[0].value)->name, ARRAY_TEMP_VAR_2,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,(yyvsp[0].value)->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation((yyvsp[0].value)->name,(yyvsp[-2].value)->name,"-", 0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								asmInstrunctions.push_back(new AsmInstruction("ADD", 5));
								asmInstrunctions.push_back(new AsmInstruction("ADD", 6));
							}
#line 2147 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 761 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_3,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2, (yyvsp[-2].value)->name,"-",0))
										return 1;
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[0].value)->name,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[0].value)->name,(yyvsp[-2].value)->name,"-",0))
										return 1;
								}
							}
#line 2183 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 792 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"-",0))
										return 1;
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,(yyvsp[0].value)->name,"-",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,(yyvsp[0].value)->name,"-",0))
										return 1;
								}
							}
#line 2219 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 823 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_3,ARRAY_TEMP_VAR_2,"-",1))
										return 1;
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2, (yyvsp[-2].value)->name,"-",1))
										return 1;
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[0].value)->name,ARRAY_TEMP_VAR_2,"-",1))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[0].value)->name,(yyvsp[-2].value)->name,"-",1))
										return 1;
								}
							}
#line 2255 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 854 "grammar.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].value)->isArray == true && (yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"-",1))
										return 1;
								}
								else if((yyvsp[0].value)->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable((yyvsp[0].value)->name, (yyvsp[0].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,ARRAY_TEMP_VAR_2,"-",1))
										return 1;
								}
								else if((yyvsp[-2].value)->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable((yyvsp[-2].value)->name, (yyvsp[-2].value)->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,(yyvsp[0].value)->name,"-",1))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation((yyvsp[-2].value)->name,(yyvsp[0].value)->name,"-",1))
										return 1;
								}
							}
#line 2291 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 886 "grammar.y" /* yacc.c:1646  */
    {
									Value* newValue = new Value;
									newValue->isArray = false;
									newValue->isVariable = false;
									newValue->isNumber = true;
									newValue->isResult = false;
									newValue->num = (yyvsp[0].string);
									newValue->name = (yyvsp[0].string); //tylko do determina
									(yyval.value) = newValue;
									//printf("debug value>num :%s\n", $1);
								}
#line 2307 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 897 "grammar.y" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value);}
#line 2313 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 899 "grammar.y" /* yacc.c:1646  */
    {
									Value* newValue = new Value;
									newValue->isArray = false;
									newValue->isVariable = true;
									newValue->isNumber = false;
									newValue->isResult = false;
									newValue->name = (yyvsp[0].string);
									(yyval.value) = newValue;
								}
#line 2327 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 908 "grammar.y" /* yacc.c:1646  */
    {
								Value* newValue = new Value;
								newValue->isArray = true;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = false;
								newValue->name = (yyvsp[-3].string);
								newValue->index = (yyvsp[-1].string);
								(yyval.value) = newValue;
							}
#line 2342 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 918 "grammar.y" /* yacc.c:1646  */
    {
								Value* newValue = new Value;
								newValue->isArray = true;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = false;
								newValue->name = (yyvsp[-3].string);
								newValue->index = (yyvsp[-1].string);
								(yyval.value) = newValue;
							}
#line 2357 "grammar.tab.c" /* yacc.c:1646  */
    break;


#line 2361 "grammar.tab.c" /* yacc.c:1646  */
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
#line 928 "grammar.y" /* yacc.c:1906  */


/********************************METHODS***********************************/

using namespace std;



//są trzy miejsca w ktorych mozna schować wartości arraya
int storeArrayValueInTemporaryVariable(string name, string index, int place)
{
	if(loadTableElementToAccumulator(name, index))
		return 1;
	if(place == 1)
	{
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_1));
	}
	else if(place == 2)
	{
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_2));
	}
	else if(place == 3)
	{
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_3));
	}
	return 0;
}

int findVariableInMemory(string name)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return -1;
	}
	else
	{
		return it->second->cell;
	}
}

//jeśli wywołasz tablice z indexem -1 (takim do zmiennych) to rzuć błąd, lub wiekszym niz rozmiar
int loadTableElementToAccumulator(string name, string index)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
	else if(it->second->array == 1)
	{
		if(regex_match(index, regex("[0-9]+")))
		{
			constructValueToRegister(stoll(index));
		}
		else
		{
			//załaduj variable do akumulatora
			map<string, MemoryItem*>::iterator it1 = memoryMap.find(index);
			if(it1 == memoryMap.end())
			{
					undefinedVariableError(index);
					return 1;
			}
			if(it1->second->array == 1)
			{
					typeMismatchError(index);
					return 1;
			}
			if(checkInitialization(index))
				return 1;
			int place = findVariableInMemory(index);
			if(place == -1)
				return 1;
			asmInstrunctions.push_back(new AsmInstruction("LOAD", place));
		}
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_1));
		asmInstrunctions.push_back(new AsmInstruction("LOAD", it->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("ADD", ARRAY_BUFFER_STORING_PLACE_1));
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_1));
		asmInstrunctions.push_back(new AsmInstruction("LOADI", ARRAY_BUFFER_STORING_PLACE_1));
		return 0;
	}
	else
	{
		typeMismatchError(name);
		return 1;
	}
}

int copyValueFromAnotherIdentifier(string from, string to)
{
	map<string, MemoryItem*>::iterator itFrom = memoryMap.find(from);
	map<string, MemoryItem*>::iterator itTo = memoryMap.find(to);
	if(itFrom == memoryMap.end())
	{
		undefinedVariableError(from);
		return 1;
	}
	else if (itTo == memoryMap.end())
	{
		undefinedVariableError(to);
		return 1;
	}
	else
	{
		if(checkInitialization(from))
			return 1;
		asmInstrunctions.push_back(new AsmInstruction("LOAD", itFrom->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("STORE", itTo->second->cell));
	}
	return 0;
}

int storeIdentifier(string name)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(memoryMap.find(name) == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
else if(it->second->array == false)
	{
		int placeInMemory = it->second->cell;
		AsmInstruction* a = new AsmInstruction("STORE", placeInMemory);
		asmInstrunctions.push_back(a);
		return 0;
	}
	else
	{
		typeMismatchError(name);
		return 1;
	}
}

int assignValueToIdentifier(string name, long long value)
{
	constructValueToRegister(value);
	return storeIdentifier(name);
}
//gte sluzy do tego zeby zrobic trik ze zwiekszeniem b przy porownaniu
int determineAndExecuteExpressionOperation(string arg1,string arg2,string oper, int gte)
{
	//cout<<"arg1: "<< arg1 << "arg2: "<< arg2 <<endl;
	//printf("debug oper: %s \n", oper.c_str());
	int arg1Num = regex_match(arg1, std::regex("[0-9]+"));
	int arg2Num = regex_match(arg2, std::regex("[0-9]+"));
	//printf("debug arg1: %s czy num: %d arg2: %s, czy num: %d \n",arg1.c_str(), arg1Num, arg2.c_str(), arg2Num);
	if(oper == "+")
	{
		if(arg1Num && arg2Num)
		{	if(Adder::add(atoi(arg1.c_str()), atoi(arg2.c_str())))
				return 1;}
		else if(!arg1Num && arg2Num)
		{	if(Adder::add(atoi(arg2.c_str()), arg1))
				return 1;}
		else if(arg1Num && !arg2Num)
		{
			if(Adder::add(atoi(arg1.c_str()), arg2))
				return 1;
		}
		else if(!arg1Num && !arg2Num)
		{	if(Adder::add(arg1,arg2))
				return 1;}
	}
	else if(oper == "-")
	{
		if(arg1Num && arg2Num)
		{
			if(gte)
			{	if(Substractor::sub(atoi(arg1.c_str())+1, atoi(arg2.c_str())))
					return 1;}
			else
			{	if(Substractor::sub(atoi(arg1.c_str()), atoi(arg2.c_str())))
					return 1;}
		}
		else if(!arg1Num && arg2Num)
		{
			if(gte)
			{	if(Substractor::subge(arg1, atoi(arg2.c_str())))
					return 1;}
			else
				{if(Substractor::sub(arg1, atoi(arg2.c_str())))
					return 1;}
		}
		else if(arg1Num && !arg2Num)
		{
			if(gte)
			{	if(Substractor::sub(atoi(arg1.c_str())+1, arg2))
					return 1;}
			else
			{	if(Substractor::sub(atoi(arg1.c_str()), arg2))
					return 1;}
		}
		else if(!arg1Num && !arg2Num)
		{
			if(gte)
			{	if(Substractor::subge(arg1,arg2))
					return 1;}
			else
			{	if(Substractor::sub(arg1,arg2))
					return 1;}
		}
	}
	else if(oper == "*")
	{
		if(arg1Num && arg2Num)
		{
			if(Multiplier::prepare(atoi(arg1.c_str()), atoi(arg2.c_str())))
				return 1;
		}
		else if(!arg1Num && arg2Num)
		{
			if(Multiplier::prepare(atoi(arg2.c_str()), arg1))
				return 1;
		}
		else if(arg1Num && !arg2Num)
		{
			if(Multiplier::prepare(atoi(arg1.c_str()), arg2))
				return 1;
		}
		else if(!arg1Num && !arg2Num)
		{
			if(Multiplier::prepare(arg1,arg2))
				return 1;
		}
		Multiplier::doTheJob();
	}
	else if(oper == "/")
	{
		if(arg1Num && arg2Num)
		{
			if(Divider::prepare(atoi(arg1.c_str()), atoi(arg2.c_str())))
				return 1;
		}
		else if(!arg1Num && arg2Num)
		{
			if(Divider::prepare(arg1,atoi(arg2.c_str())))
				return 1;
		}
		else if(arg1Num && !arg2Num)
		{
			if(Divider::prepare(atoi(arg1.c_str()), arg2))
				return 1;
		}
		else if(!arg1Num && !arg2Num)
		{
			if(Divider::prepare(arg1,arg2))
				return 1;
		}
		Divider::doTheJob();
	}
	return 0;
}

int writeNumber(long long number)
{
	constructValueToRegister(number);
	asmInstrunctions.push_back(new AsmInstruction("PUT"));
	return 0;
}

int writeIdentifier(string name)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
	else
	{
		if(checkInitialization(name))
			return 1;
		asmInstrunctions.push_back(new AsmInstruction("LOAD", it->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("PUT"));
		return 0;
	}
}

string decToBin(long long number)
{
    string result = "";
    do
    {
        if ( (number & 1) == 0 )
            result += "0";
        else
            result += "1";

        number >>= 1;
    } while ( number );

    reverse(result.begin(), result.end());
    return result;
}

int constructValueToRegister(long long value)
{
	string valueBin = decToBin(value);
	asmInstrunctions.push_back(new AsmInstruction("ZERO"));
	//printf("DEBUG: %d is binary: %s\n",value, valueBin.c_str());
	for(long long i=0; i<valueBin.length(); i++)
	{
		if(valueBin[i] == '0' && i!=0)
			asmInstrunctions.push_back(new AsmInstruction("SHL"));
		else if(valueBin[i] == '1')
		{
			asmInstrunctions.push_back(new AsmInstruction("SHL"));
			asmInstrunctions.push_back(new AsmInstruction("INC"));
		}
	}
	return 0;
}

int initializeIdentifier(string name, int tab, long long size)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		memoryMap[name] = new MemoryItem(name, tab, memory_pointer, size);
		if(tab == 1)
		{
			constructValueToRegister(memory_pointer+1);
			asmInstrunctions.push_back(new AsmInstruction("STORE", memory_pointer));
			memory_pointer++;
		}
		memory_pointer+=size;
		return 0;
	}
	else
	{
		char* error =(char*) malloc(100);
		error = strcpy(error, "Duplicate identifier: ");
		error = strcat(error,name.c_str());
		yyerror(error);
		return 1;
	}
}

int readToIdentifier(string name)
{
	initializedVars.push_back(name);
	AsmInstruction* a = new AsmInstruction("GET");
	asmInstrunctions.push_back(a);
	return storeIdentifier(name);
}

int storeAccumulatorInArray(string name, string index)
{
//	cout<<"idx: "<< index << endl;
	asmInstrunctions.push_back(new AsmInstruction("STORE", TEMP_ACC_PLACE));
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
else if(it->second->array == true)
	{
		if(regex_match(index, regex("[0-9]+")))
		{
			constructValueToRegister(stoll(index));
		}
		else
		{
			//załaduj index do akumulatora
			int place = findVariableInMemory(index);
			if(place == -1)
				return 1;
			asmInstrunctions.push_back(new AsmInstruction("LOAD", place));
		}
		asmInstrunctions.push_back(new AsmInstruction("ADD", it->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_1));
		asmInstrunctions.push_back(new AsmInstruction("LOAD", TEMP_ACC_PLACE));
		asmInstrunctions.push_back(new AsmInstruction("STOREI", ARRAY_BUFFER_STORING_PLACE_1));
		return 0;
	}
	else
	{
		typeMismatchError(name);
		return 1;
	}
}

int checkInitialization(string name)
{
	if(find(initializedVars.begin(), initializedVars.end(), name) != initializedVars.end())
	{
		return 0;
	}
	uninitializedVariableError(name);
	return 1;
}

void printAsmInstructions()
{
	ofstream outputFile;
	outputFile.open("output.mr");
	vector<AsmInstruction*>::iterator it;
	for (auto const& i : asmInstrunctions) {
    outputFile << i->toString() << endl;
	}
	outputFile.close();
}

/*******************ERROR HANDLING*********************************/

void immutableError(string varName)
{
	char* error =(char*) malloc(100);
	error = strcpy(error, "Attempt to edit immutable variable '");
	error = strcat(error,varName.c_str());
	error = strcat(error,"' .");
	yyerror(error);
	free(error);
}

void typeMismatchError(string varName)
{
	char* error =(char*) malloc(100);
	error = strcpy(error, "Incorrect call to '");
	error = strcat(error,varName.c_str());
	error = strcat(error,"' variable. Type mismatch.");
	yyerror(error);
	free(error);
}

void undefinedVariableError(string varName)
{
	char* error =(char*) malloc(100);
	error = strcpy(error, "Variable '");
	error = strcat(error,varName.c_str());
	error = strcat(error,"' undeclared.");
	yyerror(error);
	free(error);
}

void uninitializedVariableError(string varName)
{
	char* error =(char*) malloc(100);
	error = strcpy(error, "Variable '");
	error = strcat(error,varName.c_str());
	error = strcat(error,"' uninitialized.");
	yyerror(error);
	free(error);
}

void yyerror (char const *s)
{
	printf("Error at line:%d near expression '%s', detail : %s \n", yylineno, yytext, s);
}


int main (void)
{
	memory_pointer = 14;

	memoryMap[ARRAY_TEMP_VAR_1] = new MemoryItem(ARRAY_TEMP_VAR_1, 1, ARRAY_BUFFER_STORING_PLACE_1, 1);
	memoryMap[ARRAY_TEMP_VAR_2] = new MemoryItem(ARRAY_TEMP_VAR_2, 1, ARRAY_BUFFER_STORING_PLACE_2, 1);
	memoryMap[ARRAY_TEMP_VAR_3] = new MemoryItem(ARRAY_TEMP_VAR_3, 1, ARRAY_BUFFER_STORING_PLACE_3, 1);
	initializedVars.push_back(ARRAY_TEMP_VAR_1);
	initializedVars.push_back(ARRAY_TEMP_VAR_2);
	initializedVars.push_back(ARRAY_TEMP_VAR_3);

	if(yyparse() == 0)
		printf("Process returned 0, no errors.\n");
	else
		printf("Process returned 1, error.\n");

		return 0;
}
