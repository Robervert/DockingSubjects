#pragma once
#include <iostream>
#include <windows.h>

using namespace std;
void BMchecknotice(int lgc)
{
	if (lgc == 0)
	{
		MessageBox(NULL, "You have select [English] as the display language.", "Language choose", MB_OK);
		cout << ">>BasicModule_Check.processing...\n";
	}
	else if (lgc == 1)
	{
		MessageBox(NULL, "您已将【简体中文】作为显示语言。", "Language choose", MB_OK);
		cout << ">>基础模块_检测.进行中...\n";
	}
	else if (lgc == 2)
	{
		MessageBox(NULL, "あなたは「日本語」を表示言語として設定しました。", "Language choose", MB_OK);//Russian
		cout << ">>基礎モジュール_ルチェック.進行中...\n";
	}
}

using namespace std;
void BMcheckreport(int lgc)
{
	if (lgc == 0)
	{
		cout << "\n>>!Incomplete BasicModules[version: R015b.ic]!" << endl;
	}
	else if (lgc == 1)
	{
		cout << "\n>>!基础模块不完整[版本: R015b.ic]!" << endl;
	}
	else if (lgc == 2)
	{
		cout << "\n>>!不完全な基本モジュール[バージョン: R015b.ic]!" << endl;
	}
}

void CHECKFAILEDtitle(int lgc)
{
	if (lgc == 0)
	{
		system("title Docking Subjects[main](en)  --BasicModual (x)");
	}
	else if (lgc == 1)
	{
		system("title Docking Subjects[主程序](cn)  --基础模块 (x)");
	}
	else if (lgc == 2)
	{
		system("title Docking Subjects[メインプログラム](jp)  --基礎モジュール (x)");
	}
}

void CHECKCOMPLETEtitle(int lgc)
{
	if (lgc == 0)
	{
		system("title Docking Subjects [main] (en)");
		cout << ">>BasicModule_Check.complete.\n";
	}
	else if (lgc == 1)
	{
		system("title Docking Subjects [主程序] (cn)");
		cout << ">>基础模块_检查.完成.\n";
	}
	else if (lgc == 2)
	{
		system("title Docking Subjects [メインプログラム] (jp)");
		cout << ">>基礎モジュー_ルチェック.完成しました.\n";
	}
}

using namespace std;
void IO1goto(int lgc)
{
	if (lgc == 0)
	{
		system("title Docking Subjects [main]");
		gotoxy(0, 19);
		cout << " (c) 2025 Corridor DCO  All rights reserved.\n";
		cout << ">>current version:"; version();
		cout << "【Docking Subjects】- A new open source project aims to the subjects lectures and work assistances.-\n";
	}
	else if (lgc == 1)
	{
		system("title Docking Subjects [主程序]");
		gotoxy(0, 19);
		cout << " (c) 2025 Corridor DCO  版权所有.\n";
		cout << ">>当前版本:"; version();
		cout << "【Docking Subjects】- 一个新的针对学科和工作辅助的开源项目-\n";
	}
	else if (lgc == 2)
	{
		system("title Docking Subjects [メインプログラム]");
		gotoxy(0, 19);
		cout << " (c) 2025 Corridor DCO  著作権所有.\n";
		cout << ">>現在のバージョン:"; version();
		cout << "【Docking Subjects】- 新しいオープンソースプロジェクトは、学問と仕事をサポートすることを目的としています。-\n";
	}
}

using namespace std;
void IO1(int lgc)
{
	if (lgc == 0)
	{
		cout << " (c) 2025 Corridor DCO  All rights reserved.\n";
		cout << ">>current version:"; version();
		cout << "【Docking Subjects】- A new open source project aims to the subjects lectures and work assistances.-\n";
	}
	else if (lgc == 1)
	{
		cout << " (c) 2025 Corridor DCO  版权所有.\n";
		cout << ">>当前版本:"; version();
		cout << "【Docking Subjects】- 一个新的针对学科和工作辅助的开源项目-\n";
	}
	else if (lgc == 2)
	{
		cout << " (c) 2025 Corridor DCO  著作権所有.\n";
		cout << ">>現在のバージョン:"; version();
		cout << "【Docking Subjects】- 新しいオープンソースプロジェクトは、学問と仕事をサポートすることを目的としています。-\n";
	}
}

using namespace std;
void Translang(int lgc)
{
	if (lgc == 0)
	{
		cout << ">>language:【English】\n" << endl;
	}
	else if (lgc == 1)
	{
		cout << ">>语言: 【简体中文】" << endl;
	}
	else if (lgc == 2)
	{
		cout << ">>言語: 【日本語】" << endl;
	}
}

using namespace std;
void midtrans1(int lgc2)
{
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
		WinExec(".//mtneINIs//USERGUIDE.chm", SW_HIDE);//NOT EXISTED YET
	}
	else if (lgc2 == 3)
	{
		MessageBox(NULL, "CYBER MOTTOS!!!", "€￥b⁅R_M〇tτO$", MB_OK);//Russian
		WinExec(".//Cyber Motto.exe", SW_HIDE);
	}
}