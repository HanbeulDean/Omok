#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "omoksigong.h"

using namespace std;

int main()
{
	system("mode con cols=60 lines=23");
	char map[13][13];

	refreshing(map);

	while (true) {
		int selection = showmenu();
	
		if (selection == 1) {
			drawmap(map);
			break;
		}
		else if (selection == 2) {
			system("cls");
			switchlang();
			//selection = showmenu();
		}
		else if (selection == 3) {
			system("cls");
			return 0;
		}
		else {
			system("cls");
			cout << "Something is going wrong!!! Please recheck your selection..." << endl;
			Sleep(5000);
			system("cls");
			//selection = showmenu();
		}
	}

	while (true) {
		putting(map);
		drawmap(map);
	}

	return 0;
}
