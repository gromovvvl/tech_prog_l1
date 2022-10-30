#define _CRT_SECURE_NO_WARNINGS

#include "Villain.h"

void Villain::see()
{
	printf("Villain: %s, deed: %s, place: %s, skills:\n", get_name(), get_deed(), get_place());
	for (int i = 0; i < get_size(); i++)
	{
		printf(" - %s\n", get_skill(i));
	}
}



void Villain::set_size(int s)
{
	size = s;
}

int Villain::get_size()
{
	return size;
}

void Villain::set_weapon(char* w)
{
	delete weapon;
	weapon = new char[strlen(w)];
	strcpy(weapon, w);
}


char* Villain::get_weapon()
{
	return weapon;
}

void Villain::set_place(char* p)
{
	delete place;
	place = new char[strlen(p)];
	strcpy(place, p);
}


char* Villain::get_place()
{
	return place;
}

void Villain::set_deed(char* d)
{
	delete deed;
	deed = new char[strlen(d)];
	strcpy(deed, d);
}


char* Villain::get_deed()
{
	return deed;
}



void Villain::set_skill(int id, char* s)
{
	delete skills[id];
	skills[id] = new char[strlen(s)];
	strcpy(skills[id], s);
}


char* Villain::get_skill(int id)
{
	return skills[id];
}