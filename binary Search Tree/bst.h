//
//  bst.h
//  
//
//  Created by Yixin Zhang on 2016-03-15.
//
//

#ifndef bst_h
#define bst_h

#include <stdio.h>
#include "data.h"
struct BStree_struct{
    
    Node *tree_nodes;
    unsigned char *is_free;
    int size;
};
typedef struct
{
    Node *tree_nodes;
    unsigned char *is_free;
    int size;
} BStree_struct;

typedef BStree_struct* BStree;

BStree bstree_ini(int size);

void bstree_insert(BStree bst, int key, char *data);

void bstree_traversal(BStree bst);

void bstree_free(BStree bst);

#endif /* bst_h */
