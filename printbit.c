#include <stdio.h>
#include <assert.h>

void printbits(int a);

int main()
{

    int a = -10;

    unsigned int b = 10;
    b = ~b;
    b += 1;
    printf("%d\n", b);

    printbits(b);
    printbits(10);
    printbits(1);
    return 0;
}

void printbits(int a)
{
    int n = 0;
    int size_of_int = sizeof(a) * 8;
    unsigned int mask = (0x1 << 31);
    int shift = 31;

    printf("bit printing:%d\n", a);

    while(n < size_of_int)
    {
        assert(mask);
        unsigned int bit =  ((a & mask) >> shift);
        printf("%u\t", bit);
        mask >>= 1;
        shift--;
        n++;
    }
    printf("\n");
}


