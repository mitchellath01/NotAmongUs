#include "GameSetup.h"
#include "GameFiles.h"
#include "GameUIElements.h"//dont judge, these are not in header or it goes funny

//Murdered person needs a murder method, murder tool, murder location
int timePenalty = 0;
characterObjectKind murderWeapon;
bool hasCompletedMainTasks;

//Game setup
void startGame() {
	clearScreen();
	readHelp();
	pause();
	//Clear screen and reset variables here
	clearScreen();
	askForDifficulty();

	printTitleBar("\tGame Starting .");
	
	furtherQuestioning = 2;
	int gameTime = 1200; //8pm
	journalLogs.clear();
	hasCompletedMainTasks = false;


	//Making some rooms
	gameRooms.clear();
	createGameRooms();
	bulkGameSetup(3);
	
	//Game has been setup
	clearScreen();
	printTitleBar("\tGame Variables Loaded :)\n");
	pause();
	clearScreen();
	printTitleBar("\n\tThere is one dead person...\n\tAmoung us\n");
	pause();
	introView();
}

void askForDifficulty() {
	clearScreen();
	printTitleBar("\tChoose difficulty: (enter number)\n-Easy\n-Medium\n-Hard\n");
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
		if (userInputVec[0] == "EASY") { timePenalty = 1; }
		else if (userInputVec[0] == "MEDIUM") { timePenalty = 2; }
		else if (userInputVec[0] == "HARD") { timePenalty = 4; } 
		else { askForDifficulty(); }
}

void createGameRooms() {
	gameRooms.push_back(new Room(MainDeck));
	gameRooms.push_back(new Room(Bedroom));
	gameRooms.push_back(new Room(LivingRoom));
	gameRooms.push_back(new Room(Kitchen));
	gameRooms.push_back(new Room(FunRoom));
	gameRooms.push_back(new Room(EngineRoom));
	gameRooms.push_back(new Room(Bathroom));
}

//******** TEST CODE CREATE GAME ROOMS ********
void printGameRooms() {
	for (Room* i : gameRooms) {
		printSingleBar();
		i->print();
		printRoom(*i);
		system("pause;");
	}
}

//Majority of the game setup goes here
void bulkGameSetup(int innocentPairs) {
	//Creating characters with alibis
	gameCharacters.clear();
	clearScreen();
	int amountOfInnocentPairs = innocentPairs;

	vector<string> usedAlibiSection;
	vector<string> namesToUse = characterNames;

	vector<string> alibisToUse = standardAlibis;

	//BASED ON GAME PARAMETERS *************************
	int alibisToUseCount = 10;
	int characterObjectKindCount = 6;

	srand(unsigned(time(NULL)));
	int randomNumber = rand() % amountOfInnocentPairs;
	int randObject = rand() % characterObjectKindCount;

	characterObjectKind imposterObject = characterObjectKind(randObject); //use when adding objects around the map
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
			randObject = rand() % characterObjectKindCount;
			if (murderObjectRoom == count) { //Add a bloody object!
				i->objectInRoom = new RoomObject(imposterObject, true);
				murderWeapon = imposterObject;
			}
			else { //Regular room object
				i->objectInRoom = new RoomObject(characterObjectKind(randObject), false);
			}
			if (murderBodyRoom == count) { //Add a dead body!
				i->containsDeadBody = true;
			}
			count += 1;
		}

	clearScreen();
	printTitleBar("\tGame Starting ...");


	//We will randomise the orer of the game characters to ensure 
	//that it's more difficult for the  user to work out who is the imposter
	random_shuffle(gameCharacters.begin(), gameCharacters.end());
	//To get the length of the room cause why not
	int roomCount = gameRooms.end() - gameRooms.begin() - 1;
	//Set to -1 because otherwise I would have to add more if's and this works :)
	int j = -1;
	//For every character put them in a room
	for (Suspect* i : gameCharacters) {
		if (j >= roomCount) {
			//If we run out of rooms go back to the start
			j = 0;
		}
		else {
			j = j + 1;
		}
		//Add character to room
		gameRooms[j]->addRoomOccupant(i);
	}
}


//First screen of gameplay
void introView() {
	clearScreen();
	//Should pick a random room to make the dead body room
	//Give the dead body a name, have it asociated with the room
	printTitleBar("\tIt's midnight on the boat\n\tYou hear a scream,\n\tYou discover someone has been mudered...");
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
	handleInput();
}

//Give details on the room
void searchRoom(Room roomInQuestion) {
	printSingleBar();
	cout << "\t" + roomInQuestion.getName() + " details:";
	cout << "\nRoom Occupants:";
	for (string i : roomInQuestion.getDisplayRoomOccupantNames(murderWeapon)) {
		cout << "\n\t" + i;
	}
	cout << "\nObject in Room:\n";
	if (roomInQuestion.objectInRoom->isObjectBloody()) {
		cout << CharacterObject::getObjectName(roomInQuestion.objectInRoom->objectKind) + ", smeared in blood!" + "\n";
		logToJournal("FOUND - BLOODY", CharacterObject::getObjectName(roomInQuestion.objectInRoom->objectKind) + " >" + roomInQuestion.getName());
		/*hasFoundMurderWeapon = true;*/
	}
	else {
		cout << CharacterObject::getObjectName(roomInQuestion.objectInRoom->objectKind) + "\n";
		logToJournal("FOUND", CharacterObject::getObjectName(roomInQuestion.objectInRoom->objectKind) + " >" + roomInQuestion.getName());
		if (roomInQuestion.containsDeadBody) {
			/*hasFoundMurderWeapon = true;*/
			logToJournal("CRIME SCENE FOUND", roomInQuestion.getName());
			cout << "NOTE: the room is bloody...";
		}
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

void checkCompletion() {
	bool hasInterrogatedAll = true;
	for (Suspect* i : gameCharacters) {
		if (i->hasBeenInterrogated == false) {
			hasInterrogatedAll = false;
		}
	}
	bool hasVisitedAll = true;
	bool hasSearchedAll = true;
	for (Room* i : gameRooms) {
		if (i->hasBeenVisited == false) {
			hasVisitedAll = false;
		}
		if (i->hasBeenSearched == false) {
			hasVisitedAll = false;
		}
	}
	if (hasInterrogatedAll && hasVisitedAll && hasSearchedAll) {
		hasCompletedMainTasks = true;
	}
	if (gameTime > 1320) {
		clearScreen();
		cout << "you failed, it took too long";
		return;
	}
}

void readHelp() {
	// open file for reading
	ifstream fileToRead("howToPlay.txt");

	if (fileToRead.is_open()) {
		string line = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line);
			cout << line << "\n";
		}
	}
	else {
		cout << "\n File Not Found.\n";
	}
	// remember to close the file
	fileToRead.close();
}

//Handle user input
void handleInput() {
	if (hasCompletedMainTasks) {
		cout << "you can now use the 'Guess x' function";
	}
	else {
		cout << "keep searching around, and asking questions\nYou have to guess before time runs out!";
		checkCompletion();
	}
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
		readHelp();
	//Quit Came
	} 
	else if (userInputVec[0] == "QUIT") { 
		cout << "Quitting";
		return;
	//Go to room
	} 
	else if (userInputVec[0] == "GOTO") {
		int roomIndex = roomIndexByName(userInputVec[1]);
		if (roomIndex > gameRooms.size()) {
			cout << "Invalid Room!";
		}
		else {
			addTime(2);
			gameRooms[roomIndex]->hasBeenVisited = true;
			roomView(*gameRooms[roomIndex]);
		}
	}
	//Question a character
	else if (userInputVec[0] == "QUESTION") {
		int suspectIndex = suspectIndexByName(userInputVec[1]);
		if (suspectIndex > gameCharacters.size() - 1) {
			cout << "Invalid Character Name!\n";
		}
		else {
			addTime(1);
			cout << "YOU: " + gameCharacters[suspectIndex]->getName() + ", can you explain to me what you were \n\tdoing before this happened?\n";
			cout << gameCharacters[suspectIndex]->getName() + ": " + gameCharacters[suspectIndex]->getAlibi() + "\n";
			logToJournal("Questioning", gameCharacters[suspectIndex]->getName() + ": " + gameCharacters[suspectIndex]->getAlibi());
			cout << "Would you like to question them further? \n(Only " + to_string(furtherQuestioning) + " further questioning opportunities left\n Use command QUSETIONFURTER " + gameCharacters[suspectIndex]->getName() + "\n";
			gameCharacters[suspectIndex]->hasBeenInterrogated = true;
			if (gameCharacters[suspectIndex]->getIsInnocent() == false) {
				/*hasQuestionedImposter = true;*/

			}
		}
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
	//read the journal

	} 
	else if (userInputVec[0] == "JOURNAL") { 
		addTime(7);
		clearScreen();
		printTitleBar("\tJournal Entries");
		for (string i : journalLogs) {
			cout << i + "\n";
		}
		printSingleBar();
		pause();
	//Search a room
	} 
	else if (userInputVec[0] == "SEARCH") {
		int roomIndex = roomIndexByName(userInputVec[1]);
		if (roomIndex > gameRooms.size() -1) {
			cout << "Invalid Room!";
		}
		else {
			addTime(2);
			gameRooms[roomIndex]->hasBeenSearched = true;
			searchRoom(*gameRooms[roomIndex]);
		}
	//Go to map
	} 
	else if (userInputVec[0] == "MAP") { 
		mapView();
	//Get time
	} 
	else if (userInputVec[0] == "WATCH") { 
		cout << "The time is " + timeInString() + "\n";
		pause();
	} 
	else if (userInputVec[0] == "GUESS") {
		if (hasCompletedMainTasks) {
			for (Suspect* i : gameCharacters) {
				string a = i->getName();
				transform(a.begin(), a.end(), a.begin(), ::toupper);
				if (userInputVec[1] == a) {
					clearScreen();
					cout << "you have found the imposter\nCongratulations!\n";
					pause();
					return;
				}
			}
			clearScreen();
			addTime(5);
			cout << "you NOT have found the imposter\nyou have failed\n";
			pause();
			return;
		}
		else {
			cout << "You need more info first I think!\nCheck every room\nquestion everyone!\nEnsure you have searched far and near\n";
		}

	}
	else { 
		cout << "\nInvalid Command\n"; 
		pause();
	}
	checkCompletion();
	handleInput();
}