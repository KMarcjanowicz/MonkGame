#pragma once
#include "IFightSubject.h"
<<<<<<< HEAD
#include "Entity.h"
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
	void DecideTurn();
	void TurnResult();

private:
	list<Entity*> fighters;
	string message;
	int currentTurn;
=======
class FightSubject :
    public IFightSubject
{
>>>>>>> parent of c5fdc97 (Start Combat)
};

