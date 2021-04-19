#include "FightSubject.h"
#include "Player.h"

FightSubject::FightSubject()
{
	currentTurn = NULL; //always start with a player
	cout << "==========Fight starts!==========" << endl;
}

FightSubject::~FightSubject()
{
	cout << "==========Fight has ended!==========" << endl;
}

void FightSubject::Attach(Entity* entity_)
{
	this->fighters.push_back(entity_);
}

void FightSubject::Detach(Entity* entity_)
{
	this->fighters.remove(entity_);
}

void FightSubject::Notify()
{
	list<Entity*>::iterator iterator = fighters.begin();
	HowManyFighters();
	while (iterator != fighters.end()) {
		(*iterator)->Update(this->message);
		++iterator;
	}

}

void FightSubject::NotifyTurn()
{
	int i = 0;
	list<Entity*>::iterator iterator = fighters.begin();
	HowManyFighters();
	while (iterator != fighters.end()) {
		if (i = currentTurn) {
			CreateMessage("turn");
			if ((*iterator)->type == "player") {
				Player* player = dynamic_cast<Player*>((*iterator));
			}
			(*iterator)->Update(this->message);
			break;
		}
		++iterator;
		++i;
	}
}

void FightSubject::Update()
{
}

void FightSubject::CreateMessage(string message_)
{
	this->message = message_;
}

int FightSubject::HowManyFighters()
{
	cout << "There are " << this->fighters.size() << " entities engaged in the fight" << endl;;
	return this->fighters.size();
}

int FightSubject::DecideTurn()
{
	if (currentTurn == NULL) {
		currentTurn = 0;
	}
	else {
		if (currentTurn < fighters.size()) {
			currentTurn++;
		}
		else {
			currentTurn = 0;
		}
	}
	return currentTurn;
}
