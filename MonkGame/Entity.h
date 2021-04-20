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
	void addHP();
	void subtractHP();
	void addAP();
	void subtractAP();
	void attack(Entity* opponent_);
	void defend();

<<<<<<< HEAD
	void Update();
<<<<<<< HEAD
	void Update(string message_);
	void Update(string message_, int value_);

	~Entity();
=======
	void update();
>>>>>>> parent of 4c7b700 (eee)
=======
	virtual ~Entity();
>>>>>>> parent of c5fdc97 (Start Combat)
};

