#include "GameSetup.h"
#include "GameFiles.h"
#include "GameUIElements.h"

void startGame() {
	system("cls");
	printTitleBar("\tGame Starting");
	//Dirver Code:
	printSingleBar();
	cout << "\tGame loading: Rooms";

	gameRooms.clear();
	gameRooms.push_back(new Room(Bedroom));
	gameRooms.push_back(new Room(Kitchen));
	gameRooms.push_back(new Room(MainDeck));
	gameRooms.push_back(new Room(LivingRoom));

	for (Room* i : gameRooms) {
		printSingleBar();
		i->print();
		printRoom(*i);
		system("pause;");
	}

	printTitleBar("\tGame loading: Characters");
	gameCharacters.push_back(new Character("Alex", Glass, true));
	gameCharacters.push_back(new Character("Adriana", Glass, false));
	gameCharacters.push_back(new Character("Ben", Knife, true));
	gameCharacters.push_back(new Character("Beth", Knife, false));
	gameCharacters.push_back(new Character("Cam", Pillow, true));
	gameCharacters.push_back(new Character("Courtney", Pillow, false));
	gameCharacters.push_back(new Character("Denis", Pills, true));
	gameCharacters.push_back(new Character("Daniella", Pills, false));
	gameCharacters.push_back(new Character("Eric", Bottle, true));
	gameCharacters.push_back(new Character("Ella", Bottle, false));
	gameCharacters.push_back(new Character("Fred", HairBrush, true));
	gameCharacters.push_back(new Character("Francesca", HairBrush, false));
	system("pause");
	for (Character* i : gameCharacters) {
		printSingleBar();
		i->print();
		system("pause;");
	}

}