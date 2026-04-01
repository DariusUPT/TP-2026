#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Structura pentru stivă
typedef struct {
    int top;
    char items[MAX]; // Folosită pentru caractere (operatori)
    int values[MAX]; // Folosită pentru întregi (evaluare)
} Stack;

// Funcții auxiliare pentru gestionarea stivei
void pushChar(Stack *s, char c) {
    s->items[++(s->top)] = c;
}

char popChar(Stack *s) {
    return s->items[(s->top)--];
}

void pushInt(Stack *s, int val) {
    s->values[++(s->top)] = val;
}

int popInt(Stack *s) {
    return s->values[(s->top)--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

char peek(Stack *s) {
    return s->items[s->top];
}

// Prioritatea operatorilor
int prioritate(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// 1. Funcția de transformare în formă postfixată (Shunting-yard)
void infixToPostfix(char *infix, char *postfix, Stack *st) {
    int j = 0;
    st->top = -1;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            pushChar(st, c);
        } else if (c == ')') {
            while (!isEmpty(st) && peek(st) != '(') {
                postfix[j++] = popChar(st);
            }
            popChar(st); // Scoatem '('
        } else {
            while (!isEmpty(st) && prioritate(peek(st)) >= prioritate(c)) {
                postfix[j++] = popChar(st);
            }
            pushChar(st, c);
        }
    }

    while (!isEmpty(st)) {
        postfix[j++] = popChar(st);
    }
    postfix[j] = '\0';
}

// 2. Funcția de evaluare a expresiei postfixate
int evalueazaPostfix(char *postfix, Stack *fp) {
    fp->top = -1;
    int val;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            printf("Introduceti valoarea pentru operandul %c: ", c);
            scanf("%d", &val);
            pushInt(fp, val);
        } else {
            int op2 = popInt(fp);
            int op1 = popInt(fp);

            switch (c) {
                case '+': pushInt(fp, op1 + op2); break;
                case '-': pushInt(fp, op1 - op2); break;
                case '*': pushInt(fp, op1 * op2); break;
                case '/': pushInt(fp, op1 / op2); break;
                case '^': pushInt(fp, (int)pow(op1, op2)); break;
            }
        }
    }
    return popInt(fp);
}

int main() {
    char expresie[MAX], postfix[MAX];
    Stack st; // Stiva pentru conversie
    Stack fp; // Stiva pentru evaluare (forma poloneză)

    printf("Introduceti expresia infixata (ex: a+b*c): ");
    scanf("%s", expresie);

    // Transformare
    infixToPostfix(expresie, postfix, &st);
    printf("Forma postfixata: %s\n", postfix);

    // Evaluare
    int rezultat = evalueazaPostfix(postfix, &fp);
    printf("Rezultatul evaluarii: %d\n", rezultat);

    return 0;
}
