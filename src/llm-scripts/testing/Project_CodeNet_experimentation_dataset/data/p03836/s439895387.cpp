#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string L;
    string R;
    rep(i, tx - sx)
    {
        L += 'L';
        R += 'R';
    }

    string U;
    string D;
    rep(i, ty - sy)
    {
        U += 'U';
        D += 'D';
    }

    string ans = R + U + L + D + 'D' + R + 'R' + U + 'U' + 'L' + 'U' + L + 'L' + D + 'D' + 'R';

    cout << ans << endl;

    return 0;
}