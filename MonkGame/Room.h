#pragma once
#include <string>
#include <vector>

using namespace std;

class Room
{
public:
	int id_i;
	int id_j;
	int connections;
	vector<Room*> connected;
	string imageName;
	string type;
	virtual void enter(void);
	virtual void leave(void);
	~Room();
};

