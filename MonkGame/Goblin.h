#pragma once
#include "Entity.h"
#include "AI.h"
#include "FightSubject.h"
#include <list>

using namespace std;

class Goblin :
    public Entity
{
public:
    Goblin();
    vector<string> actions;
    AI* goblinAI;

    void FightInterface(list<Entity*> fighters_, int myIterator_, FightSubject* master_);
};

