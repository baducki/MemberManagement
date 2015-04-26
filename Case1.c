#include "common.h"

// 1. 회원 보기 함수
void headOfCase1(void)   // 회원 보기 헤드양식 출력
{
	system("cls");
	gotoxy(0, 0);
	textColor(16 * 14);
	cursorOff();
	printf("                             < 회원  List >                                ");
	textColor(7);
	printf("\n  No  ID_NUM    NAME                ADDRESS                 CELL PHONE\n");
	printf("  ─  ───  ────  ────────────────  ───────");
}

void printInfo(Member_t *id)   // 구조체에 있는 회원정보를 출력
{
	int i = 1, j = 1, check;    // i는 for문을 위한 변수, j는 위치 지정을 위한 변수, check는 입력키 체크
	int pre = 0, temp;      // pre는 이전, 다음 페이지 출력 확인을 위한 변수, temp는 이전, 다음 페이지 출력 시 i값 지정을 위한 변수

	headOfCase1();
	
	Member_t tempmember[10];
	Member_t *printmember = (Member_t *)malloc(sizeof(Member_t));
	printmember->next = id[0].next;
	tempmember[0].next = printmember->next;

	for (i = 1, j = 1; printmember->next != NULL; i++, j++){
		if (j > NUM_OF_PRINT) j -= NUM_OF_PRINT;  // gotoxy로 위치 지정 출력하기 위해 j 변수 선언 후 j로 출력 열 위치 조정

		gotoxy(1, j + 3);  printf("%3d", i);
		gotoxy(6, j + 3);  printf("%6d", printmember->next->Studentnum);
		gotoxy(14, j + 3); printf("%.8s", printmember->next->Name);
		gotoxy(24, j + 3); printf("%.30s", printmember->next->Address);
		gotoxy(59, j + 3); printf("%.14s", printmember->next->Cellphone);

		printmember->next = printmember->next->next;

		if (printmember->next != NULL){
			if (i%NUM_OF_PRINT == 0 && pre == 0){
				check = pauseWithRight();
				if (check == 77){
					temp = i - NUM_OF_PRINT;
					headOfCase1();
					pre++;
					tempmember[pre].next = printmember->next;
				}
				else if (check == 72) break; // 방항키 ↑를 누르면 메인 페이지로 복귀
			}
			else if (i%NUM_OF_PRINT == 0 && pre != 0){
				check = pauseWithLeftRight();
				temp = i - NUM_OF_PRINT;
				if (check == 75){
					i = i - NUM_OF_PRINT * 2;
					previousPageButton();
					pre--;
					printmember->next = tempmember[pre].next;
				}
				else {
					nextPageButton();
					pre++;
					tempmember[pre].next = printmember->next;
				}
				headOfCase1();
			}
		}

		else if (printmember->next == NULL){
			textColor(16 * 10);
			gotoxy(0, 24); printf("                       모든 회원 정보를 출력하였습니다                     ");
			textColor(7);
			check = pauseWithLeft();
			if (check == 75){
				i = temp;
				j = 0;
				previousPageButton();
				pre--;
				printmember->next = tempmember[pre].next;
				headOfCase1();
			}
			else if (check == 72) break; // 방항키 ↑를 누르면 메인 페이지로 복귀
		}
	}
	free(printmember);
	cursorOn();
}


int pauseWithLeft(void)  // 화면을 멈추고 다음화면에 계속 출력
{
	int choice;
	textColor(16 * 14);
	gotoxy(0, 26); printf("  이전 페이지 [←]     (원하시는 키를 입력하세요)      메인 페이지 [↑]    ");
	textColor(7);
	while (1){
		gotoxy(37, 26); choice = getch();
		if (choice == 224){
			choice = getch();
			if (choice == 75){
				previousPageButton(); break;
			}
			else if (choice == 72){
				homePageButton(1); break;
			}
		}
		textColor(12 * 16);
		gotoxy(0, 28); printf("                   Warning: ← 혹은 ↑방향키를 입력하세요                  ");
		textColor(7);
	}
	return choice;
}

int pauseWithRight(void)  // 화면을 멈추고 다음화면에 계속 출력
{
	int choice;
	textColor(16 * 14);
	gotoxy(0, 26); printf("  메인 페이지 [↑]     (원하시는 키를 입력하세요)      다음 페이지 [→]    ");
	textColor(7);
	while (1){
		gotoxy(37, 26); choice = getch();
		if (choice == 224){
			choice = getch();
			if (choice == 77){
				nextPageButton();
				break;
			}
			else if (choice == 72){
				homePageButton(0);
				break;
			}
		}
		textColor(12 * 16);
		gotoxy(0, 28); printf("                    Warning: ↑ 혹은 → 방향키를 입력하세요                ");
		textColor(7);
	}
	return choice;
}

int pauseWithLeftRight(void)    // 화면을 멈추고 다음화면에 계속, 이전화면으로 출력
{
	int choice;
	textColor(16 * 14);
	gotoxy(0, 26); printf("  이전 페이지 [←]     (원하시는 키를 입력하세요)      다음 페이지 [→]    ");
	textColor(7);
	while (1){
		gotoxy(37, 26); choice = getch();
		if (choice == 224){
			choice = getch();
			if (choice == 75) break;
			else if (choice == 77) break;
		}
		textColor(12 * 16);
		gotoxy(0, 28); printf("                    Warning: ← 혹은 → 방향키를 입력하세요                ");
		textColor(7);
	}
	return choice;
}

void previousPageButton(void)   // 이전 페이지 버튼 On
{
	textColor(16 * 10 + 14);
	gotoxy(0, 26); printf("  이전 페이지 [←]  "); Sleep(77);
	textColor(7);
}

void nextPageButton(void)   // 다음 페이지 버튼 On
{
	textColor(16 * 10 + 14);
	gotoxy(55, 26); printf("  다음 페이지 [→]  "); Sleep(77);
	textColor(7);
}

void homePageButton(int check)   // 다음 페이지 버튼 On
{
	textColor(16 * 10 + 14);

	if (check == 0)	gotoxy(0, 26);
	else gotoxy(55, 26);

	printf("  메인 페이지 [↑]  "); Sleep(77);
	textColor(7);
}