#include<iostream> 

int fact(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * fact(n - 1);
}

int power(int n, int k)
{
	if (k == 0)
		return 1;
	if (k == 1)
		return n;
	return n * power(n, k - 1);
}

int sumDigits(int n)
{
	if (n >= 0 && n <= 9)
		return n;
	return n % 10 + sumDigits(n / 10);
}

int countDigits(int n)
{
	int count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return count;
}

int reverse(int n)
{
	if (n >= 0 && n <= 9)
		return n;

	int countDig = countDigits(n);

	return (n % 10) * power(10,countDig - 1) + reverse(n / 10);
}
