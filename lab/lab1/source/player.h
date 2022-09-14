#ifndef __PLAYER_H__
#define __PLAYER_H__

class Skill;
class Monster;

class Player{
    public:
    int hp;
    int mp;
    int attack;
    int defense;
    int skill_count = 0;
    int position_x = 0;
    int position_y = 0;
    int coins = 1000;
    bool alive = true;
    Skill* skillset[10];

    Player(int hp, int mp, int attack, int defense);
    ~Player();

    void display_skillset() const;
    bool fight(const Skill* skill, Monster* monster);
};

#endif