#pragma once
#include <windows.h>
#include <ctime>
#include <string.h>
#include <iostream>
#include <fstream>

void msgfilecheck()
{
	struct tm* info;
	time_t curtime;
	time(&curtime);
	info = localtime(&curtime);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&curtime));
	string Ftm = tmp;

	ofstream ofsLog;
	ofsLog.open(".//log//checkLog.txt", ios::app);
	ofsLog << "\n(x)====---=ERROR=---====" << endl;
	ofsLog << "check time: " << Ftm << endl; //ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
	ofsLog << "error: Start with the INCOMPLETE BasicModual!" << endl;
	ofsLog << "-----------------------" << endl;
	ofsLog.close();
}

void msgrepairask()
{
	struct tm* info;
	time_t curtime;
	time(&curtime);
	info = localtime(&curtime);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&curtime));
	string Ftm = tmp;

	ofstream ofsLog;
	ofsLog.open(".//log//checkLog.txt", ios::app);
	ofsLog << "check time: " << Ftm << endl; //ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
	ofsLog << "action: start with repairing intention." << endl;
	ofsLog << "-----------------------" << endl;
	ofsLog.close();
	MessageBox(GetConsoleWindow(), "Please view the site:\nhttps://www.gitcode.com/Robervert_Chao/DS_netpack    \n>>Only from this one site you can download the secure genuine BasicModules!<<\n>>Downloads from other websites may be unsafe or pirated!<<", "Official files-repairing website", MB_OK); //MB_INFO
	ofstream ofsweblink;
	ofsweblink.open("WebLink.txt", ios::out);
	ofsweblink << "//Copy and search it on your browser.\n"; //, recommend to use the Microsoft edge browser
	ofsweblink << "//creat time: " << Ftm << endl;
	ofsweblink << "//Please check if the website link below is correct.\n" << endl;
	ofsweblink << "     https://www.gitcode.com/Robervert_Chao/DS_netpack\n" << endl;
	ofsweblink << "[*check code (@binary)]" << endl;
	ofsweblink.close();
	//ofstream ofsLog; //Log
	ofsLog.open(".//log//checkLog.txt", ios::app);
	ofsLog << "check time: " << Ftm << endl; //ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
	ofsLog << "action: creat file: 'WebLink.txt'" << endl;
	ofsLog << "-----------------------" << endl;
	ofsLog.close();
	Sleep(400);
	cout << ">>A txt file with the web link has been created, you could search it and download the packs you need or the repair programme you need.\n";
	cout << "website: https://www.gitcode.com/Robervert_Chao/DS_netpack\n" << endl;
	Sleep(600);
}

void msgopenwebpageask()
{
	struct tm* info;
	time_t curtime;
	time(&curtime);
	info = localtime(&curtime);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&curtime));
	string Ftm = tmp;
	ofstream ofsLog;
	ofsLog.open(".//log//checkLog.txt", ios::app);
	ofsLog << "check time: " << Ftm << endl; //ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
	ofsLog << "action: start 'fix_webpage.exe'." << endl;
	ofsLog << "-----------------------" << endl;
	ofsLog.close();
	//system("start .//fix_webpage.exe");
	WinExec(".//fix_webpage.exe", SW_SHOW); //using Winexec to start another exe in hide mode.
	//change .html to .exe ???
	//CreatProcess
}

void logfilecheck1()
{
	struct tm* info;
	time_t curtime;
	time(&curtime);
	info = localtime(&curtime);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&curtime));
	string Ftm = tmp;
	ofstream ofsLog;
	ofsLog.open(".//log//checkLog.txt", ios::app);
	ofsLog << "check time: " << Ftm << endl; //ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
	ofsLog << "action: start without repairing intention." << endl;
	ofsLog << "-----------------------" << endl;
	ofsLog.close();
}

void logfilestartsecurelynotice()
{
	struct tm* info;
	time_t curtime;
	time(&curtime);
	info = localtime(&curtime);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&curtime));
	string Ftm = tmp;
	ofstream ofsLog;
	ofsLog.open(".//log//checkLog.txt", ios::app);
	ofsLog << "\n(o)====---=NORMAL=---====" << endl;
	ofsLog << "check time: " << Ftm << endl; //ofsLog << "check time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
	ofsLog << "normal: Start securely and with complete BasicModual." << endl;
	ofsLog << "-----------------------" << endl;
	ofsLog.close();
}

void dspromptstartnotice()
{
	struct tm* info;
	time_t curtime;
	time(&curtime);
	info = localtime(&curtime);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&curtime));
	string Ftm = tmp;
	ofstream ofsLog;
	ofsLog.open(".//log//checkLog.txt", ios::app);
	ofsLog << "check time: " << Ftm << endl; //ofsLog << "start time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
	ofsLog << "action: DS Prompt started." << endl;
	ofsLog << "-----------------------" << endl;
	ofsLog.close();
}

void dspromptrefreshnotice()
{
	struct tm* info;
	time_t curtime;
	time(&curtime);
	info = localtime(&curtime);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&curtime));
	string Ftm = tmp;
	ofstream ofsLog;
	ofsLog.open(".//log//checkLog.txt", ios::app);
	ofsLog << "check time: " << Ftm << endl; //ofsLog << "start time:" << year << "." << month << "." << day << "  " << hour << ":" << min << ":" << sec << endl;
	ofsLog << "action: DS Prompt refreshed." << endl;
	ofsLog << "-----------------------" << endl;
	ofsLog.close();
}

using namespace std;
void incorrectinput(int lgc)
{
	if (lgc == 0)
	{
		cout << "\n>>Incorrect input! See the help for assistance?" << endl;
		cout << ">>You can input \"/help\"for helps or anyothers to break.\n" << endl;
	}
	else if (lgc == 1)
	{
		cout << "\n>>错误的输入！想要查看帮助菜单以获取帮助？" << endl;
		cout << ">>你可以输入 \"/help\" 来显示帮助菜单或任何输入其他选项来进行其他交互。\n" << endl;
	}
	else if (lgc == 2)
	{
		cout << "\n>>入力エラー！ヘルプメニューを表示してヘルプを取得したいですか？" << endl;
		cout << ">>\"help\" を入力するとヘルプメニューが表示されます。他のオプションを入力すると、他のインタラクションが行えます。\n" << endl;
	}
}

void incorrectpath(int lgc)
{
	if (lgc == 0) //en
	{
		std::cerr << ">>failed to open this file." << std::endl;
		std::cerr << ">>please check if your file path is correct." << std::endl;
	}
	else if (lgc == 1) //cn-zh
	{
		std::cerr << ">>文件打开失败。" << std::endl;
		std::cerr << ">>请检查文件路径是否正确。" << std::endl;
	}
	else if (lgc == 2) //jp
	{
		std::cerr << ">>このファイルを開けませんでした。" << std::endl;
		std::cerr << ">>ファイルパスが正しいかどうか確認してください。" << std::endl;
	}
}