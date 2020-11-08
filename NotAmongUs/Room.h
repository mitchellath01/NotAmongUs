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
#include "RoomObject.h"
//#include "RoomFiles.h" //Not sure if ill end up using this

class Room {

public:
	Room(roomKind newRoomKind);

	string getName();
	string roomLayout();

	vector <Suspect*> getRoomOccupants();

	void print();

	roomKind* roomType;
	bool containsDeadBody;
	vector <Suspect*> getRawRoomOccupants();
	vector <string> getDisplayRoomOccupantNames(characterObjectKind murderWeapon);
	void addRoomOccupant(Suspect* newSuspect);
	void setRawRoomOccupants(vector <Suspect*> newOccupants);

	RoomObject* objectInRoom;
private:
	vector <Suspect*> roomOccupants;
};