#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n), y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];
    int mx = *max_element(x.begin(), x.end());
    int mn = *min_element(y.begin(), y.end());
    string ans = "War";
    for (int z = -99; z <= 100; z++)
    {
        if (X < z && z <= Y && mx < z && z <= mn)
            ans = "No War";
    }
    cout << ans << endl;
}
