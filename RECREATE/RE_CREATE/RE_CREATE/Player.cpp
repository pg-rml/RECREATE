#include "Player.h"
#include "CharClass.h"
#include <iostream>

void Player::SetChar(int i) {
	Player::num++;
	switch (i) {
	case '1':
		cha.push_back(new Dealer(Player::num));
		break;
	case '2':
		cha.push_back(new Healer(Player::num));
		break;
	case '3':
		cha.push_back(new Tanker(Player::num));
		break;
	}
}
void Player::player_init() {
	loc->loc_init();
	num = 0;
	for (auto it = inven.begin(); it != inven.end();) {
		delete *it;
		it = inven.erase(it);
	}
}
void Player::setInven(Item* item) {
	inven.push_back(item);
}
