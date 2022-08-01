#include<iostream>

//Съществува ли път с дължина p
//1 -> проходима клетка
//0 -> непроходима клетка

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

bool isSafe(bool** maze, int n, int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1;
}

void printMaze(int** maze, int n)
{
    std::cout << "-------------" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
}

void hasPath(bool** maze, int n, int xs, int ys, int xd, int yd, int count, int p, int** sol)
{
    if (!(isSafe(maze, n, xs, ys)))
    {
        return;
    }

    if (xs == xd && ys == yd && count == p)
    {
        sol[xs][ys] = count;
        printMaze(sol, n);
        return;
    }

    maze[xs][ys] = 0;
    sol[xs][ys] = count++;
    hasPath(maze, n, xs + 1, ys, xd, yd, count, p, sol);
    hasPath(maze, n, xs - 1, ys, xd, yd, count, p, sol);
    hasPath(maze, n, xs, ys + 1, xd, yd, count, p, sol);
    hasPath(maze, n, xs, ys - 1, xd, yd, count, p, sol);
    sol[xs][ys] = 0;
    count--;
    maze[xs][ys] = 1;
}


int main()
{
    int n;
    std::cin >> n;
    bool** maze = new bool* [n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new bool[n];
    }
    inputMaze(maze, n);

    int** sol = new int* [n];
    for (int i = 0; i < n; i++)
    {
        sol[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = 0;
        }
    }

    int count = 1;;
    hasPath(maze, n, 0, 0, 2, 2, count, 3, sol);
    for (int i = 0; i < n; i++)
    {
        delete[] maze[i];
        delete[] sol[i];
    }
    delete[] maze;
    delete[] sol;

}
