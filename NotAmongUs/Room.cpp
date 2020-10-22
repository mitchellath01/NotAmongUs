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

void Room::print()
{
	cout << "Room Object | " << "Kind: " << getName();
}

