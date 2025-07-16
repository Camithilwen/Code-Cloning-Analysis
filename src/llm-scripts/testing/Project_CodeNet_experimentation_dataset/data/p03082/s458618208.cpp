#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int dp[2][100005];
const int mod=1e9+7;

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    int n,x;
    cin>>n>>x;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    
    dp[0][x]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
            dp[i&1][j]=0;
        for(int j=0;j<=x;j++)
        {
            dp[i&1][j%a[i]]+=dp[(i+1)&1][j];
            dp[i&1][j]+=(dp[(i+1)&1][j]*(n-i))%mod; 
            dp[i&1][j]%=mod; 
            dp[i&1][j%a[i]]%=mod; 
        }
    }

    int ans=0;
    for(int i=0;i<=x;i++)
    {
        ans=(ans+dp[n&1][i]*i)%mod;
    }
    cout<<ans;

} 

