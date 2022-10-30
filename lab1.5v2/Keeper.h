#include "stdio.h"
#include "Heroes.h"

class Keeper
{
private:
	int num;
	Heroes** arr;

	void operator-(int t);
	void operator+(Heroes* x);

public:

	Keeper()
	{
		printf("Keeper()\n");
		num = 0;
		arr = nullptr;
	}
	
	Keeper(int n, Heroes** ptr) : num(n), arr(ptr) { printf("Keeper w/params\n"); };

	~Keeper()
	{
		printf("~Keeper()\n");
		for (int i = 0; i < num; i++)
			delete arr[i];
		num = 0;
	}

	void add();
	void see();
	void edit();
	void del();
	void save();
	void load();

	int get_num();
};