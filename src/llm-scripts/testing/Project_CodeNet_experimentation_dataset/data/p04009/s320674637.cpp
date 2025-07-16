#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int res,ll,rr,uu,dd,ad,R,L,D,U,sx,sy,h,w,pr[105][105],pc[105][105],dp[105][105][105];
char s[105][105];
int main()
{
    scanf("%d%d",&h,&w);
    for (int i=1;i<=h;++i)
        scanf("%s",s[i]+1);
    for (int i=1;i<=h;++i)
        for (int j=1;j<=w;++j) {
            pr[i][j]=pr[i-1][j]+(s[i][j]=='o');
            pc[i][j]=pc[i][j-1]+(s[i][j]=='o');
            if (s[i][j]=='E')
                sx=i,sy=j;
        }
    memset(dp,-1,sizeof dp);
    dp[0][0][0]=0;
    L=sy-1,R=w-sy,U=sx-1,D=h-sx;
    for (int l=0;l<=L;++l)
        for (int r=0;r<=R;++r)
            for (int u=0;u<=U;++u)
                for (int d=0;d<=D;++d) {
                    if (dp[r][u][d]==-1)
                        continue;
                    rr=min(sy+r,w-l);
                    ll=max(sy-l,r+1);
                    uu=max(sx-u,d+1);
                    dd=min(sx+d,h-u);
                    res=max(res,dp[r][u][d]);
                    if (l+r<R) {
                        ad=pr[dd][sy+r+1]-pr[uu-1][sy+r+1];
                        dp[r+1][u][d]=max(dp[r+1][u][d],dp[r][u][d]+ad);
                    }
                    if (u+d<U) {
                        ad=pc[sx-u-1][rr]-pc[sx-u-1][ll-1];
                        dp[r][u+1][d]=max(dp[r][u+1][d],dp[r][u][d]+ad);
                    }
                    if (u+d<D) {
                        ad=pc[sx+d+1][rr]-pc[sx+d+1][ll-1];
                        dp[r][u][d+1]=max(dp[r][u][d+1],dp[r][u][d]+ad);
                    }
                    if (l+r<L) {
                        ad=pr[dd][sy-l-1]-pr[uu-1][sy-l-1];
                        dp[r][u][d]=max(dp[r][u][d],dp[r][u][d]+ad);
                    }
                }
    printf("%d\n",res);
    return 0;
}