#pragma once
#include "IFightSubject.h"
#include "Entity.h"
#include <list>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class FightSubject :
    public IFightSubject
{
public: 
    FightSubject();
    ~FightSubject();
    void Attach(Entity* observer);
    void Detach(Entity* observer);
    void Notify();

    int HowManyFighters();
    int DecideTurn();
    void NotifyTurn(int turn_);

    void Update(string msg_, Entity* entity_, int value_);
    void FightResult(list<Entity*> fighters_, Entity* looser_);

private:
    list<Entity*> fighters;
    string message;
    int currentTurn = 0;

};

