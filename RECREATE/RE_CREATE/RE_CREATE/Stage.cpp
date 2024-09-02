#include "Stage.h"
#include "UI.h"
#include "Graphic.h"

Stage::Stage() {
	while (1) {

		int x = 2;
		int y = 14;

		system("cls");
		frame();
		setMonster(Player::loc);
		stage(Player::loc->floor, Player::loc->stage);

		//cout << Player::loc->floor << "�� " << Player::loc->stage << "�������� ���� ����!";
		if (battleStart()) return;
		if (Player::loc->stage == 2 && (Player::loc->floor == 1 || Player::loc->floor == 4 || Player::loc->floor == 7)) {
			
			screen_reset();
			x = 2;
			y = 14;

			gotoxy(x, y + 2); cout << "���� ���� �߰�!" << endl;
			y += 2;
			_getch();
			if (rdfunc() % 10 < 2) {
				gotoxy(x, y + 2); cout << "�̹��� �����ߴ�! " << endl;
				y += 2;
				_getch();
				entity["����"].push_back(new Chest("�̹�"));
				if (battleStart()) return;
			}
			else {
				gotoxy(x, y + 2); cout << "������ �޾Ҵ�" << endl;
				dropitemnum += rdfunc() % 4 + 2;
				gotoxy(x, y + 2); cout << "������ " << dropitemnum << "���� ȹ���Ͽ����ϴ�." << endl;
				y += 2;

				for (; dropitemnum != 0; dropitemnum--) {
					gotoxy(x, y + 2); cout << " - " << Item::getdropItem(Player::loc->floor)->getName() << endl;
					y += 1;
					Player::inven.push_back(Item::getdropItem(Player::loc->floor));
				}
				_getch();
			}
		}
		if (Player::loc->stage < 3) Player::loc->MoveStage();
		else if (Player::loc->floor == 10 && Player::loc->stage == 3) {
			
			system("cls");
			frame();
			start_ascii();
			int x = 2;
			int y = 14;

			gotoxy(x, y + 2); cout << "CLEAR!";

			_getch();
			return;
		}
		else {
			screen_reset();
			x = 2;
			y = 14;
			gotoxy(x, y + 2); cout << "�޽�ó�� �����Ͽ����ϴ�." << endl;
			y += 2;

			_getch();

			if (Player::loc->floor == 3 || Player::loc->floor == 6) {
				gotoxy(x, y + 2); cout << "���ο� ���Ḧ �������ϴ�." << endl;
				_getch();
				Player::SetChar(UI::CharChoice());
				_getch();
			}
			if (rdfunc() % 10 < 1) {
				screen_reset();
				gotoxy(x, y + 2); cout << "���� ����! " << endl;
				_getch();
				if (Player::loc->floor <= 3) {
					entity["����"].push_back(new Rogue("����1"));
					entity["����"].push_back(new Rogue("����2"));
					if (battleStart()) return;
				}
				else {
					entity["����"].push_back(new Rogue("����1"));
					entity["����"].push_back(new Rogue("����2"));
					entity["����"].push_back(new Rogue("����3"));
					entity["����"].push_back(new Rogue("����4"));
					if (battleStart()) return;
				}
			}

			UI::StateInterface();
			for (auto a : Player::cha) {
				a->setHp(5);
				screen_reset();
				x = 2;
				y = 14;

				gotoxy(x, y + 2); cout << "����� �޽����� " << a->getName() << "�� ü���� 5 ȸ���Ǿ����ϴ�." << endl;
			}
			Player::loc->MoveStage();
		}
	}
}
bool Stage::battleStart() {
	int x = 2;
	int y = 14;

	battle_init();
	battle();
	if (fail) {
		for (auto* e : entity["����"]) {
			delete e;
		}
		entity.clear();
		buff.clear();
		Player::cha.clear();
		_getch();
		return true;
	}

	if (Player::loc->floor <= 9) {
		Item* item = nullptr;
		for (; monsternum != 0; monsternum--) dropitemnum += rdfunc() % 3;
		gotoxy(x, y + 2); cout << "������ " << dropitemnum << "���� ȹ���Ͽ����ϴ�." << endl;
		y += 2;
		for (; dropitemnum != 0; dropitemnum--) {
			Item* item = Item::getdropItem(Player::loc->floor);
			gotoxy(x, y + 2); cout << " - " << item->getName() << endl;
			y += 1;
			Player::inven.push_back(item);
		}
	}
	_getch();
	return false;
}
void Stage::battle_init() {
	dropitemnum = 0;
	monsternum = entity["����"].size();
	entity["�Ʊ�"].clear();
	for (auto* a : Player::cha) {
		a->stage_init();
		entity["�Ʊ�"].push_back(a);
	}
	buff.clear();
}
void Stage::fieldbuff(string team) {

	screen_reset();
	int x = 2;
	int y = 14;
	
	for (auto c : buffkind)
		for (auto it = buff[c].begin(); it != buff[c].end();) {
			if (it->getTurn() <= 0) {
				if (c == "�Ʊ� ���� ����")
					for (auto a : entity["�Ʊ�"]) {
						a->setIncdfs(+it->getFigure1());
						a->setIncdmg(+it->getFigure1());
					}
				else if (c == "�Ʊ� ���� ����")
					for (auto a : entity["�Ʊ�"])
						a->setIncdfs(-it->getFigure1());
				else if (c == "�Ʊ� ���ݷ� ����")
					for (auto a : entity["�Ʊ�"])
						a->setIncdmg(+it->getFigure1());

				it = buff[c].erase(it);
			}
			else {
				it->setTurn(it->getTurn() - 1);
				if (c != "�Ʊ� �ൿ�� ����") {
					gotoxy(x, y + 2); cout << it->getName() << "��(��) ���� ���Դϴ�. (���� �� ��: " << it->getTurn() / 2 << ")" << endl;
					y += 2;
					_getch();
				}
					
				if (c == "�Ʊ� ���� ������" && team == teamname[0])
					for (auto a = entity["�Ʊ�"].begin(); a != entity["�Ʊ�"].end();) {
						Entity::sufferDmg(it->getDmg(), *a, entity["�Ʊ�"], false);
						bool dead = Entity::entityErase(*a, entity["�Ʊ�"]);
						if (dead) { delete* a; a = entity["�Ʊ�"].erase(a); }
						else a++;
						if (WinOrLose()) return;
					}
				else if (c == "�Ʊ� �ൿ�� ����")
					for (auto e : entity["�Ʊ�"])
						e->setAct(e->getMaxAct() - it->getFigure1());
				it++;
			}

		}
}
bool Stage::WinOrLose() {
	if (entity["����"].empty()) {
		//cout << "�Ʊ� �¸�" << endl;
		return true;
	}
	else if (entity["�Ʊ�"].empty()) {
		//cout << "GAME OVER" << endl;
		fail = true;
		return true;
	}
	else return false;
}
void Stage::battle() {
	while (1) {
		//cout << endl << turn / 2 << "��° " << teamname[turn % 2] << " ��" << endl;
		for (auto a : entity[teamname[turn % 2]]) a->setAct(a->getMaxAct());
		fieldbuff(teamname[(turn + 1) % 2]);
		for (auto it = entity[teamname[turn % 2]].begin(); it != entity[teamname[turn % 2]].end();) {
			(*it)->attack(entity, buff);
			if (!entity[teamname[turn % 2]].empty()) {
				if ((*it)->getHp() <= 0) {
					delete* it;
					it = entity[teamname[turn % 2]].erase(it);
				}
				else ++it;
			}
			if (WinOrLose()) return;
		}
		turn++;
	}
}