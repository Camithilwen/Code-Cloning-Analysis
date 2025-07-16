#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;




int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    set<ll>st;
    map<ll,ll>mp;
    rep(i,n){
        mp[a[i]]++;
        st.insert(a[i]);
    }
    ll ans = 0;
    for(ll i=40;i>=0;i--){
        ll now = pow(2,i);
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second<=0)continue;
            ll f = itr->first;
            ll s = itr->second;
            if(f*2==now){
                while(s>1){//同一の数字のペア
                    ans++;
                    s-=2;
                    itr->second-=2;
                }
                continue;
            }
            ll x = now - f;
            if(!x>0)continue;
            if(st.find(x)==st.end())continue;
            if(mp[x]>0){
                ll c = min(s,mp[x]);
                ans += c;
                mp[x]-=c;
                itr->second-=c;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
