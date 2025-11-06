// ABSTRACT DATA TYPES
#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

// // with typedef
// typedef struct{
//     int total_size;
//     int used_size;
//     int *ptr;
// } myArray;

void createArray(struct myArray *a, int tSize, int uSize)
{
    // (*a).total_size =  tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void setVal(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        int n;
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}
void showVal(struct myArray *a)

{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

int main()
{
    struct myArray marks;
    // myArray marks;

    createArray(&marks, 10, 2);

    setVal(&marks);
    showVal(&marks);

    free(marks.ptr);
    return 0;
}
