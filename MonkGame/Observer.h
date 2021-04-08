#pragma once
#include "Room.h"
class Observer
{
private:
	Observer();

	static Observer* observer_;

public:
    /**
     * Singletons should not be cloneable.
     */
    Observer(Observer& other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Observer&) = delete;

    static Observer* GetInstance();
    /**
     * Finally, any singleton should define some business logic, which can be`
     * executed on its instance.
     */

public:
    void playerMove(Room* currentRoom_, Room* desiredRoom_);

};

