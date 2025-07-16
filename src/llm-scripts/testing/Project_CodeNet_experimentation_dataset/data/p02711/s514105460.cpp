#include<stdio.h>

int main()
{
    int n,i,dig,flag=0;

    scanf("%d",&n);

    while(n!=0)
    {
        dig = n%10;
        n = n/10;

        if(dig==7)
            flag++;
    }

    if(flag>0)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
