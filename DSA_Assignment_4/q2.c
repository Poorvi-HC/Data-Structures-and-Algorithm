#include <stdio.h>
#include <stdlib.h>

int main()
{
    int swap_count = 0;
    int number_of_towers,swapper;
    scanf("%d %d", &number_of_towers,&swapper);

    int heights[number_of_towers];
    for (int i = 0;i<number_of_towers;i++)
    {
        scanf("%d", &heights[i]);
    }

    begin:
    for (int idx = 0;idx < number_of_towers;idx++)
    {
        int flag = 0;
        for (int i = 0;i<number_of_towers - 1;i++)
        {
            if (heights[i] <= heights[i+1])
            {
                flag = 0;//sorted
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("0");
            return 0;
        }

        else if (heights[idx] > swapper)
        {
            flag = 0;
            //printf("idx swapped %d", idx);
            int temp = 0;
            temp = swapper;
            swapper = heights[idx];
            heights[idx] = temp;

            for (int i = 0;i<number_of_towers - 1;i++)
            {
                if (heights[i] <= heights[i+1])
                {
                    flag = 0;//sorted
                }
                else{
                    flag = 1;
                    swap_count++;
                    goto begin;
                }
            }
            if (flag == 0)
            {
                printf("%d",swap_count+1);
                return 0;
            }
        }
        else if (idx == number_of_towers - 1)
        {
            printf("-1");
        }
    }
    return 0;
}