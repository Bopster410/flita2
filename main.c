#include <stdlib.h>
#include <stdio.h>
#include "set.h"

void decToBin(int decNumber, char *bin, const size_t MAX_LEN);

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Error: no arguments\n");
        return 1;
    }

    set *decNumbers = NULL, *binNumbers = NULL;

    for (int i = 1; i < argc; i++) {
        int decNumber = atoi(argv[i]);
        char *binNumber = malloc(32);
        decToBin(decNumber, binNumber, 32);
        addSetElement(&decNumbers, (void *) decNumber, INT);
        addSetElement(&binNumbers, (void *) binNumber, STR);
    }

    printSet(decNumbers);
    printf("\n");
    printSet(binNumbers);

    return 0;
}

void decToBin(int decNumber, char *bin, const size_t MAX_LEN) {
    int digitInd = 0;
    int isLastDigit = 0;
    while (!isLastDigit && digitInd < MAX_LEN) {
        isLastDigit = decNumber / 2 == 0;
        char binDigit = decNumber % 2 == 1 ? '1' : '0';
        bin[digitInd] = binDigit;
        digitInd++;
        decNumber /= 2;
    }

    for (int i = digitInd - 1; i >= digitInd / 2; i--) {
        char temp = bin[digitInd - i - 1];
        bin[digitInd - i - 1] = bin[i];
        bin[i] = temp;
    }
    bin[digitInd] = '\0';
}