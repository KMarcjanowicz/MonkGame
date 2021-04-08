#include "Observer.h"

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
}
