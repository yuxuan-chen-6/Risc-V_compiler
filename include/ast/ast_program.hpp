#ifndef ast_program_hpp
#define ast_program_hpp

#include <string>
#include <iostream>
#include <vector>

#include "ast_node.hpp"
#include "ast_variable.hpp"
#include "ast_expression_statement.hpp"
#include "ast_function.hpp"

class Program
    : public Node
{
private:
    NodePtr statement;
    NodePtr function;
public:
    Program(NodePtr _statement, NodePtr _function)
        : statement(_statement), function(_function)
    {
        std::cout << "Program constructor" << std::endl;
    }

    virtual std::string gettype() const override
    {
        return "Program";
    }
    virtual std::string getname() const override
    {
        return "-1";
    }
    virtual std::string getval() const override
    {
        return "null";
    }

    virtual void print(std::ostream &dst) const override{}

    void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override
    {
        statement->compile(comp, ctxt, destreg);
        function->compile(comp, ctxt, destreg);
    }
};

#endif



