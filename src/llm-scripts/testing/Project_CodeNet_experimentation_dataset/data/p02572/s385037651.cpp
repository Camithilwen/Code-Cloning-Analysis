#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
using namespace std;
const int mod=1e9+7;

ll solve(){
    ll sm=0,ans=0;
    ll n,t=0;
    cin>>n;
    int a[n];
    for(int &i:a) cin>>i,sm=(sm+i)%mod;
    for(int i=0;i<n;i++){
        t=(t+a[i])%mod;
        ans=(ans + ((sm-t+mod)%mod)*a[i]%mod )%mod;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
