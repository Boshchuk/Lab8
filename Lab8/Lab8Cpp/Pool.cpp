#include "stdafx.h"
#include "Pool.h"
#include <cstdlib>
#include <iostream>



Pool::Pool(int x, int y)
{
	SizeX = x;
	SizeY = y;
}

void Pool::Draw() const
{
	system("cls");

	for (int i = 0; i < SizeX; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;

	// bok i seredina be veha i niza
	for (int i = 0; i < SizeY - 2; i++)
	{
		std::cout << "*";
		for (int j = 0; j < SizeX - 2; j++)
		{
			std::cout << " ";
		}
		std::cout << "*" << std::endl;

	}
	// niz
	for (int i = 0; i < SizeX; i++)
	{
		std::cout << "*";
	}
}
