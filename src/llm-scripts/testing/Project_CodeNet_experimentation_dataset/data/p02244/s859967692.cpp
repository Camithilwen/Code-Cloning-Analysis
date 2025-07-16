#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,hang[8],lie[8],zuo[15],you[15];//标记行，列，斜下，斜上
int book[8][8];//控制输出
void print()
{

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(book[i][j])
            {
                if(hang[i]!=j)
                    return ;
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(hang[i]==j)
                printf("Q");
            else printf(".");
        }
        printf("\n");
    }
}
void dfs(int x)
{
    if(x==8)//判断输出
    {
        print();//输出后直接返回
        return ;
    }
    for(int i=0; i<8; i++)
    {
        if(lie[i]==1||zuo[i+x]==1||you[x-i+8-1]==1)
        {
            continue;
        }
        hang[x]=i;
        lie[i]=zuo[i+x]=you[x-i+8-1]=1;//标记列，斜下，斜上
        dfs(x+1);//往下递归
        hang[x]=lie[i]=zuo[x+i]=you[x-i+8-1]=-1;//取消标记
    }
    return ;
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(hang,-1,sizeof(hang));
        memset(lie,-1,sizeof(lie));
        memset(zuo,-1,sizeof(zuo));
        memset(you,-1,sizeof(you));
        memset(book,0,sizeof(book));
        int a,b;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            book[a][b]=1;
        }
        dfs(0);
    }
    return 0;
}

