#include "heroes.h"

class Hero : public Heroes
{
private:
	char* weapon;
	char* deed;
	
	int size; // of skill array
	char** skills;
public:

	Hero()
	{

	}
	Hero(char* n, char* w, char* d, int s, char** a): weapon(w), deed(d), size(s), skills(a)
	{
		setName(n);
	}
	~Hero()
	{

	}

};