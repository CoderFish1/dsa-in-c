#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// insertion sort algoritm
void insertionSort(int *arr, int n){
    int key , j;
    // for passes which are (size-1), also in insertionSort we start i from 1 as [sorted][unsorted] is the logic
    for (int i = 1; i <= n-1; i++) 
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    insertionSort(arr, n);

    printf("After sorting:-\n");
    printArray(arr, n);

    return 0;
}