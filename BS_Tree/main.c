#include "datatype.h"
#include "bs_tree.h"
#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#define MAXLENGTH 50
int main()
{
    Matrix m = matrix_construction();

    while (1)
    {
        Index index1 = (Index) malloc(sizeof(char) * MAXLENGTH);
        Index index2 = (Index) malloc(sizeof(char) * MAXLENGTH);

        if (scanf("%s %s", index1, index2) != 2)
        {
            free(index1);
            free(index2);
            break;
        }

        float * data = matrix_get(m, index1, index2);

        if (data == NULL)
        {
            //insert new node
            float occurrences = 1;
            matrix_set(m, index1, index2, occurrences);
        } else
        {
            //already exist, update the data(occurrences)
            free(index1);
            free(index2);
            *data = *data + 1;
        }
    }
    printf("String1\tString2\tOccurrence\n");
    matrix_listing(m);
    matrix_destruction(m);
    return 0;
}
