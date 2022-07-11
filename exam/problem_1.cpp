#include <iostream>
int const CAPACITY = 1024;

bool isValidInput(int n, char* arr)
{
    char ch;
    int ind = 0;
    while (n != 0)
    {
        std::cin >> ch;
        if (ch != 'r' && ch != 'g' && ch != 'y')
        {
            return false;
        }
        n--;
        arr[ind++] = ch;
    }
    return true;
}

int countMoves(int n, char* arr, int ind)
{
    int count = 0;
    int newInd;

    while (ind < n)
    {   
        newInd = ind;
        if (arr[ind] == 'g' && ind != n - 1)
        {
            count++;
            newInd++;
            std::cout << ind << "->" << newInd << std::endl;
        }
        else if (arr[ind] == 'g' && ind == n - 1)
        {
            return count;
        }
        else if (arr[ind] == 'y')
        {
            bool foundGreen = false;
            for (int j = ind; j < n; j++)
            {
                if (arr[j] == 'g')
                {
                    count++;
                    newInd = j;
                    std::cout << ind << "->" << newInd<<std::endl;
                    foundGreen = true;
                    break;
                }
            }

            if (!foundGreen)
            {
                return count;
            }
        }
        else if (arr[ind] == 'r')
        {
            newInd++;
            std::cout << ind << "->" << newInd<<std::endl;
            return count;
        }

        ind = newInd;
    }
}

int main()
{
    char arr[CAPACITY];
    int n;
    std::cout << "Enter N: ";
    std::cin >> n;
    int startInd;
    std::cout << "Enter start index: ";
    std::cin >> startInd;
    if (isValidInput(n,arr))
    {
        std::cout << countMoves(n, arr, startInd);
    }
}
