#include "Dungeon.h"
#include "iostream"

using namespace std;

Dungeon* Dungeon::dungeon_ = nullptr;;

Dungeon::Dungeon()
{
    cout << "Created a new Dungeon" << endl;
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
