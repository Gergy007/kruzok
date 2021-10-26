#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void vypisPole(const int *pole,int pocet);
void vypisPole1(const int pole[],int pocet);
void vyplnPole(int *pole,int pocet);
void alokujPoleInt(int **pole,int pocet);
int *alokujPoleInt1(int pocet);
void vygenerujPole(int *pole, int pocet);
void utriedPole(int *pole, int pocet);
int comp(const void *h1, const void *h2);

int main()
{
    srand(time(NULL));
    int *pInt;
    alokujPoleInt(&pInt,10);
    //int *poledva = alokujPoleInt1(15);
    vygenerujPole(pInt,10);
    vypisPole(pInt,10);
    utriedPole(pInt,10);
    vypisPole(pInt,10);

    free(pInt);
    pInt = NULL;

    return 0;
}

void vypisPole(const int *pole,int pocet)
{
    for(int i=0;i<pocet;i++)
    {
        printf("%d ",*(pole + i));
    }
    printf("\n");

}


void vypisPole1(const int pole[],int pocet)
{
    for(int i=0;i<pocet;++i)
    {
        printf("%d ",pole[i]);
    }
}


void vyplnPole(int *pole,int pocet)
{
    for(int i=0;i<pocet;i++)
    {
        printf("Zadaj prvok pola: ");
        scanf("%d",pole+i);
    }

}


void alokujPoleInt(int **pole,int pocet)
{
    if(((*pole)=(int *)malloc(pocet*sizeof(int))) == NULL)
    {
        puts("Not allocated!/n");
        exit(1);
    }

}


int *alokujPoleInt1(int pocet)
{
    int *pole;
    if((pole = (int *)malloc(pocet*sizeof(int))) == NULL)
    {
        puts("Not allocated! /n");
        exit(1);
    }
    return pole;
}


void vygenerujPole(int *pole, int pocet)
{
    for(int i=0;i<pocet;i++)
    {
        *(pole+i) = rand() % 20;
    }
}


void utriedPole(int *pole, int pocet)
{
    qsort(pole,pocet,sizeof(int),comp);
}


int comp(const void *h1, const void *h2)
{
    int *pInt1 = (int *)h1;
    int *pInt2 = (int *)h2;
    return (*pInt1) - (*pInt2); //utriedi pole od namjemsieho prvku
    //return ((*pInt1) - (*pInt2)) * (-1); //utriedi pole od najvacsieho prvku
    //return (*((int *)h1)) - (*((int *)h2)); //kratsi zapis
}