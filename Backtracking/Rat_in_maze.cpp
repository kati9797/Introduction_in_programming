#include <iostream>
int const N = 4;

bool isSafe(int maze[N][N], int x, int y)
{
    if (x >= 0 && x <= N && y >= 0 && y <= N && maze[x][y] == 1)
        return true;
    return false;
}

bool solveUntil(int maze[N][N], int x, int y, int sol[N][N])
{
    // destination is found
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }

    // the cell is safe for the rat
    if (isSafe(maze, x, y))
    {
        // the rat has already been there
        if (sol[x][y] == 1)
            return false;
        // the rat has not been there before
        sol[x][y] = 1;
        
        // try directions
        if (solveUntil(maze, x + 1, y, sol) == true)
            return true;
        if (solveUntil(maze, x, y + 1, sol) == true)
            return true;

        // not found a path
        // BACKTRACKING!!!
        sol[x][y] = 0;
        return false;
    }
    // the cell is not safe for the rat
    return false;
}

void printSolution(int maze[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool solveMaze(int maze[N][N])
{
    int sol[N][N]= {   { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 } };

    if (solveUntil(maze, 0, 0, sol) == false)
    {
        std::cout << "A path does not exist!" << std::endl;
        return false;
    }
    else
    {
        printSolution(sol);
    }
}

int main()
{
    int maze[N][N] = { { 1, 1, 1, 1 },
                       { 0, 0, 0, 0 },
                       { 0, 1, 1, 0 },
                       { 0, 1, 1, 1 } };
    solveMaze(maze);
}
