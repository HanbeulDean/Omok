#ifndef OMOK_SIGONG_H
#define OMOK_SIGONG_H

void drawmap(char map[13][13]);												//바둑판 갱신용
int distinction(char map[13][13], int x, int y);								//규칙 확인을 위한 함수
void ruleManager(char map[13][13], int result);							//distinction()함수로부터 값을 받아 돌의 수를 구분하는 함수
void roundend(int winner);															//라운드 승자를 확인하는 함수
int showmenu();																			//메뉴 출력용 함수  출력값 1 = 게임 실행 2 = 종료 3 = 재출력
void refreshing(char map[13][13]);												//맵 초기화 함수
void putting(char map[13][13]);													//바둑알 놓는 기능을 관리하는 함수 + 턴 넘기는 기능
void gotoxy(int x, int y);
void switchlang();																			//언어 변경을 위한 함수
void restoringPosition(char map[13][13], int orderNum);			//마지막 수를 되돌립니다.
void changeColor(char map[13][13], int x, int y, int i, int q);		//승리시 생기는 이벤트 - 승리하는 해당돌의 색이 바뀐다.

#endif OMOK_SIGONG_H
