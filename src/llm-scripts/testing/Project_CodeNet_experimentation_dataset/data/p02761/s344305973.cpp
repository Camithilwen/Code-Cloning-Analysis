#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int n,m;
int s[5];
int c[5];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    scanf("%d %d",&s[i],&c[i]);

    for(int i=0;i<1000;i++)
    {
        char num[5];
        sprintf(num,"%d",i);
        // itoa(i,num,10);
        if(strlen(num)!=n) continue;
        bool flag=true;
        for(int j=0;j<m;j++)
        {
            if(num[s[j]-1]!=c[j]+'0')
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}