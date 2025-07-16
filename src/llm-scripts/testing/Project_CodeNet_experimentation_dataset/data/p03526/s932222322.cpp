#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , dp[5005][5005];
pair<ll,ll> a[5005];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    return x.first+x.second < y.first+y.second;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    sort(a,a+n,cmp);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=i;j++){
            if(dp[i][j]<=a[i].first)
                dp[i+1][j+1]=min(dp[i+1][j+1] , dp[i][j] + a[i].second);
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
        }
    }
    for(ll i=n;i>=0;i--)if(dp[n][i]<(1e16))return cout<<i , 0;
}