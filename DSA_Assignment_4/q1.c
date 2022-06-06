#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void* a, const void* b)
{
    return ( *(long long int*)a - *(long long int*)b);
}

int main()
{
    int testcases;
    scanf("%d", &testcases);
    int test = 0;
    while(test < testcases)
    {
        long long int no_of_ele;
        scanf("%lld",&no_of_ele);
        long long int array[no_of_ele];
        for (int i = 0;i<no_of_ele;i++){
            scanf("%lld", &array[i]);
        }
        
        long long int frequency[no_of_ele];
        memset(frequency,0,no_of_ele);
        long long int idx = 0;
        
        qsort(array,no_of_ele,sizeof(long long int),*cmpfunc);
        frequency[0] = 0;
        long long int ref = array[0];
        for (int i = 0;i<no_of_ele;i++)
        {
            if(array[i] == ref)
                frequency[idx] += 1;
            else{
                ref = array[i];
                frequency[++idx] = 1;
            }
        }
        qsort(frequency,idx + 1,sizeof(long long int),*cmpfunc);
        long long int max = frequency[idx];

        int max_count = 0;
        for (int i = idx;i>=0;i--)
        {
            if (max == frequency[i])
                max_count++;
            if(max != frequency[i])
                break;
        }

        if (max == 1)
            printf("%lld\n",no_of_ele);
        else{
            long long int output = (max_count - 1) + ((no_of_ele - (max*max_count))/(max - 1));
            printf("%lld\n",output);
        }
        test++;
    }
}