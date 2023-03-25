#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "ast_context.hpp"

class Node;
typedef Node *NodePtr;

class Node
{
public:
    Node() {}
    virtual ~Node() {}

    virtual void print(std::ostream &dst) const{};
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const =0;
    virtual std::string gettype() const {return "";};
    virtual std::string getname() const {return "";}
    virtual std::string getval() const {return "";};
};

#endif
