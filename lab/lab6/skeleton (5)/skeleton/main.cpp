#include <iostream>
#include "computer.h"
#include "electronics.h"
#include "technician.h"
#include "util.h"

int main(){
    Technician t1 {"Harry", new Diagnosis_Tool()};
    Technician t2 {"Ron", new Diagnosis_Tool()};
    Technician t3 {"Hagrid", new Diagnosis_Tool()};
    Technician t4 {"Hermoine", new Diagnosis_Tool()};

    Computer c1(new CPU(CPU_Model::AMD_Ryzen_7_6800H, false), new MEM(MEM_Model::DDR4_3600MHz));
    t1.repair(&c1);
    c1.check_computer(CPU_Model::AMD_Ryzen_7_6800H, MEM_Model::DDR4_3600MHz);
    
    Computer c2(new CPU(CPU_Model::AMD_Ryzen_7_6800H, false), new MEM(MEM_Model::DDR4_4000MHz, false));
    t1.repair(&c2);
    c2.check_computer(CPU_Model::AMD_Ryzen_7_6800H, MEM_Model::DDR4_4000MHz);
    
    Computer c3(new CPU(CPU_Model::INTEL_i7_12700H, false), new MEM(MEM_Model::DDR4_4400MHz, false));
    t2.repair(&c3);
    c3.check_computer(CPU_Model::INTEL_i7_12700H, MEM_Model::DDR4_4400MHz);
    
    print_report();
}