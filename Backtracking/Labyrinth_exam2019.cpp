#include<iostream>

bool isSafe(int A[][100], int N, int x, int y, int target)
{
    if (x < 0 || x >= N || y < 0 || y >= N || A[x][y] >= 10 || A[x][y] > target)
    {
        return false;
    }
    return true;
}

bool reachable(int A[][100], unsigned N, int sx, int sy, int target)
{
    if (A[sx][sy] == target)
    {
        return true;
    }

    if (isSafe(A, N, sx, sy, target))
    {
        if (reachable(A, N, sx + 1, sy, target) == true)
            return true;
        if (reachable(A, N, sx, sy + 1, target) == true)
            return true;
        return false;
    }
    return false;
}

int main()
{
    int A[][100] =
    {
        {1, 10, 0, 0},
        {4, 10, 0, 7},
        {2, 0, 3, 3},
        {2, 10, 0, 5}
    };

    std::cout << reachable(A, 4, 0, 0, 7);
}
