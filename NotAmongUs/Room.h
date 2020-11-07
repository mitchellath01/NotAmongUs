#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <array>
#include <vector>
#include "Suspect.h"
using namespace std;
#include "Enums.h"
//#include "RoomFiles.h" //Not sure if ill end up using this

class Room {

public:
	Room(roomKind newRoomKind);

	string getName();
	string roomLayout();

	vector <Suspect*> getRoomOccupants();

	void print();

	roomKind* roomType;
	vector <Suspect*> roomOccupants;

};