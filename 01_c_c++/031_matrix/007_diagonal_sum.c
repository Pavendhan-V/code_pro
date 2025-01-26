/*
Write a program to calculate the sum of diagonal elements of a square matrix.
*/

#include <stdio.h>

int main()
{
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int diagonalSum = 0;

    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         if (i == j)
    //             diagonalSum += matrix[i][j];
    //     }
    // }

    for (int i = 0; i < 4; i++) {
        diagonalSum += matrix[i][i];
    }

    printf("diagonal sum : %d\n",diagonalSum);
}