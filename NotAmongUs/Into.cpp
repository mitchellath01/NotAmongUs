#include "Intro.h"
#include "GameUIElements.h"
//Main function
int main() {
	displayMenu();
}


//Display info 
void displayMenu() {
	clearScreen();
	printTitleBar("\tScary game title :)");
	readFile("gameInfo.txt");//Get game info
	cout << "\n";
	system("pause");
	startGame();
}


//*********		FILE READ		********
//Print contents of file
void readFile(string myFileName) {
	// open file for reading
	ifstream fileToRead(myFileName);

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