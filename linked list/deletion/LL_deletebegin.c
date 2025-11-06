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

struct Node *deleteBegin(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    head = head->next;
    free(ptr);
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

    printf("Linked list before Deletion:\n");
    LLTraversal(head);

    printf("Linked list after Deletion:\n");
    head = deleteBegin(head);
    LLTraversal(head);

    return 0;
}