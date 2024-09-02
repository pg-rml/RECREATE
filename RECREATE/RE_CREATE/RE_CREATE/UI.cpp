#include "UI.h"
#include "Graphic.h"
using namespace std;

void UI::MainLogo() {

	frame();
	start_ascii();
	int x = 1;
	int y = 12;

	gotoxy(x, y + 5);
	cout << endl << endl
		<< "\t\t     ## ###   #######             ####   ## ###   #######    ###    ######   ####### " << endl
		<< "\t\t      ###  ##   ##   #            ##  ##  ###  ##   ##   #   ## ##   # ## #    ##   #" << endl
		<< "\t\t      ##   ##   ##        ##     ##       ##   ##   ##      ##   ##    ##      ##	" << endl
		<< "\t\t      ######    ####      ##     ##       ######    ####    #######    ##      ####  " << endl
		<< "\t\t      ## ##     ##               ##       ## ##     ##      ##   ##    ##      ##    " << endl
		<< "\t\t      ##  ###   ##   #    ##      ##  ##  ##  ###   ##   #  ##   ##    ##      ##   #" << endl
		<< "\t\t      ##   ##  #######    ##       ####   ##   ##  #######  ##   ##   ####    #######"
		<< endl << endl;
}
void UI::MainLobby() {
	while (1) {
		system("cls");
		UI::MainLogo();

		int i = NULL;

		int x = 1;
		int y = 34;
		gotoxy(x, y); cout << "�� \033[94m�����ϱ� \033[90m(1)\033[0m�� " << "�� \033[94m�����ϱ� \033[90m(2)\033[0m�� ";
		gotoxy(x, y + 2); cout << " Enter Number: ";
		i = _getch();
		switch (i) {
		case '1':
			Player::player_init();
			Player::SetChar(UI::CharChoice());
			Dungeon();
			break;
		case '2':
			return;
		default:
			cout << "�ٽ� �Է����ּ���" << endl;
			break;
		}
	}
}
void UI::Dungeon() {
	Stage stage;
}
void UI::ShowState() {

	system("cls");
	frame();
	start_ascii();

	int x = 2;
	int y = 14;

	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		gotoxy(x + 10, y + 2); cout << (*it)->getName();

		gotoxy(x + 7, y + 5); cout << "- ���ݷ�: " << (*it)->getDmg();
		gotoxy(x + 7, y + 7); cout << "- ����: " << (*it)->getDfs();
		gotoxy(x + 7, y + 9); cout << "- �ൿ��: " << (*it)->getMaxAct();
		gotoxy(x + 7, y + 11); cout << "- ü��: " << (*it)->getHp() << " / " << (*it)->getMaxHp();
		gotoxy(x + 7, y + 13); cout << "- ���: " << (*it)->boolequip(0) << (*it)->boolequip(1) << (*it)->boolequip(2) << (*it)->boolequip(3);

		x += 17;
	}
	/*
	for (int i = 0; i < Player::cha.size(); i++) {
		cout << "________________________";
	}
	cout << "_" << endl;
	for (int i = 0; i < Player::cha.size(); i++)	cout << "|\t\t\t";
	cout << "|" << endl;
	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		cout << "|\t" << (*it)->getName() << "\t\t";
	}
	cout << "|" << endl;
	for (int i = 0; i < Player::cha.size(); i++)	cout << "|\t\t\t";
	cout << "|" << endl;
	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		cout << "| - ���ݷ�: " << (*it)->getDmg() << "\t\t";
	}
	cout << "|" << endl;
	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		cout << "| - ����: " << (*it)->getDfs() << "\t\t";
	}
	cout << "|" << endl;
	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		cout << "| - �ൿ��: " << (*it)->getMaxAct() << "\t\t";
	}
	cout << "|" << endl;
	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		cout << "| - ü��: " << (*it)->getHp() << " / " << (*it)->getMaxHp() << "\t";
	}
	cout << "|" << endl;
	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		cout << "| - ���: " << (*it)->boolequip(0) << (*it)->boolequip(1) << (*it)->boolequip(2) << (*it)->boolequip(3) << "\t";
	}
	cout << "|" << endl;
	for (int i = 0; i < Player::cha.size(); i++) cout << "|_______________________";
	cout << "|" << endl;
	*/
}


void UI::useItem(int i) {
	int j = 1;
	auto ch = Player::cha.begin();
	while(1){
		j = 1;
		ch = Player::cha.begin();
		int x = 1;
		int y = 34;

		console_reset();
		gotoxy(x, y);
		for (; ch != Player::cha.end(); ch++) {
			 cout << "�� \033[94m" << (*ch)->getName() << " \033[90m(" << j << ")\033[0m�� ";
			 j++;
		}
		// cout << j << ". " << (*ch)->getName() << endl;
		gotoxy(x, y + 2); cout << "������ ĳ���͸� ������ : ";
		cin >> j;
		if (j > Player::cha.size() || j < 0) continue;
		else break;
	}
	ch = Player::cha.begin() + j - 1;
	auto it = Player::inven.begin() + i - 1;
	if ((*it)->getPart() == NULL) {
		(*ch)->useItem(*it);
		delete* it;
		Player::inven.erase(it);
		int x = 1;
		int y = 34;
		console_reset();
		gotoxy(x, y + 2); cout << "�������� �Ҹ�Ǿ����ϴ�." << endl;
	}
	else {
		*it = (*ch)->equip(*it);
		if (*it == nullptr) Player::inven.erase(it);
		int x = 1;
		int y = 34;
		console_reset();
		gotoxy(x, y + 2); cout << "��� �����Ǿ����ϴ�." << endl;
	}
}
void UI::deleteItem(int i) {
	int j;
	auto it = Player::inven.begin() + i - 1;
	int x = 1;
	int y = 34;
	gotoxy(x, y); cout << "�� \033[94m�ı��Ѵ� \033[90m(1)\033[0m�� " << "�� \033[94m�ı����� �ʴ´� \033[90m(2)\033[0m�� ";
	gotoxy(x, y + 2); cout << " Enter Number: ";
	cin >> j;
	switch (j) {
	case 1:
		delete* it;
		Player::inven.erase(it);
		console_reset();
		gotoxy(x, y + 2); cout << "�������� �����Ǿ����ϴ�." << endl;
		_getch();
		break;
	case 2:
		return;
	default:
		console_reset();
		gotoxy(x, y + 2); cout << "�ٽ� �Է����ּ���" << endl;
		_getch();
	}
}
void UI::Inventory() {
	while (1) {
		screen_reset();
		console_reset();
		int i = 1;
		int x = 2;
		int y = 14;

		for (auto it = Player::inven.begin(); it != Player::inven.end();it++) {
			
			//cout << i++ << ". " << (*it)->getName() << endl;
			gotoxy(x + 4, y + 5); cout << i++ << ": " << (*it)->getName();
			
			y += 2;
			if (i % 5 == 0) {
				x += 10;
				y = 14;
			}
		}

		/*
		for (auto it = Player::inven.begin(); it != Player::inven.end();it++) {
			cout << i++ << ". " << (*it)->getName() << endl;
		}*/
		x = 1;
		y = 34;
		gotoxy(x, y); cout << "�� \033[94m������ ��� \033[90m(1)\033[0m�� " << "�� \033[94m������ �ı� \033[90m(2)\033[0m�� " << "�� \033[94m���ư��� \033[90m(3)\033[0m�� ";
		gotoxy(x, y + 2); cout << " Enter Number: ";

		//cout << "1. ������ ���  2. ������ �ı�  3. ���ư���" << endl;
		//cout << "��ȣ�� �Է��ϼ���";
		cin >> i;
		switch (i) {
		case 1:
			console_reset();
			gotoxy(x, y); cout << " ����Ͻ� ������ ��ȣ�� �Է��ϼ���. ";
			gotoxy(x, y + 2); cout << " Enter Number: ";
			cin >> i;
			if (i < 0 || i > Player::inven.size()) break;
			useItem(i);
			break;
		case 2:
			console_reset();
			gotoxy(x, y); cout << "�ı��Ͻ� ������ ��ȣ�� �Է��ϼ���: ";
			cin >> i;
			if (i < 0 || i > Player::inven.size()) break;
			deleteItem(i);
			break;
		case 3:
			return;
		default:
			console_reset();
			gotoxy(x, y); cout << "�ٽ� �Է����ּ���" << endl;
		}
	}
}
void UI::StateInterface() {
	int c;
	while (1) {
		UI::ShowState();

		int x = 1;
		int y = 34;
		gotoxy(x, y); cout << "�� \033[94m�κ� Ȯ�� \033[90m(1)\033[0m�� " << "�� \033[94m���ư��� \033[90m(2)\033[0m�� ";
		gotoxy(x, y + 2); cout << " Enter Number: ";

		//cout << endl << "1. �κ� Ȯ��  2. ���ư���" << endl << "��ȣ�� �Է��ϼ���: ";
		cin >> c;
		switch (c) {
		case 1:
			UI::Inventory();
			break;
		case 2:
			return;
		default:
			gotoxy(x, y + 4); cout << "�ٽ� �Է����ּ���: ";
			_getch();
		}
	}
}

int UI::CharChoice() {

	int i = NULL;
	while (1) {

		system("cls");
		frame();
		start_ascii();
		class_choice();

		i = NULL;

		int x = 1;
		int y = 34;
		gotoxy(x, y); cout << " ĳ���͸� �����ϼ���. " << endl;
		gotoxy(x, y + 2); cout << "�� \033[94m�뺴 \033[90m(1)\033[0m�� " << "�� \033[94mġ���� \033[90m(2)\033[0m�� " << "�� \033[94m������ \033[90m(3)\033[0m�� ";
		gotoxy(x, y + 4); cout << " Enter Number: ";
		
		i = _getch();

		switch (i) {
		case '1':
			class_chosen(i);
			gotoxy(x, y); cout << "\033[31m �뺴\033[0m�� �����ϼ̽��ϴ�." << endl;
			_getch();
			return i;
		case '2':
			class_chosen(i);
			gotoxy(x, y); cout << "\033[96m ġ����\033[0m�� �����ϼ̽��ϴ�." << endl;
			_getch();
			return i;
		case '3':
			class_chosen(i);
			gotoxy(x, y); cout << "\033[34m ������\033[0m�� �����ϼ̽��ϴ�." << endl;
			_getch();
			return i;
		default:
			gotoxy(x, y + 6); cout << " �ٽ� �������ּ���." << endl;
			_getch();
			break;
		}

	}

}
