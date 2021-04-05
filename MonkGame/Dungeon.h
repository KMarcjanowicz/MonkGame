
#pragma once
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
};

