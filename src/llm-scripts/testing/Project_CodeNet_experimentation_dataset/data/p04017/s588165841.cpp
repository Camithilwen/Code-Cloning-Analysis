#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

const ll inf = 1e18;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vll x(n);
    REP(i, n) cin >> x[i];
    ll l;
    cin >> l;

    // reach[k][i] : i から出発して 2^k 日で到達できる一番遠いホテル
    vvll reach(31, vll(n));

    REP(i, n){
        ll nxt = upper_bound(ALL(x), x[i] + l) - x.begin() - 1;
        reach[0][i] = nxt;
    }
    REP(k, 30){
        REP(i, n){
            reach[k + 1][i] = reach[k][reach[k][i]];
        }
    }
    ll q;
    cin >> q;
    ll a, b;
    while (q) {
        cin >> a >> b;
        a--, b--;
        if (a > b) swap(a, b);
        ll res = 1;
        REPR(k, 30){
            if (reach[k][a] < b) {
                res += (1 << k);
                a = reach[k][a];
            }
        }
        cout << res << endl;
        q--;
    }
    return 0;
}