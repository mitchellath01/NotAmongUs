#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <array>
#include <vector>
#include "Character.h"
using namespace std;
#include "Enums.h"
//#include "RoomFiles.h"

class Room {

public:
	Room(roomKind newRoomKind);

	string getName();
	string roomLayout();

	vector <Character*> getRoomOccupants();

	void print();

	roomKind* roomType;
	vector <Character*> roomOccupants;

};