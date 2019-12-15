 #include<string.h>
#include <stdio.h>
#include <malloc.h>
int wordBreak(char * s, char ** wordDict, int wordDictSize);

int main()
{
char *wordDict[2]  = { "leet", "code"};
//char *wordDict[2]  = { "aaaa", "aaa"};

int ret = wordBreak("leetcode", wordDict, 2);

printf("ret:%d", ret);

}



int lookup(const char *s, int len, char **wordDict, int wordDictSize)
{
    int wordcnt;
    char *tmp = strdup(s);
    tmp[len] = 0;


    for(wordcnt = 0; wordcnt < wordDictSize; wordcnt++)
    {   
        char * p = wordDict[wordcnt];

        if (!(strcmp(tmp, p)))
        {   
            printf("lookup call for %s succeeds\n", tmp);
            free(tmp);
            return 1;
        }
    }

    printf("lookup call for %s fails\n", tmp);
    free(tmp);
    return 0;
}

int wordBreak(char * s, char ** wordDict, int wordDictSize){

    printf("workdBreak call for %s\n", s);

    int *dp = malloc(strlen(s));
    dp[0] = 1;

    if(*s && (*(s+1) == '\0'))
    {
        if (lookup(s, 1, wordDict, wordDictSize))
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }


    for (char *t = s; *t; t++)
    {   
        if (lookup(s, t - s + 1, wordDict, wordDictSize))
        {  

            if (dp[t -s + 1] == 1)
            {
                return 1;
            }
            if (*(t + 1) == '\0') // the last word lookup is good
            {
                dp[t - s + 1] = 1;
                return 1;
            }
            /*
            if (wordBreak(t + 1, wordDict, wordDictSize))
            {
                return 1;
            }
            */

        }

    }
    return 0;
}


