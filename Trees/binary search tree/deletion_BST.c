#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNode(int val)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = val;
    p->right = NULL;
    p->left = NULL;
    return p;
};
// Our tree(BST) looks like this : -
//         6
//        / \
//       4   7
//      / \
//     3   5

struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// inorder traversal
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct Node *deleteNode_BST(struct Node *root, int val)
{
    struct Node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // Search for element to be deleted
    if (val < root->data)
    {
        root->left = deleteNode_BST(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode_BST(root->right, val);
    }
    // Deletion logic when node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode_BST(root->left, iPre->data);
    }
    return root;
};

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

    printf("Before deletion :-\n");
    inorderTraversal(p1);

    printf("\n");

    printf("After deletion :-\n")-;
    deleteNode_BST(p1,4);
    inorderTraversal(p1);

    printf("\n");

    printf("Inorder-Predessor is %d\n",p1->data);

    return 0;
}