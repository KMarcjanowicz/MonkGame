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
    int id_i_ = 0;
    int id_j_ = 0;
    this->numberOfRooms = 0;

    for (int i = 0; i < *sizePointer; i++) {
        for (int j = 0; j < *sizePointer; j++) {
            if (this->map[i][j] == "P") {
                id_i_ = i;
                id_j_ = j;
                this->numberOfRooms++;
            }
            else if (this->map[i][j] != "X") {
                this->numberOfRooms++;
            }
        }
    }
    Corridor* corridor = new Corridor(id_i_, id_j_, getNumberOfConnections(id_i_, id_j_, sizePointer));
    //cout << id_i_ << " " << id_j_ << " " << this->numberOfRooms << endl;
    generateConnections(corridor, sizePointer);
    //cout << this->roomMap.size();
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

void Dungeon::generateConnections(Room* room_, int* sizePointer)
{
    
    int id_i_ = room_->id_i;
    int id_j_ = room_->id_j;
    if (!this->roomMap.empty()) {
        for (int i = 0; i < this->roomMap.size(); i++) {
            if (this->roomMap[i]->id_i == room_->id_i && this->roomMap[i]->id_j == room_->id_j) {
                return;
            }
        }
    }
    
    this->roomMap.push_back(room_);
    //cout << id_i_ << " " << id_j_ << " " << room_->connections << endl;

    if (id_i_ - 1 >= 0 && this->map[id_i_ - 1][id_j_] != "X") {
        Corridor* corridor = new Corridor(id_i_ - 1, id_j_, getNumberOfConnections(id_i_ - 1, id_j_, sizePointer));
        room_->connected.push_back(corridor);
        generateConnections(corridor, sizePointer);
    }
    if (id_i_ + 1 < *sizePointer && this->map[id_i_ + 1][id_j_] != "X") {
        Corridor* corridor = new Corridor(id_i_ + 1, id_j_, getNumberOfConnections(id_i_ + 1, id_j_, sizePointer));
        room_->connected.push_back(corridor);
        generateConnections(corridor, sizePointer);
    }
    if (id_j_ - 1 >= 0 && this->map[id_i_][id_j_ - 1] != "X") {
        Corridor* corridor = new Corridor(id_i_, id_j_ - 1, getNumberOfConnections(id_i_, id_j_ - 1, sizePointer));
        room_->connected.push_back(corridor);
        generateConnections(corridor, sizePointer);
    }
    if (id_j_ + 1 < *sizePointer && this->map[id_i_][id_j_ + 1] != "X") {
        Corridor* corridor = new Corridor(id_i_, id_j_ + 1, getNumberOfConnections(id_i_, id_j_ + 1, sizePointer));
        room_->connected.push_back(corridor);
        generateConnections(corridor, sizePointer);
    }

    return;
}
