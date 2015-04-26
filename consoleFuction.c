#include "common.h"

// 기능 함수

void gotoxy(int x, int y)   // 입력 커서 위치 조정
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void cursorOn(void)              // 커서 켜기
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void cursorOff(void)
{
	CONSOLE_CURSOR_INFO CurInfo; // 커서 끄기
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void textColor(int color)  // 글자색 변경
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void warningYesOrNo(void)  // Yes 혹은 No를 누르세요 Error 메세지 
{
	textColor(12 * 16);
	gotoxy(0, 28); printf("                 Warning: →(예) 혹은 ←(아니오) 키를 입력하세요           ");
	textColor(16 * 14);
}

void curtainEffect(void)
{
	gotoxy(0, 26); lineClear();
	gotoxy(0, 28); lineClear();
	textColor(15);
	gotoxy(0, 1);  printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 2);  printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 3);  printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 4);  printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 5);  printf(" ■■□□□■■□□□□■■□□□■■□□□□■■■■□□□■□■■■□■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 6);  printf(" ■□■■■□■□■■■■□■■■□■□■■■□■■□■■■■□■■■□■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 7);  printf(" ■■□■■■■□■■■■□■■■□■□■■■□■□■■■■■□■■■□■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 8);  printf(" ■■■□■■■□□□□■□□□□□■□■■□■■□■■■■■□□□□□■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 9);  printf(" ■■■■□■■□■■■■□■■■□■□□□■■■□■■■■■□■■■□■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 10); printf(" ■□■■■□■□■■■■□■■■□■□■■□■■■□■■■■□■■■□■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 11); printf(" ■■□□□■■□□□□■□■■■□■□■■■□■■■□□□■□■■■□■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 12); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 13); printf(" ■■■■■■■■■■■■■■■■");
	textColor(10); printf("< 검 색 중 >"); textColor(15);
	printf("■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 14); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 15); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 16); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 17); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 18); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 19); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 20); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 21); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 22); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 23); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 24); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY);
	gotoxy(0, 25); printf(" ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); Sleep(CURTAIN_DELAY * 7); textColor(7);
	gotoxy(0, 25); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 24); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 23); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 22); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 21); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 20); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 19); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 18); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 17); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 16); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 15); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 14); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(0, 13); lineClear(); Sleep(CURTAIN_DELAY);
	gotoxy(8, 13); printf("└────────────────────────────┘");
	gotoxy(0, 12); lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(8, 12); printf("│                                                        │");
	gotoxy(0, 11); lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(8, 11); printf("│                                                        │");
	gotoxy(0, 10); lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(8, 10); printf("│                                                        │");
	gotoxy(0, 9);  lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(8, 9);  printf("│                                                        │");
	gotoxy(0, 8);  lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(8, 8);  printf("│                                                        │");
	gotoxy(0, 7);  lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(8, 7);  printf("│                                                        │");
	gotoxy(0, 6);  lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(8, 6);  printf("│                                                        │");
	gotoxy(0, 5);  lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(8, 5);  printf("│                                                        │");
	gotoxy(0, 4);  lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(8, 4);  printf("│                                                        │");
	gotoxy(0, 3);  lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(8, 3);  printf("┌────────── < 회원정보 > ───────────┐");
	gotoxy(0, 2);  lineClear(); Sleep(CURTAIN_DELAY - 10);
	gotoxy(0, 1);  lineClear(); Sleep(CURTAIN_DELAY - 10);
}

void lineClear(void)
{
	printf("                                                                           ");
}

void printfAllNodes(Member_t *head) // Linked List를 이용해서 회원정보 출력
{
	Member_t *curNode;
	curNode = head->next;
	while (curNode){
		printf(" %s ", curNode->Name);
		curNode = curNode->next;
	}
	printf("\n");
}

void screenClearUp()
{
	int i;
	cursorOff();
	gotoxy(0, 27);
	for (i = 0; i < 28; i++)
	{
		printf("\n"); Sleep(14);
	}
	gotoxy(0, 0);
	textColor(16 * 14);
	lineClear();
	textColor(7);
	Sleep(14);
	cursorOn();
}

void screenClearDelete()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    // home for the cursor 
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	cursorOff();
	int i, j;
	for (i = 7; i <= csbi.dwSize.X; i += 7)
	{
		coordScreen.Y = i; Sleep(TIME_OF_DELAY);
		for (j = 0; j <= i; j++)
		{
			coordScreen.X = j;
			coordScreen.Y--;
			SetConsoleCursorPosition(hConsole, coordScreen);
			printf(" ");
		}
	}
	for (i = 5; i <= csbi.dwSize.X; i += 5)
	{
		coordScreen.Y = i; Sleep(TIME_OF_DELAY);
		for (j = 0; j <= i; j++)
		{
			coordScreen.X = j;
			coordScreen.Y--;
			SetConsoleCursorPosition(hConsole, coordScreen);
			printf(" ");
		}
	}

	for (i = 3; i <= csbi.dwSize.X; i += 9)
	{
		coordScreen.Y = i; Sleep(TIME_OF_DELAY);
		for (j = 0; j <= i; j++)
		{
			coordScreen.X = j;
			coordScreen.Y--;
			SetConsoleCursorPosition(hConsole, coordScreen);
			printf(" ");
		}
	}

	for (i = 0; i <= csbi.dwSize.X + 28; i++)
	{
		coordScreen.Y = i;
		for (j = 0; j <= i; j++)
		{
			coordScreen.X = j;
			coordScreen.Y--;
			SetConsoleCursorPosition(hConsole, coordScreen);
			printf(" ");
		}
	}
	SetConsoleCursorPosition(hConsole, coordScreen);
	cursorOn();
}

void welcomeUI()
{
	int i, j, x = 23, y = 11;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    // home for the cursor 
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	cursorOff();

	textColor(15);
	PlaySound(TEXT("opening.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
	for (i = 7; i <= csbi.dwSize.X-9; i++)
	{
		Sleep(21);
		coordScreen.Y = i;
		for (j = 0; j <= i; j++)
		{
			coordScreen.X = j;
			coordScreen.Y--;
			SetConsoleCursorPosition(hConsole, coordScreen);
			if (coordScreen.X == 1 + x && coordScreen.Y == 1 + y) printf("┌");
			else if (coordScreen.X == 3 + x && coordScreen.Y == 1 + y)  printf("─");
			else if (coordScreen.X == 5 + x && coordScreen.Y == 1 + y)  printf("─");
			else if (coordScreen.X == 7 + x && coordScreen.Y == 1 + y)  printf("─");
			else if (coordScreen.X == 9 + x && coordScreen.Y == 1 + y)  printf("─");
			else if (coordScreen.X == 11 + x && coordScreen.Y == 1 + y) printf("─");
			else if (coordScreen.X == 13 + x && coordScreen.Y == 1 + y) printf("─");
			else if (coordScreen.X == 15 + x && coordScreen.Y == 1 + y) printf("─");
			else if (coordScreen.X == 17 + x && coordScreen.Y == 1 + y) printf("─");
			else if (coordScreen.X == 19 + x && coordScreen.Y == 1 + y) printf("─");
			else if (coordScreen.X == 21 + x && coordScreen.Y == 1 + y) printf("─");
			else if (coordScreen.X == 23 + x && coordScreen.Y == 1 + y) printf("─");
			else if (coordScreen.X == 25 + x && coordScreen.Y == 1 + y) printf("─");
			else if (coordScreen.X == 27 + x && coordScreen.Y == 1 + y) printf("┐");
			else if (coordScreen.X == 1 + x &&  coordScreen.Y == 2 + y) printf("│");
			else if (coordScreen.X == 27 + x && coordScreen.Y == 2 + y) printf("│");
			else if (coordScreen.X == 1 + x &&  coordScreen.Y == 3 + y) printf("│");
			else if (coordScreen.X == 27 + x && coordScreen.Y == 3 + y) printf("│");
			else if (coordScreen.X == 1 + x &&  coordScreen.Y == 4 + y) printf("└");
			else if (coordScreen.X == 3 + x &&  coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 5 + x &&  coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 7 + x &&  coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 9 + x &&  coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 11 + x && coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 13 + x && coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 15 + x && coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 17 + x && coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 19 + x && coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 21 + x && coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 23 + x && coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 25 + x && coordScreen.Y == 4 + y) printf("─");
			else if (coordScreen.X == 27 + x && coordScreen.Y == 4 + y) printf("┘");
		}
	}

	for (i = 0; i <= csbi.dwSize.X-9; i++)
	{
		Sleep(21);
		coordScreen.Y = i;
		for (j = 0; j <= i; j++)
		{
			coordScreen.X = j;
			coordScreen.Y--;
			SetConsoleCursorPosition(hConsole, coordScreen);
			if (coordScreen.X == 4 + x &&  coordScreen.Y == 2 + y) printf("N");
			else if (coordScreen.X == 5 + x &&  coordScreen.Y == 2 + y) printf("H");
			else if (coordScreen.X == 6 + x &&  coordScreen.Y == 2 + y) printf("N");
			else if (coordScreen.X == 8 + x &&  coordScreen.Y == 2 + y) printf("I");
			else if (coordScreen.X == 9 + x &&  coordScreen.Y == 2 + y) printf("N");
			else if (coordScreen.X == 10 + x && coordScreen.Y == 2 + y) printf("S");
			else if (coordScreen.X == 11 + x && coordScreen.Y == 2 + y) printf("T");
			else if (coordScreen.X == 12 + x && coordScreen.Y == 2 + y) printf("I");
			else if (coordScreen.X == 13 + x && coordScreen.Y == 2 + y) printf("T");
			else if (coordScreen.X == 14 + x && coordScreen.Y == 2 + y) printf("U");
			else if (coordScreen.X == 15 + x && coordScreen.Y == 2 + y) printf("T");
			else if (coordScreen.X == 16 + x && coordScreen.Y == 2 + y) printf("E");
			else if (coordScreen.X == 18 + x && coordScreen.Y == 2 + y) printf("F");
			else if (coordScreen.X == 19 + x && coordScreen.Y == 2 + y) printf("O");
			else if (coordScreen.X == 20 + x && coordScreen.Y == 2 + y) printf("R");
			else if (coordScreen.X == 22 + x && coordScreen.Y == 2 + y) printf("T");
			else if (coordScreen.X == 23 + x && coordScreen.Y == 2 + y) printf("H");
			else if (coordScreen.X == 24 + x && coordScreen.Y == 2 + y) printf("E");
			else if (coordScreen.X == 4 + x &&  coordScreen.Y == 3 + y) {
				textColor(8); printf("N"); textColor(15);
			}
			else if (coordScreen.X == 5 + x &&  coordScreen.Y == 3 + y){
				textColor(8); printf("E"); textColor(15);
			}
			else if (coordScreen.X == 6 + x &&  coordScreen.Y == 3 + y) {
				textColor(8); printf("X"); textColor(15);
			}
			else if (coordScreen.X == 7 + x &&  coordScreen.Y == 3 + y) {
				textColor(8); printf("T"); textColor(15);
			}
			else if (coordScreen.X == 9 + x &&  coordScreen.Y == 3 + y) printf("N");
			else if (coordScreen.X == 10 + x && coordScreen.Y == 3 + y) printf("E");
			else if (coordScreen.X == 11 + x && coordScreen.Y == 3 + y) printf("T");
			else if (coordScreen.X == 12 + x && coordScreen.Y == 3 + y) printf("W");
			else if (coordScreen.X == 13 + x && coordScreen.Y == 3 + y) printf("O");
			else if (coordScreen.X == 14 + x && coordScreen.Y == 3 + y) printf("R");
			else if (coordScreen.X == 15 + x && coordScreen.Y == 3 + y) printf("K");
		}
	}

	SetConsoleCursorPosition(hConsole, coordScreen);
	Sleep(700);
	textColor(15); Sleep(TIME_OF_DELAY*3);
	gotoxy(24, 12);   printf("┌────────────┐");
	gotoxy(24, 13); printf("│ NHN INSTITUTE FOR THE  │");
	gotoxy(24, 14); printf("│ NEXT NETWORK           │");
	gotoxy(24, 15); printf("└────────────┘");
	textColor(7); Sleep(TIME_OF_DELAY*3);
	gotoxy(24, 12);   printf("┌────────────┐");
	gotoxy(24, 13); printf("│ NHN INSTITUTE FOR THE  │");
	gotoxy(24, 14); printf("│ NEXT NETWORK           │");
	gotoxy(24, 15); printf("└────────────┘");
	textColor(8); Sleep(TIME_OF_DELAY*3);
	gotoxy(24, 12);   printf("┌────────────┐");
	gotoxy(24, 13); printf("│ NHN INSTITUTE FOR THE  │");
	gotoxy(24, 14); printf("│ NEXT NETWORK           │");
	gotoxy(24, 15); printf("└────────────┘");
	textColor(0); Sleep(TIME_OF_DELAY*3);
	gotoxy(24, 12);   printf("┌────────────┐");
	gotoxy(24, 13); printf("│ NHN INSTITUTE FOR THE  │");
	gotoxy(24, 14); printf("│ NEXT NETWORK           │");
	gotoxy(24, 15); printf("└────────────┘");
	Sleep(TIME_OF_DELAY);
	Sleep(100);
	system("cls");
	textColor(7);
	gotoxy(0, 6);
	printf("                      ┌─── < 주요기능 > ───┐\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      │                          │\n");
	printf("                      └─────────────┘\n");
	textColor(15);
	gotoxy(30, 8);  printf("①  회원 보기");
	gotoxy(30, 10); printf("②  회원 등록");
	gotoxy(30, 12); printf("③  회원 삭제");
	gotoxy(30, 14); printf("④  회원 수정");
	gotoxy(30, 16); printf("⑤  회원 검색");
	gotoxy(30, 18); printf("⑥  파일 저장");
	gotoxy(30, 20); printf("⑦  종 료");
	Sleep(TIME_OF_DELAY);
	
	PlaySound(TEXT("water.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
	gotoxy(25, 1); textColor(0);  printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(25, 1); textColor(8);  printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(25, 1); textColor(7);  printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(25, 1); textColor(15); printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(25, 1); textColor(12); printf("■"); Sleep(TIME_OF_DELAY);

	PlaySound(TEXT("water.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
	gotoxy(27, 1); textColor(0);  printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(27, 1); textColor(8);  printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(27, 1); textColor(7);  printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(27, 1); textColor(15); printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(27, 1); textColor(10); printf("■"); Sleep(TIME_OF_DELAY);

	PlaySound(TEXT("water.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
	gotoxy(25, 2); textColor(0);  printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(25, 2); textColor(8);  printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(25, 2); textColor(7);  printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(25, 2); textColor(15); printf("■"); Sleep(TIME_OF_DELAY);
	gotoxy(25, 2); textColor(14); printf("■"); Sleep(TIME_OF_DELAY);


	gotoxy(29, 2); textColor(0); printf("회원 관리 프로그램"); Sleep(TIME_OF_DELAY);
	gotoxy(29, 2); textColor(8); printf("회원 관리 프로그램"); Sleep(TIME_OF_DELAY);
	gotoxy(29, 2); textColor(7); printf("회원 관리 프로그램"); Sleep(TIME_OF_DELAY);
	gotoxy(29, 2); textColor(15); printf("회원 관리 프로그램"); Sleep(TIME_OF_DELAY);
	textColor(8);
	
	for (i = 0; i <= 32; i++){
		gotoxy(i, 4);  printf("made by YG"); Sleep(17);
		if (i != 32){
			gotoxy(i, 4);  printf("                  ");
		}
	}

	textColor(16 * 14);
	gotoxy(0, 26); printf("\t\t     원하는 기능의 번호를 입력하세요【 】                  ");
	textColor(7);
}

int stringComp(char *msg1, char *msg2)
{
	int i = 0, j = 0, check = 0;

	while(1) {
		if (msg1[j] == msg2[i] && msg1[j + 1] == msg2[i + 1]){
			i += 2;
			j += 2;
			check++;
		}
		else {
			i += 2;
			check = 0;
		}
		if (j != (int)strlen(msg1) && i == (int)strlen(msg2)) check = 0;

		if (j == (int)strlen(msg1) || i == (int)strlen(msg2)) break;
	}
	return check;
}