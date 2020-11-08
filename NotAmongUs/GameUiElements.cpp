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

void printLayout()
{
	cout << "\t\t     +------------ +\n"
		"\t\t     |1           |\n"
		"\t\t     |   Main     |\n"
		"\t\t     |   deck     |\n"
		"\t\t     |            |\n"
		"\t+------------------  -----------------+\n"
		"\t|2           |3           |4          |\n"
		"\t|                                     |\n"
		"\t|  Bedroom   |Living room |  Kitchen  |\n"
		"\t|            |            |           |\n"
		"\t+-----  -----------  -----------  ----+\n"
		"\t|5           |6           |7          |\n"
		"\t|                                     |\n"
		"\t| Fun Room   |  Engine    | Bathroom  |\n"
		"\t|            |   Room     |           |\n"
		"\t+------------+------------+-----------+\n";

}

void pause()
{
	system("pause");
}

string askForInput(string questionToAsk)
{
	string x;
	printSingleBar();
	cout << ":::> " + questionToAsk + " ";
	getline(std::cin, x);
	return x;
}

