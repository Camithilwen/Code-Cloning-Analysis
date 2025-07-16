#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, q;
    cin >> n >> q;

    char s[n];
    ll rui[n+1] = {};
    rep(i, n){
        cin >> s[i];
        if(i == 0)continue;

        rui[i+1] = rui[i];
        if(s[i] == 'C' && s[i-1] == 'A')rui[i+1]++;
    }

    rep(i, q){
        ll l, r;
        cin >> l >> r;

        cout << rui[r] - rui[l] << endl;
    }
}