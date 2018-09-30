/*
 * datatype.h
 *
 */

#ifndef DATATYPE_H_
#define DATATYPE_H_

typedef float Data_Item;
typedef char* Sub_Key;

typedef struct
{
    Sub_Key key1;
    Sub_Key key2;
} Key;

//compare 2 keys return -1 if key1 < key2, return 1
//if key1 > key2 , return 0 if key1 = key2
int key_comp(Key key1, Key key2);

// generate a key from a pair of strings
Key key_gen(Sub_Key key1, Sub_Key key2);

//print a key
void key_print(Key key);

//print a data
void data_print(Data_Item data);

#endif /* DATATYPE_H_ */
