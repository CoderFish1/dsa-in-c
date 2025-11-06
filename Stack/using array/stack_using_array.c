#include <stdio.h>
#include <stdlib.h>

// Stack implementation
struct stack
{
    int size;
    int top;
    int *arr;
};

// function to check if stack is empty or not
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to checkif stack is full or not
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    // struct stack s;
    // s.size = 100;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 3;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 1;
    s->top++;
    s->arr[1] = 2;
    s->top++;
    s->arr[2] = 3;
    s->top++;

    if (isEmpty(s))
    {
        printf("The stack is Empty\n");
    }
    else
    {
        printf("The stck is not Empty\n");
    }

    if (isFull(s))
    {
        printf("The stack is full\n");
    }
    else
    {
        printf("The stck is not full\n");
    }

    return 0;
}