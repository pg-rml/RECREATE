#pragma once
#include <iostream>
//��ġ Ŭ����
class Location {
public:
	int floor;//��
	int stage;//��������
	std::string biome;//���̿�

	Location() {
		floor = 1; stage = 1; biome = "�縷";
	}
	void MoveFloor();//�� �̵�
	void MoveStage();//�������� �̵�
	void loc_init();
};