#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include <math.h>
#include <string.h>


int main()
{
    char str[10];
    scanf("%s", str);

    int size;
    scanf("%d", &size);

    Complex* A = Make_Complex(size);
    Complex* B = Make_Complex(size);
    Complex* C = Make_Complex(size);

    float res;

    if (strcmp(str, "MOD") == 0)
    {
        for (int i = 0;i<(A->size);i++)
            scanf("%f",&A->comp[i]);
        
        res = mod(A);
        printf("%.2f\n",res);
    }

    else
    {
        for (int i = 0;i<size;i++)
            scanf("%f",&A->comp[i]);

        for (int j = 0;j<size;j++)
            scanf("%f",&B->comp[j]);

        if (strcmp(str, "ADD") == 0)
        {
            C = add(A,B);
            print(C);
        }

        else if (strcmp(str, "SUB") == 0)
        {
            C = sub(A,B);
            print(C);
        }

        else if (strcmp(str, "DOT") == 0)
        {
            res = dot(A,B);
            printf("%.2f\n", res);
        }

        else if (strcmp(str, "COS") == 0)
        {
            res = COS(A,B);
            printf("%.2f\n", res);
        }
    }

    clearComplex(A);
    clearComplex(B);
    clearComplex(C);

    return 0;
}