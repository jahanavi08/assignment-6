#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

struct Term* createTerm(int coefficient, int exponent) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

void addTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Term* polynomial = NULL;

    addTerm(&polynomial, 5, 3);
    addTerm(&polynomial, -2, 2);
    addTerm(&polynomial, 1, 0);

    displayPolynomial(polynomial);

    struct Term* current = polynomial;
    while (current != NULL) {
        struct Term* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
