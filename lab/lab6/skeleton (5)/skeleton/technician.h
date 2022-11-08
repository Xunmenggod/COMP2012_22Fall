#ifndef __TECHNICIAN_H__
#define __TECHNICIAN_H__

#include "electronics.h"
#include <string>

class Computer;
class Diagnosis_Tool;

class Technician{
    private:
    std::string name;               // Name of the Technician
    int num_order_finished;         // The number of orders finished by the Technician
    Diagnosis_Tool* diagnosis_tool; // The diagnosis_tool that the Technician owns

    public:
    // Disable default constructor
    Technician() = delete;
    // Constructor that takes 2 arguments
    Technician(std::string, Diagnosis_Tool*);
    // Disable copy constructor
    Technician(const Technician&) = delete;
    // Destructor
    ~Technician();

    CPU* acquire_CPU(CPU_Model) const;
    MEM* acquire_MEM(MEM_Model) const;
    void repair(Computer*);
    
    static Technician* technician_list[];
    static int num_technician;

    // A static function that prints the information of Technicians
    static void print_report();
};

class Diagnosis_Tool{
    private:
    bool diagnose(Electronics* electronics){
        return electronics->healthy;
    }

    CPU_Model get_CPU_Model(CPU* cpu){
        return cpu->model;
    }

    MEM_Model get_MEM_Model(MEM* mem){
        return mem->model;
    }

    public:
    // TODO: friend relationship declaration

    // Use default constructor
    Diagnosis_Tool() = default;
    // Disable copy constructor
    Diagnosis_Tool(const Diagnosis_Tool&) = delete;
    // Use default destructor
    ~Diagnosis_Tool() = default;
};

#endif