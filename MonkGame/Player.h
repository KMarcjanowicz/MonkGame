#pragma once
#include <string>
#include "Entity.h"
#include "Room.h"
#include "PlayerController.h"

using namespace std;

class Player :
	public Entity
{
public:
	Player(int money_, float score_, Room* spawn_, int hp_, int ap_);
	~Player();
	int money;
	float score;
public:
	void AddHP();
	void playerName();

	void Update(string message_);
};

