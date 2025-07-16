#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> l(2 * n);
    rep(i, 2 * n) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    int ans = 0;
    for(int i = 0; i < 2 * n; i += 2) {
        ans += l[i];
    }
    cout << ans << endl;
    return 0;
}
