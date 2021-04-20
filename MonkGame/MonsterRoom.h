#pragma once
#include "Room.h"
#include "Entity.h"

class MonsterRoom :
    public Room
{
public:
    vector<Entity*> monsters;
    MonsterRoom(int id_i_, int id_j_, int conns_);
};

