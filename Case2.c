#include "common.h"

// 2. È¸¿ø µî·Ï ÇÔ¼ö
void case2(FILE *fp, Member_t *id)   // 2. È¸¿ø µî·Ï ½ÇÇà
{
	system("cls");
	case2UI();
	case2CheckListUI(0);
	inputNewMember(fp, id);          // È¸¿øµî·ÏÀÌ ¿Ï·áµÇ¸é +1, Ãë¼ÒµÇ¸é 0
}

void inputNewMember(FILE *fp, Member_t *id)   // »õ·Î¿î È¸¿ø Á¤º¸¸¦ ÀÔ·Â
{
	int i, j, maxnum, maxstudentnum, valid = -1, repeatcheck = -1, count = 0;
	findMaxStudentNum(id, &maxnum, &maxstudentnum);
	maxstudentnum++; // ÇÐ»ý ÇÐ¹ø Áß °¡Àå Å« ÇÐ¹øÀ» Ã£Àº ÈÄ +1

	id[maxnum].Studentnum = maxstudentnum;

	gotoxy(20, 4); printf("%d", maxstudentnum);
	gotoxy(63, 4); printf("(ÀÚµ¿»ý¼º)");

	while (valid)
	{
		if (count == 0){
			textColor(10);
			gotoxy(17, 6); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
			gotoxy(17, 7); printf("¦¢"); gotoxy(61, 7); printf("¦¢");
			gotoxy(17, 8); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
			textColor(7);
		}
		gotoxy(20, 7);
		gets(id[maxnum].Name);
		valid = validName(id[maxnum].Name, 1);
		case2CheckListUI(1);
		count++;
	}
	gotoxy(17, 6); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(17, 7); printf("¦¢"); gotoxy(61, 7); printf("¦¢");
	gotoxy(17, 8); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	case2CheckListUI(0);
	validNameErrorOff(); valid = -1; count = 0;

	while (valid){
		if (count == 0){
			textColor(10);
			gotoxy(17, 9); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
			gotoxy(17, 10); printf("¦¢"); gotoxy(61, 10); printf("¦¢");
			gotoxy(17, 11); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
			textColor(7);
		}
		gotoxy(20, 10);
		gets(id[maxnum].Address);
		valid = validAddress(id[maxnum].Address, 0);
		case2CheckListUI(1);
		count++;
	}
	gotoxy(17, 9); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(17, 10); printf("¦¢"); gotoxy(61, 10); printf("¦¢");
	gotoxy(17, 11); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	case2CheckListUI(0);
	validAddressErrorOff(); valid = -1; count = 0;

	while (repeatcheck){
		for (i = 0, j = 0; i < 13;){
			if (count == 0){
				textColor(10);
				gotoxy(17, 12); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
				gotoxy(17, 13); printf("¦¢"); gotoxy(61, 13); printf("¦¢");
				gotoxy(17, 14); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
				textColor(7);
			}
			if (i == 3 || i == 8){
				id[maxnum].Cellphone[i] = '-'; i++; j += 2;
			}
			else {
				gotoxy(22 + i + j, 13);
				id[maxnum].Cellphone[i] = getche();
				if (i != 0 && id[maxnum].Cellphone[i] == 8){
					if (i == 4 || i == 9){
						printf("  \b\b");
						i -= 2;
						j -= 2;
						gotoxy(22 + i + j, 13);
						printf("  \b\b");
					}
					else{
						i--;
						printf("  \b\b");
					}
				}
				else{
					valid = validCellphone(id[maxnum].Cellphone[i]);
					if (valid == 0) i++;
					else {
						validCellphoneErrorOn();
						case2CheckListUI(1);
						count++;
					}
				}
			}
		}
		id[maxnum].Cellphone[i] = '\0';
		validCellphoneErrorOff(); valid = -1;
		repeatcheck = repeatCellphone(id, id[maxnum].Cellphone, maxnum);
		if (repeatcheck == -1) {
			repeatCellphoneErrorOn(0);
			count++;
		}
	}
	gotoxy(17, 12); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(17, 13); printf("¦¢"); gotoxy(61, 13); printf("¦¢");
	gotoxy(17, 14); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	case2CheckListUI(0);
	repeatCellphoneErrorOff();
	valid = inputMemberSave();
	cursorOff();

	if (valid == 0){
		id[maxnum].Studentnum = 0;
		id[maxnum].Name;
		id[maxnum].Address;
		id[maxnum].Cellphone;
		textColor(16 * 10);
		gotoxy(0, 26); printf("                 < È¸¿ø µî·ÏÀÌ Ãë¼Ò µÇ¾ú½À´Ï´Ù >   ¾Æ¹«Å°³ª ´©¸£¼¼¿ä       ");
		textColor(7);
		gotoxy(74, 26); getche(); fflush(stdin);
	}
	else {
		id[maxnum - 1].next = &id[maxnum];
		id[maxnum].prev = &id[maxnum - 1];
		id[maxnum].next = NULL;
		closeCase2();
	}
	cursorOn();
}

void findMaxStudentNum(Member_t *id, int *maxnum, int *maxstudentnum)   // ÇöÀç ÀúÀåµÈ ÇÐ»ýµé Áß °¡Àå Å« ÇÐ¹ø °Ë»ö
{
	int i;
	for (i = 2; id[i-1].next != NULL; i++){
		if (id[i - 1].Studentnum < id[i].Studentnum)
			*maxstudentnum = id[i].Studentnum;
	}
	*maxnum = i;
}

int validName(char *str, int key)   // ÀÌ¸§¿¡ ÇÑ±Û ¿Ü ÀÔ·Â ±ÝÁö
{
	int i = 0, len = strlen(str), check = 0;
	if (str[0] >= 0 && str[0] <128){
		validNameErrorOn(key); check = -1;
	}
	else if (len == 0 || str[0] == ' ') {
		validNameErrorOn(key); check = -1;
	}
	else if (len > 8) {
		validNameErrorOn(key); check = -1;
	}
	else {
		while (i < (len - 1)){
			if (str[i] <= -56 && str[i] >= -80){
				if (str[i] < 0)	{
					if (str[i + 1] <= -2 && str[i + 1] >= -95){
						i += 2;
					}
					else { validNameErrorOn(key); check = -1; break; }
				}
				else { validNameErrorOn(key); check = -1; break; }
			}
			else { validNameErrorOn(key); check = -1; break; }
		}
	}
	return check;
}
void validNameErrorOn(int key)   // Àß¸øµÈ ÀÌ¸§ ÀÔ·Â½Ã ¿¡·¯ ¸Þ¼¼Áö On
{
	textColor(12 * 16);
	gotoxy(0, 28); printf("       Warning: ÀÌ¸§Àº ¶ç¾î¾²±â ¾øÀÌ 4ÀÚÀÌ³»·Î ÇÑ±Û¸¸ ÀÔ·ÂÇÏ¼¼¿ä           ");
	textColor(7);
	if (key == 1){
		gotoxy(19, 7); printf("                                          ");
		gotoxy(19, 10); printf("                                          ");
		gotoxy(19, 13); printf(" (     -      -      )                    ");
		case2UI();
		case2CheckListUI(1);
		textColor(12);
		gotoxy(17, 6); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
		gotoxy(17, 7); printf("¦¢"); gotoxy(61, 7); printf("¦¢");
		gotoxy(17, 8); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
		textColor(7);
	}
}
void validNameErrorOff(void)   // Àß¸øµÈ ÀÌ¸§ ÀÔ·Â½Ã ¿¡·¯ ¸Þ¼¼Áö Off
{
	gotoxy(0, 28); lineClear();
	gotoxy(63, 7); printf("(ÀÔ·Â¿Ï·á)");
}
int validAddress(char *str, int menu)   // ÀÔ·ÂµÈ ÁÖ¼Ò valid À¯¹« È®ÀÎ
{
	int i = 0, len = strlen(str), check = 0;
	if (len > 30) {
		validAddressErrorOn(menu); check = -1;
	}
	return check;
}
void validAddressErrorOn(int menu)   // Àß¸øµÈ ÀÌ¸§ ÀÔ·Â½Ã ¿¡·¯ ¸Þ¼¼Áö On
{
	textColor(12 * 16);
	gotoxy(0, 28); printf("           Warning: ÁÖ¼Ò´Â ¶ç¾î¾²±â Æ÷ÇÔ 15ÀÚÀÌ³»·Î ÀÔ·ÂÇÏ¼¼¿ä             ");
	textColor(7);
	if (menu == 0){
		gotoxy(19, 10); printf("                                         ");
		gotoxy(19, 13); printf(" (     -      -      )                    ¦¢");
		case2UI();
		case2CheckListUI(1);
		textColor(12);
		gotoxy(17, 9); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
		gotoxy(17, 10); printf("¦¢"); gotoxy(61, 10); printf("¦¢");
		gotoxy(17, 11); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
		textColor(7);
		gotoxy(63, 7); printf("(ÀÔ·Â¿Ï·á)");
	}
}
void validAddressErrorOff(void)   // Àß¸øµÈ ÁÖ¼Ò ÀÔ·Â½Ã ¿¡·¯ ¸Þ¼¼Áö Off
{
	gotoxy(0, 28); lineClear();
	gotoxy(63, 10); printf("(ÀÔ·Â¿Ï·á)");
}
int validCellphone(char a)   // ÀÌ¸§¿¡ ÇÑ±Û ¿Ü ÀÔ·Â ±ÝÁö
{
	int check = 0;
	if (a < 48 || a > 57)    // ¼ýÀÚ ¾Æ½ºÅ°ÄÚµå=48~57 ¿Ü¿¡ ÀÔ·Â ½Ã Error
		check = -1;
	return check;
}
int repeatCellphone(Member_t *id, char *str, int maxnum)
{
	for (int i = 1; i < maxnum; i++){
		if (strcmp(id[i].Cellphone, id[maxnum].Cellphone) == 0)  // ÀüÈ­ ¹øÈ£°¡ °°´Ù¸é -1À» ¹ÝÈ¯
			return -1;
	}
	return 0;
}
void validCellphoneErrorOn(void)   // Àß¸øµÈ ÀüÈ­¹øÈ£ ÀÔ·Â½Ã ¿¡·¯ ¸Þ¼¼Áö On
{
	textColor(12 * 16);
	gotoxy(0, 28); printf("               Warning: ÀüÈ­¹øÈ£´Â 11ÀÚ ÀÌ³» ¼ýÀÚ¸¸ ÀÔ·ÂÇÏ¼¼¿ä             ");
	textColor(7);
	textColor(12);
	gotoxy(17, 12); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(17, 13); printf("¦¢"); gotoxy(61, 13); printf("¦¢");
	gotoxy(17, 14); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	case2CheckListUI(1);
	textColor(7);
}
void validCellphoneErrorOff(void)   // Àß¸øµÈ ÁÖ¼Ò ÀÔ·Â½Ã ¿¡·¯ ¸Þ¼¼Áö Off
{
	gotoxy(0, 28); lineClear();
}
void repeatCellphoneErrorOn(int menu)   // Àß¸øµÈ ÀüÈ­¹øÈ£ ÀÔ·Â½Ã ¿¡·¯ ¸Þ¼¼Áö On
{
	textColor(12 * 16);
	gotoxy(0, 28); printf("         Warning: ±âÁ¸ È¸¿ø°ú µ¿ÀÏÇÑ ÀüÈ­¹øÈ£ÀÔ´Ï´Ù! ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä       ");
	textColor(7);
	if (menu == 0){
		textColor(12);
		gotoxy(17, 12); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
		gotoxy(17, 13); printf("¦¢"); gotoxy(61, 13); printf("¦¢");
		gotoxy(17, 14); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
		textColor(7);
		gotoxy(19, 13); printf(" (     -      -      )                    ");
		case2CheckListUI(1);
	}
}
void repeatCellphoneErrorOff(void)   // Àß¸øµÈ ÀüÈ­¹øÈ£ ÀÔ·Â½Ã ¿¡·¯ ¸Þ¼¼Áö Off
{
	gotoxy(0, 28); lineClear();
	gotoxy(63, 13); printf("(ÀÔ·Â¿Ï·á)");
}
void closeCase2(void)
{
	int inputkey;
	textColor(16 * 10);
	gotoxy(0, 26); printf("                 < È¸¿ø µî·ÏÀÌ ¿Ï·á µÇ¾ú½À´Ï´Ù >   ¾Æ¹«Å°³ª ´©¸£¼¼¿ä       ");
	textColor(7);
	gotoxy(74, 26); inputkey = getche();
}
int inputMemberSave(void)   // ÀÔ·ÂÇÑ È¸¿øÀÇ Á¤º¸ ÀúÀå À¯¹« È®ÀÎ
{
	int choice = -1, check = -1;
	cursorOff();
	textColor(16 * 14);
	gotoxy(0, 26); printf("      < È¸¿øµî·Ï ¿Ï·á > ÀúÀåÇÏ½Ã°Ú½À´Ï±î?    ¿¹ [¡æ]     ¾Æ´Ï¿ä [¡ç]       ");
	textColor(7);
	while (check != 1 || check != 0){
		gotoxy(0, 27); textColor(0);  choice = getche(); textColor(7);
		if (choice == 224){
			choice = getch();
			if (choice == 77){
				gotoxy(43, 26); textColor(16 * 14 + 10); printf("  ¿¹ [¡æ]  "); textColor(7); Sleep(TIME_OF_DELAY);
				cursorOn();
				return -1;
			}
			else if (choice == 75){
				gotoxy(55, 26); textColor(16 * 14 + 10); printf("  ¾Æ´Ï¿ä [¡ç]  "); textColor(7); Sleep(TIME_OF_DELAY);
				cursorOn();
				return 0;
			}
			else warningYesOrNo();
		}
		else warningYesOrNo();
	}
	gotoxy(0, 28); lineClear();
	return check;
}

void case2UI(void)   // È¸¿øµî·Ï UI Ãâ·Â
{
	gotoxy(0, 0);
	textColor(16 * 14);
	printf("                                < È¸¿ø µî·Ï >                              ");
	textColor(7);
	printf("\n\n                 ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤            ");
	gotoxy(11, 4); printf("ÇÐ¹ø : ");
	gotoxy(17, 4); printf("¦¢"); gotoxy(61, 4); printf("¦¢");
	printf("\n                 ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥            ");
	printf("                 ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤            ");
	printf("           ÀÌ¸§ :¦¢");
	gotoxy(61, 7); printf("¦¢            ");
	printf("                 ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥            ");
	printf("                 ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤            ");
	printf("           ÁÖ¼Ò :¦¢");
	gotoxy(59, 10); printf("  ¦¢            ");
	printf("                 ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥            ");
	printf("                 ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤            ");
	printf("       ÀüÈ­¹øÈ£ :¦¢ (     -      -      )                    ¦¢            ");
	printf("                 ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥            ");
	lineClear();
	lineClear();
}

void case2CheckListUI(int menu)
{
	if(menu == 0) textColor(10);
	else textColor(12);
	gotoxy(0, 17);
	printf("              ¦£              < ÀÔ·Â ½Ã ÁÖÀÇ»çÇ× >              ¦¤         ");
	printf("              ¦¢                                                ¦¢         ");
	printf("              ¦¢                                                ¦¢         ");
	printf("              ¦¢                                                ¦¢         ");
	printf("              ¦¢                                                ¦¢         ");
	printf("              ¦¢                                                ¦¢         ");
	printf("              ¦¢                                                ¦¢         ");
	printf("              ¦¦                                                ¦¥         ");
	textColor(15);
	gotoxy(19, 19); printf("1. ÇÐ¹ø: ÀÚµ¿À¸·Î »ý¼º");
	gotoxy(19, 20); printf("2. ÀÌ¸§: ¶ç¾î¾²±â ¾øÀÌ 4ÀÚÀÌ³» ÇÑ±Û¸¸ ÀÔ·Â");
	gotoxy(19, 21); printf("3. ÁÖ¼Ò: ¶ç¾î¾²±â Æ÷ÇÔ 15ÀÚ ÀÌ³» ÀÔ·Â");
	gotoxy(19, 22); printf("4. ÀüÈ­¹øÈ£: 11ÀÚ¸® ÀÌ³» ¼ýÀÚ ÀÔ·Â");
	gotoxy(19, 23); printf("5. ÇÁ·Î±×·¥ Á¾·á Àü TXTÆÄÀÏ ÀúÀå ÇÊ¿ä");
	textColor(7);
}