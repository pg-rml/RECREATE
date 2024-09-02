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
				entity["����"].push_back(new Rogue("����"));
				return;
			case 2:
				entity["����"].push_back(new Rogue("����"));
				return;
			case 3:
				entity["����"].push_back(new Rogue("����1"));
				entity["����"].push_back(new Rogue("����2"));
				return;
			}
		case 2:
			switch (loc->stage) {
			case 1:
				entity["����"].push_back(new Toad("���β���"));
				return;
			case 2:
				entity["����"].push_back(new Rogue("����"));
				return;
			case 3:
				entity["����"].push_back(new Toad("���β���1"));
				entity["����"].push_back(new Toad("���β���2"));
				return;
			}
		case 3:
			switch (loc->stage) {
			case 1:
				entity["����"].push_back(new Crocodile("�Ǿ�"));
				return;
			case 2:
				entity["����"].push_back(new Rogue("����"));
				entity["����"].push_back(new Toad("���β���"));
				return;
			case 3:
				entity["����"].push_back(new Crocodile("�Ǿ�1"));
				entity["����"].push_back(new Crocodile("�Ǿ�2"));
				return;
			}
		case 4:
			switch (loc->stage) {
			case 1:
				entity["����"].push_back(new Locust("�޶ѱ� ��"));
				return;
			case 2:
				entity["����"].push_back(new Locust("�޶ѱ� ��"));
				return;
			case 3:
				entity["����"].push_back(new Locust("�޶ѱ� ��1"));
				entity["����"].push_back(new Locust("�޶ѱ� ��2"));
				return;
			}
		case 5:
			switch (loc->stage) {
			case 1:
				entity["����"].push_back(new Locust("�޶ѱ� ��"));
				return;
			case 2:
				entity["����"].push_back(new Snake("��"));
				return;
			case 3:
				entity["����"].push_back(new Snake("��1"));
				entity["����"].push_back(new Snake("��2"));
				entity["����"].push_back(new Locust("�޶ѱ� ��"));
				return;
			}
		case 6:
			switch (loc->stage) {
			case 1:
				entity["����"].push_back(new Locust("�޶ѱ� ��"));
				return;
			case 2:
				entity["����"].push_back(new Snake("��1"));
				entity["����"].push_back(new Snake("��2"));
				return;
			case 3:
				entity["����"].push_back(new Harpy("����1"));
				entity["����"].push_back(new Harpy("����2"));
				return;
			}
		case 7:
			switch (loc->stage) {
			case 1:
				entity["����"].push_back(new Wolf("����"));
				return;
			case 2:
				entity["����"].push_back(new Wolf("����"));
				return;
			case 3:
				entity["����"].push_back(new Wolf("����1"));
				entity["����"].push_back(new Wolf("����2"));
				entity["����"].push_back(new Wolf("����3"));
				return;
			}
		case 8:
			switch (loc->stage) {
			case 1:
				entity["����"].push_back(new Wolf("����"));
				return;
			case 2:
				entity["����"].push_back(new Believer("���ŵ�1"));
				entity["����"].push_back(new Believer("���ŵ�2"));
				return;
			case 3:
				entity["����"].push_back(new Believer("���ŵ�1"));
				entity["����"].push_back(new Believer("���ŵ�2"));
				entity["����"].push_back(new Believer("���ŵ�3"));
				return;
			}
		case 9:
			switch (loc->stage) {
			case 1:
				entity["����"].push_back(new Angel("õ��(1������)", 150));
				return;
			case 2:
				entity["����"].push_back(new Angel("õ��(2������)", 300));
				return;
			case 3:
				entity["����"].push_back(new Angel("õ��(3������)", 500));
				return;
			}
		case 10:
			switch (loc->stage) {
			case 1:
				entity["����"].push_back(new God("��(1������)", 300));
				return;
			case 2:
				entity["����"].push_back(new God("��(2������)", 500));
				return;
			case 3:
				entity["����"].push_back(new God("��(3������)", 700));
				return;
			}
		default:
			cout << "���� ���ÿ� �����Ͽ����ϴ�." << endl;
			return;
		}
	}
	vector<string> buffkind = { "�Ʊ� ���� ������", "�Ʊ� ���� ����", "�Ʊ� �ൿ�� ����", "�Ʊ� ���ݷ� ����"};
	map<string, vector<Entity*>> entity;
	map<string, vector<Skill>> buff;
	bool fail = false;
	int turn = 2;
	int dropitemnum = 0;
	int monsternum = 0;
	string teamname[2] = {"�Ʊ�", "����"};
public:
	Stage();
	bool battleStart();
	void battle_init();
	void fieldbuff(string team = "");
	bool WinOrLose();
	void battle();
};