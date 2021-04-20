#include "FightSubject.h"
#include "PlayerController.h"

FightSubject::FightSubject()
{
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
}

int FightSubject::HowManyFighters()
{
	return this->fighters.size();
}

int FightSubject::DecideTurn()
{

	if (currentTurn < fighters.size()) {
		currentTurn = currentTurn + 1;
	}
	else {
		currentTurn = 0;
	}
	return (currentTurn - 1);
}

void FightSubject::NotifyTurn(int turn_)
{
	int i = 0;
	list<Entity*>::iterator iterator = fighters.begin();

	while (iterator != fighters.end()) {
		if (i = turn_) {
			cout << (*iterator)->type << endl;
			if ((*iterator)->type == "player") {
				PlayerController* controller = PlayerController::GetInstance();
				cout << "Notify player that it is his turn" << endl;
			}
			else {
				cout << "Notify monster that it is its turn" << endl;
			}
			system("pause");
		}
		++iterator;
		++i;
	}
}
