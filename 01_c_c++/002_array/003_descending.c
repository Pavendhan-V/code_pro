#include <stdio.h>

int main()
{
    int arr[] = {2, 4, 1, 5, 3, 5, 9, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}