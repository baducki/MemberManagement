#include "common.h"

void searchMemberInfo(Member_t *id)
{
	int choice = 0;	                    // 검색옵션 선택 변수
	int studentid;                   // 검색에서 입력한 studentid를 받는 변수, 검색에서 받는 배열의 순서 변수 i
	char name[NAME_MAXCHAR];            // 검색에서 입력한 name을 받는 변수
	char cellphone[CELLPHONE_MAXCHAR];  // 검색에서 입력한 cellphone을 받는 변수
	while (choice != -1){
		case5SearchOptionUI();
		gotoxy(20, 12); choice = getche();
		if (choice < 49 || choice > 52)
			errorSearchChoice();
		else {
			switch (choice)
			{
			case '1':
				textColor(16 * 10);	gotoxy(7, 5);  printf("1. 학번    "); textColor(7);
				studentid = searchStudentID();
				if (studentid != -1){
					choice = searchInfoIDnum(id, studentid);
					searchInfo(id, choice);
					choice = -1;
				}
				break;
			case '2':
				textColor(16 * 10);	gotoxy(7, 6);  printf("2. 이름    "); textColor(7);
				studentid = searchName(name);
				if (studentid != -1){
					choice = searchInfoName(id, name);
					searchInfo(id, choice);
					choice = -1;
				}
				break;
			case '3':
				textColor(16 * 10);	gotoxy(7, 7);  printf("3. 전화번호"); textColor(7);
				studentid = searchCellphone(cellphone);
				if (studentid == -2) studentid = -1;
				if (studentid != -1){
					choice = searchInfoCellphone(id, cellphone);
					searchInfo(id, choice);
					choice = -1;
				}
				break;
			case '4':
				textColor(16 * 10);	gotoxy(7, 8);  printf("4. 취소    "); textColor(7);
				searchCancel();
				choice = -1;
				break;
			}
		}
	}
}

void case5SearchOptionUI(void)  // 회원정보 수정 중 검색 옵션 UI
{
	system("cls");
	textColor(16 * 14);
	gotoxy(0, 0); printf("                             < 회원 정보 검색 >                            ");
	textColor(7);
	gotoxy(3, 3);  printf("┌ < 회원  검색 > ┐");
	gotoxy(3, 4);  printf("│                │");
	gotoxy(3, 5);  printf("│                │");
	gotoxy(3, 6);  printf("│                │");
	gotoxy(3, 7);  printf("│                │");
	gotoxy(3, 8);  printf("│                │");
	gotoxy(3, 9);  printf("│                │");
	gotoxy(3, 10); printf("└────────┘");
	textColor(15);
	gotoxy(7, 5);  printf("1. 학번");
	gotoxy(7, 6);  printf("2. 이름");
	gotoxy(7, 7);  printf("3. 전화번호");
	gotoxy(7, 8);  printf("4. 취소");
	textColor(7);
	gotoxy(4, 12); printf("검색 옵션 선택【 】");
}

void searchInfo(Member_t *id, int i)
{
	if (i != -1){
		cursorOff();
		textColor(16 * 14);
		gotoxy(0, 0); printf("                             < 회원 정보 검색 >                            ");
		textColor(7);
		gotoxy(8, 3);  printf("┌────────── < 회원정보 > ───────────┐");
		gotoxy(8, 4);  printf("│                                                        │");
		gotoxy(8, 5);  printf("│                                                        │");
		gotoxy(8, 6);  printf("│                                                        │");
		gotoxy(8, 7);  printf("│                                                        │");
		gotoxy(8, 8);  printf("│                                                        │");
		gotoxy(8, 9);  printf("│                                                        │");
		gotoxy(8, 10); printf("│                                                        │");
		gotoxy(8, 11); printf("│                                                        │");
		gotoxy(8, 12); printf("│                                                        │");
		gotoxy(8, 13); printf("└────────────────────────────┘");
		gotoxy(12, 5);  printf("①     학번 : %d", id[i].Studentnum);
		gotoxy(12, 7);  printf("②     이름 : %s", id[i].Name);
		gotoxy(12, 9);  printf("③     주소 : %s", id[i].Address);
		gotoxy(12, 11); printf("④ 전화번호 : %s", id[i].Cellphone);
		textColor(16 * 10);
		gotoxy(0, 26); printf("                 < 회원 검색이 완료 되었습니다 >   아무키나 누르세요       ");
		textColor(7); getch();
		cursorOn();
	}
}