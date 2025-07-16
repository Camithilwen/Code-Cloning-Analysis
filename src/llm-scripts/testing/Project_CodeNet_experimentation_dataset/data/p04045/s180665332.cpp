#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, K, D[10];

bool check(ll x){
    while(x > 0){
        ll d = x % 10;
        REP(i, K){
            if(d == D[i]) return false;
        }
        x /= 10;
    }
    return true;
}

signed main(){
    cin >> N >> K;
    REP(i, K) cin >> D[i];
    ll ans = N;
    while(true){
        if(check(ans)) break;
        ans++;
    }
    PRINT(ans);
    return 0;
}