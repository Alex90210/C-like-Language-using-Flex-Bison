/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "limbaj.y"

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <variant>
#include "utils.h"
#include "AST.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
SymbolTable table;
using namespace std;

std::vector<FunctionSymbol> functions;
std::vector<Symbol> currentParameters;

void initParameters() {
    currentParameters.clear();
}

void addParameter(const std::string& type, const std::string& name) {
    Symbol symbol;
    symbol.name = name;
    symbol.type = type;
    currentParameters.push_back(symbol);
}

std::string getTypeOf(const std::string& operand) {

    Symbol* sym = table.findSymbol(operand);
    if (sym != nullptr) {
        return sym->type;
    }

    if (isNumber(operand)) {
        return "int";
    }

    if (isFloat(operand)) {
        return "float";
    }

    return "unknown";
}

std::vector<std::string> splitTypes(const char* concatenatedTypes) {
    std::vector<std::string> types;
    std::istringstream iss(concatenatedTypes);
    std::string type;
    while (iss >> type) {
        types.push_back(type);
    }
    return types;
}

#line 131 "limbaj.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGIN = 3,                       /* BGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_NR = 6,                         /* NR  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_STRING = 10,                    /* STRING  */
  YYSYMBOL_CONST = 11,                     /* CONST  */
  YYSYMBOL_ID = 12,                        /* ID  */
  YYSYMBOL_TYPE = 13,                      /* TYPE  */
  YYSYMBOL_EVAL = 14,                      /* EVAL  */
  YYSYMBOL_TYPEOF = 15,                    /* TYPEOF  */
  YYSYMBOL_ARRAY_BRACKETS = 16,            /* ARRAY_BRACKETS  */
  YYSYMBOL_F_START = 17,                   /* F_START  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_FRAME_KEYWORD = 19,             /* FRAME_KEYWORD  */
  YYSYMBOL_OPEN_BRACE = 20,                /* OPEN_BRACE  */
  YYSYMBOL_CLOSE_BRACE = 21,               /* CLOSE_BRACE  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_NO_CTRL = 25,                   /* NO_CTRL  */
  YYSYMBOL_CHAR_ASSIGN = 26,               /* CHAR_ASSIGN  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_LE = 30,                        /* LE  */
  YYSYMBOL_GT = 31,                        /* GT  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_35_ = 35,                       /* '!'  */
  YYSYMBOL_36_ = 36,                       /* '<'  */
  YYSYMBOL_37_ = 37,                       /* '>'  */
  YYSYMBOL_38_ = 38,                       /* '+'  */
  YYSYMBOL_39_ = 39,                       /* '-'  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* '.'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_progr = 50,                     /* progr  */
  YYSYMBOL_frame_definition = 51,          /* frame_definition  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_frame_body = 54,                /* frame_body  */
  YYSYMBOL_declarations = 55,              /* declarations  */
  YYSYMBOL_decl = 56,                      /* decl  */
  YYSYMBOL_const_decl = 57,                /* const_decl  */
  YYSYMBOL_var_decl = 58,                  /* var_decl  */
  YYSYMBOL_array_decl = 59,                /* array_decl  */
  YYSYMBOL_ctrl_keywords = 60,             /* ctrl_keywords  */
  YYSYMBOL_ctrl_statements = 61,           /* ctrl_statements  */
  YYSYMBOL_char_expr = 62,                 /* char_expr  */
  YYSYMBOL_expr = 63,                      /* expr  */
  YYSYMBOL_number_expr = 64,               /* number_expr  */
  YYSYMBOL_bool_expr = 65,                 /* bool_expr  */
  YYSYMBOL_f_declarations = 66,            /* f_declarations  */
  YYSYMBOL_67_3 = 67,                      /* $@3  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_statements = 69,                /* statements  */
  YYSYMBOL_F_VALUE = 70,                   /* F_VALUE  */
  YYSYMBOL_parameters = 71,                /* parameters  */
  YYSYMBOL_parameter_declaration = 72,     /* parameter_declaration  */
  YYSYMBOL_block = 73,                     /* block  */
  YYSYMBOL_list = 74,                      /* list  */
  YYSYMBOL_predifined_functions = 75,      /* predifined_functions  */
  YYSYMBOL_statement = 76,                 /* statement  */
  YYSYMBOL_field_access = 77,              /* field_access  */
  YYSYMBOL_method_call = 78,               /* method_call  */
  YYSYMBOL_call_arguments = 79,            /* call_arguments  */
  YYSYMBOL_call_list = 80                  /* call_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,     2,     2,     2,     2,     2,
      45,    46,    40,    38,    48,    39,    47,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      36,     2,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,   101,   101,   109,   109,   119,   120,   121,
     124,   125,   128,   128,   128,   131,   155,   191,   215,   248,
     279,   279,   316,   372,   372,   372,   374,   375,   376,   382,
     389,   393,   407,   410,   416,   420,   424,   428,   432,   433,
     442,   457,   470,   473,   476,   477,   478,   479,   480,   481,
     485,   489,   493,   497,   500,   509,   509,   556,   556,   586,
     586,   588,   588,   588,   588,   588,   588,   590,   591,   592,
     595,   599,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   614,   618,   624,   743,   768,   784,   811,   827,
     833,   834,   835,   836,   837,   841,   844
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BGIN", "END",
  "ASSIGN", "NR", "FLOAT", "BOOL", "CHAR", "STRING", "CONST", "ID", "TYPE",
  "EVAL", "TYPEOF", "ARRAY_BRACKETS", "F_START", "RETURN", "FRAME_KEYWORD",
  "OPEN_BRACE", "CLOSE_BRACE", "IF", "WHILE", "FOR", "NO_CTRL",
  "CHAR_ASSIGN", "GE", "EQ", "NE", "LE", "GT", "LT", "OR", "AND", "'!'",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "';'", "'['", "']'", "'('",
  "')'", "'.'", "','", "$accept", "progr", "frame_definition", "$@1",
  "$@2", "frame_body", "declarations", "decl", "const_decl", "var_decl",
  "array_decl", "ctrl_keywords", "ctrl_statements", "char_expr", "expr",
  "number_expr", "bool_expr", "f_declarations", "$@3", "$@4", "statements",
  "F_VALUE", "parameters", "parameter_declaration", "block", "list",
  "predifined_functions", "statement", "field_access", "method_call",
  "call_arguments", "call_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    12,    57,   117,    44,   -56,    58,    74,    88,   190,
      63,   -56,   -56,   -56,   -56,   112,    25,    76,   125,   109,
      15,   -56,   118,   155,    54,    73,   162,   -56,   168,   -56,
     139,   175,   -56,   -56,   -56,   -56,   -56,   202,    84,   185,
      51,    54,   -56,   -56,   -56,   -16,    59,    54,   -56,   157,
     129,   -56,   -56,   -56,   -56,   187,   118,   -56,   133,   231,
      48,    56,   205,   -56,   203,   -56,   246,   241,    59,   -56,
     137,   -24,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    59,    59,   249,   202,   211,     3,   212,   213,
      92,    98,   -56,   217,   -56,   -56,   -56,   -56,   -56,   235,
      54,   216,   -56,   -56,   -56,    14,   197,   172,   172,   197,
     197,   197,   209,   209,   -56,   -56,   227,   -56,    54,    55,
     250,    54,   208,   252,    54,    54,   -56,   -56,    95,   -56,
     220,   -56,   -56,   -56,   221,   139,   219,   -56,   -56,   -56,
     255,   193,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   194,   184,   222,   223,   -56,   -56,   250,    90,   251,
     -56,   253,   250,   -56,   208,   -56,     7,   228,   230,   198,
     -56,   139,   139,   -56,   -56,   232,   199,   -56,   -56,   256,
     114,    22,   -56,   233,   139,   -56,     2,   167,   236,   -56,
      22,   182,   237,   -56,   167,   215,   -56,   210,   -56,   -56,
     -56,   -56,   -56,   -56,   238,   215,   260,   240,   -56,   262,
     -56
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    20,     0,     1,     0,     0,     0,    20,
       0,    12,    13,    14,     3,     0,    17,     0,     0,     0,
       0,    10,    20,    15,     0,     0,     0,     5,     0,    11,
      20,     0,     2,    23,    24,    25,    28,     0,     7,     0,
       0,     0,    42,    43,    54,    39,     0,     0,    18,    32,
      33,    29,    30,    31,    19,     0,    20,    57,    20,     0,
       0,     0,     0,     8,     0,    16,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,    80,     0,    74,    76,    55,     4,     9,     0,
       0,     0,    40,    38,    53,     0,    44,    45,    46,    47,
      49,    48,    34,    35,    36,    37,    50,    51,     0,     0,
      67,     0,     0,     0,     0,     0,    78,    71,     0,    81,
       0,    75,    77,    72,     0,    20,     0,    41,    22,     6,
       0,     0,    68,    84,    90,    91,    92,    94,    93,    89,
      95,     0,     0,     0,     0,    79,    73,    67,    20,     0,
      70,     0,     0,    85,     0,    86,     0,     0,     0,     0,
      26,    20,    20,    69,    96,     0,     0,    82,    83,     0,
      20,    20,    88,     0,    20,    27,     0,     0,     0,    87,
      20,     0,     0,    59,     0,     0,    60,     0,    62,    63,
      64,    66,    65,    61,     0,     0,     0,     0,    58,     0,
      56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   -56,   -56,   -56,   229,    -2,    -9,   -56,   -56,
     -56,   -38,   -33,   -56,   -37,   -35,     9,   -31,   -56,   -56,
      87,    79,   130,   124,   -56,   -56,   200,   -55,   201,   204,
     126,   122
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    22,    56,    37,    38,    10,    11,    12,
      13,    39,    40,    54,    48,    49,    50,    20,   134,    86,
     187,   204,   141,   142,    32,    91,    92,   188,    94,    95,
     150,   151
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,     9,    64,    93,    65,    61,    60,   121,   121,    82,
      83,     1,    70,   144,   145,   146,   147,   148,    30,   149,
      42,    43,   104,    64,     4,    90,    45,    66,    58,    19,
      24,    67,    31,     6,   186,     7,   130,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   122,   122,    19,
     123,    25,    64,   175,   119,    69,    71,     5,   128,   105,
      42,    43,    44,   136,    14,    31,    45,    44,    26,    97,
      70,    15,    31,    33,    34,    35,   139,    71,    33,    34,
      35,   138,    51,    52,   143,    53,    16,   153,   154,    46,
      64,   116,   117,    63,    46,     6,    27,     7,    98,    47,
      17,     6,   127,     7,    68,    21,    33,    34,    35,    36,
      87,   170,    88,    89,    33,    34,    35,    33,    34,    35,
      33,    34,    35,    36,    23,     6,   -20,     7,     6,     6,
       7,     7,   192,   158,   126,   185,     8,   155,    28,   192,
      33,    34,    35,    36,     6,    87,     7,    88,    89,    19,
       6,    29,     7,    64,   191,    33,    34,    35,    36,    64,
      41,   197,    82,    83,    72,    73,    74,    75,    55,   180,
     181,    19,    19,    76,    77,    78,    79,    80,    81,   186,
      57,    19,   190,   103,    72,    73,    74,    75,    59,    33,
      34,    35,    36,    76,    77,    78,    79,    80,    81,    72,
     195,     6,    75,     7,    33,    34,    35,    18,    76,    77,
      78,    79,    80,    81,   144,   145,   146,   147,   148,    18,
     149,   198,   199,   200,   201,   202,   165,   203,   205,   166,
      62,    84,    33,    34,    35,    78,    79,    80,    81,   161,
     163,   162,   164,    96,   179,   183,   162,   164,   100,    80,
      81,    99,   101,   102,   118,   135,   120,   124,   125,   133,
     137,    83,   156,   140,   152,   159,   157,   160,   167,   168,
     177,   171,   178,   172,   182,   189,   184,   194,   193,   196,
     206,   208,   209,   210,   207,    85,   173,   169,   176,     0,
     174,   129,   131,     0,     0,   132
};

static const yytype_int16 yycheck[] =
{
       9,     3,    40,    58,    41,    38,    37,     5,     5,    33,
      34,    19,    47,     6,     7,     8,     9,    10,     3,    12,
       6,     7,    46,    61,    12,    58,    12,    43,    30,    38,
       5,    47,    17,    11,    12,    13,    91,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    45,    45,    58,
      47,    26,    90,    46,    85,    46,    47,     0,    91,    45,
       6,     7,     8,   100,    20,    17,    12,     8,    43,    21,
     105,    13,    17,    22,    23,    24,    21,    68,    22,    23,
      24,   118,     9,    10,   121,    12,    12,   124,   125,    35,
     128,    82,    83,    42,    35,    11,    20,    13,    42,    45,
      12,    11,     4,    13,    45,    42,    22,    23,    24,    25,
      12,    21,    14,    15,    22,    23,    24,    22,    23,    24,
      22,    23,    24,    25,    12,    11,    42,    13,    11,    11,
      13,    13,   187,   135,    42,    21,    19,    42,    13,   194,
      22,    23,    24,    25,    11,    12,    13,    14,    15,   158,
      11,    42,    13,   191,   187,    22,    23,    24,    25,   197,
       5,   194,    33,    34,    27,    28,    29,    30,     6,   171,
     172,   180,   181,    36,    37,    38,    39,    40,    41,    12,
      12,   190,   184,    46,    27,    28,    29,    30,    13,    22,
      23,    24,    25,    36,    37,    38,    39,    40,    41,    27,
      18,    11,    30,    13,    22,    23,    24,    17,    36,    37,
      38,    39,    40,    41,     6,     7,     8,     9,    10,    17,
      12,     6,     7,     8,     9,    10,    42,    12,    18,    45,
      45,    44,    22,    23,    24,    38,    39,    40,    41,    46,
      46,    48,    48,    12,    46,    46,    48,    48,    45,    40,
      41,    46,     6,    12,     5,    20,    45,    45,    45,    42,
      44,    34,    42,    13,    12,    46,    45,    12,    46,    46,
      42,    20,    42,    20,    42,    42,    20,   190,    42,    42,
      42,    21,    42,    21,   205,    56,   162,   157,   166,    -1,
     164,    91,    91,    -1,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    50,    51,    12,     0,    11,    13,    19,    55,
      56,    57,    58,    59,    20,    13,    12,    12,    17,    56,
      66,    42,    52,    12,     5,    26,    43,    20,    13,    42,
       3,    17,    73,    22,    23,    24,    25,    54,    55,    60,
      61,     5,     6,     7,     8,    12,    35,    45,    63,    64,
      65,     9,    10,    12,    62,     6,    53,    12,    55,    13,
      66,    61,    45,    42,    60,    63,    43,    47,    45,    65,
      64,    65,    27,    28,    29,    30,    36,    37,    38,    39,
      40,    41,    33,    34,    44,    54,    68,    12,    14,    15,
      61,    74,    75,    76,    77,    78,    12,    21,    42,    46,
      45,     6,    12,    46,    46,    45,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,     5,    66,
      45,     5,    45,    47,    45,    45,    42,     4,    61,    75,
      76,    77,    78,    42,    67,    20,    63,    44,    63,    21,
      13,    71,    72,    63,     6,     7,     8,     9,    10,    12,
      79,    80,    12,    63,    63,    42,    42,    45,    55,    46,
      12,    46,    48,    46,    48,    42,    45,    46,    46,    71,
      21,    20,    20,    72,    79,    46,    80,    42,    42,    46,
      55,    55,    42,    46,    20,    21,    12,    69,    76,    42,
      55,    61,    76,    42,    69,    18,    42,    61,     6,     7,
       8,     9,    10,    12,    70,    18,    42,    70,    21,    42,
      21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    52,    51,    53,    51,    54,    54,    54,
      55,    55,    56,    56,    56,    57,    57,    58,    58,    58,
      59,    59,    59,    60,    60,    60,    61,    61,    61,    62,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    67,    66,    68,    66,    69,
      69,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      72,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    75,    75,    76,    76,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     7,     0,     8,     1,     2,     3,
       2,     3,     1,     1,     1,     3,     5,     2,     4,     4,
       0,     5,     7,     1,     1,     1,     6,     8,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     1,
       3,     4,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     1,     0,    16,     0,    15,     2,
       3,     1,     1,     1,     1,     1,     1,     0,     1,     3,
       2,     4,     2,     3,     1,     2,     1,     2,     2,     3,
       1,     2,     5,     5,     3,     4,     4,     7,     6,     1,
       1,     1,     1,     1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* progr: frame_definition declarations f_declarations block  */
#line 96 "limbaj.y"
                                                           {
        printf("The syntax of the code is correct.\n");
        }
#line 1354 "limbaj.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 101 "limbaj.y"
                                               {
    initParameters();
    table.addFrame(Frame{std::string((yyvsp[-1].string))});
    std::string frameName = std::string((yyvsp[-1].string)) + " FRAME";
    enterScope(frameName);
}
#line 1365 "limbaj.tab.c"
    break;

  case 4: /* frame_definition: FRAME_KEYWORD ID OPEN_BRACE $@1 frame_body f_declarations CLOSE_BRACE  */
#line 106 "limbaj.y"
                                        {    
    leaveScope();
}
#line 1373 "limbaj.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 109 "limbaj.y"
                                               {
    initParameters();
    table.addFrame(Frame{std::string((yyvsp[-2].string))});
    std::string frameName = std::string((yyvsp[-2].string)) + " FRAME";
    enterScope(frameName);
}
#line 1384 "limbaj.tab.c"
    break;

  case 6: /* frame_definition: frame_definition FRAME_KEYWORD ID OPEN_BRACE $@2 frame_body f_declarations CLOSE_BRACE  */
#line 114 "limbaj.y"
                                        {    
    leaveScope();
}
#line 1392 "limbaj.tab.c"
    break;

  case 15: /* const_decl: CONST TYPE ID  */
#line 131 "limbaj.y"
                  { 
        Symbol* sym = table.findSymbol((yyvsp[0].string));
        if (sym != nullptr && currentScope() == sym->scope) {
            yyerror(("Variable previously defined: " + std::string((yyvsp[0].string))).c_str());
        } else {
            Symbol symbol;
            symbol.name = (yyvsp[0].string);
            symbol.type = (yyvsp[-1].string);
            symbol.isConstant = true;
            symbol.scope = currentScope();

            if (endsWithFrame(currentScope())) {
                std::string frameName = extractBeforeFrame(currentScope());
                Frame* framePtr = table.findFrame(frameName);
                if (framePtr) {
                    framePtr->addSymbol(symbol);
                } else {
                    yyerror(("Frame not defined: " + frameName).c_str());
                }
            } else {
                table.addSymbol(symbol);
            }
        }
    }
#line 1421 "limbaj.tab.c"
    break;

  case 16: /* const_decl: CONST TYPE ID ASSIGN expr  */
#line 155 "limbaj.y"
                                { 
        ASTNode* exprNode = static_cast<ASTNode*>((yyvsp[0].node));  
        double result = exprNode->evaluate(table);
        std::cout << "Value of " << std::string((yyvsp[-2].string)) << ": " << result << std::endl;
        Symbol* sym = table.findSymbol((yyvsp[-2].string));
        if (sym != nullptr && currentScope() == sym->scope) {
            yyerror(("Variable previously defined: " + std::string((yyvsp[-2].string))).c_str());
        } else {
            if (std::string((yyvsp[-3].string)) != exprNode->varType) {
                yyerror(("Type mismatch in assignment. L-type:" + std::string((yyvsp[-3].string)) +
                " R-type:" + exprNode->varType).c_str());
            } else {
                Symbol symbol;
                symbol.name = (yyvsp[-2].string);
                symbol.type = (yyvsp[-3].string);
                symbol.isConstant = true;
                symbol.scope = currentScope();
                symbol.value = std::to_string(result);

                if (endsWithFrame(currentScope())) {
                    std::string frameName = extractBeforeFrame(currentScope());
                    Frame* framePtr = table.findFrame(frameName);
                    if (framePtr) {
                        framePtr->addSymbol(symbol);
                    } else {
                        yyerror(("Frame not defined: " + frameName).c_str());
                    }
                } else {
                    table.addSymbol(symbol);
                }
            }    
        }
    }
#line 1459 "limbaj.tab.c"
    break;

  case 17: /* var_decl: TYPE ID  */
#line 191 "limbaj.y"
            { 
        Symbol* sym = table.findSymbol((yyvsp[0].string));
        if (sym != nullptr && currentScope() == sym->scope) {
            yyerror(("Variable previously defined: " + std::string((yyvsp[0].string))).c_str());
        } else {
            Symbol symbol;
            symbol.name = (yyvsp[0].string);
            symbol.type = (yyvsp[-1].string);
            symbol.isConstant = false;
            symbol.scope = currentScope();

            if (endsWithFrame(currentScope())) {
                std::string frameName = extractBeforeFrame(currentScope());
                Frame* framePtr = table.findFrame(frameName);
                if (framePtr) {
                    framePtr->addSymbol(symbol);
                } else {
                    yyerror(("Frame not defined: " + frameName).c_str());
                }
            } else {
                table.addSymbol(symbol);
            }
        }
    }
#line 1488 "limbaj.tab.c"
    break;

  case 18: /* var_decl: TYPE ID ASSIGN expr  */
#line 215 "limbaj.y"
                          {
        ASTNode* exprNode = static_cast<ASTNode*>((yyvsp[0].node));  
        double result = exprNode->evaluate(table);
        std::cout << "Value of " << std::string((yyvsp[-2].string)) << ": " << result << std::endl;
        Symbol* sym = table.findSymbol((yyvsp[-2].string));
        if (sym != nullptr && currentScope() == sym->scope) {
            yyerror(("Variable previously defined: " + std::string((yyvsp[-2].string))).c_str());
        } else {
            if (std::string((yyvsp[-3].string)) != exprNode->varType) {
                yyerror(("Type mismatch in assignment. L-type:" + std::string((yyvsp[-3].string)) +
                " R-type:" + exprNode->varType).c_str());
            } else {
                Symbol symbol;
                symbol.name = (yyvsp[-2].string);
                symbol.type = (yyvsp[-3].string);
                symbol.isConstant = false;
                symbol.scope = currentScope();
                symbol.value = std::to_string(result);

                if (endsWithFrame(currentScope())) {
                    std::string frameName = extractBeforeFrame(currentScope());
                    Frame* framePtr = table.findFrame(frameName);
                    if (framePtr) {
                        framePtr->addSymbol(symbol);
                    } else {
                        yyerror(("Frame not defined: " + frameName).c_str());
                    }
                } else {
                    table.addSymbol(symbol);
                }
            }
        }
    }
#line 1526 "limbaj.tab.c"
    break;

  case 19: /* var_decl: TYPE ID CHAR_ASSIGN char_expr  */
#line 248 "limbaj.y"
                                    {
        if ((yyvsp[0].string) == nullptr) {
            yyerror("Invalid character expression.");
        } else {
            Symbol* sym = table.findSymbol((yyvsp[-2].string));
            if (sym != nullptr && currentScope() == sym->scope) {
                yyerror(("Variable already defined: " + std::string((yyvsp[-2].string))).c_str());
            } else {
                Symbol symbol;
                symbol.name = (yyvsp[-2].string);
                symbol.type = (yyvsp[-3].string);
                symbol.isConstant = false;
                symbol.scope = currentScope();
                symbol.value = (yyvsp[0].string); // Assuming $

                if (endsWithFrame(currentScope())) {
                    std::string frameName = extractBeforeFrame(currentScope());
                    Frame* framePtr = table.findFrame(frameName);
                    if (framePtr) {
                        framePtr->addSymbol(symbol);
                    } else {
                        yyerror(("Frame not defined: " + frameName).c_str());
                    }
                } else {
                    table.addSymbol(symbol);
                }
            }
        }
    }
#line 1560 "limbaj.tab.c"
    break;

  case 21: /* array_decl: TYPE ID '[' NR ']'  */
#line 279 "limbaj.y"
                                             {
                Symbol* sym = table.findSymbol((yyvsp[-3].string));
                if (sym != nullptr && currentScope() == sym->scope) {
                    yyerror(("Variable previously defined: " + std::string((yyvsp[-3].string))).c_str());
                } 
                else {
                    Symbol symbol;
                    symbol.name = (yyvsp[-3].string);
                    std::string arrayDecl {"[]"};
                    symbol.type = (yyvsp[-4].string) + arrayDecl;
                    symbol.arraySize = (yyvsp[-1].int_val);
                    symbol.isConstant = false;
                    symbol.scope = currentScope();

                    std::vector<double> stringArray(symbol.arraySize, 0);
                    symbol.values = stringArray;

                    if (endsWithFrame(currentScope())) {
                        std::string frameName = extractBeforeFrame(currentScope());

                        Frame* framePtr = table.findFrame(frameName);
                        if (framePtr) {
                            framePtr->addSymbol(symbol);
                        }
                        else {
                            yyerror(("Frame not defined: " + frameName).c_str());
                        }
                    }
                    else {
                        table.addSymbol(symbol);
                    }
                }
            }
#line 1598 "limbaj.tab.c"
    break;

  case 22: /* array_decl: TYPE ID '[' NR ']' ASSIGN expr  */
#line 316 "limbaj.y"
                                             {
                Symbol* sym = table.findSymbol((yyvsp[-5].string));
                if (sym != nullptr && currentScope() == sym->scope) {
                    yyerror(("Variable previosly defined: " + std::string((yyvsp[-5].string))).c_str());
                } 
                else {
                    if (endsWithFrame(currentScope())) {
                        std::string frameName = extractBeforeFrame(currentScope());
                        std::cout << "ARRAY IS IN SCOPE: "<< frameName << std::endl;

                        Symbol symbol;
                        symbol.name = (yyvsp[-5].string);
                        std::string arrayDecl {"[]"};
                        symbol.type = (yyvsp[-6].string) + arrayDecl;
                        symbol.arraySize = (yyvsp[-3].int_val);
                        symbol.isConstant = false;
                        symbol.scope = currentScope();


                        ASTNode* exprNode = static_cast<ASTNode*>((yyvsp[0].node));
                        double initValue = exprNode->evaluate(table);

                        std::vector<double> stringArray(symbol.arraySize, initValue);
                        symbol.values = stringArray;

                        Frame* framePtr = table.findFrame(frameName);
                        // std::cout << "frame names: " << table.frames.size() << std::endl;
                        // the names are correctly registred before the find() function is called
                        if (framePtr) {
                            framePtr->addSymbol(symbol);
                        }
                        else {
                            yyerror(("Frame not defined: " + frameName).c_str());
                        }
                    }
                    else {
                        Symbol symbol;
                        symbol.name = (yyvsp[-5].string);
                        std::string arrayDecl {"[]"};
                        symbol.type = (yyvsp[-6].string) + arrayDecl;
                        symbol.arraySize = (yyvsp[-3].int_val);
                        symbol.isConstant = false;
                        symbol.scope = currentScope();

                        ASTNode* exprNode = static_cast<ASTNode*>((yyvsp[0].node));
                        double initValue = exprNode->evaluate(table);

                        std::vector<double> stringArray(symbol.arraySize, initValue);
                        symbol.values = stringArray;

                        table.addSymbol(symbol);
                    }
                }
            }
#line 1657 "limbaj.tab.c"
    break;

  case 29: /* char_expr: CHAR  */
#line 382 "limbaj.y"
         {
        char *charValue = (char *)malloc(2 * sizeof(char));
        charValue[0] = (yyvsp[0].string)[1];
        charValue[1] = '\0';
        printf("CHAR case: %s\n", charValue);
        (yyval.string) = charValue;
    }
#line 1669 "limbaj.tab.c"
    break;

  case 30: /* char_expr: STRING  */
#line 389 "limbaj.y"
             {
        printf("STRING case: %s\n", (yyvsp[0].string));
        (yyval.string) = (yyvsp[0].string);
    }
#line 1678 "limbaj.tab.c"
    break;

  case 31: /* char_expr: ID  */
#line 393 "limbaj.y"
         {
        Symbol* sym = table.findSymbol((yyvsp[0].string));
        if (sym == nullptr) {
            yyerror(("Variable not defined: " + std::string((yyvsp[0].string))).c_str());
            (yyval.string) = nullptr;
        } else {
            (yyval.string) = strdup(sym->value.c_str());
            printf("STRING case: %s\n", (char*)(yyval.string));
        }
    }
#line 1693 "limbaj.tab.c"
    break;

  case 32: /* expr: number_expr  */
#line 407 "limbaj.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1701 "limbaj.tab.c"
    break;

  case 33: /* expr: bool_expr  */
#line 410 "limbaj.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1709 "limbaj.tab.c"
    break;

  case 34: /* number_expr: number_expr '+' number_expr  */
#line 416 "limbaj.y"
                                {
        (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::OPERATOR, static_cast<ASTNode*>((yyvsp[-2].node))->varType, "+", 
        static_cast<ASTNode*>((yyvsp[-2].node)), static_cast<ASTNode*>((yyvsp[0].node))));
    }
#line 1718 "limbaj.tab.c"
    break;

  case 35: /* number_expr: number_expr '-' number_expr  */
#line 420 "limbaj.y"
                                  {
        (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::OPERATOR, static_cast<ASTNode*>((yyvsp[-2].node))->varType, "-", 
        static_cast<ASTNode*>((yyvsp[-2].node)), static_cast<ASTNode*>((yyvsp[0].node))));
    }
#line 1727 "limbaj.tab.c"
    break;

  case 36: /* number_expr: number_expr '*' number_expr  */
#line 424 "limbaj.y"
                                  {
        (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::OPERATOR, static_cast<ASTNode*>((yyvsp[-2].node))->varType, "*", 
        static_cast<ASTNode*>((yyvsp[-2].node)), static_cast<ASTNode*>((yyvsp[0].node))));
    }
#line 1736 "limbaj.tab.c"
    break;

  case 37: /* number_expr: number_expr '/' number_expr  */
#line 428 "limbaj.y"
                                  {
        (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::OPERATOR, static_cast<ASTNode*>((yyvsp[-2].node))->varType, "/", 
        static_cast<ASTNode*>((yyvsp[-2].node)), static_cast<ASTNode*>((yyvsp[0].node))));
    }
#line 1745 "limbaj.tab.c"
    break;

  case 38: /* number_expr: '(' number_expr ')'  */
#line 432 "limbaj.y"
                          { (yyval.node) = (yyvsp[-1].node); }
#line 1751 "limbaj.tab.c"
    break;

  case 39: /* number_expr: ID  */
#line 433 "limbaj.y"
         {
        Symbol* sym = table.findSymbol((yyvsp[0].string));
        if (sym == nullptr) {
            yyerror(("Variable not defined: " + std::string((yyvsp[0].string))).c_str());
            (yyval.node) = nullptr;
        } else {
            (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::IDENTIFIER, sym->type, sym->name));
        }
    }
#line 1765 "limbaj.tab.c"
    break;

  case 40: /* number_expr: ID '.' ID  */
#line 442 "limbaj.y"
                {
        Frame* frame = table.findFrame((yyvsp[-2].string));
        if (frame == nullptr) {
            yyerror(("Frame not defined: " + std::string((yyvsp[-2].string))).c_str());
            (yyval.node) = nullptr;
        } else {
            Symbol* sym = frame->findSymbol((yyvsp[0].string));
            if (sym == nullptr) {
                yyerror(("Symbol not defined in frame '" + std::string((yyvsp[-2].string)) + "': " + std::string((yyvsp[0].string))).c_str());
                (yyval.node) = nullptr;
            } else {
                (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::IDENTIFIER, sym->type, sym->name));
            }
        }
    }
#line 1785 "limbaj.tab.c"
    break;

  case 41: /* number_expr: ID '[' NR ']'  */
#line 457 "limbaj.y"
                    {
        Symbol* sym = table.findSymbol((yyvsp[-3].string));
        if (sym == nullptr) {
            yyerror(("Variable not defined: " + std::string((yyvsp[-3].string))).c_str());
            (yyval.node) = nullptr;
        } else if (sym->type.find("[]") == std::string::npos) {
            yyerror(("Variable is not an array: " + std::string((yyvsp[-3].string))).c_str());
            (yyval.node) = nullptr;
        } else {
            ASTNode* indexNode = new ASTNode(ASTNode::NUMBER, "int", std::to_string((yyvsp[-1].int_val)));
            (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::ARRAY_ACCESS, sym->type, sym->name, nullptr, indexNode));
        }
    }
#line 1803 "limbaj.tab.c"
    break;

  case 42: /* number_expr: NR  */
#line 470 "limbaj.y"
         {
        (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::NUMBER, "int", std::to_string((yyvsp[0].int_val))));
    }
#line 1811 "limbaj.tab.c"
    break;

  case 43: /* number_expr: FLOAT  */
#line 473 "limbaj.y"
            {
        (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::NUMBER, "float", std::to_string((yyvsp[0].float_val))));
    }
#line 1819 "limbaj.tab.c"
    break;

  case 50: /* bool_expr: bool_expr OR bool_expr  */
#line 485 "limbaj.y"
                           {
        (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::BOOL_OPERATOR, "bool", "OR", 
        static_cast<ASTNode*>((yyvsp[-2].node)), static_cast<ASTNode*>((yyvsp[0].node))));
    }
#line 1828 "limbaj.tab.c"
    break;

  case 51: /* bool_expr: bool_expr AND bool_expr  */
#line 489 "limbaj.y"
                              {
        (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::BOOL_OPERATOR, "bool", "AND", 
        static_cast<ASTNode*>((yyvsp[-2].node)), static_cast<ASTNode*>((yyvsp[0].node))));
    }
#line 1837 "limbaj.tab.c"
    break;

  case 52: /* bool_expr: '!' bool_expr  */
#line 493 "limbaj.y"
                    {
        (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::BOOL_OPERATOR, "bool", "!", 
        nullptr, static_cast<ASTNode*>((yyvsp[0].node))));
    }
#line 1846 "limbaj.tab.c"
    break;

  case 53: /* bool_expr: '(' bool_expr ')'  */
#line 497 "limbaj.y"
                        {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1854 "limbaj.tab.c"
    break;

  case 54: /* bool_expr: BOOL  */
#line 500 "limbaj.y"
           {
        std::string boolValue = ((yyvsp[0].boolean)) ? "true" : "false";
        (yyval.node) = static_cast<void*>(new ASTNode(ASTNode::BOOL_VALUE, "bool", boolValue));
    }
#line 1863 "limbaj.tab.c"
    break;

  case 55: /* $@3: %empty  */
#line 509 "limbaj.y"
                               {
    FunctionSymbol function;
    function.returnType = (yyvsp[-1].string);
    function.name = (yyvsp[0].string);     
    function.parameters = currentParameters;
    std::cout << "PARAMETERS: " << currentParameters.size() << std::endl;
    function.definedInClass = currentScope();
    
    if (endsWithFrame(currentScope())) {
        std::string frameName = extractBeforeFrame(currentScope());
        Frame* framePtr = table.findFrame(frameName);
        if (framePtr) {
            framePtr->addFunctionSymbol(function);
        } else {
            yyerror(("Frame not defined: " + frameName).c_str());
        }
    } else {
        table.addFunctionSymbol(function);
    }

    initParameters();
    enterScope((yyvsp[0].string));
}
#line 1891 "limbaj.tab.c"
    break;

  case 56: /* f_declarations: f_declarations F_START TYPE ID $@3 '(' parameters ')' OPEN_BRACE declarations statements ctrl_statements RETURN F_VALUE ';' CLOSE_BRACE  */
#line 533 "limbaj.y"
                                                                                   {

    // // Search the table
    // std::string functionName = currentScope();
    // FunctionSymbol* func = table.findFunctionSymbol(functionName);
    // if (func) {
    //     func->returnValue = std::string($9);
    // }

    // if (endsWithFrame(currentScope())) {
    //     std::string frameName = extractBeforeFrame(currentScope());
    //     Frame* framePtr = table.findFrame(frameName);
    //     if (framePtr) {
    //         framePtr->;
    //     } else {
    //         yyerror(("Frame not defined: " + frameName).c_str());
    //     }
    // } else {
    //     table.addFunctionSymbol(function);
    // }

    leaveScope();
}
#line 1919 "limbaj.tab.c"
    break;

  case 57: /* $@4: %empty  */
#line 556 "limbaj.y"
                  {
    FunctionSymbol function;
    function.returnType = (yyvsp[-1].string);
    function.name = (yyvsp[0].string);
    function.parameters = currentParameters;
    std::cout << "PARAMETERS: " << currentParameters.size() << std::endl;
    function.definedInClass = currentScope();
    
    if (endsWithFrame(currentScope())) {
        std::string frameName = extractBeforeFrame(currentScope());
        Frame* framePtr = table.findFrame(frameName);
        if (framePtr) {
            framePtr->addFunctionSymbol(function);
        } else {
            yyerror(("Frame not defined: " + frameName).c_str());
        }
    } else {
        table.addFunctionSymbol(function);
    }

    initParameters();
    enterScope((yyvsp[0].string));
}
#line 1947 "limbaj.tab.c"
    break;

  case 58: /* f_declarations: F_START TYPE ID $@4 '(' parameters ')' OPEN_BRACE declarations statements ctrl_statements RETURN F_VALUE ';' CLOSE_BRACE  */
#line 580 "limbaj.y"
{
    
    leaveScope();
}
#line 1956 "limbaj.tab.c"
    break;

  case 70: /* parameter_declaration: TYPE ID  */
#line 595 "limbaj.y"
                                {
    addParameter((yyvsp[-1].string), (yyvsp[0].string));
}
#line 1964 "limbaj.tab.c"
    break;

  case 82: /* predifined_functions: EVAL '(' expr ')' ';'  */
#line 614 "limbaj.y"
                                             {
    std::cout << "Evaluated expression value: " << static_cast<ASTNode*>((yyvsp[-2].node))->evaluate(table) <<
    " At line: " << yylineno << std::endl;
}
#line 1973 "limbaj.tab.c"
    break;

  case 83: /* predifined_functions: TYPEOF '(' expr ')' ';'  */
#line 618 "limbaj.y"
                          {
    std::cout << "Type of expression: " << static_cast<ASTNode*>((yyvsp[-2].node))->varType <<
    " At line: " << yylineno << std::endl;
}
#line 1982 "limbaj.tab.c"
    break;

  case 84: /* statement: ID ASSIGN expr  */
#line 624 "limbaj.y"
                          {
    Symbol* sym = nullptr;
    if (endsWithFrame(currentScope())) {
        std::string frameName = extractBeforeFrame(currentScope());
        Frame* framePtr = table.findFrame(frameName);
        if (framePtr) {
            sym = framePtr->findSymbol((yyvsp[-2].string));
        }
        if (sym == nullptr) {
            yyerror(("Variable not defined in frame: " + std::string((yyvsp[-2].string))).c_str());
        }
    } else {
        sym = table.findSymbol((yyvsp[-2].string));
        if (sym == nullptr) {
            yyerror(("Variable not defined: " + std::string((yyvsp[-2].string))).c_str());
        }
    }

    if (sym != nullptr) {
        ASTNode* exprNode = static_cast<ASTNode*>((yyvsp[0].node));
        if (exprNode != nullptr) {
            double result = exprNode->evaluate(table);
            std::cout << "Value of " << std::string((yyvsp[-2].string)) << ": " << result << std::endl;
            if (sym->type != exprNode->varType) {
                yyerror(("Type mismatch in assignment. L-type:" + sym->type +
                " R-type:" + exprNode->varType).c_str());
            }
            else if (sym->isConstant) {
                yyerror(("Cannot assign to constant variable: " + sym->name).c_str());
            }
            else {
                sym->value = std::to_string(result);
            }
        } else {
            yyerror("Invalid expression.");
        }
    }
}
#line 2025 "limbaj.tab.c"
    break;

  case 85: /* statement: ID '(' call_list ')'  */
#line 743 "limbaj.y"
                       {
    FunctionSymbol* sym = table.findFunctionSymbol((yyvsp[-3].string));
    if (sym == nullptr) {
        yyerror(("Function not defined: " + std::string((yyvsp[-3].string))).c_str());
    }
    else {
        std::vector<std::string> argTypes = splitTypes((yyvsp[-1].string)); 
        if (sym->parameters.size() != argTypes.size()) {
            yyerror(("Incorrect number of arguments in function '" + sym->name + "' call.").c_str());
        } else {
            for (size_t i = 0; i < argTypes.size(); ++i) {
                if (argTypes[i] != sym->parameters[i].type) {
                    yyerror("Type mismatch in function call arguments.");
                    break;
                }

                // Get the value of the function 

            }
        }
    }
    free((yyvsp[-1].string)); 
}
#line 2053 "limbaj.tab.c"
    break;

  case 86: /* field_access: ID '.' ID ';'  */
#line 768 "limbaj.y"
                            {
    Frame* frame = table.findFrame((yyvsp[-3].string));
    if (frame == nullptr) {
        yyerror(("Frame not defined: " + std::string((yyvsp[-3].string))).c_str());
    } else {
        Symbol* sym = frame->findSymbol((yyvsp[-1].string));
        if (sym == nullptr) {
            yyerror(("Symbol not defined in frame '" + std::string((yyvsp[-3].string)) + "': " + std::string((yyvsp[-1].string))).c_str());
        } else {
            // Do I just want to suport this or should this actually do something?
        }
    }
}
#line 2071 "limbaj.tab.c"
    break;

  case 87: /* method_call: ID '.' ID '(' call_list ')' ';'  */
#line 784 "limbaj.y"
                                    {
        Frame* frame = table.findFrame((yyvsp[-6].string));
        if (frame == nullptr) {
            yyerror(("Frame not defined: " + std::string((yyvsp[-6].string))).c_str());
        } else {
            FunctionSymbol* sym = frame->findFunctionSymbol((yyvsp[-4].string));
            if (sym == nullptr) {
                yyerror(("Method not defined in frame '" + std::string((yyvsp[-6].string)) + "': " + std::string((yyvsp[-4].string))).c_str());
            } else {
                std::cout << "METHOD ARGS: " << std::string((yyvsp[-2].string)) << std::endl;
                std::vector<std::string> argTypes = splitTypes((yyvsp[-2].string)); 
                if (sym->parameters.size() != argTypes.size()) {
                    std::cout << "ARG COUNT: " << sym->parameters.size() << std::endl;
                    yyerror(("Incorrect number of arguments in method '" + sym->name + "' call.").c_str());
                } else {
                    for (size_t i = 0; i < argTypes.size(); ++i) {
                        if (argTypes[i] != sym->parameters[i].type) {
                            yyerror("Type mismatch in method call arguments.");
                            break;
                        }
                    }
                    // Get the value of the method
                }
            }
        }
        free((yyvsp[-2].string)); 
    }
#line 2103 "limbaj.tab.c"
    break;

  case 88: /* method_call: ID '.' ID '(' ')' ';'  */
#line 811 "limbaj.y"
                        {
        Frame* frame = table.findFrame((yyvsp[-5].string));
        if (frame == nullptr) {
            yyerror(("Frame not defined: " + std::string((yyvsp[-5].string))).c_str());
        } else {
            FunctionSymbol* sym = frame->findFunctionSymbol((yyvsp[-3].string));
            if (sym == nullptr) {
                yyerror(("Method not defined in frame '" + std::string((yyvsp[-5].string)) + "': " + std::string((yyvsp[-3].string))).c_str());
            } else if (!sym->parameters.empty()) {
                yyerror(("Method '" + sym->name + "' expects arguments.").c_str());
            }
        }
    }
#line 2121 "limbaj.tab.c"
    break;

  case 89: /* call_arguments: ID  */
#line 827 "limbaj.y"
       {
        Symbol* sym = table.findSymbol((yyvsp[0].string));
        if (sym != nullptr) {
            (yyval.string) = strdup(sym->type.c_str());
        }
    }
#line 2132 "limbaj.tab.c"
    break;

  case 90: /* call_arguments: NR  */
#line 833 "limbaj.y"
         { (yyval.string) = strdup("int"); }
#line 2138 "limbaj.tab.c"
    break;

  case 91: /* call_arguments: FLOAT  */
#line 834 "limbaj.y"
            { (yyval.string) = strdup("float"); }
#line 2144 "limbaj.tab.c"
    break;

  case 92: /* call_arguments: BOOL  */
#line 835 "limbaj.y"
           { (yyval.string) = strdup("bool"); }
#line 2150 "limbaj.tab.c"
    break;

  case 93: /* call_arguments: STRING  */
#line 836 "limbaj.y"
             { (yyval.string) = strdup("string"); }
#line 2156 "limbaj.tab.c"
    break;

  case 94: /* call_arguments: CHAR  */
#line 837 "limbaj.y"
           { (yyval.string) = strdup("char"); }
#line 2162 "limbaj.tab.c"
    break;

  case 95: /* call_list: call_arguments  */
#line 841 "limbaj.y"
                   {
        (yyval.string) = (yyvsp[0].string); 
    }
#line 2170 "limbaj.tab.c"
    break;

  case 96: /* call_list: call_list ',' call_arguments  */
#line 844 "limbaj.y"
                                   {
        char* types = new char[strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 2]; // +2 for space and '\0'
        strcpy(types, (yyvsp[-2].string));
        strcat(types, " ");
        strcat(types, (yyvsp[0].string));
        (yyval.string) = types;
        free((yyvsp[-2].string)); 
        free((yyvsp[0].string));
    }
#line 2184 "limbaj.tab.c"
    break;


#line 2188 "limbaj.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 854 "limbaj.y"

void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}
extern void* root;
int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
     table.printToFile("table.txt");
}
