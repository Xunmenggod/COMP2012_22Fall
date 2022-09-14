#include <iostream>
#include "player.h"
#include "monster.h"
#include "helper.h"
#include "shop.h"
#include "battle.h"
#include "monster_map.h"

using namespace std;

const int MAP_WIDTH = 6;
const int MAP_HEIGHT = 6;

char map[MAP_HEIGHT*MAP_WIDTH] = {
    'P', '.', '.', 'W', '.', 'G',
    '.', '.', '.', 'W', '.', '.',
    '.', '.', 'M', 'W', 'M', 'W',
    '.', 'W', '.', 'M', '.', '.',
    '.', 'W', 'M', '.', 'W', '.',
    '.', 'W', '.', 'S', '.', 'M'
};

enum Direction {UP = 0, DOWN, LEFT, RIGHT};

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

Direction char_to_direction(const char c){
    if(c == 'W' || c == 'w'){
        return UP;
    }
    if(c == 'A' || c == 'a'){
        return LEFT;
    }
    if(c == 'S' || c == 's'){
        return DOWN;
    }
    if(c == 'D' || c == 'd'){
        return RIGHT;
    }
    return UP;
}

int main(){
    cout << "Welcome to the RPG game!\n" << endl;

    //init game
    Player player(10000, 1000, 100, 80);
    Shop shop;
    Monster_Map monster_map(MAP_HEIGHT, MAP_WIDTH);
    //assign different monster into the monster map
    init_monster(&monster_map);

    //Game Cycle
    while (true)
    {
        int original_x = player.position_x;
        int original_y = player.position_y;
        int next_x, next_y;

        //print map
        print_map(map, MAP_WIDTH, MAP_HEIGHT);

        //Input processing for moving the player
        while(true){
            cout << "Input W: up, A: left, S: down, D: right or Q: quit \n";
            char input;
            cin >> input;
            if(input == 'Q' || input == 'q'){
                cout << "You left the game." << endl;
                return 0;
            }

            Direction direction;
            if(input == 'W' || input == 'w' || input == 'A' || input == 'a' 
                || input == 'S' || input == 's' || input == 'D' || input == 'd'){
                direction = char_to_direction(input);
                next_x = original_x + dx[direction];
                next_y = original_y + dy[direction];
                if(!valid_move(next_x, next_y, map, MAP_WIDTH, MAP_HEIGHT)){
                    cout << "This is not a valid move, please try again. \n";
                    continue; 
                }
                //Valid Move, move player to new position, leave the input processing stage
                player.position_x = next_x;
                player.position_y = next_y;
                break;
            }
            else{
                cout << "Incorrect input, please try again. \n";
                continue;
            }
        }
        
        //Event triggering
        char symbol = map[player.position_y * MAP_WIDTH + player.position_x];
        if(symbol == 'S'){
            shop.shop_navigation(&player);
        }
        else if(symbol == 'M'){
            Monster* monster = monster_map.get_monster(player.position_x, player.position_y);
            battle_navigation(&player, monster);
            if(!player.alive){
                return 0;
            }
            if(!monster->alive){
                delete monster;
                monster_map.set_monster(player.position_x, player.position_y, nullptr);
            }
        }
        else if(symbol == 'G'){
            cout << "CONGRADUATIONS! YOU WIN!!!" << endl;
            return 0;
        }
        else if(symbol == '.'){
            //cout << "Nothing here \n";
        }
        else{
            cout << "Error: Land on Something Unknown" << endl;
            return 0;
        }
        
        //map editing
        //restore the SHOP icon if player moved out from the store
        if(original_x == 3 && original_y == 5){
            map[original_y * MAP_WIDTH + original_x] = 'S';
        }
        else{
            map[original_y * MAP_WIDTH + original_x] = '.';
        }
        //change the icon for the player's current position
        map[player.position_y * MAP_WIDTH + player.position_x] = 'P';
    }
    return 0;
}