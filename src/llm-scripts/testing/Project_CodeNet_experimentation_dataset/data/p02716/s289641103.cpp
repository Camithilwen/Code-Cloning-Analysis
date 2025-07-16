#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[200005],dp[200005][3],ans=-0x3f3f3f3f3f3f3f3fll;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    memset(dp,0xc0,sizeof(dp));
    dp[0][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<3;j++)
        {
            for(int k=i==1?1:2;k<=4;k++) if(i-k>=0)
                for(int g=0;g<3;g++) if(i/2+j-(i-k)/2-g==1)
                    dp[i][j]=max(dp[i][j],dp[i-k][g]+a[i]);
            if(i/2+j-1==n/2) ans=max(ans,dp[i][j]);
        }
    printf("%lld",ans);
    return 0;
}