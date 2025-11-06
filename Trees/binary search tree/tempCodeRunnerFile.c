#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int val){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data =val;
    p->left = NULL;
    p->right = NULL;
    return p;
};

// Inorder Traversal of BST gives a ascending sorted array
void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

// Checkign if tree is BST or not
int isBST(struct Node *root){
    static struct Node *prev = NULL; // static ensures prev retains its value across recursive calls.
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return 1;
    }
}

// Our tree looks like this : -
//         6
//        / \
//       5   7
//      / \
//     3   4


int main(){
    struct Node *p1 = createNode(6); // root-node
    struct Node *p2 = createNode(5);
    struct Node *p3 = createNode(7);
    struct Node *p4 = createNode(3);
    struct Node *p5 = createNode(4);

    p1->left = p2;
    p1->right = p3;
    p2->left= p4;
    p2->right= p5;
    
    inorder(p1);
    
    int BSTornot = isBST(p1);
    printf("%d\n",BSTornot);

    return 0;
}