#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void gotoxy(int x, int y);

void frame(void);

void start_ascii(); // ���� �� �ƽ�Ű ��Ʈ

void PC1_info(void); // ��ܿ� ������ PC ����â
void PC2_info(void);
void PC3_info(void);

void enemy1_info(void); // ��ܿ� ������ �� ����â
void enemy2_info(void);
void enemy3_info(void);

void dialogue(void); // ��� ��� ����

void class_choice();
void class_chosen(int i);
void basic_choice(void); // �⺻ ������

void skil_choice(int i, string name, int act); // ��ų ���� �� �����ϴ� ī�� (3�� ����)
void skil_tanker(int i); // ��ų ���� �� ī�忡 ��µǴ� �׷���. �ӽ÷� skil_choice �Լ� �ȿ� �־����.
void skil_dealer(int i); // "
void skil_healer(int i); // "
void skil_input(void); // ��ų ����, �ٽ� �̱⸦ ���. �ӽ÷� skil_choice �Լ� �ȿ� �־����.

void stage(int floor, int stage); // ����� ���������� �� �� ��Ÿ��
void now_stage1(void);
void now_stage2(void);
void now_stage3(void);


// �κ� ȭ�� ���¿�
void screen_reset(void);
void console_reset(void);
void status_reset(void);

// ����� ��ų �����ܿ� 
void skil_tanker_used(int i);
void skil_dealer_used(int i); 
void skil_healer_used(int i); 
