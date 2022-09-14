#include <iostream>

#include "player.h"
#include "skill.h"
#include "monster.h"
#include "element.h"
#include "helper.h"

using namespace std;

Player::Player(const int hp, const int mp, const int attack, const int defense): hp {hp}, mp {mp}, attack {attack}, defense {defense}
{
    Skill* s = new Skill("TACKLE", 40, 0, NOMRAL, 0);
    this->skillset[skill_count] = s;
    skill_count = 1;
}

Player::~Player(){
    for(int i = 0; i < skill_count; ++i){
        if(this->skillset[i]){
            delete this->skillset[i];
        }
    }
}

void Player::display_skillset() const {
    cout.width(20); cout << left << "Name";
    cout.width(10); cout << left << "MP Cost";
    cout.width(10); cout << left << "Power";
    cout.width(20); cout << left << "Element Type";
    for(int i = 0; i < this->skill_count; ++i){
        if(this->skillset[i]){
            cout << '\n';
            Skill* current_skill = this->skillset[i];
            cout << i << ": "; cout.width(17); cout << left << current_skill->name; 
            cout.width(10); cout << left << current_skill->mp_cost;
            cout.width(10); cout << left << current_skill->power;
            cout.width(20); cout << left << display_element_type(current_skill->element);
        }
    }
    cout << endl;
}

bool Player::fight(const Skill* const skill, Monster* const monster){
    if(this->mp < skill->mp_cost){
        cout << "You don't have enough MP to use this skill!!! \n";
        return false;
    }

    bool weakness = skill->element == monster->weakness;
    int damage = calculate_damage(this->attack, monster->defense, skill->power, weakness);

    this->mp -= skill->mp_cost;
    monster->hp -= damage;

    cout << "\nYou used " << skill->name << " towards the monster. \n";
    if(weakness){
        cout << skill->name << " is SUPER EFFECTIVE!!! \n";
    }
    cout << "You have dealt " << damage << " points of damage. \n";
    return true;
}