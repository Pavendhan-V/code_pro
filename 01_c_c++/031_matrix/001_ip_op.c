/*
            Matrix Input and Output

Write a program to take input for a matrix and display it.
How do you store a 2D matrix in C?

*/


#include <stdio.h>

int main()
{
    int matrix[3][3];

    for (int row = 0; row < 3; row++) {
        printf("enter matrix row %d\n",row);
        for (int col = 0; col < 3; col++) {
            scanf("%d",&matrix[row][col]);
        }
    }

    printf("Final matrix\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    }



    return 0;
}