
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    {
        ull b = n;
        if (d != 0) {
            b = d;
            b += max(0LL, 2 * (n - d - (d + 1 - 1) ));
            b += n - max(d, (n - d + 1 - 1));
        }
        b *= m - 1;
        double ans = (double)b / n / n;
        cout << fixed << setprecision(10);
        cout << ans << endl;
    }
    return 0;
}
