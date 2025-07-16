#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int arr[n][n];
for(int i=0;i<n;i++)
{
    for(int j=0;j<n-1;j++)
    {
        cin>>arr[i][j];
       arr[i][j]-=1;
    }
}
int dp[n+1]={};
int ans=0;
while(1)
{int jarorat[n]={};
int vis[n]={};
    for(int j=0;j<n;j++)
    {
        int x=dp[j];
        if(x!=n-1)
        jarorat[j]=(arr[j][x]);
        else
            vis[j]=1;
    }

    int cnt=0;
    for(int j=0;j<n;j++)
    {
        if(jarorat[jarorat[j]]==j&&vis[j]==0&&vis[jarorat[jarorat[j]]]==0)
        {
            dp[j]++;
            dp[jarorat[j]]++;
            vis[j]=1;
            vis[jarorat[j]]=1;
            cnt++;
        }
    }
    if(cnt==0)
        break;
        
    ans++;
}

for(int i=0;i<n;i++)
{
    if(dp[i]!=n-1)
    {
        cout<<-1<<endl;
        return 0;
    }
}
cout<<ans<<endl;
























    return 0;
}
