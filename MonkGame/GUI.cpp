#include "GUI.h"

unsigned char GUI::foo = 178;
signed char GUI::bar = 176;

void GUI::PrintMap(vector<vector<string>> map_)
{
    for (int i = 0; i < map_.size(); i++) {
        for (int j = 0; j < map_[i].size(); j++) {
            if (map_[i][j] == "P") {
            cout << "P ";
            }
            else if (map_[i][j] != "X") {
                cout << foo << " ";
            }
            else {
                cout << bar << " ";
            }
        }
        cout << endl;
    }
}

void GUI::PrintMapDebug(vector<vector<string>> map_)
{
    for (int i = 0; i < map_.size(); i++) {
        for (int j = 0; j < map_[i].size(); j++) {
            if (map_[i][j] == "X") {
                cout << foo << " ";
            }
            else if (map_[i][j] == "P") {
                cout << "P ";
            }
            else if (map_[i][j] == "T") {
                cout << "T" << " ";
            }
            else if (map_[i][j] == "M") {
                cout << "M" << " ";
            }
            else if (map_[i][j] == "E") {
                cout << "E" << " ";
            }
            else {
                cout << bar << " ";
            }
        }
        cout << endl;
    }
}


void GUI::ClearConsole()
{
    system("cls");
}

void GUI::PrintRoomType(Room* room_)
{
    cout << "PLayer is in room: " << room_->type << endl;
}
