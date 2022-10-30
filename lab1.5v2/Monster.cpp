#define _CRT_SECURE_NO_WARNINGS
#include "Monster.h"


void Monster::see()
{
	printf("Monster: %s, description: %s\n", get_name(), get_description());
	
}


void Monster::set_description(char* w)
{
	delete description;
	description = new char[strlen(w)];
	strcpy(description, w);
}


char* Monster::get_description()
{
	return description;
}
