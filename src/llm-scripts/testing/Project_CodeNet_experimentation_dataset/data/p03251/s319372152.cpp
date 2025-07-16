#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int mx = -101;
    int my = 101;
    rep(i, n) {
        int x1;
        cin >> x1;
        mx = max(mx, x1);
    }
    rep(i, m) {
        int y1;
        cin >> y1;
        my = min(my, y1);
    }
    if(mx >= y || my <= x) cout << "War" << endl;
    else if(mx < my) cout << "No War" << endl;
    else cout << "War" << endl;
    return 0;
}