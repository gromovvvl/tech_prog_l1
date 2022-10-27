#include "stdio.h"
#include "string.h"

class Heroes
{
	char* name;

public:
	Heroes() 
	{ 
		printf("Heroes()\n");
		strcpy(name, "unknown"); 
	};
	Heroes(char* s): name(s)
	{
		printf("Heroes w/params\n");
	};

	~Heroes()
	{
		printf("~Heroes()\n");
	}

	virtual void print() {};

	void setName(char* s)
	{
		strcpy(name, s);
	}

};