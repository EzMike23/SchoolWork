#include <stdio.h>
#include <malloc.h>
#include "bs_tree.h"

//Allocate memory of type BStree_node*, set the value
//to NULL, and return a pointer to the allocated memory.
BStree bs_tree_ini(void)
{
    BStree tree = (BStree) malloc(sizeof(BStree_node*));
    *tree = NULL;
    return tree;
}

//Insert data with key into bst. If key is in bst, then do nothing.
void bs_tree_insert(BStree bst, Key key, Data_Item data)
{
    BStree_node* nodeP = *bst;
    BStree_node* nodeQ = NULL; // record the parent node to insert.

    while (nodeP != NULL)
    {
        nodeQ = nodeP;
        if (key_comp(nodeP->key, key) < 0)
        {
            nodeP = nodeP->right;
        } else if (key_comp(nodeP->key, key) > 0)
        {
            nodeP = nodeP->left;
        } else
        { //key is in bst, then do nothing.
            return;
        }
    }

    if (nodeQ == NULL)
    {
        //tree is empty before insert
        *bst = (BStree_node*) malloc(sizeof(BStree_node));
        (*bst)->data = data;
        (*bst)->key = key_gen(key.key1, key.key2);
        (*bst)->left = NULL;
        (*bst)->right = NULL;
    } else if (key_comp(nodeQ->key, key) < 0)
    { //insert to right node
        nodeQ->right = (BStree_node*) malloc(sizeof(BStree_node));
        nodeQ->right->data = data;
        nodeQ->right->key = key_gen(key.key1, key.key2);
        nodeQ->right->left = NULL;
        nodeQ->right->right = NULL;
    } else
    { //insert to left node
        nodeQ->left = (BStree_node*) malloc(sizeof(BStree_node));
        nodeQ->left->data = data;
        nodeQ->left->key = key_gen(key.key1, key.key2);
        nodeQ->left->left = NULL;
        nodeQ->left->right = NULL;
    }
}

//If key is in bst, return a pointer to key¡¯s associated data.
//If key is not in bst, return NULL
Data_Item *bs_tree_search(BStree bst, Key key)
{
    BStree_node* nodeP = *bst;
    while (nodeP != NULL)
    {
        if (key_comp(nodeP->key, key) < 0)
        {
            nodeP = nodeP->right;
        } else if (key_comp(nodeP->key, key) > 0)
        {
            nodeP = nodeP->left;
        } else
        { //key is in bst, then do nothing.
            return &nodeP->data;
        }
    }
    return NULL;
}

//help to print tree
void bs_tree_traversal_helper(BStree_node * node)
{
    if (node != NULL)
    {

        bs_tree_traversal_helper(node->left);
        key_print(node->key);
        data_print(node->data);
        printf("\n");
        bs_tree_traversal_helper(node->right);
    }
}

//In order traversal of bst and print each node¡¯s key and data
void bs_tree_traversal(BStree bst)
{
    bs_tree_traversal_helper(*bst);
}

//help to free bs_tree
void bs_tree_free_helper(BStree_node * node)
{
    if (node == NULL)
    {
        return;
    }
    bs_tree_free_helper(node->left);
    bs_tree_free_helper(node->right);
    free(node->key.key1);
    free(node->key.key2);
    free(node);
}

//Free all the dynamically allocated memory of bst.
void bs_tree_free(BStree bst)
{
    bs_tree_free_helper(*bst);
    free(bst);
}

