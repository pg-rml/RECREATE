#include "Monster.h"
#include "Graphic.h"

	void Rogue::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		
		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;

		
		damage = skill[n].getDmg() * (1 + incdmg);
		if (n == 2) { hide(); return; }
		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;
		gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
		reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
		dead = Entity::entityErase(e, entity["�Ʊ�"]);
		if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
		if (reflectDmg < -1) {
			hp += reflectDmg;
			gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;

			_getch();
		}
	}
	void Rogue::hide() {

		screen_reset();

		int x = 2;
		int y = 14;

		gotoxy(x, y + 2); cout << name << "�� " << skill[2].getName() << "��(��) ����Ͽ����ϴ�. " << endl;
		gotoxy(x, y + 4); cout << name << "�� �׸��ڷ� ���� ����ϴ� (1�� ����)" << endl;
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
			gotoxy(x, y + 2); cout << name << "�� �׸��ڿ��� ���Խ��ϴ�." << endl;
			_getch();
		}
	}
	void Chest::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
		screen_reset();

		int x = 2;
		int y = 14;
		
		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;
		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(��ü ���� -" << damage << ", " << skill[n].getTurn() << "�� ����)" << endl;
			y += 2;
			for (auto a = entity["�Ʊ�"].begin(); a != entity["�Ʊ�"].end();) {
				Entity::sufferDmg(damage, *a, entity["�Ʊ�"], false);
				dead = Entity::entityErase(*a, entity["�Ʊ�"]);
				if (dead) { delete* a; a = entity["�Ʊ�"].erase(a); }
				else a++;
			}
			_getch();
			insertUpperBound(buff["�Ʊ� ���� ������"], skill[n]);
			return;
		}
		if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(��ü ���� -" << damage << ")" << endl;
			y += 2;
			for (auto a = entity["�Ʊ�"].begin(); a != entity["�Ʊ�"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *a, entity["�Ʊ�"]);
				dead = Entity::entityErase(*a, entity["�Ʊ�"]);
				if (dead) { delete* a; a = entity["�Ʊ�"].erase(a); }
				else a++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					_getch();
				}
			}
			return;
		}
		if (n == 2) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
			y += 2;
			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["�Ʊ�"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
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
		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg();
			gotoxy(x, y + 2);cout << "(��ü ���� -" << damage << ", " << skill[n].getTurn() << "�� ����)" << endl;
			y += 2;
			for (auto e = entity["�Ʊ�"].begin(); e != entity["�Ʊ�"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *e, entity["�Ʊ�"]);
				dead = Entity::entityErase((*e), entity["�Ʊ�"]);
				if (dead) { delete* e; e = entity["�Ʊ�"].erase(e); }
				else e++;
				insertUpperBound(buff["�Ʊ� ���� ������"], skill[n]);
				insertUpperBound(buff["�Ʊ� �ൿ�� ����"], skill[n]);
			}
		}
		else if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
			y += 2;
			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["����"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
				y += 2;
			}
		}
		else if (n == 2) {
			gotoxy(x, y + 2); cout << "(ü�� ȸ�� +10)" << endl;
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

		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["�Ʊ�"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
			}
		}
		else if (n == 1) {
			gotoxy(x, y + 2); cout << "���ݷ��� 5% �����մϴ�. (3�� ����)" << endl;
			incdmg += skill[n].getFigure1();
			tear = 3;
		}
		else if (n == 2) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["�Ʊ�"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
			}

		}

		_getch();

	}
	void Locust::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {

		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;

		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(��ü ���� -" << damage << ")" << endl;
			y += 2;
			for (auto e = entity["�Ʊ�"].begin(); e != entity["�Ʊ�"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *e, entity["�Ʊ�"]);
				dead = Entity::entityErase((*e), entity["�Ʊ�"]);
				if (dead) { delete* e; e = entity["�Ʊ�"].erase(e); }
				else e++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					y += 2;
				}
			}
			insertUpperBound(buff["�Ʊ� �ൿ�� ����"], skill[n]);
			gotoxy(x, y + 2); cout << endl << "�Ʊ��� �ൿ���� 1 �����մϴ�." << endl;
			_getch();
			return;
		}
		else if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(��ü ���� -" << damage << ")" << endl;
			y += 2;
			for (auto e = entity["�Ʊ�"].begin(); e != entity["�Ʊ�"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *e, entity["�Ʊ�"]);
				dead = Entity::entityErase((*e), entity["�Ʊ�"]);
				if (dead) { delete* e; e = entity["�Ʊ�"].erase(e); }
				else e++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
				}
			}
			_getch();
			return;
		}
		else if (n == 2) {
			insertUpperBound(buff["�Ʊ� ���ݷ� ����"], skill[n]);
			for (auto e : entity["�Ʊ�"]) {
				e->setIncdmg(-skill[n].getFigure1());
				gotoxy(x, y + 2); cout << endl << e->getName() << "�� ���ݷ��� 5% �����Ͽ����ϴ�." << endl;
			}
		}
		_getch();
	}

	void Snake::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {

		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;
		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(��ü ���� -" << damage << ")" << endl;
			y += 2;
			for (auto e = entity["�Ʊ�"].begin(); e != entity["�Ʊ�"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *e, entity["�Ʊ�"]);
				dead = Entity::entityErase((*e), entity["�Ʊ�"]);
				if (dead) { delete* e; e = entity["�Ʊ�"].erase(e); }
				else e++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					_getch();
				}
			}
			return;
		}
		else if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["�Ʊ�"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
			}
			_getch();
			return;
		}
		else if (n == 2) {
			gotoxy(x, y + 2); cout << endl << name << "�� ���ݷ°� ������ 7% �����մϴ�." << endl;
			y += 2;

			gotoxy(x, y + 2); cout << name << "�� ü���� 10 ġ���Ǿ����ϴ�." << endl;
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
		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
			y += 2;
			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["�Ʊ�"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
				_getch();
			}
			return;
		}
		else if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(��ü ���� -" << damage << ")" << endl;
			y += 2;

			for (auto e = entity["�Ʊ�"].begin(); e != entity["�Ʊ�"].end();) {
				reflectDmg = Entity::sufferDmg(damage, *e, entity["�Ʊ�"]);
				dead = Entity::entityErase((*e), entity["�Ʊ�"]);
				if (dead) { delete* e; e = entity["�Ʊ�"].erase(e); }
				else e++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					_getch();
				}
			}
			return;
		}
		else if (n == 2) {
			gotoxy(x, y + 2); cout << endl << "�Ʊ��� ���ݷ��� 10% �����մϴ�." << endl;
			y += 2;
			_getch();
			insertUpperBound(buff["�Ʊ� ���ݷ� ����"], skill[n]);
			for (auto a : entity["�Ʊ�"])
				a->setIncdmg(-skill[n].getFigure1());
		}
	}
	void Wolf::useSkill(const int n, Entity* e, map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {

		screen_reset();
		console_reset();

		int x = 2;
		int y = 14;
		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;
		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
			y += 2;
			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["�Ʊ�"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;

				_getch();
			}
			return;
		}
		else if (n == 1) {
			gotoxy(x, y + 2); cout << endl << "�Ʊ��� ���ݷ°� ������ 10% �����մϴ�." << endl;
			y += 2;
			insertUpperBound(buff["�Ʊ� ���� ����"], skill[n]);
			for (auto a : entity["�Ʊ�"]) {
				a->setIncdfs(skill[n].getFigure1());
				a->setIncdmg(skill[n].getFigure1());
			}
		}
		else if (n == 2) {
			gotoxy(x, y + 2); cout << endl << name << "�� ü���� 15 ġ���Ǿ����ϴ�." << endl;
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
		if (entity["����"].size() <= 1 && n == 2) {
			n = rdfunc() % 2;
		}
		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["�Ʊ�"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
				_getch();
			}
			return;
		}
		else if (n == 1) {
			gotoxy(x, y + 2); cout << endl << "���� ������ �ݻ��մϴ�. (1�� ����)" << endl;
			y += 2;
			reflect = true;
		}
		else if (n == 2) {
			auto minElement = min_element(entity["����"].begin(), entity["����"].end(), [](Entity* a, Entity* b) {
				return a->getHp() < b->getHp(); });
			(*minElement)->setHp(-(*minElement)->getMaxHp());
			gotoxy(x, y + 2); cout << endl << (*minElement)->getName() << "�� ����Ǿ����ϴ�." << endl;
			y += 2;
			for (auto it = entity["����"].begin(); it != entity["����"].end();) {
				if ((*it)->getHp() > 0) {
					(*it)->setIncdfs(skill[n].getFigure2());
					(*it)->setIncdmg(skill[n].getFigure1());
					gotoxy(x, y + 2); cout << (*it)->getName() << "�� ���ݷ��� 15%, ������ 10% �����մϴ�." << endl;
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
		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;

		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["�Ʊ�"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
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
				e = target(entity["�Ʊ�"]);
				gotoxy(x, y + 2); cout << endl;
				damage = d * (1 + incdmg);
				reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
				dead = Entity::entityErase(e, entity["�Ʊ�"]);
				if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					_getch();
				}
			}
			return;
		}
		else if (n == 2) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(��ü ���� -" << damage << ")" << endl;
			y += 2;

			for (auto a = entity["�Ʊ�"].begin(); a != entity["�Ʊ�"].end();) {
				Entity::sufferDmg(damage, *a, entity["�Ʊ�"], false);
				dead = Entity::entityErase(*a, entity["�Ʊ�"]);
				if (dead) { delete* a; a = entity["�Ʊ�"].erase(a); }
				else a++;
				if (reflectDmg < -1) {
					hp += reflectDmg;
					gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
					y += 2;

				}
				else if (rdfunc() % 10 < 3) {
					e->setStern();
					gotoxy(x, y + 2); cout << e->getName() << "��(��) ������ �ɷȽ��ϴ�." << endl;
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
			gotoxy(x, y + 2); cout << endl << "ü�� 40 ġ���Ǿ����ϴ�. ���� �Ͽ� ���ݷ��� 20% �����մϴ�." << endl;
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
		gotoxy(x, y + 2); cout << name << "�� " << skill[n].getName() << "��(��) ����Ͽ����ϴ�. ";
		y += 2;
		if (n == 0) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� ���� -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["����"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
				y += 2;

			}
			else {
				e->setStern();
				gotoxy(x, y + 2); cout << e->getName() << "��(��) �ൿ �Ұ��� �ɷȽ��ϴ�." << endl;
				y += 2;

			}
			_getch();
			return;
		}
		else if (n == 1) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� ���� ���� -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage + e->getDfs() * (1 + e->getIncdfs()), e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["����"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
				y += 2;

			}
			_getch();
			return;
		}
		else if (n == 2) {
			damage = skill[n].getDmg() * (1 + incdmg);
			gotoxy(x, y + 2); cout << "(���� ���� -" << damage << ")" << endl;
			y += 2;

			reflectDmg = Entity::sufferDmg(damage, e, entity["�Ʊ�"]);
			dead = Entity::entityErase(e, entity["����"]);
			if (dead) { delete e; entity["�Ʊ�"].erase(find(entity["�Ʊ�"].begin(), entity["�Ʊ�"].end(), e)); }
			if (reflectDmg < -1) {
				hp += reflectDmg;
				gotoxy(x, y + 2); cout << name << "�� ü��: " << hp << endl;
				y += 2;

			}
			_getch();
			return;
		}
		else if (n == 3) {
			insertUpperBound(buff["�Ʊ� �ൿ�� ����"], skill[n]);
			gotoxy(x, y + 2); cout << endl << "�Ʊ��� �ൿ���� 4 �����մϴ�." << endl;
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
			gotoxy(x, y + 2); cout << endl << name << "�� ü�� " << aura[auracount] << "�� ȸ���Ͽ����ϴ�." << endl;
			_getch();

		}
	}