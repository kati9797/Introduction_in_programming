#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
const int CAPACITY = 128;

// finds if string is prefix of another string
bool isPrefix(const char* text, const char* prefix)
{
	int ind = 0;
	while (prefix[ind] != '\0')
	{
		if (text[ind] == '\0' || text[ind] != prefix[ind])
			return false;
		ind++;
	}
	return true;
}

// replace word in text
void stringReplace(char* text, const char* pattern, char* replace)
{
	char newText[CAPACITY];
	int newTextInd = 0;
	char* textIter = text;
	int lengthPattern = strlen(pattern);
	int lengthReplace = strlen(replace);

	while (*textIter != '\0')
	{
		if (isPrefix(textIter, pattern)) 
		{
			newText[newTextInd] = '\0';
			strcat(newText, replace);
			newTextInd += lengthReplace;
			textIter += lengthPattern;
		}
		else
		{
			newText[newTextInd++] = *textIter;
			textIter++;
		}
	}
	newText[newTextInd] = '\0';
	strcpy(text, newText);
}

// converts all lower cases to capital
void toUpper(char* string)
{
	char* iter = string;
	int distance = 'a' - 'A';
	while (*iter != '\0')
	{
	if (*iter >= 'a' && *iter <= 'z')
	{
		*iter -= distance;
	}
	else
	{
		iter++;
	}
	}
}

// converts all capital cases to lower
void toLower(char* string)
{
	char* iter = string;
	int distance = 'a' - 'A';
	while (*iter != '\0')
	{
		if (*iter >= 'A' && *iter <= 'Z')
		{
			*iter += distance;
		}
		else
		{
			iter++;
		}
	}
}

// finds if char is delimiter
bool isDelimiter(char c)
{
	return (c == ' ' || c == ',' || c == '.' || c == '?' || c == '!' || c == '\t');
}

// counts words in text
int countWords(char* string)
{
	char* iter = string;
	int count = 0;
	bool foundWord = false;

	do
	{
		if (!isDelimiter(*iter) && !foundWord)
		{
			iter++;
		}
		else if (!isDelimiter(*iter) && foundWord)
		{
			iter++;
			foundWord = false;
		}
		else if (isDelimiter(*iter) && !foundWord)
		{
			count++;
			foundWord = true;
			iter++;
		}
		else if (isDelimiter(*iter) && foundWord)
		{
			iter++;
		}
	} while (*iter != '\0');

	return count;
}

void saveWordsInArray(char* text, char arr[CAPACITY][CAPACITY])
{
	char* iter = text;
	char currentWord[CAPACITY];
	int wordIter = 0;
	int indArr = 0;
	do
	{
		if (!isDelimiter(*iter))
		{
			do
			{
				arr[indArr][wordIter++] = *iter;
				iter++;
			} 
			while (!isDelimiter(*iter));
			arr[indArr][wordIter] = '\0';
			wordIter = 0;
			indArr++;
		}
		else
		{
			iter++;
		}

	} while (*iter != '\0');
}

// finds most common word in text
char* mostCommonWord(char arr[CAPACITY][CAPACITY], int count)
{
	int commonWords[CAPACITY];
	int ind = 0;
	int currentCount = 0;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (strcmp(arr[i], arr[j]) == 0)
			{
				currentCount++;
			}
		}
		commonWords[ind++] = currentCount;
		currentCount = 0;
	}

	int max = commonWords[0];
	int maxInd = 0;
	for (int i = 0; i < count; i++)
	{
		if (commonWords[i] > max)
		{
			max = commonWords[i];
			maxInd = i;
		}
	}

	return arr[maxInd];
}

// finds the smallest lexicografic word in text
char* findSmallestLexWord(char arrWords[CAPACITY][CAPACITY], int count)
{
	char* smallestWord = arrWords[0];
	for (int i = 0; i < count; i++)
	{
		toLower(arrWords[i]);
		if (strcmp(arrWords[i], smallestWord) < 0)
		{
			strcpy(smallestWord, arrWords[i]);
		}
	}
	return smallestWord;
}

// find the longest sequence of letters in string - exam 01.02.2019
unsigned longestSequence(char* s)
{
	char ch;
	char* iter = s;
	unsigned count = 1;
	unsigned maxCount = count;
	while (*iter != '\0')
	{
		ch = *iter;
		iter++;
		while (*iter == ch)
		{
			count++;
			iter++;
		}

		if (count > 1)
		{
			if (maxCount < count)
				maxCount = count;
			count = 1;
		}

	}

	return maxCount;
}

int main()
{
	char text[CAPACITY] = "Me? Why always me?";
	//char pattern[] = "best";
	//char replace[] = "worst";

	char arrWords[CAPACITY][CAPACITY];
	int count = countWords(text);
	saveWordsInArray(text, arrWords);
	//std::cout << mostCommonWord(arrWords, count);

	std::cout << findSmallestLexWord(arrWords, count);
}
