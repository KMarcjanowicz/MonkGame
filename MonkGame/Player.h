#pragma once
#include <string>
#include "Entity.h"
#include "Room.h"

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
<<<<<<< HEAD
	void AddHP();
=======
	void addHP();
>>>>>>> parent of c5fdc97 (Start Combat)
	void playerName();

	~Player();
=======
	void checkStatus();

	void addHP();
>>>>>>> parent of 4c7b700 (eee)
};

