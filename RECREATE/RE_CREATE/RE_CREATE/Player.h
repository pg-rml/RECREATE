#pragma once
#include <vector>
#include "CharClass.h"
#include "Location.h"
#include "Item.h"

#define MAX_CHARCARATER_NUM 3

//플레이어 클래스
class Player {
public:
	static int num;
	static vector<Item*> inven;
	static vector<CharClass*> cha;
	static Location* loc;

	Player() {}
	static void SetChar(int i);
	static void player_init();
	static void setInven(Item* item);
};
