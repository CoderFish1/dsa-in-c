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
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linkedlist in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Linking head node to second node
    head->data = 54;
    head->next = second;

    // Linking second node to third node
    second->data = 43;
    second->next = third;

    // Linking third node to Null node
    third->data = 4;
    third->next = NULL;

    linkedlistTraversal(head);
    return 0;
}