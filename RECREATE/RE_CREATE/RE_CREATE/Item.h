#pragma once
#include <iostream>

#include "rdfunc.h"
using namespace std;

#define MAX_EQUIPMENT 4

class Item {
	string name = "(비어 있음)";
	int heal;
	int attack_increase;
	int defense_increase;
	int max_health_increase;
	int action_points_increase;
	int part;
public:
	Item(string name = "(비어 있음)", int heal = NULL, int attack_inc = NULL, int defense_inc = NULL, int max_health_inc = NULL,
		int action_points_inc = NULL, int part = NULL);

	static Item* getdropItem(int floor);

	string getName() { return name; }
	int getHeal() { return heal; }
	int getAttack_increase() { return attack_increase; }
	int getDefense_increase() { return defense_increase; }
	int getMax_health_increase() { return max_health_increase; }
	int getAction_points_increase() { return action_points_increase; }
	int getPart() { return part; }
	void showInfoName();
	void showInfoEffect();
	void ApplyState();
	void DeleteItem();
};
