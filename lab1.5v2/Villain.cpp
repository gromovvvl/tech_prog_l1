#define _CRT_SECURE_NO_WARNINGS

#include "Villain.h"
#include "input.h"

void Villain::see()
{
	printf("Villain: %s, deed: %s, place: %s, skills:\n", get_name(), get_deed(), get_place());
	for (int i = 0; i < get_size(); i++)
	{
		printf(" - %s\n", get_skill(i));
	}
}
void Villain::save(FILE* f)
{
	fprintf(f, "V\n");
	fprintf(f, "%s\n", get_name());
	fprintf(f, "%s\n", get_weapon());
	fprintf(f, "%s\n", get_deed());
	fprintf(f, "%s\n", get_place());
	fprintf(f, "%d\n", get_size());
	for (int i = 0; i < get_size(); i++)
	{
		fprintf(f, "%s\n", get_skill(i));
	}
}

void Villain::add_skill()
{
	char new_skill[1000];
	printf("enter new skill: ");
	gets_s(new_skill);

	set_size(get_size() + 1);
	char** new_skills = new char* [get_size()];
	for (int i = 0; i < get_size() - 1; i++)
	{
		new_skills[i] = new char[strlen(get_skill(i)) + 1];
		strcpy(new_skills[i], get_skill(i));
	}

	new_skills[get_size() - 1] = new char[strlen(new_skill) + 1];
	strcpy(new_skills[get_size() - 1], new_skill);
	skills = new_skills;
}

void Villain::edit_skill()
{
	if (get_size() == 0)
	{
		printf("skill list is empty\n");
		return;
	}
	int t = -1;
	printf("enter index of item from 0 to %d to edit", get_size()-1);

	while (t < 0 || t >= get_size())
		scanInt(&t);

	char new_skill[1000];
	printf("enter new skill value: ");
	gets_s(new_skill);

	set_skill(t, new_skill);
}


void Villain::delete_skill()
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

void Villain::edit()
{
	see();
	printf("-1 back\n1 edit name\n2 edit deed\n3 edit place\n40 add new skill\n41 delete skill\n42 edit skill\n");
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

		case 2:
		{
			char new_deed[1000];
			printf("enter new deed: ");
			gets_s(new_deed);
			set_deed(new_deed);
		}
		break;
		case 3:
		{
			char new_place[1000];
			printf("enter new place: ");
			gets_s(new_place);
			set_place(new_place);
		}
		break;
		case 40:
			add_skill();
			break;

		case 41:
			delete_skill();
			break;

		case 42:
			edit_skill();
			break;

		default:
			printf("unknown command\n");
		}
	}


}

void Villain::set_size(int s)
{
	size = s;
}

int Villain::get_size()
{
	return size;
}

void Villain::set_weapon(char* w)
{
	delete weapon;
	weapon = new char[strlen(w) + 1];
	strcpy(weapon, w);
}


char* Villain::get_weapon()
{
	return weapon;
}

void Villain::set_place(char* p)
{
	delete place;
	place = new char[strlen(p) + 1];
	strcpy(place, p);
}


char* Villain::get_place()
{
	return place;
}

void Villain::set_deed(char* d)
{
	delete deed;
	deed = new char[strlen(d) + 1];
	strcpy(deed, d);
}


char* Villain::get_deed()
{
	return deed;
}



void Villain::set_skill(int id, char* s)
{
	delete skills[id];
	skills[id] = new char[strlen(s) + 1];
	strcpy(skills[id], s);
}


char* Villain::get_skill(int id)
{
	return skills[id];
}