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
