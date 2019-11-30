#define min(a, b) ((a < b) ? a : b)

int maxArea(int* height, int heightSize);
int main()
{
    int a[] =  {1,2,4,3};
    maxArea(a, sizeof(a)/sizeof(a[0]));
    return 0;
}


int maxArea(int* height, int heightSize)
{

    int l = 0;
    int r = heightSize - 1;
    int *a = height;
    int support = min(a[l], a[r]);

    int max_area = support * (r - l);

    while ( l < r )
    {
        int area = 0;

        while( l < r && (min(a[l], a[r]) <= support))
        {
            l++;
        }

        if (l < r)
        {

            area = min(a[l], a[r]) * (r-l);

            if (area > max_area)
            {
                support = min(a[l], a[r]);
                max_area = area;
            }
            else
            {
                l++;
            }

        }
        else
        {
            l = 0;

            while (l < r && a[r] <= support)
            {
                r--;
            }

            if (l < r)
            {
                support = a[r];
                continue;
            }
            else
            {
                break;
            }

        }
    }

    return max_area;

}


