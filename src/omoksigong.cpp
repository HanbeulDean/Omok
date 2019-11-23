#include "omoksigong.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

bool turn = true;													//�� Ȯ���� ���� ���� ture = �� / false = ��
int posx = 12, posy = 6;										//��ǥ�� ������ ���� ��������
bool resetbtn = false;											//���� ��ȯ�� Ŀ�� ��ǥ �ʱ�ȭ�� ���� ���� ����  true = ��ȯ��   false = ���� ������
bool lang = true;													//��� ������ ���� ���� ���� true = Eng, false = Kor
short poslist[20][3];												//�� ��Ͽ� �迭
int posnum;															//poslist[][]�� ù��° ���ڸ� ���� ����

using namespace std;

void drawmap(char map[13][13]) {

	system("cls");
	//Dark yellow BG, Black Font
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);

	//i�� ����, q�� ����

	for (int i = 0; i < 15; i++) {
		if (i < 13) {
			for (int q = 0; q < 13; q++) {
				if (map[i][q] == 'X') {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
					cout << "��";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
				}
				else if (map[i][q] == 'O')
					cout << "��";
				else
					cout << map[i][q] << (char)6;
			}
			if (i < 9)
				cout << (char)6 << i + 1 << "  " << endl;
			else
				cout << (char)6 << i + 1 << " " << endl;
		}
		else if (i == 13) {
			for (int a = 0; a < 13; a++) {
				cout << (char)5 << " ";
			}
			cout << "    " << endl;
		}
		else {
			for (int a = 0; a < 13; a++) {
				cout << (char)(a + 97) << " ";
			}
			cout << "    ";
		}
	}
	//Back to Basic color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	gotoxy(32, 0);
	if (turn) {
		if(lang)
			cout << (posnum + 1) << " turn : " << " / ��";
		else
			cout << (posnum + 1) << " �� : " << " / ��";
	}
	else {
		if (lang)
			cout << (posnum + 1) << " turn : " << " / ��";
		else
			cout << (posnum + 1) << " �� : " << " / ��";

	}
}

int showmenu() {

	int choice;

	for (int i = 0; i < 30; i++)
	{
		cout << (char)6 << " ";
	}

	if (lang) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << endl << "		     Welcome to O-Mok!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "		     Chose number." << endl;
		cout << "		     1. Game start" << endl << "		     2.Change lang to Kor" << endl << "		     3.Exit" << endl;
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << endl << "		          ����" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "		     ��ȣ�� ������ �ֽÿ�." << endl;
		cout << "		     1. ���� ����" << endl << "		     2.����(����)" << endl << "		     3.����" << endl;
	}

	for (int i = 0; i < 30; i++)
	{
		cout << (char)6 << " ";
	}

	if (lang) {
		cout << endl << "Input number : ";
	}
	else {
		cout << endl << "��ȣ �Է� : ";
	}
	cin >> choice;

	return choice;
}

void switchlang() {
	lang = !lang;
}

void refreshing(char map[13][13]) {
	for (int i = 0; i < 13; i++)
	{
		if (i == 0)
			map[i][0] = (char)1;
		else if (i == 12)
			map[i][0] = (char)3;
		else
			map[i][0] = (char)25;

		for (int q = 1; q < 12; q++)
		{
			if (i == 0)
				map[i][q] = (char)22;
			else if (i == 12)
				map[i][q] = (char)21;
			else
				map[i][q] = (char)16;
		}

		if (i == 0)
			map[i][12] = (char)2;
		else if (i == 12)
			map[i][12] = (char)4;
		else
			map[i][12] = (char)23;
	}

	for (int i = 0; i < 3; i++) {
		for (int q = 0; q < 20; q++) {
			poslist[q][i] = (-1);
		}
	}

	posnum = 0;

}

void putting(char map[13][13]) {

	int x, y;
	int input;
	int result;

	gotoxy(posx, posy);
	x = posx;
	y = posy;

	while (true) {
		input = _getch();
		if (input == 75)
			x -= 2;
		else if (input == 77)
			x += 2;
		else if (input == 72)
			y--;
		else if (input == 80)
			y++;
		else if (input == 13) {
			if (map[y][(x / 2)] != 'X' && map[y][(x / 2)] != 'O') {



				poslist[posnum][0] = x / 2;
				poslist[posnum][1] = y;
				poslist[posnum][2] = (char)map[y][x / 2];
				posnum++;

				if (turn) {
					map[y][x / 2] = 'X';
					drawmap(map);
					turn = false;
				}
				else {
					map[y][x / 2] = 'O';
					drawmap(map);
					turn = true;
				}

				result = distinction(map, (x / 2), y);
				ruleManager(map, result);
				break;
			}
			else {
				gotoxy(0, 16);
				if (lang) 
					cout << "You can't put stones down on this point. Other stone is already there!";
				else 
					cout << "�̹� �ٸ� �����Ǿ� �ֽ��ϴ�. �ٸ� ���� �����ϼ���. �·�!";
			}
		}

		//��ǥ �Ѱ�ġ ����� ���� ó��
		if (x < 0)
			x = 24;
		else if (x > 24)
			x = 0;
		else if (y < 0)
			y = 12;
		else if (y > 12)
			y = 0;

		//��ǥ �̵�
		gotoxy(x, y);
	}

	//���� ���� �� ���� Ȯ�� �� ��ǥ ���� �Ǵ� �ʱ�ȭ 
	if (resetbtn) {
		resetbtn = false;
		posx = 12;
		posy = 6;
	}
	else {
		posx = x;
		posy = y;
	}
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int distinction(char map[13][13], int x, int y) {

	int x2, y2;
	int countA;
	int countB = 0;
	char enemyColor;
	bool blockedLine;

	int result = 0;													//0 = �ƹ��͵� ����. / 1 = ���� �¸� / 2 = ����  �¸� / 3 = 3.3��Ȳ / 4 = 3.4��Ȳ / 5 = 4.4��Ȳ

	if (map[y][x] == 'O')
		enemyColor = 'X';
	else if(map[y][x] == 'X')
		enemyColor = 'O';

	bool refresh = false;

	for (int i = -1; i < 2; i++) {
		for (int q = -1; q < 1; q++) {
			blockedLine = false;

			if (q == 0 && (i == 0 || i == 1)) 
				break;

			countA = 1;
			x2 = x + i;
			y2 = y + q;

			//������ Ž��

			while (map[y][x] == map[y2][x2]) {
				countA++;
				x2 += i;
				y2 += q;
			}

			//���⼭ �������� ��뵹���� Ȯ���Ѵ�.
			if (map[y2][x2] == enemyColor)
				blockedLine = true;

			/*
			while (true) {
				if (map[y][x] == map[y2][x2]) {
					count++;
					x2 += i;
					y2 += q;


					gotoxy(0, 15);
					cout << "������ �˻���. ī��Ʈ ���� : " << count << "                        " << endl;
					system("pause");
					gotoxy(x, y);


				}
				else
				break;
			}
			*/

			//������ȯ
			x2 = x - i;
			y2 = y - q;

			//������ Ž��

			while (map[y][x] == map[y2][x2]) {
				countA++;
				x2 -= i;
				y2 -= q;
			}

			//ī��Ʈ ������ ���� 3�̳� 4�� ��� ��뵹�� ������ �ִ��� Ȯ���ϰų� ���� �˻縦 �ҷ��� or�� ó����
			//��뵹�� �ִ� ���� �Ѿ�� ��뵹�� ���� ��� ī��Ʈ2 ������ ī��Ʈ ���� ���� ġȯ�Ѵ�.

			if (countA == 3 || countA == 4) {

				if (blockedLine || map[y2][x2] == enemyColor) {
					countA = 0;
				}
				else if(countB == 0){
					countB = countA;
					countA = 0;
				}
			}

			/*
			while (true) {
				if (map[y][x] == map[y2][x2]) {
					count++;
					x2 -= i;
					y2 -= q;

					/*
					gotoxy(0, 15);
					cout << "������ �˻���. ī��Ʈ ���� : " << count << "                        " << endl;
					system("pause");
					gotoxy(x, y);

				}
				else
					break;
			}
			*/

			//count�� �� Ȯ��
			if (countA == 5) {
				switch (map[y][x]) {
				case 'O':
					result = 2;
					break;
				case 'X':
					result = 1;
					break;
				}
				changeColor(map, x, y, i, q);
				refresh = true;
				break;
			}


			if (countA == 3) {
				if (countB == 3)
					result = 3;
				else if (countB == 4)
					result = 4;
			}
			else if (countA == 4) {
				if (countB == 3)
					result = 4;
				else if (countB == 4)
					result = 5;
			}
			

			/*switch (countA) {
			case 3:
				switch (countB) {
				case 3:
					gotoxy(0, 18);
					cout << "�ȴ�.";
					Sleep(5000);
					result = 3;
					break;
				case 4:
					result = 4;
					break;
				default:
					break;
				}
			case 4:
				switch (countB) {
				case 3:
					result = 4;
				case 4:
					result = 5;
				default:
					break;
				}
			default:
				break;
			}*/
		}
	}

	if (refresh)
		refreshing(map);

	return result;
}

void ruleManager(char map[13][13], int result) {

	switch (result) {
	case 1:
		roundend(result);
		break;
	case 2:
		roundend(result);
		break;
	case 3:
		restoringPosition(map, 1);
		gotoxy(0, 18);
		if (lang)
			cout << "It is 3-3 situation, out of rule." << endl;
		else
			cout << "3-3�� ��Ģ�Դϴ�." << endl;
		Sleep(2000);
		break;
	case 4:
		restoringPosition(map, 1);
		gotoxy(0, 18);
		if (lang)
			cout << "It is 4-3 situation, out of rule." << endl;
		else
			cout << "4-3�� ��Ģ�Դϴ�." << endl;
		Sleep(2000);
		break;
	case 5:
		break;
	default:
		break;
	}
}

void restoringPosition(char map[13][13], int orderNum) {
	
	int x1 = poslist[posnum-1][0];
	int y1 = poslist[posnum-1][1];
	char text1 = (char)poslist[posnum-1][2];

	int x2 = poslist[posnum-2][0];
	int y2 = poslist[posnum-2][1];
	char text2 = (char)poslist[posnum-2][2];

	//1 = 3.3�� 3.4 ���� ��� �ǵ�����    2 = ������(�� �� ���� ����)
	switch (orderNum) {
	case 1:
		map[y1][x1] = text1;
		posnum--;
		turn = !turn;
		break;
	case 2:
		map[y1][x1] = text1;
		map[y2][x2] = text2;
		posnum--;
		posnum--;
		break;
	default:
		break;
	}
}

void changeColor(char map[13][13], int x, int y, int i, int q) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 98);

	int x2 = x + i;
	int y2 = y + q;

	//������ Ž��

	while (map[y][x] == map[y2][x2]) {
		gotoxy(x2*2, y2);
		cout << "��";
		x2 += i;
		y2 += q;
	}

	//������ȯ
	x2 = x - i;
	y2 = y - q;

	//������ Ž��

	while (map[y][x] == map[y2][x2]) {
		gotoxy(x2 * 2, y2);
		cout << "��";
		x2 -= i;
		y2 -= q;
	}

	gotoxy(x*2, y);
	cout << "��";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void roundend(int winner) {
	if (winner == 1) {
		gotoxy(0, 17);
		if (lang) {
			cout << "Congratulation! White team win! You are enough to get qualification for playing SiGong!!!" << endl;
			cout << "New heroes are always welcome!" << endl;
		}
		else {
			cout << "��ȣ! �鵹�� �̰���ϴ�! ����� �ð��� ��ǳ�� �� ����� �ڰ��� ���߼̾��!!!" << endl;
			cout << "���ο� ������ ������ ȯ���̾�!" << endl;

		}
		Sleep(5000);
	}
	else {
		gotoxy(0, 17);
		if (lang) {
			cout << "Congratulation! Black team win! You are enough to get qualification for playing SiGong!!!" << endl;
			cout << "New heroes are always welcome!" << endl;
		}
		else {
			cout << "��ȣ! �浹�� �̰���ϴ�! ����� �ð��� ��ǳ�� �� ����� �ڰ��� ���߼̾��!!!" << endl;
			cout << "���ο� ������ ������ ȯ���̾�!" << endl;

		}
		Sleep(5000);
	}
	system("start chrome https://heroesofthestorm.com/ko-kr/");
	resetbtn = true;
}