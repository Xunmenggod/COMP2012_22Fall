#ifndef __HELPER_H__
#define __HELPER_H__

#include "element.h"

const int DAMAGE_NORMALIZED_FACTOR = 10;
const int WEAKNESS_BONUS_RATIO = 2;

class Monster_Map;
class Skill;

void print_map(const char map[], int MAP_WIDTH, int MAP_HEIGHT);

bool valid_move(int next_x, int next_y, const char map[], int MAP_WIDTH, int MAP_HEIGHT);

int calculate_damage(int s_atk, int t_def, int power, bool weakness);

const char* display_element_type(Element element);

void init_monster(Monster_Map* monster_map);

Skill** get_shop_skills();

#endif