%{
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
%}
// Represents the value associated with any kind of
// AST node.
%union{
  NodePtr expr;
  int number;
  std::string *string;
  StatementList *statement_list;
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

%type <expr> function_definition statement expression_statement compound_statement term factor return_parameter
%type <expr> parameter_list parameter_declaration arithmetic_expression jump_statement statement_list program if_statement
%type <expr> while_statement for_statement for_expression
%type <number> CONSTANT
%type <string> IDENTIFIER type_specifier

%start ROOT
%%

ROOT : program { std::cout<<"start"<<std::endl; g_root = $1; }
;


type_specifier
	: VOID		 { $$ = new std::string("void"); }
	| CHAR		 { $$ = new std::string("char"); }
	| SHORT		 { $$ = new std::string("short"); }
	| INT		 { $$ = new std::string("int"); }
	| UNSIGNED	 { $$ = new std::string("unsigned"); }
	| LONG		 { $$ = new std::string("long"); }
	| FLOAT		 { $$ = new std::string("float"); }
	| DOUBLE	 { $$ = new std::string("double"); }
	| SIGNED	 { $$ = new std::string("signed"); }
	| TYPE_NAME	 { $$ = new std::string("type_name"); }
	;


jump_statement
	: RETURN arithmetic_expression ';' { $$ = new ReturnStatement($2); cout<<"return"<<endl; }
	;

statement
	: expression_statement 		{ $$ = $1; cout<<"expression"<<endl; }
	| jump_statement			{ $$ = $1; cout<<"jump"<<endl; }
	| compound_statement		{ $$ = $1; }
	| if_statement				{ $$ = $1; }
	| while_statement			{ $$ = $1; }
	| for_statement				{ $$ = $1; }
	;

for_statement
	: FOR '(' expression_statement arithmetic_expression ';' for_expression ')' compound_statement { $$ = new ForStatement($3, $4, $6, $8); cout<<"for"<<endl; }
	| FOR '(' expression_statement arithmetic_expression ';' for_expression ')' '{''}' { $$ = new ForStatement($3, $4, $6, NULL); cout<<"for"<<endl; }
	;

for_expression
	: IDENTIFIER '=' arithmetic_expression { $$ = new ExpressionStatement(*$1,$3); cout<<"for"<<endl; }
	| IDENTIFIER '=' '+' '+'{ $$ = new Variable(*$1); cout<<"for"<<endl; }
	;

while_statement
	: WHILE '(' arithmetic_expression ')' statement { $$ = new WhileStatement($3, $5); cout<<"while"<<endl; }
	| WHILE '(' arithmetic_expression ')' '{''}' { $$ = new WhileStatement($3, NULL); cout<<"while"<<endl; }
	;

if_statement
	: IF '(' arithmetic_expression ')' statement { $$ = new IfStatement($3, $5, NULL); cout<<"if"<<endl; }
	| IF '(' arithmetic_expression ')' statement ELSE statement { $$ = new IfStatement($3, $5, $7); cout<<"if"<<endl; }
	;

compound_statement
	: '{' statement_list '}'  	{ $$ = $2; cout<<"compound"<<endl; }
	;// '{' '}'

statement_list
	: statement					{ $$ = $1;  cout<<"statement"<<endl;}
	| statement_list statement 	{ $$ = new StatementList($1,$2); cout<<"statement_list"<<endl;}
	;


expression_statement
	: type_specifier IDENTIFIER '=' arithmetic_expression ';' { cout<<"assignment1"<<endl; $$ = new ExpressionStatement(*$2,$4); }
	/* | type_specifier IDENTIFIER '=' CONSTANT ';' { cout<<"assignment"<<endl; $$ = new Variable( *$2,$4); } */
	| type_specifier IDENTIFIER ';' { cout<<"assignment"<<endl; $$ = new Variable(*$1, *$2); }
	| IDENTIFIER '=' arithmetic_expression ';' { cout<<"assignment"<<endl; $$ = new ExpressionStatement(*$1,$3); }
	/* | IDENTIFIER '=' IDENTIFIER ';' { cout<<"assignment"<<endl; $$ = new Variable( *$1, *$3); } */
	| type_specifier IDENTIFIER '[' CONSTANT ']' ';'{ cout<<"assignment"<<endl; $$ = new ArrayDec(*$2, $4); }
	| IDENTIFIER '[' arithmetic_expression ']' '=' arithmetic_expression ';' { cout<<"assignment"<<endl; $$ = new ArrayAssignments(*$1, $3, $6); }
	;

parameter_list
	: parameter_declaration {std::cout<<"dectected"<<std::endl; $$ = $1;  }
	| parameter_list ',' parameter_declaration {std::cout<<"dectected"<<std::endl; $$= new ParameterList($1,$3);}
	;

parameter_declaration
	: type_specifier IDENTIFIER { std::cout<<"parameter"<<std::endl; $$=new Variable(*$1, *$2);  }
	//| parameter_declaration ',' type_specifier IDENTIFIER { $$ = new Variable(*$4); std::cout<<"dectected"<<std::endl; }
	;

function_definition
	: type_specifier IDENTIFIER '(' ')' compound_statement {std::cout<<"dectected"<<std::endl; $$ = new FunctionDefinition($1, $2, $5);}
	| type_specifier IDENTIFIER '(' parameter_list ')' compound_statement {std::cout<<"dectected"<<std::endl; $$ = new FunctionDefinition($1, $2, $4, $6);}
	| type_specifier IDENTIFIER '(' ')'';' {std::cout<<"dectected"<<std::endl; $$ = new FunctionDefinition($1, $2,NULL);}
	| type_specifier IDENTIFIER '(' parameter_list ')' ';'{std::cout<<"dectected"<<std::endl; $$ = new FunctionDefinition($1, $2, $4, NULL);}
	;


program
	: function_definition { std::cout<<"dectected"<<std::endl; $$ = $1; }
	| statement_list function_definition { std::cout<<"dectected"<<std::endl; $$ = new Program($1,$2); }
	| program function_definition { std::cout<<"dectected"<<std::endl; $$ = new Program($1,$2); }
	;

arithmetic_expression
	: arithmetic_expression '+' term { std::cout<< "add operator"<< std::endl; $$ = new AddOperator($1, $3); }
	| arithmetic_expression '-' term { std::cout<< "sub operator"<< std::endl; $$ = new SubOperator($1, $3); }
	| term { $$ = $1; }
	;

term
	: term '*' factor { std::cout<< "mul operator"<< std::endl; $$ = new MulOperator($1, $3); }
	| term '/' factor { std::cout<< "div operator"<< std::endl; $$ = new DivOperator($1, $3); }
	| term '<' factor { std::cout<< "less operator"<< std::endl; $$ = new LessOperator($1, $3); }
	| term LE_OP factor { std::cout<< "less equal operator"<< std::endl; $$ = new LessEqualOperator($1, $3); }
	| term EQ_OP factor { std::cout<< "euqal operator"<< std::endl; $$ = new equalOperator($1, $3); }
	| term '&' factor { std::cout<< "and operator"<< std::endl; $$ = new AndOperator($1, $3); }
	| term '|' factor { std::cout<< "or operator"<< std::endl; $$ = new OrOperator($1, $3); }
	| term '^' factor { std::cout<< "xor operator"<< std::endl; $$ = new XorOperator($1, $3); }
	| term AND_OP factor { std::cout<< "log_and operator"<< std::endl; $$ = new LogicalAndOperator($1, $3); }
	| term OR_OP factor { std::cout<< "log_or operator"<< std::endl; $$ = new LogicalOrOperator($1, $3); }
	| term '>' factor { std::cout<< "greater operator"<< std::endl; $$ = new GreaterThanOperator($1, $3); }
	| factor {std::cout<< "factor"<< std::endl; $$ = $1; }
	;

factor
	: '(' arithmetic_expression ')' {std::cout<< "add operator"<< std::endl; $$ = $2; }
	| IDENTIFIER {std::cout<< "variabler"<< std::endl; $$ = new Variable(*$1); }
	| CONSTANT {std::cout<< "constant"<< std::endl; $$ = new Integer($1); }
	| IDENTIFIER '[' arithmetic_expression ']' {std::cout<< "array"<< std::endl; $$ = new ArrayAccess(*$1, $3); }
	| SIZEOF '(' IDENTIFIER ')' {std::cout<< "sizeof"<< std::endl; $$ = new SizeOf(*$3); }
	| SIZEOF '(' type_specifier ')' {std::cout<< "sizeof"<< std::endl; $$ = new SizeOf(*$3); }
	| IDENTIFIER '(' ')' {std::cout<< "function call"<< std::endl; $$ = new FunctionCall(*$1,NULL); }
	| IDENTIFIER '('return_parameter ')' {std::cout<< "function call"<< std::endl; $$ = new FunctionCall(*$1,$3); }
	;

return_parameter
	: return_parameter ',' factor {std::cout<< "return parameter"<< std::endl; $$ = new ReturnParameter($1,$3); }
	| factor {std::cout<< "return parameter"<< std::endl; $$ = $1; }
	;


%%


Node *g_root;
Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
