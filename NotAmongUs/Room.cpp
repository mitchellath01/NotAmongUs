#include "Room.h"

Room::Room(roomKind newRoomKind)
{
	Room::roomType = new roomKind(newRoomKind);
}

string Room::getName()
{
	switch (*roomType) {
	case LivingRoom:
		return "Living Room";
	case Bedroom:
		return "Living Room";
	case Kitchen:
		return "Kitchen";
	case MainDeck:
		return "Main Deck";
	case Hallway:
		return "Hallway";
	case FunRoom:
		return "Fun Room";
	case Bathroom:
		return "Bathroom";
	case EngineRoom:
		return "Engine Room";
	default:
		return "A Room";
	}
}

string Room::roomLayout()
{
	switch (*roomType) {
	case Bedroom:
		return "---------------------\n"
			"|         :)         |\n"
			"|                    3\n"
			"|                    |\n"
			"---------- 5 ---------\n";
	case LivingRoom:
		return "--------- 1 ---------\n"
			"|         :(         |\n"
			"2                    4\n"
			"|                    |\n"
			"----------------------\n";
	case MainDeck:
		return "---------------------\n"
			"|         :/         |\n"
			"|                    |\n"
			"|                    |\n"
			"--------- 3 ----------\n";
	case Kitchen:
		return "---------------------\n"
			"|         :0         |\n"
			"3                    |\n"
			"|                    |\n"
			"---------- 7 ---------\n";
	case FunRoom: 
		return "--------- 2 ---------\n"
		"|         :0         |\n"
		"|                    6\n"
		"|                    |\n"
		"----------------------\n";
	case EngineRoom:
		"--------- 3 ---------\n"
			"|         :0         |\n"
			"5                    7\n"
			"|                    |\n"
			"----------------------\n";
	case Bathroom:
		"--------- 4 ---------\n"
			"|         :0         |\n"
			"6                    |\n"
			"|                    |\n"
			"----------------------\n";
	default:
		return "---------------------\n"
			"|                    |\n"
			"|                    |\n"
			"|                    |\n"
			"----------------------\n";
	}
}

vector<Suspect*> Room::getRoomOccupants()
{
	return roomOccupants;
}

void Room::print()
{
	cout << "Room Object | " << "Kind: " << getName() << " \n";
}

