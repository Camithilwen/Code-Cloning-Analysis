#include<stdio.h>
int main()
{
    int a,b,c,d,s,s1;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a<b)
        s=a;
    else
        s=b;
        if(c<d)
            s1=c;
            else
            s1=d;
        printf("%d\n",(s+s1));

}