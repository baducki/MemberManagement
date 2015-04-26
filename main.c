// 프로그래밍 연습 기말과제 3주차 - 1분반 윤영기(141057), 송경(141044)
// *** 모든 기능 구현하였습니다 ***

#include "common.h"

int main(void)
{
	SetConsoleTitleA("  회원 관리 프로그램 made by YG");
	system("mode con lines=30 cols=75");  // 윈도우 창 화면 크기를 고정
	cursorOff();
	welcomeUI();
	cursorOn();
	FILE *fp = NULL;
	Member_t id[NUM_OF_MEMBERS];

	inputInfo(fp, id);                    // InputInfo : data.txt파일을 열고 구조체에 저장
	                   
	unsigned int saveneed = 0;            // saveneed는 세이브 필요 유무를 체크하는 변수
	int menu_choice = 0;                  // menu_choice는 유저가 선택하는 메뉴값 변수
	int error = 0;                        // menu 선택 시 error 발생에 따른 error 메세지 출력을 위한 변수

	while (menu_choice != -1)                // -1 (종료) 일 때 프로그램 종료
	{
		menu_choice = mainMenu(&error);
		switch (menu_choice)
		{
		case '1': //회원정보보기 
			choiceButton(menu_choice);      // 메뉴 버튼 입력 시 클릭 효과
			screenClearUp();
			printInfo(id);          // 구조체에 저장된 회원정보를 화면에 출력
			break;

		case '2': // 회원등록
			choiceButton(menu_choice);
			screenClearUp();
			case2(fp, id); // 회원 입력 후 maxnum +1
			saveneed++;
			break;

		case '3': // 회원삭제
			choiceButton(menu_choice);
			screenClearUp();
			deleteMemberInfo(id);
			saveneed++;
			break;

		case '4': // 정보수정
			choiceButton(menu_choice);
			screenClearUp();
			adjustMemberInfo(id);
			saveneed++;
			break;

		case '5': // 검색하기
			choiceButton(menu_choice);
			screenClearUp();
			searchMemberInfo(id);
			break;

		case '6': // 저장하기
			choiceButton(menu_choice);
			menu_choice = saveCheck();
			if (menu_choice == 1)
			{
				screenClearUp();
				saveFile(fp, id);
				saveneed = 0;
			}
			break;

		case '7': // 종료
			choiceButton(menu_choice);
			if (saveneed > 0) menu_choice = saveCheck();
			if (menu_choice == 1) saveFile(fp, id);
			screenClearUp();
			menu_choice = -1;
			break;
		}
	}
	programCloseUI();
	return 0;
}

// Main에 포함된 함수
void inputInfo(FILE *fp, Member_t *id)   // data.txt 파일을 구조체에 저장
{
	int i = 0;
	char idnum[12];  // 학번을 String으로 입력받기 위한 임시 변수 -> int형 Studentnum 으로 변환
	if ((fp = fopen("data.txt", "r")) == NULL){
		fprintf(stderr, "Error opening file <%s>", "data.txt");
		return ;
	}
	while (1){
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", idnum, id[i].Name, id[i].Address, id[i].Cellphone);
		id[i].Studentnum = atoi(idnum);
		
		if (i == 0);
		else {
			id[i].prev = &id[i - 1];
			id[i].next = &id[i + 1];
		}

		if (feof(fp)) break;
		i++;
	}
	if (i > 0) {  // 입력데이터가 1이상 일 때 Linked List 구현
		id[0].next = &id[1];
		id[0].prev = NULL;
		id[i].next = NULL;
		id[i+1].Studentnum = 0;
	}
	
	fclose(fp);
}

int mainMenu(int *error)  // 메인메뉴 기능 (입력값: 에러값, 출력값: 유저 메뉴선택값)
{
	int choice;
	if (*error == 0){
		mainmenuUI();                // 메인 페이지 출력
		choice = inputMenu();        // 메뉴 입력 받기
		*error = errorCheck(choice);
	}

	else if (*error == -1){          // 에러입력 시 에러메세지 출력, 에러해제 시 에러메세지 삭제
		mainmenuUI();                // 메인 페이지 출력
		textColor(12 * 16);
		gotoxy(0, 28); printf("                  Warning: 1 ~ 7번 사이의 숫자를 입력하세요                ");
		textColor(7);
		choice = inputMenu();        //  메뉴 입력 받기
		gotoxy(0, 28); lineClear();
		*error = errorCheck(choice);
	}

	return choice;
}

int inputMenu(void)         // 메뉴 선택값 입력
{
	int choice;
	gotoxy(54, 26);
	choice = getche();
	return choice;
}

int errorCheck(int check)   // 메뉴선택 시 에러 체크
{
	if (check < 49 || check > 55) return -1;
	return 0;
}

void choiceButton(int num)   // 메인 메뉴에서 기능 선택시 버튼 On
{
	switch (num)
	{
	case '1':
		textColor(16 * 10 + 14);
		gotoxy(30, 8); printf("①  회원 보기"); Sleep(77);
		textColor(7);
		break;
	case '2':
		textColor(16 * 10 + 14);
		gotoxy(30, 10); printf("②  회원 등록"); Sleep(77);
		textColor(7);
		break;
	case '3':
		textColor(16 * 10 + 14);
		gotoxy(30, 12); printf("③  회원 삭제"); Sleep(77);
		textColor(7);
		break;
	case '4':
		textColor(16 * 10 + 14);
		gotoxy(30, 14); printf("④  회원 수정"); Sleep(77);
		textColor(7);
		break;
	case '5':
		textColor(16 * 10 + 14);
		gotoxy(30, 16); printf("⑤  회원 검색"); Sleep(77);
		textColor(7);
		break;
	case '6':
		textColor(16 * 10 + 14);
		gotoxy(30, 18); printf("⑥  파일 저장"); Sleep(77);
		textColor(7);
		break;
	case '7':
		textColor(16 * 10 + 14);
		gotoxy(30, 20); printf("⑦  종 료    "); Sleep(77);
		textColor(7);
		break;
	}
}

void mainmenuUI(void)       // 메인메뉴 UI 출력
{
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

	gotoxy(25, 1); textColor(12); printf("■"); 
	gotoxy(27, 1); textColor(10); printf("■"); 
	gotoxy(25, 2); textColor(14); printf("■"); 
	gotoxy(29, 2); textColor(15); printf("회원 관리 프로그램"); 
	gotoxy(32, 4); textColor(8);  printf("made by YG");

	textColor(16 * 14);
	gotoxy(0, 26); printf("\t\t     원하는 기능의 번호를 입력하세요【 】                  ");
	textColor(7);
}