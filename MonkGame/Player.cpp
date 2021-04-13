#include "Player.h"
#include "EmptyRoom.h"

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

void Player::checkStatus()
{
}

void Player::addHP()
{
	cout << "Current HP: " << currentHP << ", max HP: " << HP << endl;
	cout << "You can heal max: " << HP - currentHP << endl;
	cout << "Praying will heal 10 HP." << endl;

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
