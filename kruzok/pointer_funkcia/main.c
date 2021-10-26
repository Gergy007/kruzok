#include <stdio.h>
#include <stdlib.h>

float sucet(float a, float b);
float rozdiel(float a, float b);
float sucin(float a, float b);
float podiel(float a, float b);


int main()
{
    float(*pF)(float a,float b); //poiter na funkciu ktora prebera 2 parametre float
    float(*pPF[])(float a,float b) = {sucet, rozdiel, sucin, podiel};
    printf("%f\n",pPF[3](1,2));
    printf("%f\n",pPF[2](1,2));

    return 0;
}

float sucet(float a, float b)
{
    return a+b;
}
float rozdiel(float a, float b)
{
    return a-b;
}
float sucin(float a, float b)
{
    return a*b;
}
float podiel(float a, float b)
{
    return a/b;
}