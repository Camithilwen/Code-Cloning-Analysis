#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=1e6+10;
const int mod=1e9+7;
const double pi=3.1415926535;
int w[3005],v[3005];
int dp[3005][2];




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
        for(int j=t-1;j>=0;j--)
        {
            for(int x=1;x>=0;x--)
            {
                if(x==0)
                {
                    if(j>=w[i])
                    {
                        dp[j][x]=max(dp[j][x],dp[j-w[i]][x]+v[i]);
                    }
                }
                else
                {
                    dp[j][x]=max(dp[j][x],dp[j][0]+v[i]);
                    if(j>=w[i])
                    {
                        dp[j][x]=max(dp[j][x],dp[j-w[i]][x]+v[i]);
                    }
                }
            }
        }
    }
    cout<<dp[t-1][1]<<'\n';






}
