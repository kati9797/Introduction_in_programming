
#include <iostream>
const int SIZE = 9;

bool isSafe(int grid[SIZE][SIZE], int x, int y, int input)
{
    // row
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[x][i] == input)
            return false;
    }

    // col
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[i][y] == input)
            return false;
    }

    int startRow = x - x % 3;
    int startCol = y - y % 3;

    // grid 3x3
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == input)
                return false;
        }
    }
    return true;
}

void printSodoku(int grid[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool solve(int grid[SIZE][SIZE], int x, int y)
{
    // solved
    if (x == SIZE - 1 && y == SIZE)
    {
        return true;
    }

    // new row
    if (y == SIZE)
    {
        x++;
        y = 0;
    }

    // we can put a number only when grid[x][y] = 0
    if (grid[x][y] > 0)
        return solve(grid, x, y + 1);

    for (int i = 1; i <= 9; i++)
    {
        // we can put a number
        if (isSafe(grid, x, y, i))
        {
            grid[x][y] = i;
            // if the number is correct
            if (solve(grid, x, y + 1))
                return true;
        }
        // the number is not correct -> we have to erase it
        // BACKTARCKING !!!
        grid[x][y] = 0;
    }

    // not found a solution
    return false;
}

int main()
{
    int grid[SIZE][SIZE] = 
       { {3, 0, 6, 5, 0, 8, 4, 0, 0},
         {5, 2, 0, 0, 0, 0, 0, 0, 0},
         {0, 8, 7, 0, 0, 0, 0, 3, 1},
         {0, 0, 3, 0, 1, 0, 0, 8, 0},
         {9, 0, 0, 8, 6, 3, 0, 0, 5},
         {0, 5, 0, 0, 9, 0, 6, 0, 0},
         {1, 3, 0, 0, 0, 0, 2, 5, 0},
         {0, 0, 0, 0, 0, 0, 0, 7, 4},
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    if (solve(grid, 0, 0) == true)
    {
        printSodoku(grid);
    }
    else
    {
        std::cout << "No solution exists!";
    }
}
