#include <windows.h>
#include <objidl.h>
#include <Gdiplus.h>
#pragma comment (lib,"Gdiplus.lib")

using namespace Gdiplus;

VOID OnPaint(HDC hdc)
{
    Graphics graphics(hdc);
    Pen      pen(Color(255, 255, 0, 255));
    Pen      bluePen(Color(255, 0, 0, 255));

    graphics.SetSmoothingMode(SmoothingModeAntiAlias);
   

    //Brown rectangule
    SolidBrush solidBrownBrush(Color(250,149, 45, 0));
    int brownRect = graphics.FillRectangle(&solidBrownBrush, 350, 280, 194, 90);

    //Blue rectangule
    SolidBrush solidBlueBrush(Color(255, 51, 102, 255));
    int blueRect = graphics.FillRectangle(&solidBlueBrush, 350, 210, 194, 90);


    //White marks
    SolidBrush solidWhiteBrush(Color(255, 255, 255, 255));
    int middleRect = graphics.FillRectangle(&solidWhiteBrush, 350, 300, 195, 2);
    int smallRect = graphics.FillRectangle(&solidWhiteBrush, 440, 294, 17, 2);
    int midRect = graphics.FillRectangle(&solidWhiteBrush, 432, 287, 34, 2);
    int smallRect2 = graphics.FillRectangle(&solidWhiteBrush, 440, 280, 17, 2);
    int marker10Rect = graphics.FillRectangle(&solidWhiteBrush, 415, 273, 68, 2);
    int smallRect3 = graphics.FillRectangle(&solidWhiteBrush, 440, 266, 17, 2);
    int midRect2 = graphics.FillRectangle(&solidWhiteBrush, 432, 259, 34, 2);
    int smallRect4 = graphics.FillRectangle(&solidWhiteBrush, 440, 252, 17, 2);
    int marker20Rect = graphics.FillRectangle(&solidWhiteBrush, 415, 245, 68, 1); //Line using only one pixel as example

    //Draw top triangle
    Point triangleArray[] = { Point(448, 227), Point(438, 240), Point(456, 240) };
    graphics.FillPolygon(&solidWhiteBrush, triangleArray, 3);


    //Numbers
    FontFamily  fontFamily(L"Times New Roman");
    Font        font(&fontFamily, 10, FontStyleRegular, UnitPixel);
    PointF      pointLeft(402.0f, 268.0f);
    PointF      pointRight(481.0f, 268.0f);

    graphics.DrawString(L"10", -1, &font, pointLeft, &solidWhiteBrush);
    graphics.DrawString(L"10", -1, &font, pointRight, &solidWhiteBrush);

    PointF      pointLeft2(402.0f, 240.0f);
    PointF      pointRight2(481.0f, 240.0f);

    graphics.DrawString(L"20", -1, &font, pointLeft2, &solidWhiteBrush);
    graphics.DrawString(L"20", -1, &font, pointRight2, &solidWhiteBrush);

    //Draw Arc


}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
    HWND                hWnd;
    MSG                 msg;
    WNDCLASS            wndClass;
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR           gdiplusToken;

    // Initialize GDI+.
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = TEXT("GettingStarted");

    RegisterClass(&wndClass);

    hWnd = CreateWindow(
        TEXT("GettingStarted"),   // window class name
        TEXT("Getting Started"),  // window caption
        WS_OVERLAPPEDWINDOW,      // window style
        CW_USEDEFAULT,            // initial x position
        CW_USEDEFAULT,            // initial y position
        CW_USEDEFAULT,            // initial x size
        CW_USEDEFAULT,            // initial y size
        NULL,                     // parent window handle
        NULL,                     // window menu handle
        hInstance,                // program instance handle
        NULL);                    // creation parameters

    ShowWindow(hWnd, iCmdShow);
    UpdateWindow(hWnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    GdiplusShutdown(gdiplusToken);
    return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
    WPARAM wParam, LPARAM lParam)
{
    HDC          hdc;
    PAINTSTRUCT  ps;

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        OnPaint(hdc);
        EndPaint(hWnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
} // WndProc