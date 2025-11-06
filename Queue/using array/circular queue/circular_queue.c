#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int r;
    int f;
    int *arr;
};

void enqueue(struct Queue *q, int val)
{
    // isFull condition
    if ((q->r + 1) % q->size == q->f)
    {
        printf("The circular queue is full!\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqueued %d in the circular queue\n", val);
    }
}

int dequeue(struct Queue *q)
{
    if (q->r == q->f)
    {
        printf("Circular is empty!!\n");
        return 0;
    }
    else
    {
        int val;
        q->f = (q->f + 1) % (q->size);
        val = q->arr[q->f];
        return val;
    }
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 5;
    q->r = q->f = 0; // here initial value of r and f is not -1 but 0, also u can can enqueue only (size - 1) elements only
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 5);
    enqueue(q, 63);
    enqueue(q, 25);
    enqueue(q, 25);
    enqueue(q, 25);
    enqueue(q, 25);

    int deqVal = dequeue(q);
    printf("Dequeued value is %d\n", deqVal);

    return 0;
}