#include <iostream>
using namespace std;
#include <cmath>;

// Функции задача 0

bool cmpDoubles(double d1, double d2)
{
    const double EPS = 0.0001;
    return fabs(d1 - d2) < EPS;
}

bool isInGray(double x, double y)
{
    if (x < 2.000 && x > -2.000 && y > -7.000 && y < -6.000)
        return true;
    else return false;
}

double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool isInPink(double d1, double d2)
{
    double s = areaOfTriangle(-0.001, 0, -2.827, -2.827, -2.827, 2.827);
    double s1 = areaOfTriangle(d1, d2, -0.001, 0, -2.827, -2.827);
    double s2 = areaOfTriangle(-2.827, -2.827, d1, d2, -2.827, 2.827);
    double s3 = areaOfTriangle(-2.827, 2.827, -0.001, 0, d1, d2);
   
    if (cmpDoubles(s,s1+s2+s3)) 
    {
        return true;
    }

    return false;
}

bool isInRed(double d1, double d2)
{
    return (d1 < 0 && d1 > -2.828 && d2> 0 && abs(d1) < d2);
}

bool isInGreen(double d1, double d2)
{
    return (d1 > 0 && d1 < 2.828 && d2 > 0 && d1 < d2);
}

bool isInBlue(double d1, double d2)
{
    return (d1 < 0 && d1 > -2.828 && d2 < 0 && abs(d1) < abs(d2));
}

bool isInYellow(double d1, double d2)
{
    double s = areaOfTriangle(0.001, 0, 2.827, 2.827, 2.827, -2.827);
    double s1 = areaOfTriangle(d1, d2, 0.001, 0, 2.827, -2.827);
    double s2 = areaOfTriangle(2.827, 2.827, d1, d2, 2.827, -2.827);
    double s3 = areaOfTriangle(2.827, 2.827, 0.001, 0, d1, d2);

    if (cmpDoubles(s, s1 + s2 + s3) || (d1 > 0 && d1 < 2.828 && d2 < 0 && d1 <= abs(d2)))
    {
        return true;
    }

    return false;
}

bool isInPurple(double d1, double d2)
{
    return (d1 > 2.828 && d2 < 4);
}

bool isInWhite(double d1, double d2)
{
    return (d1 < -2.828 && d2 > -4);
}

// Функции задача 1

void function(int x, int k)
{
    int f1 = x;
    int res = 0;

    for (int i = 1; i <= k ; i++)
    {
        if (i == 1)
        {
            res = f1;
        }
        else
        {
            if (res % 2 == 0)
            {
                res = res / 2;
            }
            else
            {
                res = (3 * res) + 1;
            }
        }
    }

    cout << "f ("<< k << ") = " << res << endl;
}

// Функции задача 2

void barcode(int n)
{
    int count_blueberry = 0;
    int count_peach = 0;
    int count_roseHip = 0;

    while (n != 0)
    {
        if (n < 8)
        {
            break;
        }

        for (int i = 1; i <= 3; i++)
        {
            int code_country;
            cin >> code_country;
            n--;
        }

        int res = 0;
        for (int i = 1; i <= 4; i++)
        {
            int code_jam;
            cin >> code_jam;
            res = (res * 10) + code_jam;
            n--;
        }

        if (res % 7 == 0) count_blueberry++;
        if (res % 13 == 0) count_peach++;
        if (res % 17 == 0) count_roseHip++;

        int control;
        cin >> control;
        n--;
    }

    cout << "Blueberry jam: " << count_blueberry << endl;
    cout << "Peach jam: " << count_peach << endl;
    cout << "Rose Hip jam: " << count_roseHip << endl;
}

// Функции задача 3

bool IsInterestingNumber(int n)
{
    if (n >= 0 && n <= 9) return true;

    while (n > 9)
    {
        int lastNumber = n % 10;
        int toLastNumber = (n / 10) % 10;

        if (lastNumber % 2 == 0 && toLastNumber % 2 == 0 || lastNumber % 2 != 0 && toLastNumber % 2 != 0)
        {
            return false;
        }

        n /= 10;
    }
    
    return true;
}

int sumInterestingNumbers(int a, int b)
{
    int sum = 0;
    for (int i = a; i <= b; i++)
    {
        if (IsInterestingNumber(i))
            sum += i;
    }

    return sum;
}

// Функции задача 4

bool containsDigit(int n, int k)
{
    while (n != 0)
    {
        int lastDigit = n % 10;
        if (lastDigit == k)
        {
            return true;
        }
        n /= 10;
    } 
    return false;
}

bool isNumberValid(int n)
{   
    if (n < 1234 || n > 9876) return false;

    while(n > 9)
    {
        int lastDigit = n % 10;
        int num = n / 10;
        if (lastDigit == 0 || containsDigit(num,0) || containsDigit(num, lastDigit))
        {
            return false;
        }
        n /= 10;
    }
    
    return true;
}

int validNumberToGuess()
{
    int n = rand();

    while (!(isNumberValid(n)))
    {
        n = rand();
    }
    
    return n;
}

int getBulls(int toGuess, int myGuess)
{
    int count = 0;

    while (toGuess != 0)
    {
        int lastDigitMyGuess = myGuess % 10;
        int lastDigitToGuess = toGuess % 10;

        if (lastDigitMyGuess == lastDigitToGuess)
            count++;

        toGuess /= 10;
        myGuess /= 10;
    }
    
    return count;
}

int getSumOfBullsAndCows(int toGuess, int myGuess)
{
    int countBullsAndCows = 0;

    while (myGuess != 0)
    {
        int lastDigitMyGuess = myGuess % 10;

        if (containsDigit(toGuess, lastDigitMyGuess))
            countBullsAndCows++;

        myGuess /= 10;
    }

    return countBullsAndCows;
}

void getBullsAndCows(int toGuess, int myGuess, int& bulls, int& cows)
{
    bulls = getBulls(toGuess, myGuess);
    cows = getSumOfBullsAndCows(toGuess, myGuess) - bulls;
}

//Main функция на задача 0
/*

int main()
{
    double x, y;
    cin >> x >> y;
    if (isInGray(x, y))
    {
        cout << "Gray sector" << endl;
    }
    else 
    {
        if ((x * x) + (y * y) < 16)
        {
            if (isInPink(x, y)) cout << "Pink sector";
            else if (isInRed(x, y)) cout << "Red sector";
            else if (isInGreen(x, y)) cout << "Green sector";
            else if (isInBlue(x, y)) cout << "Blue sector";
            else if (isInYellow(x, y)) cout << "Yellow sector";
            else if (isInPurple(x, y)) cout << "Purple sector";
            else if (isInWhite(x, y)) cout << "In the circle, but not in a colored sector" << endl;
            else cout << "On a line" << endl;
        }
        else if((x * x) + (y * y) == 16)
        {
            cout<<"On the line of the crcle"<<endl;
        }  
        else
        {
            cout << "Out of the circle" << endl;
        }
    }
    return 0;
}

*/

//Main функция на задача 1
/*

int main()
{
    int x;
    cin >> x;
    function(x, 35);
    return 0;
}

*/

//Main функция на задача 2
/*

int main()
{
    int n;
    cin >> n;
    barcode(n);
}

*/

//Main функция на задача 3
///*

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "Sum: "<< sumInterestingNumbers(a, b);
    return 0;
}

//*/

//Main функция на задача 4
/*

int main()
{
    const int N = 10;
    int toGuess = validNumberToGuess();
    cout << "Try to guess the number!" << endl;
    cout << "You have " << N << " trys!" << endl;
    //cout << "Number to guess: " << toGuess << endl;

    int bulls = 0;
    int cows = 0;
    int myGuess;
    bool guessedNumber = false;

    for (int i = 1; i <= N; i++)
    {
        cout << "My guess " << i << ": ";
        cin >> myGuess;
        cout << endl;
      
        if (!(isNumberValid(myGuess)))
        {
            cout << "Invalid input" << endl;
            continue;
        }

        getBullsAndCows(toGuess, myGuess, bulls, cows);

        if (bulls == 4)
        {
            cout << "You guessed the number!"<<endl;
            guessedNumber = true;
            break;
        }
        else
        {
            cout << "Bulls: " << bulls << ", Cows: " << cows << endl;
        }
    }
    
    if (guessedNumber == false) cout << "Sorry, your trys are over!" << endl;

    cout << "Game over!" << endl;

    return 0;
}

*/ 
