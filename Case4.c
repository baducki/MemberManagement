#include "common.h"

// 검색화면 함수

void adjustMemberInfo(Member_t *id)
{
	int choice = 0;	                    // 검색옵션 선택 변수
	int studentid, i;                   // 검색에서 입력한 studentid를 받는 변수, 검색에서 받는 배열의 순서 변수 i
	char name[NAME_MAXCHAR];            // 검색에서 입력한 name을 받는 변수
	char cellphone[CELLPHONE_MAXCHAR] ; // 검색에서 입력한 cellphone을 받는 변수
	while (choice != -1){
		case4SearchOptionUI();
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
					choice = adjustInfo(id, i);
				}
				break;
			case '2':
				textColor(16 * 10);	gotoxy(7, 6);  printf("2. 이름    "); textColor(7);
				studentid = searchName(name);
				if (studentid != -1){
					i = searchInfoName(id, name);
					choice = adjustInfo(id, i);
				}
				break;
			case '3':
				textColor(16 * 10);	gotoxy(7, 7);  printf("3. 전화번호"); textColor(7);
				studentid = searchCellphone(cellphone);
				if (studentid == -2) studentid = -1;
				if (studentid != -1){
					i = searchInfoCellphone(id, cellphone);
					choice = adjustInfo(id, i);
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

int searchInfoIDnum(Member_t *id, int idnum)
{
	int i;
	for (i = 1; id[i].Studentnum != 0; i++){
		if (idnum == id[i].Studentnum) break;
	}
	if (id[i].Studentnum == 0) i = -1;
	curtainEffect();
	case4PrintInfo(id, i);
	return i;
}

int searchCellphone(char *cellphone)
{
	int valid = -1, count = 0;    // valid는 전화번호가 유효한지 확인, count는 에러메세지가 필요한지 확인
	while (valid == -1){
		if (count != 0) textColor(12);
		else textColor(10);
		gotoxy(4, 14);  printf("            ┌──────────┐");
		gotoxy(16, 15); printf("│     -      -       │");
		gotoxy(4, 16);  printf("            └──────────┘ ");
		textColor(7);
		gotoxy(4, 15);  printf("검색할 번호:");
		gotoxy(19, 15); 
		valid = insertCellphone(19, 15, cellphone, 0);
		if (valid == -1){
			case4SearchOptionUI();
			textColor(12 * 16); gotoxy(0, 28); printf("               Warning: 전화번호는 11자 이내 숫자만 입력하세요             ");
		}
		count++;
	}

	gotoxy(0, 26); lineClear();
	gotoxy(0, 28); lineClear();

	return valid;
}

int insertCellphone(int line, int row, char *cellphone, int menu)
{
	int valid, i, j, count = 0;
	gotoxy(line, row);

	for (i = 0, j = 0; i < 13;){
		if (i == 3 || i == 8){
			cellphone[i] = '-'; i++; j += 2;
		}
		else {
			gotoxy(line + i + j, row);
			cellphone[i] = getche();
			if (i != 0 && cellphone[i] == 8){
				if (i == 4 || i == 9){
					printf("  \b\b");
					i -= 2;
					j -= 2;
					gotoxy(line + i + j, row);
					printf("  \b\b");
				}
				else{
					i--;
					printf("  \b\b");
				}
			}
			else{
				valid = validCellphone(cellphone[i]);
				if (valid == 0) i++;
				else return -1;
			}
		}
	}
	validCellphoneErrorOff();

	if (valid != -1){
		valid = inputInfoYesOrNo(menu);
		if (valid == 0) cellphone[i] = '\0';
		else valid = -2;

		gotoxy(0, 26); lineClear();
		gotoxy(0, 28); lineClear();
	}
	return valid;
}

int searchInfoCellphone(Member_t *id, char *cellphone)
{
	int i, j;

	for (i = 1, j = 0; id[i-1].next != NULL; i++){
		if (!strcmp(cellphone, id[i].Cellphone)) {
			j++;
			break;
		}
	}
	if (j == 0) i = -1;
	curtainEffect();
	case4PrintInfo(id, i);

	return i;
}

int searchStudentID(void)
{
	int studentidnum;  // studentidnum은 학번 변수
	textColor(10);
	gotoxy(4, 14);  printf("            ┌───────┐");
	gotoxy(16, 15); printf("│              │");
	gotoxy(4, 16);  printf("            └───────┘ ");
	textColor(7);
	gotoxy(4, 15);  printf("검색할 학번:");
	gotoxy(19, 15);
	studentidnum = insertStudentNum(19, 15, 0);
	return studentidnum;
}

int insertStudentNum(int line, int row, int menu)
{
	char studentid[STUDENTID_MAXCHAR];  // 입력받을 학번 변수
	int i, studentidnum = 0;  // for문을 위한 변수 i, studentidnum은 입력받은 char를 int로 받는 변수
	int valid = 0;            // 입력 정보를 valid 체크 후 컨펌 받는 변수
	while (valid != -1){
		for (i = 0; i < STUDENTID_MAXCHAR - 1; i++){
			gotoxy(line + i, row);
			studentid[i] = getche();
			if (i != 0 && studentid[i] == 8){  // 백스페이스 입력 시 바로 전 숫자 삭제
				gotoxy(line + i - 1, row); printf(" ");
				i -= 2;
			}
			else validStudentID(studentid[i], &i, line, row, menu);
		}
		studentid[i] = '\0';
		valid = inputInfoYesOrNo(menu);
		if (valid == 0) {
			studentidnum = atoi(studentid);
			return studentidnum;
		}
		gotoxy(0, 16); lineClear();
		gotoxy(0, 17); lineClear();
		gotoxy(0, 18); lineClear();
		gotoxy(0, 26); lineClear();
		gotoxy(0, 28); lineClear();
	}
	return -1;
}

int searchName(char *name)
{
	int valid = -1, count = 0;    // valid는 이름이 유효한지 확인, count는 에러메세지가 필요한지 확인
	while (valid == -1){
		if (count != 0) textColor(12);
		else textColor(10);
		gotoxy(4, 14);  printf("            ┌───────┐");
		gotoxy(16, 15); printf("│              │");
		gotoxy(4, 16);  printf("            └───────┘ ");
		textColor(7);
		gotoxy(4, 15);  printf("검색할 이름:");
		gotoxy(19, 15);
		valid = insertName(19, 15, name, 0);
		if (valid == -1){
			case4SearchOptionUI();
			textColor(12*16); gotoxy(0, 28); printf("       Warning: 이름은 띄어쓰기 없이 4자이내로 한글만 입력하세요           ");
		}
		count++;
	}
	gotoxy(0, 16); lineClear();
	gotoxy(0, 17); lineClear();
	gotoxy(0, 18); lineClear();
	gotoxy(0, 26); lineClear();
	gotoxy(0, 28); lineClear();

	if (valid == 0) return 0;
	return -1;
}

int searchInfoName(Member_t *id, char *name)
{
	int i, j;
	int sameName[50];
	for (i = 0; i < 50; i++) sameName[i] = 0;

	for (i = 1, j = 0; id[i-1].next != NULL; i++){
		if (stringComp(name, id[i].Name)) {
			sameName[j] = i;
			j++;
		}
	}
	if (j == 0){
		curtainEffect();
		case4PrintInfo(id, -1);
		return -1;
	}

	else if (j == 1){
		curtainEffect();
		case4PrintInfo(id, sameName[j-1]);
		return sameName[j-1];
	}
	else if (j > 1){
		j = printSameNameMember(id, sameName, j);
		curtainEffect();
		case4PrintInfo(id, sameName[j-1]);
		return sameName[j-1];
	}
	return -1;
}

int insertName(int line, int row, char *name, int menu)
{
	int valid;
	char temp[1000];
	gotoxy(line, row);
	gets(temp);

	valid = validName(temp, 2);
	if (valid != -1){
		valid = inputInfoYesOrNo(menu);
		if (valid == 0){
			strcpy(name, temp);
			return 0;
		}
		else if (valid == -1) return -2;
		gotoxy(0, 16); lineClear();
		gotoxy(0, 17); lineClear();
		gotoxy(0, 18); lineClear();
		gotoxy(0, 26); lineClear();
		gotoxy(0, 28); lineClear();
	}
	return valid;
}

int printSameNameMember(Member_t *id, int *sameName, int j)
{
	int i, valid = -1;
	textColor(10);
	gotoxy(0, 14); printf("┌───────────────────────────────────┐");
	gotoxy(0, 15); lineClear();
	gotoxy(0, 15); printf("│                                                                      │");
	gotoxy(0, 16); printf("│                                                                      │");
	gotoxy(0, 17); printf("│                                                                      │");
	gotoxy(0, 18); printf("│                                                                      │");
	gotoxy(0, 19); printf("│                                                                      │");
	gotoxy(0, 20); printf("│                                                                      │");
	gotoxy(0, 21); printf("│                                                                      │");
	gotoxy(0, 22); printf("│                                                                      │");
	gotoxy(0, 23); printf("│                                                                      │");
	gotoxy(0, 24); printf("│                                                                      │");
	gotoxy(0, 25); printf("└───────────────────────────────────┘");
	textColor(7);
	gotoxy(8, 14); printf(" < 검색결과 > ");
	gotoxy(2, 16); printf("No  ID_NUM    NAME                ADDRESS                 CELL PHONE\n");
	gotoxy(2, 17); printf("─  ───  ────  ────────────────  ───────");
	for (i = 0; i < j; i++){
		gotoxy(2, i + 18); printf("%2d", i + 1);
		gotoxy(6, i + 18); printf("%6d", id[sameName[i]].Studentnum);
		gotoxy(14, i + 18); printf("%.8s", id[sameName[i]].Name);
		gotoxy(24, i + 18); printf("%.30s", id[sameName[i]].Address);
		gotoxy(59, i + 18); printf("%.14s", id[sameName[i]].Cellphone);
	}
	while (valid == -1){
		textColor(16 * 14);
		gotoxy(0, 26); printf("               검색할 회원의 No번호를 입력하세요  【 】                   ");
		textColor(7);
		gotoxy(52, 26); i = getch();
		if (i > 48 && i <= j + 48) return i-48;
		else {
			textColor(12 * 16);
			gotoxy(0, 28); printf("                Warning: 검색결과에 있는 숫자를 입력하세요                ");
			textColor(7);
			valid = -1;
		}
	}
	return 0;
}

int insertAddress(int line, int row, char *address, int menu)
{
	int valid;
	char temp[500];
	gotoxy(line, row);
	gets(temp);

	valid = validAddress(temp, 1);
	if (valid != -1){
		valid = inputInfoYesOrNo(menu);
		if (valid == 0){
			strcpy(address, temp);
			return 0;
		}
		else if (valid == -1) return -2;
		gotoxy(0, 16); lineClear();
		gotoxy(0, 17); lineClear();
		gotoxy(0, 18); lineClear();
		gotoxy(0, 26); lineClear();
		gotoxy(0, 28); lineClear();
	}
	return valid;
}

void errorSearchChoice(void)
{
	textColor(12 * 16);
	gotoxy(0, 28); printf("                  Warning: 1 ~ 4번 사이의 숫자를 입력하세요                ");
	textColor(7);
}

void searchCancel(void)
{
	cursorOff();
	textColor(16 * 10);
	gotoxy(0, 26); printf("         < 회원정보 수정이 취소 되었습니다 > 아무 키나 누르세요            ");
	textColor(7);
	getch();
	cursorOn();
}

void validStudentID(char studentID, int *i, int line, int row, int menu)
{
	if (studentID < 48 || studentID > 57){  // 숫자 아스키코드 48~57 외에 입력 시 Error
		validStudentIDError(menu);
		gotoxy(line + *i, row); printf(" ");
		*i-=1;
	}
}

void validStudentIDError(int menu)
{
	textColor(12 * 16);
	gotoxy(0, 28); printf("                 Warning: 학번은 6자 이내 숫자만 입력하세요                ");
	textColor(12);
	if (menu == 0){
		gotoxy(4, 14);  printf("            ┌───────┐");
		gotoxy(16, 15); printf("│");
		gotoxy(32, 15); printf("│");
		gotoxy(4, 16);  printf("            └───────┘ ");
	}
	else if (menu == 1) {
		gotoxy(0, 16); printf("                    ┌─────────────────────┐         ");
		gotoxy(20, 17); printf("│"); gotoxy(64, 17); printf("│");
		gotoxy(0, 18); printf("                    └─────────────────────┘         ");
	}
	textColor(7);
}

int inputInfoYesOrNo(int i) // 입력정보 선택 여부 확인 (입력값 i: 검색 or 수정 선택 변수)
{
	int choice;  // key: Yes or No 선택 변수
	char input[2][5] = { "검색", "수정" };
	while (1){
		cursorOff();
		textColor(16 * 10);
		gotoxy(0, 26); printf("            위 정보로 %s하시겠습니까?      예 [→]     아니요 [←]       ", input[i]);
		textColor(0);
		gotoxy(0, 27);
		choice = getche();
		textColor(7);
		if (choice == 224){
			choice = getch();
			if (choice == 77){
				gotoxy(43, 26); textColor(16 * 14 + 10); printf("  예 [→]  "); textColor(7); Sleep(TIME_OF_DELAY);
				cursorOn();
				return 0;
			}
			else if (choice == 75){
				gotoxy(55, 26); textColor(16 * 14 + 10); printf("  아니요 [←]  "); textColor(7); Sleep(TIME_OF_DELAY);
				cursorOn();
				return -1;
			}
			else warningYesOrNo();
		}
		else warningYesOrNo();
	}
	return 0;
}

void case4PrintInfo(Member_t *id, int i)
{
	if (i == -1){
		textColor(12);
		gotoxy(21, 7);  printf("검색한 정보가 존재하지 않습니다!");
		cursorOff();
		textColor(12 * 16);
		gotoxy(0, 28); printf("    Warning: 존재하지 않는 회원정보를 검색했습니다 (아무키나 누르세요)     ");
		textColor(7); getch();
		cursorOn();
	}
	else{
		textColor(15);
		gotoxy(12, 5);  printf("①     학번 : %d", id[i].Studentnum);
		gotoxy(12, 7);  printf("②     이름 : %s", id[i].Name);
		gotoxy(12, 9);  printf("③     주소 : %s", id[i].Address);
		gotoxy(12, 11); printf("④ 전화번호 : %s", id[i].Cellphone);
		textColor(7);
	}
}

// 수정화면 함수

int adjustInfo(Member_t *id, int i)
{
	int j, IDnum = 0, valid = -1, count = 0;
	int choice = 0;
	char tempname[NAME_MAXCHAR];           // 이름 수정 정보를 되돌리기 위한 temp 변수
	char tempaddress[ADDRESS_MAXCHAR];     // 주소 수정 정보를 되돌리기 위한 temp 변수
	char tempcellphone[CELLPHONE_MAXCHAR]; // 전화번호 수정 정보를 되돌리기 위한 temp 변수

	if (i != -1){
		while (choice != -1){
			choice = adjustInfoMenuChoice();
			switch (choice)
			{
			case '1':
				adjustCell(count);
				gotoxy(6, 17); printf("①     학번 : ");
				IDnum = insertStudentNum(23, 17, 1);
				if (IDnum > -1)
					IDnum = repeatStudentIDCheck(id, IDnum);
				if (IDnum > -1)
					adjustInfoInputStudentID(id, IDnum, i);
				break;
			case '2':
				while (valid == -1){
					adjustCell(count);
					gotoxy(6, 17); printf("②     이름 : ");
					strcpy(tempname, id[i].Name);
					valid = insertName(23, 17, id[i].Name, 1);
					if (valid > -1)
						adjustInfoInputName(id, i);
					else strcpy(id[i].Name, tempname);
					count++;
				}
				valid = -1; count = 0;
				break;
			case '3':
				while (valid == -1){
					adjustCell(count);
					gotoxy(6, 17); printf("③     주소 : ");
					strcpy(tempaddress, id[i].Address);
					valid = insertAddress(23, 17, id[i].Address, 1);
					if (valid > -1)	adjustInfoInputAddress(id, i);
					else strcpy(id[i].Address, tempaddress);
					count++;
				}
				valid = -1; count = 0;
				break;
			case '4':
				while (valid == -1){
					adjustCell(count);
					gotoxy(6, 17); printf("④ 전화번호 : ");
					gotoxy(26, 17); printf(" -      -     ");
					strcpy(tempcellphone, id[i].Cellphone);
					valid = insertCellphone(23, 17, id[i].Cellphone, 1);
					if (valid > -1){  // 전화번호 중복 Check
						for (j = 1; id[j].Studentnum != 0; j++){
							if (i == j);
							else if (strcmp(id[j].Cellphone, id[i].Cellphone) == 0) {  // 전화 번호가 같다면 -1을 반환
								repeatCellphoneErrorOn(1);
								valid = -1;
								break;
							}
						}
					}
					if (valid != -1) {
						adjustInfoInputCellphone(id, i);
						break;
					}
					else strcpy(id[i].Cellphone, tempcellphone);
					count++;
				}
				break;
			}
			gotoxy(0, 16); lineClear(); gotoxy(0, 17); lineClear(); gotoxy(0, 18); lineClear();
		}
	}
	return -1;
}

int adjustInfoMenuChoice(void)
{
	int choice;
	textColor(16 * 14);
	gotoxy(0, 26); printf("             수정할 정보의 번호를 입력하세요  【 】     메인 페이지 [↑]   ");
	textColor(7);
	while (1){
		gotoxy(48, 26); textColor(16 * 14); printf(" "); textColor(7);
		gotoxy(48, 26); choice = getche();
		if (choice == 224){
			choice = getch();
			if (choice == 72){
				homePageButton(1);
				return -1;
			}
		}
		else if (choice < '0' || choice > '4'){
			textColor(12 * 16);
			gotoxy(0, 28); printf("                  Warning: 1 ~ 4번 사이의 숫자를 입력하세요                ");
			textColor(7);
		}
		else {
			gotoxy(0, 26); lineClear();
			break;
		}
	}
	return choice;
}

void adjustCell(int count)
{
	if (count == 0)	textColor(10);
	else textColor(12);
	gotoxy(0, 16); printf("                    ┌─────────────────────┐         ");
	gotoxy(0, 17); lineClear();
	gotoxy(20, 17); printf("│"); gotoxy(64, 17); printf("│");
	gotoxy(0, 18); printf("                    └─────────────────────┘         ");
	textColor(7);
}

 void adjustInfoInputStudentID(Member_t *id, int IDnum, int i)
{
	id[i].Studentnum = IDnum;
	cursorOff();
	textColor(16 * 10);
	gotoxy(0, 26); printf("          < 학번 수정이 완료 되었습니다 > 아무 키나 누르세요             ");
	textColor(7);
	getch();
	cursorOn();
	gotoxy(0, 16); lineClear();
	gotoxy(0, 17); lineClear();
	gotoxy(0, 18); lineClear();
	gotoxy(0, 26); lineClear();
	gotoxy(0, 28); lineClear();
	case4PrintInfo(id, i);
}

 void adjustInfoInputName(Member_t *id, int i)
{
	 cursorOff();
	 textColor(16 * 10);
	 gotoxy(0, 26); printf("          < 이름 수정이 완료 되었습니다 > 아무 키나 누르세요             ");
	 textColor(7);
	 getch();
	 cursorOn();
	 gotoxy(22, 7); printf("          ");
	 gotoxy(0, 16); lineClear();
	 gotoxy(0, 17); lineClear();
	 gotoxy(0, 18); lineClear();
	 gotoxy(0, 26); lineClear();
	 gotoxy(0, 28); lineClear();
	 case4PrintInfo(id, i);
 }
 
 void adjustInfoInputAddress(Member_t *id, int i)
 {
	 cursorOff();
	 textColor(16 * 10);
	 gotoxy(0, 26); printf("          < 주소 수정이 완료 되었습니다 > 아무 키나 누르세요             ");
	 textColor(7);
	 getch();
	 cursorOn();
	 gotoxy(22, 9); printf("                                            ");
	 gotoxy(0, 16); lineClear();
	 gotoxy(0, 17); lineClear();
	 gotoxy(0, 18); lineClear();
	 gotoxy(0, 26); lineClear();
	 gotoxy(0, 28); lineClear();
	 case4PrintInfo(id, i);
 }

 void adjustInfoInputCellphone(Member_t *id, int i)
 {
	 cursorOff();
	 textColor(16 * 10);
	 gotoxy(0, 26); printf("           < 전화번호 수정이 완료 되었습니다 > 아무 키나 누르세요          ");
	 textColor(7);
	 getch();
	 cursorOn();
	 gotoxy(0, 16); lineClear();
	 gotoxy(0, 17); lineClear();
	 gotoxy(0, 18); lineClear();
	 gotoxy(0, 26); lineClear();
	 gotoxy(0, 28); lineClear();
	 case4PrintInfo(id, i);
 }

 int repeatStudentIDCheck(Member_t *id, int IDnum)
 {
	 int i;  // for 문을 위한 변수 i
	 for (i = 1; id[i].Studentnum != 0; i++){
		 if (id[i].Studentnum == IDnum){
			 cursorOff();
			 textColor(12 * 16);
			 gotoxy(0, 28); printf("      Warning: 기존 회원과 중복되는 학번입니다 (아무키나 누르세요)         ");
			 textColor(7); getch();
			 cursorOn();
			 gotoxy(0, 16); lineClear();
			 gotoxy(0, 17); lineClear();
			 gotoxy(0, 18); lineClear();
			 gotoxy(0, 26); lineClear();
			 gotoxy(0, 28); lineClear();
			 IDnum = -1;
			 break;
		 }
	 }
	 return IDnum;
 }

 void case4SearchOptionUI(void)  // 회원정보 수정 중 검색 옵션 UI
 {
	 system("cls");
	 textColor(16 * 14);
	 gotoxy(0, 0); printf("                             < 회원 정보 수정 >                            ");
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