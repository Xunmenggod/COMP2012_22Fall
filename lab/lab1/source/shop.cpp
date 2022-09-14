#include <iostream>
#include "shop.h"
#include "skill.h"
#include "element.h"
#include "helper.h"
#include "player.h"

using namespace std;

// Skill* shop_skills[SHOP_MAX_SKILLS_NUM] = {
//     new Skill("Fireball", 40, 30, Element::FIRE, 40),
//     new Skill("Blizzard", 120, 80, Element::ICE, 200),
//     nullptr
// };

Shop::Shop(): skills {}, skill_count {0} {
    Skill** shop_skills = get_shop_skills();
    for(int i = 0; i < SHOP_MAX_SKILLS_NUM; ++i){
        if(shop_skills[i] == nullptr){
            break;
        }
        this->skills[skill_count] = shop_skills[i];
        skill_count++;
    }
    delete [] shop_skills;
}

Shop::~Shop(){
    for(int i = 0; i < SHOP_MAX_SKILLS_NUM; ++i){
        if(this->skills[i]){
            delete this->skills[i];
        }
    }
}

void Shop::shop_navigation(Player* const player){
    cout << "----------------------\n";
    cout << "WELCOME TO THE SHOP!!! \n";
    cout << "----------------------\n";
    while(true){
        cout << "\nYou may do the following opeartions: \n";
        cout << "1: Purchase Skills \n";
        cout << "2: Boost Status \n";
        cout << "Q: Quit the Shop \n";
        char command;
        cin >> command;
        if(command ==  '1'){
            skill_nagivation(player);
        }
        else if(command == '2'){
            boost_status_navigation(player);
        }
        else if(command == 'Q' || command == 'q'){
            cout << "You left the store." << endl;
            break;
        }
        else{
            cout << "Please input correct command! \n";
        }
    }
}

void Shop::skill_nagivation(Player* const player) {
    while(true){
        display_skills();
        cout << "\nYou have " << player->coins << " number of coins.\n";
        cout << "Press the NUMBER next to the skill name to purchase or Press Q to go back. \n";
        char command;
        cin >> command;
        if(command - '0' >= 0 && command - '0' < SHOP_MAX_SKILLS_NUM){
            purchase_skill(command - '0', player);
        }
        else if(command == 'Q' || command == 'q'){
            return;
        }
        else{
            cout << "Please input correct command! \n";
        }
    }
}

void Shop::boost_status_navigation(Player* const player) const {
    while(true){
        if(player->coins < 100){
            cout << "You don't have enough coins. \n";
            break;
        }
        cout << "\nYou have " << player->coins << " number of coins.\n";
        cout << "Use 100 coins to upgrade any one of the followings or Press Q to go back. \n";
        cout << "1: 1000 HP\n";
        cout << "2: 100 MP\n";
        cout << "3: 10 ATK\n";
        cout << "4: 10 DEF\n";
        char input;
        cin >> input;
        if(input == '1'){
            player->coins -= 100;
            player->hp += 1000;
            cout << "Your HP is now " << player->hp << ".\n";
        }
        else if(input == '2'){
            player->coins -= 100;
            player->mp += 100;
            cout << "Your MP is now " << player->mp << ".\n";
        }
        else if(input == '3'){
            player->coins -= 100;
            player->attack += 10;
            cout << "Your attack is now " << player->attack << ".\n";
        }
        else if(input == '4'){
            player->coins -= 100;
            player->defense += 10;
            cout << "Your defense is now " << player->defense << ".\n";
        }
        else if(input == 'Q'){
            break;
        }
        else{
            cout << "Please input correct command! \n";
        }
    }
}

void Shop::display_skills() const {
    cout << "-----------------------------\n";
    cout << "Skills Avaliable in This Shop \n";
    cout << "-----------------------------\n";
    cout.width(20); cout << left << "Name";
    cout.width(10); cout << left << "MP Cost";
    cout.width(10); cout << left << "Power";
    cout.width(20); cout << left << "Element Type";
    cout.width(10); cout << left << "Cost";
    for(int i = 0; i < SHOP_MAX_SKILLS_NUM; ++i){
        if(this->skills[i]){
            cout << '\n';
            Skill* current_skill = this->skills[i];
            cout << i << ": "; cout.width(17); cout << left << current_skill->name; 
            cout.width(10); cout << left << current_skill->mp_cost;
            cout.width(10); cout << left << current_skill->power;
            cout.width(20); cout << left << display_element_type(current_skill->element);
            cout.width(10); cout << left << current_skill->shop_cost;
            // cout << i << ": \t" << current_skill->name << '\n';
            // cout << "MP Cost: \t" << current_skill->mp_cost <<  '\n';
            // cout << "Power: \t" << current_skill->power << '\n';
            // cout << "Element Type: \t" << display_element_type(current_skill->element) << '\n';
            // cout << "This skill cost: \t" << current_skill->shop_cost << " number of coins \n\n";
        }
    }
    cout << endl;
}

bool Shop::purchase_skill(const int index, Player* const player){
    Skill* target_skill = this->skills[index];
    if(target_skill == nullptr){
        cout << "\nThere is no such skill. \n";
        return false;
    }

    if(player->coins < target_skill->shop_cost){
        cout << "\nYou do not have enough coins. \n" << endl;
        return false;
    }

    if(player->skill_count >= 10){
        cout << "\nYou don't have enough skill slots to learn this\n" << endl;
        return false;
    }

    player->coins -= target_skill->shop_cost;
    //transfer ownership of skill from shop to player
    player->skillset[player->skill_count] = target_skill;
    player->skill_count++;
    this->skills[index] = nullptr;
    this->skill_count--;
    return true;
}