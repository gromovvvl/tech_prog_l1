#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"

void Hero::see()
{
	printf("Hero: %s, skills:\n", get_name());
	for (int i = 0; i < get_size(); i++)
	{
		printf(" - %s\n", get_skill(i));
	}
}



void Hero::set_size(int s)
{
	size = s;
}

int Hero::get_size()
{
	return size;
}

void Hero::set_weapon(char* w)
{
	delete weapon;
	weapon = new char[strlen(w)];
	strcpy(weapon, w);
}


char* Hero::get_weapon()
{
	return weapon;
}

void Hero::set_skill(int id, char* s)
{
	delete skills[id];
	skills[id] = new char[strlen(s)];
	strcpy(skills[id], s);
}


char* Hero::get_skill(int id)
{
	return skills[id];
}