#pragma once
#include <windows.h>
#include <stdio.h>
#include <cstdio>
#include <ctime>

using namespace std;
static void version()
{
    cout << "[v 1.0.0.2 - 2025.06.30-beta]" << endl; //check .txt
}


/*
    0 = ��ɫ 1 = ��ɫ 2 = ��ɫ 3 = ǳ��ɫ 4 = ��ɫ 5 = ��ɫ 6 = ��ɫ 7 = ��ɫ //firstone,before black block.
    8 = ��ɫ 9 = ����ɫ 10 = ����ɫ 11 = ��ǳ��ɫ 12 = ����ɫ 13 = ����ɫ 14 = ����ɫ 15 = ����ɫ
    */
constexpr auto hei = 0;
constexpr auto lan = 1;
constexpr auto lv = 2;
constexpr auto qianlv = 3;
constexpr auto hong = 4;
constexpr auto zi = 5;
constexpr auto huang = 6;
constexpr auto bai = 7;
constexpr auto hui = 8;
constexpr auto danlan = 9;
constexpr auto danlv = 10;
constexpr auto danqianlv = 11;
constexpr auto danhong = 12;
constexpr auto danzi = 13;
constexpr auto danhuang = 14;
constexpr auto liangbai = 15;
/*
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)

int ENTERKEY()
{
	while (!KEY_DOWN(VK_RETURN)); // ʹ�ú���Enter���Ƿ���
	printf("The 'Enter' key has been pressed, programme destroyed.");
	return 0;
}
*/

//Keydown
/*
bool CtrlHandler(DWORD fdwCtrlType)
{
    switch (fdwCtrlType)
    {
    case CTRL_CLOSE_EVENT:
        printf("Ctrl+C event detected\n");
        Sleep(1000);
        return false; // ���� false ��ʾ�������������¼�
    default:
        return false;
    }
}
*/

////////////////////////////////////////
#if !defined(_WIN32)//???!?!
#include <unistd.h>
#endif

class ConsoleWizard {
public:
    // ��Ⱦɫħ��
    static void colorLine(int lineNum, int colorCode) {
        moveCursor(lineNum, 0);

#if defined(_WIN32)
        // Windowsħ����
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, colorCode);
#else
        // UNIX/Linux����
        std::cout << "\033[" << colorCode << "m";
#endif
    }

    // �ֲ������ʽ
    static void clearArea(int startLine, int startCol, int endLine, int endCol) {
        for (int y = startLine; y <= endLine; y++) {
            moveCursor(y, startCol);
            // �ÿո񸲸�Ŀ������
            std::cout << std::string(endCol - startCol, ' ');
#if defined(_WIN32)
            // Windows��Ҫ��ʱˢ��
            std::cout.flush();
#endif
        }
    }

private:
    // ���˲���ƶ�����
    static void moveCursor(int line, int col) {
#if defined(_WIN32)
        COORD coord = { static_cast<SHORT>(col), static_cast<SHORT>(line) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
        std::cout << "\033[" << line << ";" << col << "H";
#endif
    }
};

// define color print function
void COLOR_PRINT(const char* s, int color) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    printf("%s", s);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7); // �ָ�Ĭ����ɫ
}

void gotoxy(short x, short y)
{
    COORD coord = { x, y };
    //COORD��Windows API�ж����һ�ֽṹ�����ͣ���ʾ����̨��Ļ�ϵ����ꡣ
    //��������Ƕ�����COORD���͵ı���coord�������β�x��y���г�ʼ����
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    //GetStdHandle(STD_OUTPUT_HANDLE); ��ȡ����̨������
    //Ȼ����SetConsoleCursorPosition���ÿ���̨(cmd)���λ��
}

void clrscr()
{    //�����Ļ
    HANDLE hdout = GetStdHandle(STD_OUTPUT_HANDLE);    //��ȡ��׼����豸�ľ��
    CONSOLE_SCREEN_BUFFER_INFO csbi;    //�����ʾ��Ļ���������Եı���
    GetConsoleScreenBufferInfo(hdout, &csbi);  //��ȡ��׼����豸����Ļ����������
    DWORD size = csbi.dwSize.X * csbi.dwSize.Y, num = 0; //����˫�ֽڱ���
    COORD pos = { 0, 0 };    //��ʾ����ı�������ʼ��Ϊ���Ͻ�(0, 0)�㣩
    //�Ѵ��ڻ�����ȫ�����Ϊ�ո����ΪĬ����ɫ��������
    FillConsoleOutputCharacter(hdout, ' ', size, pos, &num);
    FillConsoleOutputAttribute(hdout, csbi.wAttributes, size, pos, &num);
    SetConsoleCursorPosition(hdout, pos);    //��궨λ���������Ͻ�
}

/////////////////////SHIT/////////////////////

using namespace std;
void FreshTime() //fresh time
{
    struct tm* info;
    //��ȡ��ǰʱ��
    time_t curtime;
    time(&curtime);
    info = localtime(&curtime);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y.%m.%d  _ %H:%M:%S", localtime(&curtime));
    string Ftm = tmp;
    cout << ">>current time:[ " << Ftm <<" ]"<< endl;
}

/////////////////////SHIT/////////////////////

/*
* Which looks bad but performed extremely well.
* 
* 
    time_t now = time(0); // time��date
    tm time = *localtime(&now);//(&now)
    int year = time.tm_year + 1900;
    int month = time.tm_mon + 1;
    int day = time.tm_mday;
    int hour = time.tm_hour;
    int min = time.tm_min;
    int sec = time.tm_sec;
*
* 
*/

/*
                            if (lgc == 0) //�ж�
                            {
                                gotoxy(0, USY);
                                CP("English (BrE)", 6); cout << "    "; CP("Chinese (��������)", 8); cout << "    "; CP("Japanese (�ձ��Z)", 8); cout << "" << endl;
                            }
                            else if (lgc == 1)
                            {
                                gotoxy(0, USY);
                                CP("English (BrE)", 8); cout << "    "; CP("Chinese (��������)", 6); cout << "    "; CP("Japanese (�ձ��Z)", 8); cout << "" << endl;
                            }
                            else if (lgc == 2)
                            {
                                gotoxy(0, USY);
                                CP("English (BrE)", 8); cout << "    "; CP("Chinese (��������)", 8); cout << "    "; CP("Japanese (�ձ��Z)", 6); cout << "" << endl;
                            }
                            else
                            {
                                lgc = 0;
                                gotoxy(0, USY);
                                CP("English (BrE)", 6); cout << "    "; CP("Chinese (��������)", 8); cout << "    "; CP("Japanese (�ձ��Z)", 8); cout << "" << endl;
                            }
*/