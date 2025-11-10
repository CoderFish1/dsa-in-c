#include <stdio.h>

// function to print the array elements
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort function
void bubbleSort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for number of passes, no of passes = size-1
    {
        for (int j = 0; j < n - 1 - i; j++) // for number of comparsions , for i pass, comparsions = size-1-i;
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    bubbleSort(arr, n);

    printf("After sorting:-\n");
    printArray(arr, n);

    return 0;
}