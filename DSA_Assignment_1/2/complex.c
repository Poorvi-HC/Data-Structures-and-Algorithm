#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include <assert.h>
#include <math.h>

// creates a standard complex which stores 'size' number of integers each

Complex* Make_Complex(int size)
{
    Complex* complex= (Complex*) malloc(sizeof(Complex));
    complex->comp = (float*) malloc(size*sizeof(float));
    assert(complex->comp != NULL);
    complex->size = size;
    return complex;
}

// adds 2 complexes together to return a new complex
Complex* add(Complex* A, Complex* B)
{
    if ((A->size) != (B->size))
        return NULL;
    if (A->size == 0 || B->size == 0)
        return NULL;

    Complex* C = Make_Complex(A->size);

    for (int i = 0;i<(A->size);i++)
    {
        C->comp[i] = A->comp[i] + B->comp[i];
    }

    return C;
}

// subtracts 2 complex numbers to generate new
Complex* sub(Complex* A, Complex* B)
{
    if ((A->size) != (B->size))
        return NULL;
    if (A->size == 0 || B->size == 0)
        return NULL;

    Complex* C = Make_Complex(A->size);

    for (int i = 0;i<(A->size);i++)
    {
        C->comp[i] = A->comp[i] - B->comp[i];
    }

    return C;
}

// produces a float output when a complex is given as input
float mod(Complex* A)
{
    if (A->size == 0)
        return -1;
    
    float sum = 0;
    for (int i = 0;i<(A->size);i++)
    {
        sum += (A->comp[i] * A->comp[i]);
    }

    return sqrt(sum);
    // -lm for compilation
}

// a float is returned when dot is initiated which returns dot prod of 2 complex numbers 
float dot(Complex* A, Complex* B)
{
    if ((A->size) != (B->size))
        return -1;
    if (A->size == 0 || B->size == 0)
        return -1;

    float sum=0;

    for (int i = 0;i<(A->size);i++)
    {
        sum += (A->comp[i])*(B->comp[i]);
    }

    return sum;
}

//a float is returned as cos = dot/mod*mod
float COS(Complex* A, Complex* B)
{
    if ((A->size) != (B->size))
        return -1;
    if (A->size == 0 || B->size == 0)
        return -1;

    float x;
    x = (dot(A,B)/(mod(A)*mod(B)));

    return x;
}

// Complex is printed onto the terminal
int print(Complex* A)
{
    for (int i = 0;i<A->size;i++)
    {
        printf("%f ", A->comp[i]);
    }
    printf("\n");
    return 1;
}

// Used to free up space when complex is no longer used to preserve space in heap
void clearComplex(Complex* C)
{
    free(C->comp);
    free(C);
}