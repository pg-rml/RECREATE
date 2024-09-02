#include "Monster.h"
#include "Graphic.h"

	void Rogue::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		
		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;

		
		damage = skill[n].getDmg() * (1 + incdmg);
		if (n == 2) { hide(); return; }
		gotoxy(x, y + 2); cout << name << "이 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;
		gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
		reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
		dead = Entity::entityErase(e, entity["아군"]);
		if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
		if (reflectDmg < -1) {
			hp += reflectDmg;
			gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;

			_getch();
		}
	}
	void Rogue::hide() {

		screen_reset();

		int x = 2;
		int y = 14;

		gotoxy(x, y + 2); cout << name << "이 " << skill[2].getName() << "을(를) 사용하였습니다. " << endl;
		gotoxy(x, y + 4); cout << name << "이 그림자로 몸을 숨깁니다 (1턴 지속)" << endl;
		hidden = true;

		_getch();
	}
	void Rogue::hideOnOff() {

		screen_reset();

		int x = 2;
		int y = 14;

		if (hidden == false) hidden = true;
		else {
			hidden = false;
			gotoxy(x, y + 2); cout << name << "이 그림자에서 나왔습니다." << endl;
			_getch();
		}
	}
	void Chest::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		screen_reset();

		int x = 2;
		int y = 14;
		
		gotoxy(x, y + 2); cout << name << "이 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;
		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단체 공격 -" << damage << ", " << skill[n].getTurn() << "턴 지속)" << endl;
			y += 2;
			for (auto a = entity["아군"].begin(); a != entity["아군"].end();) {
				Entity::sufferDmg(damage, *a, entity["아군"], false);
				dead = Entity::entityErase(*a, entity["아군"]);
				if (dead) { delete* a; a = entity["아군"].erase(a); }
				else a++;
			}
			_getch();
			insertUpperBound(buff["아군 지속 데미지"], skill[n]);
			return;
		}
		if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단체 공격 -" << damage << ")" << endl;
			y += 2;
			for (auto a = entity["아군"].begin(); a != entity["아군"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *a, entity["아군"]);
				dead = Entity::entityErase(*a, entity["아군"]);
				if (dead) { delete* a; a = entity["아군"].erase(a); }
				else a++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					_getch();
				}
			}
			return;
		}
		if (n == 2) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
			y += 2;
			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["아군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				_getch();
			}
			return;
		}
	}


	void Toad::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {

		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;
		gotoxy(x, y + 2); cout << name << "가 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg();
			gotoxy(x, y + 2);cout << "(단체 공격 -" << damage << ", " << skill[n].getTurn() << "턴 지속)" << endl;
			y += 2;
			for (auto e = entity["아군"].begin(); e != entity["아군"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *e, entity["아군"]);
				dead = Entity::entityErase((*e), entity["아군"]);
				if (dead) { delete* e; e = entity["아군"].erase(e); }
				else e++;
				insertUpperBound(buff["아군 지속 데미지"], skill[n]);
				insertUpperBound(buff["아군 행동력 감소"], skill[n]);
			}
		}
		else if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
			y += 2;
			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["적군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				y += 2;
			}
		}
		else if (n == 2) {
			gotoxy(x, y + 2); cout << "(체력 회복 +10)" << endl;
			y += 2;
			setHp(10);
		}

		_getch();

	}


	void Crocodile::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		
		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;

		gotoxy(x, y + 2); cout << name << "가 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["아군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
			}
		}
		else if (n == 1) {
			gotoxy(x, y + 2); cout << "공격력이 5% 증가합니다. (3턴 지속)" << endl;
			incdmg += skill[n].getFigure1();
			tear = 3;
		}
		else if (n == 2) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["아군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
			}

		}

		_getch();

	}
	void Locust::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {

		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;

		gotoxy(x, y + 2); cout << name << "가 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단체 공격 -" << damage << ")" << endl;
			y += 2;
			for (auto e = entity["아군"].begin(); e != entity["아군"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *e, entity["아군"]);
				dead = Entity::entityErase((*e), entity["아군"]);
				if (dead) { delete* e; e = entity["아군"].erase(e); }
				else e++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					y += 2;
				}
			}
			insertUpperBound(buff["아군 행동력 감소"], skill[n]);
			gotoxy(x, y + 2); cout << endl << "아군의 행동력이 1 감소합니다." << endl;
			_getch();
			return;
		}
		else if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단체 공격 -" << damage << ")" << endl;
			y += 2;
			for (auto e = entity["아군"].begin(); e != entity["아군"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *e, entity["아군"]);
				dead = Entity::entityErase((*e), entity["아군"]);
				if (dead) { delete* e; e = entity["아군"].erase(e); }
				else e++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				}
			}
			_getch();
			return;
		}
		else if (n == 2) {
			insertUpperBound(buff["아군 공격력 감소"], skill[n]);
			for (auto e : entity["아군"]) {
				e->setIncdmg(-skill[n].getFigure1());
				gotoxy(x, y + 2); cout << endl << e->getName() << "의 공격력이 5% 감소하였습니다." << endl;
			}
		}
		_getch();
	}

	void Snake::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {

		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;
		gotoxy(x, y + 2); cout << name << "가 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단체 공격 -" << damage << ")" << endl;
			y += 2;
			for (auto e = entity["아군"].begin(); e != entity["아군"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *e, entity["아군"]);
				dead = Entity::entityErase((*e), entity["아군"]);
				if (dead) { delete* e; e = entity["아군"].erase(e); }
				else e++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					_getch();
				}
			}
			return;
		}
		else if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["아군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
			}
			_getch();
			return;
		}
		else if (n == 2) {
			gotoxy(x, y + 2); cout << endl << name << "의 공격력과 방어력이 7% 증가합니다." << endl;
			y += 2;

			gotoxy(x, y + 2); cout << name << "의 체력이 10 치유되었습니다." << endl;
			y += 2;
			_getch();

			molt = 3;
			incdmg += skill[n].getFigure1();
			incdfs += skill[n].getFigure1();
			setHp(10);

			//_getch();
		}
	}
	void Harpy::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {

		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;
		gotoxy(x, y + 2); cout << name << "가 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
			y += 2;
			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["아군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				_getch();
			}
			return;
		}
		else if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단체 공격 -" << damage << ")" << endl;
			y += 2;

			for (auto e = entity["아군"].begin(); e != entity["아군"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *e, entity["아군"]);
				dead = Entity::entityErase((*e), entity["아군"]);
				if (dead) { delete* e; e = entity["아군"].erase(e); }
				else e++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					_getch();
				}
			}
			return;
		}
		else if (n == 2) {
			gotoxy(x, y + 2); cout << endl << "아군의 공격력이 10% 감소합니다." << endl;
			y += 2;
			_getch();
			insertUpperBound(buff["아군 공격력 감소"], skill[n]);
			for (auto a : entity["아군"])
				a->setIncdmg(-skill[n].getFigure1());
		}
	}
	void Wolf::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {

		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;
		gotoxy(x, y + 2); cout << name << "가 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;
		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
			y += 2;
			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["아군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;

				_getch();
			}
			return;
		}
		else if (n == 1) {
			gotoxy(x, y + 2); cout << endl << "아군의 공격력과 방어력이 10% 감소합니다." << endl;
			y += 2;
			insertUpperBound(buff["아군 스탯 감소"], skill[n]);
			for (auto a : entity["아군"]) {
				a->setIncdfs(skill[n].getFigure1());
				a->setIncdmg(skill[n].getFigure1());
			}
		}
		else if (n == 2) {
			gotoxy(x, y + 2); cout << endl << name << "의 체력이 15 치유되었습니다." << endl;
			y += 2;

			setHp(15);
		}
		_getch();
	}
	void Believer::useSkill(int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {

		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;
		if (entity["적군"].size() <= 1 && n == 2) {
			n = rdfunc() % 2;
		}
		gotoxy(x, y + 2); cout << name << "가 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["아군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				_getch();
			}
			return;
		}
		else if (n == 1) {
			gotoxy(x, y + 2); cout << endl << "적의 공격을 반사합니다. (1턴 지속)" << endl;
			y += 2;
			reflect = true;
		}
		else if (n == 2) {
			auto minElement = min_element(entity["적군"].begin(), entity["적군"].end(), [](Entity* a, Entity* b) {
				return a->getHp() < b->getHp(); });
			(*minElement)->setHp(-(*minElement)->getMaxHp());
			gotoxy(x, y + 2); cout << endl << (*minElement)->getName() << "가 희생되었습니다." << endl;
			y += 2;
			for (auto it = entity["적군"].begin(); it != entity["적군"].end();) {
				if ((*it)->getHp() > 0) {
					(*it)->setIncdfs(skill[n].getFigure2());
					(*it)->setIncdmg(skill[n].getFigure1());
					gotoxy(x, y + 2); cout << (*it)->getName() << "가 공격력이 15%, 방어력이 10% 증가합니다." << endl;
					_getch();
				}
				it++;
			}
		}
		_getch();
	}
	void Angel::useSkill(int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;
		gotoxy(x, y + 2); cout << name << "가 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["아군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				_getch();
			}
			return;
		}

		else if (n == 1) {

			vector<float> abc;
			for (int i = 0; i < 2; i++)
				abc.push_back(rdfunc() % 49 + 1);
			sort(abc.begin(), abc.end());
			vector<int> result;
			result.push_back(abc[0]);
			result.push_back(abc[1] - abc[0]);
			result.push_back(40 - abc[1]);
			for (int d : result) {
				e = target(entity["아군"]);
				gotoxy(x, y + 2); cout << endl;
				damage = d * (1 + incdmg);
				reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
				dead = Entity::entityErase(e, entity["아군"]);
				if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					_getch();
				}
			}
			return;
		}
		else if (n == 2) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단체 공격 -" << damage << ")" << endl;
			y += 2;

			for (auto a = entity["아군"].begin(); a != entity["아군"].end();) {
				Entity::sufferDmg(damage, *a, entity["아군"], false);
				dead = Entity::entityErase(*a, entity["아군"]);
				if (dead) { delete* a; a = entity["아군"].erase(a); }
				else a++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
					y += 2;

				}
				else if (rdfunc() % 10 < 3) {
					e->setStern();
					gotoxy(x, y + 2); cout << e->getName() << "이(가) 기절에 걸렸습니다." << endl;
					y += 2;

				}
			}
			_getch();
			return;
		}
		else if (n == 3) {
			setHp(30);
			holy = 1;
			incdmg += skill[n].getFigure1();
			gotoxy(x, y + 2); cout << endl << "체력 40 치유되었습니다. 다음 턴에 공격력이 20% 증가합니다." << endl;
			_getch();
		}
	}

	void God::useSkill(int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;
		if (auracount != NULL && n == 4)
			n = rdfunc() % 4;
		gotoxy(x, y + 2); cout << name << "가 " << skill[n].getName() << "을(를) 사용하였습니다. ";
		y += 2;
		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 스턴 공격 -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["적군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				y += 2;

			}
			else {
				e->setStern();
				gotoxy(x, y + 2); cout << e->getName() << "이(가) 행동 불가에 걸렸습니다." << endl;
				y += 2;

			}
			_getch();
			return;
		}
		else if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 방어력 무시 공격 -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage + e->getDfs() * (1 + e->getIncdfs()), e, entity["아군"]);
			dead = Entity::entityErase(e, entity["적군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				y += 2;

			}
			_getch();
			return;
		}
		else if (n == 2) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(단일 공격 -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["아군"]);
			dead = Entity::entityErase(e, entity["적군"]);
			if (dead) { delete e; entity["아군"].erase(find(entity["아군"].begin(), entity["아군"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "의 체력: " << hp << endl;
				y += 2;

			}
			_getch();
			return;
		}
		else if (n == 3) {
			insertUpperBound(buff["아군 행동력 감소"], skill[n]);
			gotoxy(x, y + 2); cout << endl << "아군의 행동력이 4 감소합니다." << endl;
			_getch();
			return;
		}
		else if (n == 4) {
			vector<float> abc;
			for (int i = 0; i < 4; i++)
				abc.push_back(rdfunc() % 99 + 1);
			sort(abc.begin(), abc.end());
			aura.push_back(abc[0]);
			aura.push_back(abc[1] - abc[0]);
			aura.push_back(abc[2] - abc[1]);
			aura.push_back(abc[3] - abc[2]);
			aura.push_back(100 - abc[3]);
			auracount = 4;
			setHp(aura[auracount]);
			gotoxy(x, y + 2); cout << endl << name << "이 체력 " << aura[auracount] << "을 회복하였습니다." << endl;
			_getch();

		}
	}