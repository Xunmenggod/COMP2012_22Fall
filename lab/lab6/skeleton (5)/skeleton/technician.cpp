#include <iostream>
#include "technician.h"
#include "computer.h"
#include "electronics.h"

const int MAX_NUM_TECHNICIAN = 10;

// TODO: initialize the static varibles of class Technician
Technician* Technician::technician_list[MAX_NUM_TECHNICIAN]{};
int Technician::num_technician = 0;

// TODO: Implement the constructor
Technician::Technician(std::string name, Diagnosis_Tool* diagnosis_tool): name(name), diagnosis_tool(diagnosis_tool), num_order_finished(0)
{   
    if (num_technician < MAX_NUM_TECHNICIAN)
        technician_list[num_technician++] = this;
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
    if (!diagnosis_tool->diagnose(computer->cpu)) { // check the cpu condition
        CPU_Model cpuModel = diagnosis_tool->get_CPU_Model(computer->cpu);
        CPU* newCpu = acquire_CPU(cpuModel);
        delete computer->cpu;
        // CPU::manufacture_count++;
        computer->cpu = newCpu;
        CPU::defect_count++;
    }

    if (!diagnosis_tool->diagnose(computer->mem)) { // check the mem condition
        MEM_Model memModel = diagnosis_tool->get_MEM_Model(computer->mem);
        MEM* newMem = acquire_MEM(memModel);
        delete computer->mem;
        // MEM::manufacture_count++;
        computer->mem = newMem;
        MEM::defect_count++;
    }
    this->num_order_finished++;
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
