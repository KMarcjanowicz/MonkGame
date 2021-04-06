#pragma once
#include "Room.h"
#include <string>

using namespace std;

class Corridor :
    public Room
{
public:
    Corridor(int id_i_, int id_j_, int conns_);
private:
    
};

