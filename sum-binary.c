#include <stdio.h>

int getSum(int a, int b);

int main()
{

    int a = -10;
    int b = -11;
    int val = getSum(a, b);
    printf("%d", val);
    return val;
}

int getSum(int a, int b){
    int n = 0;
    int size_of_int = sizeof(a) * 8;
    int outval = 0;
    int carry = 0;

    while(n < size_of_int)
    {
        int bit1 = a & 0x1;
        int bit2 = b & 0x1;
        int outbit = 0;

        outbit = bit1 ^ bit2 ^ carry;
        printf("n:%d bit1:%d bit2:%d carry:%d outbit:%d\n", n, bit1, bit2, carry, outbit);

        bit1 & bit2

        if (((bit1 == 1 && bit2 == 1))
                || ((carry == 1) && (bit1 == 1 || bit2 == 1)))
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }


        outbit = outbit << n;
        n++;

        outval |= outbit;

        a = a>>1;
        b = b>>1;

    }


    return outval;
}


