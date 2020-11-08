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
vector <string> journalLogs;
int gameTime = 960; //8pm
int furtherQuestioning = 2;
const vector <string> characterNames = { "Adam", "Alex", "Aaron", "Ben", "Carl", "Dan", "David", "Edward", "Fred", "Frank", "George", "Hal", "Hank", "Ike", "John", "Jack", "Joe", "Larry", "Monte", "Matthew", "Mark", "Nathan", "Otto", "Paul", "Peter", "Roger", "Roger", "Steve", "Thomas", "Tim", "Ty", "Victor", "Walter" };
const vector <string> standardAlibis = { "were doing a game of chess", "went on a quick midnight snack together", "were looking at the stars", "did some tiktok dances", "were star gazing, we are lowkey in love!", "were stressing about the USA election, we're the people from Nevada who are supposed to be counting ballots...", "we were doing what Scott Morrision does all day... sleeping! what else?", "were fixing some of the steeting adjustments the captain wanted", "were too busy doing FIT1048 assignments to do anything else!", "were filling out our Monash University SETU Feedback as it is truely important for the college to reflect on the teaching semester from a student perspective" };