#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int val)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    return p;
};

// Our tree looks like this : -
//         6
//        / \
//       4   7
//      / \
//     3   5

struct Node *iterative_search(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
};

// inserting
void insert(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert, already %d is presernt.\n", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct Node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

int main()
{

    struct Node *p1 = createNode(6); // root-node
    struct Node *p2 = createNode(4);
    struct Node *p3 = createNode(7);
    struct Node *p4 = createNode(3);
    struct Node *p5 = createNode(5);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    struct Node *result = iterative_search(p1, 9);

    if (result != NULL)
    {
        printf("Found : %d\n", result->data);
    }
    else
    {
        printf("Not found.\n");
    }

    insert(p1, 9);
    printf("Inserted %d\n", p1->right->right->data);

    return 0;
}