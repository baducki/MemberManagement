#include "common.h"

// 7. 종료 함수
int saveCheck(void)   // 종료 전 파일 저장 유무를 질문 (반환값: 입력여부)
{
	int errorcheck = 0;
	while (1){
		if (errorcheck != -1){
			cursorOff();
			textColor(16 * 10);
			gotoxy(0, 24); printf("        수정한 내용을 저장하시겠습니까?      예 [→]     아니요 [←]       ");
			textColor(7);
			errorcheck = checkSaveValue();
			cursorOn();
			if (errorcheck != -1) break;
		}
		else if (errorcheck == -1){
			cursorOff();
			textColor(16 * 10);
			gotoxy(0, 24); printf("        수정한 내용을 저장하시겠습니까?      예 [→]     아니요 [←]        ");
			warningYesOrNo();
			textColor(7);
			errorcheck = checkSaveValue();
			cursorOn();
			if (errorcheck != -1) break;
		}
	}

	return errorcheck;
}
int checkSaveValue(void)   // 파일 저장 유무 시 유저가 입력한 값을 검증
{
	int choice;
	while (1){
		gotoxy(0, 27); textColor(0); choice = getche(); textColor(7);
		if (choice == 224){
			gotoxy(0, 27); textColor(0); choice = getch(); textColor(7);
			if (choice == 77){
				gotoxy(43, 24); textColor(16 * 14 + 10); printf("  예 [→]  "); textColor(7); Sleep(TIME_OF_DELAY);
				cursorOn();
				return 1;
			}
			else if (choice == 75){
				gotoxy(55, 24); textColor(16 * 14 + 10); printf("  아니요 [←]  "); textColor(7); Sleep(TIME_OF_DELAY);
				cursorOn();
				return 2;
			}
			else warningYesOrNo();
		}
		else warningYesOrNo();
	}
	return 0;
}

void programCloseUI(void)   // 프로그램 종료 UI
{
	cursorOff();
	system("cls");
	textColor(16 * 14);
	printf("                             < 프로그램 종료 >                             "); Sleep(TIME_OF_DELAY);
	textColor(15);
	printf("                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"); Sleep(TIME_OF_DELAY);
	printf("                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"); Sleep(TIME_OF_DELAY);
	printf("               @@@@@@@@@@@@@@@@@***.....*@@@@@@*@@@@@@@@@@@@@@@@@@@@@@@@@@\n"); Sleep(TIME_OF_DELAY);
	printf("              @@@@@@@@@@@***...           ..****@@@@@@@@@@@@@@@@@@@@@@@@@@\n"); Sleep(TIME_OF_DELAY);
	printf("              *@*@@@@@@@*....                 .**. *@@@@@@@@@@@@@@@@@@@@@@\n"); Sleep(TIME_OF_DELAY);
	printf("                 @@@@@@*....       ...........     .@@@@@@@@@@@@@@@@@@@@@@\n"); Sleep(TIME_OF_DELAY);
	printf("                *@@@@@@*..     ..*********......    .*@@@@@@@@@@@@@@@@@@@@\n"); Sleep(TIME_OF_DELAY);
	printf("                ****@@@@@@*..    ....                  .@@@@@@@**.   ..@@@\n"); Sleep(TIME_OF_DELAY);
	printf("                     @@******..    ...*.****..          .@@@@*.       ..@@\n"); Sleep(TIME_OF_DELAY);
	printf("                      ***.*..**    ..*..***.            .*@@*.. ...   ..@@\n"); Sleep(TIME_OF_DELAY);
	printf("                      ***.****.       ..                 .*@*.     ..  *@@\n"); Sleep(TIME_OF_DELAY);
	printf("                      ***...**                           .**.      .  .@@@\n"); Sleep(TIME_OF_DELAY);
	printf("                      *....**                            .*.         *@@@@\n"); Sleep(TIME_OF_DELAY);
	printf("                       *..**                             ... ..    ..@@@@@\n"); Sleep(TIME_OF_DELAY);
	printf("                        **@@*.   .                          ..........@@@@\n"); Sleep(TIME_OF_DELAY);
	printf("                         @***@. .                          ...    ....***@\n"); Sleep(TIME_OF_DELAY);
	printf("                          @*@*....                         ... ...........\n"); Sleep(TIME_OF_DELAY);
	printf("                           @*@@*.***...*                  ............   .\n"); Sleep(TIME_OF_DELAY);
	printf("                            @@@*.*...                 ....   .......     .\n"); Sleep(TIME_OF_DELAY);
	printf("                             @@*....               .....        .        .\n"); Sleep(TIME_OF_DELAY);
	printf("                               *@..             ...........              .\n"); Sleep(TIME_OF_DELAY);
	printf("                                .@*..     ...****..........  ..          .\n"); Sleep(TIME_OF_DELAY);
	printf("                                  ........   .@@****.........            .\n"); Sleep(TIME_OF_DELAY);
	printf("                                               *******...**              .\n"); Sleep(TIME_OF_DELAY);
	printf("                                                .*@@**@@@*           .  ..\n"); Sleep(TIME_OF_DELAY);
	printf("    ..........................................@@@@@@@@*             .   ..\n"); Sleep(TIME_OF_DELAY);
	textColor(7);
	gotoxy(4, 25); printf(" made by YG");
	textColor(14);
	gotoxy(4, 17);
	printf("G"); Sleep(TIME_OF_DELAY);
	printf("O"); Sleep(TIME_OF_DELAY);
	printf("O"); Sleep(TIME_OF_DELAY);
	printf("D"); Sleep(TIME_OF_DELAY);
	gotoxy(9, 17);
	printf("B"); Sleep(TIME_OF_DELAY);
	printf("Y"); Sleep(TIME_OF_DELAY);
	printf("E"); Sleep(TIME_OF_DELAY);
	gotoxy(4, 18);
	printf("S"); Sleep(TIME_OF_DELAY);
	printf("E"); Sleep(TIME_OF_DELAY);
	printf("E"); Sleep(TIME_OF_DELAY);
	gotoxy(8, 18);
	printf("Y"); Sleep(TIME_OF_DELAY);
	printf("O"); Sleep(TIME_OF_DELAY);
	printf("U"); Sleep(TIME_OF_DELAY);
	gotoxy(12, 18);
	printf("L"); Sleep(TIME_OF_DELAY);
	printf("A"); Sleep(TIME_OF_DELAY);
	printf("T"); Sleep(TIME_OF_DELAY);
	printf("E"); Sleep(TIME_OF_DELAY);
	printf("R"); Sleep(TIME_OF_DELAY);
	gotoxy(31, 18);
	textColor(12);
	printf("♡"); Sleep(TIME_OF_DELAY * 3);
	textColor(15);
	gotoxy(31, 18);
	printf("*.");
	textColor(12);
	gotoxy(25, 18);
	printf("\b\b♥"); Sleep(TIME_OF_DELAY);
	printf("\b\b\b♥"); Sleep(TIME_OF_DELAY);
	printf("\b\b\b♥"); Sleep(TIME_OF_DELAY);
	printf("\b\b\b♥"); Sleep(TIME_OF_DELAY);
	printf("\b\b\b♥"); Sleep(TIME_OF_DELAY);
	printf("\b\b\b♥"); Sleep(TIME_OF_DELAY);
	printf("\b\b\b♥"); Sleep(TIME_OF_DELAY);
	textColor(7);
	gotoxy(4, 28);
}