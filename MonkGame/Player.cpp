#include "Player.h"
#include "EmptyRoom.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

Player::Player(int money_, float score_, Room* spawn_, int hp_, int ap_)
{
	this->money = money_;
	this->score = score_;
	this->currentRoom = spawn_;
	this->type = "player";

	this->HP = hp_;
	this->currentHP = hp_;
	this->AP = ap_;
	this->currentAP = ap_;
}

Player::~Player()
{
}

void Player::AddHP()
{
	cout << "Current HP: " << currentHP << ", max HP: " << HP << endl;
	cout << "Praying will heal up to 10 HP." << endl;
	cout << "You can heal max: " << HP - currentHP << endl;
	

	if (currentRoom->type == "empty") {
		EmptyRoom* emptyRoom = dynamic_cast<EmptyRoom*>(currentRoom);  // Works
		if (emptyRoom->prayed == false) {
			currentHP += 10;
			if (currentHP > HP) {
				currentHP = HP;
			}
			emptyRoom->prayed = true;
			cout << "You prayed." << endl;
		}
	}
}

void Player::playerName()
{
	cout << "What is your name: ";
	cin >> name;
	cout << endl << "How are you as a person: ";
	cin >> desc;
	cout << endl << "Now your adventure begins! " << this->name << ", I will look forward to hearing about your adventures!" << endl;
	Sleep(3000);
	system("pause");
}
