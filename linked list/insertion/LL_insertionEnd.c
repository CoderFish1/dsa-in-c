#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("The element %d\n",ptr->data);
        ptr = ptr->next;
    }
}
 
struct Node *LLInsertionEnd(struct Node*head, int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));

    struct Node *p;

    p = head;
    ptr->data = data;

    while(p->next != NULL){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
};
 
int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    // Linking head node to second node
    head->data = 54;
    head->next = second;

    // Linking second node to third node
    second->data = 43;
    second->next = third;

    // Linking third node to Null node
    third->data = 4;
    third->next = NULL;

    printf("Before end insertion :\n");
    linkedlistTraversal(head);

    printf("After end insertion :\n");
    head = LLInsertionEnd(head, 100);
    linkedlistTraversal(head);

    return 0;
}