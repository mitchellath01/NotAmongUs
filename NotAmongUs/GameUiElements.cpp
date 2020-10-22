#include "GameUIElements.h"

//Clear the screen
void clearScreen() {
	system("cls");
}

//The Title Bar
void printTitleBar(string Title = "\tSolve The Mystery") {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << Title + " \n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}

void printSingleBar() {
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void printRoom(Room roomInQuestion)
{
	clearScreen();
	printTitleBar(roomInQuestion.getName());
	cout << roomInQuestion.roomLayout();
}


