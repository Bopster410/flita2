#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "set.h"

#define SWAP(a, b) a = a + b; \
                   b = a - b; \
                   a = a - b;

#define MAX_STR_LEN  32

void decToBin(int16_t decNumber, char *bin, const int16_t MAX_LEN);

int main(int argc, char **argv) {
    if (argc == 1) {
        puts("Error: no arguments");
        return 1;
    }

    set *decNumbers = NULL, *binNumbers = NULL;

    for (int i = 1; i < argc; i++) {
        int16_t decNumber = atoi(argv[i]);
        char *binNumber = malloc(sizeof(char) * MAX_STR_LEN);
        decToBin(decNumber, binNumber, MAX_STR_LEN);
        decNumbers = addSetElement(decNumbers, (void *) decNumber, INT);
        binNumbers = addSetElement(binNumbers, (void *) binNumber, STR);
    }

    printSet(decNumbers);
    putchar('\n');
    printSet(binNumbers);
    putchar('\n');
    decNumbers = removeSetElement(decNumbers, (void*)12);
    printSet(decNumbers);
    putchar('\n');
    binNumbers = removeSetElement(binNumbers, (void*)"11011110");
    printSet(binNumbers);


    return 0;
}

void decToBin(int16_t decNumber, char *bin, const int16_t MAX_LEN) {
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