#ifndef FLITA2_SET_H
#define FLITA2_SET_H
#include <stdbool.h>

typedef enum type {
    INT,
    STR
} type;

typedef struct set {
    void *value;
    struct set *nextElement;
    type valueType;
} set;


// Adds element [newElement] to set
set* addSetElement(set *pSet, void *newElement, type valueType);

// Removes element [element] from set
set* removeSetElement(set *pSet, void *element);

// Prints all set elements
void printSet(set *pSet);

// Checks if element is in set
bool isInSet(set *pSet, void *element);


#endif