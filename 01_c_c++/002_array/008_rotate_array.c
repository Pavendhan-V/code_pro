#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    int rotate = 5;
    int rotate_arr[size];

    for (int i = rotate; i < size; i++) {
        rotate_arr[i - rotate] = arr[i];
    }

    for (int i = 0; i < rotate; i++) {
        rotate_arr[size - rotate + i] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        printf("%d ",rotate_arr[i]);
    }
    printf("\n");


    return 0;
}