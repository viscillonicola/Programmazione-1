#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char codice[10];
    char titolo[50];
    char autore[50];
    float prezzo;
}Archivio;

Archivio JAZZ[3];
Archivio ROCK[3];
Archivio PUNK[3];

int i, j, k, cont_j, cont_r, cont_p;

void inserimento()
{
    int categoria;
    printf("Inserisci genere: \n");
    printf("[1] Jazz\n[2] Rock\n[3] Punk\n");
    scanf("%d", &categoria);
    switch(categoria)
    {
        case 1: if(i<3)
                {
                    //Inserimento disco Jazz
                    fflush(stdin);
                    printf("Hai scelto la categoria Jazz\n");
                    printf("Inserisci codice categoria: \n");
                    gets(JAZZ[i].codice);
                    printf("Inserisci titolo disco %d: \n", i+1);
                    gets(JAZZ[i].titolo);
                    printf("Inserisci autore disco %d: \n", i+1);
                    gets(JAZZ[i].autore);
                    printf("Inserisci prezzo disco %d: \n", i+1);
                    scanf("%f", &JAZZ[i].prezzo);
                    i++;
                    printf("Hai inserito il disco %d!\n", i);
                    cont_j++;
                }
                else
                    printf("Errore! Spazio esaurito! Non si possono pi� inserire dischi Jazz\n");
            break;
        case 2: if(j<3)
                {
                    //Inserimento disco Rock
                    fflush(stdin);
                    printf("Hai scelto la categoria Rock\n");
                    printf("Inserisci codice categoria: \n");
                    gets(ROCK[i].codice);
                    printf("Inserisci titolo disco %d: \n", j+1);
                    gets(ROCK[j].titolo);
                    printf("Inserisci autore disco %d: \n", j+1);
                    gets(ROCK[j].autore);
                    printf("Inserisci prezzo disco %d: \n", j+1);
                    scanf("%f", &ROCK[j].prezzo);
                    j++;
                    printf("Hai inserito il disco %d!\n", j);
                    cont_r++;
                }
                else
                    printf("Errore! Spazio esaurito! Non si possono pi� inserire dischi Rock\n");
            break;
        case 3: if(k<3)
                {
                    //Inserimento disco Punk
                    fflush(stdin);
                    printf("Hai scelto la categoria Punk\n");
                    printf("Inserisci codice categoria: \n");
                    gets(PUNK[i].codice);
                    printf("Inserisci titolo disco %d: \n", k+1);
                    gets(PUNK[k].titolo);
                    printf("Inserisci autore disco %d: \n", k+1);
                    gets(PUNK[k].autore);
                    printf("Inserisci prezzo disco %d: \n", k+1);
                    scanf("%f", &PUNK[k].prezzo);
                    k++;
                    printf("Hai inserito il disco %d!\n", k);
                    cont_p++;
                }
                else
                    printf("Errore! Spazio esaurito! Non si possono pi� inserire dischi Punk\n");
            break;
    }
}

void elimina_disco()
{
    int a;
    char tit[50];
    fflush(stdin);
    printf("Inserisci titolo da ricercare ed eliminare: \n");
    gets(tit);
    for(a=0; a<10; a++)     //Mettiamo a<10 perché possiamo inserire massimo 9 dischi
    {
        if(strcmp(JAZZ[a].titolo, tit)==0)
        {
            strcpy(JAZZ[a].titolo, " ");
            strcpy(JAZZ[a].autore, " ");
            JAZZ[a].prezzo=0;
            printf("Disco Jazz eliminato!\n");
        }
        else if(strcmp(ROCK[a].titolo, tit)==0)
        {
            strcpy(ROCK[a].titolo, " ");
            strcpy(ROCK[a].autore, " ");
            ROCK[a].prezzo=0;
            printf("Disco Rock eliminato!\n");
        }
        else if(strcmp(PUNK[a].titolo, tit)==0)
        {
            strcpy(PUNK[a].titolo, " ");
            strcpy(PUNK[a].autore, " ");
            PUNK[a].prezzo=0;
            printf("Disco Punk eliminato!\n");
        }
    }
}

int minimo(int x, int y)
{
    if(x<y)
        return x;
    else
        return y;
}

int min_arrayjazz(Archivio JAZZ[], int n)
{
    if(n==1)
        return JAZZ[0].prezzo;
    else
        return minimo(JAZZ[0].prezzo,min_arrayjazz(JAZZ+1, n-1));
}

int min_arrayrock(Archivio ROCK[], int n)
{
    if(n==1)
        return ROCK[0].prezzo;
    else
        return minimo(ROCK[0].prezzo,min_arrayrock(ROCK+1, n-1));
}

int min_arraypunk(Archivio PUNK[], int n)
{
    if(n==1)
        return PUNK[0].prezzo;
    else
        return minimo(PUNK[0].prezzo,min_arraypunk(PUNK+1, n-1));
}

int disco_p_minore()
{
    int x, i;
    float minimo;
    printf("Inserisci la categoria del prodotto da ricercare: \n");
    printf("[1]JAZZ \n[2] ROCK \n[3] PUNK\n");
    scanf("%d",&x);
    switch(x)
    {
        case 1: minimo=min_arrayjazz(JAZZ,3);
                for(i=0;i<3;i++)
                {
                    if(JAZZ[i].prezzo==minimo)
                        printf("Il disco con il prezzo minimo %f e' %s ",JAZZ[i].prezzo, JAZZ[i].titolo);
                }
            break;
        case 2: minimo=min_arrayrock(ROCK,3);
                for(i=0;i<3;i++)
                {
                    if(ROCK[i].prezzo==minimo)
                        printf("Il disco con il prezzo minimo %f e' %s ",ROCK[i].prezzo, ROCK[i].titolo);
                }
            break;
        case 3: minimo=min_arraypunk(PUNK,3);
                for(i=0;i<3;i++)
                {
                    if(PUNK[i].prezzo==minimo)
                        printf("Il disco con il prezzo minimo %f e' %s ",PUNK[i].prezzo, PUNK[i].titolo);
                }
            break;
    }
}



