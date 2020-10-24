#include "CharacterObject.h"

string CharacterObject::getObjectName(characterObjectKind objectType)
{
	switch (objectType) {
	case Glass:
		return "a peice of glass";
	case Phone:
		return "a phone"; //imposter's phone is at the apple store //innocent just got their pre-ordered  iPhone 12
	case Knife:
		return "a chefs knife"; //imposter used to kill //innocent is a chef
	case Pillow:
		return "a pillow, with a very cute striped case"; //imposter used to kill //innocent is very sleepy
	case Pills:
		return "some prescription medication, from Chemist Warehouse. We beat everyone's prices."; //imposter used to kill //innocent works for Chemist Warehouse
	case Bottle:
		return "a little bottle of scotch"; //imposter does not drink //innocent is alcoholic
	case HairBrush:
		return "a lovely hair brush"; //imposter is blad //innocent has lovely hair
	default:
		return "nothing at all";
	}
}

