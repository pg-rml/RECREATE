#pragma once
#include <iostream>

#include "Entity.h"
#include "Item.h"
#include "Graphic.h"
class CharClass : public Entity {
protected:
	//Equipment* equip;
	vector<int> deck;
	int n, s, donedmg = NULL;
	bool reroll = true;
	Entity* e;
	Item* equipment[4] = { nullptr, nullptr, nullptr, nullptr };
public:
	CharClass() {
		monster = false;
		MaxAct = 10;
	}
	virtual void attack(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff);
	virtual void useSkill(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) = 0;
	void skillReset();
	void choiceSkill();
	void choiceEntity(vector<Entity*>& entity);
	string boolequip(int i) {
		if (equipment[i] == nullptr) return "��";
		else return "��";
	}
	Item* equip(Item* item) {
		int i;
		Item* tempitem = nullptr;
		if (equipment[item->getPart()] == nullptr) {
			equipment[item->getPart()] = item;
			useItem(item);
			return nullptr;
		}
		else {
			console_reset();
			int x = 1;
			int y = 34;

			gotoxy(x, y); cout << "�� \033[94m��� ��ü�Ѵ� \033[90m(1)\033[0m�� " << "�� \033[94m��ü���� �ʴ´� \033[90m(2)\033[0m�� ";
			gotoxy(x, y + 2); cout << " Enter Number: ";
			cin >> i;
			tempitem = equipment[item->getPart()];
			equipment[item->getPart()] = item;
			useItem(item);
			disuseItem(tempitem);
			return tempitem;
		}
	}
	void useItem(Item* item) {
		setHp(item->getHeal());
		setDmg(item->getAttack_increase());
		setDfs(item->getDefense_increase());
		setMaxHp(item->getMax_health_increase());
		setMaxAct(item->getAction_points_increase());
	}
	void disuseItem(Item* item) {
		setHp(-item->getHeal());
		setDmg(-item->getAttack_increase());
		setDfs(-item->getDefense_increase());
		setMaxHp(-item->getMax_health_increase());
		setMaxAct(-item->getAction_points_increase());
	}
};

//name, act, dmgRate
class Dealer : public CharClass {
public:
	Dealer(int& j) {
		name = "�뺴" + to_string(j); MaxHp = 100; hp = MaxHp; skillnum = 5; charseq = j;
		skill = new Skill[skillnum];
		skill[0].setSkill("���", 35, 0, 0, 0, 3);
		skill[1].setSkill("���  ����", 30, 0, 0, 0, 4);
		skill[2].setSkill("����  ���", 25, 0, 0, 0, 5);
		skill[3].setSkill("�⼱  ����", 20, 3, 0.15, 0.1, 5);
		skill[4].setSkill("����  �˱�", 70, 0, 0, 0, 10);
	}
	void useSkill(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		while (act > 0 && hp > 0) {
			screen_reset();
			console_reset();
			frame();
			int x = 1;
			int y = 0;
			if (entity["����"].size() <= 0) return;
			status_reset();
			//cout << endl << "====================�Ʊ�====================" << endl;
			for (auto a : entity["�Ʊ�"]) { a->print(x, y); y += 4; }
			x = 44;
			y = 0;
			//cout << endl << "====================����====================" << endl;
			for (auto a : entity["����"]) { a->print(x, y); y += 4; }
			choiceSkill();
			if (n == -1) return;
			else switch (n) {
			case 0:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					console_reset();
					gotoxy(x, y + 4); cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["����"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(���� ���� -" << damage << ")" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["����"]);
				dead = Entity::entityErase(e, entity["����"]);
				if (dead) { delete e; entity["����"].erase(find(entity["����"].begin(), entity["����"].end(), e)); }
				if (reflectDmg < -1) {

					screen_reset();

					x = 2;
					y = 14;

					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
				}
				act -= skill[n].getAct();
				break;
			case 1:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["����"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(���� ���� ���� ���� -" << damage << ")" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["����"]);
				dead = Entity::entityErase(e, entity["����"]);
				if (dead) { delete e; entity["����"].erase(find(entity["����"].begin(), entity["����"].end(), e)); }
				if (reflectDmg < -1) {
					hp += reflectDmg;
					screen_reset();

					x = 2;
					y = 14;

					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
				}
				act -= skill[n].getAct();
				break;
			case 2:
				if (act < skill[n].getAct()) {

					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
					//cout << endl << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					//break;
				}
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(��ü ���� -" << damage << ")" << endl;
				_getch();
				for (auto e = entity["����"].begin(); e != entity["����"].end();) {
					reflectDmg = Entity::sufferDmg(damage, *e, entity["����"]);
					dead = Entity::entityErase((*e), entity["����"]);
					if (dead) { delete* e; e = entity["����"].erase(e); }
					else e++;
					if (reflectDmg < -1) {
						screen_reset();
						hp += reflectDmg;
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					}
				}
				act -= skill[n].getAct();
				break;
			case 3:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
					//cout << endl << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					//break;
				}
				choiceEntity(entity["����"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(���� ���� -" << damage << ", " << skill[n].getTurn() << "�� ����)" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["����"]);
				dead = Entity::entityErase(e, entity["����"]);
				if (dead) { delete e; entity["����"].erase(find(entity["����"].begin(), entity["����"].end(), e)); }
				if (reflectDmg < -1) {
					screen_reset();
					hp += reflectDmg;
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
				}
				else if (reflectDmg != -1) {
					screen_reset();

					if (!dead) {
						e->setOverpower(-skill[n].getFigure2());
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout  << e->getName() << "�� ���ݷ��� " << skill[n].getFigure2() * 100 << "% �����Ͽ����ϴ�. (" << skill[n].getTurn() / 2 << "�� ����)" << endl;
						y += 2;
					}
					setIncdmg(skill[n].getFigure1());
					gotoxy(x, y + 2); cout  << name << "�� ���ݷ��� " << skill[n].getFigure1() * 100 << "% �����Ͽ����ϴ�. (" << skill[n].getTurn()/2 << "�� ����)" << endl;
				}
				act -= skill[n].getAct();
				break;
			case 4:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
					//cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					//break;
				}
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(��ü ���� ���� ����-" << damage << ", " << skill[n].getTurn() << "�� ����)" << endl;
				_getch();
				for (auto e = entity["����"].begin(); e != entity["����"].end();) {
					reflectDmg = Entity::sufferDmg(damage + (*e)->getDfs() * (1 + (*e)->getIncdfs()), (*e), entity["����"]);
					dead = Entity::entityErase((*e), entity["����"]);
					if (dead) { delete* e; e = entity["����"].erase(e); }
					else e++;

					screen_reset();
					if (reflectDmg > 0) {
						setHp(reflectDmg * 0.3);
						gotoxy(x, y + 2); cout << "ü���� " << reflectDmg * 0.3 << "��ŭ ȸ���Ͽ����ϴ�." << endl;
					}
					else if (reflectDmg < -1) {
						hp += reflectDmg;
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					}
				}
				act -= skill[n].getAct();
				break;
			default:
				cout << "���� ��ų ��ȣ �Դϴ�. �ٽ� �������ּ���" << endl;
				break;
			}
			//print();
		}
	}
};
class Healer : public CharClass {
public:
	Healer(int& j) {
		name = "ġ����" + to_string(j); MaxHp = 80; hp = MaxHp; skillnum = 5;  charseq = j;
		skill = new Skill[skillnum];
		skill[0].setSkill("ġ��", 0, 0, 0, 0, 2);
		skill[1].setSkill("���", 0, 0, 0, 0, 3);
		skill[2].setSkill("����  ����", 35, 0, 0, 0, 4);
		skill[3].setSkill("����", 40, 1, 0.15, 0, 5);
		skill[4].setSkill("������  ����", 0, 5, 0.1, 0, 10);
	}
	void useSkill(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		while (act > 0 && hp > 0) {
			screen_reset();
			console_reset();
			frame();
			int x = 1;
			int y = 0;
			bool empty = entity["����"].empty();
			if (empty) return;
			status_reset();
			//cout << endl << endl << "====================�Ʊ�====================" << endl;
			for (auto a : entity["�Ʊ�"]) { a->print(x, y); y += 4; }
			x = 44;
			y = 0;			
			//cout << endl << endl << "====================����====================" << endl;
			for (auto a : entity["����"]) { a->print(x, y); y += 4; }
			choiceSkill();
			if (n == -1) return;
			else switch (n) {
			case 0:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout  << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					return;
				}
				choiceEntity(entity["�Ʊ�"]);
				if (e == NULL) return;
				e->setHp(15);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << e->getName() <<"�� ü���� 15 ġ���Ǿ����ϴ�." << endl;
				if (rdfunc() % 10 < 2) {
					e->setHp(15);
					gotoxy(x, y + 6); cout << "(!) �߰��� 15 �� ġ���Ǿ����ϴ�." << endl;
				}
				_getch();
				act -= skill[n].getAct();
				break;
			case 1:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["�Ʊ�"]);
				if (e == NULL) return;
				e->setShield(30);
				e->setReflect(30);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << e->getName() << "�� ���尡 30 �����Ͽ����ϴ�." << endl;
				_getch();
				act -= skill[n].getAct();
				break;
			case 2:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["����"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(���� ���� -" << damage << ")" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["����"]);
				dead = Entity::entityErase(e, entity["����"]);
				if (dead) { delete e; entity["����"].erase(find(entity["����"].begin(), entity["����"].end(), e)); }
				if (reflectDmg < -1) {
					hp += reflectDmg;
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					_getch();
				}
				else if (reflectDmg != -1 && !dead) {
					if (rdfunc() % 10 < 6) {
						e->setStern();
						screen_reset();
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout << "���� ������ �ɸ��ϴ�." << endl;
						_getch();
					}
				}
				act -= skill[n].getAct();
				break;
			case 3:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4);cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["����"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				//screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(���� ���� -" << damage << ")" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["����"]);
				dead = Entity::entityErase(e, entity["����"]);
				if (dead) { delete e; entity["����"].erase(find(entity["����"].begin(), entity["����"].end(), e)); }
				if (reflectDmg < -1) {
					hp += reflectDmg;
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					_getch();
				}
				else if (reflectDmg != -1) {
					if (!dead) e->setCursedDoll(-skill[n].getFigure1());
					setHp(20);
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << "ü�� 20��ŭ ȸ���Ͽ����ϴ�." << endl;
					_getch();
				}
				act -= skill[n].getAct();
				break;
			case 4:
				if (act < skill[n].getAct()) {
					
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
				}
				
				screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 2); cout << "�Ʊ� ��ü���� ġ�� 40�� ���� 50, ���� 10% �����մϴ�. (5�� ����)" << endl;
				_getch();

				insertUpperBound(buff["�Ʊ� ���� ����"], skill[n]);
				act -= skill[n].getAct();
				for (auto a : entity["�Ʊ�"]) {
					screen_reset();
					x = 2;
					y = 14;
					a->setHp(40);
					gotoxy(x, y + 2); cout << a->getName() << "�� ü���� 40 ġ���Ǿ����ϴ�." << endl;
					a->setShield(50);
					gotoxy(x, y + 2); cout << a->getName() << "�� ���尡 50 �����Ͽ����ϴ�." << endl;
					a->setIncdfs(skill[n].getFigure1());
					gotoxy(x, y + 2); cout << a->getName() << "�� ������ 10% �����Ͽ����ϴ�." << endl;
					_getch();
				}
				break;
			default:
				cout << "���� ��ų ��ȣ �Դϴ�. �ٽ� �������ּ���" << endl;
				break;
			}
			//print();
		}
	}
};
class Tanker : public CharClass {
public:
	Tanker(int& num) {
		name = "������" + to_string(num); MaxHp = 170; hp = MaxHp; skillnum = 5; charseq = num;
		skill = new Skill[skillnum];
		skill[0].setSkill("����", 0, 1, 0.6, 0, 3);
		skill[1].setSkill("��׷�", 20, 1, 0, 0, 3);
		skill[2].setSkill("���  �±�", 0, 1, 0, 0, 3);
		skill[3].setSkill("����", 50, 0, 0, 0, 4);
		skill[4].setSkill("������  ��ȣ", 0 , 5, 0.5, 0, 10);
	}
	void useSkill(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		
		while (act > 0 && hp > 0) {

			screen_reset();
			console_reset();
			frame();
			int x = 1;
			int y = 0;
			if (entity["����"].size() <= 0) return;
			status_reset();
			//cout << endl << endl << "====================�Ʊ�====================" << endl;
			for (auto a : entity["�Ʊ�"]) { a->print(x, y); y += 4; }
			x = 44;
			y = 0;
			//cout << endl << endl << "====================����====================" << endl;
			for (auto a : entity["����"]) { a->print(x, y); y += 4; }
			choiceSkill();
			if (n == -1) return;
			else switch (n) {
			case 0:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4);cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
				}
				setIncdfs(skill[n].getFigure1());
				guard++;
				act -= skill[n].getAct();
				screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 2); cout << "������ 60%��ŭ �����մϴ�." << endl;
				_getch();
				break;
			case 1:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4);cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					return;
				}
				choiceEntity(entity["����"]);
				if (e == NULL) return;
				damage = dmg + skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(���� ���� -" << damage << ", " << skill[n].getTurn() << "�� ����)" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["����"]);
				dead = Entity::entityErase(e, entity["����"]);
				if (dead) { delete e; entity["����"].erase(find(entity["����"].begin(), entity["����"].end(), e)); }
				if (reflectDmg < -1) {
					hp += reflectDmg;
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					_getch();
				}
				else if(reflectDmg != -1 && !dead) {
					if (rdfunc() % 100 < 55) {
						screen_reset();
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout << "���� ��׷ο� �ɸ��ϴ�." << endl;
						_getch();
						e->setAggro(charseq);
					}
				}
				act -= skill[n].getAct();
				break;
			case 2:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout <<"�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					return;
				}
				choiceEntity(entity["�Ʊ�"]);
				if (e == NULL) return;
				screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 2); cout << e->getName() << "�� ������ ��� �½��ϴ�" << endl;
				if (e->getInstead() == charseq) {
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << "�̹� ����� ����Դϴ�" << endl;
					_getch();
					break;
				}
				e->setInstead(charseq);
				act -= skill[n].getAct();
				break;
			case 3:
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["����"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(���� ���� -" << damage << ", " << skill[n].getTurn() << "�� ����)" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["����"]);
				dead = Entity::entityErase(e, entity["����"]);
				if (reflectDmg < -1) {
					hp += reflectDmg;
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					_getch();
				}
				else if (reflectDmg != -1 && !dead) {
					if (rdfunc() % 10 < 2) {
						screen_reset();
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout << "���� ������ �ɸ��ϴ�." << endl;
						_getch();
						e->setStern();
					}
				}
				act -= skill[n].getAct();
				break;
			case 4:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout <<"�ൿ���� �����Ͽ� ��ų�� ����� �� �����ϴ�." << endl;
					_getch();
					break;
				}
				screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 2); cout << "�Ʊ� ��ü�� ������ +50% �����մϴ�. (5�� ����)" << endl;
				_getch();

				insertUpperBound(buff["�Ʊ� ���� ����"], skill[n]);
				act -= skill[n].getAct();
				for (auto a : entity["�Ʊ�"]) {
					a->setIncdfs(skill[n].getFigure1());
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << a->getName() << "�� ������ +50% �����մϴ�." << endl;
					_getch();
				}
				break;
			default:
				cout << "���� ��ų ��ȣ �Դϴ�. �ٽ� �������ּ���" << endl;
				break;
			}
			//print();
		}
	}
};