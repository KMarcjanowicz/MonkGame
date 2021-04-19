#include "MonsterRoom.h"
#include "Goblin.h"

MonsterRoom::MonsterRoom(int id_i_, int id_j_, int conns_)
{
	this->id_i = id_i_;
	this->id_j = id_j_;
	this->connections = conns_;
	this->type = "monster";
	Goblin* goblin = new Goblin();
	monsters.push_back(goblin);
}
