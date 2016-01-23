#pragma once

class Ball
{
private:
	int LastX;
	int LastY;
public:

	int Radius;

	int PosX;

	int PosY;

	int VelX;
	int VelY;

	int ClientWidth;

	int ClientHeight;

public:
	Ball(int radius, int posX, int posY, int velX, int velY, int clientWidth, int clientHeight);

public:
	

	static void GoToxy(short x, short y);
	void MoveBall();
	void Draw() const;
};
