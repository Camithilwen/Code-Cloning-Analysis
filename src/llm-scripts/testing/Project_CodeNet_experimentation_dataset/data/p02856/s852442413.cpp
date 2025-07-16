#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


ll c[200010], d[200010];
int main(){
    int m;
    cin >> m;
    rep(i, m) cin >> d[i] >> c[i];

    ll tot = 0, digit = 0;
    rep(i, m) {
        tot += d[i] * c[i];
        digit += c[i];
    }

    cout << digit - 1 + (tot - 1) / 9 << endl;

    return 0;
}
