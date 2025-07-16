#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll D, G, p[20], c[20];

ll solve(ll st){
    ll sum = 0, cnt = 0;
    REP(i, D){
        if(st & (1 << i)){
            sum += p[i] * 100 * (i + 1) + c[i];
            cnt += p[i];
        }
    }
    while(sum < G){
        for(int i = D - 1; i >= 0; i--){
            if(st & (1 << i)) continue;
            ll d = (G - sum + 100 * (i + 1) - 1) / (100 * (i + 1));
            if(d <= p[i]){
                cnt += d;
                return cnt;
            }
            cnt += p[i];
            sum += p[i] * 100 * (i + 1);
        }
    }
    return cnt;
}

signed main(){
    cin >> D >> G;
    REP(i, D) cin >> p[i] >> c[i];
    ll ans = INT64_MAX;
    REP(i, 1 << D){
        ans = min(ans, solve(i));
    }
    PRINT(ans);
    return 0;
}