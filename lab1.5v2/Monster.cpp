#define _CRT_SECURE_NO_WARNINGS
#include "Monster.h"
#include "input.h"

void Monster::see()
{
	printf("Monster: %s, description: %s\n", get_name(), get_description());
	
}
void Monster::save(FILE* f)
{
	fprintf(f, "M\n");
	fprintf(f, "%d %s\n", strlen(get_name()), get_name());
	fprintf(f, "%d %s\n", strlen(get_description()), get_description());
}

void Monster::edit()
{
	see();
	printf("-1 back\n1 edit name\n2edit description\n");
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
		char new_desc[1000];
		printf("enter new description: ");
		gets_s(new_desc);
		set_description(new_desc);
		}

		default:
			printf("unknown command\n");
		}
	}
	
}

void Monster::set_description(char* w)
{
	delete description;
	description = new char[strlen(w) + 1];
	strcpy(description, w);
}


char* Monster::get_description()
{
	return description;
}
