#ifndef __SHOP_H__
#define __SHOP_H__

#define SHOP_MAX_SKILLS_NUM 10

class Skill;
class Player;


class Shop{
    private:
    Skill* skills[SHOP_MAX_SKILLS_NUM];

    public:
    int skill_count;
    Shop();
    ~Shop();
    void shop_navigation(Player* player);
    void skill_nagivation(Player* player);
    void boost_status_navigation(Player* player) const;
    // bool raise_hp();
    // bool raise_mp();
    void display_skills() const;
    bool purchase_skill(int index, Player* player);
};

#endif