
/*
How do you check if a given matrix is an identity matrix?
    An identity matrix is a square matrix (i.e., the number of rows equals the number of columns) in which:
    All the diagonal elements are 1.
    All other elements are 0.
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool isIdentity = 1;

    int matrix[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (row == col) { // i == j -> 1
                if (matrix[row][col] != 1) {
                    isIdentity = 0;
                    break;
                }
            }
            else {
                if (matrix[row][col] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }

        if (!isIdentity)
            break;
    }

    printf("matrix identity status : %d\n",isIdentity);
}