#ifndef ast_statement_hpp
#define ast_statement_hpp

#include <string>
#include <iostream>
#include <vector>

#include "ast_node.hpp"
#include "ast_number.hpp"
using namespace std;

class Statement : public Node
{
    public:
    Statement() {}
    virtual ~Statement() {}
    virtual void print(std::ostream &dst) const override {}
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override {}
    virtual std::string gettype() const override
    {
        return "Statement";
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

class StatementList : public Statement
{
    public:
    std::vector<Node*> list;
    StatementList(Node *_stmt, Node *_stmt2)
    {
        list.push_back(_stmt);
        list.push_back(_stmt2);
        // list.push_back(_stmt2);
        std::cout << "StatementList constructor" << std::endl;
        std::cout << list.size() << std::endl;
    }
    virtual ~StatementList() {
        for (auto &stmt : list) {
            delete stmt;
        }
    }

    void add_statement(Node *_stmt, Node *_stmt2)
    {
        std::cout << "add_statement" << std::endl;
        list.push_back(_stmt);
        list.push_back(_stmt2);
    }
    void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override
    {
        for (auto &stmt : list) {
            stmt->compile(comp, ctxt, destreg);
        }

    }

    virtual void print(std::ostream &dst) const override{}

    std::string gettype() const
    {
        return "StatementList";
    }

    std::string  getname() const
    {
        return "-1";
    }

    std::string getval() const
    {
        return "null";
    }
};


class ReturnStatement : public Statement
{
    public:
    std::vector<Node*> list;
    std::string id;
    NodePtr return_val;

    ReturnStatement(Node *_return_val)
        : return_val(_return_val){
            list.push_back(_return_val);
            cout<<"ReturnStatement constructor"<<endl;
        }
    void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override
    {

        std::string regname = ctxt.get_free_Register();
        // if(return_val->gettype() == "Variable"){
        return_val->compile(comp, ctxt, destreg);
        // comp<<"lw "<< destreg << "," << ctxt.first_position << "(s0)" <<std::endl;
        // if(ctxt.type == "double"){
        //     comp<<"fmv.d f"<< destreg << ",f" << regname <<std::endl;
        // }
        // else if(ctxt.type == "float"){
        //     comp<<"fmv.s f"<< destreg << ",f" << regname <<std::endl;
        // }
        // else{
        //     comp<<"mv "<< destreg << "," << regname <<std::endl;
        // }
        // comp<<"mv "<< destreg << "," << regname <<std::endl;
    }

    virtual void print(std::ostream &dst) const override{}

    std::string gettype() const
    {
        return "ReturnStat";
    }

    std::string  getname() const
    {
        return "-1";
    }

    std::string getval() const
    {
        return return_val->getval();
    }


};

class IfStatement : public Statement
{
    public:
    NodePtr condition;
    NodePtr statement;
    NodePtr else_statement;
    IfStatement(Node *_condition, Node *_statement, Node *_else_statement)
        : condition(_condition), statement(_statement), else_statement(_else_statement)
    {
        std::cout << "IfStatement constructor" << std::endl;
    }

    virtual void print(std::ostream &dst) const override{}

    std::string gettype() const
    {
        return "IfStatement";
    }

    std::string  getname() const
    {
        return "-1";
    }

    std::string getval() const
    {
        return "null";
    }

    void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override
    {
        std::string regname = ctxt.get_free_Register();
        condition->compile(comp, ctxt, regname);
        int labelcount = ctxt.ifcount++;
        comp<<"beq "<< regname << ",zero," << ".L" << labelcount <<std::endl;
        statement->compile(comp, ctxt, regname);
        comp << "mv " << "a0," << regname << std::endl;
        comp << "lw ra,48(sp)" << std::endl;
        comp << "lw s0,44(sp)" << std::endl;
        comp << "addi sp,sp,52" << std::endl;
        comp << "jr ra" << std::endl;
        comp<<"j .L" << ctxt.ifcount <<std::endl;
        comp<<".L" << labelcount << ":" <<std::endl;
        if(else_statement != NULL){
            else_statement->compile(comp, ctxt, destreg);
        }
        comp<<".L" << labelcount+1 << ":" <<std::endl;
        // if(condition->getval() == "1"){
        //     statement->compile(comp, ctxt, regname);
        // }
        // else if(condition->getval() == "0"){
        //     else_statement->compile(comp, ctxt, regname);
        // }
    }
};


class WhileStatement : public Statement
{
    public:
    NodePtr condition;
    NodePtr statement;
    WhileStatement(Node *_condition, Node *_statement)
        : condition(_condition), statement(_statement)
    {
        std::cout << "WhileStatement constructor" << std::endl;
    }

    virtual void print(std::ostream &dst) const override{}

    std::string gettype() const
    {
        return "WhileStatement";
    }

    std::string  getname() const
    {
        return "-1";
    }

    std::string getval() const
    {
        return "null";
    }

    void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override
    {
        std::string regname = ctxt.get_free_Register();
        int labelcount = ctxt.whilecount++;
        comp << "j " << ".L" << labelcount << std::endl;
        comp << ".L" << ctxt.whilecount << ":" << std::endl;
        if(statement != NULL){
            statement->compile(comp, ctxt, destreg);
        }
        comp << ".L" << labelcount << ":" << std::endl;
        condition->compile(comp, ctxt, regname);

    }
};

class ForStatement : public Statement
{
    public:
    NodePtr init;
    NodePtr condition;
    NodePtr update;
    NodePtr statement;
    ForStatement(Node *_init, Node *_condition, Node *_update, Node *_statement)
        : init(_init), condition(_condition), update(_update), statement(_statement)
    {
        std::cout << "ForStatement constructor" << std::endl;
    }

    virtual void print(std::ostream &dst) const override{}

    std::string gettype() const
    {
        return "ForStatement";
    }

    std::string  getname() const
    {
        return "-1";
    }

    std::string getval() const
    {
        return "null";
    }

    void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override
    {
        std::string regname = ctxt.get_free_Register();
        int labelcount = ctxt.forcount++; //labelcount=0, ctxt.forcount=1
        ctxt.isFor=true;
        init->compile(comp, ctxt, regname);
        comp << "j " << ".L" << ctxt.forcount << std::endl;
        comp << ".L" << labelcount << ":" << std::endl;
        if(statement != NULL){
            statement->compile(comp, ctxt, regname);
        }
        update->compile(comp, ctxt, destreg);
        comp << ".L" << ctxt.forcount << ":" << std::endl;
        condition->compile(comp, ctxt, regname);
    }
};

#endif
