#include "GameSetup.h"
#include "GameFiles.h"
#include "GameUIElements.h"

void startGame() {
	system("cls");
	printTitleBar("\tGame Starting");
	//Test drive greating rooms
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

	//Test drive creating characters
	clearScreen();
	printTitleBar("\tGame testing: Characters");
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
	printTitleBar("\t Character combinations Printed");
	system("pause");


	gameCharacters.clear();
	system("cls");
	vector<string> usedAlibiSection;
	printTitleBar("\tGame Loading: Characters");
for (int i = 0; i < 4; i++) {
		if (i == 5) {
			string nameC = gameCharacters[0]->getName(); //random character between 1 and 4
			string alibiC = usedAlibiSection[0] + " haha "; //number between 1 and 4
			gameCharacters.push_back(new Character("ERR3", Glass, false));
			gameCharacters.back()->setAlibi(nameC + " and i were " + alibiC);
		}
		else if (i % 2 == 0) {
			//need name logic
   			string nameA = "A";
			string nameB = "B";
			//need alibi logic
			string pairedAlibi = "doing x and y";
			usedAlibiSection.push_back(pairedAlibi);
			//make characters with alibi
			gameCharacters.push_back(new Character("ERR1", Glass, false));
			gameCharacters.back()->setAlibi(nameA + " and i were " + pairedAlibi);
			gameCharacters.push_back(new Character("ERR2", Glass, false));
			gameCharacters.back()->setAlibi(nameB + " and i were " + pairedAlibi);
		}
	}
	system("pause");
	for (Character* i : gameCharacters) {
		printSingleBar();
		cout << i->getName() + " | " + i->getAlibi();
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