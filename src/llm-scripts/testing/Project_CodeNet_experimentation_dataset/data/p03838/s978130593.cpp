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


int main(){
    ll X, Y;
    cin >> X >> Y;
    ll cnt = LINF;
    rep(i, 2) rep(j, 2){
        ll x = X, y = Y;
        ll tmp = 0;
        if (i) x *= -1, tmp++;
        if (j) y *= -1, tmp++;
        if (x <= y) {
            tmp += y - x;
            cnt = min(cnt, tmp);
        }
    }

    cout << cnt << endl;

    return 0;
}
