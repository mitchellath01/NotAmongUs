#include "GameSetup.h"
#include "GameFiles.h"
#include "GameUIElements.h"

void startGame() {
	system("cls");
	printTitleBar("Game Starting");

	gameRooms.clear();
	gameRooms.push_back(new Room(Bedroom));
	gameRooms.push_back(new Room(Kitchen));
	gameRooms.push_back(new Room(MainDeck));
	gameRooms.push_back(new Room(LivingRoom));

	for (Room* i : gameRooms) {
		i->print();
	}

	printSingleBar();
	system("pause");
	for (Room* i : gameRooms) {
		clearScreen();
		printRoom(*i);
		system("pause;");
	}
}