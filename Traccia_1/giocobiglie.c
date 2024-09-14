#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define n 15

void visualizza (char campo[][50])          //Questa void serve per visualizzare il campo da gioco
{
    int i, j;
    for(i=0; i<n; i++)
    {
        printf("\n");
        for(j=0; j<n; j++)
            printf("[%3c]", campo[i][j]);
    }
}

void Nord(int *riga, int *colonna)          //Questa void e le successive servono per gli spostamenti della biglia; ogni direzione scelta dal giocatore corrisponde ad una void
{
    if(*riga>0)
        *riga-=1;
}

void Sud(int *riga, int *colonna)
{
    if(*riga<n)
        *riga+=1;
}

void Ovest (int *riga, int *colonna)
{
    if(*colonna>0)
        *colonna-=1;
}

void Est (int *riga, int *colonna)
{
    if(*colonna<n)
        *colonna+=1;
}

void Nord_Ovest (int *riga, int *colonna)
{
    if(*riga>0 && *colonna<n)
    {
        *riga-=1;
        *colonna-=1;
    }
}

void Nord_Est (int *riga, int *colonna)
{
    if(*riga>0 && *colonna<n)
    {
        *riga-=1;
        *colonna+=1;
    }
}

void Sud_Ovest (int *riga, int *colonna)
{
    if(*riga<n && *colonna>0)
    {
        *riga+=1;
        *colonna-=1;
    }
}

void Sud_Est (int *riga, int *colonna)
{
    if(*riga<n && *colonna<n)
    {
        *riga+=1;
        *colonna+=1;
    }
}

void pulizia_campo(char campo[][50], int x_salva, int y_salva)          //Questa void serve per "cancellare" dal campo da gioco la posizione precedente della biglia, quindi per far visualizzare solo la posizione attuale
{
    campo[x_salva][y_salva]=' ';
}
