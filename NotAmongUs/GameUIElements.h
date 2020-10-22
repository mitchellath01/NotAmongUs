#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include "GameSetup.h"
#include "Room.h"

using namespace std;
void clearScreen();
void printTitleBar(string Title);
void printSingleBar();
void printRoom(Room roomInQuestion);