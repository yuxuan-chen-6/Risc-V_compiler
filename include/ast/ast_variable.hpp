#ifndef ast_variable_hpp
#define ast_variable_hpp

#include <string>
#include <iostream>
#include "ast_context.hpp"
#include "ast_node.hpp"


class Variable
    : public Node
{
private:
    std::string id;
    std::string type;
    int value;
public:

    Variable(const std::string _id, int _value)
        : id(_id), value(_value){
            //context.bindings[_id].initial_value = _value;
            std::cout << "Variable constructor" << std::endl;
            std::cout << value << std::endl;

        }
    Variable(const std::string _id)
        : id(_id),value(0){
            std::cout << value << std::endl;
            std::cout << "Variable constructor" << std::endl;
            //value = context.bindings[_id].initial_value;
        }
    Variable(const std::string _type, const std::string _id)
        : type(_type), id(_id){
            std::cout << "Variable constructor" << std::endl;
        }

    // Variable(const std::string _id, const std::string _id2)
    // : id(_id), id2(_id2){
    //     std::cout << "Variable constructor" << std::endl;
    // }

    // Variable(const std::string _id, NodePtr _Store_variable)
    //  : id(_id), Store_variable(_Store_variable){
    //     std::cout << "Variable constructor" << std::endl;
    // }
    virtual std::string gettype() const override
    {
        return "Variable";
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

    void compile(std::ostream &comp, Context &context, std::string destReg) const override
    {
        if(type != ""){
            context.type=type;
        }
        if(context .Localbindings.find(id) == context .Localbindings.end()) {
            comp << "# declaring var" << id<< "at" << context .cur_offset << std::endl;
            context .Localbindings[id] = context .cur_offset;
        }
        int offset = context.Localbindings[id];
        if(context.isFunctionArg==true){
            int offset_from_a0 = context.counter++;
            comp << "# arg construct " << std::endl;
            if(context.type == "float"){
                comp << "fsw fa" << offset_from_a0 << ",-" << offset << "(s0)" << std::endl;
            }
            else if(context.type == "double"){
                comp << "fsd fa" << offset_from_a0 << ",-" << offset << "(s0)" << std::endl;
            }
            else{
                comp << "sw a" << offset_from_a0 << ",-" << offset << "(s0)" << std::endl;
            }
            // comp << "sw a" << offset_from_a0 << ", -" << offset << "(s0)" << std::endl;
        }
        else{
            comp << "# variable construct " << std::endl;
            if(context.type == "float"){
                comp << "flw f" << destReg << ",-" << offset << "(s0)" << std::endl;
            }
            else if(context.type == "double"){
                comp << "fld f" << destReg << ",-" << offset << "(s0)" << std::endl;
            }
            else{
                comp << "lw " << destReg << ",-" << offset << "(s0)" << std::endl;
            }
            // comp << "lw " << destReg << ", -" << offset << "(s0)" << std::endl;
        }
        // comp << "# variable construct " << std::endl;
        // comp << "lw " << destReg << ", -" << offset << "(s0)" << std::endl;
        context .cur_offset -= 4;



    }


};


class ParameterList : public Node
{
public:
    std::vector<Node*> args;
    ParameterList(Node *_before, Node *_next)
    {
        std::cout << "parameter_list constructor" << std::endl;
        args.push_back(_before);
        args.push_back(_next);
        std::cout << args.size() << std::endl;
    }

    virtual void print(std::ostream &dst) const override {}
    std::string gettype() const
    {
        return "ParameterList";
    }
    std::string getname() const
    {
        return "-1";
    }
    std::string getval() const
    {
        return "null";
    }

    virtual void compile(std::ostream &comp, Context &context, std::string destReg) const override
    {
        for(int i = 0; i < args.size(); i++){
            args[i]->compile(comp, context, destReg);
        }
        // comp << "# aruguments size "<< args.size() << std::endl;
        //     for(int i = 0; i < args.size(); i++){
        //         int offset = context.cur_offset;
        //         context.Localbindings[args[i]->getname()] = offset;
        //         comp << "sw a" << i << ", -" << offset << "(s0)" << std::endl;
        //         context .cur_offset -= 4;
        // }
        }

};

class SizeOf
    : public Node
{
private:
    std::string id;

public:
    SizeOf(const std::string _id)
        :  id(_id){
            std::cout << "SizeOf constructor" << std::endl;
        }

    void compile(std::ostream &comp, Context &context, std::string destReg) const override{
        int size=4;
        comp << "# sizeof " << id << std::endl;
        if(id == "char" || context.type == "char"){
            size = 1;
        }
        comp << "li " << destReg << ", " << size << std::endl;
    }
};


class ArrayDec
    : public Node
{
private:
    std::string id;
    int value;

public:
    ArrayDec(const std::string _id, int _value)
        : id(_id), value(_value){
            std::cout << "ArrayDec constructor" << std::endl;
            std::cout << value << std::endl;
        }

    void compile(std::ostream &comp, Context &context, std::string destReg) const override{

        comp << "# declaring array" << id<< "at" << context .cur_offset << std::endl;
        context .Localbindings[id] = context .cur_offset;
        for(int i = 0; i < value; i++){
            comp << "sw zero, -" << context .cur_offset << "(s0)" << std::endl;
            context .cur_offset -= 4;
        }

    }
};

class ArrayAssignments
    : public Node
{
private:
    std::string id;
    Node* value;
    Node* index;
public:
    ArrayAssignments(const std::string _id, Node* _value, Node* _index)
        : id(_id), value(_value), index(_index){
            std::cout << "ArrayAssignments constructor" << std::endl;
            std::cout << value << std::endl;
        }

    void compile(std::ostream &comp, Context &context, std::string destReg) const override{
        int offset = context.Localbindings[id];
        comp << "# array assignment" << std::endl;
        index->compile(comp, context, "a5");
        value->compile(comp, context, "a4");
        comp << "li a7, 4" << std::endl;
        comp << "mul a4, a4, a7" << std::endl;
        comp << "sub a4, zero, a4" << std::endl;
        comp << "addi a4, a4, " << offset << std::endl;
        comp << "sub a4, s0, a4" << std::endl;
        comp << "sw a5, 0(a4)" << std::endl;
    }
};

class ArrayAccess
    : public Node
{
private:
    std::string id;
    Node* index;
public:
    ArrayAccess(const std::string _id, Node* _index)
        : id(_id), index(_index){
            std::cout << "ArrayAccess constructor" << std::endl;
        }

    void compile(std::ostream &comp, Context &context, std::string destReg) const override{
        int offset = context.Localbindings[id];
        comp << "# array access" << std::endl;
        index->compile(comp, context, "a4");
        comp << "li a7, 4" << std::endl;
        comp << "mul a4, a4, a7" << std::endl;
        comp << "sub a4, zero, a4" << std::endl;
        comp << "addi a4, a4, " << offset << std::endl;
        comp << "sub a4, s0, a4" << std::endl;
        comp << "lw " << destReg << ", 0(a4)" << std::endl;
    }
};
#endif
