
#include <stdio.h>
int getSum(int a, int b) ;
void printbits(int a);

int main()
{
    printf("%d\n", getSum(10, -11));
}

int getSum(int a, int b) {
    int carry = 0;
    while(b) {
        carry = a & b;
        printf("print carry:%u\n", carry);
        printbits(carry);
        a ^= b;
        b = (unsigned int)carry << 1;
        printf("print a:%u b:%u\n", a, b);
        printbits(a);
        printbits(b);
    }
    return a;
}

void printbits(int a)
{
    int n = 0;
    int size_of_int = sizeof(a) * 8;
    unsigned int mask = (0x1 << 31);

    printf("bit printing:%d\n", a);

    while(n < size_of_int)
    {
        unsigned int bit =  (a & mask);
        printf("%d\t", bit);
        mask >>= 1;
        n++;
    }
    printf("\n");
}
