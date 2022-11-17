#include "util.h"

void print_report()
{
    //TODO: call a suitable static function
    Technician::print_report();
    std::cout << "----------------------" << std::endl;
    std::cout << "REPORT FOR ELECTRONICS" << std::endl;
    std::cout << "----------------------" << std::endl;
    //TODO: call a suitable static function
    CPU::print_report();
    std::cout << '\n';
    //TODO: call a suitable static function
    MEM::print_report();
    std::cout << "----------------------" << std::endl;
    std::cout << "--- END OF REPORT ----" << std::endl;
    std::cout << "----------------------" << std::endl;
}