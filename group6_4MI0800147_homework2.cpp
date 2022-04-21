// group6_4MI0800147_homework2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <cmath>
#pragma warning (disable:4996)

const int CAPACITY_TEXT = 1024;
const int CAP_DIC_1 = 128;
const int CAP_DIC_2 = 100;
const int CAPACITY_NEW_TEXT = 2048;

// Фукции на задача 0

void inputText(int n, char text[CAPACITY_TEXT])
{
    char ch;
    int textIter = 0;
    while (n >= 0)
    {
        std::cin.get(ch);
        text[textIter++] = ch;
        n--;
    }
    text[textIter] = '\0';
}

void makeOneRecord(char wrongWords[CAP_DIC_1][CAP_DIC_2], char correctWords[CAP_DIC_1][CAP_DIC_2], int n)
{
    char ch;
    int wordIter = 0;
    std::cin.get(ch);

    do
    {
       wrongWords[n][wordIter++] = ch;
       std::cin.get(ch);
    } 
    while (ch != '-');
    wrongWords[n][wordIter] = '\0';
    wordIter = 0;

    std::cin.get(ch);
    
    do
    {
        correctWords[n][wordIter++] = ch;
        std::cin.get(ch);
    }

    while (ch != '\n');
    correctWords[n][wordIter] = '\0';
}

void inputDictionary(int size, char wrongWords[CAP_DIC_1][CAP_DIC_2], char correctWords[CAP_DIC_1][CAP_DIC_2])
{
    for (int i = 0; i < size; i++)
    {
        makeOneRecord(wrongWords, correctWords, i);
    }
}

bool isPuctuationMark(char ch)
{
    if ((ch == '.') || (ch == '!') || (ch == '?') || (ch == '(') || (ch == ')') || (ch == '-') || (ch == '+') || (ch == '-') || (ch == ':') || (ch == '%') || (ch == ',') || (ch == '='))
    {
        return true;
    }
    return false;
}

bool needSpaceBefore(char ch)
{
    if ((ch == '(') || (ch == '-') || (ch == '+') || (ch == '-') || (ch == ':') || (ch == '%') || (ch == '=') )
    {
        return true;
    }
    return false;
}

bool needSpaceAfter(char ch)
{
    if (ch == ')' || ch == '.' || ch == '!' || ch == '?' || ch == ',')
    {
        return true;
    }
    return false;
}

bool isPrefix(char* text, char* prefix)
{
    int iter = 0;
    while (prefix[iter] != '\0')
    {
        if (text[iter] == '\0' || text[iter] != prefix[iter])
        {
            return false;
        }
        else
        {
            iter++;
        }
    }

    return true;
}

void NewTextToCheck(char* text, char* resText, int currentInd)
{
    int lengthText = strlen(text);
    for (int i = currentInd, resTextInd = 0; i < lengthText; i++)
    {
        resText[resTextInd++] = text[i];
    }
}

bool foundWrongWord(char* text, char wrongWords[CAP_DIC_1][CAP_DIC_2], int sizeOfDictionary, int currentInd, int& wrongWordInd)
{
    int lengthText = strlen(text);
    char* textToCheck = new char[lengthText - currentInd];
    NewTextToCheck(text, textToCheck, currentInd);

    for (int i = 0; i < sizeOfDictionary; i++)
    {
        if (isPrefix(textToCheck, wrongWords[i]))
        {
            wrongWordInd = i;
            delete[] textToCheck;
            return true;
        }
    }

    delete[] textToCheck;
    return false;
}

bool endOfTheSentance(char ch, int length, int index)
{
    if ((ch == '/n') || (index == length - 1))
    {
        return true;
    }
    return false;
}

void autoCorrect(char* text, char newText[CAPACITY_NEW_TEXT], char wrongWords[CAP_DIC_1][CAP_DIC_2], char correctWords[CAP_DIC_1][CAP_DIC_2], int sizeOfDictionary)
{
    int lengthText = strlen(text);
    int newTextInd = 0;
    int wrongWordInd = 0;

    for (int i = 0; i < lengthText; i++)
    {
        if (isPuctuationMark(text[i]))
        {
            if (needSpaceBefore(text[i]))
            {
                if ((i - 1 > 0) && text[i - 1] != ' ')
                newText[newTextInd++] = ' '; 
                newText[newTextInd++] = text[i];
            }
            else if (needSpaceAfter(text[i]))
            {
                if ((i + 1) < lengthText && text[i + 1] != ' ')
                {
                    newText[newTextInd++] = text[i];
                    newText[newTextInd++] = ' ';
                }
            }
        }
        else if (foundWrongWord(text, wrongWords, sizeOfDictionary, i, wrongWordInd))
        {
            int lengthReplace = (strlen(correctWords[wrongWordInd]));
                for (int j = 0; j < lengthReplace; j++)
                {
                    newText[newTextInd++] = correctWords[wrongWordInd][j];
                }
            int lengthPattern = (strlen(wrongWords[wrongWordInd]) - 1);
            i += lengthPattern;
        }
        else if (endOfTheSentance(text[i],lengthText,i))
        {
            if (text[i] == ' ')
            {
                newText[newTextInd++] = text[i];
            }
            if (text[i] == '"' && text[i-1] != '.')
            {   
                newText[newTextInd++] = '.';
                newText[newTextInd++] = '"';
            }
        }
        else
        {
            newText[newTextInd++] = text[i];
        }
    }
    newText[newTextInd] = '\0';
}

// Функции на задача 1

void inputMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << '[' << matrix[i][j] << ']' << " ";
        }
        std::cout << std::endl;
    }
}

void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void removeElements(int*& arr, int m)
{
    int* newArr = new int[m];
    for (int i = 0; i < m; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;

    arr = newArr;
}

void transformMatrix(int**& matrixA, int** matrixB, int& N1, int& M1, int N2, int M2)
{

    if (N2 < N1)
    {
        for (int i = N2; i < N1; i++)
        {
            delete[] matrixA[i];
        }
        N1 = N2;
    }

    if (M2 < M1)
    {
        for (int i = 0; i < N1; i++)
        {
            removeElements(matrixA[i], M2);
        }
        M1 = M2;
    }

    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < M1; j++)
        {
            if (matrixA[i][j] < matrixB[i][j])
            {
                matrixA[i][j] = matrixB[i][j];
            }

            if (matrixA[i][j] > matrixB[i][j])
            {
                matrixA[i][j] = -(matrixA[i][j]);
            }
        }
    }

}

// Функции на задача 2'

void inputField(char** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols];
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void freeField(char** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

char invertLetter(char ch)
{
    const int distance = 'a' - 'A';
    if (ch >= 'A' && ch <= 'Z') ch += distance;
    else if (ch >= 'a' && ch <= 'z') ch -= distance;

    return ch;
}

bool isValid(char** matrix, int rows, int cols, int i, int j)
{
    if (i < 0 || i > rows - 1 || j < 0 || j > cols - 1)
    {
        return false;
    }
    else if (matrix[i][j] == 'r' || matrix[i][j] == 'l' || matrix[i][j] == 'u' || matrix[i][j] == 'd')
    {
        return false;
    }

    return true;
}

void changeDirection(char** matrix, int i, int j, int& x, int& y)
{
    x = i;
    y = j;

    if (matrix[x][y] == 'R')
    {
        y++;
    }
    else if (matrix[x][y] == 'L')
    {
        y--;
    }
    else if (matrix[x][y] == 'U')
    {
        x--;
    }
    else if (matrix[x][y] == 'D')
    {
        x++;
    }
}

void moveThroughTheField(char** matrix, int rows, int cols, int i, int j, int& moves)
{
    if (isValid(matrix, rows, cols, i, j) == false)
    {
        return;
    }

    int x, y;
    
    changeDirection(matrix, i, j, x, y);
    matrix[i][j]=invertLetter(matrix[i][j]);

    moveThroughTheField(matrix, rows, cols, x, y, moves);
    moves++;

    matrix[i][j] = invertLetter(matrix[i][j]);
}

void findTheBestPath(char** matrix, int rows, int cols)
{
    int bestMoves = -1;
    int resX=-1, resY=-1;
    int currentMoves;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        { 
            currentMoves = 0;
            moveThroughTheField(matrix, rows, cols, i, j, currentMoves);
            
            if (currentMoves > bestMoves)
            {
                bestMoves = currentMoves;
                resX = i;
                resY = j;
            }
        }
    }

    std::cout << "Best starting point is [" << resX << ',' << resY << ']' << std::endl;
}

// Main - функция на задача 0

/*
int main()
{
    int numberOfSymbols;
    std::cout << "Enter number of symbols : ";
    std::cin >> numberOfSymbols;
    char text[CAPACITY_TEXT];
    std::cout << "Enter text : ";
    inputText(numberOfSymbols, text);

    int sizeOfDictionary;
    std::cout << "Enter number of words in the dictionary : ";
    std::cin >> sizeOfDictionary;
    char wrongWords[CAP_DIC_1][CAP_DIC_2];
    char correctWords[CAP_DIC_1][CAP_DIC_2];
    std::cout << "Enter wrong word-correct word : "<< std::endl;
    inputDictionary(sizeOfDictionary, wrongWords, correctWords);

    char newText[CAPACITY_NEW_TEXT];
    autoCorrect(text, newText, wrongWords, correctWords, sizeOfDictionary);
    
    std::cout << "Corrected text: " << std::endl;
    std::cout << newText;
    return 0;
}
*/

// Main - функция на задача 1

/*
int main()
{
    int N1, M1, N2, M2;
    std::cout << "Enter N1: ";
    std::cin >> N1;
    std::cout << std::endl;
    std::cout << "Enter M1: ";
    std::cin >> M1;
    std::cout << std::endl;
    std::cout << "Enter N2: ";
    std::cin >> N2;
    std::cout << std::endl;
    std::cout << "Enter M2: ";
    std::cin >> M2;
    std::cout << std::endl;

    int** A = new int* [N1];
    int** B = new int* [N2];

    std::cout << "A: " << std::endl;
    inputMatrix(A, N1, M1);

    std::cout << "B: " << std::endl;
    inputMatrix(B, N2, M2);

    transformMatrix(A, B, N1, M1, N2, M2);
    std::cout << "Transformed A:" << std::endl;
    printMatrix(A, N1, M1);

    freeMatrix(A,N1);
    freeMatrix(B, N2);

    return 0;
}
*/

// Main - функция на задача 2'

/*
int main()
{
    int N, M;
    std::cout << "Enter N: ";
    std::cin >> N; 
    std::cout<<std::endl;
    std::cout << "Enter M: ";
    std::cin >> M;
    std::cout << std::endl;

    char** field = new char* [N];
    std::cout << "Enter field: " << std::endl;
    inputField(field, N, M);

    findTheBestPath(field, N, M);
    
    freeField(field, N);

    return 0;
}
*/
