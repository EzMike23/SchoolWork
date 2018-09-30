#include "datatype.h"
#include "string.h"
#include <stdio.h>

//compare 2 keys return -1 if key1 < key2, return 1
//if key1 > key2 , return 0 if key1 = key2
int key_comp(Key key1, Key key2)
{
    if (strcmp(key1.key1, key2.key1) != 0)
    {
        return strcmp(key1.key1, key2.key1);
    } else
    {
        return strcmp(key1.key2, key2.key2);
    }
}

// generate a key from a pair of strings
Key key_gen(Sub_Key key1, Sub_Key key2)
{
    Key key;
    key.key1 = key1;
    key.key2 = key2;
    return key;
}

//print a key
void key_print(Key key)
{
    printf("%s\t%s\t", key.key1, key.key2);
}

//print a data
void data_print(Data_Item data)
{
    printf("%.0f\t", data);
}
