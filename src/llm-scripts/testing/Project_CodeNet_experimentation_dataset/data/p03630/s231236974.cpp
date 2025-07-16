#include <cstdio>
#include <algorithm>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
#define repd(i,x,y) for (int i=x; i>=y; --i)
using namespace std;

int n,m,len[2010],l[2010],r[2010],stk[2010],top,ans;
char a[2010][2010];

int main()
{
    scanf("%d%d",&n,&m);
    repu(i,1,n)
        scanf("%s",a[i]+1);
    ans=m;
    repu(i,1,m)
    {
        stk[top=0]=0;
        repu(j,1,n-1)
        {
            len[j]=i>1 && (a[j][i]==a[j+1][i])==(a[j][i-1]==a[j+1][i-1])?len[j]+1:1;
            for (; top && len[j]<=len[stk[top]]; --top);
            l[j]=stk[top],stk[++top]=j;
        }
        stk[top=0]=n;
        repd(j,n-1,1)
        {
            for (; top && len[j]<=len[stk[top]]; --top);
            r[j]=stk[top],stk[++top]=j;
            ans=max(ans,len[j]*(r[j]-l[j]));
        }
    }
    printf("%d\n",ans);
    return 0;
}