#include <stdio.h>

int main() {
    unsigned char permisiuni = 0; // inițial toate permisiunile sunt 0
    int opt, bit;

    do {
        printf("\n--- Meniu ---\n");
        printf("1. Adauga permisiune\n");
        printf("2. Sterge permisiune\n");
        printf("3. Afiseaza permisiuni\n");
        printf("0. Iesire\n");
        printf("Optiunea: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Alege permisiunea (0-Read, 1-Write, 2-Delete, 3-Rename, 4-Copy): ");
                scanf("%d", &bit);
                permisiuni |= (1 << bit);   // punem bitul pe 1
                break;

            case 2:
                printf("Alege permisiunea (0-Read, 1-Write, 2-Delete, 3-Rename, 4-Copy): ");
                scanf("%d", &bit);
                permisiuni &= ~(1 << bit);  // punem bitul pe 0
                break;

            case 3: {
                const char *nume[] = {"Read", "Write", "Delete", "Rename", "Copy"};
                printf("\nPermisiuni setate:\n");
                for (int i = 0; i < 5; i++) {
                    if (permisiuni & (1 << i)) {
                        printf("%s\n", nume[i]);
                    }
                }
                printf("\nPermisiuni nesetate:\n");
                for (int i = 0; i < 5; i++) {
                    if (!(permisiuni & (1 << i))) {
                        printf("%s\n", nume[i]);
                    }
                }
                break;
            }

            case 0:
                printf("Iesire.\n");
                break;

            default:
                printf("Optiune invalida!\n");
        }
    } while (opt != 0);

    return 0;
}
