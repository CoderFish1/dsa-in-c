#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void LLtraversal(struct Node* head){
    struct Node* ptr = head;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

int main(){

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

    fourth->next = head; // linking last node to head as it is cicularLL
    fourth->data = 4;

    LLtraversal(head);

    return 0;
}