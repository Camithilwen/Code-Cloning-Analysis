#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 + 100, INF = 1e9 * 1e4 + 10, MOD = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, a, b, c, d, dp[SIZE][30], lf, q;
vector<ll> vec;
map<ll, ll> ch;

ll check(int val, int pos) {
    if (val == 0) return pos;

    ll lft = val, u = pos;
    for (ll i = 29; i >= 0; i--) {
        if (lft - (1ll << i) >= 0) {
            u = dp[u][i];
            lft -= (1ll << i);
        }
    }

    return u;
}
void sol() {
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    cin >> lf;

    cin >> q;

    for (int i = 29; i >= 0; i--) {
        dp[n - 1][i] = n - 1;
    }
    for (int i = vec.size() - 2; i >= 0; i--) {
        int l = i, r = vec.size();

        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (vec[i] + lf < vec[mid]) {
                r = mid;
            }
            else {
                l = mid;
            }
        }

        dp[i][0] = l;
        for (int j = 1; j < 30; j++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    
    while (q--) {
        ll lq, rq;
        cin >> lq >> rq;
        if (lq > rq) swap(lq, rq);

        if (lq == rq) {
            cout << "0\n";
            continue;
        }

        lq--;
        rq--;
        ll dist = 0, cur = lq, curR = rq;

        int l = 0, r = vec.size() + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid, cur) >= curR) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        cout << r << "\n";
    }
}

int main()
{
    fastInp;

    ll t = 1;

    while (t--) {
        sol();
    }

    return 0;
}