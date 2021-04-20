#include "Observer.h"
#include "MonsterRoom.h"
#include "Goblin.h"
#include "FightSubject.h"

using namespace std;

Observer* Observer::observer_ = nullptr;;

Observer::Observer() {
}

Observer* Observer::GetInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if (observer_ == nullptr) {
        observer_ = new Observer();
    }
    return observer_;
}

void Observer::playerMove(Room* currentRoom_, Room* desiredRoom_)
{
    dungeon->changePlayerLocation(currentRoom_, desiredRoom_, player);
}

void Observer::playerPray()
{
    this->player->addHP();
}

void Observer::PlayerFight(Player* player_, Room* room_)
{
    MonsterRoom* monsterRoom = dynamic_cast<MonsterRoom*>(room_);
    vector<Entity*>monsters = monsterRoom->monsters;
    //cout << monsters.size();

    FightSubject* FightObject = new FightSubject();
    FightObject->Attach(player_);
    for (int i = 0; i < monsters.size(); i++)
    {
        FightObject->Attach(monsters[i]);
    }

    while (FightObject->HowManyFighters() > 1)
    {
        FightObject->NotifyTurn(FightObject->DecideTurn());

    }
    delete FightObject;
}
