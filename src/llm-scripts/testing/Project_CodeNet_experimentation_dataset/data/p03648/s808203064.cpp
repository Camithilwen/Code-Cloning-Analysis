#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll k; cin >> k;
    ll m = k % 50;
    cout << 50 << '\n';
    vector<ll> a(50, k / 50 + 49 - m);
    for (int i = 0; i < m; i++) a[i] += 51;
    for (int i = 0; i < 50; i++) cout << a[i] << " \n"[i == 49];
    return 0;
}
