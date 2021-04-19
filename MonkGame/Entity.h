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
	void AddHP();
	void SubtractHP();
	void AddAP();
	void SubtractAP();
	void Attack(Entity* opponent_);
	void Defend();

	void Update();
	void Update(string message_);
	void Update(string message_, int value_);

	virtual ~Entity();
};

