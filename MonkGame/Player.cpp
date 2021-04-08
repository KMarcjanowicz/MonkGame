#include "Player.h"

Player::Player(int money_, float score_, Room* spawn_)
{
	this->money = money_;
	this->score = score_;
	this->currentRoom = spawn_;
	this->type = "player";
}

Player::~Player()
{
}

void Player::move()
{
}
