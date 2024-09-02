#include "CharClass.h"
using namespace std;

void CharClass::attack(map<string, vector<Entity*>>& entity, map<string, vector<Skill>>& buff) {
	reroll = true;

	int x = 2;
	int y = 14;
	screen_reset();

	while (guard != 0) {

		gotoxy(x, y + 2); cout << "���带 �����մϴ�." << endl;
		y += 2;
		setIncdfs(-skill[0].getFigure1());
		guard--;
		_getch();
	}
	if (overpower != 0) {

		gotoxy(x, y + 2); cout << "�⼱ ������ ���� �� �Դϴ�.(���� ��: " << overpower << "��" << endl;
		y += 2;
		_getch();
		setIncdmg(-skill[0].getFigure1());
		overpower--;
	}
	if (stern) {
		gotoxy(x, y + 2); cout << getName() << "�� �ൿ�� �� �����ϴ�." << endl;
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
			gotoxy(x, y + 2); cout << "���� ������ϴ�" << endl;
			n = -1;
			_getch();
			return;
		}
		else {
			auto it = deck.begin();
			//cout << endl << "���� ��:" << endl;
			int i = 0;
			for (; it != deck.end(); it++) {
				console_reset();
				skil_choice(i++, skill[*it].getName(), skill[*it].getAct());
				if (this->name.find("�뺴") != string::npos) skil_dealer(i-1);
				if (this->name.find("ġ����") != string::npos) skil_healer(i-1);
				if (this->name.find("������") != string::npos) skil_tanker(i-1);

				//this->name == "����"
				//cout << i++ << ". " << skill[*it].getName() << " (�ൿ�� " << skill[*it].getAct();
				//if (skill[*it].getDmg() == 0) cout << ")" << endl;
				//else cout << ", ������ " << (int)(dmg + skill[*it].getDmg() * (1 + getIncdmg())) << ")" << endl;
			}
			for (; i < 5; i++) {
				skil_choice(i, "   -", 0);
				if (this->name.find("�뺴") != string::npos) skil_dealer_used(i);
				if (this->name.find("ġ����") != string::npos) skil_healer_used(i);
				if (this->name.find("������") != string::npos) skil_tanker_used(i);
			}

			console_reset();
			int x = 1;
			int y = 34;
			gotoxy(x, y); cout << "�� \033[94m�� ���� \033[90m(0)\033[0m�� " << "�� \033[94m�ٽ� �̱� \033[90m(-1)\033[0m�� ";
			gotoxy(x, y + 2); cout << " Enter Number: ";
			//cout << endl << "��ȣ�� �Է����ּ���(�� ����(0) / �ٽ� �̱�(-1) �Է�): ";
			cin >> n;
			if (n == 0) {
				gotoxy(x, y + 4); cout << " ���� �����մϴ�." << endl;
				_getch();
				n = -1;
				return;
			}
			else if (n == -1 && reroll) {
				gotoxy(x, y + 4); cout << " ���� �ٽ� �̽��ϴ�." << endl;
				_getch();
				reroll = false;
				skillReset();
			}
			else if (n == -1) {
				gotoxy(x, y + 4); cout << " ��ȸ�� ��� �Ҹ��Ͽ����ϴ�." << endl;
				_getch();
			}
			else if (n > deck.size()) {
				gotoxy(x, y + 4); cout << " ��ų ��ȣ�� �ٽ� �Է����ּ���" << endl;
				_getch();
			}
			else {
				it = deck.begin() + n - 1;
				n = *it;
				x = 2;
				y = 14;
				screen_reset();
				console_reset();
				gotoxy(x, y + 2); cout << name << "�� \033[33m" << skill[n].getName() << "\033[0m��(��) ����Ͽ����ϴ�." << endl;
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
		gotoxy(x, y + 2); cout << "������ ����� �����ϴ�." << endl;
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

		gotoxy(x, y + 2); cout << "Ÿ���� �����ϼ���. " << endl;
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
				gotoxy(x, y + 2); cout << "�ٽ� �Է����ּ���" << endl;
			}
			else {
				it = entity.begin() + s - 1;
				e = *it;
				screen_reset();
				x = 2;
				y = 14;
				gotoxy(x, y + 2); cout << "������� " << e->getName() << "��(��) �����Ͽ����ϴ�.";

				_getch();
				return;
			}
		}
	}

	

}