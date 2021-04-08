// MonkGame.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include "PublicVariables.h"

#include "Dungeon.h"
#include "Player.h"
#include "PlayerController.h"
#include "GUI.h"

using namespace std;

int main()
{
    // dungeon generation
    std::cout << "Hello World!\n";
    PublicVariables* variables = PublicVariables::GetInstance();
    Dungeon* dungeon = Dungeon::GetInstance();
    dungeon->generateDungeonMap(variables->DUNG_SIZE_PTR, variables->getDungMap());

    // player spawn
    Player* player = new Player(10, 0.0f, dungeon->getSpawn());
    PlayerController* controller = new PlayerController(player);
    cout << "Starting room: " << controller->player->currentRoom->id_i << " " << controller->player->currentRoom->id_j << endl;

    // main game loop
    while (!variables->gameEnd) {
        GUI::printMap(dungeon->map);
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
