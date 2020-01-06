#include <stdio.h>
#include <assert.h>

int
bsearch(int *a, int l, int r, int val);

void main()
{

//    int a[] = {-1, 1, 2, 2, 3,3, 3, 3, 3 , 6, 7, 8,8,8};
    //int a[]= {2, 2, 2, 3};
   // int a[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
//    int a[] = {30, 40, 50, 10, 20};
//    int a[] =  {4,5,6,7,8,9,1,2,3};
//   int a[] = {2, 3, 2, 2, 2};
//    int a[] = {1, 1, 3, 1};
//    int a[] = { 1, 3};
    int a[] = {1, 1, 3};
  //  int a[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};

    int size = sizeof(a)/sizeof(a[0]);
    int val = 3;

    int index = bsearch(a, 0, size - 1, val);
    
    printf("%d\n", index);
//    assert(index < 0 || (a[index] == val && (index == 0 || a[index - 1] < val)));
     assert(index < 0 || (a[index] == val));
}

int
bsearch(int *a, int l, int r, int val)
{

    int ret = -1;

    printf("l = %d r= %d\n", l, r);

    if (a[l] == val)
    {
        printf("a[l] is val\n");
        return l;
    }



    if (l > r)
    {

        return -1;
    }


    int m = (l + r)/2;

    printf("m = %d a[m]:%d\n", m, a[m]);


    if (a[m] == val && a[m - 1] != a[m]) 
    {
        return m;
    }

    // left is sorted and the val is in left
    if (a[l] < a[m] && (val <= a[m] && val > a[l]))
    {
        ret =  bsearch(a, l + 1, m - 1, val);
        goto _out;
    }

    // left is pivoted and the val is left

    if (a[l] > a[m] && (val <=a[m] || val > a[l]))
    {
        ret =  bsearch(a, l + 1, m - 1, val);
        goto _out;

    }

    // right is sorted and val is in right
    if (a[m] < a[r] && val >a[m] && val < a[r])
    {
        ret =  bsearch(a, m + 1, r , val);
        goto _out;

    }

    //right is pivoted

    if (a[m] >= a[r] && (val > a[m] || val <= a[r]))
    {
        ret = bsearch(a, m +1 , r, val);
        goto _out;
    }

_out:

    return ret;

}
