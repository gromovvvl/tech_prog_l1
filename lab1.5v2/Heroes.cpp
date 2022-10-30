#define _CRT_SECURE_NO_WARNINGS

#include "Heroes.h"
void Heroes::set_name(char* s)
{
	delete name;
	name = new char[strlen(s) + 1];
	strcpy(name, s);
}

char* Heroes::get_name()
{
	return name;
}


void Heroes::edit_name()
{
	char new_name[200];
	printf("enter new name: ");
	gets_s(new_name);
	set_name(new_name);
}