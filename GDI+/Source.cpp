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
    Pen whitePen(Color(255, 255, 255, 255));
    Pen blackPen(Color(255, 0, 0, 0));
    SolidBrush solidWhiteBrush(Color(255, 255, 255, 255));
    SolidBrush solidYellowBrush(Color(255, 255, 204, 0));
    graphics.SetSmoothingMode(SmoothingModeAntiAlias);
   
    

    //Brown rectangule
    SolidBrush solidBrownBrush(Color(250,149, 45, 0));
    graphics.FillRectangle(&solidBrownBrush, 350, 280, 194, 90);

    //Blue rectangule
    SolidBrush solidBlueBrush(Color(255, 51, 102, 255));
    graphics.FillRectangle(&solidBlueBrush, 350, 210, 194, 90);

    //Draw Center Line
    graphics.DrawLine(&whitePen, 350, 300, 544, 300);

    // Top White marks 
    graphics.DrawLine(&whitePen, 440, 295, 457, 295);
    graphics.DrawLine(&whitePen, 432, 288, 466, 288);
    graphics.DrawLine(&whitePen, 440, 281, 457, 281);
    graphics.DrawLine(&whitePen, 415, 274, 483, 274);
    graphics.DrawLine(&whitePen, 440, 267, 457, 267);
    graphics.DrawLine(&whitePen, 432, 260, 466, 260);
    graphics.DrawLine(&whitePen, 440, 253, 457, 253);
    graphics.DrawLine(&whitePen, 415, 246, 483, 246);

    //Marks made with rectangule for reference
    /*SolidBrush solidWhiteBrush(Color(255, 255, 255, 255));
    int middleRect = graphics.FillRectangle(&solidWhiteBrush, 350, 300, 195, 2);
    int smallRect = graphics.FillRectangle(&solidWhiteBrush, 440, 294, 17, 2);
    int midRect = graphics.FillRectangle(&solidWhiteBrush, 432, 287, 34, 2);
    int smallRect2 = graphics.FillRectangle(&solidWhiteBrush, 440, 280, 17, 2);
    int marker10Rect = graphics.FillRectangle(&solidWhiteBrush, 415, 273, 68, 2);
    int smallRect3 = graphics.FillRectangle(&solidWhiteBrush, 440, 266, 17, 2);
    int midRect2 = graphics.FillRectangle(&solidWhiteBrush, 432, 259, 34, 2);
    int smallRect4 = graphics.FillRectangle(&solidWhiteBrush, 440, 252, 17, 2);
    int marker20Rect = graphics.FillRectangle(&solidWhiteBrush, 415, 245, 68, 1); //Line using only one pixel as example
    */
    
    //Bottom white marks
    graphics.DrawLine(&whitePen, 440, 306, 457, 306);
    graphics.DrawLine(&whitePen, 432, 313, 466, 313);
    graphics.DrawLine(&whitePen, 440, 320, 457, 320);
    graphics.DrawLine(&whitePen, 415, 327, 483, 327);
    graphics.DrawLine(&whitePen, 440, 334, 457, 334);
    graphics.DrawLine(&whitePen, 432, 341, 466, 341);
    graphics.DrawLine(&whitePen, 440, 348, 457, 348);
    graphics.DrawLine(&whitePen, 415, 355, 483, 355);


    //Top triangle
    Point triangleArray[] = { Point(448, 227), Point(439, 240), Point(457, 240) };
    graphics.FillPolygon(&solidWhiteBrush, triangleArray, 3);
    //Top triangle border
    Point triangleArray2[] = { Point(448, 227), Point(439, 240), Point(457, 240), Point(449, 227) };
    graphics.DrawLines(&blackPen, triangleArray2, 4);

    //Upsidedown triangle
    Point upsidedowTriangleArray[] = { Point(449, 224), Point(441, 217), Point(456, 217) };
    graphics.FillPolygon(&solidWhiteBrush, upsidedowTriangleArray, 3);

    //Arc
    Image arc(L"C:/Users/igof1/Desktop/C++/GDI+/Images/arc.png");
    graphics.DrawImage(&arc, 327, 180);
    //int arc = graphics.DrawArc(&whitePen, 359, 226, 180, 180, 217, 105);

    //Top Numbers
    FontFamily  fontFamily(L"Times New Roman");
    Font        font(&fontFamily, 10, FontStyleRegular, UnitPixel);
    PointF      pointLeft(402.0f, 321);
    PointF      pointRight(482.0f, 321.0f);

    graphics.DrawString(L"10", -1, &font, pointLeft, &solidWhiteBrush);
    graphics.DrawString(L"10", -1, &font, pointRight, &solidWhiteBrush);

    PointF      pointLeft2(402.0f, 349.0f);
    PointF      pointRight2(482.0f, 349.0f);

    graphics.DrawString(L"20", -1, &font, pointLeft2, &solidWhiteBrush);
    graphics.DrawString(L"20", -1, &font, pointRight2, &solidWhiteBrush);

    //Bottom Numbers
    PointF      pointBottomLeft(402.0f, 268.0f);
    PointF      pointBottomRight(482.0f, 268.0f);

    graphics.DrawString(L"10", -1, &font, pointBottomLeft, &solidWhiteBrush);
    graphics.DrawString(L"10", -1, &font, pointBottomRight, &solidWhiteBrush);

    PointF      pointBottomLeft2(402.0f, 240.0f);
    PointF      pointBottomRight2(482.0f, 240.0f);

    graphics.DrawString(L"20", -1, &font, pointBottomLeft2, &solidWhiteBrush);
    graphics.DrawString(L"20", -1, &font, pointBottomRight2, &solidWhiteBrush);

   //Miniature Airplane
    Point miniAirplaneArray[] = { Point(449, 300), Point(399, 328), Point(449, 317), Point(499, 328) }; // X var = 2nd Point is 20 less then 1st. 4th point is 20 more then 1st
    graphics.FillPolygon(&solidYellowBrush, miniAirplaneArray, 4);
    //Miniature Airplane Border
    Point miniAirplaneArray2[] = { Point(449, 300), Point(399, 328), Point(449, 317), Point(499, 328), Point(449, 300) };
    graphics.DrawLines(&blackPen, miniAirplaneArray2, 5);

    //Wings
   
    Image leftWing(L"C:/Users/igof1/Desktop/C++/GDI+/Images/Attitude indicator with border.png");
    graphics.DrawImage(&leftWing, 376, 297);

    Image rightWing(L"C:/Users/igof1/Desktop/C++/GDI+/Images/right Attitude indicator with border.png");
    graphics.DrawImage(&rightWing, 496, 297);
   
    //Drawing the wings with GDI+ functions
    //Point leftWingArray[] = { Point(400, 300), Point(380, 305), Point(380, 295) };
    //int wingLeftTriangle = graphics.FillPolygon(&solidYellowBrush, leftWingArray, 3);
    //int wingLeftRect = graphics.FillRectangle(&solidYellowBrush, 395, 300, 20, 5);
    //Point righttWingArray[] = { Point(494, 300), Point(514, 305), Point(514, 295)  };
    //int wingRightTriangle = graphics.FillPolygon(&solidYellowBrush, righttWingArray, 3);
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