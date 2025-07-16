#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
bool chmin(ll & a, ll  b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll & a, ll b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N=500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main() {
    cin>>n;
    vl beki;
    multiset<ll> A;
    beki.push_back(1);
    rep(i,40){
        beki.push_back(beki.back()*2);
    }
    rep(i,n){
        cin>>x;
        A.insert(x);
    }

    while(!A.empty()){
        auto ite=A.end();
        ite--;
        x=*ite;
      	A.erase(ite);
        k=upper_bound(all(beki),x*2)-beki.begin()-1;
        if(!A.empty()&&A.count(beki[k]-x)>0){
            auto ite2=A.lower_bound(beki[k]-x);
            A.erase(ite2);
            ans++;
        }
    }
    cout<<ans<<endl;
}
