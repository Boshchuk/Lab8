#include "stdafx.h"

#include "Ball.h"

#include <windows.h>
#include <iostream>




Ball::Ball(int posX, int posY, int velX, int velY, int clientWidth, int clientHeight)
{
	ClientHeight = clientHeight;
	ClientWidth = clientWidth;
	PosX = posX;
	PosY = posY;
	VelX = velX;
	VelY = velY;

	LastX = posX;
	LastY = posY;
}

void Ball::GoToxy(short x, short y)
{
	COORD coord;// = COORD({ x, y };
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Ball::MoveBall()
{
	LastX = PosX;
	LastY = PosY;
	PosX = PosX + VelX;
	PosY = PosY + VelY;
	if (PosX >= ClientWidth - 2)
	{
		VelX = -VelX;
	}

	if (PosX <= 1)
	{
		VelX = -VelX;
	}

	if (PosY >= ClientHeight - 2)
	{
		VelY = -VelY;
	}

	if (PosY <= 1)
	{
		VelY = -VelY;
	}
}



void Ball::Draw()
{
	//var lastColor = Console.ForegroundColor;

	//Console.ForegroundColor = ConsoleColor.Red;

	GoToxy(LastX, LastY);
	std::cout << " ";
	GoToxy(PosX, PosY);
	std::cout << "o";

	//Console.ForegroundColor = lastColor;
}
