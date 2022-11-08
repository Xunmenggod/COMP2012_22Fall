#ifndef __ELECTRONICS_H__
#define __ELECTRONICS_H__

#include "model.h"

class Electronics{
    private:
    bool healthy;
    public:
    // TODO: friend relationship declaration

    Electronics(bool);
    ~Electronics() = default;

    // For grading purpose only, you should not call this function.
    bool check_healthy() const;
};

class CPU: public Electronics{
    private:
    CPU_Model model;

    public:
    // TODO: friend relationship declaration

    CPU(CPU_Model, bool healthy = true);
    CPU(const CPU& cpu) = delete;
    ~CPU() = default;

    static int manufacture_count;
    static int defect_count;
    static void print_report();

    // For grading purpose only, you should not call this function.
    bool check_model(CPU_Model model) const;
};

class MEM: public Electronics{
    private:
    MEM_Model model;
    public:
    // TODO: friend relationship declaration

    MEM(MEM_Model, bool healthy = true);
    MEM(const MEM& mem) = delete;
    ~MEM() = default;

    static int manufacture_count;
    static int defect_count;
    static void print_report();

    // For grading purpose only, you should not call this function.
    bool check_model(MEM_Model model) const;
};

#endif