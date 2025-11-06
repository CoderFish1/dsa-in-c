#include <stdio.h>
int binarySearch(int arr[], int element, int size)
{
    int low = 0; 
    int mid;
    int high = size - 1;

    // searching starts
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    } // searching ends
    return -1;
}
int main()
{
    // for binary search the array should be sorted
    int arr[] = {2, 5, 6, 7, 33, 60, 83, 100, 333, 636, 15252};

    int size = sizeof(arr)/sizeof(int);
    int element = 33;

    int binaryIndex = binarySearch(arr, element, size);

    printf("The element %d is at %d index.", element, binaryIndex);

    return 0;
}