#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

void doit(){
    ll n,i,k,j;
    cin >> n;
    vector< ll >v(n);
    for(i = 0; i < n; i++)cin>>v[i];
    vector<pii>answer(61,{0,0});
    rep(i,0,n){
        rep(j,0,61){
            if(v[i] & (1LL << j) )answer[j].ff++;
            else answer[j].ss++;
        }
    }
    ll ans = 0,mod = 1e9+7;
    rep(i,0,61){
        ll k1 = (answer[i].ff * answer[i].ss)%mod ;
        ll k2 = (1LL << i)%mod;
        k1 = (k1*k2)%mod;
        ans = ((ans % mod) + (k1 % mod)) % mod;
    }
    cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
