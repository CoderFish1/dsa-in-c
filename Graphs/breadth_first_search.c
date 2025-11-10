#include <stdio.h>
#include <stdlib.h>

// queue follows FIFO
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// insertion at rear
void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overfloow !!\n");
    }
    else
    {
        q->r = q->r + 1; // q->r++;
        q->arr[q->r] = val;
        printf("(Enqueing)Inserted element %d at the rear\n", val);
    }
}

// deletion at front
void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!!\n");
    }
    else
    {
        q->f++;
        int val = q->arr[q->f];
        printf("(Dequeing)Deleted element %d at the front\n", val);
    }
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));

    q->size = 500;
    q->f = q->r = 0; //for BFS Implementation make front and rear as 0 not -1.
    q->arr = (int *)malloc(q->size * sizeof(int));

    return 0;
}