#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>

int const MAX_SIZE = 1024;

// Task 1

bool containsDigit(int num, int dig)
{
    while (num != 0)
    {
        if (num % 10 == dig)
            return true;
        else
            num /= 10;
    }
    return false;
}

void strengthOfNumbers(int first, int second)
{

    if (first < 0)
    {
        first = -first;
    }

    if (second < 0)
    {
        second = -second;
    }

    int n1 = first;
    int n2 = second;

    // first -> second
    while (n1 != 0)
    {
        if (!containsDigit(second, n1 % 10))
        {
            // first не се съд. в second
            while (n2 != 0)
            {
                if (!containsDigit(first, n2 % 10))
                {
                    std::cout << "Not comperable!" << std::endl;
                    return;
                }
                n2 /= 10;
            }

            std::cout << "The second is weaker!" << std::endl;
            return;
        }
        n1 /= 10;
    }

    n1 = first;
    n2 = second;
    while (n2 != 0)
    {
        if (!containsDigit(n1, n2 % 10))
        {
            std::cout << "The first is weaker!" << std::endl;
            return;
        }
        n2 /= 10;
    }

    std::cout << "Equal strength!" << std::endl;
}

// Task 2

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    double temp = sqrt(n);

    for (int i = 2; i <= temp; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Task 2

void readArr(int arr[], int n)
{
    std::cout << "Enter array: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        while (arr[i] < 0)
        {
            std::cin>>arr[i];
        }
    }
}

int countProblems(int arr[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isPrime(arr[i]) && !isPrime(arr[j]))
                cnt++;
            else if ((isPrime(arr[i]) && isPrime(arr[j])) && (arr[j] < arr[i]))
                cnt++;
        }
    }

    return cnt;
}

// Task 3

int mod(int n)
{
    if (n < 0)
        return -n;
    else
        return n;
}

bool hasPath(int arr1[], int arr2[], int size1, int size2, double& path)
{
    double path1 = 0;
    double path2 = 0;

    for (int i = 0; i < size1 - 2 ; i++)
    {
        path1 += mod(arr1[i + 2] - arr1[i]);
    }

    for (int i = 0; i < size2 - 2; i++)
    {
        path2 += mod(arr2[i + 2] - arr2[i]);
    }

    if (path1 == path2)
    {
        path = path1;
    }

    return (path1 == path2);
}

// Task 5

void drawBus(int k)
{
    for (int i = 0; i <k ; i++)
    {
        std::cout << ' ';
    }

    std::cout << ' ';
    for (int i = 0; i < 18; i++)
    {
        std::cout << '_';
    }
    std::cout << std::endl;

    for (int i = 0; i < k; i++)
    {
        std::cout << ' ';
    }

    for (int i = 0; i < 7; i++)
    {
        if (i == 0)
        {
            std::cout << "|  ";
        }
        else if (i == 4 || i == 5)
        {
            std::cout << "| ";
        }
        else if (i == 6)
            std::cout << '\\' << std::endl;
        else
            std::cout << "|   ";
    }

    for (int i = 0; i < k; i++)
    {
        std::cout << ' ';
    }

    for (int i = 0; i < 7; i++)
    {
        if (i == 0 || i == 5)
        {
            std::cout << "|__";
        }
        else if (i == 4)
        {
            std::cout << "|_";
        }
        else if (i == 6)
            std::cout << '\\' << std::endl;
        else
            std::cout << "|___";
    }

    for (int i = 0; i < k; i++)
    {
        std::cout << ' ';
    }

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
            std::cout << "|              ";
        else if (i == 1)
            std::cout << "| ";
        else
            std::cout << "|   " << '\\' << std::endl;
    }

    for (int i = 0; i < k; i++)
    {
        std::cout << ' ';
    }

    for (int i = 0; i < 7; i++)
    {
        if (i == 0 || i == 6)
            std::cout << '\'';
        else if (i == 1)
            std::cout << "__";
        else if (i == 2 || i == 3 || i == 5)
            std::cout << "(o)";
        else
            std::cout << "_________";
    }
}
    
int main()
{
    //Task 1
    
    //strengthOfNumbers(123, 3121);
    //strengthOfNumbers(12, 1523);
    //strengthOfNumbers(-43550, 430);
    //strengthOfNumbers(123, 456);
    //strengthOfNumbers(189, -99018);
    //strengthOfNumbers(101010, 10);
    
    //Task 2

    //int arr[MAX_SIZE];
    //int length;
    //std::cout << "Enter length of array: ";
    //std::cin >> length;
    //readArr(arr, length);
    //std::cout<<countProblems(arr,length);

    //Task 3
    /*
    std::cout << "Enter size1 and size2: ";
    int size1, size2;
    std::cin >> size1 >> size2;
    if (size1 > MAX_SIZE || size2 > MAX_SIZE)
    {
        throw std::invalid_argument("Invalid size!");
       
    }
    int arr1[2 * MAX_SIZE];
    int arr2[2 * MAX_SIZE];
    int arrSize1 = size1 * 2;
    int arrSize2 = size2 * 2;
    readArr(arr1, arrSize1);
    readArr(arr2, arrSize2);

    double path = 0;
    if (hasPath(arr1, arr2, arrSize1, arrSize2, path))
    {
        std::cout << "true" << std::endl;
        std::cout << std::fixed << std::setprecision(2) << path << std::endl;
    }
    else
    {
        std::cout << "false" <<std::endl;
    }
    */

    
    // Task 5
    /*
    using namespace std::chrono_literals;
    for (int i = 0; i < 100; i++)
    {
        drawBus(i);
        std::this_thread::sleep_for(200ms);
        system("CLS");
    }
    */
}
