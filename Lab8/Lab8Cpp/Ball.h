#pragma once

class Ball
{
public:
	int LastX;
	int LastY;

	int PosX;

	int PosY;

	int VelX;
	int VelY;

	int ClientWidth;

	int ClientHeight;

public:
	Ball(int posX, int posY, int velX, int velY, int clientWidth, int clientHeight);

public:
	

	static void GoToxy(short x, short y);
	void MoveBall();
	void Draw();
};
