#include "set.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

set *addSetElement(set *pSet, void *newElement, type valueType) {
    bool isFirstElement = pSet == NULL, isInSetEl;
    if (!isFirstElement) {
        isInSetEl = isInSet(pSet, newElement);
    }
    if (isFirstElement || !isInSetEl) {
        set *pTemp = malloc(sizeof(set));
        pTemp->value = newElement;
        pTemp->nextElement = pSet;
        pTemp->valueType = valueType;
        return pTemp;
    }
    return pSet;
}

set *removeSetElement(set *pSet, void *element) {
    set *nextElement = pSet->nextElement;
    if (pSet->value == element) {
        pSet = pSet->nextElement;
        return pSet;
    } else if (nextElement->value == element) {
        pSet->nextElement = nextElement->nextElement;
        free(nextElement);
        return pSet;
    } else if (nextElement->nextElement == NULL) {
        return pSet;
    } else {
        pSet->nextElement = removeSetElement(pSet->nextElement, element);
        return pSet;
    }
}

void printSet(set *pSet) {
    char *formatStr;
    switch (pSet->valueType) {
        case INT:
            formatStr = "%d ";
            break;
        case STR:
            formatStr = "%s ";
            break;
        default:
            formatStr = "error\n";
    }
    if (pSet->nextElement == NULL) {
        printf(formatStr, pSet->value);
    } else {
        printf(formatStr, pSet->value);
        printSet(pSet->nextElement);
    }
}

int isInSet(set *pSet, void *element) {
    bool isElement = 0;
    if (pSet->valueType == STR) {
        isElement = strcmp(pSet->value, element) == 0 ? 1 : 0;
    } else {
        isElement = pSet->value == element;
    }

    if (isElement) {
        return 1;
    } else if (pSet->nextElement == NULL) {
        return 0;
    } else {
        return isInSet(pSet->nextElement, element);
    }
}
