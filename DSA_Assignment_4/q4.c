#include <stdio.h>
#include <stdlib.h>

long long int size = 0;
void swap(long long int* a,long long int* b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray(long long int array[])
{
    for(int i = 0;i<size;i++)
    {
        printf("%lld ",array[i]);
    }
    printf("\n");
}

void heapify(long long int array[],long long int size,long long int idx )
{
    if(size != 1 && idx < size)
    { 
        long long int smallest = idx;
        long long int left = idx*2 + 1;
        long long int right = idx*2 + 2;

        if(left < size && array[left] < array[smallest])
            smallest = left;
        if(right <size && array[right] < array[smallest])
            smallest = right;

        if(smallest != idx)
        {
            swap(&array[idx],&array[smallest]);
            heapify(array,size,smallest);
        }
    }
}

void insert(long long int array[],long long int data)
{
    array[size] = data;
    long long int temp = array[size];
    long long int i = size;
    size+=1;
    while(i >= 1 && temp < array[(i-1)/2])
    {
        array[i] = array[(i-1)/2];
        i = (i-1)/2;
    }
    array[i] = temp;
}

long long int deleteRoot(long long int array[])
{
    long long int retval = array[0];
    swap(&array[0],&array[size - 1]);
    size -=1;
    long long int idx = 0;
    long long int j = 2*idx + 1;//left child
    while(j <= (size - 1))
    {
        if ((j+ 1)<size && array[j + 1] < array[j])
            j = j + 1;
        if (array[idx] > array[j])
        {
            swap(&array[idx],&array[j]);
            idx = j;
            j = 2*idx + 1;
        }
        else{
            break;
        }
    }
    return retval;
}

int main()
{
    long long int length, parts;
    long long int cost = 0;
    scanf("%lld %lld",&length, &parts);

    long long int array[parts];
    long long int idx;
    for (idx = 0;idx <parts;idx++)
    {
        scanf("%lld", &array[idx]);
    }

    size = parts;
    long long int i;
    for (i =(size/2 - 1);i>=0;i--)
        heapify(array,size,i);

    long long int ele_1=0,ele_2=0;
    while(size > 1)
    {
        ele_1 = deleteRoot(array);
        ele_2 = deleteRoot(array);
        insert(array,ele_1 + ele_2);
        cost += ele_1 + ele_2;     
    }
    printf("%lld \n",cost);

    return 0;
}