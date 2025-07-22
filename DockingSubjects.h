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
    0 = 黑色 1 = 蓝色 2 = 绿色 3 = 浅绿色 4 = 红色 5 = 紫色 6 = 黄色 7 = 白色 //firstone,before black block.
    8 = 灰色 9 = 淡蓝色 10 = 淡绿色 11 = 淡浅绿色 12 = 淡红色 13 = 淡紫色 14 = 淡黄色 15 = 亮白色
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
	while (!KEY_DOWN(VK_RETURN)); // 使用宏检测Enter键是否按下
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
        return false; // 返回 false 表示继续处理其他事件
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
    // 行染色魔法
    static void colorLine(int lineNum, int colorCode) {
        moveCursor(lineNum, 0);

#if defined(_WIN32)
        // Windows魔法阵
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, colorCode);
#else
        // UNIX/Linux咒文
        std::cout << "\033[" << colorCode << "m";
#endif
    }

    // 局部清除术式
    static void clearArea(int startLine, int startCol, int endLine, int endCol) {
        for (int y = startLine; y <= endLine; y++) {
            moveCursor(y, startCol);
            // 用空格覆盖目标区域
            std::cout << std::string(endCol - startCol, ' ');
#if defined(_WIN32)
            // Windows需要即时刷新
            std::cout.flush();
#endif
        }
    }

private:
    // 光标瞬间移动奥义
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
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7); // 恢复默认颜色
}

void gotoxy(short x, short y)
{
    COORD coord = { x, y };
    //COORD是Windows API中定义的一种结构体类型，表示控制台屏幕上的坐标。
    //上面语句是定义了COORD类型的变量coord，并以形参x和y进行初始化。
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    //GetStdHandle(STD_OUTPUT_HANDLE); 获取控制台输出句柄
    //然后用SetConsoleCursorPosition设置控制台(cmd)光标位置
}

void clrscr()
{    //清空屏幕
    HANDLE hdout = GetStdHandle(STD_OUTPUT_HANDLE);    //获取标准输出设备的句柄
    CONSOLE_SCREEN_BUFFER_INFO csbi;    //定义表示屏幕缓冲区属性的变量
    GetConsoleScreenBufferInfo(hdout, &csbi);  //获取标准输出设备的屏幕缓冲区属性
    DWORD size = csbi.dwSize.X * csbi.dwSize.Y, num = 0; //定义双字节变量
    COORD pos = { 0, 0 };    //表示坐标的变量（初始化为左上角(0, 0)点）
    //把窗口缓冲区全部填充为空格并填充为默认颜色（清屏）
    FillConsoleOutputCharacter(hdout, ' ', size, pos, &num);
    FillConsoleOutputAttribute(hdout, csbi.wAttributes, size, pos, &num);
    SetConsoleCursorPosition(hdout, pos);    //光标定位到窗口左上角
}

/////////////////////SHIT/////////////////////

using namespace std;
void FreshTime() //fresh time
{
    struct tm* info;
    //获取当前时间
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
    time_t now = time(0); // time，date
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
                            if (lgc == 0) //判定
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
                            else
                            {
                                lgc = 0;
                                gotoxy(0, USY);
                                CP("English (BrE)", 6); cout << "    "; CP("Chinese (简体中文)", 8); cout << "    "; CP("Japanese (日本語)", 8); cout << "" << endl;
                            }
*/