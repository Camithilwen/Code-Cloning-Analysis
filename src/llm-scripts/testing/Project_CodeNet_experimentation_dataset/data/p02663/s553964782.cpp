#include<stdio.h>

int main()
{
    int h1,h2,m1,m2,k;
    scanf("%d%d%d%d%d",&h1,&m1,&h2,&m2,&k);
    m1+=60*h1;
    m2+=60*h2;
    printf("%d\n",m2-m1-k);
    return 0;
}