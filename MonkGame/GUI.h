#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "Room.h"

using namespace std;

class GUI
{
private:
	static unsigned char foo;
	static signed char bar;

public:
	static void PrintMap(vector<vector<string>> map_);
	static void PrintMapDebug(vector<vector<string>> map_);
	static void ClearConsole();
	static void PrintRoomType(Room* room_);
};

