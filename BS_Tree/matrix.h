/*
 * matrix.h
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include "datatype.h"
#include "bs_tree.h"

typedef BStree Matrix;
typedef Sub_Key Index;

//Matrix construction using bs_tree ini();
Matrix matrix_construction(void);

//If at location (index1, index2) in Matrix m, the value is defined,
//then return a pointer to the associated data. Otherwise, return NULL.
Data_Item *matrix_get(Matrix m, Index index1, Index index2);

//Assign data to Matrix m at location (index1, index2).
void matrix_set(Matrix m, Index index1, Index index2, Data_Item data);

//Print values in the Matrix m (with bs_tree_traversal()).
void matrix_listing(Matrix m);

//Free allocated space (with bs_tree_free()).
void matrix_destruction(Matrix m);

#endif /* MATRIX_H_ */
