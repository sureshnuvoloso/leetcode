#include <stdio.h>
void rotate(int nums[], int n, int k);
void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

int swap(int *p1 , int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

#if 0
#define swap(a, b)              do{\
          int tmp = (a);           \
          (a) = (b);               \
          (b) = tmp;               \
} while(0)
#endif


void main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int size = sizeof(a)/sizeof(a[0]);
    rotate(a, size, 3);
    printarray(a, size);
}


void rotate(int nums[], int n, int k) {
    for (; k %= n; n -= k)
        for (int i = 0; i < k; i++)
            swap(nums++, &nums[n - k]);
}
