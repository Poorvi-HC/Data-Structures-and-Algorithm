#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


/* Q2.c failed in OJ because of 2 reasons:
    1) power function(under math.h) always returns a double value which is prone to errors creating mistake in final
        solution.
    2) RTE was given as I was storing the depth of every single element in the array.
    which is not feasible and practical,
    hence stick to finding depth of only the elements you encounter.
    making solution easier and faster.
*/
long long int NumberToAddWith(long long int Num, char Command, long long int noOfRooms)
{
    long long int retval = 0;
    long long int level = 1;
    long long int x = Num;
    while(x%2 == 0)
    {
        level++;
        x=x/2;
    }

    long long int pow[64];
    pow[0] = 1;
    for (int i = 1;i<64;i++)
    {
        pow[i] = pow[i - 1]*2;
    }

    if (Command == 'U')
    {
        long long int number = (Num / pow[level - 1]);

        if (Num == (noOfRooms + 1) / 2)
        {
            retval = 0;
            return retval;
        }

        else if (((number + 1) / 2) % 2 != 0)
        {
            //left child
            retval = pow[(level- 1)];
            return retval;
        }

        else if (((number + 1) / 2) % 2 == 0)
        {
            //right child
            retval = -1 * pow[(level - 1)];
            return retval;
        }
    }

    else if (Command == 'L')
    {
        if ((Num) % 2 == 0)
        {
            retval = -1 * pow[(level - 2)];
            return retval;
        }
        else
        {
            return 0;
        }
    }

    else
    {
        if ((Num) % 2 == 0)
        {
            retval = pow[(level - 2)];
            return retval;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    long long int noOfRooms, noOfTests;
    scanf("%lld %lld", &noOfRooms, &noOfTests);

    for (int i = 0;i<noOfTests;i++)
    {
        long long int start;
        scanf("%lld", &start);
        char str[100001];
        scanf("%s", str);

        for (int i = 0; i < strlen(str); i++)
        {
            start += NumberToAddWith(start, str[i], noOfRooms);
        }
        printf("%lld\n", start);
        
    }
}
