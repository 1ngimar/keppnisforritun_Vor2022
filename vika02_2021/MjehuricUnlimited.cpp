#include <iostream>

using namespace std;

// This code is junk




// pls, do not try to improve this any further




// pls stop reading and do something else





// pls


/**
 * @brief prints everything inside a 1D int array of unspecified size as
 *  one line with whitespace between numbers
 *
 * @param arr 1D array (as pointer) of unspecified size
 * @param N size of array
 */
void printArray(int *arr, int N)
{
    for (int i = 0; i < N; i++) // Type inference by const reference.
    {
        std::cout << arr[i] << " ";
    }
    std::cout << endl;
}

/**
 * @brief Swaps the integers in a 1D array
 *
 * @param arr pointer to a 1D integer array that will be changed
 * @param x position of the number that will be swapped with y
 * @param y position of the number that will be swapped with x
 * @return int* a 1D arry of integers
 */
int *swap(int *arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    return arr;
}

bool isOrdered(int *arr, int N)
{
    for (int i = 1; i < N + 1; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

void weirdSort(int *arr, int N)
{
    for (int i = 1; i < N + 1; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            arr = swap(arr, i - 1, i);
            printArray(arr, N);
        }
    }
    if (!isOrdered(arr, N))
    {
        weirdSort(arr, N);
    }
}

int main()
{
    int *arr, n;
    std::cin >> n;
    arr = new int[n];
    // int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    weirdSort(arr, n);
    return 0;
}