#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Player.h"

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
	static void PrintPlayerInfo(Player* player_);
	static void StartScreen();
};

