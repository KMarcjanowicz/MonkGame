#include "Dungeon.h"
#include "Corridor.h"

#include <iostream>


using namespace std;

Dungeon* Dungeon::dungeon_ = nullptr;;

Dungeon::Dungeon()
{
    //cout << "Created a new Dungeon" << endl;
}

Dungeon* Dungeon::GetInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if (dungeon_ == nullptr) {
        dungeon_ = new Dungeon();
    }
    return dungeon_;
}

bool Dungeon::generateDungeonMap(int* sizePointer, vector<vector<string>> map_)
{
    this->map = map_;

    this->roomMap.resize(*sizePointer);
    for (int i = 0; i < *sizePointer; i++) {
        this->roomMap[i].resize(*sizePointer);
    }

    for (int i = 0; i < *sizePointer; i++) {
        for (int j = 0; j < *sizePointer; j++) {
            if (this->map[i][j] != "X") {
                //implement function that calculates the amount of connections to the room
                Corridor* corridor = new Corridor(i, j, getNumberOfConnections(i, j, sizePointer));
                this->roomMap[i][j] = corridor;
            }
        }
    }

    return false;
}

int Dungeon::getNumberOfConnections(int id_i_, int id_j_, int* sizePointer)
{
    int conns_ = 0;
    if (id_i_ - 1 >= 0 && this->map[id_i_ - 1][id_j_] != "X") {
        conns_++;
    }
    if(id_i_ + 1 < *sizePointer && this->map[id_i_ + 1][id_j_] != "X") {
        conns_++;
    }
    if (id_j_ - 1 >= 0 && this->map[id_i_][id_j_ - 1] != "X") {
        conns_++;
    }
    if (id_j_ + 1 < *sizePointer && this->map[id_i_][id_j_ + 1] != "X") {
        conns_++;
    }

    return conns_;
}
