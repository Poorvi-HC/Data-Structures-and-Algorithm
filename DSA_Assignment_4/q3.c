#include <stdio.h>
#include <stdlib.h>

int swap (long long int * a, long long int* b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
    return 1;
}

int bubble_sort(long long int array[], long long int no_of_ele)
{
    long long int out_idx, in_idx;
    for (out_idx = 0; out_idx < no_of_ele - 1; out_idx++)
        for (in_idx = 0; in_idx < no_of_ele - out_idx - 1; in_idx++)
            if (array[in_idx] > array[in_idx + 1])
                swap(&array[in_idx], &array[in_idx + 1]);
    return 0;
}

int main()
{
    long int no_of_ele, No_of_segments;
    scanf("%ld %ld",&no_of_ele,&No_of_segments);

    long long int array[no_of_ele];
    for (int i = 0;i<no_of_ele;i++)
    {
        scanf("%lld",&array[i]);
    }

    long long int sum_array[no_of_ele - 1];
    long long int sum = 0;

    for(int i = (no_of_ele - 1);i>=0;i--)
    {
        sum += array[i];
        if (i > 0)
            sum_array[i-1] = sum;
    }

    long long int reserve = sum;
    bubble_sort(sum_array, no_of_ele - 1);

    for (int i = (no_of_ele - 2);i>=(no_of_ele - No_of_segments);i--)
    {
        reserve += sum_array[i];
    }

    printf("%lld ", reserve);
    return 0;
}