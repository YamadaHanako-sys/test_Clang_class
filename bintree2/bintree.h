#ifndef ___bintree
#define ___bintree

#include "mydata.h"
typedef struct __bnode {
mydata data;
struct __bnode* left;
struct __bnode* right;
} binnode;

binnode* add(binnode* p, const mydata* x);

void printtree(const binnode* p);

#endif
