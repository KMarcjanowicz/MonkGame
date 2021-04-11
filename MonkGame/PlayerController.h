#pragma once
#include <vector>
#include "Player.h"
#include "Room.h"
class PlayerController
{
public:
	PlayerController(Player* player_);
	Player* player;

public:
	void chooseAction();
	void move(vector<Room*> connections_, Room* currentRoom_);
};

