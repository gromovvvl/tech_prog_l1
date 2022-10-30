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
		
	}

	fclose(fp);
}


void Keeper::load()
{
	char file[250];
	printf("enter file name: ");
	scanf("%s", &file);

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
	Heroes* add = nullptr;
	for (int i = 0; i < size; i++)
	{
		if (fscanf(fp, "%c\n", &ch) != 1)
			throw (char*)"exeption: data error, type not stated";
		switch (ch)
		{
			case 'H':
			{
				int len = 0;
				if (fscanf(fp, "%d \n", &len)!=1)
					throw (char*)"exeption: string len not stated";
				char *n = new char[len+1]; fgets(n, len+1, fp); trim(n);

				if (fscanf(fp, "%d \n", &len) != 1)
					throw (char*)"exeption: string len not stated";
				char* w = new char[len + 1]; fgets(w, len + 1, fp); trim(w);
				
				int s = 0;
				if (fscanf(fp, "%d \n", &s) != 1)
					throw (char*)"exeption: skill number not stated";
				char** sklls = new char* [s];

				for (int i = 0; i < s; i++)
				{
					if (fscanf(fp, "%d \n", &len) != 1)
						throw (char*)"exeption: string len not stated"; 
					char* l = new char[len + 1]; fgets(l, len + 1, fp); trim(l);
					sklls[i] = new char[strlen(l) + 1];
					strcpy(sklls[i], l);
				}
				if (s == 0)
					sklls = nullptr;
				 add = new Hero(n, w, s, sklls);
			}
				break;

			case 'V':
			{
				int len = 0;
				if (fscanf(fp, "%d \n", &len) != 1)
					throw (char*)"exeption: string len not stated"; 
				char* n = new char[len + 1]; fgets(n, len + 1, fp);  trim(n);
				
				if (fscanf(fp, "%d \n", &len) != 1)
					throw (char*)"exeption: string len not stated";
				char* w = new char[len + 1]; fgets(w, len + 1, fp); trim(w);
				
				if (fscanf(fp, "%d \n", &len) != 1)
					throw (char*)"exeption: string len not stated"; 
				char* p = new char[len + 1]; fgets(p, len + 1, fp);  trim(p);
				
				if (fscanf(fp, "%d \n", &len) != 1)
					throw (char*)"exeption: string len not stated";
				char* d = new char[len + 1]; fgets(d, len + 1, fp);  trim(d);

				int s = 0;
				if (fscanf(fp, "%d \n", &s) != 1)
					throw (char*)"exeption: skill number not stated";
				char** sklls = new char* [s];
				for (int i = 0; i < s; i++)
				{
					if (fscanf(fp, "%d \n", &len) != 1)
						throw (char*)"exeption: string len not stated"; 
					char* l = new char[len + 1]; fgets(l, len + 1, fp); trim(l);
					sklls[i] = new char[strlen(l) + 1];
					strcpy(sklls[i], l);
				}
				if (s == 0)
					sklls = nullptr;
				add = new Villain(n, w, d, p, s, sklls);
			}
				break;

			case 'M':
			{
				int len = 0;
				if (fscanf(fp, "%d \n", &len) != 1)
					throw (char*)"exeption: string len not stated"; 
				char* n = new char[len + 1]; fgets(n, len + 1, fp); trim(n);
				
				if (fscanf(fp, "%d \n", &len) != 1)
					throw (char*)"exeption: string len not stated"; 
				char* d = new char[len + 1]; fgets(d, len + 1, fp); trim(d);

				 add = new Monster(n, d);
			}
				break;

			default:
				throw (char*)"exeption: data error, wrong type";
		}
		(*this) + add;

	}

	fclose(fp);

}


int Keeper::get_num()
{
	return num;
}