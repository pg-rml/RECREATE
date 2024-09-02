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
		skill[0].setSkill("������ ����", 25);
		skill[1].setSkill("���� �ϰ�", 30);
		skill[2].setSkill("�׸��� ����", 0, 1);
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
		skill[0].setSkill("���� ����", 15, 3);
		skill[1].setSkill("��¦ ����", 35);
		skill[2].setSkill("������ �߾�", 50);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Toad : public Entity {
public:
	Toad(string name = "") {
		this->name = name; this->MaxHp = 80; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("������", 15, 3, 1);
		skill[1].setSkill("�� ä��", 30);
		skill[2].setSkill("�޼� ȸ��", 0, 0, 10);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Crocodile : public Entity {
public:
	Crocodile(string name = "") {
		this->name = name; this->MaxHp = 110; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("������ ����", 45);
		skill[1].setSkill("�Ǿ��� ����", 0, 3, 0.05);
		skill[2].setSkill("���� ����", 30);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Locust : public Entity {
public:
	Locust(string name = "") {
		this->name = name; this->MaxHp = 150; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("�ҿ뵹��", 30, 1, 1);
		skill[1].setSkill("�뵹��", 25);
		skill[2].setSkill("��ȿ", 0, 1, 0.05);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Snake : public Entity {
public:
	Snake(string name = "") {
		this->name = name; this->MaxHp = 160; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("���� �ձ�", 40);
		skill[1].setSkill("������ ����", 45);
		skill[2].setSkill("Ż��", 0, 3, 0.07);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Harpy : public Entity {
public:
	Harpy(string name = "") {
		this->name = name; this->MaxHp = 200; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("��ī�ο� ����", 45);
		skill[1].setSkill("��ǳ�� ����", 40);
		skill[2].setSkill("�ò����� ����", 0, 3, 0.1);
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Wolf : public Entity {
public:
	Wolf(string name = "") {
		this->name = name; this->MaxHp = 200; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("�߻��� ����", 50);
		skill[1].setSkill("��ȿ", 0, 3, 0.1);
		skill[2].setSkill("�׷��");
	}
	void useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Believer : public Entity {
public:
	Believer(string name = "") {
		this->name = name; this->MaxHp = 230; this->hp = MaxHp; this->skillnum = 3;
		skill = new Skill[skillnum];
		skill[0].setSkill("��ȭ�� �ұ�", 40);
		skill[1].setSkill("��ȥ�� ����");
		skill[2].setSkill("�������� ���", 0, 0, 0.15, 0.1);
	}
	void useSkill(int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class Angel : public Entity {
public:
	Angel(string name = "", int hp = 0) {
		this->name = name; this->MaxHp = hp; this->hp = MaxHp; this->skillnum = 4;
		skill = new Skill[skillnum];
		skill[0].setSkill("õ���� ����", 45);
		skill[1].setSkill("������ �Ͱ�", 50);
		skill[2].setSkill("õ���� ��ǳ", 30);
		skill[3].setSkill("�ż��� ��", 0, 0, 0.2);
	}
	void useSkill(int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};
class God : public Entity {
public:
	God(string name = "", int hp = 0) {
		this->name = name; this->MaxHp = hp; this->hp = MaxHp; this->skillnum = 5;
		skill = new Skill[skillnum];
		skill[0].setSkill("õ��", 50);
		skill[1].setSkill("�ر�", 55);
		skill[2].setSkill("������ ����", 80);
		skill[3].setSkill("�ð��� ����", 0, 1, 4);
		skill[4].setSkill("������ ����", 0, 5);
	}
	void useSkill(int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
};