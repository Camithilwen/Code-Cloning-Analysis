#include<stdio.h>
int a,b,c,d,e[1001],f[1001],g[1001],h[1001],x[1001],y[1004],z[1001];
int main(void)
{
    while(scanf("%d%d%d",&a,&b,&c),a + b + c)
    {
        int result[320] = {0};
        scanf("%d",&d);

        for(int i = 0; i < d; i++)
        {
            scanf("%d%d%d%d",&e[i],&f[i],&g[i],&h[i]);
            if(h[i] == 1)//ok!
            {
                result[e[i]-1] = 1;x[i] = e[i];
                result[f[i]-1] = 1;y[i] = f[i];
                result[g[i]-1] = 1;z[i] = g[i];
            }
        }

        for(int i = 0; i < d; i++)
        {
            if(h[i] == 0)
            {
                if(result[f[i]-1] == 1 && result[g[i]-1] == 1)result[e[i]-1] = 2;
            }
            if(h[i] == 0)
            {
                if(result[e[i]-1] == 1 && result[g[i]-1] == 1)result[f[i]-1] = 2;
            }
            if(h[i] == 0)
            {
                if(result[f[i]-1] == 1 && result[e[i]-1] == 1)result[g[i]-1] = 2;
            }
        }
        for(int i = 0; i < a+b+c; i++)
        {
            if(result[i] == 2)result[i] = 0;
            else if(result[i] == 0)result[i] = 2;
            printf("%d\n",result[i]);
        }
    }
    return 0;
}