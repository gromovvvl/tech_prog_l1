#pragma once
#include "heroes.h"

class Villain : public Heroes
{
private:
	char* weapon;
	char* deed;
	char* place;

	int size; // of skill array
	char** skills;
	void add_skill();
	void edit_skill();
	void delete_skill();

public:

	Villain()
	{
		printf("Villain()\n");
		set_name((char*)"unknown");
		set_size(0);
		skills = nullptr;
		set_weapon((char*)"unknown");
		set_deed((char*)"unknown");
		set_place((char*)"unknown");
	}

	Villain(char* n, char* w, char* d, char* pl, int s, char** a) : weapon(w), deed(d), place(pl), size(s), skills(a)
	{
		printf("Villain() w/params\n");
		set_name(n);
	}

	~Villain()
	{
		printf("~Villain()\n");
	}

	void set_weapon(char* w);
	char* get_weapon();

	void set_place(char* p);
	char* get_place();

	void set_deed(char* d);
	char* get_deed();

	void set_size(int s);
	int get_size();

	char* get_skill(int id);
	void set_skill(int id, char* s);

	void see() override;
	void edit() override;
	
	

};