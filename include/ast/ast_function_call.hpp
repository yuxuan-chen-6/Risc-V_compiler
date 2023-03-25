#ifndef ast_function_call_hpp
#define ast_function_call_hpp

#include <string>
#include <iostream>
#include "ast_context.hpp"
#include "ast_node.hpp"
#include "ast_statement.hpp"
#include "ast_function.hpp"

class FunctionCall
    : public Node
{
private:
    std::string id;
    int value;
    NodePtr variable;
public:
        FunctionCall(const std::string _id, NodePtr _variable)
            : id(_id), variable(_variable), value(0){
                std::cout << value << std::endl;
                std::cout << "FunctionCall constructor" << std::endl;
            }

        virtual std::string gettype() const override
        {
            return "FunctionCall";
        }
        virtual std::string getname() const override
        {
            return id;
        }
        virtual std::string getval() const override
        {
            return std::to_string(value);
        }

        virtual void print(std::ostream &dst) const override{}

        virtual void compile(std::ostream &comp, Context &context, std::string destReg) const override
        {
            if(variable != NULL){
                variable->compile(comp, context, "a0");
        }
            comp << "call " << id << std::endl;
            comp << "mv " << destReg<< ",a0" << std::endl;
        }
};

#endif

