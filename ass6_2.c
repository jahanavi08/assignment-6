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

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coef1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int coef2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        if (exp1 > exp2) {
            addTerm(&result, coef1, exp1);
            poly1 = poly1->next;
        } else if (exp1 < exp2) {
            addTerm(&result, coef2, exp2);
            poly2 = poly2->next;
        } else {
            addTerm(&result, coef1 + coef2, exp1);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
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

void freePolynomial(struct Term* poly) {
    struct Term* current = poly;
    while (current != NULL) {
        struct Term* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Term* polynomial1 = NULL;
    struct Term* polynomial2 = NULL;

    addTerm(&polynomial1, 5, 3);
    addTerm(&polynomial1, -2, 2);
    addTerm(&polynomial1, 1, 0);

    addTerm(&polynomial2, 3, 2);
    addTerm(&polynomial2, 2, 1);
    addTerm(&polynomial2, -1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(polynomial1);

    printf("Polynomial 2: ");
    displayPolynomial(polynomial2);

    struct Term* sum = addPolynomials(polynomial1, polynomial2);

    printf("Sum: ");
    displayPolynomial(sum);

    freePolynomial(polynomial1);
    freePolynomial(polynomial2);
    freePolynomial(sum);

    return 0;
}
