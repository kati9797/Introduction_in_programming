
int convert(int* num, int iter)
{
    iter--;
    int result = 0;
    int i = 0;

    while (iter >= 0)
    {
        result += (num[i++] * pow(10, iter));
        iter--;
    }
    return result;
}

int calculate(char* string)
{
    int firstNum[24];
    int firstIter = 0;
    int secNum[24];
    int secIter = 0;
    char operation;
    bool foundOperation = false;

    char* iter = string;
    while (*iter != '\0')
    {
        if (isPrefix(iter, "one") && !foundOperation)
        {
            iter += strlen("one");
            firstNum[firstIter++] = 1;
        }
        else if (isPrefix(iter, "one") && foundOperation)
        {
            iter += strlen("one");
            secNum[secIter++] = 1;
        }
        else if (isPrefix(iter, "two") && !foundOperation)
        {
            iter += strlen("two");
            firstNum[firstIter++] = 2;
        }
        else if (isPrefix(iter, "two") && foundOperation)
        {
            iter += strlen("two");
            secNum[secIter++] = 2;
        }
        else if (isPrefix(iter, "three") && !foundOperation)
        {
            iter += strlen("three");
            firstNum[firstIter++] = 3;
        }
        else if (isPrefix(iter, "three") && foundOperation)
        {
            iter += strlen("three");
            secNum[secIter++] = 3;
        }
        else if (isPrefix(iter, "four") && !foundOperation)
        {
            iter += strlen("four");
            firstNum[firstIter++] = 4;
        }
        else if (isPrefix(iter, "four") && foundOperation)
        {
            iter += strlen("four");
            secNum[secIter++] = 4;
        }
        else if (isPrefix(iter, "five") && !foundOperation)
        {
            iter += strlen("five");
            firstNum[firstIter++] = 5;
        }
        else if (isPrefix(iter, "five") && foundOperation)
        {
            iter += strlen("five");
            secNum[secIter++] = 5;
        }
        else if (isPrefix(iter, "six") && !foundOperation)
        {
            iter += strlen("six");
            firstNum[firstIter++] = 6;
        }
        else if (isPrefix(iter, "six") && foundOperation)
        {
            iter += strlen("six");
            secNum[secIter++] = 6;
        }
        else if (isPrefix(iter, "seven") && !foundOperation)
        {
            iter += strlen("seven");
            firstNum[firstIter++] = 7;
        }
        else if (isPrefix(iter, "seven") && foundOperation)
        {
            iter += strlen("seven");
            secNum[secIter++] = 7;
        }
        else if (isPrefix(iter, "eight") && !foundOperation)
        {
            iter += strlen("eight");
            firstNum[firstIter++] = 8;
        }
        else if (isPrefix(iter, "eight") && foundOperation)
        {
            iter += strlen("eight");
            secNum[secIter++] = 8;
        }
        else if (isPrefix(iter, "nine") && !foundOperation)
        {
            iter += strlen("nine");
            firstNum[firstIter++] = 9;
        }
        else if (isPrefix(iter, "nine") && foundOperation)
        {
            iter += strlen("nine");
            secNum[secIter++] = 9;
        }
        else if (isPrefix(iter, "plus"))
        {
            iter+=strlen("plus");
            operation = '+';
            foundOperation = true;
        }
        else if (isPrefix(iter, "minus"))
        {
            iter += strlen("minus");
            operation = '-';
            foundOperation = true;
        }
    }

    if (!foundOperation)
    {
        return 0;
    }
    if (operation == '+')
    {
        return convert(firstNum, firstIter) + convert(secNum, secIter);
    }
    else if (operation == '-')
    {
        return convert(firstNum, firstIter) - convert(secNum, secIter);
    }
}

int main()
{
    char string[CAPACITY] = "oneminustwothree";
    std::cout << calculate(string);
}
