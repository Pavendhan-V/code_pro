
/*
Rotation of a Matrix:
    Write a program to rotate a matrix 90 degrees clockwise or counterclockwise
*/

// To rotate a matrix 90∘ clockwise:
// Transpose the matrix (convert rows to columns).
// Reverse the rows of the transposed matrix.

#include <stdio.h>

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    /* clocke wise 90deg */
    // step 1 : Transpose the matrix (convert rows to columns).
    for (int  i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // step 2 : Reverse the rows of the transposed matrix.
    int colSize = 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (colSize / 2); j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][colSize - j - 1];
            matrix[i][colSize - j - 1] = temp;
        }
    }

    printf("Rotated matrix of 90deg clockwise\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }


    /* counter clocke wise 90deg */
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // step 1 : Transpose the matrix (convert rows to columns).
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int temp = matrix1[i][j];
            matrix1[i][j] = matrix1[j][i];
            matrix1[j][i] = temp;
        }
    }

    // step 2 : Reverse the coloms of the transposed matrix.
    int rowSize = 3;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < rowSize / 2; i++) {
            int temp = matrix1[i][j];
            matrix1[i][j] = matrix1[rowSize - i -1][j];
            matrix1[rowSize - i -1][j] = temp;
        }
    }

    printf("Rotated matrix of 90deg clockwise\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ",matrix1[i][j]);
        }
        printf("\n");
    }

    return 0;
}