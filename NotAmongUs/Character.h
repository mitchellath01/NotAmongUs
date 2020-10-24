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
	string getAlibi();
	string getObjectName();
	bool getIsInnocent();
	void print();
private:
	characterObjectKind object;
	bool isInnocent;
	string name;
};