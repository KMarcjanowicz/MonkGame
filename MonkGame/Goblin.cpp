#include "Goblin.h"
#include "Player.h"

Goblin::Goblin() {

	currentHP = 10, HP = 10;
	AP = 2;
	type = "goblin";
	goblinAI = new AI();
}

void Goblin::FightInterface(list<Entity*> fighters_, int myIterator_, FightSubject* master_)
{
	Player* player = NULL;
	list<Entity*>::iterator iterator = fighters_.begin();

	while (iterator != fighters_.end()) {
		if ((*iterator)->type == "player") {
			player = dynamic_cast<Player*>((*iterator));
		}
		++iterator;
	}

	if (goblinAI->ChooseAction(this->HP, this->currentHP) == "attack") {
		if (goblinAI->CoinFlip() > 50) {
			master_->Update("attack", player, this->AP);
		}
	}
	else if (goblinAI->ChooseAction(this->HP, this->currentHP) == "defend") {
		if (goblinAI->CoinFlip() > 50) {
			master_->Update("defend", this, 1);
		}
	}
}
