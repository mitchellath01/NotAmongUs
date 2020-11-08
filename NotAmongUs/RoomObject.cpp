#include "RoomObject.h"

RoomObject::RoomObject(characterObjectKind objectKind, bool bloodyObjectStatus)
{
	objectKind = objectKind;
	isBloody = bloodyObjectStatus;
}

bool RoomObject::isObjectBloody()
{
	return isBloody;
}
