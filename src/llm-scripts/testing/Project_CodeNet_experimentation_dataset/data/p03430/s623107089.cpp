#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300+10;
int dp[2][MAXN][2][2][MAXN];
char str[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin>>str;
    int K,N=strlen(str);
    cin>>K;
    int ans=0;
    for(int i=0;i<N;++i)
    {
        int ii=i%2;
        for(int j=N-1;j>=i;--j)
        {
            for(int k=0;k<=K;++k)
            {
                dp[ii][j][0][0][k]=max(max(dp[!ii][j][0][0][k],dp[!ii][j][1][0][k]),max(dp[ii][j+1][0][0][k],dp[ii][j+1][0][1][k]));
                dp[ii][j][0][1][k]=max(dp[!ii][j][0][1][k],dp[!ii][j][1][1][k]);
                dp[ii][j][1][0][k]=max(dp[ii][j+1][1][0][k],dp[ii][j+1][1][1][k]);
                if(str[i]==str[j])
                    dp[ii][j][1][1][k]=max(max(dp[!ii][j][0][0][k],dp[!ii][j][1][0][k]),max(dp[ii][j+1][0][0][k],dp[ii][j+1][0][1][k]))+1;
                else if(k!=0)
                    dp[ii][j][1][1][k]=max(max(dp[!ii][j][0][0][k-1],dp[!ii][j][1][0][k-1]),max(dp[ii][j+1][0][0][k-1],dp[ii][j+1][0][1][k-1]))+1;
                int tmp=0;
                for(int ui=0;ui<2;++ui)
                    for(int uj=0;uj<2;++uj)
                        if(!(ui&&uj))
                            tmp=max(tmp,dp[ii][j][ui][uj][k]);
                ans=max(ans,tmp*2);
                if(i==j)
                    ans=max(ans,2*dp[ii][j][1][1][k]-1);
                else ans=max(ans,2*dp[ii][j][1][1][k]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
