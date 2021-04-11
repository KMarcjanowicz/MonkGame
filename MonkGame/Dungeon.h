
#pragma once
#include <string>
#include <vector>
#include "Room.h"
#include "Player.h"

using namespace std;

class Dungeon
{
private:
    Dungeon();

    static Dungeon* dungeon_;

public:
    /**
     * Singletons should not be cloneable.
     */
    Dungeon(Dungeon& other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Dungeon&) = delete;

    static Dungeon* GetInstance();
    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */
public:
    vector<vector<string>> map;
    vector<Room*> roomMap;
    int numberOfRooms;

public:
    bool generateDungeonMap(int* sizePointer, vector<vector<string>> map);
    bool changePlayerLocation(Room* playerRoom_, Room* desiredRoom_, Player* player_);
    Room* getSpawn();
private:
    int getNumberOfConnections(int id_i_, int id_j_, int* sizePointer);
    void generateConnections(Room* room_, int* sizePointer);
};

