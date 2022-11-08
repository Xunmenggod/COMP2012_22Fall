#include <iostream>
#include "technician.h"
#include "computer.h"
#include "electronics.h"

const int MAX_NUM_TECHNICIAN = 10;

// TODO: initialize the static varibles of class Technician

// TODO: Implement the constructor
Technician::Technician(std::string name, Diagnosis_Tool* diagnosis_tool){

}

Technician::~Technician(){
    delete diagnosis_tool;
}

CPU* Technician::acquire_CPU(CPU_Model model) const {
    return new CPU(model);
}

MEM* Technician::acquire_MEM(MEM_Model model) const {
    return new MEM(model);
}

// TODO: implement repair function
void Technician::repair(Computer* computer){
    
}

void Technician::print_report(){
    std::cout << "----------------------" << std::endl;
    std::cout << "REPORT FOR TECHNICIANS" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout.width(20);
    std::cout << std::left << "NAME" << "ORDERS_COMPLETED" << std::endl;
    for(int i = 0; i < num_technician; ++i){
        std::cout.width(20);
        std::cout << std::left << technician_list[i]->name << technician_list[i]->num_order_finished << std::endl;
    }
}
