#include <iostream>

// AC

using namespace std;

/**
 * @brief prints everyting inside a 1D int array ONLY OF SIZE 5 in 
 *  one line with whitespace between numbers
 * 
 * @param arr 1D array that must be of size 5
 */
void printArray(int arr[5])
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i];
        if (i != 4)
        {
            std::cout << " ";
        }
        else
        {
            std::cout << endl;
        }
    }
}

/**
 * @brief Swaps the integers in a 1D array
 * 
 * @param arr pointer to a 1D integer array that will be changed 
 * @param x position of the number that will be swapped with y
 * @param y position of the number that will be swapped with x
 */
void swap(int *arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    printArray(arr);
}

int main()
{
    // initializing array based on the input order
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        std::cin >> arr[i];
    }

    int temp;
    while (true)
    {
        if (arr[0] > arr[1])
        {
            swap(arr, 0, 1);
        }
        if (arr[1] > arr[2])
        {
            swap(arr, 1, 2);
        }
        if (arr[2] > arr[3])
        {
            swap(arr, 2, 3);
        }
        if (arr[3] > arr[4])
        {
            swap(arr, 3, 4);
        }
        if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5)
        {
            break;
        }
    }
    return 0;
}