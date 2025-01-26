#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int isNoMissing = 0;
    int missingNo = -1;

    for (int i = 0; i < size - 1; i++) {
        if ((arr[i+1] - arr[i]) != 1) {
            isNoMissing = 1;
            missingNo = arr[i] + 1;
            break;
        }
    }

    if (isNoMissing) {
        printf("missing no : %d\n",missingNo);
    }
    else {
        printf("there is no missing no\n");
    }

    return 0;
}