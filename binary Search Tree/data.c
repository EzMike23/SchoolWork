//
//  data.c
//  
//
//  Created by Yixin Zhang on 2016-03-15.
//
//

#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
// Input: ’node’: a node
// Effect: node.key is printed and then the node.data is printed

void print_node(Node node) {
    printf("%d, %s", node.key, node.data);
    //print the key and the data
}


// Input: ’data’: a string ends with ’\0’
// Output: a pointer of type pointer to char,
// pointing to an allocated memory containing a copy of ’data’
// Effect: dynamically allocate memory to hold a copy of ’data’

char *data_dup(char *data) {
    scanf("%c", &*data);
    //get the data
    char *c;
    c= (char*)malloc(sizeof(data));
    //point to a dynamically allocated memory that can
    //hold  a copy of 'data'
    return c;
    
}
