#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void gotoxy(int x, int y);

void frame(void);

void start_ascii(); // 제목 위 아스키 아트

void PC1_info(void); // 상단에 나오는 PC 정보창
void PC2_info(void);
void PC3_info(void);

void enemy1_info(void); // 상단에 나오는 적 정보창
void enemy2_info(void);
void enemy3_info(void);

void dialogue(void); // 대사 출력 공간

void class_choice();
void class_chosen(int i);
void basic_choice(void); // 기본 선택지

void skil_choice(int i, string name, int act); // 스킬 선택 시 등장하는 카드 (3번 선택)
void skil_tanker(int i); // 스킬 선택 시 카드에 출력되는 그래픽. 임시로 skil_choice 함수 안에 넣어놓음.
void skil_dealer(int i); // "
void skil_healer(int i); // "
void skil_input(void); // 스킬 선택, 다시 뽑기를 물어봄. 임시로 skil_choice 함수 안에 넣어놓음.

void stage(int floor, int stage); // 가운데에 스테이지와 층 수 나타냄
void now_stage1(void);
void now_stage2(void);
void now_stage3(void);


// 부분 화면 리셋용
void screen_reset(void);
void console_reset(void);
void status_reset(void);

// 사용한 스킬 아이콘용 
void skil_tanker_used(int i);
void skil_dealer_used(int i); 
void skil_healer_used(int i); 
