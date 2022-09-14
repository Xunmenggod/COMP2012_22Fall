#include <iostream>
#include "helper.h"
#include "element.h"
#include "monster_map.h"
#include "monster.h"
#include "skill.h"
#include "shop.h"

using namespace std;

//You should not add more monster or change the position_x or position_y, or else the program will crash.
//For elements, you may refer to element.h
void init_monster(Monster_Map* const monster_map){
    monster_map->set_monster(2, 2, new Monster("Ada", 100, 10, 2, 2, 2, 2, 2, ICE));
    monster_map->set_monster(2, 4, new Monster("Bob", 100, 10, 2, 2, 4, 2, 2, NOMRAL));
    monster_map->set_monster(3, 3, new Monster("Candy", 100, 10, 2, 2, 3, 3, 2, FIRE));
    monster_map->set_monster(5, 5, new Monster("David", 100, 10, 10, 2, 5, 5, 2, WIND));
    monster_map->set_monster(4, 2, new Monster("Eros", 100, 10, 10, 10, 2, 4, 1, THUNDER));
}

//You should not add more than 10 skills for the shop.
Skill** get_shop_skills(){
    Skill** shop_skills = new Skill*[SHOP_MAX_SKILLS_NUM] {
        new Skill("Fireball", 40, 30, Element::FIRE, 40),
        new Skill("Blizzard", 120, 80, Element::ICE, 200),
        nullptr
    };
    return shop_skills;
}

void print_map(const char map[], const int MAP_WIDTH, const int MAP_HEIGHT){
    cout << '\n';
    for(int row = 0; row < MAP_HEIGHT; ++row){
        for(int col = 0; col < MAP_WIDTH; ++col){
            cout << map[row * MAP_WIDTH + col] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}


bool valid_move(const int next_x, const int next_y, const char map[], const int MAP_WIDTH, const int MAP_HEIGHT){
    if(next_x < 0 || next_x >= MAP_WIDTH || next_y < 0 || next_y >= MAP_HEIGHT || map[next_y * MAP_WIDTH + next_x] == 'W'){
        return false;
    }
    return true;
}

int calculate_damage(const int s_atk, const int t_def, const int power, const bool weakness){
    const int difference = s_atk - t_def;
    const int base_damage = difference > 0 ? difference : 0;
    const int weakness_bonus = weakness ? WEAKNESS_BONUS_RATIO : 1;
    return (base_damage * power * weakness_bonus)/DAMAGE_NORMALIZED_FACTOR;
}

const char* display_element_type(const Element element){
    switch(element){
        case FIRE:
        return "FIRE";
        case ICE:
        return "ICE";
        case WIND:
        return "WIND";
        case THUNDER:
        return "THUNDER";
        case NOMRAL:
        return "NO TYPE";
    }
    return "Error in display_element_type: no such skill type";
}
