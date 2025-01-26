/*
    Write a program to find the transpose of a given matrix.s


Original Matrix (3x2):
1  2
3  4
5  6

Transposed Matrix (2x3):
1  3  5
2  4  6

*/

#include <stdio.h>


int main()
{
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int transpose_matrix[4][3];

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            transpose_matrix[col][row] = matrix[row][col];
        }
    }

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ",transpose_matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}