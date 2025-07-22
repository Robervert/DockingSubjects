#pragma once
//MADE BY TianQi AI 2025.06.29 17:43
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "DockingSubjects.h"

int n{}; //r-回环
//#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
int a = 5; //次数
int b = 6; //数位
namespace CaptchaSystem {
    // 验证码生成模块
    class CaptchaGenerator {
    public:
        static std::string generate(int length = b)
        {
            std::string captcha;
            srand(static_cast<unsigned>(time(0)));

            for (int i = 0; i < length; ++i)
            {
                captcha += '0' + rand() % 10; // 生成数字验证码
            }
            return captcha;
        }
    };
    // 用户交互模块
    class CaptchaInterface
    {
    public:
        static void display(const std::string& captcha)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            gotoxy(0, 23);
            std::cout << "\n CAPTCHA Code: [ ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            std::cout << captcha;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << " ] ";
        }

        static bool validate(const std::string& captcha)
        {
            std::cout << "Please enter the CAPTCHA code: "; // (press \"r\" key to regenerate new code): "
            std::string input;
            std::cin >> input;
            //////////////*
            //while (!(GetAsyncKeyState(VK_UP) & 0x8000))
            //return input == captcha;//
            //////////////**
            //if (GetAsyncKeyState('R'))
            //{
            //    return input == captcha;
            //}
            //////////////***
            ConsoleWizard::clearArea(24, 55, 24, 70);
            if (input == "r")
            {
                n = 2;
            }
            else
            {
                n = 0;
            }
            if (input == "r") return false;// 重新生成标志
            return input == captcha;
            
        }
    };

    // 核心验证逻辑模块
    class CaptchaVerifier
    {
    public:
        static bool executeVerification()
        {
            const int MAX_ATTEMPTS = 5 + n;
            int attempts = 0;
            std::string currentCaptcha;
            while (attempts < MAX_ATTEMPTS)
            {
                currentCaptcha = CaptchaGenerator::generate();
                CaptchaInterface::display(currentCaptcha);

                if (CaptchaInterface::validate(currentCaptcha))
                {
                    //gotoxy(24, 55);
                    std::cout << "\n\x1b[32mCheck Complete!                                     \x1b[0m\n";
                    return true;
                }

                if (++attempts < MAX_ATTEMPTS)
                {
                    std::cout << "\n\x1b[33mCheck Failed, You still have "//\x1b
                        << (MAX_ATTEMPTS - attempts) <<" times to retry."<<"\x1b[0m\n";
                }
            }

            std::cout << "\n\x1b[31mYou've been failed for over "<<a<<" times.                         "<<"\a\x1b\n[0m";
            return false;
        }
    };
}
//    std::cout << "===== 命令行验证码系统 =====\n";
//    return CaptchaSystem::CaptchaVerifier::executeVerification() ? 0 : 1;

