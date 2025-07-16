#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    int maxL, minR;
    maxL = -1e9;
    minR = 1e9;
    rep(i, m)
    {
        int l, r;
        cin >> l >> r;
        minR = min(minR, r);
        maxL = max(maxL, l);
        // printf("%d %d\n", minR, maxL);
    }
    cout << max(0, minR - maxL + 1) << endl;
    return 0;
}