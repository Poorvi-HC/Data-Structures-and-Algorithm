#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "tree.h"

int main()
{
    ll test;
    scanf("%lld", &test);
    //ll t = 0;

    for (int t = 0; t < test; t++)
    {
        ll idx;
        scanf("%lld", &idx);

        ll log = log2((double)idx) + 1;
        //printf("%lld\n" ,log);
        ll num = (pow(2, log) - 1);
        //printf("%lld\n",num);

        long long int *data;
        data = (ll *)calloc(num, sizeof(ll));

        for (int i = 0; i < idx; i++)
        {
            scanf("%lld", &data[i]);
        }

        Tree *T = CreateTree();
        LevelOrderTrav(data, T, num);
        TNode *root = T->root;
        InOrderTraversal(root);
        InOrderTraversal_Sum(root);
        //print2D(T);

        ll retval;
        retval = findMin(root);
        printf("%lld\n", retval);
    }
    return 0;
}