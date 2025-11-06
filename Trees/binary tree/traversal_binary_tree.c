// preorder, postorder and inorder traversal
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
;

struct Node *createNode(int val)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    return p;
};

// preorder traversal
void preoder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preoder(root->left);
        preoder(root->right);
    }
}
// postorder traversal
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
// inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Our tree looks like this : -
//         4
//        / \
//       1   6
//      / \
//     5   2

int main()
{
    struct Node *p1 = createNode(4); // root-node
    struct Node *p2 = createNode(1);
    struct Node *p3 = createNode(6);
    struct Node *p4 = createNode(5);
    struct Node *p5 = createNode(2);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    printf("Preoder Traversal :- \n");
    preoder(p1);
    printf("\n");
    printf("Postoder Traversal :- \n");
    postorder(p1);
    printf("\n");
    printf("Inorder Traversal :- \n");
    inorder(p1);

    return 0;
}