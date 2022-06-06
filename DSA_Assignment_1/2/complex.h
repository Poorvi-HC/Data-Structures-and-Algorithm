#ifndef __COMPLEX_H
#define __COMPLEX_H

// basic structure of a complex number
typedef struct complex{
    float* comp;
    int size;
}Complex;

Complex* Make_Complex(int size);
Complex* add(Complex* A, Complex* B);
Complex* sub(Complex* A, Complex* B);
float mod(Complex* A);
float dot(Complex* A, Complex* B);
float COS(Complex* A, Complex* B);
int print(Complex* A);
void clearComplex(Complex* A);

#endif