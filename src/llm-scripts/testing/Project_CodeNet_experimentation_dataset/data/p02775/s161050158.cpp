#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dp[1000005][2];

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

    string a;
    cin>>a;
    int n=a.length();
    reverse(a.begin(),a.end());
    a="#"+a;
    int ans=0;
    fill_n(&dp[0][0],1000005*2,1e17);
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        int z=a[i]-'0';
        dp[i][0]=min(dp[i][0],dp[i-1][0]+z);
        dp[i][1]=min(dp[i][1],dp[i-1][0]+(10-z));
        z++;
        dp[i][0]=min(dp[i][0],dp[i-1][1]+z);
        dp[i][1]=min(dp[i][1],dp[i-1][1]+(10-z));
    }
    int mn=min(dp[n][0],dp[n][1]+1);
    cout<<mn;
} 

