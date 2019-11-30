#include <malloc.h>
#include <stdio.h>
int* countBits(int num, int* returnSize);

int main()
{
    int num = 2;
    int size;
    int *retarray = countBits(2, &size);

    for(int i = 0; i < size; i++)
    {
        printf("%d\t", retarray[i]);
    }
    return 0;
}

int* countBits(int num, int* returnSize){

    int * out = malloc((num + 1) * sizeof(int));

    *returnSize = num + 1;

    out[0] = 0;
    out[1] = 1;
    out[2] = 1;

    for (int i = 3; i <= num ; i++)
    {
        int prev = i & (i - 1);

        out[i] = 1 + out[prev];

    }
    return out;

}


