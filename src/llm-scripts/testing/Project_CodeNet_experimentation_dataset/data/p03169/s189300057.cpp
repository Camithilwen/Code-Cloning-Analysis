#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pb push_back
#define F first
#define S second
const int A = 3e2 + 2;
const int mod = 1e9 + 7;
int n;
bool vis[A][A][A];
ld mem[A][A][A];
ld solve (int c1, int c2, int c3) {
    if (c1 + c2 + c3 == 0) return 0;
    if (vis[c1][c2][c3])
        return mem[c1][c2][c3];
    vis[c1][c2][c3] = 1;
    int c0 = n - (c1 + c2 + c3);
    ld ret = 1;
    if (c1)
        ret += solve(c1 - 1, c2, c3) * (c1 / (n * 1.0));
    if (c2)
        ret += solve(c1 + 1, c2 - 1, c3) * (c2 / (n * 1.0));
    if (c3)
        ret += solve(c1, c2 + 1, c3 - 1) * (c3 / (n * 1.0));
    ret /= (1 - (c0 / (n * 1.0)));
    return mem[c1][c2][c3] = ret;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int freq[4] = {};
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        freq[x]++;
    }
    cout << setprecision(9) << fixed << solve(freq[1], freq[2], freq[3]);
    return 0;
}