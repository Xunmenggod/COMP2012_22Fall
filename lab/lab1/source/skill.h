#ifndef __SKILL_H__
#define __SKILL_H__

#include "element.h"

class Skill{
    public:
    const char* name;
    int power;
    int mp_cost;
    Element element;
    int shop_cost;

    Skill(const char* name, int power, int mp_cost, Element element, int shop_cost);
};

#endif