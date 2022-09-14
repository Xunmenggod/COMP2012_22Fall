#include "skill.h"

Skill::Skill(const char* const name, const int power, const int mp_cost, const Element element, const int shop_cost)
: name {name}, power {power}, mp_cost {mp_cost}, element {element}, shop_cost {shop_cost}
{

}