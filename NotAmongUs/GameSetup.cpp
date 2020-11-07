#include "GameSetup.h"
#include "GameFiles.h"
#include "GameUIElements.h"


void startGame() {
	clearScreen();
	printTitleBar("\tGame Starting .");
	//Test drive greating rooms
	//printSingleBar();
	//cout << "\tGame loading: Rooms";

	//Making some rooms
	gameRooms.clear();
	gameRooms.push_back(new Room(Bedroom));
	gameRooms.push_back(new Room(Kitchen));
	gameRooms.push_back(new Room(MainDeck));
	gameRooms.push_back(new Room(LivingRoom));
	//rooms have been added to game memory

	//******** TEST CODE START ********
	//for (Room* i : gameRooms) {
	//	printSingleBar();
	//	i->print();
	//	printRoom(*i);
	//	system("pause;");
	//}

	//Test drive creating characters
	//Lets me see if characters are printing and being created properly, 
	//focusing on object alibis in this case.
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

	clearScreen();
	printTitleBar("\tGame Starting ..");

	//Creating characters with alibis

	gameCharacters.clear();
	clearScreen();
	int amountOfInnocentPairs = 2;

	vector<string> usedAlibiSection;
	vector<string> namesToUse = characterNames;

	vector<string> alibisToUse = standardAlibis;
	int alibisToUseCount = 4;

	int characterObjectKindCount = 6;

	srand(unsigned(time(NULL)));
	int randomNumber = rand() % amountOfInnocentPairs;
	int randObject = rand() % characterObjectKindCount;

	//printTitleBar("\tGame Loading: Characters");
for (int i = 0; i < (amountOfInnocentPairs * 2) + 1; i++) {

		if (i == amountOfInnocentPairs * 2) { 
			//If we're at the final character who isnt in a pair, aka the imposter
			//Pick a random existing character
			string nameC = gameCharacters[randomNumber]->getName(); //random character between 1 and 4
			//Pick an alibi which has already been used
			string alibiC = usedAlibiSection[0] + " haha "; //number between 1 and 4
			//Give them a name
			int randName = rand() % sizeof(namesToUse) + 1;
			//Add them into the list of characters
			gameCharacters.push_back(new Suspect(namesToUse[randName], characterObjectKind(randObject), false));
			//give them an alibi
			gameCharacters.back()->setAlibi(nameC + " and i were " + alibiC);
		}
		else if (i % 2 == 0) { //Create a new pair
			//Decide two names
			int randName = rand() % sizeof(namesToUse) + 1;
   			string nameA = namesToUse[randName];
			namesToUse.erase(namesToUse.begin() + randName); //remove name so it isnt used twice 
			int randNameB = rand() % sizeof(namesToUse) + 1;
			string nameB = namesToUse[randNameB];
			namesToUse.erase(namesToUse.begin() + randNameB); //remove name so it isnt used twice 

			//Pick an unused alibi from random
			int randAlibi = rand() % (sizeof(alibisToUseCount) - 1);
			string pairedAlibi = alibisToUse[randAlibi];
			usedAlibiSection.push_back(pairedAlibi);
			alibisToUse.erase(alibisToUse.begin() + randAlibi);
			alibisToUseCount -= 1;
			//make characters with alibi
			gameCharacters.push_back(new Suspect(nameB, characterObjectKind(randObject), false));
			gameCharacters.back()->setAlibi(nameA + " and i were " + pairedAlibi);
			gameCharacters.push_back(new Suspect(nameA, characterObjectKind(randObject), false));
			gameCharacters.back()->setAlibi(nameB + " and i were " + pairedAlibi);
		}
	}
	//******** TEST CODE START ********
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
	printTitleBar("\tGame Starting ...");

	//clearScreen();
	//printTitleBar("\t Game Loading: Characters into rooms");
	//We will randomise the orer of the game characters to ensure 
	//that it's more difficult for the  user to work out who is the imposter
	random_shuffle(gameCharacters.begin(), gameCharacters.end());
	//To get the length of the room cause why not
	int roomCount = gameRooms.end() - gameRooms.begin() -1;
	//Set to -1 because otherwise I would have to add more if's and this works :)
	int j = -1;
	//For every character put them in a room
	for (Suspect* i : gameCharacters) {
		if (j >= roomCount) {
			//If we run out of rooms go back to the start
			j = 0;
		} else {
			j = j + 1;
		}
		//Add character to room
   		gameRooms[j]->roomOccupants.push_back(i);
	}
	////Print out ocupants
	//for (Room* i : gameRooms) {
	//	printTitleBar("\tOccupants of " + i->getName());
	//	vector <Character*> occupants = i->getRoomOccupants();
	//	for (Character* j : occupants) {
	//		cout << j->getName();
	//		cout << "\n";
	//	}
	//}
	//system("pause");
	//startGame(); //Infinite loop to let me test this code many times to ensure it doesnt break

	clearScreen();
	printTitleBar("\tGame Variables Loaded :)");
	introView();
}

void introView() {
	clearScreen();
	//Should pick a random room to make the dead body room
	//Give the dead body a name, have it asociated with the room
	printTitleBar("\tIt's midnight on the boat\n\tYou are in the kitchen\n\tYou discover someone has been mudered...");
	printLayout();
	askForRoom();
	system("pause");
}

void roomView(Room: roomInQuestion) {

}

int askForRoom() {
	int x = stoi(askForInput("Which room will you investigate?"));
	cout << sizeof(gameRooms) / sizeof(gameRooms[0]);
	if (x > sizeof(gameRooms) / sizeof(gameRooms[0]) || x < 0) {
		cout << x + " uh oh! that was invalid, try again...";
		return askForRoom();
	}
	else {
		cout << "valid room " + gameRooms[x]->getName();
		return x;
	}
}


//Ask Screen -> Go to a room -> pick a suspect (2 guesses remaining)
//Room Selection -> Select room
//Inside room -> Interrogate x y z, follow up ask them about object -> return to rooms 