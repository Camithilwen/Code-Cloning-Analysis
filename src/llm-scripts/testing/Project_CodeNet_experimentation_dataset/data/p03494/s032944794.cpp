#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    int res = 1001001001;
    int cnt;
    rep(i, n)
    {
        cnt = 0;
        while (v[i] % 2 == 0)
        {
            cnt++;
            v[i] /= 2;
        }
        res = min(res, cnt);
    }

    cout << res << endl;
    return (0);
}
