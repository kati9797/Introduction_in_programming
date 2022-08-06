#include<iostream>

void readMaze(char** maze, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> maze[i][j];
		}
	}
}

void printMaze(bool** maze, int n)
{
	std::cout << "--------------" << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << maze[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool isValidInd(char** maze, int n, int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] != '*');
}

void findTreasure(char** maze, int n, int sx, int sy, bool** sol, bool &found)
{
	if (!(isValidInd(maze, n, sx, sy)))
	{
		return;
	}

	if (maze[sx][sy] == '$')
	{
		sol[sx][sy] = 1;
		//printMaze(sol, n);
		found = true;
		return;
	}

	maze[sx][sy] = '*';
	sol[sx][sy] = 1;
	findTreasure(maze, n, sx + 1, sy, sol, found);
	findTreasure(maze, n, sx - 1, sy, sol, found);
	findTreasure(maze, n, sx, sy + 1, sol, found);
	findTreasure(maze, n, sx, sy - 1, sol, found);
	sol[sx][sy] = 0;
	maze[sx][sy] = '-';

}

int main()
{
	int n;
	std::cin >> n;

	char** maze = new char* [n];
	for (int i = 0; i < n; i++)
	{
		maze[i] = new char[n];
	}
	readMaze(maze, n);

	bool** sol = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		sol[i] = new bool[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sol[i][j] = 0;
		}
	}
	
	bool found = false;
	findTreasure(maze, n, 4, 0, sol, found);
	if (found == true)
	{
		std::cout << "The treasure is found!";
	}
	else
	{
		std::cout << "Not found!";
	}

	for (int i = 0; i < n; i++)
	{
		delete[] maze[i];
		delete[] sol[i];
	}
	delete[] maze;
	delete[] sol;
}

/*
* - * * -
* - - - *
- - * - -
* - * * -
- - * * $
*/
