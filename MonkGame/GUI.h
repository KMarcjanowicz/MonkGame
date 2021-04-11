#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class GUI
{
private:
	static unsigned char foo;
	static signed char bar;

public:
	static void printMap(vector<vector<string>> map_);
};

