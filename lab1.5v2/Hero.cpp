#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include "input.h"

void Hero::see()
{
	printf("Hero: %s, skills:\n", get_name());
	for (int i = 0; i < get_size(); i++)
	{
		printf(" - %s\n", get_skill(i));
	}
}

void Hero::save(FILE* f)
{
	fprintf(f, "H\n");
	fprintf(f, "%s\n", get_name());
	fprintf(f, "%s\n", get_weapon());
	fprintf(f, "%d\n", get_size());
	for (int i = 0; i < get_size(); i++)
	{
		fprintf(f, "%s\n", get_skill(i));
	}
}

void Hero::add_skill()
{
	char new_skill[1000];
	printf("enter new skill: ");
	gets_s(new_skill);

	set_size(get_size() + 1);
	char** new_skills = new char* [get_size()];
	for (int i = 0; i < get_size()-1; i++)
	{
		new_skills[i] = new char[strlen(get_skill(i)) + 1];
		strcpy(new_skills[i], get_skill(i));
	}

	new_skills[get_size()-1] = new char[strlen(new_skill)+1];
	strcpy(new_skills[get_size()-1], new_skill);
	skills = new_skills;
}

void Hero::edit_skill()
{
	if (get_size() == 0)
	{
		printf("skill list is empty\n");
		return;
	}
	int t = -1;
	printf("enter index of item from 0 to %d to edit", get_size() - 1);

	while (t < 0 || t >= get_size())
		scanInt(&t);

	char new_skill[1000];
	printf("enter new skill value: ");
	gets_s(new_skill);

	set_skill(t, new_skill);
}


void Hero::delete_skill()
{
	if (get_size() == 0)
	{
		printf("skill list is empty\n");
		return;
	}
	int t = -1;
	printf("enter index of item from 0 to %d to delete", get_size() - 1);

	while (t < 0 || t >= get_size())
		scanInt(&t);

	delete skills[t];
	set_size(get_size() - 1);
	for (int i = t; i < get_size(); i++)
		strcpy(skills[i], get_skill(i + 1));
}

void Hero::edit()
{
	see();
	printf("-1 back\n1 edit name\n20 add new skill\n21 delete skill\n22 edit skill\n");
	while (true)
	{
		int t = 0;
		scanInt(&t);
		switch (t)
		{
		case -1:
			return;
		case 1:
			edit_name();
			break;

		case 20:
			add_skill();
			break;
		case 21:
			delete_skill();
			break;
		case 22:
			edit_skill();
			break;

		default:
			printf("unknown command\n");
		}
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
	weapon = new char[strlen(w)+1];
	strcpy(weapon, w);
}


char* Hero::get_weapon()
{
	return weapon;
}

void Hero::set_skill(int id, char* s)
{
	delete skills[id];
	skills[id] = new char[strlen(s) + 1];
	strcpy(skills[id], s);
}


char* Hero::get_skill(int id)
{
	return skills[id];
}