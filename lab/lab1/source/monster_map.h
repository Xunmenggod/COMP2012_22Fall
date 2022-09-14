#ifndef __MONSTER_MAP_H__
#define __MONSTER_MAP_H__

class Monster;

class Monster_Map{
    public:
    Monster** map;
    int width;
    int height;
    Monster_Map(int MAP_HEIGHT, int MAP_WIDTH);
    ~Monster_Map();
    void set_monster(int x, int y, Monster* monster);
    Monster* get_monster(int x, int y) const;
};

#endif