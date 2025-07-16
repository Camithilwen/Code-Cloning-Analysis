#include<stdio.h>
#include<string.h>
#define N 8

int mp[N][N],row[N],col[N],dneg[2*N-1],dops[2*N-1];

void init()
{
    for(int i=0; i<N; i++)
        row[i]=col[i]=0;
    for(int i=0; i<2*N-1; i++)
        dneg[i]=dops[i]=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            mp[i][j]=0;
}

void check()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(mp[i][j])
            {
                if(row[i]!=j)
                    return ;
            }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%c",(row[i]==j)?'Q':'.');
        }
        printf("\n");
    }
    return ;
}

void dfs(int i)
{
    if(i==N)
    {
        check();
        return ;
    }
    for(int j=0; j<N; j++)
    {
        if(col[j] || dops[i+j] || dneg[i-j+N-1]) continue;
        row[i]=j;
        col[j]=dops[i+j]=dneg[i-j+N-1]=1;
        dfs(i+1);
        row[i]=col[j]=dops[i+j]=dneg[i-j+N-1]=0;
    }
}

int main()
{
    int k,r,c;
    while(~scanf("%d",&k))
    {
        init();
        for(int i=0; i<k; i++)
        {
            scanf("%d%d",&r,&c);
            mp[r][c]=1;
        }
        dfs(0);
    }
    return 0;
}

