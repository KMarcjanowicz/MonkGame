// MonkGame.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include "PublicVariables.h"

#include "Dungeon.h"
#include "Player.h"
#include "PlayerController.h"
#include "Observer.h"
#include "GUI.h"

using namespace std;

int main()
{
    char debug = 'q'; 
    //pre-game variables
    PublicVariables* variables = PublicVariables::GetInstance();

    // dungeon generation
    Dungeon* dungeon = Dungeon::GetInstance();
    dungeon->generateDungeonMap(variables->DUNG_SIZE_PTR, variables->getDungMap());

    // player spawn
    Player* player = new Player(10, 0.0f, dungeon->getSpawn(), 15, 3);
    PlayerController* controller = new PlayerController(player);

    //observer
    Observer* observer = Observer::GetInstance();
    observer->player = player;
    observer->dungeon = dungeon;

    do {
        cout << "Debug mode: (y/n)";
        cin >> debug;
    } while (debug != 'n' && debug != 'y');
    GUI::StartScreen();
    player->playerName();
    if (debug == 'y') {
        cout << "Starting room: " << controller->player->currentRoom->id_i << " " << controller->player->currentRoom->id_j << endl;
    }
    // main game loop
    while (!variables->gameEnd) {
        if (debug == 'n') {
            GUI::ClearConsole();
        }
        GUI::PrintPlayerInfo(player);
        GUI::PrintRoomType(player->currentRoom);

        if (debug == 'y') {
            GUI::PrintMapDebug(dungeon->map);
        }
        else {
            GUI::PrintMap(dungeon->map);
        }
        controller->chooseAction();
    }
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
