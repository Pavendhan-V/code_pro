
/*

Write a program to multiply two matrices.
Explain the conditions under which matrix multiplication is possible.
        Matrix multiplication is possible under the following condition:
        Condition:
        The number of columns in the first matrix must be equal to the number of rows in the second matrix.
        If:
            • Matrix AAAis of size m×nm \times nm×n(m rows, n columns), and
            • Matrix BBBis of size p×qp \times qp×q(p rows, q columns),
        Matrix multiplication A×BA \times BA×Bis possible only if n=p n=p n=p.
*/

#include <stdio.h>

int main()
{
    int matrix1[3][3] = {
        {1, 2, 3},
        {5, 6, 7,},
        {9, 10, 11,}
    };

    int matrix2[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int matrix3[3][4];

    printf("matrix mul started\n");
    for (int row1 = 0; row1 < 3; row1++) {
        for (int col2 = 0; col2 < 4; col2++) {
            for (int col1 = 0; col1 < 3; col1++) {
                matrix3[row1][col2] += matrix1[row1][col1] * matrix2[col1][col2];
            }
        }
    }

    printf("matrix2 \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ",matrix3[i][j]);
        }
        printf("\n");
    }

    return 0;
}