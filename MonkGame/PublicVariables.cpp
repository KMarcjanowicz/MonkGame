#include "PublicVariables.h"

#include <iostream>

using namespace std;

PublicVariables* PublicVariables::variables_ = nullptr;;

PublicVariables::PublicVariables()
{
}

PublicVariables* PublicVariables::GetInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if (variables_ == nullptr) {
        variables_ = new PublicVariables();
    }
    return variables_;
}


void PublicVariables::printDungeonMap()
{
    unsigned char foo;
    foo = 178;
    signed char bar;
    bar = 176;
    for (int i = 0; i < DUNG_SIZE; i++) {
        for (int j = 0; j < DUNG_SIZE; j++) {
            if (DUNG_MAP[i][j] == "X") {
                cout << foo << " ";
            }
            else {
                cout << bar << " ";
            }
        }
        cout << endl;
    }
}

vector<vector<string>> PublicVariables::getDungMap()
{
    return DUNG_MAP;
}



