#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

void startGame();
void introView();
//int askForRoom();
void mapView();
void introView();
void handleInput();
void createGameRooms();
void bulkGameSetup(int innocentPairs);
void askForDifficulty();
void logToJournal(string activity, string description);
void readHelp();