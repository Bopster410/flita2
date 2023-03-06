#ifndef FLITA2_SET_H
#define FLITA2_SET_H

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
void addSetElement(set **ppSet, void *newElement, type valueType);

// Removes element [element] from set
void removeSetElement(set **headElement, set **ppSet, void *element);

// Prints all set elements
void printSet(set *pSet);

// Checks if element is in set
int isInSet(set *pSet, void *element);


#endif