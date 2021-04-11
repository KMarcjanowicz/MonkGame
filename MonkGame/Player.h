#pragma once
#include "Entity.h"
#include "Room.h"

class Player :
	public Entity
{
public:
	Player(int money_, float score_, Room* spawn_, int hp_, int ap_);
	~Player();
	int money;
	float score;
public:
	void checkStatus();
};

