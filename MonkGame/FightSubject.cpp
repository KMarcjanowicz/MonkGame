#include "FightSubject.h"
#include "Player.h"
#include <string>

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
	/*
	int i = 0;
	list<Entity*>::iterator iterator = fighters.begin();
	HowManyFighters();
	while (iterator != fighters.end()) {
		if (i = currentTurn) {
			CreateMessage("turn");
			if ((*iterator)->type == "player") {
				PlayerController* controller = PlayerController::GetInstance();
				controller->FightInterface(fighters, i, this);
			}
			else {
				(*iterator)->Update(this->message);
			}
			break;
		}
		++iterator;
		++i;
	}
	*/
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

void FightSubject::DecideTurn()
{
	if (this->currentTurn == NULL) {
		this->currentTurn = 0;
	}
	else {
		if (this->currentTurn < fighters.size()) {
			this->currentTurn++;
		}
		else {
			this->currentTurn = 0;
		}
	}
	CreateMessage("Turn has been decided, starts: " + to_string(this->currentTurn));
	Notify();
}

void FightSubject::TurnResult()
{
}
