#include <bits/stdc++.h>


using namespace std;
using ll = long long;
const int INF = 1000000009;
const ll LINF = 1e18;

int cal_digit(ll n) {
    int rtn = 0;
    while (n) {
        ++rtn;
        n /= 10;
    }
    return rtn;
}

int main() {
    ll n;
    cin >> n;
    int rtn = INF;
    for (ll a = 1; a * a <= n; ++a) {
        if (n % a == 0) {
            ll b = n / a;
            int t_dig = max(cal_digit(a), cal_digit(b));
            rtn = min(rtn, t_dig);
        }
    }
    cout << rtn << endl;
}
