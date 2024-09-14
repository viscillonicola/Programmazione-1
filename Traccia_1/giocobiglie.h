#include "giocobiglie.c"

void visualizza (char campo[][50]);
void Nord(int *riga, int *colonna);
void Sud(int *riga, int *colonna);
void Ovest(int *riga, int *colonna);
void Est(int *riga, int *colonna);
void Nord_Ovest(int *riga, int *colonna);
void Nord_Est(int *riga, int *colonna);
void Sud_Ovest(int *riga, int *colonna);
void Sud_Est(int *riga, int *colonna);
void pulizia_campo(char campo[][50], int x_salva, int y_salva);
