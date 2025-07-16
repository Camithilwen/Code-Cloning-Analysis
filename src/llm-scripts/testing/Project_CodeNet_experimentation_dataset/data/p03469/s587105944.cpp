#include <stdio.h>

int main()
{
    char s[12];
    scanf("%s", &s);
    s[3]++;
    printf("%s\n", s);
    return 0;
}