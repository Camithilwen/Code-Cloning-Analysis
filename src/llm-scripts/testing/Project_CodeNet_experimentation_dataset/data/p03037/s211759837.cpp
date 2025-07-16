#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll maL = -1;
    ll miR = n + 10;
    rep(i, m)
    {
        ll l, r;
        cin >> l >> r;
        maL = max(maL, l);
        miR = min(miR, r);
    }

    ll ans = max((ll)0, miR - maL + 1);
    cout << ans << endl;
}