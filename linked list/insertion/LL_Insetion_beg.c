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

// function for insertion in begining in LinkedList
struct Node *insertionAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linkedlist in heap
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
    third->next = fourth;

    // Linking fourth node to NULL
    fourth->data = 63;
    fourth->next = NULL;

    printf("Before Insertion:\n");
    linkedlistTraversal(head);

    head = insertionAtBegining(head, 100);

    printf("After Insertion at begining:\n");
    linkedlistTraversal(head);
    return 0;
}
