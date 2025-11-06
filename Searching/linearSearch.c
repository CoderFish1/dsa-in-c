#include <stdio.h>
int linearSearch(int arr[], int element, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {35, 6345, 63, 23, 1, 52, 5, 6, 2, 6, 99, 100};

    int size = sizeof(arr) / sizeof(int);
    int element = 1;

    int searchIndex = linearSearch(arr, element, size);
    printf("The element %d is found at %d index", element, searchIndex);
}