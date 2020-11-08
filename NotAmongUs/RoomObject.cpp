#include "RoomObject.h"

RoomObject::RoomObject()
{
	
}

RoomObject::RoomObject(characterObjectKind newObjectKind, bool bloodyObjectStatus)
{
	objectKind = newObjectKind;
	isBloody = bloodyObjectStatus;
	characterObjectKind getObjectKind();
}

bool RoomObject::isObjectBloody()
{
	return isBloody;
}
