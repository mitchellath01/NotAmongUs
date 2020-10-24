#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <array>
using namespace std;
#include "Enums.h"

class CharacterObject {

public:
	static string getObjectName(characterObjectKind objectType);
};