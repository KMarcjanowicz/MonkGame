#include "PlayerController.h"
#include <iostream>
#include "Observer.h"
#include "EmptyRoom.h"
#include "GUI.h"
#include <list>
#include "Goblin.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "MonsterRoom.h"

using namespace std;

PlayerController* PlayerController::playerController_ = nullptr;;

PlayerController::PlayerController()
{
}


PlayerController* PlayerController::GetInstance()
{
	/**
	 * This is a safer way to create an instance. instance = new Singleton is
	 * dangeruous in case two instance threads wants to access at the same time
	 */
	if (playerController_ == nullptr) {
		playerController_ = new PlayerController();
	}
	return playerController_;
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

			bool possibleFight = false;
			MonsterRoom* mRoom = dynamic_cast<MonsterRoom*>(this->player->currentRoom);
			cout << mRoom->monsters.size() << endl;
			system("pause");

			if (mRoom->monsters.size() > 0) {
				for (int i = 0; i < mRoom->monsters.size(); i++) {
					if (mRoom->monsters[i]->currentHP > 0) {
						possibleFight = true;
						break;
					}
				}
			}
			if (possibleFight) {
				fight();
			}

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

void PlayerController::fight()
{
	Observer* observer = Observer::GetInstance();
	observer->PlayerFight(player, player->currentRoom);
}

void PlayerController::FightInterface(list<Entity*> fighters_, int myIterator_, FightSubject* master_)
{
	/* initialize random seed: */
	srand(time(NULL));

	int action;
	GUI::ClearConsole();
	GUI::PrintPlayerInfo(this->player);
	list<Entity*>::iterator iterator = fighters_.begin();
	Goblin* goblin = NULL;

	while (iterator != fighters_.end()) {
		if ((*iterator)->type != "player") {
			goblin = dynamic_cast<Goblin*>((*iterator));
		}
		++iterator;
	}

	GUI::FightScreen(goblin);

	cout << "Choose action: " << endl;
	cout << "1. Attack" << endl;
	cout << "2. Defend" << endl;
	cout << "Perform: ";
	cin >> action;

	if (action == 1) {
		//do something
		cout << "========== ATTACK! ==========" << endl;
		/* generate secret number between 1 and 10: */
		int success = rand() * 47 % 100 + 1;
		cout << success << endl;
		if (success >= 50) {
			master_->Update("attack", goblin, this->player->AP);
		}
	}
	else if (action == 2)
	{
		//do something else
		cout << "========== DEFEND! ==========" << endl;
		int success = rand() * 47 % 100 + 1;
		if (success >= 50) {
			master_->Update("defend", this->player, 1);
		}
	}
	else {
		FightInterface(fighters_, myIterator_, master_);
	}
}
