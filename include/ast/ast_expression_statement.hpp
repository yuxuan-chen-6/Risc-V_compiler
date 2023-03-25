#ifndef ast_expression_statement_hpp
#define ast_expression_statement_hpp

#include <string>
#include <iostream>
#include <vector>

#include "ast_node.hpp"
#include "ast_number.hpp"
using namespace std;

class ExpressionStatement : public Node
{
    Node *expr;
    std::string id;
    public:
    ExpressionStatement(const std::string _id, Node *_expr)
    : id(_id), expr(_expr) {
        std::cout << "ExpressionStatement constructor" << std::endl;
    }
    virtual ~ExpressionStatement() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        if(ctxt.Localbindings.find(id) == ctxt.Localbindings.end()) {
            comp << "# declaring var" << id<< "at" << ctxt.cur_offset << std::endl;
            ctxt.Localbindings[id] = ctxt.cur_offset;
            ctxt.cur_offset -= 4;
        }
        expr->compile(comp, ctxt, destreg);
        int offset = ctxt.Localbindings[id];
        comp << "# storing var" << id << "at" << offset << std::endl;
        comp << "sw " << destreg << ", -" << offset << "(s0)" << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "ExpressionStatement";
    }
    virtual std::string getname() const override
    {
        return "-1";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};


#endif
