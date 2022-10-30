#include "input.h"
#include "Keeper.h"

void commands()
{
	printf("MENU\n");
	printf("0 exit\n");
	printf("1 print all to screen\n");
	printf("2 add\n");
	printf("3 delete\n");
	printf("4 edit\n");
	printf("11 load\n");
	printf("12 save\n");
}

void menu()
{
	Keeper cont;
	int t;
	commands();

	while (true)
	{
		printf("MAIN MENU\n");
		scanInt(&t);
		switch (t)
		{
		case 0:
			return;

		case 1:
			cont.see();
			break;

		case 2:
			cont.add();
			break;

		case 3:
			if (cont.get_num() == 0)
				printf("keeper is empty\n");
			else
				cont.del();
			break;

		case 4:
			if (cont.get_num() == 0)
				printf("keeper is empty\n");
			else
				cont.edit();
			break;

		case 11:
			cont.load();
			break;

		case 12:
			if (cont.get_num() == 0)
				printf("keeper is empty\n");
			else
				cont.save();
			break;


		default:
			printf("unknown command\n"); commands();

		}
	}

}


int main()
{
	menu();
	return 0;
}