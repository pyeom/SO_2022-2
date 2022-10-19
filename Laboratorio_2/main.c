#include <stdio.h>
#include <stdlib.h>

typedef struct domino dom, *dom;

struct domino {
    int id;
    int mask[2];
    struct domino *next;
    struct domino *prev;
};

struct domino dstock[28];




