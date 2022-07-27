//Дадена е мрежа Gr от 𝑚 × 𝑛(𝑚, 𝑛 ∈[2; 20]) квадратчета.
//Във всяко квадратче на мрежата е записано естествено число.
//Дадени са също две произволни квадратчета k1 и k2 в мрежата.
//Ацикличен път между две квадратчета е всяка редица от различни съседни във вертикано или хоризонтално направление квадратчета, 
//започваща от началното и завършваща в крайното квадратче.Да се дефинира рекурсивна функция, която проверява, 
//дали съществува ацикличен път от K1 до K2 в Gr, който представлява аритметична прогресия с разлика d.

void inputMaze(int** maze, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> maze[i][j];
		}
	}
}

bool isSafe(int** maze, int x, int y, int n, int m)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

bool isAritmeticProgression(int* path, int size, int diff)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (path[i] + diff != path[i + 1])
			return false;
	}
	return true;
}

void hasPath(int** maze, int n, int m, int k1x, int k1y, int k2x, int k2y, int diff, int* path, int pathInd, bool** sol)
{
	if (k1x == k2x && k1y == k2y)
	{
		path[pathInd++] = maze[k2x][k2y];
		if (isAritmeticProgression(path, pathInd, diff))
		{
			for (int i = 0; i < pathInd; i++)
			{
				std::cout << path[i] << ' ';
			}
		}
		return;
	}

	if (isSafe(maze, k1x, k1y, n, m))
	{
		if (sol[k1x][k1y] == 1)
			return;
		sol[k1x][k1y] = 1;
		path[pathInd++] = maze[k1x][k1y];
		
		k1x = k1x + 1;
		hasPath(maze, n, m, k1x, k1y, k2x, k2y, diff, path, pathInd, sol);
		k1x = k1x - 1;

		k1x = k1x - 1;
		hasPath(maze, n, m, k1x, k1y, k2x, k2y, diff, path, pathInd, sol);
		k1x = k1x + 1;

		k1y = k1y + 1;
		hasPath(maze, n, m, k1x, k1y, k2x, k2y, diff, path, pathInd, sol);
		k1y = k1y - 1;

		k1y = k1y - 1;
		hasPath(maze, n, m, k1x, k1y, k2x, k2y, diff, path, pathInd, sol);
		k1y = k1y + 1;

		sol[k1x][k1y] = 0;
		pathInd--;
	}
	return;
}

int main()
{
	int n, m;
	std::cout << "n, m: ";
	std::cin >> n >> m;

	std::cout << "Maze: " << std::endl;
	int** maze = new int* [n];
	for (int i = 0; i < n; i++)
	{
		maze[i] = new int[m];
	}
	inputMaze(maze, n, m);

	bool** sol = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		sol[i] = new bool[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sol[i][j] = 0;
		}
	}

	int* path = new int[n * m];

	int k1x, k1y, k2x, k2y;
	std::cout << "k1_x, k1_y: ";
	std::cin >> k1x >> k1y;
	std::cout << "k2_x, k2_y: ";
	std::cin >> k2x >> k2y;

	int sum = maze[k1x][k1y];
	int diff;
	std::cout << "Difference: ";
	std::cin >> diff;

	hasPath(maze, n, m, k1x, k1y, k2x, k2y, diff, path, 0, sol);

	for (int i = 0; i < n; i++)
	{
		delete[] maze[i];
		delete[] sol[i];
	}
	delete[] maze;
	delete[] sol;
	delete[] path;
}
