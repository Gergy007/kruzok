//skusit spravit nekonecne pole intov - po konci poctu sa opyta ci chce este nacitavat, ak ano tak reallocuje pamat a nacita dalej

#include <stdio.h>
#include <stdlib.h>
#define POCET 10

int main()
{
    FILE *fr;
    if((fr = fopen("cisla.txt","r")) == NULL)
    {
        puts("Subor sa nepodarilo otvorit");
        exit(1);
    }
    int cislo;
    size_t pocetCisel = 0;
    size_t pocetRealokacii = 1;
    int *cisla;
    if((cisla = (int *)malloc(sizeof(int)*POCET)) == NULL)
    {
        puts("Not allocated!");
        exit(1);
    }

    //int koniec;
    while(fscanf(fr,"%d",&cislo)!=EOF) //citanie znakov az do konca riadka = Enter = \n
    {
        ++pocetCisel;
        if(pocetCisel % POCET == 0) // uz som na nasobku 10 pri pocte znakov, musim realocovat
        {
            ++pocetRealokacii;
            if((cisla = (int *)realloc(cisla,POCET*pocetRealokacii*sizeof(int))) == NULL)
            {
                puts("Chyba alokacie pamate!");
                exit(1);
            }
        }
        *(cisla+pocetCisel-1) = cislo; //zapisem znak do pola
        printf("%d ",cislo);
    }

    printf("Zadali sme %ld cisel a %ld-krat sme reallocovali pole",pocetCisel,pocetRealokacii);


    free(cisla);
    cisla = NULL;

    fclose(fr);

    return 0;
}