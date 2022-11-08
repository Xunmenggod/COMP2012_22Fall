#include <iostream>
#include "electronics.h"
#include "computer.h"

Computer::Computer(CPU* cpu, MEM* mem): cpu {cpu}, mem {mem} {

}

Computer::~Computer(){
    delete cpu;
    delete mem;
}

// For grading purpose only, you should not call this function.
void Computer::check_computer(CPU_Model cpu_model, MEM_Model mem_model) const{
    std::cout << "QA starts checking the Computer" << std::endl;

    if(this->cpu->check_healthy() && this->mem->check_healthy()){
        std::cout << "The Computer is fully repaired!\n";
    }

    if(this->cpu->check_model(cpu_model) && this->mem->check_model(mem_model)){
        std::cout << "The models are well-matched!\n";
    }

    std::cout << "QA finished checking the Computer.\n" << std::endl;
}