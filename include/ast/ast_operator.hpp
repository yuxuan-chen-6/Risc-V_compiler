#ifndef ast_operator_hpp
#define ast_operator_hpp

#include <string>
#include <iostream>
#include <cmath>
#include "ast_context.hpp"
#include "ast_node.hpp"
#include "ast_number.hpp"
using namespace std;

class Operator : public Node
{
    public:
    Operator() {}
    virtual ~Operator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {}
    virtual std::string gettype() const override
    {
        return "Operator";
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

class AddOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    AddOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "AddOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~AddOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        left->compile(comp, ctxt, destreg);
        comp << "#"<<destreg<<std::endl;
        std::string regname = ctxt.get_free_Register();
        right->compile(comp, ctxt, regname);
        if(ctxt.type == "double")
            comp << "fadd.d f" << destreg << ",f" << regname << ",f" << destreg << std::endl;
        else if(ctxt.type == "float"){
            comp << "fadd.s f" << destreg << ",f" << regname << ",f" << destreg << std::endl;
        }
        else{
            comp << "add " << destreg << "," << destreg << "," << regname << std::endl;
        }
        // comp << "add " << destreg << "," << regname << "," << destreg << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "AddOperator";
    }
    virtual std::string getname() const override
    {
        return "+";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

class SubOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    SubOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "SubOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~SubOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        right->compile(comp, ctxt, regname);
        comp << "sub " << destreg << "," << destreg << "," << regname << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "SubOperator";
    }
    virtual std::string getname() const override
    {
        return "-";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

class MulOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    MulOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "MulOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~MulOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        right->compile(comp, ctxt, regname);
        if(ctxt.type == "double")
            comp << "fmul.d f" << destreg << ",f" << destreg << ",f" << regname << std::endl;
        else if(ctxt.type == "float"){
            comp << "fmul.s f" << destreg << ",f" << destreg << ",f" << regname << std::endl;
        }
        else{
            comp << "mul " << destreg << "," << destreg << "," << regname << std::endl;
        }
        // comp << "mul " << destreg << "," << destreg << "," << regname << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "MulOperator";
    }
    virtual std::string getname() const override
    {
        return "*";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

class DivOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    DivOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "DivOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~DivOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        right->compile(comp, ctxt, regname);
        comp << "div " << destreg << "," << destreg << "," << regname << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "DivOperator";
    }
    virtual std::string getname() const override
    {
        return "/";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

class LessOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    LessOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "LessOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~LessOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        right->compile(comp, ctxt, regname);
        if(ctxt.isFor == true){
            comp << "blt " << destreg << "," << regname << ",.L" << ctxt.forcount-1 << std::endl;
        }
        else{
            comp << "slt " << destreg << "," << destreg << "," << regname << std::endl;
            comp << "andi " << destreg << "," << destreg << ",0xff" << std::endl;
    }
        ctxt.isFor = false;
    }
    virtual std::string gettype() const override
    {
        return "LessOperator";
    }
    virtual std::string getname() const override
    {
        return "<";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

class equalOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    equalOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "equalOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~equalOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        right->compile(comp, ctxt, regname);
        comp << "sub " << destreg << "," << regname << "," << destreg << std::endl;
        comp << "seqz " << destreg << "," << destreg << std::endl;
        comp << "andi " << destreg << "," << destreg << ",0xff" << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "equalOperator";
    }
    virtual std::string getname() const override
    {
        return "==";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

class LessEqualOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    LessEqualOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "LessEqualOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~LessEqualOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        right->compile(comp, ctxt, regname);
        comp << "sgt " << destreg << "," << destreg << "," << regname << std::endl;
        comp << "xor " << destreg << "," << destreg << ",1" << std::endl;
        comp << "andi " << destreg << "," << destreg << ",0xff" << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "LessEqualOperator";
    }
    virtual std::string getname() const override
    {
        return "<=";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

class AndOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    AndOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "bitwiseAndOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~AndOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        right->compile(comp, ctxt, regname);
        comp << "and " << destreg << "," << regname << "," << destreg << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "bitwiseAndOperator";
    }
    virtual std::string getname() const override
    {
        return "&";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

class OrOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    OrOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "bitwiseOrOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~OrOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        right->compile(comp, ctxt, regname);
        comp << "or " << destreg << "," << regname << "," << destreg << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "bitwiseOrOperator";
    }
    virtual std::string getname() const override
    {
        return "|";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

class XorOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    XorOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "bitwiseXorOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~XorOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        right->compile(comp, ctxt, regname);
        comp << "xor " << destreg << "," << regname << "," << destreg << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "bitwiseXorOperator";
    }
    virtual std::string getname() const override
    {
        return "^";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

class LogicalAndOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    LogicalAndOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "logicalAndOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~LogicalAndOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        int label1= ctxt.label++;
        int label2= ctxt.label++;
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        comp << "beq " << destreg << "," << "zero" << ",.L" << label1 << std::endl;
        right->compile(comp, ctxt, destreg);
        comp << "beq " << destreg << "," << "zero" << ",.L" << label2 << std::endl;
        comp << "li " << destreg << "," << "1" <<std::endl;
        comp << "j " << ".L"<< label2 << std::endl;
        comp << ".L" << label1 << ":" << std::endl;
        comp << "li " << destreg << "," << "0" <<std::endl;
        comp << ".L" << label2 << ":" << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "logicalAndOperator";
    }
    virtual std::string getname() const override
    {
        return "&&";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};


class LogicalOrOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    LogicalOrOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "logicalOrOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~LogicalOrOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        int label1= ctxt.label++;
        int label2= ctxt.label++;
        int label3= ctxt.label++;
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        comp << "bne " << destreg << "," << "zero" << ",.L" << label1 << std::endl;
        right->compile(comp, ctxt, destreg);
        comp << "beq " << destreg << "," << "zero" << ",.L" << label2 << std::endl;
        comp << ".L" << label1 << ":" << std::endl;
        comp << "li " << destreg << "," << "1" <<std::endl;
        comp << "j " << ".L"<< label3 << std::endl;
        comp << ".L" << label2 << ":" << std::endl;
        comp << "li " << destreg << "," << "0" <<std::endl;
        comp << ".L" << label3 << ":" << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "logicalOrOperator";
    }
    virtual std::string getname() const override
    {
        return "||";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};


class GreaterThanOperator : public Operator
{
    private:
    NodePtr left;
    NodePtr right;

    public:
    GreaterThanOperator(NodePtr _left, NodePtr _right)
    : left(_left), right(_right) {
        std::cout << "greaterThanOperator constructor" << std::endl;
        std::cout << left->getval() << std::endl;
        std::cout << right->getval() << std::endl;
    }
    virtual ~GreaterThanOperator() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {
        std::string regname = ctxt.get_free_Register();
        left->compile(comp, ctxt, destreg);
        right->compile(comp, ctxt, regname);
        comp << "bgt " << destreg << "," << regname << ",.L" << ctxt.whilecount << std::endl;
    }
    virtual std::string gettype() const override
    {
        return "greaterThanOperator";
    }
    virtual std::string getname() const override
    {
        return ">";
    }
    virtual std::string getval() const override
    {
        return "null";
    }
};

#endif
