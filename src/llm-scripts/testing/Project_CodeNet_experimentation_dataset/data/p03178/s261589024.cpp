#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define flash ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
ll dp[2][2][100];
ll mod=1e9+7;ll d;
ll mo(ll x)
{
    if(x>=0)
    return(x%d);
    else
    return(x%d+d)%d;
}
int main()
{
    flash
    string s;
    cin>>s;ll n=s.size();ll a[n];
    for(ll i=0;i<n;i++)
    {
        a[i]=s[i]-'0';
    }
cin>>d;
  dp[1][0][0] = 1;dp[1][1][0] = 1;
 
    for(ll i = n-1; i >=0 ; i--) {
        for(ll state = 0; state < 2 ; state++) {
            for(ll sum = 0; sum < d; sum++) {
                if(state) {
                    for(ll x = 0; x <= a[i] ; x++) {
                        dp[0][1][sum] += (x== a[i]) ? dp[1][1][mo(sum-x)]%mod:dp[1][0][mo(sum-x)]%mod;
                    }
                }
                else {
                    for(ll x = 0; x < 10 ; x++) {
                        dp[0][0][sum] += dp[1][0][mo(sum-x)]%mod;
                    }
                }
            }
          }
          if(i!=0)
          {
         for(ll sum=0;sum<d;sum++)
            {
                dp[1][1][sum]=dp[0][1][sum];
                dp[1][0][sum]=dp[0][0][sum];
                dp[0][1][sum]=0;
                dp[0][0][sum]=0;
            }
          }
    }
    dp[0][1][0]--;
    if(dp[0][1][0]==-1)
    dp[0][1][0]=mod-1;
    dp[0][1][0]=dp[0][1][0]%mod;
    cout<<dp[0][1][0]<<endl;
}