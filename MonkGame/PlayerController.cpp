#include "PlayerController.h"
#include <iostream>
#include "Observer.h"
#include "EmptyRoom.h"

using namespace std;

Observer* observer = Observer::GetInstance();

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
			cout << "Chosen action: " << action << endl;
			if (action == 1) {
				// do move action
				move(this->player->currentRoom->connected, this->player->currentRoom);
				correct = true;
			}
			else {
				cout << "Wrong action chosen, please retry." << endl;
				correct = false;
			}
		}
		else if (currentRoomType == "monster") {
			cout << "FIGHT!" << endl;
			cout << "Monster fight will be implemented here" << endl << endl;

			cout << "Choose action: " << endl;
			cout << "1. Move" << endl;
			cin >> action;
			cout << "Chosen action: " << action << endl;
			if (action == 1) {
				// do move action
				move(this->player->currentRoom->connected, this->player->currentRoom);
				correct = true;
			}
			else {
				cout << "Wrong action chosen, please retry." << endl;
				correct = false;
			}
		}
		else if (currentRoomType == "empty") {

			EmptyRoom* emptyRoom = dynamic_cast<EmptyRoom*>(this->player->currentRoom);  // Works

			cout << "Choose action: " << endl;
			cout << "1. Move" << endl;
			if (!emptyRoom->prayed) {
				cout << "2. Pray" << endl;
			}
			
			cin >> action;
			cout << "Chosen action: " << action << endl;
			if (action == 1) {
				// do move action
				move(this->player->currentRoom->connected, this->player->currentRoom);
				correct = true;
			}
			else if (action == 2 && !emptyRoom->prayed) {
				// do pray action
				pray();
				correct = false;
			}
			else {
				cout << "Wrong action chosen, please retry." << endl;
				correct = false;
			}
		}
	}
	
}

void PlayerController::move(vector<Room*> connections_, Room* currentRoom_)
{
	string msg = "";
	int numberOfConnections = connections_.size();
	int chosenRoom = 0;
	for (int i = 0; i < numberOfConnections; i++) {
		if (currentRoom_->id_i < connections_[i]->id_i) {
			msg = "to the bottom";
		}
		if (currentRoom_->id_i > connections_[i]->id_i) {
			msg = "to the top";
		}
		if (currentRoom_->id_j > connections_[i]->id_j) {
			msg = "on the left";
		}
		if (currentRoom_->id_j < connections_[i]->id_j) {
			msg = "on the right";
		}
		cout << i + 1 << ". " << "Go to room " << msg << endl;
	}
	cin >> chosenRoom;
	if (connections_[chosenRoom - 1]) {
		Observer* observer = Observer::GetInstance();
		observer->playerMove(this->player->currentRoom, connections_[chosenRoom - 1]);
	}
	else {
		cout << "Wrong number supplied" << endl;
	}
}

void PlayerController::pray()
{
	Observer* observer = Observer::GetInstance();
	observer->playerPray();
}
