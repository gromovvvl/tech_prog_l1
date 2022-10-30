#pragma once
#include "heroes.h"

class Hero : public Heroes
{
private:
	char* weapon;
	
	int size; // of skill array
	char** skills;
	void add_skill();
	void edit_skill();
	void delete_skill();

public:

	Hero()
	{
		printf("Hero()\n");
		set_name((char*)"unknown");
		set_size(0);
		skills = nullptr;
		set_weapon((char*)"unknown");
	}

	Hero(char* n, char* w, int s, char** a): weapon(w), size(s), skills(a)
	{
		printf("Hero() w/params\n");
		set_name(n);
	}

	~Hero()
	{
		printf("~Hero()\n");
	}


	void set_weapon(char* w);
	char* get_weapon();

	void set_size(int s);
	int get_size();

	char* get_skill(int id);
	void set_skill(int id, char* s);

	void see() override;
	void edit() override;
};