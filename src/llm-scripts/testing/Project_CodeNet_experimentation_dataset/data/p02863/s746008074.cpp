#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=1e6+10;
const int mod=1e9+7;
const double pi=3.1415926535;
int w[3005],v[3005];
int dp[3005][3005][2];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=t-1;j++)
        {
            dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][0]+v[i]);
            if(j>=w[i])
            {
                dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j-w[i]][0]+v[i]);
                dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-w[i]][1]+v[i]);
            }
            else
            {
                dp[i][j][0]=dp[i-1][j][0];
            }
        }
    }
    cout<<dp[n][t-1][1]<<'\n';






}
