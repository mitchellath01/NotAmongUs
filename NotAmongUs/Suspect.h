#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <array>
using namespace std;
#include "CharacterObject.h"

class Suspect {

public:
	Suspect(string newName, characterObjectKind newType, bool innocentStatus);
	string getName(); //Find out their name in a string form
	string getObjectAlibi(); //Explains why they have a certain object
	string getRegularAlibi(); //Explains who they were with etc
	string getObjectName(); //Object they are holding name in string form
	bool getIsInnocent(); //Are they innocent?
	void print(); //Print out details 
	void setName(string newName); //Give em a name
	void setAlibi(string newAlibi); //Give em an alibi
	string getAlibi(); //Tell us the alibi
private:
	characterObjectKind object; //Object they are holding
	bool isInnocent; //true if innocent, false if a murderer
	string alibi; //An alibi in a string form
	string name; //Their name
};