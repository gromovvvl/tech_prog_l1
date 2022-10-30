#include "Keeper.h"
#include "Hero.h"
#include "Villain.h"
#include "Monster.h"
#include "input.h"

void Keeper::see()
{
	printf("\tALL ITEMS\n");
	for (int i = 0; i < num; i++)
		arr[i]->see();

}


void Keeper::operator+(Heroes*x)
{
	num += 1;
	Heroes** new_arr = new Heroes * [num];
	for (int i = 0; i < num - 1; i++)
		new_arr[i] = arr[i];
	
	new_arr[num - 1] = x;
	arr = new_arr;
}

void Keeper::add()
{

	int t = 0;
	printf("1 add hero\n2 add villain\n3 add monster\n");
	while (t <= 0 || t > 3)
		scanInt(&t);

	switch (t)
	{
	case 1:
	{
		Heroes* add = new Hero;
		(*this) + add;
	}
		break;
	
	case 2:
	{
		Heroes* add = new Villain;
		(*this) + add;
	}
		break;
	
	case 3:
	{
		Heroes* add = new Monster;
		(*this) + add;
	}
		break;

	}

}


void Keeper::edit()
{
	int t = -1;
	printf("enter number of item to edit, from 0 to %d\n", num-1);
	while (t < 0 || t >= num)
		scanInt(&t);
	
	arr[t]->edit();

	printf("edited\n");
}

void Keeper::operator-(int t)
{
	delete arr[t];
	for (int h = t; h < num - 1; h++)
	{
		arr[h] = arr[h + 1];
	}
}

void Keeper::del()
{
	int t = -1;
	printf("enter number of item to delete, from 0 to %d\n", num);
	while (t < 0 || t >= num)
		scanInt(&t);
	(*this) - t;
	
	printf("deleted\n");
	num--;
}


void Keeper::save()
{

}


void Keeper::load()
{

}


int Keeper::get_num()
{
	return num;
}