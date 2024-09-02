#pragma once
#include <algorithm>

#include "Entity.h"
#include "Skill.h"

#define MAX_MONSTER_NUM 3

class Rogue : public Entity {
public:
	Rogue(string name = "") {
		this->name = name; this->MaxHp = 50; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("은밀한 공격", 25);
		skill[1].setSkill("비열한 일격", 30);
		skill[2].setSkill("그림자 숨기", 0, 1);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
	void hide();
	void hideOnOff();
};
class Chest : public Entity {
public:
	Chest(string name = "") {
		this->name = name; this->MaxHp = 120; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("독성 가루", 15, 3);
		skill[1].setSkill("깜짝 폭발", 35);
		skill[2].setSkill("최후의 발악", 50);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Toad : public Entity {
public:
	Toad(string name = "") {
		this->name = name; this->MaxHp = 80; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("독구름", 15, 3, 1);
		skill[1].setSkill("혀 채찍", 30);
		skill[2].setSkill("급속 회복", 0, 0, 10);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Crocodile : public Entity {
public:
	Crocodile(string name = "") {
		this->name = name; this->MaxHp = 110; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("강력한 물기", 45);
		skill[1].setSkill("악어의 눈물", 0, 3, 0.05);
		skill[2].setSkill("질식 공격", 30);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Locust : public Entity {
public:
	Locust(string name = "") {
		this->name = name; this->MaxHp = 150; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("소용돌이", 30, 1, 1);
		skill[1].setSkill("대돌진", 25);
		skill[2].setSkill("포효", 0, 1, 0.05);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Snake : public Entity {
public:
	Snake(string name = "") {
		this->name = name; this->MaxHp = 160; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("독액 뿜기", 40);
		skill[1].setSkill("죽음의 포옹", 45);
		skill[2].setSkill("탈피", 0, 3, 0.07);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Harpy : public Entity {
public:
	Harpy(string name = "") {
		this->name = name; this->MaxHp = 200; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("날카로운 발톱", 45);
		skill[1].setSkill("폭풍의 날개", 40);
		skill[2].setSkill("시끄러운 고함", 0, 3, 0.1);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Wolf : public Entity {
public:
	Wolf(string name = "") {
		this->name = name; this->MaxHp = 200; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("야생의 돌진", 50);
		skill[1].setSkill("포효", 0, 3, 0.1);
		skill[2].setSkill("그루밍");
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Believer : public Entity {
public:
	Believer(string name = "") {
		this->name = name; this->MaxHp = 230; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("정화의 불길", 40);
		skill[1].setSkill("영혼의 방패");
		skill[2].setSkill("순교자의 계약", 0, 0, 0.15, 0.1);
	}
	void useSkill(int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Angel : public Entity {
public:
	Angel(string name = "", int hp = 0) {
		this->name = name; this->MaxHp = hp; this->hp = MaxHp; this->skillnum = 4;
		skill = new Skill[skillnum];
		skill[0].setSkill("천사의 심판", 45);
		skill[1].setSkill("구원의 맹공", 50);
		skill[2].setSkill("천국의 폭풍", 30);
		skill[3].setSkill("신성한 힘", 0, 0, 0.2);
	}
	void useSkill(int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class God : public Entity {
public:
	God(string name = "", int hp = 0) {
		this->name = name; this->MaxHp = hp; this->hp = MaxHp; this->skillnum = 5;
		skill = new Skill[skillnum];
		skill[0].setSkill("천벌", 50);
		skill[1].setSkill("붕괴", 55);
		skill[2].setSkill("최후의 심판", 80);
		skill[3].setSkill("시간의 지배", 0, 1, 4);
		skill[4].setSkill("영원의 오라", 0, 5);
	}
	void useSkill(int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};