#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int f(int n)
{
    return ((n & 1) ? 3 * n + 1 : n / 2);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1), y(m + 1);
    cin >> x[0] >> y[0];
    rep2(i, 1, n + 1) cin >> x[i];
    rep2(i, 1, m + 1) cin >> y[i];

    sort(all(x));
    sort(all(y));

    cout << ((x[n] < y[0]) ? "No War" : "War") << '\n';
    return 0;
}
