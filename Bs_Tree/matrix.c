#include "matrix.h"

//Matrix construction using bs_tree ini();
Matrix matrix_construction(void)
{
    Matrix m = bs_tree_ini();
    return m;
}

//If at location (index1, index2) in Matrix m, the value is defined,
//then return a pointer to the associated data. Otherwise, return NULL.
Data_Item *matrix_get(Matrix m, Index index1, Index index2)
{
    Key key = key_gen(index1, index2);
    return bs_tree_search(m, key);
}

//Assign data to Matrix m at location (index1, index2).
void matrix_set(Matrix m, Index index1, Index index2, Data_Item data)
{
    Key key = key_gen(index1, index2);
    bs_tree_insert(m, key, data);
}

//Print values in the Matrix m (with bs_tree_traversal()).
void matrix_listing(Matrix m)
{
    bs_tree_traversal(m);
}

//Free allocated space (with bs_tree_free()).
void matrix_destruction(Matrix m)
{
    bs_tree_free(m);
}
