#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void LL_Traversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void LL_Traversal_Reverse(struct Node *tail)
{
    struct Node *ptr = tail;
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    struct Node *N1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N4 = (struct Node *)malloc(sizeof(struct Node));

    N1->data = 1;
    N1->next = N2;
    N1->prev = NULL;

    N2->data = 2;
    N2->next = N3;
    N2->prev = N1;

    N3->data = 3;
    N3->next = N4;
    N3->prev = N2;

    N4->data = 4;
    N4->next = NULL;
    N4->prev = N3;

    printf("Traversal : \n");
    LL_Traversal(N1);

    printf("Reverse Traversa : \n");
    LL_Traversal_Reverse(N4);

    return 0;
}
