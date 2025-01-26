#include <stdio.h>

int main()
{
    // int arr1[] = {1, 3, 5, 7, 9};
    // int arr2[] = {0, 2, 4, 6, 8};

    int arr1[] = {1, 3, 5, 7, 9, 11, 13, 15, 16, 17, 19};
    int arr2[] = {0, 2, 4, 6, 8};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int i = 0, j = 0, k = 0;

    int size3 = size1 + size2;
    int arr3[size3];

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        arr3[k++] = arr1[i++];
    }

    while ( j < size2)
    {
        arr3[k++] = arr2[j++];
    }

    for (int m = 0; m < size3; m++) {
        printf("%d ",arr3[m]);
    }
    printf("\n");    


    return 0;
}