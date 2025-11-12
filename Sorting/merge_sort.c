#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int low, int mid, int high)
{
    int i, j, k, b[100];
    i = low;
    j = mid + 1;
    k = low;

    while(i<=mid && j<=high){
        if(arr[i] < arr[j]){
            b[k] = arr[i];
            i++;k++;
        }
        else{
            b[k] = arr[j];
            j++;k++;
        }
    }
    while(i<=mid){
        b[k] = arr[i];
        i++;k++;
    }
    while(j<=high){
        b[k] = arr[j];
        j++;k++;
    }
    
    for(int i = low; i <= high; i++){
        arr[i] = b[i];
    }
}

void mergesort(int *arr, int low, int high)
{
    int mid;
    if(low < high){
        mid = (low + high)/2;

        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
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

    mergesort(arr, 0, n-1);

    printf("After sorting:-\n");
    printArray(arr, n);
    return 0;
}