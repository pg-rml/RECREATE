#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>

#include "Stage.h"
#include "Player.h"
#include "rdfunc.h"
#include "Stage.h"

class UI {
public:
	static void MainLogo();
	static void MainLobby();
	static int Start();
	static int CharChoice();
	static void Dungeon();
	static void ShowState();
	static void StateInterface();
	static void Inventory();
	static void useItem(int i);
	static void deleteItem(int i);
};