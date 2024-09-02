#pragma once
#include <map>
#include <vector>
#include <windows.h>
using namespace std;

#include "Player.h"
#include "Monster.h"
#include "rdfunc.h"
#include "Item.h"

class Stage {
	void setMonster(Location* loc) {
		switch (loc->floor) {
		case 1:
			switch (loc->stage) {
			case 1:
				entity["적군"].push_back(new Rogue("도적"));
				return;
			case 2:
				entity["적군"].push_back(new Rogue("도적"));
				return;
			case 3:
				entity["적군"].push_back(new Rogue("도적1"));
				entity["적군"].push_back(new Rogue("도적2"));
				return;
			}
		case 2:
			switch (loc->stage) {
			case 1:
				entity["적군"].push_back(new Toad("독두꺼비"));
				return;
			case 2:
				entity["적군"].push_back(new Rogue("도적"));
				return;
			case 3:
				entity["적군"].push_back(new Toad("독두꺼비1"));
				entity["적군"].push_back(new Toad("독두꺼비2"));
				return;
			}
		case 3:
			switch (loc->stage) {
			case 1:
				entity["적군"].push_back(new Crocodile("악어"));
				return;
			case 2:
				entity["적군"].push_back(new Rogue("도적"));
				entity["적군"].push_back(new Toad("독두꺼비"));
				return;
			case 3:
				entity["적군"].push_back(new Crocodile("악어1"));
				entity["적군"].push_back(new Crocodile("악어2"));
				return;
			}
		case 4:
			switch (loc->stage) {
			case 1:
				entity["적군"].push_back(new Locust("메뚜기 떼"));
				return;
			case 2:
				entity["적군"].push_back(new Locust("메뚜기 떼"));
				return;
			case 3:
				entity["적군"].push_back(new Locust("메뚜기 떼1"));
				entity["적군"].push_back(new Locust("메뚜기 떼2"));
				return;
			}
		case 5:
			switch (loc->stage) {
			case 1:
				entity["적군"].push_back(new Locust("메뚜기 떼"));
				return;
			case 2:
				entity["적군"].push_back(new Snake("뱀"));
				return;
			case 3:
				entity["적군"].push_back(new Snake("뱀1"));
				entity["적군"].push_back(new Snake("뱀2"));
				entity["적군"].push_back(new Locust("메뚜기 떼"));
				return;
			}
		case 6:
			switch (loc->stage) {
			case 1:
				entity["적군"].push_back(new Locust("메뚜기 떼"));
				return;
			case 2:
				entity["적군"].push_back(new Snake("뱀1"));
				entity["적군"].push_back(new Snake("뱀2"));
				return;
			case 3:
				entity["적군"].push_back(new Harpy("하피1"));
				entity["적군"].push_back(new Harpy("하피2"));
				return;
			}
		case 7:
			switch (loc->stage) {
			case 1:
				entity["적군"].push_back(new Wolf("늑대"));
				return;
			case 2:
				entity["적군"].push_back(new Wolf("늑대"));
				return;
			case 3:
				entity["적군"].push_back(new Wolf("늑대1"));
				entity["적군"].push_back(new Wolf("늑대2"));
				entity["적군"].push_back(new Wolf("늑대3"));
				return;
			}
		case 8:
			switch (loc->stage) {
			case 1:
				entity["적군"].push_back(new Wolf("늑대"));
				return;
			case 2:
				entity["적군"].push_back(new Believer("광신도1"));
				entity["적군"].push_back(new Believer("광신도2"));
				return;
			case 3:
				entity["적군"].push_back(new Believer("광신도1"));
				entity["적군"].push_back(new Believer("광신도2"));
				entity["적군"].push_back(new Believer("광신도3"));
				return;
			}
		case 9:
			switch (loc->stage) {
			case 1:
				entity["적군"].push_back(new Angel("천사(1페이즈)", 150));
				return;
			case 2:
				entity["적군"].push_back(new Angel("천사(2페이즈)", 300));
				return;
			case 3:
				entity["적군"].push_back(new Angel("천사(3페이즈)", 500));
				return;
			}
		case 10:
			switch (loc->stage) {
			case 1:
				entity["적군"].push_back(new God("신(1페이즈)", 300));
				return;
			case 2:
				entity["적군"].push_back(new God("신(2페이즈)", 500));
				return;
			case 3:
				entity["적군"].push_back(new God("신(3페이즈)", 700));
				return;
			}
		default:
			cout << "몬스터 세팅에 실패하였습니다." << endl;
			return;
		}
	}
	vector<string> buffkind = { "아군 지속 데미지", "아군 방어력 증가", "아군 행동력 감소", "아군 공격력 감소"};
	map<string, vector<Entity*>> entity;
	map<string, vector<Skill>> buff;
	bool fail = false;
	int turn = 2;
	int dropitemnum = 0;
	int monsternum = 0;
	string teamname[2] = {"아군", "적군"};
public:
	Stage();
	bool battleStart();
	void battle_init();
	void fieldbuff(string team = "");
	bool WinOrLose();
	void battle();
};