#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<P> c(n);
    
    REP(i, n) cin >> a[i] >> b[i];
    REP(i, n) {
        c[i].first = a[i] + b[i];
        c[i].second = i;
    }
    sort(ALL(c));
    reverse(ALL(c));

    ll aoki = 0, takahashi = 0;
    REP(i, n) {
        if(i % 2 == 0) {
            aoki += a[c[i].second];
        } else {
            takahashi += b[c[i].second];
        }
    }

    cout << aoki - takahashi << endl;

    return 0;
}