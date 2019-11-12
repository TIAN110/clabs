#include <stdio.h>


int  strindex(char s[], char t[]);
int  strindex2(char s[], char t[]);
int main()
{
    char s[] = "hello 00000 hello 00000";
    char t[] = "hello";
    int index;

    index = strindex(s, t);
    printf("%d\n", index);

    index = strindex2(s, t);
    printf("%d\n", index);
}


int  strindex(char s[], char t[])
{
    int i, j, k, l;
    for (i = 0; s[i] != '\0'; i++)
        ;
    for (j = 0; t[j] != '\0'; j++)
        ;

    j--; 

    while (--i >= j) 
    {
        k = i;
        l = j;
        while (l >= 0 && s[k--] == t[l--])
            ;
        if (l < 0) 
            return ++k; 
    }
    return -1;
}


int  strindex2(char s[], char t[])
{
    int i, j, k, l;
    l = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (t[k] == '\0')
            l = i;
    }
    return l;
}
