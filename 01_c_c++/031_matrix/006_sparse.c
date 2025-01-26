/*
Sparse Matrix
    Write a program to identify whether a given matrix is sparse.
    How can a sparse matrix be represented efficiently in C?
        Compressed Sparse Row (CSR) Representation
            In CSR representation, the matrix is represented by three arrays:
            value[]: Non-zero elements.
            colIndex[]: Column indices of the non-zero elements.
            rowPointer[]: Indicates the starting index of each row in the value[] array.
*/
// The number of zero elements is significantly greater than the number of non-zero elements.
// Sparse matrices are usually stored and processed in specialized ways to save memory and improve performance.

#include <stdio.h>

int main()
{
    // int matrix [4][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    //     {10, 11, 12}
    // };
    int matrix [4][3] = {
        {0, 2, 3},
        {4, 0, 0},
        {0, 8, 0},
        {0, 0, 0}
    };
    int count = 0;
    int nonZero = 0;
    int totalSize = 4 * 3;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0)
                count++;
            else
                nonZero++;
        }
    }

    if (count > (totalSize / 2)) {
        printf("matrix is sparse\n");
    }
    else {
        printf("matrix is not sparse\n");
    }

    // compressed sparse row reprasenstation
    int row[nonZero];
    int col[nonZero];
    int value[nonZero];
    int index = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != 0) {
                row[index] = i;
                col[index] = j;
                value[index] = matrix[i][j];
                index++;
            }
        }
    }

    printf("nonZero : %d\n",nonZero);

    printf("row : ");
    for (int i = 0; i < nonZero; i++) {
        printf("%d ", row[i]);
    }
    printf("\n");

    printf("col : ");
    for (int i = 0; i < nonZero; i++) {
        printf("%d ", col[i]);
    }
    printf("\n");

    printf("value : ");
    for (int i = 0; i < nonZero; i++) {
        printf("%d ", value[i]);
    }
    printf("\n");

    return 0;
}