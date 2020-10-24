#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;
#include "Room.h"
#include "Character.h"
//This class is to store the global game files such as the rooms list

vector <Room*> gameRooms;
vector <Character*> gameCharacters;
