#include <stdio.h>
#include <stdlib.h>

// defining a node for tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// function to create a create a node for tree dynmaically
struct Node *createNode(int data)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};

int main()
{
    // constructing nodes using function
    struct Node *p1 = createNode(5); // root node
    struct Node *p2 = createNode(7); // first nbde
    struct Node *p3 = createNode(2); // second node

    p1->left = p2;
    p1->right = p3;

    return 0;
}