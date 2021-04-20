#include "MonsterRoom.h"
#include "Goblin.h"

MonsterRoom::MonsterRoom(int id_i_, int id_j_, int conns_)
{
	this->id_i = id_i_;
	this->id_j = id_j_;
	this->connections = conns_;
	this->type = "monster";
	Goblin* goblin = new Goblin();
	this->monsters.push_back(goblin);
}

void MonsterRoom::deleteMonsters()
{
	try
	{
		this->monsters.clear();
	}
	catch (const std::exception& ex)
	{
		cout << "Error occured while trying to delete monster array" << endl;
	}
	
}
