#ifndef OMOK_SIGONG_H
#define OMOK_SIGONG_H

void drawmap(char map[13][13]);												//�ٵ��� ���ſ�
int distinction(char map[13][13], int x, int y);								//��Ģ Ȯ���� ���� �Լ�
void ruleManager(char map[13][13], int result);							//distinction()�Լ��κ��� ���� �޾� ���� ���� �����ϴ� �Լ�
void roundend(int winner);															//���� ���ڸ� Ȯ���ϴ� �Լ�
int showmenu();																			//�޴� ��¿� �Լ�  ��°� 1 = ���� ���� 2 = ���� 3 = �����
void refreshing(char map[13][13]);												//�� �ʱ�ȭ �Լ�
void putting(char map[13][13]);													//�ٵϾ� ���� ����� �����ϴ� �Լ� + �� �ѱ�� ���
void gotoxy(int x, int y);
void switchlang();																			//��� ������ ���� �Լ�
void restoringPosition(char map[13][13], int orderNum);			//������ ���� �ǵ����ϴ�.
void changeColor(char map[13][13], int x, int y, int i, int q);		//�¸��� ����� �̺�Ʈ - �¸��ϴ� �ش絹�� ���� �ٲ��.

#endif OMOK_SIGONG_H
