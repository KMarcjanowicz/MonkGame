#pragma once
#include <string>
#include <iostream>
#include "Room.h"

using namespace std;

class Entity
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

<<<<<<< HEAD
	void Update();
	void Update(string message_);
	void Update(string message_, int value_);

	~Entity();
=======
	void update();
>>>>>>> parent of 4c7b700 (eee)
};

