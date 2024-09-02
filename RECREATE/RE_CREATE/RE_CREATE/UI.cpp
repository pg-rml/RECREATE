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
		gotoxy(x, y); cout << "│ \033[94m시작하기 \033[90m(1)\033[0m│ " << "│ \033[94m종료하기 \033[90m(2)\033[0m│ ";
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
			cout << "다시 입력해주세요" << endl;
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

		gotoxy(x + 7, y + 5); cout << "- 공격력: " << (*it)->getDmg();
		gotoxy(x + 7, y + 7); cout << "- 방어력: " << (*it)->getDfs();
		gotoxy(x + 7, y + 9); cout << "- 행동력: " << (*it)->getMaxAct();
		gotoxy(x + 7, y + 11); cout << "- 체력: " << (*it)->getHp() << " / " << (*it)->getMaxHp();
		gotoxy(x + 7, y + 13); cout << "- 장비: " << (*it)->boolequip(0) << (*it)->boolequip(1) << (*it)->boolequip(2) << (*it)->boolequip(3);

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
		cout << "| - 공격력: " << (*it)->getDmg() << "\t\t";
	}
	cout << "|" << endl;
	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		cout << "| - 방어력: " << (*it)->getDfs() << "\t\t";
	}
	cout << "|" << endl;
	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		cout << "| - 행동력: " << (*it)->getMaxAct() << "\t\t";
	}
	cout << "|" << endl;
	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		cout << "| - 체력: " << (*it)->getHp() << " / " << (*it)->getMaxHp() << "\t";
	}
	cout << "|" << endl;
	for (auto it = Player::cha.begin(); it != Player::cha.end(); it++) {
		cout << "| - 장비: " << (*it)->boolequip(0) << (*it)->boolequip(1) << (*it)->boolequip(2) << (*it)->boolequip(3) << "\t";
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
			 cout << "│ \033[94m" << (*ch)->getName() << " \033[90m(" << j << ")\033[0m│ ";
			 j++;
		}
		// cout << j << ". " << (*ch)->getName() << endl;
		gotoxy(x, y + 2); cout << "적용할 캐릭터를 고르세요 : ";
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
		gotoxy(x, y + 2); cout << "아이템이 소모되었습니다." << endl;
	}
	else {
		*it = (*ch)->equip(*it);
		if (*it == nullptr) Player::inven.erase(it);
		int x = 1;
		int y = 34;
		console_reset();
		gotoxy(x, y + 2); cout << "장비가 장착되었습니다." << endl;
	}
}
void UI::deleteItem(int i) {
	int j;
	auto it = Player::inven.begin() + i - 1;
	int x = 1;
	int y = 34;
	gotoxy(x, y); cout << "│ \033[94m파괴한다 \033[90m(1)\033[0m│ " << "│ \033[94m파괴하지 않는다 \033[90m(2)\033[0m│ ";
	gotoxy(x, y + 2); cout << " Enter Number: ";
	cin >> j;
	switch (j) {
	case 1:
		delete* it;
		Player::inven.erase(it);
		console_reset();
		gotoxy(x, y + 2); cout << "아이템이 삭제되었습니다." << endl;
		_getch();
		break;
	case 2:
		return;
	default:
		console_reset();
		gotoxy(x, y + 2); cout << "다시 입력해주세요" << endl;
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
		gotoxy(x, y); cout << "│ \033[94m아이템 사용 \033[90m(1)\033[0m│ " << "│ \033[94m아이템 파괴 \033[90m(2)\033[0m│ " << "│ \033[94m돌아가기 \033[90m(3)\033[0m│ ";
		gotoxy(x, y + 2); cout << " Enter Number: ";

		//cout << "1. 아이템 사용  2. 아이템 파괴  3. 돌아가기" << endl;
		//cout << "번호를 입력하세요";
		cin >> i;
		switch (i) {
		case 1:
			console_reset();
			gotoxy(x, y); cout << " 사용하실 아이템 번호를 입력하세요. ";
			gotoxy(x, y + 2); cout << " Enter Number: ";
			cin >> i;
			if (i < 0 || i > Player::inven.size()) break;
			useItem(i);
			break;
		case 2:
			console_reset();
			gotoxy(x, y); cout << "파괴하실 아이템 번호를 입력하세요: ";
			cin >> i;
			if (i < 0 || i > Player::inven.size()) break;
			deleteItem(i);
			break;
		case 3:
			return;
		default:
			console_reset();
			gotoxy(x, y); cout << "다시 입력해주세요" << endl;
		}
	}
}
void UI::StateInterface() {
	int c;
	while (1) {
		UI::ShowState();

		int x = 1;
		int y = 34;
		gotoxy(x, y); cout << "│ \033[94m인벤 확인 \033[90m(1)\033[0m│ " << "│ \033[94m돌아가기 \033[90m(2)\033[0m│ ";
		gotoxy(x, y + 2); cout << " Enter Number: ";

		//cout << endl << "1. 인벤 확인  2. 돌아가기" << endl << "번호를 입력하세요: ";
		cin >> c;
		switch (c) {
		case 1:
			UI::Inventory();
			break;
		case 2:
			return;
		default:
			gotoxy(x, y + 4); cout << "다시 입력해주세요: ";
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
		gotoxy(x, y); cout << " 캐릭터를 선택하세요. " << endl;
		gotoxy(x, y + 2); cout << "│ \033[94m용병 \033[90m(1)\033[0m│ " << "│ \033[94m치유사 \033[90m(2)\033[0m│ " << "│ \033[94m돌격자 \033[90m(3)\033[0m│ ";
		gotoxy(x, y + 4); cout << " Enter Number: ";
		
		i = _getch();

		switch (i) {
		case '1':
			class_chosen(i);
			gotoxy(x, y); cout << "\033[31m 용병\033[0m을 선택하셨습니다." << endl;
			_getch();
			return i;
		case '2':
			class_chosen(i);
			gotoxy(x, y); cout << "\033[96m 치유사\033[0m를 선택하셨습니다." << endl;
			_getch();
			return i;
		case '3':
			class_chosen(i);
			gotoxy(x, y); cout << "\033[34m 돌격자\033[0m를 선택하셨습니다." << endl;
			_getch();
			return i;
		default:
			gotoxy(x, y + 6); cout << " 다시 선택해주세요." << endl;
			_getch();
			break;
		}

	}

}
