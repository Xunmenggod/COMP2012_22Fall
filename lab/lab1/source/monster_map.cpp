#include "monster_map.h"
#include "monster.h"

Monster_Map::Monster_Map(const int MAP_HEIGHT, const int MAP_WIDTH): width {MAP_WIDTH}, height {MAP_HEIGHT} {
    this->map = new Monster*[MAP_WIDTH*MAP_HEIGHT]{};
}

Monster_Map::~Monster_Map(){
    for(int i = 0; i < width; ++i){
        for(int j = 0; j < height; ++j){
            int index = j * width + i;
            if(map[index]){
                delete map[index];
            }
        }
    }
    delete [] map;
}

void Monster_Map::set_monster(const int x, const int y, Monster* const monster){
    map[y*width+x] = monster;
}

Monster* Monster_Map::get_monster(const int x, const int y) const {
    return map[y*width+x];
}