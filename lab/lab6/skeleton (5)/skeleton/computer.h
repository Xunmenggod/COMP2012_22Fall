#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include "model.h"

class CPU;
class MEM;

class Computer{
    private:
    CPU* cpu;
    MEM* mem;

    public:
    // TODO: friend relationship declaration
    
    Computer() = delete;
    Computer(CPU*, MEM*);
    ~Computer();

    // For grading purpose only, you should not call this function.
    void check_computer(CPU_Model cpu_model, MEM_Model mem_model) const;
};

#endif