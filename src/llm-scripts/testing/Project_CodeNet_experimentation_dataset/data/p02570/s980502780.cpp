#include<stdio.h>
int D,T,S;
int main()
{
    scanf("%d %d %d",&D,&T,&S);
    if((D+S-1)/S<=T)printf("Yes");
    else printf("No");
}
