#pragma once
#include "IFightSubject.h"
#include <list>

using namespace std;

class FightSubject :
    public IFightSubject
{
public:
	FightSubject();
	~FightSubject();
	void Attach(Entity* entity_);
	void Detach(Entity* entity_);
	void Notify(); 
	void NotifyTurn();
	void Update();
	void CreateMessage(string message_);
	int HowManyFighters();
	int DecideTurn();

private:
	list<Entity*> fighters;
	string message;
	int currentTurn;
};

