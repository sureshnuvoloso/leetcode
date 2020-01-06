#include <stdio.h>
#include <assert.h>

int
bsearch(int *a, int l, int r, int val);

void main()
{

//    int a[] = {-1, 1, 2, 2, 3,3, 3, 3, 3 , 6, 7, 8,8,8};
    int a[]= {2, 2, 2, 3};

    int size = sizeof(a)/sizeof(a[0]);
    int val = 3;

    int index = bsearch(a, 0, size - 1, val);
    
    printf("%d\n", index);
    assert(index < 0 || (a[index] == val && (index == 0 || a[index - 1] < val)));
}

int
bsearch(int *a, int l, int r, int val)
{

    int ret;

    printf("l = %d r= %d\n", l, r);

    if (a[l] == val)
    {
        printf("a[l] is val\n");
        return l;
    }

    if (a[l] > val)
        return -1;

#if 0
    if (l == r)
    {
        if (a[l] == val)
        {
            return a[l];
        }
    }
#endif


    if (l > r)
    {

        return -1;
    }

#if 0

    if ((r - l)  == 1)
    {
        if (a[r] == val)
        {
            return r;
        }
        else
        {
            return -1;
        }
    }
#endif

    int m = (l + r)/2;

    printf("m = %d a[m]:%d\n", m, a[m]);


    if (a[m] >= val)
    {
        ret =  bsearch(a, l, m - 1, val);
    }
    else 
    {
        ret =  bsearch(a, m + 1, r, val);
    }

    return ret;

}
