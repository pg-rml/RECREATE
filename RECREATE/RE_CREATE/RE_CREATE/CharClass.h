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
		if (equipment[i] == nullptr) return "○";
		else return "●";
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

			gotoxy(x, y); cout << "│ \033[94m장비를 교체한다 \033[90m(1)\033[0m│ " << "│ \033[94m교체하지 않는다 \033[90m(2)\033[0m│ ";
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
		name = "용병" + to_string(j); MaxHp = 100; hp = MaxHp; skillnum = 5; charseq = j;
		skill = new Skill[skillnum];
		skill[0].setSkill("찌르기", 35, 0, 0, 0, 3);
		skill[1].setSkill("깊게  베기", 30, 0, 0, 0, 4);
		skill[2].setSkill("권총  사격", 25, 0, 0, 0, 5);
		skill[3].setSkill("기선  제압", 20, 3, 0.15, 0.1, 5);
		skill[4].setSkill("붉은  검기", 70, 0, 0, 0, 10);
	}
	void useSkill(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		while (act > 0 && hp > 0) {
			screen_reset();
			console_reset();
			frame();
			int x = 1;
			int y = 0;
			if (entity["적군"].size() <= 0) return;
			status_reset();
			//cout << endl << "====================아군====================" << endl;
			for (auto a : entity["아군"]) { a->print(x, y); y += 4; }
			x = 44;
			y = 0;
			//cout << endl << "====================적군====================" << endl;
			for (auto a : entity["적군"]) { a->print(x, y); y += 4; }
			choiceSkill();
			if (n == -1) return;
			else switch (n) {
			case 0:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					console_reset();
					gotoxy(x, y + 4); cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["적군"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(단일 공격 -" << damage << ")" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["적군"]);
				dead = Entity::entityErase(e, entity["적군"]);
				if (dead) { delete e; entity["적군"].erase(find(entity["적군"].begin(), entity["적군"].end(), e)); }
				if (reflectDmg < -1) {

					screen_reset();

					x = 2;
					y = 14;

					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				}
				act -= skill[n].getAct();
				break;
			case 1:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["적군"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(단일 방어력 무시 공격 -" << damage << ")" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["적군"]);
				dead = Entity::entityErase(e, entity["적군"]);
				if (dead) { delete e; entity["적군"].erase(find(entity["적군"].begin(), entity["적군"].end(), e)); }
				if (reflectDmg < -1) {
					hp += reflectDmg;
					screen_reset();

					x = 2;
					y = 14;

					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				}
				act -= skill[n].getAct();
				break;
			case 2:
				if (act < skill[n].getAct()) {

					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
					//cout << endl << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					//break;
				}
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(단체 공격 -" << damage << ")" << endl;
				_getch();
				for (auto e = entity["적군"].begin(); e != entity["적군"].end();) {
					reflectDmg = Entity::sufferDmg(damage, *e, entity["적군"]);
					dead = Entity::entityErase((*e), entity["적군"]);
					if (dead) { delete* e; e = entity["적군"].erase(e); }
					else e++;
					if (reflectDmg < -1) {
						screen_reset();
						hp += reflectDmg;
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					}
				}
				act -= skill[n].getAct();
				break;
			case 3:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
					//cout << endl << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					//break;
				}
				choiceEntity(entity["적군"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(단일 공격 -" << damage << ", " << skill[n].getTurn() << "턴 지속)" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["적군"]);
				dead = Entity::entityErase(e, entity["적군"]);
				if (dead) { delete e; entity["적군"].erase(find(entity["적군"].begin(), entity["적군"].end(), e)); }
				if (reflectDmg < -1) {
					screen_reset();
					hp += reflectDmg;
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				}
				else if (reflectDmg != -1) {
					screen_reset();

					if (!dead) {
						e->setOverpower(-skill[n].getFigure2());
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout  << e->getName() << "의 공격력이 " << skill[n].getFigure2() * 100 << "% 감소하였습니다. (" << skill[n].getTurn() / 2 << "턴 지속)" << endl;
						y += 2;
					}
					setIncdmg(skill[n].getFigure1());
					gotoxy(x, y + 2); cout  << name << "의 공격력이 " << skill[n].getFigure1() * 100 << "% 증가하였습니다. (" << skill[n].getTurn()/2 << "턴 지속)" << endl;
				}
				act -= skill[n].getAct();
				break;
			case 4:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
					//cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					//break;
				}
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(단체 방어력 무시 공격-" << damage << ", " << skill[n].getTurn() << "턴 지속)" << endl;
				_getch();
				for (auto e = entity["적군"].begin(); e != entity["적군"].end();) {
					reflectDmg = Entity::sufferDmg(damage + (*e)->getDfs() * (1 + (*e)->getIncdfs()), (*e), entity["적군"]);
					dead = Entity::entityErase((*e), entity["적군"]);
					if (dead) { delete* e; e = entity["적군"].erase(e); }
					else e++;

					screen_reset();
					if (reflectDmg > 0) {
						setHp(reflectDmg * 0.3);
						gotoxy(x, y + 2); cout << "체력을 " << reflectDmg * 0.3 << "만큼 회복하였습니다." << endl;
					}
					else if (reflectDmg < -1) {
						hp += reflectDmg;
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					}
				}
				act -= skill[n].getAct();
				break;
			default:
				cout << "없는 스킬 번호 입니다. 다시 선택해주세요" << endl;
				break;
			}
			//print();
		}
	}
};
class Healer : public CharClass {
public:
	Healer(int& j) {
		name = "치유사" + to_string(j); MaxHp = 80; hp = MaxHp; skillnum = 5;  charseq = j;
		skill = new Skill[skillnum];
		skill[0].setSkill("치유", 0, 0, 0, 0, 2);
		skill[1].setSkill("방어", 0, 0, 0, 0, 3);
		skill[2].setSkill("저주  인형", 35, 0, 0, 0, 4);
		skill[3].setSkill("갈증", 40, 1, 0.15, 0, 5);
		skill[4].setSkill("생명의  샘물", 0, 5, 0.1, 0, 10);
	}
	void useSkill(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		while (act > 0 && hp > 0) {
			screen_reset();
			console_reset();
			frame();
			int x = 1;
			int y = 0;
			bool empty = entity["적군"].empty();
			if (empty) return;
			status_reset();
			//cout << endl << endl << "====================아군====================" << endl;
			for (auto a : entity["아군"]) { a->print(x, y); y += 4; }
			x = 44;
			y = 0;			
			//cout << endl << endl << "====================적군====================" << endl;
			for (auto a : entity["적군"]) { a->print(x, y); y += 4; }
			choiceSkill();
			if (n == -1) return;
			else switch (n) {
			case 0:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout  << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					return;
				}
				choiceEntity(entity["아군"]);
				if (e == NULL) return;
				e->setHp(15);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << e->getName() <<"의 체력이 15 치유되었습니다." << endl;
				if (rdfunc() % 10 < 2) {
					e->setHp(15);
					gotoxy(x, y + 6); cout << "(!) 추가로 15 더 치유되었습니다." << endl;
				}
				_getch();
				act -= skill[n].getAct();
				break;
			case 1:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["아군"]);
				if (e == NULL) return;
				e->setShield(30);
				e->setReflect(30);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << e->getName() << "의 쉴드가 30 증가하였습니다." << endl;
				_getch();
				act -= skill[n].getAct();
				break;
			case 2:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["적군"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(단일 공격 -" << damage << ")" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["적군"]);
				dead = Entity::entityErase(e, entity["적군"]);
				if (dead) { delete e; entity["적군"].erase(find(entity["적군"].begin(), entity["적군"].end(), e)); }
				if (reflectDmg < -1) {
					hp += reflectDmg;
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					_getch();
				}
				else if (reflectDmg != -1 && !dead) {
					if (rdfunc() % 10 < 6) {
						e->setStern();
						screen_reset();
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout << "적이 기절에 걸립니다." << endl;
						_getch();
					}
				}
				act -= skill[n].getAct();
				break;
			case 3:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4);cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["적군"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				//screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(단일 공격 -" << damage << ")" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["적군"]);
				dead = Entity::entityErase(e, entity["적군"]);
				if (dead) { delete e; entity["적군"].erase(find(entity["적군"].begin(), entity["적군"].end(), e)); }
				if (reflectDmg < -1) {
					hp += reflectDmg;
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					_getch();
				}
				else if (reflectDmg != -1) {
					if (!dead) e->setCursedDoll(-skill[n].getFigure1());
					setHp(20);
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << "체력 20만큼 회복하였습니다." << endl;
					_getch();
				}
				act -= skill[n].getAct();
				break;
			case 4:
				if (act < skill[n].getAct()) {
					
					x = 2;
					y = 14;
					gotoxy(x, y + 4); cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
				}
				
				screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 2); cout << "아군 전체에게 치유 40과 쉴드 50, 방어력 10% 증가합니다. (5턴 지속)" << endl;
				_getch();

				insertUpperBound(buff["아군 방어력 증가"], skill[n]);
				act -= skill[n].getAct();
				for (auto a : entity["아군"]) {
					screen_reset();
					x = 2;
					y = 14;
					a->setHp(40);
					gotoxy(x, y + 2); cout << a->getName() << "의 체력이 40 치유되었습니다." << endl;
					a->setShield(50);
					gotoxy(x, y + 2); cout << a->getName() << "의 쉴드가 50 증가하였습니다." << endl;
					a->setIncdfs(skill[n].getFigure1());
					gotoxy(x, y + 2); cout << a->getName() << "의 방어력이 10% 증가하였습니다." << endl;
					_getch();
				}
				break;
			default:
				cout << "없는 스킬 번호 입니다. 다시 선택해주세요" << endl;
				break;
			}
			//print();
		}
	}
};
class Tanker : public CharClass {
public:
	Tanker(int& num) {
		name = "돌격자" + to_string(num); MaxHp = 170; hp = MaxHp; skillnum = 5; charseq = num;
		skill = new Skill[skillnum];
		skill[0].setSkill("가드", 0, 1, 0.6, 0, 3);
		skill[1].setSkill("어그로", 20, 1, 0, 0, 3);
		skill[2].setSkill("대신  맞기", 0, 1, 0, 0, 3);
		skill[3].setSkill("돌진", 50, 0, 0, 0, 4);
		skill[4].setSkill("전사의  수호", 0 , 5, 0.5, 0, 10);
	}
	void useSkill(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		
		while (act > 0 && hp > 0) {

			screen_reset();
			console_reset();
			frame();
			int x = 1;
			int y = 0;
			if (entity["적군"].size() <= 0) return;
			status_reset();
			//cout << endl << endl << "====================아군====================" << endl;
			for (auto a : entity["아군"]) { a->print(x, y); y += 4; }
			x = 44;
			y = 0;
			//cout << endl << endl << "====================적군====================" << endl;
			for (auto a : entity["적군"]) { a->print(x, y); y += 4; }
			choiceSkill();
			if (n == -1) return;
			else switch (n) {
			case 0:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4);cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
				}
				setIncdfs(skill[n].getFigure1());
				guard++;
				act -= skill[n].getAct();
				screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 2); cout << "방어력이 60%만큼 증가합니다." << endl;
				_getch();
				break;
			case 1:
				if (act < skill[n].getAct()) {
					x = 2;
					y = 14;
					gotoxy(x, y + 4);cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					return;
				}
				choiceEntity(entity["적군"]);
				if (e == NULL) return;
				damage = dmg + skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(단일 공격 -" << damage << ", " << skill[n].getTurn() << "턴 지속)" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["적군"]);
				dead = Entity::entityErase(e, entity["적군"]);
				if (dead) { delete e; entity["적군"].erase(find(entity["적군"].begin(), entity["적군"].end(), e)); }
				if (reflectDmg < -1) {
					hp += reflectDmg;
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					_getch();
				}
				else if(reflectDmg != -1 && !dead) {
					if (rdfunc() % 100 < 55) {
						screen_reset();
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout << "적이 어그로에 걸립니다." << endl;
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
					gotoxy(x, y + 4); cout <<"행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					return;
				}
				choiceEntity(entity["아군"]);
				if (e == NULL) return;
				screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 2); cout << e->getName() << "의 공격을 대신 맞습니다" << endl;
				if (e->getInstead() == charseq) {
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << "이미 적용된 대상입니다" << endl;
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
					gotoxy(x, y + 4); cout << "행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
				}
				choiceEntity(entity["적군"]);
				if (e == NULL) return;
				damage = dmg +skill[n].getDmg() * (1 + incdmg);
				x = 2;
				y = 14;
				gotoxy(x, y + 4); cout << "(단일 공격 -" << damage << ", " << skill[n].getTurn() << "턴 지속)" << endl;
				_getch();
				reflectDmg = Entity::sufferDmg(damage, e, entity["적군"]);
				dead = Entity::entityErase(e, entity["적군"]);
				if (reflectDmg < -1) {
					hp += reflectDmg;
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					_getch();
				}
				else if (reflectDmg != -1 && !dead) {
					if (rdfunc() % 10 < 2) {
						screen_reset();
						x = 2;
						y = 14;
						gotoxy(x, y + 2); cout << "적이 기절에 걸립니다." << endl;
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
					gotoxy(x, y + 4); cout <<"행동력이 부족하여 스킬을 사용할 수 없습니다." << endl;
					_getch();
					break;
				}
				screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 2); cout << "아군 전체의 방어력이 +50% 증가합니다. (5턴 지속)" << endl;
				_getch();

				insertUpperBound(buff["아군 방어력 증가"], skill[n]);
				act -= skill[n].getAct();
				for (auto a : entity["아군"]) {
					a->setIncdfs(skill[n].getFigure1());
					screen_reset();
					x = 2;
					y = 14;
					gotoxy(x, y + 2); cout << a->getName() << "의 방어력이 +50% 증가합니다." << endl;
					_getch();
				}
				break;
			default:
				cout << "없는 스킬 번호 입니다. 다시 선택해주세요" << endl;
				break;
			}
			//print();
		}
	}
};