#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// algorithm for selection sort
void selectionSort(int *arr, int n)
{
    int minElementIndex;
    for (int i = 0; i < n - 1; i++) // for loop for passes (which are size -1)
    {
        minElementIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minElementIndex])
            {
                minElementIndex = j;
            }
        }
        // logic to swap minElementIndex with i'th element if less
        int temp = arr[i];
        arr[i] = arr[minElementIndex];
        arr[minElementIndex] = temp;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements you want in the array :\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array elements :-\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting:-\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("After sorting:-\n");
    printArray(arr, n);

    return 0;
}