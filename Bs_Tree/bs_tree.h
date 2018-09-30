/*
 * tree.h
 *
 */

#ifndef BS_TREE_H_
#define BS_TREE_H_
#include "datatype.h"
struct Bst_Node
{
    Key key;
    Data_Item data;
    struct Bst_Node *left, *right;
};

typedef struct Bst_Node BStree_node;

typedef BStree_node** BStree;

//Allocate memory of type BStree node*, set the value
//to NULL, and return a pointer to the allocated memory.
BStree bs_tree_ini(void);

//Insert data with key into bst. If key is in bst, then do nothing.
void bs_tree_insert(BStree bst, Key key, Data_Item data);

//If key is in bst, return a pointer to key¡¯s associated data.
//If key is not in bst, return NULL
Data_Item *bs_tree_search(BStree bst, Key key);

//In order traversal of bst and print each node¡¯s key and data
void bs_tree_traversal(BStree bst);

//Free all the dynamically allocated memory of bst.
void bs_tree_free(BStree bst);

#endif /* TREE_H_ */
