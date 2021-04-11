#include "GUI.h"

unsigned char GUI::foo = 178;
signed char GUI::bar = 176;

void GUI::printMap(vector<vector<string>> map_)
{

    system("cls");

    for (int i = 0; i < map_.size(); i++) {
        for (int j = 0; j < map_[i].size(); j++) {
            if (map_[i][j] == "X") {
                cout << foo << " ";
            }
            else if (map_[i][j] == "P"){
                cout << "P ";
            }
            else if (map_[i][j] == "T") {
                cout << "T" << " ";
            }
            else {
                cout << bar << " ";
            }
        }
        cout << endl;
    }
}
