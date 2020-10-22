#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <array>
using namespace std;
#include "RoomKind.h"

class Room {

public:
	Room(roomKind newRoomKind);

	string getName();

	void print();

	roomKind* roomType;
};