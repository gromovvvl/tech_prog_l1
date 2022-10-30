#define _CRT_SECURE_NO_WARNINGS

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
	printf("enter number of item to delete, from 0 to %d\n", num-1);
	while (t < 0 || t >= num)
		scanInt(&t);
	(*this) - t;
	
	printf("deleted\n");
	num--;
}


void Keeper::save()
{
	char file[250];
	printf("enter file name: ");
	scanf("%s", &file);

	printf("file %s\n", file);

	FILE* fp = fopen(file, "w");
	if (fp == NULL)
	{
		printf("error opening file\n");
		return;
	}

	fprintf(fp, "%d\n", get_num());
	for (int i = 0; i < get_num(); i++)
	{
		arr[i]->save(fp);
		fprintf(fp, "%d\n", i);
	}

	fclose(fp);
}


void Keeper::load()
{
	char file[250];
	printf("enter file name: ");
	scanf("%s", &file);

	printf("file %s\n", file);

	FILE* fp = fopen(file, "r");
	if (fp == NULL)
	{
		printf("error opening file\n");
		return;
	}
	int size = 0;
	if (fscanf(fp, "%d\n", &size)!= 1)
		throw (char*)"exeption: size not stated";

	if (size <= 0)
		throw (char*)"exeption: size <= 0";

	char ch;

	for (int i = 0; i < size; i++)
	{
		if (fscanf(fp, "%c\n", &ch) != 1)
			throw (char*)"exeption: data error, type not stated";
		switch (ch)
		{
			case 'H':
			{
				char n[1000]; fgets(n, 1000, fp); trim(n);
				char w[1000]; fgets(w, 1000, fp); trim(w);
				int s = 0;
				fscanf(fp, "%d\n", s);
				char** sklls = new char* [s];
				for (int i = 0; i < s; i++)
				{
					char l[1000]; fgets(l, 1000, fp); trim(l);
					sklls[i] = new char[strlen(l) + 1];
					strcpy(sklls[i], l);
				}
				Heroes* add = new Hero(n, w, s, sklls);
				(*this) + add;
			}
				break;

			case 'V':
			{

				char n[1000]; fgets(n, 1000, fp); trim(n);
				char w[1000]; fgets(w, 1000, fp); trim(w);
				char d[1000]; fgets(d, 1000, fp); trim(d);
				char p[1000]; fgets(p, 1000, fp); trim(p);
				int s = 0;
				fscanf(fp, "%d\n", s);
				char** sklls = new char* [s];
				for (int i = 0; i < s; i++)
				{
					char l[1000]; fgets(l, 1000, fp); trim(l);
					sklls[i] = new char[strlen(l) + 1];
					strcpy(sklls[i], l);
				}
				Heroes* add = new Villain(n, w, d, p, s, sklls);
				(*this) + add;
			}
				break;

			case 'M':
			{
				char n[1000]; fgets(n, 1000, fp); trim(n);
				char d[1000]; fgets(d, 1000, fp); trim(d);

				Heroes* add = new Monster(n, d);
				(*this) + add;
			}
				break;

			default:
				throw (char*)"exeption: data error, wrong type";
		}

		int id;
		fscanf(fp, "%d\n", &id);
		if (id != 1)
			return;

	}

	fclose(fp);

}


int Keeper::get_num()
{
	return num;
}