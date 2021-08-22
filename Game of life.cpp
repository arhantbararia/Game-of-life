// Game of life.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// display
//logic
//input for the starting point

#include <iostream>
#include <conio.h>

static constexpr int bHeight = 10;
static constexpr int bWidth = 10;

int dead = 0;
int live = 1;

int board[bHeight][bWidth];


void logic()
{
	int neighbour = 0;
	int x, y;
	for (int i = 0; i < bWidth; ++i)
	{
		for (int j = 0; j < bHeight; ++j)
		{
			x = i; 
			y = j;
			if (board[i - 1][j - 1] == live)
				neighbour++;

			if (board[i + 1][j + 1] == live)
				neighbour++;

			if (board[i][j - 1] == live)
				neighbour++;

			if (board[i][j + 1] == live)
				neighbour++;

			if (board[i - 1][j] == live)
				neighbour++;

			if (board[i + 1][j] == live)
				neighbour++;
		}
	}

	if (neighbour <= 1)				//underpopulation
	{
		board[x][y] = dead;
	}

	else if (neighbour >= 2 || neighbour <= 3)		//survival
	{
		board[x][y] = live;

	}
	else if (neighbour > 3)		//overpopulation
	{
		board[x][y] = dead;
	}

}

void display()
{
	system("cls");
	for (int i = 0; i < bHeight; ++i)
	{
		for (int j = 0; j < bWidth; ++j)
		{
			if (board[i][j] == live)
			{
				std::cout << "#";
			}
			else
			{
				std::cout << "0";
			}
			std::cout << "\t";
		}
		std::cout << "\n\n";
	}

}


int main()
{
	for (int i = 0; i < bWidth; ++i)
	{
		for (int j = 0; j < bHeight; ++j)
		{
			board[i][j] = dead;
		}
	}

	board[5][3] = live;
	board[6][3] = live;
	board[7][3] = live;
	while(true)
	{
		logic();
		display();
	}
}
