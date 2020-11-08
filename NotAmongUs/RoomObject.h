#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <array>
using namespace std;

#include "Enums.h"
#include "CharacterObject.h"


class RoomObject: public CharacterObject {
public:
	RoomObject();
	RoomObject(characterObjectKind objectKind, bool bloodyObjectStatus);
	bool isObjectBloody();
	characterObjectKind objectKind;
private:
	bool isBloody;
};