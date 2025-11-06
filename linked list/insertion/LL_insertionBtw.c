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

struct Node *LLinsertion_btw(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;
    struct Node *p = head;
    ptr->data = data;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

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
    third->next = fourth;

    // Linking fourth node to NULL
    fourth->data = 63;
    fourth->next = NULL;

    printf("Before insertion in the between(at index) of the LL :-\n");
    linkedlistTraversal(head);

    printf("After insertion in the between(at index) of the LL :-\n");
    head = LLinsertion_btw(head, 100, 2);
    linkedlistTraversal(head);
    return 0;
}