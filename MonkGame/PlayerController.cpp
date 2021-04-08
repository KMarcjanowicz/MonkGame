#include "PlayerController.h"
#include <iostream>
#include "Observer.h"

using namespace std;

PlayerController::PlayerController(Player* player_)
{
	this->player = player_;
}

void PlayerController::chooseAction()
{
	string currentRoomType = this->player->currentRoom->type;
	int action = 0;
	bool correct = false;
	while (!correct) {
		if (currentRoomType == "corridor") {
			cout << "Choose action: " << endl;
			cout << "1. Move" << endl;
			cin >> action;

			if (action == 1) {
				// do move action

			}
			else {
				cout << "Wrong action chosen, please retry." << endl;
			}
		}
	}
	
}

void PlayerController::move(vector<Room*> connections_)
{
}
