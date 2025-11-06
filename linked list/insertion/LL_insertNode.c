#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("The element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *LLInsertionNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
};

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

    // Linking head node to second node
    head->data = 54;
    head->next = second;

    // Linking second node to third node
    second->data = 43;
    second->next = third;

    // Linking third node to fourth node
    third->data = 4;
    third->next = NULL;

    // Linking fourth node to Null node
    fourth->data = 86;
    fourth->next = NULL;

    printf("Before given Node insertion :\n");
    linkedlistTraversal(head);

    printf("After given Node insertion :\n");
    head = LLInsertionNode(head, third, 100);
    linkedlistTraversal(head);

    return 0;
}