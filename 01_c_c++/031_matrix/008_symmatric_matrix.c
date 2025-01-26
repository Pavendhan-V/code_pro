
/* 
Write a program to check if a matrix is symmetric.
    A matrix is said to be symmetric if it is a square matrix and its transpose is equal to itself. In other words, a matrix AAAis symmetric if:
A[i][j]=A[j][i]
*/

#include <stdio.h>

int main()
{
    // int matrix[3][3] = {
    //     {1, 2, 3},
    //     {2, 4, 5},
    //     {3, 5, 6}
    // };
    int matrix[3][3] = {
        {1, 2, 3},
        {2, 7, 5},
        {3, 8, 6}
    };
    int isSymmetric = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }

    if (isSymmetric) {
        printf("matrix is symmetric\n");
    }
    else {
        printf("matrix is not symmetric\n");
    }

    return 0;
}