#include <stdio.h>

int hexstring_to_int(char *str);
char * int_to_hex(int a) ;

void main()
{
    printf("%d\n", hexstring_to_int("18"));
    int_to_hex(42);

}

int hexstring_to_int(char *str)
{

    int out = 0;

    char * p = str;
    int count = 0;
#if 0
    while (*p)
    {
        p++;
        count++;
    }
#endif


    while(*p)
    {
        int val = *p - '0' ;
        out  = out * 16;
        out += val;
        p++;
    }

    return out;
}


char * int_to_hex(int a) 
{

    char p[25];
    int i = 0;
    char out;

    while(a)
    {
        int digit = a % 16; 
        if ( a < 10)
        {
            out = '0' + a;
        } 
        else
        {
            out = 'a' +   (10 - out);
        }
        p[i++] =  out;
        a = a / 16;
    }

    p[i] = '\0';
    printf("%s\n", p);


}
