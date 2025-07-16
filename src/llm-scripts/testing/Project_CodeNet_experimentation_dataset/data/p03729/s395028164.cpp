#include<stdio.h>
#include<string.h>
int main()
{
    char x[100], y[100], z[100];
    scanf("%s %s %s", x, y, z);
    int lenA = strlen(x);
    int lenB = strlen(y);
    if(x[lenA - 1] == y[0] && y[lenB - 1] == z[0])
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}