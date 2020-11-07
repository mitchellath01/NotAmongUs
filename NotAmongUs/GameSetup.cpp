#include "GameSetup.h"
#include "GameFiles.h"
#include "GameUIElements.h"

void startGame() {
	system("cls");
	printTitleBar("\tGame Starting");
	//Test drive greating rooms
	//printSingleBar();
	//cout << "\tGame loading: Rooms";

	gameRooms.clear();
	gameRooms.push_back(new Room(Bedroom));
	gameRooms.push_back(new Room(Kitchen));
	gameRooms.push_back(new Room(MainDeck));
	gameRooms.push_back(new Room(LivingRoom));

	//for (Room* i : gameRooms) {
	//	printSingleBar();
	//	i->print();
	//	printRoom(*i);
	//	system("pause;");
	//}

	//Test drive creating characters
	//clearScreen();
	//printTitleBar("\tGame testing: Characters");
	//gameCharacters.push_back(new Character("Alex", Glass, true));
	//gameCharacters.push_back(new Character("Adriana", Glass, false));
	//gameCharacters.push_back(new Character("Ben", Knife, true));
	//gameCharacters.push_back(new Character("Beth", Knife, false));
	//gameCharacters.push_back(new Character("Cam", Pillow, true));
	//gameCharacters.push_back(new Character("Courtney", Pillow, false));
	//gameCharacters.push_back(new Character("Denis", Pills, true));
	//gameCharacters.push_back(new Character("Daniella", Pills, false));
	//gameCharacters.push_back(new Character("Eric", Bottle, true));
	//gameCharacters.push_back(new Character("Ella", Bottle, false));
	//gameCharacters.push_back(new Character("Fred", HairBrush, true));
	//gameCharacters.push_back(new Character("Francesca", HairBrush, false));
	//system("pause");
	//for (Character* i : gameCharacters) {
	//	printSingleBar();
	//	i->print();
	//	system("pause;");
	//}
	//printTitleBar("\t Character combinations Printed");
	//system("pause");


	gameCharacters.clear();
	system("cls");
	int amountOfInnocentPairs = 2;

	vector<string> usedAlibiSection;
	vector<string> namesToUse = characterNames;

	vector<string> alibisToUse = standardAlibis;
	int alibisToUseCount = 4;

	int characterObjectKindCount = 6;

	srand(unsigned(time(NULL)));
	int randomNumber = rand() % amountOfInnocentPairs;
	int randObject = rand() % characterObjectKindCount;

	printTitleBar("\tGame Loading: Characters");
for (int i = 0; i < (amountOfInnocentPairs * 2) + 1; i++) {

		if (i == amountOfInnocentPairs * 2) {
			string nameC = gameCharacters[randomNumber]->getName(); //random character between 1 and 4
			string alibiC = usedAlibiSection[0] + " haha "; //number between 1 and 4
			int randName = rand() % sizeof(namesToUse) + 1;
			gameCharacters.push_back(new Character(namesToUse[randName], characterObjectKind(randObject), false));
			gameCharacters.back()->setAlibi(nameC + " and i were " + alibiC);
		}
		else if (i % 2 == 0) {
			int randName = rand() % sizeof(namesToUse) + 1;
   			string nameA = namesToUse[randName];
			namesToUse.erase(namesToUse.begin() + randName);
			int randNameB = rand() % sizeof(namesToUse) + 1;
			string nameB = namesToUse[randNameB];
			namesToUse.erase(namesToUse.begin() + randNameB);
			//need alibi logic
			int randAlibi = rand() % (sizeof(alibisToUseCount) - 1);
			string pairedAlibi = alibisToUse[randAlibi];
			usedAlibiSection.push_back(pairedAlibi);
			alibisToUse.erase(alibisToUse.begin() + randAlibi);
			alibisToUseCount -= 1;
			//make characters with alibi
			gameCharacters.push_back(new Character(nameB, characterObjectKind(randObject), false));
			gameCharacters.back()->setAlibi(nameA + " and i were " + pairedAlibi);
			gameCharacters.push_back(new Character(nameA, characterObjectKind(randObject), false));
			gameCharacters.back()->setAlibi(nameB + " and i were " + pairedAlibi);
		}
	}
	//system("pause");
	//for (Character* i : gameCharacters) {
	//	printSingleBar();
	//	cout << randomNumber + "\n";
	//	cout << i->getName() + " | " + i->getAlibi();
	//	system("pause;");
	//}
	//printTitleBar("\t Characters Printed");
	//system("pause");


	clearScreen();
	printTitleBar("\t Game Loading: Characters into rooms");
	//We will randomise the orer of the game characters to ensure 
	//that it's more difficult for the  user to work out who is the imposter
	random_shuffle(gameCharacters.begin(), gameCharacters.end());
	//To get the length of the room cause why not
	int roomCount = gameRooms.end() - gameRooms.begin() -1;
	//Set to -1 because otherwise I would have to add more if's and this works :)
	int j = -1;
	//For every character put them in a room
	for (Character* i : gameCharacters) {
		if (j >= roomCount) {
			//If we run out of rooms go back to the start
			j = 0;
		} else {
			j = j + 1;
		}
		//Add character to room
   		gameRooms[j]->roomOccupants.push_back(i);
	}
	//Print out ocupants
	for (Room* i : gameRooms) {
		printTitleBar("\tOccupants of " + i->getName());
		vector <Character*> occupants = i->getRoomOccupants();
		for (Character* j : occupants) {
			cout << j->getName();
			cout << "\n";
		}
	}
	system("pause");
	startGame();

}