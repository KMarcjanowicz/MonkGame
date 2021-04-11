#pragma once
#include "Room.h"
#include <string>

using namespace std;

class TreasureRoom :
    public Room
{
public:
    TreasureRoom(int id_i_, int id_j_, int conns_);
};

