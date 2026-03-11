#include <stdio.h>

// Bubble Sort
void bubbleSort(int v[], int n) {
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

// Căutare binară – returnează poziția sau -1 dacă nu există
int binarySearch(int v[], int n, int x) {
    int st = 0, dr = n - 1, mij;

    while (st <= dr) {
        mij = (st + dr) / 2;

        if (v[mij] == x)
            return mij;   // poziția găsită
        else if (v[mij] < x)
            st = mij + 1;
        else
            dr = mij - 1;
    }

    return -1; // nu a fost găsit
}

int main() {
    int v[100], n, i, x;

    printf("Numarul de elemente: ");
    scanf("%d", &n);

    printf("Introdu elementele:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    bubbleSort(v, n);

    printf("Vectorul sortat: ");
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    printf("Elementul cautat: ");
    scanf("%d", &x);

    int poz = binarySearch(v, n, x);

    if (poz >= 0)
        printf("Elementul %d a fost gasit la pozitia %d.\n", x, poz);
    else
        printf("Elementul nu a fost gasit.\n");

    return 0;
}
