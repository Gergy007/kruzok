//skusit spravit nekonecne pole intov - po konci poctu sa opyta ci chce este nacitavat, ak ano tak reallocuje pamat a nacita dalej

#include <stdio.h>
#include <stdlib.h>
#define POCET 10

int main()
{
    FILE *fr;
    if((fr = fopen("text.txt","r")) == NULL)
    {
        puts("Subor sa nepodarilo otvorit");
        exit(1);
    }
    int znak;
    size_t pocetZnakov = 0;
    size_t pocetRealokacii = 1;
    char *veta;
    if((veta = (char*)malloc(sizeof(char)*POCET)) == NULL)
    {
        puts("Not allocated!");
        exit(1);
    }

    while((znak = getc(stdin)) != '\n') //citanie znakov azdo konca riadka = Enter = \n
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
    printf("Zadali sme %ld znakov a %ld-krat sme reallocovali pole",pocetZnakov,pocetRealokacii);


    free(veta);
    veta = NULL;

    return 0;
}