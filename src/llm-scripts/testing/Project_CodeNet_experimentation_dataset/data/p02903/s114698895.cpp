#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    rep(i, b)
    {
        rep(j, a) cout << 0;
        for (int j = a; j < w; j++)
            cout << 1;
        cout << endl;
    }
    for (int i = b; i < h; i++)
    {
        rep(j, a) cout << 1;
        for (int j = a; j < w; j++)
            cout << 0;
        cout << endl;
    }
}