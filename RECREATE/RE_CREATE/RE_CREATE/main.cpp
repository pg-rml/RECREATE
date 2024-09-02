#include "Location.h"
#include "CharClass.h"
#include "Item.h"
#include "Entity.h"
#include "Monster.h"
#include "Location.h"
#include "Player.h"
#include "Skill.h"
#include "UI.h"
#include "Monster.h"
#include "Stage.h"
using namespace std;

int Player::num = 0;
vector<CharClass*> Player::cha;
Location* Player::loc = new Location();
vector<Item*> Player::inven;

int main() {
	system("mode con:cols=120 lines=42");

	UI::MainLobby();
}