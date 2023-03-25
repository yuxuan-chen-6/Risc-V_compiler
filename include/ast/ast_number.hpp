#ifndef ast_numbers_hpp
#define ast_numbers_hpp

#include <string>
#include <iostream>
#include"ast_node.hpp"


class Integer : public Node
{
private:
    int value;
public:
    Integer(int _value)
        : value(_value)
    {
        std::cout << "Integer constructor" << std::endl;
    }
    bool IsIntergerStmt() const {return true;}

    double getIntValue() const
    { return value; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<value;
    }
    virtual std::string gettype() const
    {
        return "Number";
    }
    virtual std::string getname() const
    {
        return "-1";
    }
    virtual std::string getval() const
    {
        return std::to_string(value);
    }
    virtual void compile(std::ostream &comp, Context &ctxt, std::string destreg) const override
    {
        comp << "li " << destreg << "," << value << std::endl;
    }

};



#endif
