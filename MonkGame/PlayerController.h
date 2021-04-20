#pragma once
#include <vector>
#include "Player.h"
#include "Room.h"
#include "Observer.h"
#include "FightSubject.h"
#include <list>

using namespace std;

class PlayerController
{
private:
    PlayerController();

    static PlayerController* playerController_;

public:
    /**
     * Singletons should not be cloneable.
     */
    PlayerController(PlayerController& other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const PlayerController&) = delete;

    static PlayerController* GetInstance();
    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */

public:
    Player* player;

public:
    void chooseAction();
    void move(vector<Room*> connections_, Room* currentRoom_);
    void pray();
    void fight();
};