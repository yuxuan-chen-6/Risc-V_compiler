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
#line 1 "src/parser.y"

  #include "../include/ast.hpp"
  #include <cassert>
  #include <iostream>
  #include <string>
  #include <vector>
  using namespace std;
  extern Node *g_root; // A way of getting the AST out
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 86 "src/parser.tab.cpp"

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

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_SIZEOF = 6,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 7,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 8,                     /* INC_OP  */
  YYSYMBOL_DEC_OP = 9,                     /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 10,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 11,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 13,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 16,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 17,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 18,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 19,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 20,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 21,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 22,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 23,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 24,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 25,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 26,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 27,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPE_NAME = 28,                 /* TYPE_NAME  */
  YYSYMBOL_TYPEDEF = 29,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 30,                    /* EXTERN  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_AUTO = 32,                      /* AUTO  */
  YYSYMBOL_REGISTER = 33,                  /* REGISTER  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_SHORT = 35,                     /* SHORT  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_LONG = 37,                      /* LONG  */
  YYSYMBOL_SIGNED = 38,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 39,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 41,                    /* DOUBLE  */
  YYSYMBOL_CONST = 42,                     /* CONST  */
  YYSYMBOL_VOLATILE = 43,                  /* VOLATILE  */
  YYSYMBOL_VOID = 44,                      /* VOID  */
  YYSYMBOL_STRUCT = 45,                    /* STRUCT  */
  YYSYMBOL_UNION = 46,                     /* UNION  */
  YYSYMBOL_ENUM = 47,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 48,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 49,                      /* CASE  */
  YYSYMBOL_DEFAULT = 50,                   /* DEFAULT  */
  YYSYMBOL_IF = 51,                        /* IF  */
  YYSYMBOL_ELSE = 52,                      /* ELSE  */
  YYSYMBOL_SWITCH = 53,                    /* SWITCH  */
  YYSYMBOL_WHILE = 54,                     /* WHILE  */
  YYSYMBOL_DO = 55,                        /* DO  */
  YYSYMBOL_FOR = 56,                       /* FOR  */
  YYSYMBOL_GOTO = 57,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 58,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 59,                     /* BREAK  */
  YYSYMBOL_RETURN = 60,                    /* RETURN  */
  YYSYMBOL_61_ = 61,                       /* ';'  */
  YYSYMBOL_62_ = 62,                       /* '('  */
  YYSYMBOL_63_ = 63,                       /* ')'  */
  YYSYMBOL_64_ = 64,                       /* '{'  */
  YYSYMBOL_65_ = 65,                       /* '}'  */
  YYSYMBOL_66_ = 66,                       /* '='  */
  YYSYMBOL_67_ = 67,                       /* '+'  */
  YYSYMBOL_68_ = 68,                       /* '['  */
  YYSYMBOL_69_ = 69,                       /* ']'  */
  YYSYMBOL_70_ = 70,                       /* ','  */
  YYSYMBOL_71_ = 71,                       /* '-'  */
  YYSYMBOL_72_ = 72,                       /* '*'  */
  YYSYMBOL_73_ = 73,                       /* '/'  */
  YYSYMBOL_74_ = 74,                       /* '<'  */
  YYSYMBOL_75_ = 75,                       /* '&'  */
  YYSYMBOL_76_ = 76,                       /* '|'  */
  YYSYMBOL_77_ = 77,                       /* '^'  */
  YYSYMBOL_78_ = 78,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_ROOT = 80,                      /* ROOT  */
  YYSYMBOL_type_specifier = 81,            /* type_specifier  */
  YYSYMBOL_jump_statement = 82,            /* jump_statement  */
  YYSYMBOL_statement = 83,                 /* statement  */
  YYSYMBOL_for_statement = 84,             /* for_statement  */
  YYSYMBOL_for_expression = 85,            /* for_expression  */
  YYSYMBOL_while_statement = 86,           /* while_statement  */
  YYSYMBOL_if_statement = 87,              /* if_statement  */
  YYSYMBOL_compound_statement = 88,        /* compound_statement  */
  YYSYMBOL_statement_list = 89,            /* statement_list  */
  YYSYMBOL_expression_statement = 90,      /* expression_statement  */
  YYSYMBOL_parameter_list = 91,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 92,     /* parameter_declaration  */
  YYSYMBOL_function_definition = 93,       /* function_definition  */
  YYSYMBOL_program = 94,                   /* program  */
  YYSYMBOL_arithmetic_expression = 95,     /* arithmetic_expression  */
  YYSYMBOL_term = 96,                      /* term  */
  YYSYMBOL_factor = 97,                    /* factor  */
  YYSYMBOL_return_parameter = 98           /* return_parameter  */
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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
       2,     2,     2,     2,     2,     2,     2,     2,    75,     2,
      62,    63,    72,    67,    70,    71,     2,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
      74,    66,    78,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    76,    65,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    62,    66,    67,    68,    69,    70,    71,
      75,    76,    80,    81,    85,    86,    90,    91,    95,    99,
     100,   105,   107,   108,   110,   111,   115,   116,   120,   125,
     126,   127,   128,   133,   134,   135,   139,   140,   141,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   160,   161,   162,   163,   164,   165,   166,   167,   171,
     172
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "';'", "'('", "')'",
  "'{'", "'}'", "'='", "'+'", "'['", "']'", "','", "'-'", "'*'", "'/'",
  "'<'", "'&'", "'|'", "'^'", "'>'", "$accept", "ROOT", "type_specifier",
  "jump_statement", "statement", "for_statement", "for_expression",
  "while_statement", "if_statement", "compound_statement",
  "statement_list", "expression_statement", "parameter_list",
  "parameter_declaration", "function_definition", "program",
  "arithmetic_expression", "term", "factor", "return_parameter", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     169,    -3,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -29,   -27,   -10,    20,   169,    53,    64,   -90,
     -90,   -90,   -90,   -90,   -90,   169,   -90,   -90,   290,    20,
      20,    20,    20,   247,    -2,   -90,    14,    20,   -12,    -4,
     -90,    78,    51,   -90,    35,   -90,   -90,    95,   -90,    39,
      70,    83,   112,    20,    58,    20,   262,   122,   -90,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,   -59,   -90,   -90,   276,    20,   113,    37,   -90,
      56,   169,   208,    47,   -90,   -90,   -49,    90,    60,    75,
     -90,    -4,    -4,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,    48,   133,   -33,   -90,    73,    79,
      20,   100,    91,   -90,   159,   -90,    20,   -90,   -90,   -90,
     -90,   -90,   -90,    99,   290,   -90,   115,    82,   169,   -90,
     107,   114,   -90,   -90,   -90,   -90,   -90,   -90,   -90,    16,
     116,   111,   -35,   130,   -90,   -90,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    12,     4,     5,     6,     8,    11,     7,     9,
      10,     3,     0,     0,     0,     0,     0,     0,     0,    15,
      29,    19,    18,    17,    16,     0,    14,    43,     2,     0,
       0,     0,     0,     0,    62,    63,     0,     0,     0,    48,
      60,     0,     0,     1,     0,    30,    44,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    32,     0,     0,     0,     0,    33,
       0,     0,     0,     0,    67,    70,     0,     0,     0,     0,
      61,    46,    47,    52,    53,    57,    58,    49,    50,    51,
      54,    55,    56,    59,     0,     0,     0,    36,     0,     0,
       0,    26,     0,    24,     0,    68,     0,    64,    65,    66,
      41,    39,    38,     0,     0,    31,     0,     0,     0,    25,
       0,     0,    69,    42,    40,    37,    34,    35,    27,     0,
       0,     0,    22,     0,    20,    23,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,     0,   -90,   -24,   -90,   -90,   -90,   -90,   -89,
     182,   154,   -90,    67,    52,   -90,   -26,   -43,   -23,   -90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    17,    41,    19,    20,    21,   131,    22,    23,    24,
      42,    26,   106,   107,    27,    28,    38,    39,    40,    86
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      18,    45,    74,    49,    50,    51,    52,    76,    61,    77,
      62,    57,    63,    64,   115,   121,    91,    92,    45,    34,
      35,   116,    36,    34,    35,    18,    36,    83,    47,    87,
     123,    85,    59,    31,   134,    32,    60,   124,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    58,
     108,   144,    33,    43,     1,    59,    89,   111,   113,    60,
      54,    34,    35,    29,    36,    30,    55,    44,    65,    66,
      67,    68,    69,    70,    71,   105,    56,    46,    37,     2,
      48,    72,    37,   141,   127,     3,     4,     5,     6,     7,
       8,     9,    10,   132,     1,    11,    74,    75,    78,    75,
      79,    76,    12,    77,   138,    13,    59,    14,   114,   120,
      60,    15,    16,   142,    59,    16,    73,   109,    60,     2,
      37,    84,   110,   118,   105,     3,     4,     5,     6,     7,
       8,     9,    10,     1,   125,    11,   122,    59,   119,    80,
      59,    60,    12,   137,    60,    13,    81,    14,   126,    59,
      59,    15,   128,    60,    60,    16,   129,    59,     2,   117,
     133,    60,   130,    16,     3,     4,     5,     6,     7,     8,
       9,    10,     1,   139,    11,    82,   136,   140,   145,    59,
     143,    12,    25,    60,    13,    90,    14,    53,     0,    59,
      15,   135,     0,    60,    16,   146,     0,     2,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     1,     0,    11,     0,     0,     0,     0,     0,     0,
      12,     0,     0,    13,     0,    14,     0,     0,     0,    15,
       0,     0,     0,    16,     0,     0,     2,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       1,     0,    11,     0,     0,     0,     0,     0,     0,    12,
       0,     0,    13,     0,    14,    88,     0,     0,    15,     0,
       0,     0,   112,     0,     0,     2,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
       2,    11,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     2,     0,    11,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     2,     0,
      11,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,     0,    11,     0,     0,     0,     0,   104
};

static const yytype_int16 yycheck[] =
{
       0,    25,    61,    29,    30,    31,    32,    66,    12,    68,
      14,    37,    16,    17,    63,   104,    59,    60,    42,     3,
       4,    70,     6,     3,     4,    25,     6,    53,    28,    55,
      63,    54,    67,    62,   123,    62,    71,    70,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    61,
      76,   140,    62,     0,     3,    67,    56,    81,    82,    71,
      62,     3,     4,    66,     6,    68,    68,     3,    72,    73,
      74,    75,    76,    77,    78,    75,    62,    25,    62,    28,
      28,     3,    62,    67,   110,    34,    35,    36,    37,    38,
      39,    40,    41,   116,     3,    44,    61,    62,     3,    62,
      61,    66,    51,    68,   128,    54,    67,    56,    61,    61,
      71,    60,    64,   139,    67,    64,    65,     4,    71,    28,
      62,    63,    66,    63,   124,    34,    35,    36,    37,    38,
      39,    40,    41,     3,    61,    44,     3,    67,    63,    69,
      67,    71,    51,    61,    71,    54,    63,    56,    69,    67,
      67,    60,    52,    71,    71,    64,    65,    67,    28,    69,
      61,    71,     3,    64,    34,    35,    36,    37,    38,    39,
      40,    41,     3,    66,    44,    63,    61,    63,    67,    67,
      64,    51,     0,    71,    54,    63,    56,    33,    -1,    67,
      60,   124,    -1,    71,    64,    65,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,     3,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    54,    -1,    56,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
       3,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    -1,    56,     3,    -1,    -1,    60,    -1,
      -1,    -1,    64,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      28,    44,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    28,    -1,    44,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    28,    -1,
      44,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    28,    34,    35,    36,    37,    38,    39,    40,
      41,    44,    51,    54,    56,    60,    64,    80,    81,    82,
      83,    84,    86,    87,    88,    89,    90,    93,    94,    66,
      68,    62,    62,    62,     3,     4,     6,    62,    95,    96,
      97,    81,    89,     0,     3,    83,    93,    81,    93,    95,
      95,    95,    95,    90,    62,    68,    62,    95,    61,    67,
      71,    12,    14,    16,    17,    72,    73,    74,    75,    76,
      77,    78,     3,    65,    61,    62,    66,    68,     3,    61,
      69,    63,    63,    95,    63,    97,    98,    95,     3,    81,
      63,    96,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    63,    81,    91,    92,    95,     4,
      66,    83,    64,    83,    61,    63,    70,    69,    63,    63,
      61,    88,     3,    63,    70,    61,    69,    95,    52,    65,
       3,    85,    97,    61,    88,    92,    61,    61,    83,    66,
      63,    67,    95,    64,    88,    67,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    79,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    82,    83,    83,    83,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    89,
      89,    90,    90,    90,    90,    90,    91,    91,    92,    93,
      93,    93,    93,    94,    94,    94,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       8,     9,     3,     4,     5,     6,     5,     7,     3,     1,
       2,     5,     3,     4,     6,     7,     1,     3,     2,     5,
       6,     5,     6,     1,     2,     2,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     1,     4,     4,     4,     3,     4,     3,
       1
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
  case 2: /* ROOT: program  */
#line 43 "src/parser.y"
               { std::cout<<"start"<<std::endl; g_root = (yyvsp[0].expr); }
#line 1309 "src/parser.tab.cpp"
    break;

  case 3: /* type_specifier: VOID  */
#line 48 "src/parser.y"
                         { (yyval.string) = new std::string("void"); }
#line 1315 "src/parser.tab.cpp"
    break;

  case 4: /* type_specifier: CHAR  */
#line 49 "src/parser.y"
                         { (yyval.string) = new std::string("char"); }
#line 1321 "src/parser.tab.cpp"
    break;

  case 5: /* type_specifier: SHORT  */
#line 50 "src/parser.y"
                         { (yyval.string) = new std::string("short"); }
#line 1327 "src/parser.tab.cpp"
    break;

  case 6: /* type_specifier: INT  */
#line 51 "src/parser.y"
                         { (yyval.string) = new std::string("int"); }
#line 1333 "src/parser.tab.cpp"
    break;

  case 7: /* type_specifier: UNSIGNED  */
#line 52 "src/parser.y"
                         { (yyval.string) = new std::string("unsigned"); }
#line 1339 "src/parser.tab.cpp"
    break;

  case 8: /* type_specifier: LONG  */
#line 53 "src/parser.y"
                         { (yyval.string) = new std::string("long"); }
#line 1345 "src/parser.tab.cpp"
    break;

  case 9: /* type_specifier: FLOAT  */
#line 54 "src/parser.y"
                         { (yyval.string) = new std::string("float"); }
#line 1351 "src/parser.tab.cpp"
    break;

  case 10: /* type_specifier: DOUBLE  */
#line 55 "src/parser.y"
                         { (yyval.string) = new std::string("double"); }
#line 1357 "src/parser.tab.cpp"
    break;

  case 11: /* type_specifier: SIGNED  */
#line 56 "src/parser.y"
                         { (yyval.string) = new std::string("signed"); }
#line 1363 "src/parser.tab.cpp"
    break;

  case 12: /* type_specifier: TYPE_NAME  */
#line 57 "src/parser.y"
                         { (yyval.string) = new std::string("type_name"); }
#line 1369 "src/parser.tab.cpp"
    break;

  case 13: /* jump_statement: RETURN arithmetic_expression ';'  */
#line 62 "src/parser.y"
                                           { (yyval.expr) = new ReturnStatement((yyvsp[-1].expr)); cout<<"return"<<endl; }
#line 1375 "src/parser.tab.cpp"
    break;

  case 14: /* statement: expression_statement  */
#line 66 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); cout<<"expression"<<endl; }
#line 1381 "src/parser.tab.cpp"
    break;

  case 15: /* statement: jump_statement  */
#line 67 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); cout<<"jump"<<endl; }
#line 1387 "src/parser.tab.cpp"
    break;

  case 16: /* statement: compound_statement  */
#line 68 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1393 "src/parser.tab.cpp"
    break;

  case 17: /* statement: if_statement  */
#line 69 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1399 "src/parser.tab.cpp"
    break;

  case 18: /* statement: while_statement  */
#line 70 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1405 "src/parser.tab.cpp"
    break;

  case 19: /* statement: for_statement  */
#line 71 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1411 "src/parser.tab.cpp"
    break;

  case 20: /* for_statement: FOR '(' expression_statement arithmetic_expression ';' for_expression ')' compound_statement  */
#line 75 "src/parser.y"
                                                                                                       { (yyval.expr) = new ForStatement((yyvsp[-5].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); cout<<"for"<<endl; }
#line 1417 "src/parser.tab.cpp"
    break;

  case 21: /* for_statement: FOR '(' expression_statement arithmetic_expression ';' for_expression ')' '{' '}'  */
#line 76 "src/parser.y"
                                                                                           { (yyval.expr) = new ForStatement((yyvsp[-6].expr), (yyvsp[-5].expr), (yyvsp[-3].expr), NULL); cout<<"for"<<endl; }
#line 1423 "src/parser.tab.cpp"
    break;

  case 22: /* for_expression: IDENTIFIER '=' arithmetic_expression  */
#line 80 "src/parser.y"
                                               { (yyval.expr) = new ExpressionStatement(*(yyvsp[-2].string),(yyvsp[0].expr)); cout<<"for"<<endl; }
#line 1429 "src/parser.tab.cpp"
    break;

  case 23: /* for_expression: IDENTIFIER '=' '+' '+'  */
#line 81 "src/parser.y"
                                { (yyval.expr) = new Variable(*(yyvsp[-3].string)); cout<<"for"<<endl; }
#line 1435 "src/parser.tab.cpp"
    break;

  case 24: /* while_statement: WHILE '(' arithmetic_expression ')' statement  */
#line 85 "src/parser.y"
                                                        { (yyval.expr) = new WhileStatement((yyvsp[-2].expr), (yyvsp[0].expr)); cout<<"while"<<endl; }
#line 1441 "src/parser.tab.cpp"
    break;

  case 25: /* while_statement: WHILE '(' arithmetic_expression ')' '{' '}'  */
#line 86 "src/parser.y"
                                                     { (yyval.expr) = new WhileStatement((yyvsp[-3].expr), NULL); cout<<"while"<<endl; }
#line 1447 "src/parser.tab.cpp"
    break;

  case 26: /* if_statement: IF '(' arithmetic_expression ')' statement  */
#line 90 "src/parser.y"
                                                     { (yyval.expr) = new IfStatement((yyvsp[-2].expr), (yyvsp[0].expr), NULL); cout<<"if"<<endl; }
#line 1453 "src/parser.tab.cpp"
    break;

  case 27: /* if_statement: IF '(' arithmetic_expression ')' statement ELSE statement  */
#line 91 "src/parser.y"
                                                                    { (yyval.expr) = new IfStatement((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); cout<<"if"<<endl; }
#line 1459 "src/parser.tab.cpp"
    break;

  case 28: /* compound_statement: '{' statement_list '}'  */
#line 95 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[-1].expr); cout<<"compound"<<endl; }
#line 1465 "src/parser.tab.cpp"
    break;

  case 29: /* statement_list: statement  */
#line 99 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr);  cout<<"statement"<<endl;}
#line 1471 "src/parser.tab.cpp"
    break;

  case 30: /* statement_list: statement_list statement  */
#line 100 "src/parser.y"
                                        { (yyval.expr) = new StatementList((yyvsp[-1].expr),(yyvsp[0].expr)); cout<<"statement_list"<<endl;}
#line 1477 "src/parser.tab.cpp"
    break;

  case 31: /* expression_statement: type_specifier IDENTIFIER '=' arithmetic_expression ';'  */
#line 105 "src/parser.y"
                                                                  { cout<<"assignment1"<<endl; (yyval.expr) = new ExpressionStatement(*(yyvsp[-3].string),(yyvsp[-1].expr)); }
#line 1483 "src/parser.tab.cpp"
    break;

  case 32: /* expression_statement: type_specifier IDENTIFIER ';'  */
#line 107 "src/parser.y"
                                        { cout<<"assignment"<<endl; (yyval.expr) = new Variable(*(yyvsp[-2].string), *(yyvsp[-1].string)); }
#line 1489 "src/parser.tab.cpp"
    break;

  case 33: /* expression_statement: IDENTIFIER '=' arithmetic_expression ';'  */
#line 108 "src/parser.y"
                                                   { cout<<"assignment"<<endl; (yyval.expr) = new ExpressionStatement(*(yyvsp[-3].string),(yyvsp[-1].expr)); }
#line 1495 "src/parser.tab.cpp"
    break;

  case 34: /* expression_statement: type_specifier IDENTIFIER '[' CONSTANT ']' ';'  */
#line 110 "src/parser.y"
                                                        { cout<<"assignment"<<endl; (yyval.expr) = new ArrayDec(*(yyvsp[-4].string), (yyvsp[-2].number)); }
#line 1501 "src/parser.tab.cpp"
    break;

  case 35: /* expression_statement: IDENTIFIER '[' arithmetic_expression ']' '=' arithmetic_expression ';'  */
#line 111 "src/parser.y"
                                                                                 { cout<<"assignment"<<endl; (yyval.expr) = new ArrayAssignments(*(yyvsp[-6].string), (yyvsp[-4].expr), (yyvsp[-1].expr)); }
#line 1507 "src/parser.tab.cpp"
    break;

  case 36: /* parameter_list: parameter_declaration  */
#line 115 "src/parser.y"
                                {std::cout<<"dectected"<<std::endl; (yyval.expr) = (yyvsp[0].expr);  }
#line 1513 "src/parser.tab.cpp"
    break;

  case 37: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 116 "src/parser.y"
                                                   {std::cout<<"dectected"<<std::endl; (yyval.expr)= new ParameterList((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1519 "src/parser.tab.cpp"
    break;

  case 38: /* parameter_declaration: type_specifier IDENTIFIER  */
#line 120 "src/parser.y"
                                    { std::cout<<"parameter"<<std::endl; (yyval.expr)=new Variable(*(yyvsp[-1].string), *(yyvsp[0].string));  }
#line 1525 "src/parser.tab.cpp"
    break;

  case 39: /* function_definition: type_specifier IDENTIFIER '(' ')' compound_statement  */
#line 125 "src/parser.y"
                                                               {std::cout<<"dectected"<<std::endl; (yyval.expr) = new FunctionDefinition((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[0].expr));}
#line 1531 "src/parser.tab.cpp"
    break;

  case 40: /* function_definition: type_specifier IDENTIFIER '(' parameter_list ')' compound_statement  */
#line 126 "src/parser.y"
                                                                              {std::cout<<"dectected"<<std::endl; (yyval.expr) = new FunctionDefinition((yyvsp[-5].string), (yyvsp[-4].string), (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1537 "src/parser.tab.cpp"
    break;

  case 41: /* function_definition: type_specifier IDENTIFIER '(' ')' ';'  */
#line 127 "src/parser.y"
                                               {std::cout<<"dectected"<<std::endl; (yyval.expr) = new FunctionDefinition((yyvsp[-4].string), (yyvsp[-3].string),NULL);}
#line 1543 "src/parser.tab.cpp"
    break;

  case 42: /* function_definition: type_specifier IDENTIFIER '(' parameter_list ')' ';'  */
#line 128 "src/parser.y"
                                                              {std::cout<<"dectected"<<std::endl; (yyval.expr) = new FunctionDefinition((yyvsp[-5].string), (yyvsp[-4].string), (yyvsp[-2].expr), NULL);}
#line 1549 "src/parser.tab.cpp"
    break;

  case 43: /* program: function_definition  */
#line 133 "src/parser.y"
                              { std::cout<<"dectected"<<std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 1555 "src/parser.tab.cpp"
    break;

  case 44: /* program: statement_list function_definition  */
#line 134 "src/parser.y"
                                             { std::cout<<"dectected"<<std::endl; (yyval.expr) = new Program((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 1561 "src/parser.tab.cpp"
    break;

  case 45: /* program: program function_definition  */
#line 135 "src/parser.y"
                                      { std::cout<<"dectected"<<std::endl; (yyval.expr) = new Program((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 1567 "src/parser.tab.cpp"
    break;

  case 46: /* arithmetic_expression: arithmetic_expression '+' term  */
#line 139 "src/parser.y"
                                         { std::cout<< "add operator"<< std::endl; (yyval.expr) = new AddOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1573 "src/parser.tab.cpp"
    break;

  case 47: /* arithmetic_expression: arithmetic_expression '-' term  */
#line 140 "src/parser.y"
                                         { std::cout<< "sub operator"<< std::endl; (yyval.expr) = new SubOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1579 "src/parser.tab.cpp"
    break;

  case 48: /* arithmetic_expression: term  */
#line 141 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 1585 "src/parser.tab.cpp"
    break;

  case 49: /* term: term '*' factor  */
#line 145 "src/parser.y"
                          { std::cout<< "mul operator"<< std::endl; (yyval.expr) = new MulOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1591 "src/parser.tab.cpp"
    break;

  case 50: /* term: term '/' factor  */
#line 146 "src/parser.y"
                          { std::cout<< "div operator"<< std::endl; (yyval.expr) = new DivOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1597 "src/parser.tab.cpp"
    break;

  case 51: /* term: term '<' factor  */
#line 147 "src/parser.y"
                          { std::cout<< "less operator"<< std::endl; (yyval.expr) = new LessOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1603 "src/parser.tab.cpp"
    break;

  case 52: /* term: term LE_OP factor  */
#line 148 "src/parser.y"
                            { std::cout<< "less equal operator"<< std::endl; (yyval.expr) = new LessEqualOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1609 "src/parser.tab.cpp"
    break;

  case 53: /* term: term EQ_OP factor  */
#line 149 "src/parser.y"
                            { std::cout<< "euqal operator"<< std::endl; (yyval.expr) = new equalOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1615 "src/parser.tab.cpp"
    break;

  case 54: /* term: term '&' factor  */
#line 150 "src/parser.y"
                          { std::cout<< "and operator"<< std::endl; (yyval.expr) = new AndOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1621 "src/parser.tab.cpp"
    break;

  case 55: /* term: term '|' factor  */
#line 151 "src/parser.y"
                          { std::cout<< "or operator"<< std::endl; (yyval.expr) = new OrOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1627 "src/parser.tab.cpp"
    break;

  case 56: /* term: term '^' factor  */
#line 152 "src/parser.y"
                          { std::cout<< "xor operator"<< std::endl; (yyval.expr) = new XorOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1633 "src/parser.tab.cpp"
    break;

  case 57: /* term: term AND_OP factor  */
#line 153 "src/parser.y"
                             { std::cout<< "log_and operator"<< std::endl; (yyval.expr) = new LogicalAndOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1639 "src/parser.tab.cpp"
    break;

  case 58: /* term: term OR_OP factor  */
#line 154 "src/parser.y"
                            { std::cout<< "log_or operator"<< std::endl; (yyval.expr) = new LogicalOrOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1645 "src/parser.tab.cpp"
    break;

  case 59: /* term: term '>' factor  */
#line 155 "src/parser.y"
                          { std::cout<< "greater operator"<< std::endl; (yyval.expr) = new GreaterThanOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1651 "src/parser.tab.cpp"
    break;

  case 60: /* term: factor  */
#line 156 "src/parser.y"
                 {std::cout<< "factor"<< std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 1657 "src/parser.tab.cpp"
    break;

  case 61: /* factor: '(' arithmetic_expression ')'  */
#line 160 "src/parser.y"
                                        {std::cout<< "add operator"<< std::endl; (yyval.expr) = (yyvsp[-1].expr); }
#line 1663 "src/parser.tab.cpp"
    break;

  case 62: /* factor: IDENTIFIER  */
#line 161 "src/parser.y"
                     {std::cout<< "variabler"<< std::endl; (yyval.expr) = new Variable(*(yyvsp[0].string)); }
#line 1669 "src/parser.tab.cpp"
    break;

  case 63: /* factor: CONSTANT  */
#line 162 "src/parser.y"
                   {std::cout<< "constant"<< std::endl; (yyval.expr) = new Integer((yyvsp[0].number)); }
#line 1675 "src/parser.tab.cpp"
    break;

  case 64: /* factor: IDENTIFIER '[' arithmetic_expression ']'  */
#line 163 "src/parser.y"
                                                   {std::cout<< "array"<< std::endl; (yyval.expr) = new ArrayAccess(*(yyvsp[-3].string), (yyvsp[-1].expr)); }
#line 1681 "src/parser.tab.cpp"
    break;

  case 65: /* factor: SIZEOF '(' IDENTIFIER ')'  */
#line 164 "src/parser.y"
                                    {std::cout<< "sizeof"<< std::endl; (yyval.expr) = new SizeOf(*(yyvsp[-1].string)); }
#line 1687 "src/parser.tab.cpp"
    break;

  case 66: /* factor: SIZEOF '(' type_specifier ')'  */
#line 165 "src/parser.y"
                                        {std::cout<< "sizeof"<< std::endl; (yyval.expr) = new SizeOf(*(yyvsp[-1].string)); }
#line 1693 "src/parser.tab.cpp"
    break;

  case 67: /* factor: IDENTIFIER '(' ')'  */
#line 166 "src/parser.y"
                             {std::cout<< "function call"<< std::endl; (yyval.expr) = new FunctionCall(*(yyvsp[-2].string),NULL); }
#line 1699 "src/parser.tab.cpp"
    break;

  case 68: /* factor: IDENTIFIER '(' return_parameter ')'  */
#line 167 "src/parser.y"
                                             {std::cout<< "function call"<< std::endl; (yyval.expr) = new FunctionCall(*(yyvsp[-3].string),(yyvsp[-1].expr)); }
#line 1705 "src/parser.tab.cpp"
    break;

  case 69: /* return_parameter: return_parameter ',' factor  */
#line 171 "src/parser.y"
                                      {std::cout<< "return parameter"<< std::endl; (yyval.expr) = new ReturnParameter((yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1711 "src/parser.tab.cpp"
    break;

  case 70: /* return_parameter: factor  */
#line 172 "src/parser.y"
                 {std::cout<< "return parameter"<< std::endl; (yyval.expr) = (yyvsp[0].expr); }
#line 1717 "src/parser.tab.cpp"
    break;


#line 1721 "src/parser.tab.cpp"

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

#line 176 "src/parser.y"



Node *g_root;
Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
