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
    cout << "Player is in room: " << room_->type << endl;
}

void GUI::PrintPlayerInfo(Player* player_)
{
    cout << player_->name << "'s HP: " << player_->currentHP << ", Score: " << player_->score << endl;
}

void GUI::StartScreen()
{
    // Create and open a text file
    ifstream  MyFile("Screens/StartScreen.txt");

    // Create a text string, which is used to output the text file
    string myText;

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyFile, myText)) {
        // Output the text from the file
        cout << myText << endl;
    }

    // Close the file
    MyFile.close();
}

void GUI::FightScreen(Goblin* goblin_)
{
    cout << "You have been attacked by a " << goblin_->type << "!" << endl;
    // Create and open a text file
    ifstream  MyFile("Screens/Goblin.txt");

    // Create a text string, which is used to output the text file
    string myText;

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyFile, myText)) {
        // Output the text from the file
        cout << myText << endl;
    }

    // Close the file
    MyFile.close();

    cout << goblin_->type << ", HP: " << goblin_->currentHP << " / " << goblin_->HP << " AP: " << goblin_->AP << endl;
}
