#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "element.h"

class Player;

class Monster{
    public:
    const char* name;
    int hp;
    int attack;
    int skill_power;
    int defense;
    int position_x;
    int position_y;
    int coins;
    bool alive = true;
    Element weakness;

    Monster(const char* name, int hp, int attack, int skill_power, 
            int defense, int pos_x, int pos_y, int coins, 
            Element weakness);
    void fight(Player* player) const;
};

#endif