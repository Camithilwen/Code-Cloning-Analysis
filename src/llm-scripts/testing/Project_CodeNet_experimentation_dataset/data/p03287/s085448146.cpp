#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    vector<ll>sum(n+1);
    for(int i=1; i<=n; ++i){
        sum[i]=sum[i-1]+a[i-1];
    }
    map<ll,int>mp;
    ll ans=0;
    rep(i,n+1){
        ans+=mp[sum[i]%m];
        mp[sum[i]%m]++;
    }
    cout<<ans<<endl;
}