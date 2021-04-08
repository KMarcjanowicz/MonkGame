#pragma once
#include "Entity.h"

class Player :
	public Entity
{
public:
	Player(int money_, float score_, Room* spawn_);
	~Player();
	int money;
	float score;
public:
	void move();
};

