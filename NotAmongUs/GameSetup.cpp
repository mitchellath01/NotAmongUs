#include "GameSetup.h"
#include "GameFiles.h"
#include "GameUIElements.h"


//Make room object class
//Rooms can contain objects
//Each room gets object
//One room gets bloodied object at random
//One room is bloodied

//Murdered person needs a murder method, murder tool, murder location

//Game setup
void startGame() {
	clearScreen();
	printTitleBar("\tGame Starting .");
	furtherQuestioning = 2;
	int gameTime = 960; //8pm
	journalLogs.clear();

	//Test drive greating rooms
	//printSingleBar();
	//cout << "\tGame loading: Rooms";

	//Making some rooms
	gameRooms.clear();
	gameRooms.push_back(new Room(MainDeck));
	gameRooms.push_back(new Room(Bedroom));
	gameRooms.push_back(new Room(LivingRoom));
	gameRooms.push_back(new Room(Kitchen));
	gameRooms.push_back(new Room(FunRoom));
	gameRooms.push_back(new Room(EngineRoom));
	gameRooms.push_back(new Room(Bathroom));
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

	characterObjectKind imposterObject; //use when adding objects around the map
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
			imposterObject = characterObjectKind(randObject);
			gameCharacters.push_back(new Suspect(namesToUse[randName], imposterObject, false));
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


		//Make room object class
//Rooms can contain objects
//Each room gets object
//One room gets bloodied object at random
//One room is bloodied
		int murderObjectRoom = rand() % (sizeof(gameRooms) / sizeof(gameRooms[0]));
		int murderBodyRoom = rand() % (sizeof(gameRooms) / sizeof(gameRooms[0]));
		int count = 0;
		for (Room* i : gameRooms) {
			if (murderObjectRoom == count) { //Add a bloody object!
				i->objectInRoom = RoomObject(imposterObject, true);
			}
			else if (murderBodyRoom == count) { //Add a dead body!
				//dead person mechanics
			}
			else { //Regular room object
				i->objectInRoom = RoomObject(characterObjectKind(randObject), true);
			}
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

//First screen of gameplay
void introView() {
	clearScreen();
	//Should pick a random room to make the dead body room
	//Give the dead body a name, have it asociated with the room
	printTitleBar("\tIt's midnight on the boat\n\tYou are in the kitchen\n\tYou discover someone has been mudered...");
	printLayout();
	handleInput();
}

//display the map view
void mapView() {
	clearScreen();
	printLayout();
	handleInput();
}

//Display the room view
void roomView(Room roomInQuestion) {
	clearScreen();
	printTitleBar("\t" + roomInQuestion.getName());
	cout << roomInQuestion.roomLayout();
	printSingleBar();
	cout << "\nRoom Occupants";
	for (Suspect* i : roomInQuestion.getRoomOccupants()) {
		cout << "\n\t" + i->getName();
	}
	handleInput();
}

//increment the time
void addTime(int taskLevel) {
	gameTime += taskLevel * 4;
}

//get time in form of string HH:MM
string timeInString() {
	float converted = gameTime / 60.0;
	converted *= 100;
	int normalised = converted;
	string toInsert = to_string(normalised);
	toInsert.insert(2, ":");
	return toInsert;
}

//get index of room by room name
int roomIndexByName(string roomInQuestion) {
	int x = 0;
	for (Room* i : gameRooms) {
		string roomName = i->getName();
		transform(roomName.begin(), roomName.end(), roomName.begin(), ::toupper);
		if (roomName == roomInQuestion) {
			return x;
		}
		else {
			x += 1;
		}
	}
	return x;
}

//get index of suspect by their name
int suspectIndexByName(string suspectInQuestion) {
	int x = 0;
	for (Suspect* i : gameCharacters) {
		string characterName = i->getName();
		transform(characterName.begin(), characterName.end(), characterName.begin(), ::toupper);
		if (characterName == suspectInQuestion) {
			return x;
		}
		else {
			x += 1;
		}
	}
	return x;
}

//Log item into journal
void logToJournal(string activity, string description) {
	journalLogs.push_back(timeInString() + " | " + activity + " | " + description);
}

//Returns the room indexes where an item is found in
vector<int> roomIndexesByItem(characterObjectKind objectInQuestion) {
	vector<int> results;
	int iterator = 0;
	for (Room* i : gameRooms) {
		bool isInRoom = false;
		for (Suspect* j : i->getRoomOccupants()) {
			if (j->getObject() == objectInQuestion) {
				isInRoom = true;
			}
		}
		if (isInRoom) {
			results.push_back(iterator);
		}
		iterator += 1;
	}
	return results;
}

//Handle user input
void handleInput() {
	//Get user input handling
	stringstream rawUserInput(askForInput("\nNext Command: \n"));
	vector<string> userInputVec;
	while (rawUserInput.good())
	{
		string a;
		getline(rawUserInput, a, ' ');
		transform(a.begin(), a.end(), a.begin(), ::toupper);
		userInputVec.push_back(a);
	}
	//Action the input
	if (userInputVec[0] == "HELP") { //TODO: Print Help File
		cout << "Help commans go here";
	//Quit Came
	} else if (userInputVec[0] == "QUIT") { 
		cout << "Quitting";
	//Go to room
	} else if (userInputVec[0] == "GOTO") {
		int roomIndex = roomIndexByName(userInputVec[1]);
		if (roomIndex > (sizeof(gameRooms) / sizeof(gameRooms[0]))) {
			cout << "Invalid Room!";
			handleInput();
		}
		else {
			addTime(2);
			roomView(*gameRooms[roomIndex]);
		}
	}
	//Question a character
	else if (userInputVec[0] == "QUESTION") {
		int suspectIndex = suspectIndexByName(userInputVec[1]);
		if (suspectIndex > (sizeof(gameCharacters) / sizeof(gameCharacters[0]))) {
			cout << "Invalid Character Name!\n";
		}
		else {
			addTime(1);
			cout << "YOU: " + gameCharacters[suspectIndex]->getName() + ", can you explain to me what you were \n\tdoing before this happened?\n";
			cout << gameCharacters[suspectIndex]->getName() + ": " + gameCharacters[suspectIndex]->getAlibi() + "\n";
			logToJournal("Questioning", gameCharacters[suspectIndex]->getName() + ": " + gameCharacters[suspectIndex]->getAlibi());
			cout << "Would you like to question them further? \n(Only " + to_string(furtherQuestioning) + " further questioning opportunities left\n Use command QUSETIONFURTER " + gameCharacters[suspectIndex]->getName() + "\n";
		}
		handleInput();
	}
	//Question someone further
	else if (userInputVec[0] == "QUESTIONFURTHER") {
		if (furtherQuestioning > 0) {
			int suspectIndex = suspectIndexByName(userInputVec[1]);
			if (suspectIndex > (sizeof(gameCharacters) / sizeof(gameCharacters[0]))) {
				cout << "Invalid Character Name!\n";
				handleInput();
			}
			else {
				furtherQuestioning -= 1;
				addTime(10);
				cout << "YOU: " + gameCharacters[suspectIndex]->getName() + ", why are you holding " + gameCharacters[suspectIndex]->getObjectName() + "?\n";
				cout << gameCharacters[suspectIndex]->getName() + ": " + gameCharacters[suspectIndex]->getObjectAlibi() + "\n";
				logToJournal("Further Questioning", gameCharacters[suspectIndex]->getName() + ": " + gameCharacters[suspectIndex]->getObjectAlibi());
				cout << to_string(furtherQuestioning) + " further questionings remain.\n";
			}
		}
		else {
			cout << "no more further questioning remains\n";
		}
		handleInput();
	//read the journal
	} else if (userInputVec[0] == "JOURNAL") { 
		addTime(7);
		clearScreen();
		printTitleBar("\tJournal Entries");
		for (string i : journalLogs) {
			cout << i + "\n";
		}
		printSingleBar();
		pause();
	//Search a room	******** TO DO ********
	} else if (userInputVec[0] == "SEARCH") { //TO DO
		//Returns info on a room
		cout << "search";
	//Go to map
	} else if (userInputVec[0] == "MAP") { 
		mapView();
	//Get time
	} else if (userInputVec[0] == "WATCH") { 
		cout << "The time is " + timeInString() + "\n";
		pause();
		handleInput();
	} else { 
		cout << "\nInvalid Command\n"; 
		system("Pause"); 
		handleInput();
	}
}