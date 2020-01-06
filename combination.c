
#include <stdio.h>
#include <malloc.h>

void combination(int * arr , int n, int len, int start_pos, int *result , int rsize);
void main()
{
    int arr[] = { 0,3, 5, 7, 8, 9};
    int r = 3;

    int *result = malloc(sizeof(int) * r);

    combination(arr, sizeof(arr)/sizeof(arr[0]), /*r= */3,/*start_pos = */ 0, result, r);
}

void print_array(int *result, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}

void combination(int * arr , int n, int len, int start_pos, int *result, int result_size)
{
    if (len == 0){
        print_array(result, result_size);
        return;
    }       
    for (int i = start_pos; i <= n - len; i++){
        result[result_size - len] = arr[i];
        combination(arr, n, len-1, i+1, result, result_size);
    }
}       
