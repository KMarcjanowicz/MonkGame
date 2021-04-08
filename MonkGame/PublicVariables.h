#pragma once
#include <string>
#include <vector>

using namespace std;

class PublicVariables
{
private:
    PublicVariables();

    static PublicVariables* variables_;

public:
    /**
     * Singletons should not be cloneable.
     */
    PublicVariables(PublicVariables& other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const PublicVariables&) = delete;

    static PublicVariables* GetInstance();
    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */

private:
	int DUNG_SIZE= 10;
    vector<vector<string>> DUNG_MAP{
    {"X", "X", "X", "X", "X", "X", "X", "X", "X", "X"},
    {"X", "P", "O", "O", "O", "X", "X", "X", "X", "X"},
    {"X", "X", "X", "X", "O", "X", "M", "X", "X", "X"},
    {"X", "X", "E", "X", "M", "X", "O", "X", "X", "X"},
    {"X", "X", "O", "X", "O", "X", "O", "X", "X", "X"},
    {"X", "M", "O", "O", "O", "E", "O", "O", "E", "X"},
    {"X", "X", "X", "X", "X", "O", "X", "O", "X", "X"},
    {"X", "X", "X", "X", "M", "O", "X", "O", "X", "X"},
    {"X", "X", "X", "X", "X", "X", "X", "O", "M", "T"},
    {"X", "X", "X", "X", "X", "X", "X", "X", "X", "X"}
    };
public:
	int* DUNG_SIZE_PTR = &DUNG_SIZE;
    bool gameEnd = false;
public:
    void printDungeonMap();
    vector<vector<string>> getDungMap();
};

