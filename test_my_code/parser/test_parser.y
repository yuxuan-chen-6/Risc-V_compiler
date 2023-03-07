%code requires{
  #include "ast.hpp"
  #include <cassert>
  extern const Expression *g_root; // A way of getting the AST out
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}
// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}



%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME
%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <expr> EXPR
%type <string> IDENTIFIER

%start ROOT
%%

ROOT : EXPR { std::cout<<"start"; }

EXPR
	: IDENTIFIER {$$= new Variable(*$1);}
  ;

declaration
	: declaration_specifiers EXPR ';'
	;

declaration_specifiers
	: type_specifier
  | type_specifier declaration_specifiers
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| TYPE_NAME
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

statement
	: compound_statement
	| expression_statement
	| jump_statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'

statement_list
	: statement
	| statement_list statement
	;

expression
	: CONSTANT
	;



expression_statement
	: ';'
	| expression ';'
	;

function_definition
	: direct_declarator compound_statement
	;


direct_declarator
	: IDENTIFIER
	| direct_declarator '[' jump_statement ']'
	| direct_declarator '[' ']'
  | declaration_specifiers direct_declarator
	| direct_declarator '(' ')'
	;

%%


const Expression *g_root;
const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
