#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

// Function to add a term to the polynomial
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

// Function to multiply two polynomials and return the result as a new polynomial
struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL) {
        
        struct Term* tempPoly2 = poly2;
        while (tempPoly2 != NULL) {
            int coef1 = poly1->coefficient;
            int exp1 = poly1->exponent;
            int coef2 = tempPoly2->coefficient;
            int exp2 = tempPoly2->exponent;

            int newCoef = coef1 * coef2;
            int newExp = exp1 + exp2;

            
            addTerm(&result, newCoef, newExp);

            tempPoly2 = tempPoly2->next;
        }
        poly1 = poly1->next;
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

    struct Term* product = multiplyPolynomials(polynomial1, polynomial2);

    printf("Product: ");
    displayPolynomial(product);

    freePolynomial(polynomial1);
    freePolynomial(polynomial2);
    freePolynomial(product);

    return 0;
}
