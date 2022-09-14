#include <iostream>
#include "battle.h"
#include "player.h"
#include "monster.h"
#include "helper.h"

using namespace std;

void display_status(const Player* const player, const Monster* const monster){
    cout.width(15); cout << left << "Your Status:"; cout.width(20); cout << ""; 
    cout.width(15); cout << left << "Monster: " << monster->name << "\n";
    cout.width(15); cout << left << "HP: "; cout.width(20); cout << left << player->hp; cout.width(15); cout << left << "HP: "; cout << monster->hp << "\n";
    cout.width(15); cout << left << "MP: "; cout.width(20); cout << left << player->mp; cout.width(15); cout << left << "WEAKNESS: "; cout << display_element_type(monster->weakness) << "\n";
    cout.width(15); cout << left << "ATK: "; cout.width(20); cout << left << player->attack; cout.width(15); cout << left << "ATK: "; cout << monster->attack << "\n";
    cout.width(15); cout << left << "DEF: "; cout.width(20); cout << left << player->defense; cout.width(15); cout << left << "DEF: "; cout << monster->defense << "\n";
}

void battle_navigation(Player* const player, Monster* const monster){
    cout << "----------------------\n"; 
    cout << "A Wild " << monster->name << " Appears!!\n";
    //fight cycle
    while(true){
        display_status(player, monster);
        cout << "\nIt's your turn, pick a skill from your skillset by inputing the number. \n\n";
        player->display_skillset();

        char skill_num;
        while(true){
            cin >> skill_num;

            if(skill_num - '0' < 0 || skill_num - '0' >= player->skill_count){
                cout << "You don't have such skill. Please pick another number. \n";
                continue;
            }
            //
            else if(player->fight(player->skillset[skill_num - '0'], monster)){
                break;
            }
        }

        if(monster->hp < 0){
            monster->alive = false;
            cout << "You defeat the monster! You are rewarded with " << monster->coins << " coins.\n";
            player->coins += monster->coins;
            return;
        }
        
        cout << "It's the monster's turn. \n";
        monster->fight(player);

        if(player->hp < 0){
            player->alive = false;
            cout << "YOU DIED. \n";
            return;
        }
    }
    
}

