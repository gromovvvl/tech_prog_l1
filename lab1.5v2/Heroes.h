#pragma once
#include "stdio.h"
#include "string.h"

class Heroes
{
	char* name;

public:
	Heroes() 
	{ 
		printf("Heroes()\n");
		set_name((char*)"unknown"); 
	};

	Heroes(char* s): name(s)
	{
		printf("Heroes w/params\n");
	};

	~Heroes()
	{
		printf("~Heroes()\n");
	}

	virtual void see() {};

	void set_name(char* s);

	char* get_name();

};