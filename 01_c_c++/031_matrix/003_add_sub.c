
/*
        Write a program to add and subtract two matrices.
*/

#include <stdio.h>

int main()
{
    int matrix1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int matrix2[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int add[3][4];
    int sub[3][4];

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            add[row][col] = matrix1[row][col] + matrix2[row][col];
            sub[row][col] = matrix1[row][col] - matrix2[row][col];
        }
    }

    printf("Matrix addition\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%d ",add[row][col]);
        }
        printf("\n");
    }

    printf("Matrix subtraction\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%d ",sub[row][col]);
        }
        printf("\n");
    }

    return 0;
}