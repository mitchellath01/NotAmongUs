#include "Character.h"

string Character::getObjectName()
{
	return CharacterObject::getObjectName(object);
}

Character::Character(string newName, characterObjectKind newType, bool innocentStatus)
{
	name = newName;
	object = newType;
	isInnocent = innocentStatus;
}

string Character::getName()
{
	return name;
}

string Character::getAlibi()
{
	switch (object) {
	case Glass:
		if (isInnocent) {
			return "remember when the wine glass broke before, \nI found some extra shards";
		}
		else {
			return "I accidentally cut myself, \nand all this blood is just my own, \nwhat else would it be...";
		}
	case Phone:
		if (isInnocent) {
			return "well my new iPhone came in just then, \nI was snooping arround looking for the best strength 5g";
		}
		else {
			return "I was playing arround with bixby on my new iPhone, \nit's a fun internet thing on this phone I always use";
		}
	case Knife:
		if (isInnocent) {
			return "I was just sharpening it actually, \nyou know there's going to be an amazing meat board tomorrow";
		}
		else {
			return "I saw it down the hall, \nclearly we know it's NOT me right! I dont own any knives!";
		}
	case Pillow:
		if (isInnocent) {
			return "I sleep walk,\nso sometimes I just carry it with me";
		}
		else {
			return "I was looking for an extra pillow for my bed";
		}
	case Pills:
		if (isInnocent) {
			return "I have some issues with my heart,\nand these help a lot";
		}
		else {
			return "I didn't even realise I had them!";
		}
	case Bottle:
		if (isInnocent) {
			return "Please don't tell anyone,\nbut I drink a lot nowadays";
		}
		else {
			return "It's Ramadan, and after the sun sets I am allowed to drink";
		}
	case HairBrush:
		return "It's for those pesky hair emergencies.";
	default:
		return "i am not sure what to tell you...";
	}
};

bool Character::getIsInnocent()
{
	if (isInnocent) {
		return true;
	}
	else {
		return false;
	}
}
void Character::print()
{
	cout << "Character object | " + getName() + "\n";
	if (isInnocent) {
		cout << "Character innocent | TRUE\n";
	}
	else {
		cout << "Character innocent | FALSE\n";
	};
	cout << "Character object | " + getObjectName() + "\n";
	cout << CharacterObject::getObjectName(object) + "\n";
	cout << "Character alibi | " + getAlibi() + "\n";
}
;