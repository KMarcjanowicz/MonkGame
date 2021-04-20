#include "FightSubject.h"
#include "PlayerController.h"
#include "MonsterRoom.h"
#include "Goblin.h"

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
				controller->FightInterface(fighters, i, this);
			}
			else {
				cout << "Notify monster that it is its turn" << endl;
				if ((*iterator)->type == "goblin") {
					Goblin* goblin = dynamic_cast<Goblin*>(*iterator);
					goblin->FightInterface(fighters, i, this);
				}
			}
			system("pause");
		}
		++iterator;
		++i;
	}
}

void FightSubject::Update(string msg_, Entity* entity_, int value_)
{
	if (msg_ == "attack") {
		entity_->subtractHP(value_);
		if (entity_->currentHP == 0) {
			FightResult(this->fighters, entity_);
		}
	}
	else if (msg_ == "defend") {
		entity_->addHP(value_);
	}
}

void FightSubject::FightResult(list<Entity*> fighters_, Entity* looser_)
{
	if (looser_->type != "player") {
		MonsterRoom* mRoom = dynamic_cast<MonsterRoom*>(looser_->currentRoom);
		Detach(looser_);

		list<Entity*>::iterator iterator = fighters.begin();

		while (iterator != fighters.end()) {
			if ((*iterator != looser_ && (*iterator)->type == "player")) {
				Player* player = dynamic_cast<Player*>(*iterator);
				player->score += looser_->HP * 2;
			}
			++iterator;
		}
	}
	else {
		//when player looses
	}
}
