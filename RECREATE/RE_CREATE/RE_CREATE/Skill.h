#pragma once
#include <iostream>
#include <map>
using namespace std;

class Skill {
	string name;
	int dmg;
	int turn;
	int act;
	float figure1;
	float figure2;
public:
	void setSkill(string name = "", int dmg = 0, int turn = 0, float figure1 = 0, float figure2 = 0, int act = 0) {
		this->name = name;
		this->dmg = dmg;
		this->turn = turn * 2;
		this->act = act;
		this->figure1 = figure1;
		this->figure2 = figure2;
	}
	string getName() { return name; }
	int getDmg() { return dmg; }
	int getTurn() { return turn; }
	int getAct() { return act; }
	void setTurn(int turn) { this->turn = turn; }
	float getFigure1() { return figure1; }
	float getFigure2() { return figure2; }

	bool operator<(const Skill& other) const {
		return turn < other.turn;
	}
};