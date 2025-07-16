#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

int main(){
    int N; cin >> N;
    ll m = INF;
    int count = 0;
    ll res = 0ll;

    rp(i, 0, N) {
        ll a; cin >> a;
        if(a < 0) count ++;
        a = abs(a);
        chmin(m, a);
        res += a;
    }
    if(count % 2) res -= 2 * m;
    cout << res << endl;
    return 0;
}