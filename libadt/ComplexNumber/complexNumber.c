#include "complexNumber.h"
#include <stdlib.h>

#include <math.h>

struct ComplexNumber
{
    float real;
    float imag;
};

void cmplexAddIP(struct ComplexNumber* cn1, struct ComplexNumber* cn2)
{
    cn1->real += cn2->real;
    cn1->imag += cn2->imag;
}

void cmplexAdd(struct ComplexNumber* cn1, struct ComplexNumber* cn2, struct ComplexNumber* res)
{
    float real, imag;
    real = cn1->real + cn2->real;
    res = complexNumberConstructor(real, imag);
}

void cmplexSubIP(struct ComplexNumber* cn1, struct ComplexNumber* cn2)
{
    cn1->real -= cn2->real;
    cn2->imag -= cn2->imag;
}
void cmplexMultIP(struct ComplexNumber* cn1, struct ComplexNumber* cn2)
{
}
void cmplexDiv(struct ComplexNumber* cn1, struct ComplexNumber* cn2)
{

}

void cmplxConj(struct ComplexNumber* cn)
{
    cn->imag = -cn->imag;
}

void complexNumberDisplay(struct ComplexNumber* cn)
{
    if(cn->imag >= 0)
    {
        printf("%f + %fi\n", cn->real, cn->imag);
    }
    else
    {
        printf("%f - %fi\n", cn->real,fabs(cn->imag));
    }
}

float complexNumberGetReal(struct ComplexNumber* cn)
{
    return cn->real;
}
float complexNumberGetImag(struct ComplexNumber* cn)
{
    return cn->imag;
}

float complexNumberGetTheta(struct ComplexNumber* cn)
{
    return atan(cn->imag/cn->real);
}

float complexNumberGetMag(struct ComplexNumber* cn)
{
    return sqrt(((cn->real * cn->real) + (cn->imag * cn->imag)));
}

struct ComplexNumber* complexNumberConstructor(float real, float imag)
{
    struct ComplexNumber* complexNumber;
    complexNumber = malloc(sizeof(struct ComplexNumber));
    complexNumber->real = real;
    complexNumber->imag = imag;

    return complexNumber;
}

void complexNumberDestructor(struct ComplexNumber* complexNumber)
{
    free(complexNumber);
}
