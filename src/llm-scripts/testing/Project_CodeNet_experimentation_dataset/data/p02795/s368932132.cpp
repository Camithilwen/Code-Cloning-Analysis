#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int h, w, n;
    cin >> h >> w >> n;
    int longer = max(h, w);
    if (n % longer == 0)
        cout << (n / longer) << endl;
    else
        cout << (n / longer + 1) << endl;
}