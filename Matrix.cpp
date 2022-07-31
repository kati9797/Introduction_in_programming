#include <iostream>

const int SIZE = 50;;

void read(int matrix[SIZE][SIZE], int length)
{
    for (int row = 0; row < length; row++)
    {
        for (int col = 0; col < length; col++)
        {
            std::cin >> matrix[row][col];
        }
    }
}

void print(int matrix[SIZE][SIZE], int length)
{
    for (int row = 0; row < length; row++)
    {
        for (int col = 0; col < length; col++)
        {
            std::cout << '[' << matrix[row][col] << ']' << " ";
        }
        std::cout << std::endl;
    }
}

void mainDiagonal (int matrix[SIZE][SIZE], int length)
{
    for (int row = 0; row < length; row++)
    {
        for (int col = 0; col < length; col++)
        {
            if(row == col)
            std::cout << '[' << matrix[row][col] << ']' << " ";
        }
        std::cout << std::endl;
    }
}

void secondDiagonal(int matrix[SIZE][SIZE], int length)
{
    for (int row = 0; row <length ; row++)
    {
        for (int col = length-1; col >= length-row-1; col--)
        {
            if (col==length-row-1)
                std::cout << '[' << matrix[row][col] << ']' << " ";
        }
        std::cout << std::endl;
    }
}

void belowMainDiagonal(int matrix[SIZE][SIZE], int length)
{
    for (int row = 0; row < length; row++)
    {
        for (int col = 0; col < row; col++)
        {
                std::cout << '[' << matrix[row][col] << ']' << " ";
        }
        std::cout << std::endl;
    }
}

void belowSecondDiagonal(int matrix[SIZE][SIZE], int length)
{
    for (int row = 0; row < length; row++)
    {
        for (int col = length - 1; col > length - row - 1; col--)
        {
                std::cout << '[' << matrix[row][col] << ']' << " ";
        }
        std::cout << std::endl;
    }
}

void overSecondDiagonal(int matrix[SIZE][SIZE], int length)
{
    for (int row = 0; row < length-1; row++)
    {
        for (int col = length - 2; col >= 0; col--)
        {
            if(col<length-row-1)
            std::cout << '[' << matrix[row][col] << ']' << " ";
        }
        std::cout << std::endl;
    }
}

void overMainDiagonal(int matrix[SIZE][SIZE], int length)
{
    for (int row = 0; row < length; row++)
    {
        for (int col = 1; col < length; col++)
        {
            if(col>row)
            std::cout << '[' << matrix[row][col] << ']' << " ";
        }
        std::cout << std::endl;
    }
}

void inputMatrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void freeMatrix(int** matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** transpondedMatrix(int** matrix, int row, int col)
{
    int** newMatrix = new int* [row];
    for (int i = 0; i < row; i++)
    {
        newMatrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                newMatrix[i][j] = matrix[j][i];
            }
    }
    /*
    for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                std::cout<< newMatrix[i][j]<<" ";
            }
            std::cout << std::endl;
        }
    */  
    //freeMatrix(newMatrix, row);

    return newMatrix;
}

void printMatrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << matrix[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}
// [0,0] [0,1] [0,2] [0,3]
// [1,0] [1,1] [1,2] [1,3]
// [2,0] [2,1] [2,2] [2,3]
// [3,0] [3,1] [3,2] [3,3]

int main()
{
    /*int matrix[SIZE][SIZE] =
    {
        {1,2,3,4,7},
        {5,6,7,8,9},
        {9,10,11,12,11},
        {13,14,15,16,22}
    };
    */

    int n, m;
    std::cin >> n >> m;
    int** dynamicMatrix = new int* [n];
    inputMatrix(dynamicMatrix, n, m);
    int** newMatrix = transpondedMatrix(dynamicMatrix, m, n);
    printMatrix(newMatrix, m, n);
    //freeMatrix(dynamicMatrix, n);
    //freeMatrix(newMatrix, m);
    //mainDiagonal(matrix, 4);
    //secondDiagonal(matrix, 4);
    //overMainDiagonal(matrix, 4);
    //belowSecondDiagonal(matrix, 4);
    //overSecondDiagonal(matrix, 4);
    //overMainDiagonal(matrix, 4);
    return 0;
}

//Дадена е целочислена матрица с размерност nxm(n, m e[1; 10]).
//Да се напише програма, която проверява дали съществува елемент,
//който е равен на сумата от съседите си.
//Всеки елемент има до 8 съседа.

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

bool findElement(int** maze, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                if (maze[0][1] + maze[1][0] + maze[1][1] == maze[0][0])
                    return true;
            }
            else if (i == n - 1 && j == 0)
            {
                if (maze[n - 1][1] + maze[n - 2][0] + maze[n - 2][1] == maze[n - 1][0])
                    return true;
            }
            else if (i == 0 && j == m - 1)
            {
                if (maze[1][m - 1] + maze[0][m - 2] + maze[1][m - 2] == maze[0][m - 1])
                    return true;
            }
            else if (i == n - 1 && j == m - 1)
            {
                if (maze[n - 1][m - 2] + maze[n - 2][m - 1] + maze[n - 2][m - 2] == maze[n - 1][m - 1])
                    return true;
            }
            else if (i == 0 && j > 0 && j < m - 1)
            {
                if (maze[0][j + 1] + maze[0][j - 1] + maze[1][j] + maze[1][j - 1] + maze[1][j + 1] == maze[0][j])
                    return true;
            }
            else if (i == n - 1 && j > 0 && j < m - 1)
            {
                if (maze[n - 1][j + 1] + maze[n - 1][j - 1] + maze[n - 2][j] + maze[n - 2][j - 1] + maze[n - 2][j + 1] == maze[n - 1][j])
                    return true;
            }
            else if (j == 0 && i > 0 && i < n - 1)
            {
                if (maze[i + 1][0] + maze[i - 1][0] + maze[i][1] + maze[i - 1][1] + maze[i + 1][1] == maze[i][0])
                    return true;
            }
            else if (j == n - 1 && i > 0 && i < m - 1)
            {
                if (maze[i + 1][m - 1] + maze[i - 1][m - 1] + maze[i][m - 2] + maze[i + 1][m - 2] + maze[i - 1][m - 2] == maze[i][m - 1])
                    return true;
            }
            else
            {
                if (maze[i][j + 1] + maze[i][j - 1] + maze[i - 1][j] + maze[i + 1][j] + maze[i - 1][j - 1] + maze[i - 1][j + 1] + maze[i + 1][j - 1] + maze[i + 1][j + 1] == maze[i][j])
                    return true;
            }
        }
    }
    return false;
}

void freeMaze(int** maze, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] maze[i];
    }

    delete[] maze;
}

/*
int main()
{
    int n, m;
    std::cin >> n >> m;
    int** maze = new int* [n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[m];
    }
    inputMaze(maze, n, m);
    std::cout << findElement(maze, n, m);
    freeMaze(maze, n);
}
*/

//Да се напише програма, която определя дали квадратна матрица A с размерност(1 <= n <= 20) е магически квадрат, 
//т.е.такава, че сумата от елементите от всички редове, стълбове и двата диагонала е еднаква.

void inputMaze(int** maze, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> maze[i][j];
        }
    }
}

bool isMagicalSquare(int** maze, int n)
{
    //rows
    int sumFirstRow = 0;
  
    for (int j = 0; j < n; j++)
    {
        sumFirstRow += maze[0][j];
    }

    int currSumRow = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            currSumRow += maze[i][j];
        }

        if (currSumRow != sumFirstRow)
            return false;
        currSumRow = 0;
    }

    //cols
    int sumFirstCol = 0;

    for (int i = 0; i < n; i++)
    {
        sumFirstCol += maze[i][0];
    }

    if (sumFirstCol != sumFirstRow)
        return false;

    int currSumCol = 0;
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            currSumCol += maze[i][j];
        }

        if (currSumCol != sumFirstCol)
            return false;
        currSumCol = 0;
    }

    //main diagonal
    int sumMainD = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                sumMainD += maze[i][j];
        }
    }

    if (sumMainD != sumFirstRow)
        return false;

    //second diagonal
    int sumSecD = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (j == n - i - 1)
                sumSecD += maze[i][j];
        }
    }

    if (sumSecD != sumMainD)
        return false;
    return true;

}

/*
int main()
{
    int n;
    std::cin >> n;
    int** maze = new int* [n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
    }
    inputMaze(maze, n);

    if (isMagicalSquare(maze,n))
        std::cout << "It's a magical square!";
    else
        std::cout << "Not a magical square!";
    freeMaze(maze, n);
}
*/
