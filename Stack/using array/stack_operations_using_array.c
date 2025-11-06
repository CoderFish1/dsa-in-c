#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// function to check if stack is Empty of not
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
// function to check if stack is Full of not
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

// Push operation
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow, %d cannot be pushed!!\n", val);
    }
    else
    { 
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("Pushed %d to the stack.\n", val);
    }
}

// Pop operation
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// stackTop operation
int stackTop(struct stack *sp){
    return sp->arr[sp->top];
}
// stackBottom operation
int stackBottom(struct stack *sp){
    return sp->arr[0];
}

// Peek operation
int peek(struct stack *ptr, int i)
{
    int arrIndex = ptr->top - i + 1;
    if (arrIndex < 0 || i <= 0)
    {
        return -1;
    }
    else
    {
        return ptr->arr[arrIndex];
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 1);
    push(s, 53);
    push(s, 23);
    push(s, 65);
    push(s, 95);  // will push till this value , as stack size if only 5
    push(s, 195); // stack will overflow and cant push this

    int popResult = pop(s);
    if (popResult == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("%d element is popped!\n", popResult);
    }

    // //printing eleemnts using peek operation
    // for (int j = 1; j <= s->top + 1; j++)
    // {
    //     printf("The peek element at positon %d is %d \n", j, peek(s, j));
    // }

    printf("The top-most element of the stack is %d\n",stackTop(s));
    printf("The bottom-most element of the stack is %d\n",stackBottom(s));

    return 0;
}