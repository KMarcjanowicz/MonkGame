#include "AI.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

AI::AI()
{
	srand(time(NULL));
}

int AI::CoinFlip()
{
	return (rand() * 47 % 100 + 1);
}

string AI::ChooseAction(int hp_, int currentHP_)
{
	if (hp_ == currentHP_) {
		return "attack";
	}
	else {
		string action = "attack";
		if (CoinFlip() > 50) {
			action = "defend";
		}
		return action;
	}
}
