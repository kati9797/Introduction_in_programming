#include <iostream>

// Възможна ли е конкатенация

bool isSufix(int n, int sufix)
{
	int lastNumSuf = sufix % 10;
	while (sufix != 0)
	{
		int lastNum = n % 10;
		if (lastNum != lastNumSuf)
			return false;
		n /= 10;
		sufix /= 10;
		lastNumSuf = sufix % 10;
	}
	return true;
}

bool isInfix(int n, int infix)
{
	n /= 10;
	while (n >= 10)
	{
		if (isSufix(n, infix))
			return true;
		n /= 10;
	}
	return false;

}

bool concat(int N, int K)
{
	return isInfix(N, K);
}

/*
int main()
{
	int N, K;
	std::cin >> N >> K;

	std::cout << concat(N, K);
}
*/

// Стринг
// Броя на малките и големите латински букви
// Произведение на числата от стринга

bool isLower(char ch)
{
	return (ch >= 'a' && ch <= 'z');
}

bool isUpper(char ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

void countLowerAndUpperCases(char str[], int &lower, int &upper)
{
	char* ptr = str;
	while (*ptr != '\0')
	{
		if (isLower(*ptr))
			lower++;
		else if (isUpper(*ptr))
			upper++;

		ptr++;
	}
}

bool isDigit(char ch)
{
	return (ch >= '1' && ch <= '9');
}

int convertToInt(char ch)
{
	return ch - '0';
}

int calc(char str[])
{
	int product = 1;
	int iter = 0;
	int countDig = 0;
	while (str[iter] != '\0')
	{
		if (isDigit(str[iter]))
		{
			int startIter = iter;
			
			while (isDigit(str[iter]))
			{
				countDig++;
				iter++;
			}
			
			int currProduct = 0;
			while (countDig != 0)
			{
				currProduct += convertToInt(str[startIter]) * pow(10, countDig - 1);
				startIter++;
				countDig--;
			}
		
			product *= currProduct;
			currProduct = 0;
			
		}
		else
		{
			iter++;
		}
	}

	return product;
}
