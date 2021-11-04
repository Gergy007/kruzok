//skusit spravit nekonecne pole intov - po konci poctu sa opyta ci chce este nacitavat, ak ano tak reallocuje pamat a nacita dalej

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define POCET 10

int main()
{
    int znak;
    bool go = true;
    int rozhodni;
    size_t pocetIntov = 0;
    size_t pocetZnakov = 0;
    size_t pocetRealokacii = 1;
    char *veta;

    if((veta = (char*)malloc(sizeof(char)*POCET)) == NULL)
    {
        puts("Not allocated!");
        exit(1);
    }

    while((znak = getc(stdin)) != '\n') //citanie znakov az do konca riadka = Enter = \n
    {
        ++pocetZnakov;
        if(pocetZnakov % POCET == 0) // uz som na nasobku 10 pri pocte znakov, musim realocovat
        {
            ++pocetRealokacii;
            if((veta = (char *)realloc(veta,POCET*pocetRealokacii*sizeof(char))) == NULL)
            {
                puts("Chyba alokacie pamate!");
                exit(1);
            }
        }
        *(veta+pocetZnakov-1) = znak; //zapisem znak do pola
    }
    *(veta+pocetZnakov) = '\0';
    puts(veta);
    printf("Zadali sme %ld znakov a %ld-krat sme reallocovali pole.\n",pocetZnakov,pocetRealokacii-1);


    pocetRealokacii = 1;
    int *inty;
    if((inty = (int *) malloc(sizeof (int)*POCET)) == NULL)
    {
        puts("Not allocated!\n");
        exit(1);
    }

    while (go == true)
    {
        ++pocetIntov;
        scanf("%d",inty+pocetIntov-1);
        if((pocetIntov % POCET) == 0)
        {
            puts("Chces este zadavat cisla? (ano - 1; nie - 0)");
            scanf("%d",&rozhodni);
            if(rozhodni == 1)
            {
                ++pocetRealokacii;
                if((inty = (int *) realloc(inty,POCET*pocetRealokacii*sizeof (int))) == NULL)
                {
                    puts("Chyba alokacie pamate\n");
                    exit(1);
                }
            }
            else
            {
                go = false;
            }
        }
    }

    printf("Zadali sme %ld cisel a pole sme reallocovali %ld-krat.\n",pocetIntov,pocetRealokacii-1);

    free(inty);
    inty = NULL;
    //free(veta);
    //veta = NULL;

}