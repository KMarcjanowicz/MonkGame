#pragma once
#include <string>

using namespace std;

class AI
{
public:
	AI();
	int CoinFlip();
	string ChooseAction(int hp_, int currentHP_);
};

