#include "CharClass.h"
using namespace std;

void CharClass::attack(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
	reroll = true;

	int x = 2;
	int y = 14;
	screen_reset();

	while (guard != 0) {

		gotoxy(x, y + 2); cout << "가드를 해제합니다." << endl;
		y += 2;
		setIncdfs(-skill[0].getFigure1());
		guard--;
		_getch();
	}
	if (overpower != 0) {

		gotoxy(x, y + 2); cout << "기선 제압이 지속 중 입니다.(남은 턴: " << overpower << "턴" << endl;
		y += 2;
		_getch();
		setIncdmg(-skill[0].getFigure1());
		overpower--;
	}
	if (stern) {
		gotoxy(x, y + 2); cout << getName() << "가 행동할 수 없습니다." << endl;
		stern = false;;
		_getch();
		return;
	}

	
	skillReset();
	useSkill(entity, buff);
}
void CharClass::skillReset() {
	deck = {};
	auto r = []() -> int {
		int random = rdfunc() % 20;
		if (random == 0) return 4;
		else return	(rdfunc() % 4);
		};

	for (int i = 0; i < 5; i++)
		deck.push_back(r());
}
void CharClass::choiceSkill() {
	while (1) {
		if (deck.empty()) {
			int x = 2;
			int y = 14;
			screen_reset();
			gotoxy(x, y + 2); cout << "덱이 비었습니다" << endl;
			n = -1;
			_getch();
			return;
		}
		else {
			auto it = deck.begin();
			//cout << endl << "현재 덱:" << endl;
			int i = 0;
			for (; it != deck.end(); it++) {
				console_reset();
				skil_choice(i++, skill[*it].getName(), skill[*it].getAct());
				if (this->name.find("용병") != string::npos) skil_dealer(i-1);
				if (this->name.find("치유사") != string::npos) skil_healer(i-1);
				if (this->name.find("돌격자") != string::npos) skil_tanker(i-1);

				//this->name == "딜러"
				//cout << i++ << ". " << skill[*it].getName() << " (행동력 " << skill[*it].getAct();
				//if (skill[*it].getDmg() == 0) cout << ")" << endl;
				//else cout << ", 데미지 " << (int)(dmg + skill[*it].getDmg() * (1 + getIncdmg())) << ")" << endl;
			}
			for (; i < 5; i++) {
				skil_choice(i, "   -", 0);
				if (this->name.find("용병") != string::npos) skil_dealer_used(i);
				if (this->name.find("치유사") != string::npos) skil_healer_used(i);
				if (this->name.find("돌격자") != string::npos) skil_tanker_used(i);
			}

			console_reset();
			int x = 1;
			int y = 34;
			gotoxy(x, y); cout << "│ \033[94m턴 종료 \033[90m(0)\033[0m│ " << "│ \033[94m다시 뽑기 \033[90m(-1)\033[0m│ ";
			gotoxy(x, y + 2); cout << " Enter Number: ";
			//cout << endl << "번호를 입력해주세요(턴 종료(0) / 다시 뽑기(-1) 입력): ";
			cin >> n;
			if (n == 0) {
				gotoxy(x, y + 4); cout << " 턴을 종료합니다." << endl;
				_getch();
				n = -1;
				return;
			}
			else if (n == -1 && reroll) {
				gotoxy(x, y + 4); cout << " 덱을 다시 뽑습니다." << endl;
				_getch();
				reroll = false;
				skillReset();
			}
			else if (n == -1) {
				gotoxy(x, y + 4); cout << " 기회를 모두 소모하였습니다." << endl;
				_getch();
			}
			else if (n > deck.size()) {
				gotoxy(x, y + 4); cout << " 스킬 번호를 다시 입력해주세요" << endl;
				_getch();
			}
			else {
				it = deck.begin() + n - 1;
				n = *it;
				x = 2;
				y = 14;
				screen_reset();
				console_reset();
				gotoxy(x, y + 2); cout << name << "이 \033[33m" << skill[n].getName() << "\033[0m을(를) 사용하였습니다." << endl;
				_getch();
				deck.erase(it);
				return;
			}
		}
	}
}
void CharClass::choiceEntity(vector<Entity*>& entity) {

	int x = 2;
	int y = 14;

	//cout << endl;
	if (entity.empty()) {
		screen_reset();
		console_reset();
		gotoxy(x, y + 2); cout << "선택할 대상이 없습니다." << endl;
		e = NULL;
		_getch();
		return;
	}
	else if (entity.size() == 1) {
		e = *entity.begin();
	}
	else {

		screen_reset();
		console_reset();

		auto it = entity.begin();
		int i = 1;

		gotoxy(x, y + 2); cout << "타겟을 선택하세요. " << endl;
		y += 2;

		for (auto it = entity.begin(); it != entity.end(); it++) {
			gotoxy(x, y + 2); cout << i++ << ": " << (*it)->getName() << " (" << (*it)->getHp() << ")\t";
			y += 1;
		}

		x = 1;
		y = 34;

		while (1) {
			console_reset();

			gotoxy(x, y); cout << " Enter Number: ";
			cin >> s;
			if (s > entity.size() || s < 0) {
				gotoxy(x, y + 2); cout << "다시 입력해주세요" << endl;
			}
			else {
				it = entity.begin() + s - 1;
				e = *it;
				screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 2); cout << "대상으로 " << e->getName() << "을(를) 선택하였습니다.";

				_getch();
				return;
			}
		}
	}

	

}