#include<iostram>
const int N = 128;

bool isSafe(int maze[N][N], int n, int m, int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int solve(int maze[N][N], int n, int m, int x, int y)
{
    if (!isSafe(maze, n, m, x, y))
        return 0;

    return maze[x][y] + std::max(solve(maze, n, m, x + 1, y),
                                 solve(maze, n, m, x, y + 1));
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

    std::cout<<solve(maze, n, m, 0, 0);
}
