#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <array>
using namespace std;
#include "CharacterObject.h"

class Character {

public:
	Character(string newName, characterObjectKind newType, bool innocentStatus);
	string getName();
	string getObjectAlibi(); //Explains why they have a certain object
	string getRegularAlibi();
	string getObjectName();
	bool getIsInnocent();
	void print();
	void setName(string newName);
	void setAlibi(string newAlibi);
	string getAlibi();
private:
	characterObjectKind object;
	bool isInnocent;
	string alibi;
	string name;
};