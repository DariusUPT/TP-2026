#include <stdio.h>
#include <stdlib.h>

// Functia primeste vectorul (prin adresa pointerului), dimensiunea si pozitia (prin adresa)
void gasesteMinimSiInterschimba(int **v, int *n, int *pozitie) {
    if (*pozitie < 0 || *pozitie >= *n) {
        printf("Pozitie invalida!\n");
        return;
    }

    // Folosim pointeri pentru a parcurge vectorul pana la pozitia data
    int *p = *v;
    int *pMin = *v; // Presupunem ca primul element este cel mai mic

    for (int i = 1; i <= *pozitie; i++) {
        if (*(p + i) < *pMin) {
            pMin = (p + i);
        }
    }

    // Interschimbarea elementului minim gasit cu cel de la pozitia specificata
    int aux = *pMin;
    *pMin = *(*v + *pozitie);
    *(*v + *pozitie) = aux;
}

int main() {
    int *vector = NULL;
    int n, poz;
    int optiune;

    do {
        printf("\n--- MENIU INTERACTIV ---\n");
        printf("1. Introducere date (dimensiune si elemente)\n");
        printf("2. Executa gasire minim si interschimbare pe pozitie\n");
        printf("0. Iesire\n");
        printf("Alegeti optiunea: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                if (vector != NULL) free(vector); // Eliberam memoria daca a mai fost alocata

                printf("Introduceti dimensiunea vectorului: ");
                scanf("%d", &n);

                vector = (int *)malloc(n * sizeof(int));
                if (vector == NULL) {
                    printf("Eroare la alocarea memoriei!\n");
                    return 1;
                }

                printf("Introduceti elementele vectorului:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", vector + i);
                }
                break;

            case 2:
                if (vector == NULL) {
                    printf("Mai intai introduceti datele (Optiunea 1)!\n");
                } else {
                    printf("Introduceti pozitia pentru interschimbare (0 - %d): ", n - 1);
                    scanf("%d", &poz);

                    // Transmitem parametrii prin referinta
                    gasesteMinimSiInterschimba(&vector, &n, &poz);

                    printf("Vectorul modificat este: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", *(vector + i));
                    }
                    printf("\n");
                }
                break;

            case 0:
                printf("Inchidere program...\n");
                break;

            default:
                printf("Optiune invalida!\n");
        }
    } while (optiune != 0);

    // Eliberarea memoriei inainte de finalizare
    if (vector != NULL) {
        free(vector);
    }

    return 0;
}
