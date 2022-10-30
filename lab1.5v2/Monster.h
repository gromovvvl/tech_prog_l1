#pragma once
#include "Heroes.h"


class Monster : public Heroes
{
private:
	char* description;

public:

	Monster()
	{
		printf("Monster()\n");
		set_name((char*)"unknown");	
		set_description((char*)"unknown");
	}

	Monster(char* n, char* d) : description(d)
	{
		printf("Monster() w/params\n");
		set_name(n);
	}

	~Monster()
	{
		printf("~Monster()\n");
	}


	void set_description(char* w);
	char* get_description();

	void see() override;
	void edit() override;
};