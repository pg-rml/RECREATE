#pragma once
#include <iostream>
//위치 클래스
class Location {
public:
	int floor;//층
	int stage;//스테이지
	std::string biome;//바이옴

	Location() {
		floor = 1; stage = 1; biome = "사막";
	}
	void MoveFloor();//층 이동
	void MoveStage();//스테이지 이동
	void loc_init();
};