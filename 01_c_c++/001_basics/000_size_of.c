
#include <stdio.h>

int main()
{
    int val;
    int size = (char *)(&val + 1) - (char *)(&val);

    printf("size of val : %d\n",size);

    return 0;
}