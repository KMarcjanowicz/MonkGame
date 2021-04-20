#include "Entity.h"

void Entity::addHP(int value_)
{
	this->currentHP += value_;
	if (this->currentHP > this->HP) {
		this->currentHP = this->HP;
	}
}

void Entity::subtractHP(int value_)
{
	this->currentHP -= value_;
	if (this->currentHP <= 0) {
		this->currentHP = 0;
	}
}

void Entity::addAP()
{
}

void Entity::subtractAP()
{
}

void Entity::attack(Entity* opponent_)
{
}

void Entity::defend()
{
}

void Entity::Update()
{
}

Entity::~Entity()
{
}

