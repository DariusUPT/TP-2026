#include <stdio.h>
// Include biblioteca standard pentru funcțiile de intrare/ieșire, precum printf.

#include <stdlib.h>
// Include biblioteca standard pentru gestiunea memoriei și controlul proceselor.

#include <ctype.h>
// Include biblioteca necesară pentru funcția isdigit, care verifică dacă un caracter este cifră.

#define MAX 100
// Definește o constantă simbolică pentru dimensiunea maximă a stivei noastre.

int stack[MAX];
// Declară un tablou de întregi ce va servi drept container pentru stiva LIFO.

int top = -1;
// Inițializează cursorul stivei la -1, indicând faptul că stiva este momentan goală.

void push(int val) {
// Definește funcția de adăugare a unui element în vârful stivei.
    stack[++top] = val;
    // Incrementează poziția cursorului, apoi stochează valoarea la noul index "top".
}

int pop() {
// Definește funcția care extrage și returnează elementul din vârful stivei.
    return stack[top--];
    // Returnează valoarea curentă de la "top" și apoi decrementează cursorul.
}

int evaluateRPN(char* expression) {
// Definește funcția de evaluare a expresiei în Notație Poloneză Inversă.
    for (int i = 0; expression[i] != '\0'; i++) {
    // Parcurge șirul de caractere element cu element până la întâlnirea terminatorului nul.
        
        if (expression[i] == ' ') continue;
        // Dacă simbolul curent este un spațiu, ignoră iterația și treci la următorul caracter.

        if (isdigit(expression[i])) {
        // Verifică dacă caracterul curent reprezintă o cifră între '0' și '9'.
            push(expression[i] - '0'); 
            // Convertește caracterul ASCII în valoare numerică și îl pune pe stivă.
        } 
        else {
        // Dacă simbolul este un operator, pregătește extragerea operanzilor pentru calcul.
            int val2 = pop();
            // Extrage primul operand disponibil (care este cel din dreapta în expresia matematică).
            int val1 = pop();
            // Extrage al doilea operand disponibil (care este cel din stânga în expresia matematică).
            
            switch (expression[i]) {
            // Analizează tipul operatorului curent pentru a executa operația corespunzătoare.
                case '+': push(val1 + val2); break;
                // Efectuează adunarea și reintroduce rezultatul obținut înapoi pe stivă.
                case '-': push(val1 - val2); break;
                // Efectuează scăderea (val1 minus val2) și pune rezultatul pe stivă.
                case '*': push(val1 * val2); break;
                // Efectuează înmulțirea și salvează rezultatul pe stivă pentru pașii următori.
                case '/': push(val1 / val2); break;
                // Efectuează împărțirea întreagă și stochează câtul rezultat pe stivă.
            }
        }
    }
    return pop();
    // Returnează ultimul element rămas pe stivă, care reprezintă rezultatul final al calculului.
}

int main() {
// Funcția principală, punctul de pornire al execuției programului.
    char exp[] = "5 3 + 2 *"; 
    // Declară un șir de caractere ce conține expresia în format postfixat (RPN).
    printf("Rezultatul expresiei '%s' este: %d\n", exp, evaluateRPN(exp));
    // Apelează funcția de evaluare și afișează textul rezultatului în consolă.
    return 0;
    // Returnează valoarea 0 către sistemul de operare, confirmând execuția fără erori.
}
