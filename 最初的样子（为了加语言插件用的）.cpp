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
#include <ctime>
#include "DockingSubjects.h"

#define CP COLOR_PRINT //简化定义

static void DSclose()
{
	system("taskkill /F /IM DockingSubjects.exe /fi \"pid gt 0\""); //强制关闭
}

using namespace std;
static void animation() //可做成自定义的
{
	cout << "                                                                                                                        \n\n" << endl;
	cout << "             _/_/_//                       _//       _//                   " << endl;
	cout << "            _//   _//   _/_//     _/_/_// _// _//       _/_/_//     _/_/_//" << endl;
	cout << "           _//   _// _//   _// _//       _/_//     _// _//   _// _//   _// " << endl;
	cout << "          _//   _// _//   _// _//       _// _//   _// _//   _// _//   _//  " << endl;
	cout << "         _/_/_//     _/_//     _/_/_// _//   _// _// _//   _//   _/_/_//   " << endl;
	cout << "                                                                    _//    " << endl;
	cout << "                                                               _/_//      \n" << endl;
	cout << "                                             _/_/_//           _//       _//                       _//               " << endl;
	cout << "                                          _//       _//   _// _/_/_//         _/_//     _/_/_// _/_/_/_//   _/_/_//  " << endl;
	cout << "                                           _/_//   _//   _// _//   _// _// _/_/_/_// _//         _//     _/_//       " << endl;
	cout << "                                              _// _//   _// _//   _// _// _//       _//         _//         _/_//    " << endl;
	cout << "                                       _/_/_//    _/_/_//  _/_/_//   _//   _/_/_//   _/_/_//     _/_// _/_/_//       " << endl;
	cout << "                                                                    _//                                              " << endl;
	cout << "                                                                 _//                                                 \n" << endl;
}
using namespace std;
static void DSmainrestart()
{
	clrscr();
	animation();
	cout << " (c) 2025 Corridor DCO  All rights reserved.\n";
	cout << ">>current version:[v 1.0.0.1 -alpha]\n";
	cout << "【Docking Subjects】- A new open source project aims to the subjects lectures and work assistances.-\n";
}
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
	cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//capital letters
	cout << "=.,-_ +/?\\'\";:()[]{}|!@#$%^&*`~";//punctuations
	cout << "abcdefghijklmnopqrstuvwxyz" << endl;//lowercase letters
	CP("█▓ ", bai); CP("█▓ ", 0); CP("█▓ ", 1); CP("█▓ ", 2); CP("█▓ ", 3); CP("█▓ ", 4); CP("█▓ ", 5); CP("█▓ \n", 6);
	CP("█▓ ", 8); CP("█▓ ", 9); CP("█▓ ", 10); CP("█▓ ", 11); CP("█▓ ", 12); CP("█▓ ", 13); CP("█▓ ", 14); CP("█▓ \n", 15);
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
	//////////////////////////////////////////逻辑运算部分/////////////////////////////(还得放到dll里面)
    // 分开放呢???↑
	// 
	//////////////////////////////////////////逻辑运算部分/////////////////////////////
static bool fileExists(const std::string& filename)
{
	std::ifstream file(filename);
	return file.good();
}

using namespace std;
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
	int lgc{};

	clrscr();
	animation();
	Sleep(200);
	system("color f7"); Sleep(70); system("color 0f"); Sleep(70); system("color f7"); Sleep(70);
	system("color 0f"); Sleep(1700); system("color f7"); Sleep(150);
	system("color 0f");

	int resr = 0, lgc2 = 0, lgc3 = 0, settings = 0, errors = 0, arrange = 0;
	cout << "Language Setting" << endl;
	gotoxy(0, 20);
	CP("English (BrE)", 6); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Russian (Русский)", 8); cout << "こにちわ test" << endl;
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
			break;
		}
		if (lgc == 0) //判定
		{
			gotoxy(0, 20);
			CP("English (BrE)", 6); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Russian (Русский)", 8); cout << "" << endl;
			//return lgc = 0;
		}
		else if (lgc == 1)
		{
			gotoxy(0, 20);
			CP("English (BrE)", 8); cout << "    "; CP("Chinese (简体中文)", 6); cout << "    "; CP("Russian (Русский)", 8); cout << "" << endl;
			//return lgc = 1;
		}
		else if (lgc == 2)
		{
			gotoxy(0, 20);
			CP("English (BrE)", 8); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Russian (Русский)", 6); cout << "" << endl;
			//return lgc = 2;
		}
	}
	if (lgc == 0)
	{
		MessageBox(NULL,"English", "0", MB_OK);
	}
	else if (lgc == 1)
	{
		MessageBox(NULL, "Chinese", "1", MB_OK);
	}
	else if (lgc == 2)
	{
		MessageBox(NULL, "Russian", "2", MB_OK);
	}

	clrscr();
	animation();

	Greetings();
	
	system("title Docking Subjects [main]");
	cout << " (c) 2025 Corridor DCO  All rights reserved.\n";
	cout << ">>current version:[v 1.0.0.1 -alpha]\n";
	cout << "【Docking Subjects】- A new open source project aims to the subjects lectures and work assistances.-\n";
	printf(">>start time:%4d.%02d.%02d %3d:%02d:%02d\n", year, month, day, hour, min, sec); // time
	cout << ">>language: *unknown" << endl;
	Sleep(650);
	cout << ">>BasicModule_Check.processing...\n";
	
	std::string checklist = ".//R.15_Bsm.ic_direct//R.15_ic_checklist.txt";// Files check.//compare with another file
	//std::string checkLog = ".//log//checkLog.txt";
	if (!fileExists(checklist))//edit filename below
	{
		ofstream ofsLog;
		ofsLog.open(".//log//checkLog.txt", ios::app);
		ofsLog << "\n(x)====---=ERROR=---====" << endl;
		ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
		ofsLog << "error: Start with the INCOMPLETE BasicModual!" << endl;
		ofsLog << "-----------------------" << endl;
		ofsLog.close();
		
		cout << "\n>>!Incomplete BasicModules[version: R015b.ic]!" << endl;
		if (MessageBox(GetConsoleWindow(), "Your program [Docking Subjects] is incomplete, do you want to repair it?\n You can click (Yes) to repair, or click (No) to start this incomplete program with some unexpected errors.", "Program Incomplete warning", MB_ICONWARNING | MB_YESNO) == IDYES)
		{
			ofstream ofsLog;
			ofsLog.open(".//log//checkLog.txt", ios::app);
			ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
			ofsLog << "action: start with repairing intention." << endl;
			ofsLog << "-----------------------" << endl;
			ofsLog.close();

			MessageBox(GetConsoleWindow(), "Please view the site:\nhttps://www.gitcode.com/Robervert_Chao/DS_netpack    \n>>Only from this one site you can download the secure genuine BasicModules!<<\n>>Downloads from other websites may be unsafe or pirated!<<", "Official files-repairing website", MB_OK); //MB_INFO
			ofstream ofsweblink;
			ofsweblink.open("WebLink.txt", ios::out);
			ofsweblink << "//Copy and search it on your browser.\n"; //, recommend to use the Microsoft edge browser
			ofsweblink << "//Please check if the website link below is correct.\n" << endl;
			ofsweblink << "     https://www.gitcode.com/Robervert_Chao/DS_netpack\n" << endl;
			ofsweblink << "[*check code (@binary)]" << endl;
			ofsweblink.close();

			//ofstream ofsLog; //Log
			ofsLog.open(".//log//checkLog.txt", ios::app);
			ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
			ofsLog << "action: creat file: 'WebLink.txt'" << endl;
			ofsLog << "-----------------------" << endl;
			ofsLog.close();

			Sleep(400);
			cout << ">>A txt file with the web link has been created, you could search it and download the packs you need or the repair programme you need.\n";
			cout << "website: https://www.gitcode.com/Robervert_Chao/DS_netpack\n" << endl;
			Sleep(600);
			if (MessageBox(GetConsoleWindow(), "Do you want to open the webpage now?", "Webpage opening inqiry", MB_YESNO) == IDYES) //⬅ What is the help? (MB_HELP)***=== == __ +++ ++ ~~
			{
				ofstream ofsLog;
				ofsLog.open(".//log//checkLog.txt", ios::app);
				ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
				ofsLog << "action: start 'fix_webpage.exe'." << endl;
				ofsLog << "-----------------------" << endl;
				ofsLog.close();
				//system("start .//fix_webpage.exe");
				WinExec(".//fix_webpage.exe",SW_SHOW); //using Winexec to start another exe in hide mode.
				//change .html to .exe ???
				//CreatProcess
			}
			else
			{
				cout << "\n\n\n\n            [DockingSubjects.interrupted.]\n\n\n\n\n\n" << endl;
			}
		}
		else
		{
			system("title Docking Subjects[main](en)  --BasicModual (x)");
			ofstream ofsLog;
			ofsLog.open(".//log//checkLog.txt", ios::app);
			ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
			ofsLog << "action: start without repairing intention." << endl;
			ofsLog << "-----------------------" << endl;
			ofsLog << "start time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
			ofsLog << "action: Prompt started." << endl;
			ofsLog << "-----------------------" << endl; // 顺序问题,小bug而已.
			ofsLog.close();
			goto loop;
		}
	}
	else ////////////////////////////////////////////////////////////////////////////////////////////////////////
	{
		system("title Docking Subjects [main] (en)");
		cout << ">>BasicModule_Check.complete.\n";
		
		if (1) //不得已而为之， goto loop初始化...
		{
			ofstream ofsLogup;
			ofsLogup.open(".//log//checkLog.txt", ios::app);
			ofsLogup << "\n(o)====---=NORMAL=---====" << endl;
			ofsLogup << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
			ofsLogup << "normal: Start securely and with complete BasicModual." << endl;
			ofsLogup << "-----------------------" << endl;
			ofsLogup.close();
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
		DSmainrestart();
		
		printf(">>start time:%4d.%02d.%02d %3d:%02d:%02d\n", year, month, day, hour, min, sec);
		cout << ">>language:【English】\n" << endl;
		ofstream ofsLog;
		ofsLog.open(".//log//checkLog.txt", ios::app);
		ofsLog << "start time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
		ofsLog << "action: DS Prompt started." << endl;
		ofsLog << "-----------------------" << endl;
		ofsLog.close();
	    loopback:
		while (1)
		{
			printf("<\\Docking_Subjects:>_");
			scanf("%s", input1);
			strncpy(inputone, input1, 200);
			if (strcmp(inputone, "/docking") == 0) //*****DOCKING_SUBJECTS***** 接口
			{
			    loopdocking:
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
					else if (strcmp(inputtwo, "cls") == 0)
					{
						DSmainrestart();
						printf(">>start time:%4d.%02d.%02d %3d:%02d:%02d\n", year, month, day, hour, min, sec);
						cout << ">>language:【English\n" << endl;
						cout << "    >>DOCKING...\n";
						goto loopdocking;
					}
					else
					{
						cout << "\n>>Incorrect input! See the help for assistance?\n" << endl;
						cout << ">>You can input \"/help\"for helps or anyothers to break." << endl;
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
									DSclose();
								}
								else if (IDYES)
								{
									cout << "saved~~~\n";   //写cout提示！！！
									Sleep(1000);
									return 0;
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
								cout << "\n>>Incorrect input! See the help for assistance?\n" << endl;
								cout << ">>You can input \"/help\"for helps or anyothers to break." << endl;
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
						cout << "\n>>Incorrect input! See the help for assistance?\n" << endl;
						cout << ">>You can input \"/help\"for helps or anyothers to break." << endl;
					}
					break;
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
							std::cerr << ">>failed to open this file." << std::endl;
							std::cerr << ">>please check if your file path is correct." << std::endl;
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
								cout << "\n>>Incorrect input! See the help for assistance?\n" << endl;
								cout << ">>You can input \"/help\"for helps or anyothers to break." << endl;
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
						cout << "\n>>Incorrect input! See the help for assistance?\n" << endl;
						cout << ">>You can input \"/help\"for helps or anyothers to break." << endl;
					}
					break;
				}
			}
			else if (strcmp(inputone, "/time") == 0)
			{
				printf(">>curent time:\n");
				freshtime();//printf("\n>>current time:%4d.%02d.%02d. %3d:%02d:%02d\n", year, month, day, hour, min, sec); //大bug!//////////////////////////时间无法改变！！！////////////
				printf("\n");
            }
			else if (strcmp(inputone, "/cls") == 0)
			{
				DSmainrestart();
				printf(">>start time:%4d.%02d.%02d %3d:%02d:%02d\n", year, month, day, hour, min, sec);
				cout << ">>language:【English】\n" << endl;
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
			else if (strcmp(inputone, "8") == 0)//*****************
			{
				clrscr();
				gotoxy(25, 15);
				CP("It seems that you've found the developer mode. :>\n",2);//void();  //......
				CP("test", 2);
				Sleep(1000);
				clrscr();
			}
			//announcement??
			else if (strcmp(inputone, "/help") == 0)
			{
				DShelps(); //helps
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
				cout << "\n>>Incorrect input! See the help for assistance?\n" << endl;
				cout << ">>You can input \"/help\"for helps or anyothers to break." << endl;
			}
			/*
			while (!(GetAsyncKeyState(VK_RETURN) & 0x8000)); // 检测Enter键是否按下
			{
				printf("\n\n检测到您按下了 Enter 键，已退出程序！\n");
				goto exitloop;
			}
			*/
			/*
			if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
			{
				while (true)
				{
					Sleep(1000); // 主线程保持运行
				}
			}
			else
			{
				printf("Failed to set control handler\n");
			}
			*/
		}
	}
	//exitloop:
	cout << "\nIf you want to exit, ";
	system("pause");
	return 0;
}
//做中文插件
//调用蓝屏dll