#include "set.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addSetElement(set **ppSet, void* newElement, type valueType) {
    int isFirstElement = (*ppSet) == NULL, isIntSet;
    if (!isFirstElement) {
        isIntSet = isInSet(*ppSet, newElement);
    }
    if (isFirstElement || !isIntSet){
        set *pTemp = malloc(sizeof(set));
        pTemp->value = newElement;
        pTemp->nextElement = *ppSet;
        pTemp->valueType = valueType;
        *ppSet = pTemp;
    }
}

void removeSetElement(set **ppHeadElement, set **ppSet, void* element) {
    set *nextElement = (*ppSet)->nextElement;
    set *currentElement = (*ppSet);
    if (nextElement->value == element) {
        currentElement->nextElement = nextElement->nextElement;
        free(nextElement);
    } else if (nextElement->nextElement == NULL || currentElement == NULL) {
        if (isInSet(*ppHeadElement, element)) {
            *ppHeadElement = (*ppHeadElement)->nextElement;
        } else {
            printf("Error: element is not in set\n");
        }
    } else {
        removeSetElement(ppHeadElement, &nextElement, element);
    }
}

void printSet(set *pSet) {
    char* formatStr;
    switch (pSet->valueType)
    {
        case INT:
            formatStr = "%d ";
            break;
        case STR:
            formatStr = "%s ";
            break;
        default:
            formatStr = "error\n";
    }
    if (pSet->nextElement == NULL){
        printf(formatStr, pSet->value);
    } else {
        printf(formatStr, pSet->value);
        printSet(pSet->nextElement);
    }
}

int isInSet(set *pSet, void* element) {
    int isElement = 0;
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
