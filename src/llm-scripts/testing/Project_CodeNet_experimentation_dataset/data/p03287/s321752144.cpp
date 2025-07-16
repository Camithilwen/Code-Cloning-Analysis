#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), sum(N + 1, 0);
    rep(i, N) { cin >> A[i]; }

    map<ll, ll> cnt;
    ll ans = 0;
    rep(i, N) { sum[i + 1] = sum[i] + A[i]; }

    rep(i, N + 1) { cnt[sum[i] % M]++; }

    for (auto c : cnt) {
        ans += (c.second * (c.second - 1)) / 2;
    }

    cout << ans << endl;
}