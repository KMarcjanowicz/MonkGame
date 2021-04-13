#pragma once
#include "Room.h"
class EmptyRoom :
    public Room
{
public:
    EmptyRoom(int id_i_, int id_j_, int conns_);

    bool prayed;
};

