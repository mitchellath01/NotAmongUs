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
		return "Bedroom"; //2
	case Kitchen:
		return "Kitchen";
	case MainDeck:
		return "Main Deck"; //1
	case Hallway:
		return "Hallway";
	case FunRoom:
		return "Fun Room";
	case Bathroom:
		return "Bathroom";
	case EngineRoom:
		return "Engine Room"; //6
	default:
		return "A Room";
	}
}

string Room::roomLayout()
{
	switch (*roomType) {
	case MainDeck:
		return "---------------------\n"
			"|         :/         |\n"
			"|                    |\n"
			"|                 *  |\n"
			"|                    |\n"
			"--------- 3 ----------\n";
	case Bedroom:
		return "---------------------\n"
			"| *       :)         |\n"
			"|                    3\n"
			"|                    |\n"
			"|                    |\n"
			"---------- 5 ---------\n";
	case LivingRoom:
		return "--------- 1 ---------\n"
			"|         :(         |\n"
			"2                *   4\n"
			"|                    |\n"
			"|                    |\n"
			"----------------------\n";
	case Kitchen:
		return "---------------------\n"
			"|         :0         |\n"
			"3                *   |\n"
			"|                    |\n"
			"|                    |\n"
			"---------- 7 ---------\n";
	case FunRoom: 
		return "--------- 2 ---------\n"
			"|         :3         |\n"
			"|                    6\n"
			"|  *                 |\n"
			"|                    |\n"
		"----------------------\n";
	case EngineRoom:
		return "--------- 3 ---------\n"
			"|         :$         |\n"
			"5                    7\n"
			"|               *    |\n"
			"|                    |\n"
			"----------------------\n";
	case Bathroom:
		return "--------- 4 ---------\n"
			"|         :*       * |\n"
			"6                    |\n"
			"|                    |\n"
			"|                    |\n"
			"----------------------\n";
	default:
		return "---------------------\n"
			"|                    |\n"
			"|         0          |\n"
			"|                    |\n"
			"|                 *  |\n"
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

