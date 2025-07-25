#include <iostream>
#include <string>
#include <windows.h>

// #define DEBUG

#define TIMER_ID 1 // 定时器 ID
HWND hwnd; // 窗口句柄
bool isDragging = false; // 是否在拖动窗口
bool isPinned = true; // 是否锁定（右键置顶）
bool isVisible = false; // 窗口是否可见
POINT dragStart; // 记录鼠标拖动起始位置
RECT windowStart; // 记录窗口拖动起始位置
HFONT hFont; // 自定义字体

const wchar_t* contents[] = {
    L"1. Be brave",
    L"2. Be confidient",
    L"3. Be elegent",
    L"4. Be smart",
    L"5. Be friendly",
};

int contentIndex = 2; // 默认conent的index
const int PADDING_X = 20;
const int PADDING_Y = 10;

#ifdef DEBUG
void CreateConsole() {
    AllocConsole(); // 创建控制台窗口
    freopen("CONOUT$", "w", stdout); // 绑定标准输出
    freopen("CONOUT$", "w", stderr); // 绑定标准错误
    freopen("CONIN$", "r", stdin); // 绑定标准输入
    std::cout.clear(); // 清除错误状态
    std::cerr.clear();
}
#endif

void AdjustWindowSize(HWND hwnd) {
    HDC hdc = GetDC(hwnd);
    RECT rect = { 0, 0, 800 - 2 * PADDING_X, 0 }; // 800 为最大宽度
    SelectObject(hdc, hFont);

    DrawTextW(hdc, contents[contentIndex], -1, &rect, DT_CALCRECT | DT_WORDBREAK);
    ReleaseDC(hwnd, hdc);

    int width = rect.right + 2 * PADDING_X; // 增加一些边距
    int height = rect.bottom + 2 * PADDING_Y;

    // 重新设置窗口大小
    SetWindowPos(hwnd, NULL, (GetSystemMetrics(SM_CXSCREEN) - width) / 2, 10, width, height, SWP_NOZORDER);
}

void AdjustTextPos(RECT& rect) {
    rect.right -= PADDING_X;
    rect.left += PADDING_X;
    rect.top += PADDING_Y;
    // rect.bottom += PADDING_Y;
}

// **获取屏幕宽度**
int getScreenWidth() { return GetSystemMetrics(SM_CXSCREEN); }

// **检查鼠标是否在顶部指定区域**
bool isMouseAtTopRegion() {
    POINT pt;
    GetCursorPos(&pt);
    int screenWidth = getScreenWidth();
    int leftBound = screenWidth * 7 / 16;
    int rightBound = screenWidth * 9 / 16;

    return (pt.y < 5) && (pt.x > leftBound) && (pt.x < rightBound);
}

// **窗口过程**
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
        SetTimer(hwnd, TIMER_ID, 1000, NULL);
        hFont = CreateFontW(30, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, GB2312_CHARSET, OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"微软雅黑");

        AdjustWindowSize(hwnd); // **动态调整窗口大小**
        break;

    case WM_TIMER:
        if (!isPinned) {
            if (isMouseAtTopRegion()) {
                if (!isVisible) {
                    ShowWindow(hwnd, SW_SHOW);
                    isVisible = true;
                }
            }
            else {
                RECT rect;
                GetWindowRect(hwnd, &rect);
                POINT pt;
                GetCursorPos(&pt);
                if (!PtInRect(&rect, pt)) {
                    ShowWindow(hwnd, SW_HIDE);
                    isVisible = false;
                }
            }
        }
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        SetTextColor(hdc, RGB(255, 255, 255));
        SetBkMode(hdc, TRANSPARENT);
        SelectObject(hdc, hFont);

        // RECT rect = {0, 0, 800, 0}; // 800 为最大宽度
        RECT rect;
        GetClientRect(hwnd, &rect);
        // printf("left: %d, top: %d, right: %d, bottom: %d \n", rect.left, rect.top, rect.right, rect.bottom);
        AdjustTextPos(rect);
        // printf("left: %d, top: %d, right: %d, bottom: %d \n", rect.left, rect.top, rect.right, rect.bottom);
        DrawTextW(hdc, contents[contentIndex], -1, &rect, DT_WORDBREAK); // **自动换行**
        EndPaint(hwnd, &ps);
        break;
    }

    case WM_LBUTTONDOWN:
        isDragging = true;
        GetCursorPos(&dragStart);
        GetWindowRect(hwnd, &windowStart);
        SetCapture(hwnd);
        break;

    case WM_MOUSEMOVE:
        if (isDragging) {
            POINT pt;
            GetCursorPos(&pt);
            int dx = pt.x - dragStart.x;
            int dy = pt.y - dragStart.y;
            SetWindowPos(hwnd, NULL, windowStart.left + dx, windowStart.top + dy, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
        break;

    case WM_LBUTTONUP:
        isDragging = false;
        ReleaseCapture();
        RECT rect;
        GetWindowRect(hwnd, &rect);
        if (rect.top < 5 && !isPinned) {
            ShowWindow(hwnd, SW_HIDE);
            isVisible = false;
        }
        break;

    case WM_RBUTTONDOWN:
        isPinned = !isPinned;
        if (isPinned) {
            ShowWindow(hwnd, SW_SHOW);
            isVisible = true;
        }
        break;

    case WM_KEYDOWN:
        if (wParam >= '1' && wParam <= '5') // **监听 1-5 键**
        {
            int index = wParam - '1'; // 计算索引（'1' -> 0, ..., '5' -> 4）
            if (index != contentIndex) {
                contentIndex = index;
                InvalidateRect(hwnd, NULL, TRUE); // **触发重绘**
                AdjustWindowSize(hwnd);
            }
        }
        break;

    case WM_SETCURSOR:
        SetCursor(LoadCursor(NULL, IDC_ARROW));
        return TRUE;

    case WM_DESTROY:
        KillTimer(hwnd, TIMER_ID);
        DeleteObject(hFont);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// **主函数**
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
#ifdef DEBUG
    CreateConsole();
#endif

    const wchar_t CLASS_NAME[] = L"FloatingWindow";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));

    RegisterClassW(&wc);

    hwnd = CreateWindowExW(WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TOOLWINDOW,
        CLASS_NAME, L"FloatingWindow", WS_POPUP,
        960, 10, 300, 100, NULL, NULL, hInstance, NULL
    );

    SetLayeredWindowAttributes(hwnd, 0, 200, LWA_ALPHA);
    ShowWindow(hwnd, SW_SHOW);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
