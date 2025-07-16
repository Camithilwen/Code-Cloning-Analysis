#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rep1(i, n) for (int i = 1; i < int(n); ++i)
#define repx(i, x, n) for (int i = int(x); i < int(n); ++i)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define ALL(n) begin(n), end(n)
#define IN(a, x, b) ((a) <= (x) && (x) < (b))
#define OUT(a, x, b) ((x) < (a) || (x) < (b))
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const ll MOD = 1000000007;

const ll MAX = 1e9 + 10;

int main()
{
    ll N, A, B, thr, pre, now;
    cin >> N >> A >> B;
    thr = ll(B / A);
    ll ans = 0;

    cin >> pre;
    rep1(i, N)
    {
        cin >> now;
        if (now - pre > thr)
        {
            ans += B;
            // cout << "+B" << endl;
        }
        else
        {
            ans += A * (now - pre);
            // cout << "+" << A * (now - pre) << endl;
        }
        pre = now;
    }

    cout << ans << endl;

    return 0;
}
