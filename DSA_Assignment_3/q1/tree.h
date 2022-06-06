#ifndef __BIN_TREE_H
#define __BIN_TREE_H
#include "queue.h"

typedef struct Node_Tree{
    long long int data;
    struct Node_Tree* left;
    struct Node_Tree* right;
    int isBST; 
    long long int sum;
}TNode;

typedef struct Tree{
    TNode* root;
    long long int no_of_nodes;
}Tree;

typedef long long int ll;

TNode* CreateTNode(ll data);
Tree* CreateTree();
Tree* LevelOrderTrav(ll* data_set, Tree* T,ll index);
void print2D(Tree* T);
void print2DUtil(TNode* T, int space);
int InOrderTraversal(TNode* root);
int isBST_De(TNode* node, int min, int max);
int isBST_As(TNode* node, int min, int max);
int InOrderTraversal_Sum(TNode* root);
ll Sum(TNode* root);
int findMin(TNode* root);

#endif