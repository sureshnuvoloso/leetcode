#include <stdio.h>
#include <string.h>

int lcs(char * text1, char * text2, int swap);

int main()
{
    char *text1 = "oxcpqrsvwf";
    char *text2 = "shmtulqrypy";

#if 0
    char *text2 = "abcde";
    char *text1 = "ace";
#endif

    int ret = lcs(text1, text2, 0);
    printf("%d\n", ret);
}


int lcs(char * text1, char * text2, int swap){

    int cnt = 0;

    if (!text1 || !text2)
    {
        return 0;
    }

    if (!*text1 || !*text2)
    {
        return 0;
    }
    char *  first_string = text1;
    char *  second_string = text2;

    if (swap)
    {
        int len1 = strlen(text1);

        int len2 = strlen(text2);

        if (len1 < len2)
        {
            first_string= text2;
            second_string = text1;
        }
    }

    char * q_index = second_string;

    for (char *p= first_string; *p; p++)
    {
        for (char *q = q_index; *q; q++)
        {

            if (*p == *q) {

                cnt++;
                q_index = q + 1;
                break;
            }

        }
    }

    return cnt;


}


