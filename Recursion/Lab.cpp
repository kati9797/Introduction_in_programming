#include <iostream>

//Дадена е квадратна матрица с размери nxn, n която описва лабиринт.
//Стойност 0 в дадена клетка означава „стена“, стойност 1 означа „свободно място за движение“.
//Даден е низ съдържащ само буквите E(east), W(west), N(north) и S(south),
//които указват едностъпкови придвижвания в съответните географски посоки.Да се напише функция,
//която проверява дали даденият низ е валиден път от някоя проходима клетка в лабиринта до долния десен ъгъл в лабиринта.

void inputMaze(bool** maze, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> maze[i][j];
		}
	}
}

bool isSafe(bool** maze, int x, int y, int n)
{
	return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

bool hasPath(bool** maze, int n, int xs, int ys, char* string)
{
	if (xs == n - 1 && ys == n - 1 && string[0] == '\0')
	{
		return true;
	}

	if (isSafe(maze, xs, ys, n))
	{
		if (string[0] == 'E')
			return hasPath(maze, n, xs, ys + 1, string + 1);
		if(string[0] == 'W')
			return hasPath(maze, n, xs, ys - 1, string + 1);
		if (string[0] == 'S')
			return hasPath(maze, n, xs + 1, ys, string + 1);
		if (string[0] == 'N')
			return hasPath(maze, n, xs - 1, ys, string + 1);
	}
	return false;
}

int main()
{
	int n;
	std::cout << "n: " << std::endl;
	std::cin >> n;

	bool** maze = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		maze[i] = new bool[n];
	}

	std::cout << "Maze:" << std::endl;
	inputMaze(maze, n);

	char* string = new char[n * n];
	std::cout << "Enter string: ";
	std::cin >> string;

	std::cout << hasPath(maze, n, 0, 0, string);

	for (int i = 0; i < n; i++)
	{
		delete[] maze[i];
	}
	delete[] maze;
	delete[] string;
}
