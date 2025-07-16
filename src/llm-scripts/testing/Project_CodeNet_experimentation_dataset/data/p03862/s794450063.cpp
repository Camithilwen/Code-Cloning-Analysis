#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, x;
    cin >> N >> x;
    vector<ll> a(N);
    rep(i, N) { cin >> a[i]; }

    ll cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (a[i] + a[i + 1] > x) {
            int diff = a[i] + a[i + 1] - x;
            if (diff > a[i + 1])
                cnt += a[i + 1], a[i + 1] = 0;
            else
                cnt += diff, a[i + 1] -= diff;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        if (a[i] + a[i + 1] > x) {
            int diff = a[i] + a[i + 1] - x;
            a[i] -= diff, cnt += diff;
        }
    }

    cout << cnt << endl;
}