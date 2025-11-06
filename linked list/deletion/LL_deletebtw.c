#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void LLTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *deleteNodeBtw(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->next = second;
    head->data = 1;

    second->next = third;
    second->data = 2;

    third->next = fourth;
    third->data = 3;

    fourth->next = NULL;
    fourth->data = 4;

    printf("Linked list before Deleting index Node:\n");
    LLTraversal(head);

    printf("Linked list after Deleting index Node:\n");
    head = deleteNodeBtw(head, 2);
    LLTraversal(head);
    return 0;
}