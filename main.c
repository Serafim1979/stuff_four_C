#include <stdio.h>
#include <stdlib.h>
///////////////////////////////////////
int StringLen(char *s);
char *StringCat(char *s1, char *s2);
int StringToInt(char*s, int min, int max, int *prez);
///////////////////////////////////////
int main()
{
    int n, rez = 0;
    char buf[255];
    char *s1 = "abcdef";
    char *s2 = "12345";
    char *s3 = StringCat(s1, s2);
    int len = StringLen(s3);

    printf("len = %d\n", len);
    printf("%s\n", s3);

    printf("Input number (1-15): ");
    scanf("%s", buf);

    n = StringToInt(buf, 1, 15, &rez);
    if(n == -1)
        printf("Enter to integer\n");
    else if(n == -3)
        printf(">=1\n");
    else if(n == -5)
        printf("<=15\n");

    printf("rez = %d \n", rez);

    free(s3);

    return 0;
}
///////////////////////////////////////
int StringToInt(char*s, int min, int max, int *prez)
{
    int n = 0, rez = 0;

    if(s == NULL || prez == NULL || max < min)
        n = -13;
    else
    {
        rez = atoi(s);

        if(rez == 0)
        {
            if(StringLen(s) == 1 && s[0] == '0')
            *prez = 0;
                else n = -1;
        }
        else
        {
            if(rez < min)
                n = -3;
            else if(rez > max)
                n = -5;
            else *prez = rez;
        }
    }
    return n;
}
///////////////////////////////////////
int StringLen(char *s)
{
    int i;

    if(s == NULL)
        i = -1;
    else
        for(i = 0; s[i] != '\0'; i++);

    return i;
}
////////////////////////////////////////
char *StringCat(char *s1, char *s2)
{
    int i;

    int lenOne = StringLen(s1);
    int lenTwo = StringLen(s2);

    char*rez = (char*)malloc(lenOne+lenTwo+1);

    for(i = 0; i < lenOne; i++)
    {
        rez[i] = s1[i];
    }

    for(; i < lenOne + lenTwo + 1; i++)
    {
        rez[i] = s2[i-lenOne];
    }

    return rez;
}
