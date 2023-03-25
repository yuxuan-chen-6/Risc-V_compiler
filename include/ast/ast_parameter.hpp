#ifndef parameter_hpp
#define parameter_hpp
using namespace std;
#include <string>
#include <iostream>
#include <vector>

#include "ast_node.hpp"

class Parameter : public Node
{
    public:
    std::string type;
    std::string id;

    Parameter (std::string in_type, std::string in_id)
        : type(in_type), id(in_id) {}

    void print(std::ostream &dst) const{}

    void compile(std::ostream &comp, Context &ctxt, std::string destreg) const {
        comp << "sw " << "a0" << "," << "s(0)" << std::endl;
    }

    std::string gettype() const
    {
        return "parameter";
    }

    std::string  getname() const
    {
        return id;
    }

    std::string getval() const
    {
        return "null";
    }
};


class ParameterList : public Node
{
    public:
    std::vector<Parameter*> args;

    ParameterList (){}
    void add(Parameter* in_arg)
    {
        args.push_back(in_arg);
    }


    void print(std::ostream &dst) const{}

    void compile(std::ostream &comp, Context &context, std::string destReg) const
    {
        for (int i=0; i<args.size(); i++) {
            args[i]->compile(comp, context, destReg);

    }
}

    std::string gettype() const
    {
        return "paramlist";
    }

    std::string  getname() const
    {
        return "-1";
    }

    std::string getval() const
    {
        return "null";
    }

    int getsize() const
    {
        return args.size();
    }


};

#endif

