#pragma once
#include <string>
#include <iostream>
#include "Room.h"
#include "IFightObserver.h"

using namespace std;

class Entity : public IFightObserver
{
public:
	int HP;
	int AP;
	int currentHP;
	int currentAP;
	string desc;
	string name;
	string type;
	Room* currentRoom;
public:
	void addHP(int value_);
	void subtractHP(int value_);
	void addAP();
	void subtractAP();
	void attack(Entity* opponent_);
	void defend();

	void Update();
	virtual ~Entity();
};

