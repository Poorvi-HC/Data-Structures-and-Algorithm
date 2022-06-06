#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef long long int ll;

typedef struct TNode
{
    char A;
    int idx;
    int pre;
    struct TNode *left;
    struct TNode *right;
} TNode;

TNode *init_tree_node(int idx)
{
    TNode *node = NULL;
    node = (TNode *)malloc(sizeof(TNode));
    assert(node != NULL);
    node->idx = idx;
    node->pre = 0; //
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(TNode *root, char *a, long long int *inx)
{
    if (root != NULL)
    {
        a[*inx] = root->A;
        root->pre = *inx;
        *inx = *inx + 1;
        preorder(root->left, a, inx);
        preorder(root->right, a, inx);
    }
    return;
}

int main()
{
    ll NoOfNodes;
    scanf("%lld", &NoOfNodes);

    TNode *Tree[NoOfNodes];
    for (int i = 0; i < NoOfNodes; i++)
    {
        Tree[i] = init_tree_node(i + 1); //
        // made pointers to tree nodes for all
    }

    char Main_String[NoOfNodes+1];
    scanf("%s", Main_String);

    for (int i = 0; i < NoOfNodes; i++)
    {
        Tree[i]->A = Main_String[i];
    }

    ll sum = (NoOfNodes * (NoOfNodes + 1)) / 2;
    ll sum_step = 0;
    for (int i = 0; i < (NoOfNodes - 1); i++)
    {
        ll Arr[3];
        for (int j = 0; j < 3; j++)
            scanf("%lld", &Arr[j]);

        if (Arr[2] == 2)
            Tree[Arr[0] - 1]->right = Tree[Arr[1] - 1];
        else if (Arr[2] == 1)
            Tree[Arr[0] - 1]->left = Tree[Arr[1] - 1];
        sum_step += Arr[1];
    }

    ll root = sum - sum_step;
    char *idx_preorder = (char *)malloc(NoOfNodes * sizeof(char));
    long long int inx = 0;
    preorder(Tree[root-1], idx_preorder, &inx);

    char Comp_String[1000002];
    scanf("%s", Comp_String);

    ll queries;
    scanf("%lld", &queries);
    //ll test = 0;

    while (queries--)
    {
        ll Task;
        scanf("%lld", &Task);

        if (Task == 1)
        {
            ll Integer;
            char Char;
            scanf("%lld %c", &Integer, &Char);
            Tree[Integer - 1]->A = Char;
            idx_preorder[Tree[Integer - 1]->pre] = Char;
            // printf("namasyes");
        }

        else if (Task == 2)
        {
            ll L, R, I;
            scanf("%lld %lld %lld", &L, &R, &I);
            ll len = R - L + 1;
            if (strncmp(&idx_preorder[Tree[I - 1]->pre], &Comp_String[L - 1], len) == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}