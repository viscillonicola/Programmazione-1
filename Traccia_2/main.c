#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestionedischi.h"

Archivio JAZZ[3];
Archivio ROCK[3];
Archivio PUNK[3];

int main()
{
    int scelta;
    printf("Benvenuto nel programma gestione dischi!\n");
    while(scelta>=1 || scelta<=3)
    {
        printf("[1] inserisci disco\n[2] elimina disco\n[3] disco con prezzo minore\n[4] esci\n");
        printf("Inserisci scelta: \n");
        scanf("%d", &scelta);
        if(scelta>3)
        {
            printf("Arrivederci!\n");
            return 0;
        }
        else
        {
            switch(scelta)
            {
                case 1: inserimento();      //Punto 1
                        system("PAUSE");
                    break;
                case 2: elimina_disco();    //Punto 2
                        system("PAUSE");
                    break;
                case 3: disco_p_minore();   //Punto 3
                        system("PAUSE");
                    break;
            }
        }
    }
    return 0;
}

