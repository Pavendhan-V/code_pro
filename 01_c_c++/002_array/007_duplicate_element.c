#include <stdio.h>

int main()
{
    // int arr[] = {1, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 0, 0};
    int arr[] = {1, 1, 1, 3, 4, 4, 3, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int found[20];
    int count = 0;

    for (int i = 0; i < size; i++) {
        count = 0;    
        if (found[i] == 1) {
            continue;
        }

        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                found[j] == 1;
                count++;
            }
        }

        if (count == 1)
            printf("%d ",arr[i]);
    }

    return 0;
}