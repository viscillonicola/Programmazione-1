#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "giocobiglie.h"
#define n 15

int main()
{
    int i, j, x, y, w, z, x_salva, y_salva;
    int tiri_complessivi=0, mov;
    int riga, colonna, b1, b2, c1=0, c2=0, randx, randy;
    char giocatore[50], pallina=254, buca=79;

    printf("Benvenuto nel gioco delle biglie!\n");
    fflush(stdin);
    printf("Inserisci nome giocatore: \n");
    gets(giocatore);

    char campo[50][50];
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            campo[i][j]=' ';

    //Generazione buca
    srand(time(0));
    x=rand()%n+1;
    y=rand()%n+1;
    campo[x][y]=buca;     //La buca verrà visualizzata attraverso un codice della tabella ASCII

    //Generazione posizione
    w=rand()%n;
    z=rand()%n;
    campo[w][z]=pallina;    //La posizione verrà visualizzata attraverso un codice della tabella ASCII

    char zero;  //Oscuriamo le buche random

    //Generazione buche nascoste random
    while(c1<40)
    {
        riga=1+rand()%n;
        colonna=1+rand()%n;
        b1=campo[riga][colonna]=zero;    //Buche nascoste posizione random
        c1++;
    }
    while(c2<20)
    {
        colonna=rand()%n;
        riga=rand()%n;
        b2=campo[riga][colonna]=zero;    //Buche che terminano il gioco
        c2++;
    }

    //visualizzazione campo
    visualizza(campo);
    printf("\n");

    //Inizio gioco
    do
    {
        x_salva=w;
        y_salva=z;
        printf("\nTiri effettuati: %d\n", tiri_complessivi);
        printf("%s ti trovi in posizione: [%d][%d]\n", giocatore, w, z);
        printf("La buca si trova in posizione: [%d][%d]\n", x, y);
        printf("In che direzione vuoi andare?\n");
        printf("1. Nord 2. Sud 3. Ovest 4. Est 5. Nord Ovest 6. Nord Est 7. Sud Ovest 8. Sud Est\nInserire direzione: \n");
        scanf("%d", &mov);
        switch(mov)
        {
            case 1: pulizia_campo(campo, x_salva, y_salva);
                    Nord(&w, &z);
                break;
            case 2: pulizia_campo(campo, x_salva, y_salva);
                    Sud(&w, &z);
                break;
            case 3: pulizia_campo(campo, x_salva, y_salva);
                    Ovest(&w, &z);
                break;
            case 4: pulizia_campo(campo, x_salva, y_salva);
                    Est(&w, &z);
                break;
            case 5: pulizia_campo(campo, x_salva, y_salva);
                    Nord_Ovest(&w, &z);
                break;
            case 6: pulizia_campo(campo, x_salva, y_salva);
                    Nord_Est(&w, &z);
                break;
            case 7: pulizia_campo(campo, x_salva, y_salva);
                    Sud_Ovest(&w, &z);
                break;
            case 8: pulizia_campo(campo, x_salva, y_salva);
                    Sud_Est(&w, &z);
                break;
            default: tiri_complessivi++;
                break;
        }
        if(campo[w][z]==b2)             //Controllo se la posizione della biglia corrisponde ad una buca random che fa terminare il gioco
        {
            printf("Hai perso!\n");
            printf("Numero di tiri effettuati 50\nGame over :(\n");
            return 0;
        }
        if(campo[w][z]==b1)             //Controllo se la posizione della biglia corrisponde ad una buca random che fa spostare la biglia in una zona random del campo da gioco
        {
            w=rand()%n;
            z=rand()%n;
        }
        if(w==n || z==n)                //Questo if e il successivo controllano se la biglia esce dal campo; nel caso fosse uscita riposizionano la biglia in una posizione random
        {
            randx=1+rand()%n;
            randy=1+rand()%n;
            w=w-randx;
            z=z-randy;
        }
        if(w==0 || z==0)
        {
            randx=1+rand()%n;
            randy=1+rand()%n;
            w=w+randx;
            z=z+randy;
        }
        tiri_complessivi++;
        campo[w][z]=pallina;

        visualizza(campo);
        if(tiri_complessivi==0)
            printf("\nMi dispiace %s hai perso!\nGame over :(\n", giocatore);
    }
    while(tiri_complessivi<50 && campo[w][z]!=campo[x][y]);
    if(campo[w][z]==campo[x][y])
        printf("\n\nCongratulazioni %s hai vinto!\n", giocatore);
    return 0;
}
