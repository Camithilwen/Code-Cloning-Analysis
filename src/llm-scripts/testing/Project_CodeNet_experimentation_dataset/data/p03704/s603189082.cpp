#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, pw10[19], nDig, ans;

bool ok(int a, int b, int mod) { return ( ( (a % mod) + mod) % mod) == ( ( (b % mod) + mod) % mod); }

int bt(int pos, int d) {
    int ret = 0;
    if(pos == nDig / 2 + 1) {
        return (d == 0) * (nDig % 2 ? 10 : 1);
    }
    for (int sub = -9; sub < 10; ++ sub) {
        if( ok(d, sub * 9 * pw10[pos - 1], 9 * pw10[pos]) ) {
            d -= sub * (pw10[nDig - pos] - pw10[pos - 1]);
            int temp = 10 - abs(sub);
            if(pos == 1) temp --;
            ret += bt(pos + 1, d) * temp;
            d += sub * (pw10[nDig - pos] - pw10[pos - 1]);
        }
    }
    return ret;
}

signed main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    pw10[0] = 1; for (int i = 1; i < 19; ++i) pw10[i] = 10 * pw10[i - 1];
    for (int i = 1; i <= 18; ++i) nDig = i, ans += bt(1, n);

    cout << ans;

    return 0;
}
