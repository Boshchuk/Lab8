// Lab8Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pool.h"
#include "Ball.h"
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>


int main()
{
	srand(time(0));
	
	auto sizeX = 5 + rand() % 40;
	auto sizeY = 5 + rand() % 30;

	auto xDir = 0;
	auto yDir = 0;

	while (xDir == 0 || yDir == 0)
	{
		xDir = -1 + rand() % 1;
		yDir = -1 + rand() % 1;
	}

	Pool pool = Pool(sizeX,	sizeY);
	Ball ball = Ball(2, 2, xDir, yDir, sizeX, sizeY);
	
	pool.Draw();
	while (true)
	{
		
		ball.MoveBall();
		ball.Draw();
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
    return 0;
}

