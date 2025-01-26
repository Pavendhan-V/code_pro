/*
Write a program to find the maximum and minimum elements in a matrix.
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
    int min = matrix[0][0];
    int max = matrix[0][0];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (min > matrix[i][j]) {
                min = matrix[i][j];
            }
            if (max < matrix[i][j]) {
                max = matrix[i][j];
            }
        }
    }

    printf("min element : %d\n",min);
    printf("max element : %d\n",max);

    return 0;
}