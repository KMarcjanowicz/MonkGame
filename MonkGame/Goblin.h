#pragma once
#include "Entity.h"

using namespace std;

class Goblin :
    public Entity
{
public:
    Goblin();
    vector<string> actions;

};

