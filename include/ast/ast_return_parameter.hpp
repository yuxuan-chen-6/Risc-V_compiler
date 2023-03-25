#ifndef ast_return_parameter_hpp
#define ast_return_parameter_hpp

#include <string>
#include <iostream>
#include "ast_context.hpp"
#include "ast_node.hpp"

class ReturnParameter
    : public Node
{
private:
    NodePtr variable;
    NodePtr variable2;
public:
    ReturnParameter(NodePtr _variable,NodePtr _variable2)
        : variable(_variable), variable2(_variable2){
            std::cout << "ReturnParameter constructor" << std::endl;
        }

    virtual std::string gettype() const override
    {
        return "ReturnParameter";
    }
    virtual std::string getname() const override
    {
        return "-1";
    }
    virtual std::string getval() const override
    {
        return std::to_string(0);
    }

    virtual void print(std::ostream &dst) const override{}

    virtual void compile(std::ostream &comp, Context &context, std::string destReg) const override
    {
        variable->compile(comp, context, "a0");
        std::string regname1 = "a"+ to_string(++context.countparam);
        variable2->compile(comp, context, regname1);
    }
};

#endif
