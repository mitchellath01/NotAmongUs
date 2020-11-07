#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;
#include "Room.h"
#include "Suspect.h"
//This class is to store the global game files such as the rooms list

vector <Room*> gameRooms;
vector <Suspect*> gameCharacters;
const vector <string> characterNames = { "Adam", "Alex", "Aaron", "Ben", "Carl", "Dan", "David", "Edward", "Fred", "Frank", "George", "Hal", "Hank", "Ike", "John", "Jack", "Joe", "Larry", "Monte", "Matthew", "Mark", "Nathan", "Otto", "Paul", "Peter", "Roger", "Roger", "Steve", "Thomas", "Tim", "Ty", "Victor", "Walter" };
const vector <string> standardAlibis = { "were doing a game of chess", "went on a quick midnight snack together", "were looking at the stars", "did some tiktok dances" };