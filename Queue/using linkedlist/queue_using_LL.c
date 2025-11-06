#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *r = NULL;
struct Node *f = NULL;

void LLTraversal(struct Node *ptr)
{
    printf("Printing Elements :--\n");
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// insertion at rear
void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);

        return val;
    }
}

int main()
{
    enqueue(132);
    enqueue(52);
    enqueue(32);

    int deqElement = dequeue();
    printf("Dequeued element is %d\n", deqElement);

    LLTraversal(f);

    return 0;
}