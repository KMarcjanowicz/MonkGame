#pragma once
#include <string>

using namespace std;

class Room
{
public:
	int id_i;
	int id_j;
	int connections;
	string imageName;
	virtual void enter(void);
	virtual void leave(void);
	~Room();
};

