//
//  bst.c
//  
//
//  Created by Yixin Zhang on 2016-03-15.
//  This program is difficult.
//  I do the best I can :)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

//Input: ’size’: size of an array
//Output: a pointer of type BStree,
//i.e. a pointer to an allocated memory of BStree_struct type

//Effect: dynamically allocate memory of type BStree_struct
//allocate memory for a Node array of size+1 for member tree_nodes allocate
//memory for an unsigned char array of size+1 for member is_free
//set all entries of is_free to 1
//set member size to ’size’;
BStree bstree_ini(int size) {
    int i;
    //make a BStree
    BStree tree = (BStree_struct*)malloc(sizeof(BStree));
    //allocate memory for a Node array
    tree->tree_nodes= (Node*)malloc((size+1)*sizeof(Node));
    //allocate memory for a unsigned char array
    tree->is_free= (unsigned char*)malloc((size+1)*sizeof(unsigned char));
    
    for (i=0; i<size; i++) {
        tree->is_free[i]= 1;
        bstree_insert(tree, i, tree->tree_nodes[i].data);
    }
    return tree;
}


// Input: ’bst’: a binary search tree ’key’: an integer
//’data’: a string
//Effect: ’data’ with ’key’ is inserted into ’bst’
//if ’key’ is in ’bst’, do nothing
void bstree_insert(BStree bst, int key, char *data) {
    int i;
    //Using the helper function
    //  the previous code is : void helper(bst,key,data,i);
    //but there is an error and i can't find it
    void helper();
    
    
}
void helper(BStree bst,int key, char *data, int i){
    for(i=0;;i++){
        
    if (bst->is_free[i]==1) {
        //if the tree is free, insert the key and data
        data_dup(bst->tree_nodes[i].data);
    }
    else{
        //if the tree is not free
        if (i < key) {
            //if the holding key is greater then the key you want to insert,
            //go to left
            data_dup(bst->tree_nodes[2*i].data);
        }
        else if(i > key){
            //if the holding key is less then the key you want to insert,
            //go to right
            data_dup(bst->tree_nodes[2*i+1].data);
        }
        else
            //else, do nothing
            return ;
    }
    }
    
}


// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
    int i;
    if (bst) {
        //Here is the inorder traversal.
        //Check the left most subtree starting at the left external node
        //visit parent node
        //visit the right subtree
        if (bst->is_free != '1'){
        bst_traversal(bst->tree_nodes[2*i].data);
            printf("%s",bst->tree_nodes->data);
        bst_traversal(bst->tree_nodes[2*i+1].data);
        
    }
    }
    
}

// Input: ’bst’: a binary search tree
// Effect: all memory used by bst are freed
void bstree_free(BStree bst) {
    free(bst->tree_nodes);
    free(bst->is_free);
    free(bst);
}

int main(void) {
    //Enter a size.
    int size;
    printf("Please enter a size: ");
    scanf("%d", &size);
    //Sample case
    BStree bst;
    bst = bstree_ini(size);
    bstree_insert(bst, 6, "correct");
    bstree_insert(bst, 3, "is");
    bstree_insert(bst, 9, "output");
    bstree_insert(bst, 4, "the");
    bstree_insert(bst, 6, "incorrect");
    bstree_insert(bst, 20, "!");
    bstree_insert(bst, 1, "This");
    bstree_traversal(bst);
    bstree_free(bst);
}
