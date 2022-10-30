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
public:

	Villain()
	{

	}
	Villain(char* n, char* w, char* d, char* pl, int s, char** a) : weapon(w), deed(d), place(pl), size(s), skills(a)
	{
		set_name(n);
	}
	~Villain()
	{

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
	

};