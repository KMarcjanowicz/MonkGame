#include "GUI.h"



void GUI::printMap(vector<vector<string>> map_)
{
    unsigned char foo;
    foo = 178;
    signed char bar;
    bar = 176;
    for (int i = 0; i < map_.size(); i++) {
        for (int j = 0; j < map_[i].size(); j++) {
            if (map_[i][j] == "X") {
                cout << foo << " ";
            }
            else if (map_[i][j] == "P"){
                cout << "P ";
            }
            else {
                cout << bar << " ";
            }
        }
        cout << endl;
    }
}
