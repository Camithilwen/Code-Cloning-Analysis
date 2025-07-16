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

// 約数列挙
vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
            }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> div = divisor(m);

    ll ans = 1;

    for(auto v : div){
        ll k = m / v;
        if (k >= n) ans = max(ans, v);
    }

    cout << ans << endl;

    return 0;
}
