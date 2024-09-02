#include "Item.h"

Item::Item(string name, int heal, int attack_inc, int defense_inc, int max_health_inc, int action_points_inc, int part) {
	this->name = name;
	this->heal = heal;
	this->attack_increase = attack_inc;
	this->defense_increase = defense_inc;
	this->max_health_increase = max_health_inc;
	this->action_points_increase = action_points_inc;
	this->part = part;
}

Item* Item::getdropItem(int floor) {
	Item* item = nullptr;
	int prob = rdfunc() % 100;
	if (prob < 30) {
		item = new Item("해진 붕대", 10);
	}
	else if (prob < 45) {
		item = new Item("수상한 비약", 0, 5);
	}
	else if (prob < 52) {
		item = new Item("악마의 묘약", 0, 0, 0, 5);
	}
	else if (prob < 57) {
		item = new Item("성수", 0, 0, 0, 0, 1);
	}
	else {
		int random = rdfunc() % 4;
		switch (floor) {
		case 1: case 2: case 3:
			if (random == 0)
				item = new Item("낡은 로브", 0, 3, 0, 0, 0);
			else if (random == 1)
				item = new Item("낡은 바지", 0, 0, 3, 0, 0, 1);
			else if (random == 2)
				item = new Item("낡은 장갑", 0, 0, 1, 0, 0, 2);
			else if (random == 3)
				item = new Item("낡은 부츠", 0, 1, 0, 0, 0, 3);
			break;
		case 4: case 5: case 6:
			if (random == 0)
				item = new Item("모험가의 로브", 0, 10, 0, 0, 0, 0);
			else if (random == 1)
				item = new Item("모험가의 바지", 0, 0, 10, 0, 0, 1);
			else if (random == 2)
				item = new Item("모험가의 장갑", 0, 0, 7, 0, 0, 2);
			else if (random == 3)
				item = new Item("모험가의 부츠", 0, 7, 0, 0, 0, 3);
			break;
		case 7: case 8: case 9:
			if (random == 0)
				item = new Item("대적자의 로브", 0, 20, 0, 0, 0, 1);
			else if (random == 1)
				item = new Item("대적자의 바지", 0, 0, 20, 0, 0, 2);
			else if (random == 2)
				item = new Item("대적자의 장갑", 0, 0, 13, 10, 0, 3);
			else if (random == 3)
				item = new Item("대적자의 부츠", 0, 13, 0, 0, 2, 4);
			break;
		}
	}
	return item;
}
