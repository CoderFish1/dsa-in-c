#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL; // declared as a global component not inside main function

void LLTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
        return 1;
    }
    return 0;
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

// pop operation
struct Node *push(struct Node *tp, int x)
{
    if (isFull(tp))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = x;
        ptr->next = tp;
        tp = ptr;
        return tp;
    }
}
// pop operation
int pop()
{
    if (isEmpty(top))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        struct Node *ptr = top;
        int x = top->data;

        top = top->next;
        free(ptr);
        printf("Element popped is %d\n", x);
        return x;
    }
}

// peak operation
int peek(int pos){
    struct Node *ptr = top;
    for (int i = 0; i < (pos-1 && ptr != NULL); i++){
        ptr = ptr->next;
    }
    if(ptr != NULL){
        return ptr->data; 
    }
    return -1;
}

// stackTop operation
int stackTop(){
    struct Node *ptr = top;
    return ptr->data;
}
// stackBottom operation
int stackBottom(){
    struct Node *ptr = top;
    while(ptr->next != NULL){
        ptr = ptr ->next;
    }
    return ptr->data;
}
int main()
{

    top = push(top, 52);
    top = push(top, 24);
    top = push(top, 12);
    top = push(top, 84);
    top = push(top, 74);

    printf("FULL : %d\n", isFull(top));
    printf("Empty : %d\n", isEmpty(top));

    pop();
    pop();

    int peekElement = peek(1);
    printf("Peek element at position is %d\n",peekElement);

    int stacktTopElement = stackTop();
    printf("Top most of element of stack is %d\n",stacktTopElement);
    
    int stackBottmElement = stackBottom();
    printf("Bottom most of element of stack is %d\n",stackBottmElement);

    LLTraversal(top);

    return 0;
}