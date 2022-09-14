#include <iostream>
#include "monster.h"
#include "player.h"
#include "helper.h"

using namespace std;

Monster::Monster(const char* const name, const int hp, const int attack, const int skill_power, 
                const int defense, const int pos_x, const int pos_y, const int coins, 
                const Element weakness):
name {name}, hp {hp}, attack {attack}, skill_power {skill_power}, defense {defense}, position_x {pos_x}, position_y {pos_y}, coins {coins}, weakness {weakness} {

}

void Monster::fight(Player* const player) const {
    int damage = calculate_damage(this->attack, player->defense, this->skill_power, false);
    player->hp -= damage;
    cout << "The monster attacks you, dealing with " << damage << " points of damage." "\n";
}