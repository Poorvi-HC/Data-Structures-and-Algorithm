#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef long long int ll;
typedef ll Element;

int cmpfunc(const void* a, const void* b)
{
    return ( *(long long int*)a - *(long long int*)b);
}

struct Heap{
    ll isize;
    ll icapacity;
    Element* pElements;
};

typedef struct Heap* Heap;

void Print(Heap H)
{
    for (int i = 0;i<=H->isize;i++)
    {
        printf("%lld  ",H->pElements[i]);
    }
    printf("\n");
}

Heap CreateHeap(ll capacity)
{
    Heap H;
    assert(capacity > 0);
    H = (Heap) malloc(sizeof(struct Heap));
    assert(H != NULL);
    H->pElements = (Element*) malloc(sizeof(Element)*(capacity + 1));
    assert(H->pElements != NULL);
    H->icapacity = capacity;
    H->isize = 0;
    H->pElements[0] = INT_MAX;

    return H;
}

int isHeapFull(Heap H)
{
    return (H->isize == H->icapacity + 1);
}

int isEmpty(Heap H)
{
    return (H->isize == 0);
}

void InsertmaxHeap(Heap H, Element n)
{
        int i;
        for(i = ++H->isize; H->pElements[i/2]<n;i/=2) 
        {
            H->pElements[i] = H->pElements[i/2];
        }
        H->pElements[i] = n;
        return;
}

Element ExtractMax (Heap H)
{
    ll i , child;
    Element MaxElement,Last;
    if (isEmpty(H))
    {
        return H->pElements[0];
    }
    MaxElement = H->pElements[1];
    Last = H->pElements[H->isize--];

    for (i=1;i*2 <= H->isize;i = child)
    {
        child = 2*i;
        if ((child != H->isize) && (H->pElements[child+1] > H->pElements[child]))
        {
            child++;
        }
        if (Last < H->pElements[child])
        {
            H->pElements[i] = H->pElements[child];
        }
        else{
            break;
        }
    }

    H->pElements[i] = Last;
    return MaxElement;
}

void modify_array(ll size, ll array_1[],ll array_2[])
{
    Heap H = CreateHeap(size);
    for (int i = 0;i<size;i++)
    {
        if (i == 0)
        {
            for (int j = 0;j<size;j++)
            {
                ll sum = array_1[i] + array_2[j];
                InsertmaxHeap(H,sum);
            }
        }
        else
        {
            for (int j = 0;j<size;j++)
            {
                ll sum = array_1[i] + array_2[j];
                if (sum < H->pElements[1])
                {
                    ExtractMax(H);
                    InsertmaxHeap(H,sum);
                }
                else
                    break;
            }
        }
    }
    for (int k = size-1;k>=0;k--)
    {
        ll ele = ExtractMax(H);
        array_2[k] = ele;
    }
}

int main()
{
    ll testcases;
    scanf("%lld", &testcases);
    while(testcases--)
    {
        ll no_of_sections;
        scanf("%lld", &no_of_sections);

        ll** array_3D = (ll**) malloc(no_of_sections* sizeof(ll*));
        for (int i = 0;i<no_of_sections;i++)
        {
            array_3D[i] = (ll*) malloc(no_of_sections*sizeof(ll));
        }

        for (int i = 0;i<no_of_sections;i++)
        {
            for (int j = 0;j<no_of_sections;j++)
            {
                scanf("%lld", &array_3D[i][j]);
            }
        }

        for (int i = 0;i<no_of_sections;i++)
            qsort(array_3D[i],no_of_sections,sizeof(ll),cmpfunc);

        for (int i = 0;i<no_of_sections - 1;i++)
            modify_array(no_of_sections,array_3D[i],array_3D[i+1]);
        for (int i = 0;i<no_of_sections;i++)
            printf("%lld ",array_3D[no_of_sections - 1][i]);
        printf("\n");
        free(array_3D);
    }
}