#define _CRT_SECURE_NO_WARNINGS

#include "input.h"
#include "string.h"

void scanInt(int* _x)
{
	while (true)
	{
		if (scanf("%d", _x) != 1)
			printf("invalid input, try again\n");
		else
		{
			if (getchar());
			return;
		}
		if (getchar());
	}
}

void trim(char* s)
{
	int l = strlen(s);
	if (s[l - 1] == '\n')
		s[l - 1] = '\0';
}