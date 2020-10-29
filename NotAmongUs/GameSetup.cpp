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

	clearScreen();
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
	printTitleBar("\t Characters Printed");
	system("pause");

	clearScreen();
	printTitleBar("\t Game Loading: Characters into rooms");
	int roomCount = gameRooms.end() - gameRooms.begin() -1;
	int j = -1;
	for (Character* i : gameCharacters) {
		if (j >= roomCount) {
			j = 0;
		} else {
			j = j + 1;
		}
   		gameRooms[j]->roomOccupants.push_back(i);
	}


	for (Room* i : gameRooms) {
		printTitleBar("\tOccupants of " + i->getName());
		vector <Character*> occupants = i->getRoomOccupants();
		for (Character* j : occupants) {
			cout << j->getName();
			cout << "\n";
		}
		system("pause");
	}

}