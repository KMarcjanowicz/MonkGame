#include "Player.h"

Player::Player(int money_, float score_, Room* spawn_, int hp_, int ap_)
{
	this->money = money_;
	this->score = score_;
	this->currentRoom = spawn_;
	this->type = "player";
	this->HP = hp_;
	this->AP = ap_;
}

Player::~Player()
{
}

void Player::checkStatus()
{
}
