#include <iostream>
const int N = 9;

bool isValidInd(char C[3][3], int x, int y, char* word)
{
    return x >= 0 && x < 3 && y >= 0 && y < 3 && C[x][y] == word[0];
}

bool rec(char C[3][3], char* word, int x, int y)
{
    if (!isValidInd(C, x, y, word))
    {
        return false;
    }

    if (word[1] == '\0')
    {
        return true;
    }

    return rec(C, word + 1, x + 1, y) ||
           rec(C, word + 1, x - 1, y) ||
           rec(C, word + 1, x, y + 1) ||
           rec(C, word + 1, x, y - 1);
}

bool crossword(char C[3][3], char** words, int n)
{
    bool lamp = false;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rec(C, words[k], i, j))
                {
                    lamp = true;
                }
            }
        } 
        if (!lamp)
            return false;
        lamp = false;
    }
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    char** words = new char* [n];
    for (int i = 0; i < n; i++)
    {
        words[i] = new char[N];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> words[i];
    }
    
    char C[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> C[i][j];
        }
    }
    
    std::cout << crossword(C, words, n);
    
    for (int i = 0; i < n; i++)
    {
        delete[] words[i];
    }
    delete[] words;
}

 /*
 ----> true
3
cat
what
not
c a t
w h o
w i n
 */

 /*
 ----> false
3
cat
hot
chat
c a t
w h o
w i n
 */
