//
//  data.h
//  
//
//  Created by Yixin Zhang on 2016-03-15.
//
//

#ifndef data_h
#define data_h

#include <stdio.h>
typedef struct {
    int key;
    char *data;
}Node;

void print_node(Node node);


char *data_dup(char *data);

#endif /* data_h */
