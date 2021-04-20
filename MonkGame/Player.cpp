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

<<<<<<< HEAD
<<<<<<< HEAD
void Player::AddHP()
=======
void Player::checkStatus()
{
}

void Player::addHP()
>>>>>>> parent of 4c7b700 (eee)
=======
void Player::addHP()
>>>>>>> parent of c5fdc97 (Start Combat)
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
<<<<<<< HEAD

void Player::playerName()
{
	cout << "What is your name: ";
	cin >> name;
	cout << endl << "How are you as a person: ";
	cin >> desc;
	cout << endl << "Now your adventure begins! " << this->name << ", I will look forward to hearing about your adventures!" << endl;
	//Sleep(3000);
	system("pause");
}

=======
>>>>>>> parent of 4c7b700 (eee)
