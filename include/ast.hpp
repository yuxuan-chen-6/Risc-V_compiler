#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_context.hpp"
#include "ast/ast_node.hpp"
#include "ast/ast_number.hpp"
#include "ast/ast_statement.hpp"
#include "ast/ast_function.hpp"
#include "ast/ast_variable.hpp"
#include "ast/ast_operator.hpp"
#include "ast/ast_expression_statement.hpp"
#include "ast/ast_program.hpp"
#include "ast/ast_function_call.hpp"
#include "ast/ast_return_parameter.hpp"

extern Node *parseAST();

#endif
