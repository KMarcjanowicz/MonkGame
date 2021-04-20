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
	
	int money;
	float score;
public:
<<<<<<< HEAD
	void AddHP();
	void playerName();

	~Player();
=======
	void checkStatus();

	void addHP();
>>>>>>> parent of 4c7b700 (eee)
};

