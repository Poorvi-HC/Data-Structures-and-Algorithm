#include "tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#define COUNT 10

TNode *CreateTNode(ll data)
{
    TNode *node;
    node = (TNode *)malloc(sizeof(TNode));
    assert(node != NULL);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->isBST = 0;
    node->sum = 0;
    return node;
}

Tree *CreateTree()
{
    // Tree* T;
    Tree *T = (Tree *)malloc(sizeof(Tree));
    assert(T != NULL);
    T->no_of_nodes = 0;
    T->root = NULL;
    return T;
}

Tree *LevelOrderTrav(ll *data_set, Tree *T, ll index)
{
   // printf("Entered\n");
    queue *Q;
    Q = CreateQueue();
    long long int idx = 1;

    TNode *node = CreateTNode(data_set[0]);
    push(Q, node, 0);
    T->root = node;
    T->no_of_nodes += 1;

    //printf("Root initiated\n");
    TNode *top;
    top = node;

    while (idx < index && (idx + 1) < index)
    {
        //printf("Entered while\n");
        long long int k = idx;
        if (!isEmpty(Q) && top != NULL)
        {
            if (data_set[k] != 0)
            {
                TNode *node = CreateTNode(data_set[k]);
                push(Q, node, -1);
                top->left = node;
                T->no_of_nodes++;
            }
            /*else if (data_set[k] == 0)
            {
                top->left = NULL;
            }*/

            if (data_set[k + 1] != 0)
            {
                TNode *node = CreateTNode(data_set[k + 1]);
                push(Q, node, 1);
                top->right = node;
                T->no_of_nodes++;
            }
            /*else if (data_set[k + 1] == 0)
            {
                top->right = NULL;
            }*/
            //printf("hello\n");
            pop(Q);
            //printf("**hello\n");
            if (Q->head != NULL)
                top = Q->head->address;
        }
        idx += 2;
    }
    return T;
}

void print2DUtil(TNode *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%lld %d %lld\n", root->data, root->isBST, root->sum);

    print2DUtil(root->left, space);
}

void print2D(Tree *T)
{
    print2DUtil(T->root, 0);
}

int isBST_As(TNode *node, int min, int max)
{
    if (node == NULL)
        return 1;

    if (node->data < min || node->data > max)
        return 0;

    return isBST_As(node->left, min, node->data - 1) &&
           isBST_As(node->right, node->data + 1, max); // Allow only distinct values
}

int isBST_De(TNode *node, int min, int max)
{
    if (node == NULL)
        return 1;

    if (node->data < min || node->data > max)
        return 0;

    return isBST_De(node->right, min, node->data - 1) &&
           isBST_De(node->left, node->data + 1, max); // Allow only distinct values
}

int isBST(TNode *node)
{
    return (isBST_As(node, INT_MIN, INT_MAX)) ||
           (isBST_De(node, INT_MIN, INT_MAX));
}

int InOrderTraversal(TNode *root)
{
    if (root == NULL)
        return 0;

    InOrderTraversal(root->left);
    int retval = isBST(root);
    if (retval == 1)
        root->isBST = 1;
    InOrderTraversal(root->right);
    return 1;
}

ll Sum(TNode *root)
{
    if (root == NULL)
        return 0;

    long long int sum = 0;
    if (root->isBST == 1)
    {
        sum = root->data + Sum(root->left) + Sum(root->right);
        return sum;
    }

    return INT_MAX;
}

int InOrderTraversal_Sum(TNode *root)
{
    if (root == NULL)
        return 0;

    InOrderTraversal_Sum(root->left);
    root->sum = Sum(root);
    InOrderTraversal_Sum(root->right);
    return 1;
}

int findMin(TNode *root)
{
    if (root == NULL)
        return INT_MAX;

    int res = root->sum;
    int lres = findMin(root->left);
    int rres = findMin(root->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}
