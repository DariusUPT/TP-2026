#include <stdio.h>

void cautareLiniara(int arr[], int n, int x) { 
    for (int i = 0; i < n; i++) { 
        if (arr[i] == x) { 
            printf("Elementul %d a fost gasit la indexul %d.\n", x, i); 
            return; 
        } 
    } 
    printf("Elementul %d nu a fost gasit in sir.\n", x); 
}

int main() { 
    // Declaram un vector specificand clar ca are 10 pozitii 
    // si il umplem cu 10 numere.
    int arr[10] = {45, 12, 89, 2, 33, 16, 7, 55, 90, 21}; 
    
    // Deoarece stim clar dimensiunea, ii dam lui n direct valoarea 10.
    int n = 10; 
    
    int x; // Declaram variabila pentru numarul cautat
    
    // Cerem utilizatorului sa introduca un numar
    printf("Introdu numarul pe care vrei sa il cauti: ");
    scanf("%d", &x); 

    // Apelam functia de cautare liniara
    cautareLiniara(arr, n, x); 

    return 0; 
}
