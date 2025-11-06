#include <stdio.h>

void display(int arr[],int n){
    // traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int indDelete(int arr[], int index, int size){
    for(int i = index; i <= size - 1; i++){
        arr[i] = arr[i+1];
    }
    return 1;
}

int main(){
    int arr[100] = {1,3,4,5,52,525,62};
    int size = 7, index = 5; // index 5 = 525

    printf("Before deletion:-\n");
    display(arr, size);                         

    indDelete(arr, index, size);

    size -= 1;
                                  
    printf("After deletion:-\n");
    display(arr, size);

    return 0;
}