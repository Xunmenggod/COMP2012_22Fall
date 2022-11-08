#include <iostream>
#include "electronics.h"

//TODO: initialize the static varibles of class CPU and class MEM

Electronics::Electronics(bool healthy): healthy {healthy} {

}

CPU::CPU(CPU_Model model, bool healthy): Electronics(healthy), model {model} {
    ++manufacture_count;
}

void CPU::print_report(){
    std::cout << "Total number of CPU used: " << manufacture_count << std::endl;
    std::cout << "Number of Defected CPU: " << defect_count << std::endl;
}

MEM::MEM(MEM_Model model, bool healthy): Electronics(healthy), model {model} {
    ++manufacture_count;
}

void MEM::print_report(){
    std::cout << "Total number of MEM used: " << manufacture_count << std::endl;
    std::cout << "Number of Defected MEM: " << defect_count << std::endl;
}

// The following functions are all for grading purposes, you should not call them
bool Electronics::check_healthy() const{
    std::cout << "QA checks for healthy for electronics...\n";
    if(this->healthy){
        std::cout << "It is working great!\n";
        return true;
    }
    else{
        std::cout << "The technician fails to repair the computer!\n";
        return false;
    }
}

bool CPU::check_model(CPU_Model model) const{
    std::cout << "QA checks for the CPU model...\n";
    if(this->model == model){
        std::cout << "The CPU model is correct! \n";
        return true;
    }
    else{
        std::cout << "The CPU model is incorrect!\n";
        return false;
    }
}

bool MEM::check_model(MEM_Model model) const{
    std::cout << "QA checks for the MEM model...\n";
    if(this->model == model){
        std::cout << "The MEM model is correct! \n";
        return true;
    }
    else{
        std::cout << "The MEM model is incorrect!\n";
        return false;
    }
}
