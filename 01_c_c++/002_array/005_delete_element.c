#include <stdio.h>

void del_element(int arr[], int size, int element)
{
    for (int i = element; i < size; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size-1] = 0;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int delelement = 2;

    del_element(arr, size, delelement);
    del_element(arr, size, 2);
    del_element(arr, size, 2);

    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}