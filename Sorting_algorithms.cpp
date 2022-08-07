#include <iostream>

void swap(int& firstEl, int& secEl)
{
    int temp = firstEl;
    firstEl = secEl;
    secEl = temp;
}

// selection sort
void selectionSort(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minEl = arr[i];
        int minInd = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < minEl)
            {
                minEl = arr[j];
                minInd = j;
            }
        }
        if (minInd != i)
            swap(arr[i], arr[minInd]);
    }
}

// bubble sort
void bubbleSort(int arr[], int length)
{
    bool isSwapped = false;
    for(int i = 0; i < length - 1; i++)
    {
        isSwapped = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
            return;
    }
}

// binary search
bool binarySearch(int arr[], int n, int searched)
{
    int left = n - 1;
    int right = 0;
    
    while (right <= left)
    {
        int mid = right + (left - right) / 2;
        if (arr[mid] == searched)
            return true;
        else if (arr[mid] > searched)
            left = mid - 1;
        else
            right = mid + 1;
    }
    return false;
}

int main()
{
    
    int arr[] = { 5, 2, 1, 6, 3, 9, 8 };
    selectionSort(arr, 7);
    //bubbleSort(arr, 7);
    for (int i = 0; i < 7; i++)    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << binarySearch(arr, 7, 1)<<std::endl;
    std::cout << binarySearch(arr, 7, 0) << std::endl;
}
