// Lab8Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pool.h"
#include "Ball.h"
#include <ctime>
#include <cstdlib>
#include <chrono>

#include <windows.h>
#include <conio.h>
#include <thread>

/* use http://kpolyakov.spb.ru/school/c/faq.htm
for config lib in dev.cpp
*/




int main()
{
	srand(time(0));

	auto sizeX = (50 + rand() % 400);
	auto sizeY = (50 + rand() % 300);

	auto xDir = 0;
	auto yDir = 0;

	while (xDir == 0 || yDir == 0)
	{
		xDir = (-1 + rand() % 1) * rand() % 3;
		yDir = (-1 + rand() % 1) *rand() % 3;
	}

	auto posx = 1 + rand() % (sizeX - 1);
	auto posy = 1 + rand() % (sizeY - 1);


	Pool pool = Pool(sizeX, sizeY);
	Ball ball = Ball(10, posx, posy, xDir, yDir, sizeX, sizeY);

	HWND hwnd;
	wchar_t Title[1024];

	GetConsoleTitle(Title, 1024); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	RECT rc;
	GetClientRect(hwnd, &rc);
	int iWidth = rc.right;
	int iHeight = rc.bottom;
	HDC hdc = GetDC(hwnd);    // Получаем контекст для рисования
	HPEN p1, p2 = CreatePen(PS_SOLID, 2, RGB(0, 245, 0)); // Создаем красное перо
	p1 = (HPEN)SelectObject(hdc, p2);  // Заносим красное перо в контекст рисования
	int x = 0, y = 0, R = iWidth / 2;
	double fi = 0;
	

	

	// draw pool
	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, pool.SizeX, 1);
	LineTo(hdc, pool.SizeX, pool.SizeY);
	LineTo(hdc, 1, pool.SizeY);
	LineTo(hdc, 1, 1);
	
	p1, p2 = CreatePen(PS_SOLID, 2, RGB(250, 0, 0));
	p1 = (HPEN)SelectObject(hdc, p2);
	int r = 5;

	RECT rect = RECT();
	rect.left = 0;
	rect.top = 0;
	rect.right = pool.SizeX;
	rect.bottom = pool.SizeY;

	while (true)
	{
		
		FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 2));


		ball.MoveBall();
		Ellipse(hdc, ball.PosX-ball.Radius, ball.PosY -ball.Radius, ball.PosX + ball.Radius, ball.PosY + ball.Radius);
		
	
	//	ball.Draw();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	
	SelectObject(hdc, p1);   // Возвращаем старое перо
	ReleaseDC(hwnd, hdc);    // Освобождаем контекст рисования
	DeleteObject(p2);       // Удаляем созданное перо

	_getch();


    return 0;
}

