#include "stdafx.h"

#include "Ball.h"

#include <windows.h>
#include <iostream>




Ball::Ball(int radius, int posX, int posY, int velX, int velY, int clientWidth, int clientHeight)
{
	Radius = radius;

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
	COORD coord;
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
	

	if (PosX + Radius >= ClientWidth - 2)
	{
		PosX = ClientWidth - 2 - Radius;
		VelX = -VelX;
	}

	if (PosX -Radius <= 1)
	{
		PosX = 1 +Radius;
		VelX = -VelX;
	}

	if (PosY +Radius >= ClientHeight - 2)
	{
		PosY = ClientHeight - 2 - Radius;
		VelY = -VelY;
	}

	if (PosY -Radius <= 1)
	{
		PosY = 1 +Radius;
		VelY = -VelY;
	}
	
}

void Ball::Draw() const
{

	GoToxy(LastX, LastY);
	std::cout << " ";
	GoToxy(PosX, PosY);
	std::cout << "o";

}
