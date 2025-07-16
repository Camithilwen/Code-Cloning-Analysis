#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int m;
ll d[200001], c[200001];
ll digitsum(ll n) {
    ll res = 0;
    while (n != 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
int main() {
    cin >> m;
    rep(i, m) { cin >> d[i] >> c[i]; }
    ll sum = 0;
    ll dignum = 0;
    rep(i, m) {
        dignum += c[i];
        sum += d[i] * c[i];
    }
    cout << dignum - 1 + (sum - 1) / 9 << endl;
    return 0;
}