#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>


class Context
{
  public:

  bool reg[32];
  std::string type;
  std::string name;
  int cur_offset=52;
  int initial_value;
  int label;
  bool isFunctionArg;
  int counter;
  int countparam;
  int ifcount;
  int whilecount;
  int forcount;
  bool isFor;


  std::unordered_map<std::string, int> Localbindings;

Context()
  {
    for(int i=0; i<32; i++)
    {
      reg[i] = false;
    }
    reg[0] = true;
    reg[1] = true;
    reg[2] = true;
    reg[3] = true;
    cur_offset = 52;
    label = 0;
    isFunctionArg = false;
    counter = 0;
    std::string type="NULL";
    countparam = 0;
    ifcount = 0;
    whilecount = 0;
    forcount = 0;
    isFor = false;

  }
  bool InLocal (const std::string id) const
    {
        if (Localbindings.find(id) != Localbindings.end()){//.find returns the end of the map if not found
            return true;
        }
        return false;
    }

    void AddLocal (const std::string id, int val)
    {
        Localbindings.emplace(id, val);
    }

    int GetLocal (const std::string id) const
    {
        if (Localbindings.count(id) == 0) {
            std::cout << "ERROR: Variable " << id << " not found in context" << std::endl;
            exit(1);
        }
        return Localbindings.find(id)->second;
    }

    std::string get_free_Register()
    {
        std::vector <std::string> regName = {"a6", "a7", "t0", "t1", "t2","t3", "t4", "t5", "t6"};
        for (int i = 12; i < regName.size()+12; i++)
        {
            if (!reg[i]){
                reg[i] = true; // Set the register to be used
                return regName[i-12]; // Return the first available register
            }
        }
        std::cerr<<"ERROR: Registers insufficient to implement program"<<std::endl;
        exit(1);
    }

    void occupied_Register(std::string regname)
    {
      if (regname == "a6")
      {
        reg[6] = true;
      }
      else if (regname == "a7")
      {
        reg[7] = true;
      }
      else if (regname == "t0")
      {
        reg[14] = true;
      }
      else if (regname == "t1")
      {
        reg[15] = true;
      }
      else if (regname == "t2")
      {
        reg[16] = true;
      }
      else
      {
        std::cerr<<"ERROR: Registers insufficient to implement program"<<std::endl;
        exit(1);
      }
    }


    std::string free_Register(std::string regname)
    {
      if (regname == "a6")
      {
        reg[6] = false;
      }
      else if (regname == "a7")
      {
        reg[7] = false;
      }
      else if (regname == "t0")
      {
        reg[14] = false;
      }
      else if (regname == "t1")
      {
        reg[15] = false;
      }
      else if (regname == "t2")
      {
        reg[16] = false;
      }
      else
      {
        std::cerr<<"ERROR: Registers insufficient to implement program"<<std::endl;
        exit(1);
      }
    }
};
// Only used with when compiling, the compile function. Ignore when looking at only translate or print


#endif
