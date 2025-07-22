///////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(once:4996)

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <ctime>
#include "DockingSubjects.h"
#include "msgbox.h"
#include "music.h"
#include "Trans.h"
#include "captcha.h"

#include "ChernobylCRT.h"

#define CP COLOR_PRINT //简化定义

HWND g_hMDIClient, g_hStatusBar, g_hToolBar; //?????目前没用......
static LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_CLOSE:
		if (MessageBox(GetConsoleWindow(), " Unsaved files will not be saved automatically!\nYou can click'Yes(是)'to exit directly, or 'No(否)'to stop from quitting.", " DCO DoCod Working Panel", MB_ICONQUESTION | MB_YESNO) == IDYES)
		{
			Sleep(500);
			DestroyWindow(hwnd);
			break;
		}
		else
		{
			void();
			break;
		}
	case WM_DESTROY:
		Sleep(500);
		PostQuitMessage(0);
		break;
		return true;
	default:
		return DefFrameProc(hwnd, g_hMDIClient, Message, wParam, lParam);
		/*
		* default:
		*	return false; //???better?
		*/
	}
	return 0;
}

static void DSclose()
{
	system("taskkill /F /IM DockingSubjects.exe /fi \"pid gt 0\""); //强制关闭
}

using namespace std;
static void animation() //可做成自定义的
{
	cout << "                                                                                                                              \n\n" << endl;
	cout << "            _/_/_//                       _//       _//                   " << endl;
	cout << "           _//   _//   _/_//     _/_/_// _// _//       _/_/_//     _/_/_//" << endl;
	cout << "          _//   _// _//   _// _//       _/_//     _// _//   _// _//   _// " << endl;
	cout << "         _//   _// _//   _// _//       _// _//   _// _//   _// _//   _//  " << endl;
	cout << "        _/_/_//     _/_//     _/_/_// _//   _// _// _//   _//   _/_/_//   " << endl;
	cout << "                                                                   _//    " << endl;
	cout << "                                                              _/_//      \n" << endl;
	cout << "                                            _/_/_//           _//       _//                       _//               " << endl;
	cout << "                                         _//       _//   _// _/_/_//         _/_//     _/_/_// _/_/_/_//   _/_/_//  " << endl;
	cout << "                                          _/_//   _//   _// _//   _// _// _/_/_/_// _//         _//     _/_//       " << endl;
	cout << "                                             _// _//   _// _//   _// _// _//       _//         _//         _/_//    " << endl;
	cout << "                                      _/_/_//    _/_/_//  _/_/_//   _//   _/_/_//   _/_/_//     _/_// _/_/_//       " << endl;
	cout << "                                                                   _//                                              " << endl;
	cout << "                                                                _//                                                 \n" << endl;
}
/*
using namespace std;
static void DSmainrestart()
{
	clrscr();
	animation();
	cout << " (c) 2025 Corridor DCO  All rights reserved.\n";
	cout << ">>current version:[v 1.0.0.1 -alpha]\n";
	cout << "【Docking Subjects】- A new open source project aims to the subjects lectures and work assistances.-\n";
}
*/
using namespace std;
static void Greetings()
{
	if (MessageBox(GetConsoleWindow(), "    Welcome to CorridorDCO Docking Subjects!\nHere are some basic tips you should know:\n  1.This program is for studing and working assistance, nobody is allowed to use this program to do illegal activities.\n  2. \n    Do you agree with the basic tips above? You could only use this program after you agreed with the tips."
		, "Helps", MB_HELP | MB_SYSTEMMODAL | MB_YESNO) == IDYES)
	{
		void();
	}
	else if (IDNO)
	{
		if (MessageBox(GetConsoleWindow(), "Sorry, you can not use Docking Subjects without agreeing the basic tips.", "Docking Subjects notice",
			MB_SYSTEMMODAL | MB_OK | MB_ICONERROR) == IDOK)
		{
			DSclose();
		}
	}
	///*
	else if (IDHELP)
	{
		MessageBox(0, "Sorry, you can not use Docking Subjects without agreeing the basic tips.", "Docking Subjects notice", MB_OK);
		DSclose();
	}
	//*/
	else
	{
		0; // ???WTF???
	}
}

static void MAINTEST() //MCK
{
	cout << "\n\n<DS service\\>\n//DS-test below//\n" << endl;
	version();
	cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//capital letters
	cout << "=.,-_ +/?\\'\";:()[]{}|!@#$%^&*`~";//punctuations
	cout << "abcdefghijklmnopqrstuvwxyz" << endl;//lowercase letters
	CP("█▓ ██", bai); CP("█▓ ██", 0); CP("█▓ ██", 1); CP("█▓ ██", 2); CP("█▓ ██", 3); CP("█▓ ██", 4); CP("█▓ ██", 5); CP("█▓ ██\n", 6);
	CP("█▓ ██", 8); CP("█▓ ██", 9); CP("█▓ ██", 10); CP("█▓ ██", 11); CP("█▓ ██", 12); CP("█▓ ██", 13); CP("█▓ ██", 14); CP("█▓ ██\n", 15);
	cout << "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ\n";//Rus uppercaseletters
	cout << "абвгдеёжзийклмнопрстуфхцчшщъыьэюя\n";//Rus lowercaseletters
	cout << "\n</DS-test>\n\n" << endl;
}

/*
MyStruct MyProc1()
{
MyStruct l_mystruct;
l_mystruct.x = 1;
l_mystruct.y = 2;
return l_mystruct;
}
//调用
MyStruct myStruct = MyProc1();
*/
using namespace std;
static void DShelps()
{
    /*
	0 = 黑色 1 = 蓝色 2 = 绿色 3 = 浅绿色 4 = 红色 5 = 紫色 6 = 黄色 7 = 白色 //firstone,before black block.
	8 = 灰色 9 = 淡蓝色 10 = 淡绿色 11 = 淡浅绿色 12 = 淡红色 13 = 淡紫色 14 = 淡黄色 15 = 亮白色
	*/
	cout << "\n  ===---------------------------------------------------------------------===" << endl;
	cout << "  |------------------------------"; COLOR_PRINT("GRAMMAR HELPS",6); cout << "------------------------------| " << endl;
	cout << "  |-------------------------------------------------------------------------|" << endl;
	cout << "  |_List_|_Command1--->Comd2--->Comd3--->Comd4__|__________Effects__________|" << endl;
	cout << "  |  0.  |                back                  |        back to HOME       |" << endl;
	cout << "  |------|--------------------------------------|---------------------------|" << endl;
	cout << "  |  1.  |   /cls        *        *        *    |        clean screen       |" << endl;
	cout << "  |  2.  |   /cmd        *        *        *    |      start cmd prompt     |" << endl;
	cout << "  |  2.  |   /check     MCK       *        *    |     simple check for DS   |" << endl;
	cout << "  |  2.  |    ~     MSGbeeptest   *        *    |      beep sound test      |" << endl;
	cout << "  |------|--------------------------------------|---------------------------|" << endl;
	cout << "  |  3.  |   /DS       close     -c        *    |    cancel close process   |" << endl;
	cout << "  |      |    ~          ~       -f        *    |       close forcibly      |" << endl;
	cout << "  |      |    ~          ~       -s        *    | close with saving inquiry |" << endl;
	cout << "  |  4.  |   /DS      restart     *        *    |         restart DS        |" << endl;
	cout << "  |  5.  |   /DS       /tree      *        *    |   list file paths of DS   |" << endl;
	cout << "  |  5.  |   /DS     /settines    *        *    |       change settings     |" << endl;
	cout << "  |      |    ~          ~     Language    *    |  add or change languages  |" << endl;
	cout << "  |      |    ~          ~      Animn      *    |     add or change anims   |" << endl;
	cout << "  |------|--------------------------------------|---------------------------|" << endl;
	cout << "  |  6.  | /docking     cls                     |        clean screen       |" << endl;
	cout << "  |      | /docking                        *    |                           |" << endl;
	cout << "  |      |    ~          ~                 *    |                           |" << endl;
	cout << "  |      |    ~          ~                 *    |                           |" << endl;
	cout << "  |      |    ~          ~                 *    |                           |" << endl;
	cout << "  |------|--------------------------------------|---------------------------|" << endl;
	cout << "  |  7.  |  /str   DSmain-license *        *    |  show the DSmain license  |" << endl;
	cout << "  |      |  /str        ini      help      *    |     see helps for ini     |" << endl;
	cout << "  |      |    ~          ~     path.to  ($path) | open files in text format |" << endl;
	cout << "  |      |    ~          ~                 *    |                           |" << endl;
	cout << "  |------|--------------------------------------|---------------------------|" << endl;
	cout << "  |  8.  |  time         *        *        *    |     show current time     |" << endl;
	cout << "  |------|--------------------------------------|---------------------------|" << endl;
	cout << "  |  9.  |    ~          ~                 *    |                           |" << endl;
	cout << "  |      |    ~          ~                 *    |                           |" << endl;
	cout << "  |      |    ~          ~                 *    |                           |" << endl;
	cout << "  |-------------------------------------------------------------------------|" << endl;//end
	cout << "  ===---------------------------------------------------------------------===" << endl;

}

static bool fileExists(const std::string& filename)
{
	std::ifstream file(filename);
	return file.good();
}

using namespace std;//////////////////////////////////////
int main()
{
looprestart:
	time_t now = time(0); // time，date
	tm time = *localtime(&now);//(&now)
	int year = time.tm_year + 1900;
	int month = time.tm_mon + 1;
	int day = time.tm_mday;
	int hour = time.tm_hour;
	int min = time.tm_min;
	int sec = time.tm_sec;

	//setlocale(LC_CTYPE, "ru_RU.UTF-8");
	int lgc{}, lgc2{};
	int resr = 0, lgc3 = 0, settings = 0, errors = 0, arrange = 0;
	clrscr();
	animation();
	//version();
	Sleep(200);
	system("color f7"); Sleep(70); system("color 0f"); Sleep(70); system("color f7"); Sleep(70);
	system("color 0f"); Sleep(1700); system("color f7"); Sleep(150);
	system("color 0f");
	Greetings();
	system("title Docking Subjects [main]");
	cout << " (c) 2025 Corridor DCO  All rights reserved.\n";
	cout << ">>current version: [*unknown]\n";
	cout << "【Docking Subjects】- A new open source project aims to the subjects lectures and work assistances.-\n";
	 //cout << ">>start time: " << Ftm << endl; //printf(">>start time:%4d.%02d.%02d %3d:%02d:%02d\n", year, month, day, hour, min, sec); // time
	cout << ">>language: *unknown\n" << endl;
	
	//////////////////////////////////

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hConsole, &mode);
	SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	Sleep(500);
	if (!CaptchaSystem::CaptchaVerifier::executeVerification())
	{
		std::cerr << "Failed to identify. This program has been forcibly quitted.";
		Sleep(1200);
		return -1;
	}

	Sleep(900);
	clrscr();
	animation();
	system("title Docking Subjects [main]");
	cout << " (c) 2025 Corridor DCO  All rights reserved.\n";
	cout << ">>current version:"; version();
	cout << "【Docking Subjects】- A new open source project aims to the subjects lectures and work assistances.-\n";
	//cout << ">>start time: " << Ftm << endl; //printf(">>start time:%4d.%02d.%02d %3d:%02d:%02d\n", year, month, day, hour, min, sec); // time
	cout << ">>language: *unknown\n" << endl;
	//////////////////////////////////

	Sleep(650);
	cout << "Language Setting" << endl;
	gotoxy(0, 26);
	CP("English (BrE)", 6); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Japanese (日本語)", 8); cout << "" << endl; //Russian (Русский)
	while (1)
	{
		char c = _getch(); // 读取键盘输入的第一个字符
		if (c == '\xE0') // 如果是特殊字符（如箭头键）
		{
			c = _getch(); // 继续读取下一个字符
			if (c == 'H') // 上箭头键 (ASCII 码为 72)
			{
				arrange = arrange - 1;
				if (arrange < 0)
				{
					arrange = 3;
				}
			}
			else if (c == 'P') // 下箭头键 (ASCII 码为 80)
			{
				arrange = arrange + 1;
				if (arrange > 3)
				{
					arrange = 0;
				}
			}
			else if (c == 'K') // 左箭头键 (ASCII 码为 75)
			{
				lgc = lgc - 1;
				if (lgc < 0)
				{
					lgc = 2;
				}
			}
			else if (c == 'M') // 右箭头键 (ASCII 码为 77)
			{
				lgc = lgc + 1;
				if (lgc > 2)
				{
					lgc = 0;
				}
			}
		}
		else if (c == '\r')// '\r' (13/10)
		{
			resr = lgc;
			clrscr();
			animation();
			break;
		}
		if (lgc == 0) //判定
		{
			gotoxy(0, 26);
			CP("English (BrE)", 6); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Japanese (日本語)", 8); cout << "" << endl;
			//return lgc = 0;
		}
		else if (lgc == 1)
		{
			gotoxy(0, 26);
			CP("English (BrE)", 8); cout << "    "; CP("Chinese (简体中文)", 6); cout << "    "; CP("Japanese (日本語)", 8); cout << "" << endl;
			//return lgc = 1;
		}
		else if (lgc == 2)
		{
			gotoxy(0, 26);
			CP("English (BrE)", 8); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Japanese (日本語)", 6); cout << "" << endl;
			//return lgc = 2;
		}
	}

	BMchecknotice(lgc);

	std::string checklist = ".//R.15_Bsm.ic_direct//R.15_ic_checklist.txt";// Files check.//compare with another file
	//std::string checkLog = ".//log//checkLog.txt";
	if (!fileExists(checklist))//edit filename below
	{
		msgfilecheck();
		BMcheckreport(lgc);
		//////////给弹窗做不同语言版本
		if (MessageBox(GetConsoleWindow(), "Your program [Docking Subjects] is incomplete, do you want to repair it?\n You can click (Yes) to repair, or click (No) to start this incomplete program with some unexpected errors.", "Program Incomplete warning", MB_ICONWARNING | MB_YESNO) == IDYES)
		{
			msgrepairask();
			if (MessageBox(GetConsoleWindow(), "Do you want to open the webpage now?", "Webpage opening inqiry", MB_YESNO) == IDYES) //⬅ What is the help? (MB_HELP)***=== == __ +++ ++ ~~
			{
				msgopenwebpageask();
			}
			else
			{
				cout << "\n\n\n\n            [DockingSubjects.interrupted.]\n\n\n\n\n\n" << endl;
			}
		}
		else
		{
			CHECKFAILEDtitle(lgc);
			logfilecheck1();
			goto loop;
		}
	}
	else ////////////////////////////////////////////////////////////////////////////////////////////////////////
	{
		CHECKCOMPLETEtitle(lgc);
		
		if (1) //不得已而为之， goto loop初始化...
		{
			logfilestartsecurelynotice();
		}
		Sleep(1000);
	loop: //*****
		char inputone[200];
		char inputtwo[200];
		char inputthree[200];
		char input1[200];
		char input2[200];
		char input3[200];
		char inputdir[200];
		char inputnote[200]{};
		char inputNT[200]{};
		char body[5000]{};

		IO1goto(lgc);
		FreshTime();
		Translang(lgc);
		dspromptstartnotice();

	    loopback:
		while (1)
		{
			printf("<\\Docking_Subjects:>_");
			scanf("%s", input1);
			strncpy(inputone, input1, 200);
			if (strcmp(inputone, "/docking") == 0) //*****DOCKING_SUBJECTS***** 接口
			{
				cout << ">>[Docking_Subjects]docking>>";
				while (1)
				{
					printf(">_docking_"); //for() ?
					scanf("%s", input2);
					strncpy(inputtwo, input2, 200);
					if (strcmp(inputtwo, "***dll***") == 0)//dlls
					{
						cout << "\n	   [>>docking>.returned_back]\n" << endl;
						//dlls.
					}
					else if (strcmp(inputtwo, "back") == 0)
					{
						cout << "\n	   [>>docking>.returned_back]\n" << endl;
						break;
						//goto loopback; //用于多次break
					}
					else
					{
						incorrectinput(lgc);
					}
					// for est, otheruse.
				}
			} //**********
			else if (strcmp(inputone, "/DS") == 0)
			{
				cout << ">>[Docking_Subjects]system control>>";
				while (1)
				{
					printf(">_DSctrl_");
					scanf("%s", input2);
					strncpy(inputtwo, input2, 200);
					if (strcmp(inputtwo, "restart") == 0)
					{
						clrscr();
						cout << "\n\n    [Docking_Subjects].restarting...\n" << endl;
						Sleep(1000);
						clrscr(); //原谅我不会做动画
						ofstream ofsLog;
						ofsLog.open(".//log//checkLog.txt", ios::app);
						ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
						ofsLog << "action: restart." << endl;
						ofsLog << "-↓↓↓----restart----↓↓↓-" << endl; //上下怎么摆
						ofsLog.close();
						clrscr();
						goto looprestart;
					}
					else if (strcmp(inputtwo, "settings") == 0)
					{
						printf("\n");
						printf(">_DSctrl_settings_");
						CP("\n    HELP", 6);
						cout << "\n*Language -> To change language.\n";
						cout << "*Anim -> To change your Greeting Animation.\n" << endl;
						int CUX, CUY, USY;
						scanf("%s", input3);
						strncpy(inputthree, input3, 200);
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						COORD coordScreen = { 0, 0 }; //光标位置
						CONSOLE_SCREEN_BUFFER_INFO csbi{};
						if (strcmp(inputthree, "Language") == 0)
						{
							int USYa;
							USYa = csbi.dwCursorPosition.Y - 1;
							cout << "Language Setting" << endl;
							if (lgc == 0)
							{
								gotoxy(0, USYa);
								CP("English (BrE)", 6); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Japanese (日本語)", 8); cout << "" << endl;
							}
							else if (lgc == 1)
							{
								gotoxy(0, USYa);
								CP("English (BrE)", 8); cout << "    "; CP("Chinese (简体中文)", 6); cout << "    "; CP("Japanese (日本語)", 8); cout << "" << endl;
							}
							else if (lgc == 2)
							{
								gotoxy(0, USYa);
								CP("English (BrE)", 8); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Japanese (日本語)", 6); cout << "" << endl;
							}
							while (1)
							{
								char c = _getch();
								if (c == '\xE0')
								{
									c = _getch();
									if (c == 'K')
									{
										lgc = lgc - 1;
										if (lgc < 0)
										{
											lgc = 2;
										}
									}
									else if (c == 'M')
									{
										lgc = lgc + 1;
										if (lgc > 2)
										{
											lgc = 0;
										}
									}
								}
								else if (c == '\r')
								{
									resr = lgc;
									clrscr();
									animation();
									break;
								}
								if (GetConsoleScreenBufferInfo(hConsole, &csbi))
								{
									CUX = csbi.dwCursorPosition.X;
									CUY = csbi.dwCursorPosition.Y;
									USY = CUY - 1;
									if (lgc == 0)
									{
										gotoxy(0, USY);
										CP("English (BrE)", 6); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Japanese (日本語)", 8); cout << "" << endl;
									}
									else if (lgc == 1)
									{
										gotoxy(0, USY);
										CP("English (BrE)", 8); cout << "    "; CP("Chinese (简体中文)", 6); cout << "    "; CP("Japanese (日本語)", 8); cout << "" << endl;
									}
									else if (lgc == 2)
									{
										gotoxy(0, USY);
										CP("English (BrE)", 8); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Japanese (日本語)", 6); cout << "" << endl;
									}
								}
								else
								{
									MessageBox(GetConsoleWindow(), "An unexpected error has been occurred when getting the current cursor position.\n ERROR: 1x000002-RF", "Error!", MB_ICONWARNING | MB_OK);//Russian
									clrscr();
									animation();
									IO1(lgc);
									goto loopback;
								}
							}
							if (lgc == 0)
							{
								MessageBox(NULL, "You have changed you display language to 【ENGLISH】\n    >Refresh to apply<", "Language setting", MB_OK);
							}
							else if (lgc == 1)
							{
								MessageBox(NULL, "您已将显示语言更改为【简体中文】\n    >刷新以应用<", "Language setting", MB_OK);
							}
							else if (lgc == 2)
							{
								MessageBox(NULL, "表示言語を【日本語】に変更しました\n    >アプリを更新する<", "Language setting", MB_OK);//Russian
							}
							clrscr();
							animation();
							IO1goto(lgc);
							FreshTime();
							Translang(lgc);
							cout << "\n>>You can also enter \"/cls\" to refresh and apply your settings.\n" << endl;
						}
						else if (strcmp(inputthree, "Animn") == 0)
						{
							void();
						}
						else
						{
							incorrectinput(lgc);
						}
					}
					else if (strcmp(inputtwo, "close") == 0)// /DS-close
					{
						//cout helps
						while (1)
						{
							printf("\n");
							printf(">_DSctrl_close_");
							scanf("%s", input3);
							strncpy(inputthree, input3, 200);
							if (strcmp(inputthree, "-f") == 0)
							{
								cout << "\n    >>This program has been forcibly closed, No files will be saved.\n" << endl;
								Sleep(1000);
								DSclose(); //硬关闭
							}
							else if (strcmp(inputthree, "-s") == 0)
							{
								if (MessageBox(GetConsoleWindow(), "Your files and works have not been saved\n    Do you want to save them?", "Save inquiry", MB_YESNOCANCEL | MB_ICONQUESTION) == IDCANCEL)
								{
									goto loopback;
								}
								else if (IDNO)
								{
									Sleep(1100);
									PostQuitMessage(0); //软关闭。
								}
								else if (IDYES)
								{
									//cout << "saved~~~\n";   //写cout提示！！！
									Sleep(1000);
									PostQuitMessage(0);
								}
								Sleep(1000);
								DSclose();
							}
							else if (strcmp(inputthree, "-c") == 0)
							{
								cout << "\n	   [>>DSctrl>close>.returned_back]\n" << endl;
								goto loopback;
							}
							else
							{
								incorrectinput(lgc);
							}
							break;
						}
					}
					else if (strcmp(inputtwo, "/tree") == 0)
					{
						cout << "***" << endl;
						system("tree");
					}
					else if (strcmp(inputtwo, "back") == 0)
					{
						cout << "\n	   [>>DSctrl>.returned_back]\n" << endl;
						goto loopback;
					}
					else
					{
						incorrectinput(lgc);
					}
					break;
				}
			}
			else if (strcmp(inputone, "/wrt") == 0) //写入
			{
				cout << ">>[Docking_Subjects]write>>";
				while (1)
				{
					printf(">_start_"); //for() ?
					scanf("%s", input2);
					strncpy(inputtwo, input2, 200);
					if (strcmp(inputtwo, "back") == 0)
					{
						cout << "\n	   [>>write>.returned_back]\n" << endl;
						goto loopback;
					}
			        else if (strcmp(inputtwo, "help") == 0) // /str-ini-help
					{
						void();
					}
					else if (strcmp(inputtwo, "notebook") == 0) //SHIT//SHIT//SHIT//SHIT//SHIT//SHIT//SHIT//SHIT////////
					{
						cout << "\nWrite down what you would like to write! The first must be space now...\n" << endl;
						
						while (1)
						{
							//printf("  Path:"); //for() ?
						    //scanf("%s", inputnote);
						    //strncpy(inputnote, inputNT, 200);
							FILE* fp;
							char ch;
							//判断文件是否成功打开
							if ((fp = fopen(".//demo.txt", "wt+")) == NULL)
							{
								printf("Cannot open file, press any key to exit!\n");
								getch();
								exit(1);
							}
							printf("Input a string:\n");
							getchar();
							//每次从键盘读取一个字符并写入文件
							while ((ch = getchar()) != '\n')
							{
								fputc(ch, fp);
							}
							fclose(fp);
							getchar();
						}
					}
					else
					{
						incorrectinput(lgc);
					}
				}
			}
			else if (strcmp(inputone, "/str") == 0) //打开
			{
				cout << ">>[Docking_Subjects]start>>";
				while (1)
				{
				loopstr:
					printf(">_start_"); //for() ?
					scanf("%s", input2);
					strncpy(inputtwo, input2, 200);
					if (strcmp(inputtwo, "back") == 0)
					{
						cout << "\n	   [>>start>.returned_back]\n" << endl;
						goto loopback;
					}
					else if (strcmp(inputtwo, "DSmain-license") == 0)
					{
						std::ifstream file;
						file.open(".//license//DSmain-license.txt", std::ios::in); // 使用输入模式打开文件 //  %s???
						if (!file)
						{
							incorrectpath(lgc);
							goto loopstr;
						}// 文件读取操作
						cout << "\n";
						std::string line;
						while (std::getline(file, line))/////////////////////////
						{
							std::cout << line << std::endl;
						}
						file.close(); // 关闭文件
						goto loopstr;
					}
					else if (strcmp(inputtwo, "ini") == 0) // dll接口！
					{
						while (1)
						{
							printf(">_start_ini_"); //安装插件，修改direct目录的.(.txt)
							scanf("%s", input3);
							strncpy(inputthree, input3, 200);
							if (strcmp(inputthree, "back") == 0) // /str-ini-back
							{
								cout << "\n	   [>>start>ini>.returned_back]\n" << endl;
								goto loopback;
							}
							else if (strcmp(inputthree, "help") == 0) // /str-ini-help
							{
								void();
							}
							else if (strcmp(inputthree, "path.to") == 0) // /str-ini-path
							{
								cout << ">dir_path_to_";
								scanf("%s", inputdir); //add inputdir2
								std::ifstream file; //add check files inquiries.
								file.open(inputdir, std::ios::in);
								if (!file)
								{
									std::cerr << ">>failed to open this file." << std::endl;
									std::cerr << ">>please check if your file path is correct." << std::endl;
									goto loopstr;
								}
								cout << "\n";
								std::string line;
								while (std::getline(file, line)) //以行为变量
								{
									std::cout << line << std::endl; //check if line =... ,then ... .
								}
								file.close();
								goto loopstr;
							}
							else if (strcmp(inputthree, "1") == 0) //?
							{
								void();
							}
							else if (strcmp(inputthree, "2") == 0) //?
							{
								void();
							}
							else
							{
								incorrectinput(lgc);
							}
							break;
						}
					}
					else if (strcmp(inputtwo, "back") == 0)
					{
						cout << "\n	   [>>DSctrl>.returned_back]\n" << endl;
						goto loopback;
					}
					else
					{
						incorrectinput(lgc);
					}
					break;
				}
			}
			else if (strcmp(inputone, "/time") == 0)
			{
				
				cout << "\n    ";
				FreshTime();// Plan 1
				//printf("\n>>current time:%4d.%02d.%02d. %3d:%02d:%02d\n", year, month, day, hour, min, sec); // Plan 2 !大bug!//////////////////////////时间无法改变！！！////////////
				cout << "\n";
            }
			else if (strcmp(inputone, "/cls") == 0)
			{
				clrscr();
				animation();
				system("color f7"); Sleep(50); system("color 0f");
				IO1goto(lgc);
				FreshTime(); // printf(">>start time:%4d.%02d.%02d %3d:%02d:%02d\n", year, month, day, hour, min, sec); // time
				Translang(lgc);
			}
			else if (strcmp(inputone, "/cmd") == 0)//*****************
			{
				cout << "\n\n	>>You can always enter \"DCO\" or \"dost\" to start DCO_DS.\n" << endl;
				ofstream ofsLog;
				ofsLog.open(".//log//checkLog.txt", ios::app);
				ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
				ofsLog << "action: start windows cmd prompt" << endl;
				ofsLog << "-----------------------" << endl; //是不是可以去掉<<endl然后再开头加\n，下一次直接接在后面
				ofsLog.close();
				system("cmd");
			}
			else if (strcmp(inputone, "8") == 0)//*****************////////to be deleted///////////////////////////
			{                                   //*****************////////to be deleted///////////////////////////
				clrscr();
				gotoxy(25, 15);
				CP("It seems that you've found the developer mode. :>\n",2);//void();  //......
				CP("test", 2);
				Sleep(1000);
                #include "wavfreq.h"/////////顶头？
				Beep(mi1, point);
				Sleep(1000);
				cout << "Chernobyl CRT simulator" << endl;
				if (MessageBox(NULL, "TEST, START? \n    now is in English, I will make the Russian version when I got how to resolve the Russian print problem...", "Your are the operator.", MB_YESNO) == IDYES)
				{
					system("color 7f");
					clrscr();
					Beep(mi1, pad);
					system("color 80");
					Sleep(1000);
					cout << "\n\n        You know you are the best...";
					Sleep(2000);
					clrscr();
					system("color 0f");
					Sleep(500);
					CRTsim();
				}
				else
				{
					CP("okay", huang);
				}

				clrscr();
				goto looprestart;
			}
			//announcement??
			else if (strcmp(inputone, "/help") == 0)
			{
				DShelps(); //helps
				cout << "\n\n    You can press arrow keys to select and try other ways for help." << endl;
				cout << "You can also press other keys(except \"enter\") key to escape and continue:\n" << endl;
				int CUX2, CUY2, USY2;
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				COORD coordScreen = { 0, 0 }; //光标位置
				CONSOLE_SCREEN_BUFFER_INFO csbi2{};
				lgc2 = 4;
				CP("*Download Up-to-date version", 8); cout << "  "; CP("*Visit official website", 8); cout << "  "; CP("*Check detailed user guide", 8); cout << "  "; CP("*use cyber motto to encorage you", 8); cout << "\n"; CP("[EXIT]", 2);
				while (1)
				{
					char c2 = _getch(); // 读取键盘输入的第一个字符
					if (c2 == '\xE0') // 如果是特殊字符（如箭头键）
					{
						c2 = _getch(); // 继续读取下一个字符
						if (c2 == 'K') // 左箭头键 (ASCII 码为 75)
						{
							lgc2 = lgc2 - 1;
							if (lgc2 < 0)
							{
								lgc2 = 4;
							}
						}
						else if (c2 == 'M') // 右箭头键 (ASCII 码为 77)
						{
							lgc2 = lgc2 + 1;
							if (lgc2 > 4)
							{
								lgc2 = 0;
							}
						}
					}
					else if (c2 == '\r')// '\r' (13/10)
					{
						break;
					}
					else if (c2 != ('\r' | 'M' | 'K'))
					{
						cout << "\n\n";
						goto loopback;
					}
					if (GetConsoleScreenBufferInfo(hConsole, &csbi2))
					{
						CUX2 = csbi2.dwCursorPosition.X;
						CUY2 = csbi2.dwCursorPosition.Y;
						USY2 = CUY2 - 1;//
						//printf("光标坐标:(%d,%d)\n", csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
						if (lgc2 == 0) //判定
						{
							gotoxy(0, USY2);
							CP("*Download Up-to-date version", 6); cout << "  "; CP("*Visit official website", 8); cout << "  "; CP("*Check detailed user guide", 8); cout << "  "; CP("*use cyber motto to encorage you", 8); cout << "\n"; CP("[EXIT]", 8);
						}
						else if (lgc2 == 1)
						{
							gotoxy(0, USY2);
							CP("*Download Up-to-date version", 8); cout << "  "; CP("*Visit official website", 6); cout << "  "; CP("*Check detailed user guide", 8); cout << "  "; CP("*use cyber motto to encorage you", 8); cout << "\n"; CP("[EXIT]", 8);
						}
						else if (lgc2 == 2)
						{
							gotoxy(0, USY2);
							CP("*Download Up-to-date version", 8); cout << "  "; CP("*Visit official website", 8); cout << "  "; CP("*Check detailed user guide", 6); cout << "  "; CP("*use cyber motto to encorage you", 8); cout << "\n"; CP("[EXIT]", 8);
						}
						else if (lgc2 == 3)
						{
							gotoxy(0, USY2);
							CP("*Download Up-to-date version", 8); cout << "  "; CP("*Visit official website", 8); cout << "  "; CP("*Check detailed user guide", 8); cout << "  "; CP("*use cyber motto to encorage you", 6); cout << "\n"; CP("[EXIT]", 8);
						}
						else if (lgc2 == 4)
						{
							gotoxy(0, USY2);
							CP("*Download Up-to-date version", 8); cout << "  "; CP("*Visit official website", 8); cout << "  "; CP("*Check detailed user guide", 8); cout << "  "; CP("*use cyber motto to encorage you", 8); cout << "\n"; CP("[EXIT]", 2);
						}
					}
					else
					{
						MessageBox(GetConsoleWindow(), "An unexpected error has been occurred when getting the current cursor position.\n ERROR: 1x000002-RF", "Error!", MB_ICONWARNING | MB_OK);//Russian
						clrscr();
						animation();
						IO1(lgc);
						goto loopback;
					}
				}
				// midtrans1(lgc2)
				if (lgc2 == 0)
				{
					cout << ">>WebDownloader starting...\n";
					Sleep(100);
					WinExec(".//mtneINIs//DCODownloader.exe", SW_SHOW);
				}
				else if (lgc2 == 1)
				{
					cout << ">>Linging to official website...\n";
					WinExec(".//mtneINIs//fix_webpage.exe", SW_HIDE);
				}
				else if (lgc2 == 2)
				{
					cout << ">>User_Guide starting...\n";
					WinExec(".//dshelpsfile//DS_userguide.chm", SW_SHOW);//NOT EXISTED YET
				}
				else if (lgc2 == 3)
				{
					MessageBox(NULL, "CYBER MOTTOS!!!", "€￥b⁅R_M〇tτO$", MB_OK);//Russian
					WinExec(".//Cyber Motto.exe", SW_HIDE);
				}
				else if (lgc2 == 4)
				{
					lgc2 = 0;
				}
				cout << "" << endl;
			}
			else if (strcmp(inputone, "/version") == 0)
			{
				cout << "\n    Current version: "; version(); cout << "\n";
			}
			else if (strcmp(inputone, "/check") == 0)
			{
				printf(">_DScheck_");
				scanf("%s", input2);
				strncpy(inputtwo, input2, 200);
				if (strcmp(inputtwo, "MSGbeeptest") == 0)//能否调用其他声音，例如.wav波形文件？
				{
					MessageBeep(MB_OK);
					Sleep(1000);
					MessageBeep(MB_ICONQUESTION);
					Sleep(1000);
					MessageBeep(MB_ICONHAND);
					Sleep(1000);
					MessageBeep(MB_ICONEXCLAMATION);
					continue;//???
				}
				else if (strcmp(inputtwo, "MCK") == 0)
				{
					MAINTEST(); //helps //在每一种内加一个
				}
			}
			else
			{
				incorrectinput(lgc);
			}
		}
	}
	//exitloop:
	cout << "\nIf you want to exit, please press \"Enter\" key.\n";
	//system("pause");
	while (!(GetAsyncKeyState(VK_RETURN) & 0x8000))
	{
		printf("Detected that you pressed the Enter key, the program has exited!\n");
		Sleep(800);
		return 0;
	}// 检测Enter键是否按下
	return 0;
}
//做中文插件
//调用蓝屏dll