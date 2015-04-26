#include "common.h"


void deleteMemberInfo(Member_t *id)
{
	int choice = 0;	                    // 검색옵션 선택 변수
	int studentid, i;                   // 검색에서 입력한 studentid를 받는 변수, 검색에서 받는 배열의 순서 변수 i
	char name[NAME_MAXCHAR];            // 검색에서 입력한 name을 받는 변수
	char cellphone[CELLPHONE_MAXCHAR];  // 검색에서 입력한 cellphone을 받는 변수
	while (choice != -1){
		case3DeleteSearchOptionUI();
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
					i = searchInfoIDnum(id, studentid);
					choice = deleteInfo(id, i);
				}
				break;
			case '2':
				textColor(16 * 10);	gotoxy(7, 6);  printf("2. 이름    "); textColor(7);
				studentid = searchName(name);
				if (studentid != -1){
					i = searchInfoName(id, name);
					choice = deleteInfo(id, i);
				}
				break;
			case '3':
				textColor(16 * 10);	gotoxy(7, 7);  printf("3. 전화번호"); textColor(7);
				studentid = searchCellphone(cellphone);
				if (studentid == -2) studentid = -1;
				if (studentid != -1){
					i = searchInfoCellphone(id, cellphone);
					choice = deleteInfo(id, i);
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

int deleteInfo(Member_t *id, int i)
{
	int choice;
	while (i != -1){
		cursorOff();
		textColor(16 * 14);
		gotoxy(0, 26); printf("   위 회원을 삭제하시겠습니까?   삭제[→]    취소[←]    메인 페이지 [↑]  ");
		textColor(7);
		gotoxy(0, 27); textColor(0); choice = getche(); textColor(7);
		if (choice == 224){
			choice = getch();
			if (choice == 72){
				homePageButton(1);
				return -1;
			}
			else if (choice == 77){
				deleteSearchInfoUI(id, i);
				deleteLinkedList(id, i);
				cursorOff();
				gotoxy(31, 26); textColor(16 * 10 + 14); printf("  삭제[→]  "); textColor(7); Sleep(TIME_OF_DELAY);
				textColor(16 * 10);
				gotoxy(0, 26); printf("           < 회원 정보가 삭제되었습니다 >   아무 키나 누르세요             ");
				textColor(7);
				deleteCompleteUI();
				getch();
				screenClearDelete();
				cursorOn();
				return -1;
			}
			else if (choice == 75){
				cursorOff();
				gotoxy(43, 26); textColor(16 * 10 + 14); printf("  취소[←]  "); textColor(7); Sleep(TIME_OF_DELAY);
				textColor(16 * 10);
				gotoxy(0, 26); printf("        < 회원 정보 삭제가 취소되었습니다 >    아무 키나 누르세요          ");
				textColor(7);
				getch();
				cursorOn();
				return -1;
			}
			else{
				textColor(12 * 16);
				gotoxy(0, 28); printf("        Warning:  →(삭제), ←(취소), ↑(메인페이지)키를 입력하세요        ");
				textColor(7);
			}
		}
		else {
			textColor(12 * 16);
			gotoxy(0, 28); printf("        Warning:  →(삭제), ←(취소), ↑(메인페이지)키를 입력하세요        ");
			textColor(7);
		}
	}
	return -1;
}

void deleteLinkedList(Member_t *id, int i)
{
	int j;
	Member_t *temp = (Member_t*)malloc(sizeof(Member_t));

	temp->prev = id[i].prev;
	temp->next = id[i].next;
	
	if (id[i].next != NULL){
		id[i].prev->next = temp->next;
		id[i].next->prev = temp->prev;
	}
	else id[i].prev->next = NULL;

	id[i].Address[0] = '\0';
	for (j = 0; j < CELLPHONE_MAXCHAR-1; j++) id[i].Cellphone[j] = ' ';
	id[i].Cellphone[j] = '\0';
	for (j = 0; j < NAME_MAXCHAR-1; j++) id[i].Name[j] = ' ';
	id[i].Name[j] = '\0';
	id[i].Studentnum = 0;

	free(temp);
}

void case3DeleteSearchOptionUI(void)  // 회원정보 수정 중 검색 옵션 UI
{
	system("cls");
	textColor(16 * 14);
	gotoxy(0, 0); printf("                             < 회원 정보 삭제 >                            ");
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

void deleteSearchInfoUI(Member_t *id, int i)
{
	textColor(16 * 14);
	gotoxy(0, 0); printf("                             < 회원 정보 삭제 >                            ");
	textColor(12 * 16);
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
}

void deleteCompleteUI(void)
{
	textColor(12);
	gotoxy(0, 15);  printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ "); 
	gotoxy(0, 16);  printf("■□□□■■■□□□□□■□■■■■■□□□□□■□□□□□■□□□□□■ "); 
	gotoxy(0, 17);  printf("■□■■□■■□■■■■■□■■■■■□■■■■■■■□■■■□■■■■■ "); 
	gotoxy(0, 18);  printf("■□■■■□■□■■■■■□■■■■■□■■■■■■■□■■■□■■■■■ ");
	gotoxy(0, 19);  printf("■□■■■□■□□□□□■□■■■■■□□□□□■■■□■■■□□□□□■ ");
	gotoxy(0, 20);  printf("■□■■■□■□■■■■■□■■■■■□■■■■■■■□■■■□■■■■■ ");
	gotoxy(0, 21);  printf("■□■■□■■□■■■■■□■■■■■□■■■■■■■□■■■□■■■■■ ");
	gotoxy(0, 22);  printf("■□□□■■■□□□□□■□□□□□■□□□□□■■■□■■■□□□□□■ ");
	gotoxy(0, 23);  printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ ");
	textColor(7);
}