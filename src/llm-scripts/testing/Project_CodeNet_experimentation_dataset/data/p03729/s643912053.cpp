#include<stdio.h>
#include<string.h>
int main()
{
    char a[20], b[20], c[20];
    scanf("%s %s %s", &a, &b, &c);
    int al, bl;
    al = strlen(a)-1;
    bl = strlen(b)-1;
    if(a[al]==b[0] && b[bl]==c[0])
    printf("YES");
    else printf("NO");
}
