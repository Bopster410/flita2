#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "set.h"

#define SWAP(a, b) a = a + b; \
                   b = a - b; \
                   a = a - b;

void decToBin(int16_t decNumber, char *bin, const size_t MAX_LEN);

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Error: no arguments\n");
        return 1;
    }

    set *decNumbers = NULL, *binNumbers = NULL;

    for (int i = 1; i < argc; i++) {
        int16_t decNumber = atoi(argv[i]);
        char *binNumber = malloc(32);
        decToBin(decNumber, binNumber, 32);
        decNumbers = addSetElement(decNumbers, (void *) decNumber, INT);
        binNumbers = addSetElement(binNumbers, (void *) binNumber, STR);
    }

    printSet(decNumbers);
    putchar('\n');
    printSet(binNumbers);
//    decNumbers = removeSetElement(decNumbers, (void*)12);
//    printSet(decNumbers);


    return 0;
}

void decToBin(int16_t decNumber, char *bin, const size_t MAX_LEN) {
    int16_t digitInd = 0;
    bool isLastDigit = 0;
    while (!isLastDigit && digitInd < MAX_LEN) {
        isLastDigit = decNumber / 2 == 0;
        char binDigit = decNumber % 2 == 1 ? '1' : '0';
        bin[digitInd] = binDigit;
        digitInd++;
        decNumber /= 2;
    }

    for (int i = 0; i < digitInd / 2; i++) {
        SWAP(bin[i], bin[digitInd - i - 1]);
    }
    bin[digitInd] = '\0';
}