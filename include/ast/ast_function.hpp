#ifndef ast_function_hpp
#define ast_function_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_node.hpp"
#include "ast_statement.hpp"

using namespace std;

class ReturnStatement;
class FunctionDefinition : public Node
{
private:
    std::string type;
    std::string name;
    std::vector<std::string> args;
    NodePtr arg;
    Node* body;
public:
    FunctionDefinition(std::string *_type,
                       std::string *_name,
                       Node *_body)
        : type(*_type), name(*_name), body(_body)
    {
        std::cout << "FunctionDefinition constructor" << std::endl;
    }
    FunctionDefinition(std::string *_type,
                       std::string *_name,
                       Node *_args,
                       Node *_body)
        : type(*_type), name(*_name), arg(_args), body(_body)
    {
        args.push_back(arg->getname());
        std::cout << args.size() << std::endl;
        std::cout << "FunctionDefinition constructor" << std::endl;
    }
    virtual ~FunctionDefinition()
    {
        delete body;
    }

    virtual void print(std::ostream &dst) const override {}
    std::string gettype() const
    {
        return type;
    }
    std::string getname() const
    {
        return name;
    }
    std::string getval() const
    {
        return "null";
    }

    virtual void compile(std::ostream &comp, Context &context, std::string destReg) const override
    {
        context.type = type;
        std::string regname = context.get_free_Register();
        if(body != nullptr){
            comp << ".globl "<< name << std::endl;
            comp << ".text " << std::endl;
            comp << name +":" << std::endl;
            comp << "addi sp,sp,-52" << std::endl;
            comp << "sw ra,48(sp)" << std::endl;
            comp << "sw s0,44(sp)" << std::endl;
            comp << "addi s0,sp,52" << std::endl;
        }
        if(arg != nullptr && body != nullptr){
            context.isFunctionArg = true;
            arg->compile(comp, context, regname);
            context.isFunctionArg = false;
        }
        // comp << "#" << args.size() << std::endl;
        // for(int i = 0; i < args.size(); i++){
        //     comp << "sw a" << i << ", " << -52+i*4 << "(s0)" << std::endl;
        // }


        if(body != nullptr){
            body->compile(comp, context, regname);
            if(context.type == "float"){
                comp << "fmv.s fa0" << ",f" << regname << std::endl;
            }
            else if(context.type == "double"){
                comp << "fmv.d fa0" << ",f" << regname << std::endl;
            }
            else{
                comp << "mv a0" << "," << regname << std::endl;
            }
                comp << "lw ra,48(sp)" << std::endl;
                comp << "lw s0,44(sp)" << std::endl;
                comp << "addi sp,sp,52" << std::endl;
                comp << "jr ra" << std::endl;
        }
            // if(context.type == "float"){
            //     comp << "fmv.s fa0" << ",f" << regname << std::endl;
            // }
            // else if(context.type == "double"){
            //     comp << "fmv.d fa0" << ",f" << regname << std::endl;
            // }
            // else{
            //     comp << "mv a0" << "," << regname << std::endl;
            // }
            // comp << "lw s0,48(sp)" << std::endl;
            // comp << "addi sp,sp,52" << std::endl;
            // comp << "jr ra" << std::endl;
    }
};


#endif // ast_function_hpp
