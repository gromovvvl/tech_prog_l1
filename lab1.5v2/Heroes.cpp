#define _CRT_SECURE_NO_WARNINGS

#include "Heroes.h"
void Heroes::set_name(char* s)
{
	delete name;
	name = new char[strlen(s)];
	strcpy(name, s);
}

char* Heroes::get_name()
{
	return name;
}
