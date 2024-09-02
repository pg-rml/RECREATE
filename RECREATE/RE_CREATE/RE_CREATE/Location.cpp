#include "Location.h"
using namespace std;

void Location::MoveFloor() {
	if (floor < 6) biome = "사막";
	else if (floor < 9) biome = "빙하";
	else if (floor >= 10) biome = "공허";
}
void Location::MoveStage() {
	if (stage >= 3) {
		stage = 1;
		floor++;
		MoveFloor();
	}
	else stage++;
}
void Location::loc_init() {
	floor = 1;
	stage = 1;
	biome = "사막";
}