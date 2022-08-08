const int N = 128;

bool isSafe(int maze[N][N], int n, int m, int x, int y)
{
    return (x >= 0 && x < n&& y >= 0 && y < m) && (maze[x][y] == 0);
}

void solve(int maze[N][N], int n, int m, int sx, int sy, int dx, int dy)
{
    if (sx == dx && sy == dy)
    {
        maze[sx][sy] = 1; 
        std::cout << "--------------" << std::endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << maze[i][j] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }

    if (!isSafe(maze, n, m, sx, sy))
        return;

    maze[sx][sy] = 1;
    solve(maze, n, m, sx + 1, sy, dx, dy);
    solve(maze, n, m, sx - 1, sy, dx, dy);
    solve(maze, n, m, sx, sy + 1, dx, dy);
    solve(maze, n, m, sx, sy - 1, dx, dy);
    maze[sx][sy] = 0;
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
    solve(maze, n, m, sx, sy, dx, dy);
}

/*
3 4
0 0 1 1
0 0 0 1
1 0 0 0
0 0 2 3
*/
