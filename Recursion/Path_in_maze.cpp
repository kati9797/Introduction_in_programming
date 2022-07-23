#include <iostream>
const int N = 128;

bool isSafe(int maze[N][N], int n, int m, int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m) && (maze[x][y] == 0);
}

bool solve(int maze[N][N], int n, int m, int sx, int sy, int dx, int dy)
{
    if (sx == dx && sy == dy)
        return true;

        if (!isSafe(maze, n, m, sx, sy))
            return false; 

        maze[sx][sy] = 1;
        return solve(maze, n, m, sx + 1, sy, dx, dy) ||
               solve(maze, n, m, sx - 1, sy, dx, dy) ||
               solve(maze, n, m, sx, sy + 1, dx, dy) ||
               solve(maze, n, m, sx, sy - 1, dx, dy);
}

int main()
{
    int maze[N][N];
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> maze[i][j];
        }
    }

    int sx, sy, dx, dy;
    std::cin >> sx >> sy >> dx >> dy;
    if (solve(maze, n, m, sx, sy, dx, dy))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout<<maze[i][j]<<" ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "No path";
    }
}
