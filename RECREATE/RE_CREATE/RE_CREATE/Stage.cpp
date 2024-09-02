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

		//cout << Player::loc->floor << "층 " << Player::loc->stage << "스테이지 전투 시작!";
		if (battleStart()) return;
		if (Player::loc->stage == 2 && (Player::loc->floor == 1 || Player::loc->floor == 4 || Player::loc->floor == 7)) {
			
			screen_reset();
			x = 2;
			y = 14;

			gotoxy(x, y + 2); cout << "보물 상자 발견!" << endl;
			y += 2;
			_getch();
			if (rdfunc() % 10 < 2) {
				gotoxy(x, y + 2); cout << "미믹이 출현했다! " << endl;
				y += 2;
				_getch();
				entity["적군"].push_back(new Chest("미믹"));
				if (battleStart()) return;
			}
			else {
				gotoxy(x, y + 2); cout << "보상을 받았다" << endl;
				dropitemnum += rdfunc() % 4 + 2;
				gotoxy(x, y + 2); cout << "아이템 " << dropitemnum << "개를 획득하였습니다." << endl;
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
			gotoxy(x, y + 2); cout << "휴식처에 도착하였습니다." << endl;
			y += 2;

			_getch();

			if (Player::loc->floor == 3 || Player::loc->floor == 6) {
				gotoxy(x, y + 2); cout << "새로운 동료를 만났습니다." << endl;
				_getch();
				Player::SetChar(UI::CharChoice());
				_getch();
			}
			if (rdfunc() % 10 < 1) {
				screen_reset();
				gotoxy(x, y + 2); cout << "도적 출현! " << endl;
				_getch();
				if (Player::loc->floor <= 3) {
					entity["적군"].push_back(new Rogue("도적1"));
					entity["적군"].push_back(new Rogue("도적2"));
					if (battleStart()) return;
				}
				else {
					entity["적군"].push_back(new Rogue("도적1"));
					entity["적군"].push_back(new Rogue("도적2"));
					entity["적군"].push_back(new Rogue("도적3"));
					entity["적군"].push_back(new Rogue("도적4"));
					if (battleStart()) return;
				}
			}

			UI::StateInterface();
			for (auto a : Player::cha) {
				a->setHp(5);
				screen_reset();
				x = 2;
				y = 14;

				gotoxy(x, y + 2); cout << "충분한 휴식으로 " << a->getName() << "의 체력이 5 회복되었습니다." << endl;
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
		for (auto* e : entity["적군"]) {
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
		gotoxy(x, y + 2); cout << "아이템 " << dropitemnum << "개를 획득하였습니다." << endl;
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
	monsternum = entity["적군"].size();
	entity["아군"].clear();
	for (auto* a : Player::cha) {
		a->stage_init();
		entity["아군"].push_back(a);
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
				if (c == "아군 스탯 감소")
					for (auto a : entity["아군"]) {
						a->setIncdfs(+it->getFigure1());
						a->setIncdmg(+it->getFigure1());
					}
				else if (c == "아군 방어력 증가")
					for (auto a : entity["아군"])
						a->setIncdfs(-it->getFigure1());
				else if (c == "아군 공격력 감소")
					for (auto a : entity["아군"])
						a->setIncdmg(+it->getFigure1());

				it = buff[c].erase(it);
			}
			else {
				it->setTurn(it->getTurn() - 1);
				if (c != "아군 행동력 감소") {
					gotoxy(x, y + 2); cout << it->getName() << "이(가) 지속 중입니다. (남은 턴 수: " << it->getTurn() / 2 << ")" << endl;
					y += 2;
					_getch();
				}
					
				if (c == "아군 지속 데미지" && team == teamname[0])
					for (auto a = entity["아군"].begin(); a != entity["아군"].end();) {
						Entity::sufferDmg(it->getDmg(), *a, entity["아군"], false);
						bool dead = Entity::entityErase(*a, entity["아군"]);
						if (dead) { delete* a; a = entity["아군"].erase(a); }
						else a++;
						if (WinOrLose()) return;
					}
				else if (c == "아군 행동력 감소")
					for (auto e : entity["아군"])
						e->setAct(e->getMaxAct() - it->getFigure1());
				it++;
			}

		}
}
bool Stage::WinOrLose() {
	if (entity["적군"].empty()) {
		//cout << "아군 승리" << endl;
		return true;
	}
	else if (entity["아군"].empty()) {
		//cout << "GAME OVER" << endl;
		fail = true;
		return true;
	}
	else return false;
}
void Stage::battle() {
	while (1) {
		//cout << endl << turn / 2 << "번째 " << teamname[turn % 2] << " 턴" << endl;
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