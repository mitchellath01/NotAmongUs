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
			"|                    |\n"
			"|                    |\n"
			"----------------------\n";
	case LivingRoom:
		return "---------------------\n"
			"|         :(         |\n"
			"|                    |\n"
			"|                    |\n"
			"----------------------\n";
	case MainDeck:
		return "---------------------\n"
			"|         :/         |\n"
			"|                    |\n"
			"|                    |\n"
			"----------------------\n";
	case Kitchen:
		return "---------------------\n"
			"|         :0         |\n"
			"|                    |\n"
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

