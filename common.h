// 회원관리 프로그램 헤더파일

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <mmsystem.h>

#pragma comment (lib ,"winmm.lib")
#pragma warning (disable:4996)

// 회원관리 프로그램 Define

#define NUM_OF_MEMBERS      200
#define NUM_OF_PRINT         20
#define TIME_OF_DELAY        77
#define CURTAIN_DELAY        37
#define STUDENTID_MAXCHAR     7
#define NAME_MAXCHAR          9
#define ADDRESS_MAXCHAR      41
#define CELLPHONE_MAXCHAR    15

// 회원관리 프로그램 구조체

typedef struct Member {
	int Studentnum;         // 학번
	char Name[NAME_MAXCHAR];
	char Address[ADDRESS_MAXCHAR];
	char Cellphone[CELLPHONE_MAXCHAR];
	struct Member *prev;    // Linked List 앞 포인터
	struct Member *next;    // Linked List 뒤 포인터
} Member_t;

/*** 회원관리 프로그램 함수 ***/


// Main에 포함된 함수
void inputInfo(FILE *fp, Member_t *id); // data.txt 파일을 구조체에 저장
int mainMenu(int* error);               // 메인메뉴 기능 (입력값: 에러값, 출력값: 유저 메뉴선택값)
int inputMenu(void);                    // 메뉴 선택값 입력
int errorCheck(int check);              // 메뉴선택 시 에러 체크
void mainmenuUI(void);                  // 메인메뉴 UI
void welcomeUI();                       // 시작 화면 UI

// 1. 회원 보기 함수
void headOfCase1(void);                  // 회원 보기 헤드양식 출력
void printInfo(Member_t *id);            // 구조체에 있는 회원정보를 출력
int pauseWithLeftRight(void);            // 이젠 페이지, 다음 페이지 화면 출력
int pauseWithLeft(void);                 // 이전 페이지 화면 출력 (다음 페이지 없음)
int pauseWithRight(void);                // 다음 페이지 화면 출력 (이전 페이지 없음)
void choiceButton(int num);              // 메인 메뉴에서 기능 선택시 버튼 On
void previousPageButton(void);           // 이전 페이지 버튼 On
void nextPageButton(void);               // 다음 페이지 버튼 On
void homePageButton(int check);          // 다음 페이지 버튼 On

// 2. 회원 등록 함수
void case2(FILE *fp, Member_t *id);             // 2. 회원 등록 실행 (회원이 등록되면 maxnum +1)
void inputNewMember(FILE *fp, Member_t *id);    // 새로운 회원 정보를 입력 (Maxnum 증가 여부 반환)
void findMaxStudentNum(Member_t *id, int *maxnum, int *maxstudentnum); // 현재 저장된 학생들 중 가장 큰 학번 검색
int validName(char *str, int key);                           // 입력된 이름 valid 유무 확인
void validNameErrorOn(int key);                              // 잘못된 이름 입력시 에러 메세지 On
void validNameErrorOff(void);                                // 잘못된 이름 입력시 에러 메세지 Off
int validAddress(char *str, int menu);                       // 입력된 주소 valid 유무 확인
void validAddressErrorOn(int menu);                          // 잘못된 주소 입력시 에러 메세지 On
void validAddressErrorOff(void);                             // 잘못된 주소 입력시 에러 메세지 Off
int validCellphone(char a);                                  // 입력된 전화번호 valid 유무 확인
void validCellphoneErrorOn(void);                            // 잘못된 전화번호 입력시 에러 메세지 On
void validCellphoneErrorOff(void);                           // 잘못된 전화번호 입력시 에러 메세지 Off
int repeatCellphone(Member_t *id, char *str, int maxnum);    // 입력된 전화번호 중복 여부 확인
void repeatCellphoneErrorOn(int menu);                       // 잘못된 전화번호 입력시 에러 메세지 On
void repeatCellphoneErrorOff(void);                          // 잘못된 전화번호 입력시 에러 메세지 Off
void closeCase2(void);                                       // 회원 등록 종료 화면 출력
int inputMemberSave(void);                                   // 입력한 회원의 정보 저장 유무 확인
void case2UI(void);                                          // 회원등록 UI
void case2CheckListUI(int menu);                             // 회원등록 유의사항 UI

// 3. 회원 삭제 함수
void deleteMemberInfo(Member_t *id);                         // 3. 회원 삭제 실행 
void case3DeleteSearchOptionUI(void);                        // 회원정보 삭제 중 검색 옵션 UI
int deleteInfo(Member_t *id, int i);                         // 회원 삭제
void deleteLinkedList(Member_t *id, int i);                  // 회원 Linked List 삭제
void deleteCompleteUI(void);                                 // 회원 삭제 UI
void deleteSearchInfoUI(Member_t *id, int i);                // 회원 삭제 중 회원 검색 UI

// 4. 회원 정보 수정 함수
void adjustMemberInfo(Member_t *id);          // 4. 회원 정보 수정 실행
int searchInfoIDnum(Member_t *id, int idnum); // 회원 학번으로 검색 (입력값: idnum은 학번)
int searchStudentID(void);             // 회원 정보 검색 옵션 중 학번 검색
int searchName(char *name);            // 회원 정보 검색 옵션 중 이름 검색
int searchCellphone(char *cellphone);  // 회원 정보 검색 옵션 중 전화번호 검색
void errorSearchChoice(void);          // 회원 정보 검색 시 에러메세지
void searchCancel(void);               // 회원 정보 검색 취소
void validStudentID(char studentID, int *i, int line, int row, int menu);  // 학번 valid Check
void validStudentIDError(int menu);                       // 학번 valid Error On
int inputInfoYesOrNo(int i);                              // 입력정보 선택 여부 확인 (입력값 i: 검색 or 수정 선택 변수)
int searchInfoName(Member_t *id, char *name);             // 회원 이름으로 검색
void case4PrintInfo(Member_t *id, int i);                 // 검색된 회원 정보 출력
int adjustInfo(Member_t *id, int i);                      // 회원 정보 수정
int adjustInfoMenuChoice(void);                           // 회원정보 수정 시 옵션 선택
void adjustCell(int count);                               // 회원정보 수정 시 입력창 출력 (입력값: 에러시 색상 변경)
int insertStudentNum(int line, int row, int menu);        // 학번 입력 및 Valid Check (입력값: 행열을 입력하여 위치를 지정함)
int insertName(int line, int row, char *name, int menu);  // 이름 입력 및 Valid Check
void adjustInfoInputStudentID(Member_t *id, int INDnum, int i); // 수정된 학번 정보를 저장
int repeatStudentIDCheck(Member_t *id, int IDnum);              // 학번 중복 Check
int printSameNameMember(Member_t *id, int *sameName, int j);    // 동일한 이름을 가진 회원 정보 출력
void adjustInfoInputName(Member_t *id, int i);                  // 수정된 이름 정보를 저장
int insertCellphone(int line, int row, char *name, int menu);   // 전화번호 입력 및 valid Check
int searchInfoCellphone(Member_t *id, char *cellphone);         // 전화번호로 검색
void adjustInfoInputAddress(Member_t *id, int i);               // 수정된 주소 정보를 저장
void adjustInfoInputCellphone(Member_t *id, int i);             // 수정된 전화번호 정보를 저장
void case4SearchOptionUI(void);                                 // 회원수정 중 검색 옵션 UI

// 5. 검색 함수
void searchMemberInfo(Member_t *id);          // 5. 회원정보 검색 실행
void case5SearchOptionUI(void);               // 회원정보 검색 옵션 선택 화면
void searchInfo(Member_t *id, int i);          // 회원정보 검색 

// 6. 저장 함수 
void saveFile(FILE *fp, Member_t *id);  // 메모리에 저장되어 있는 내용을 파일로 저장
void fileSaveUI(void);                              // 파일저장 UI

// 7. 종료 함수
int saveCheck(void);                     // 종료 전 파일 저장 유무를 질문 (반환값: 입력여부)
int checkSaveValue(void);             // 파일 저장 유무 시 유저가 입력한 값을 검증
void programCloseUI(void);               // 프로그램 종료 UI

// 기능함수 (consoleFuntion.c)
void gotoxy(int x, int y);               // 입력 커서 위치 조정
void cursorOn(void);                     // 커서 On
void cursorOff(void);                    // 커서 Off
void textColor(int color);               // 글자색 변경
void warningYesOrNo(void);               // Yes 혹은 No를 누르세요 Error 메세지 
void curtainEffect(void);                // 회원정보 검색 시 커튼 화면 효과
void lineClear(void);                    // 한 줄 메세지 제거
void printfAllNodes(Member_t *head);     // Linked List를 이용해서 회원정보 출력
void screenClearUp();                    // 화면 위로 이동
void screenClearDelete();                // 화면 지우개로 지움
int stringComp(char *msg1, char *msg2);