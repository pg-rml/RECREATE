#pragma once
#include <conio.h>
#include <string>
#include <vector>

#include "Item.h"
#include "Skill.h"
using namespace std;

#define temp 15

class Entity {
protected:
    std::string name;

    int MaxHp;
    int hp;

    int MaxAct = -1;
    int act = MaxAct;

    int dmg = 0;
    float incdmg = 0;
    int dfs = 10;
    float incdfs = 0;

    int shield = 0;

    Skill* skill;
    int skillnum = 1;

    bool hidden = false;
    bool stern = false;
    bool aggro = false;

    int instead = NULL;
    int charseq = NULL;

    int overpower = NULL;
    int overpowercount = 0;
    bool cursedDoll = false;
    int guard = 0;
    int molt = NULL;
    int tear = NULL;
    int holy = NULL;
    int auracount = NULL;

    int finalDfs = 0;
    int finalDmg = 0;

    bool reflect = false;
    int reflectShield = 0;
    int reflectDmg = 0;

    int damage = 0;
    bool monster = true;

    bool dead = false;
    vector<int> aura;

    int dropItem = 0;
public:
    Entity() {
        name = "(알수없음)"; MaxHp = 0, hp = MaxHp; skill = { nullptr };
    }
    virtual void showInfo();
    static int sufferDmg(int dmg, Entity* e, vector<Entity*>& entity, bool reflect = true);
    static int decreaseHp(int dmg, Entity* e, vector<Entity*>& entity);
    Entity* target(vector<Entity*>& entity);
    virtual void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
    virtual void attack(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
    static bool entityErase(Entity* e, vector<Entity*>& entity);
    void insertUpperBound(vector<Skill>& buff, Skill& skill);
    void print(int x, int y);
    void stage_init();

    string getName() { return name; }

    void setAct(int act) { this->act = act; }
    int getAct() { return act; }
    void setMaxAct(int MaxAct) { this->MaxAct += MaxAct; }
    int getMaxAct() { return MaxAct; }

    int getMaxHp() { return MaxHp; }
    void setMaxHp(int MaxHp) { this->MaxHp += MaxHp; }
    int getHp() { return hp; }
    void setHp(int figure) {
        if (this->hp + figure < this->MaxHp) this->hp += figure;
        else this->hp = this->MaxHp;
    }
    void hitHp(int dmg) { this->hp -= dmg; }
    int getDmg() { return dmg; }
    void setDmg(int dmg) { this->dmg += dmg; }

    float getIncdmg() { return incdmg; }
    void setIncdmg(float figure) { this->incdmg += figure; }

    int getDfs() { return dfs; }
    void setDfs(int dfs) { this->dfs += dfs; }
    float getIncdfs() { return incdfs; }
    void setIncdfs(float figure) { this->incdfs += figure; }

    Skill getSkill() { return*skill; }
    int getSkillNum() { return skillnum; }

    bool getHidden() { return hidden; }

    void setAggro(int charseq) { this->charseq = charseq; aggro = true; }

    void setInstead(int charseq) { instead = charseq; }
    int getInstead() { return instead; }

    void setStern() { stern = true; }
    bool getStern() { return stern; }

    void setOverpower(float figure) {
        this->incdmg += figure;
        overpower = 3;
        overpower++;
    }

    int getReflectShield() { return reflectShield; }
    int getShield() { return shield; }
    void setShield(int shield) { this->shield += shield; }
    void setReflect(int shield) {
        if (reflectShield < 0) reflectShield = shield;
        else reflectShield += shield;
        reflect = true;
    }
    void setCursedDoll(float figure) {
        this->incdmg += figure;
        cursedDoll = true;
    }
};
