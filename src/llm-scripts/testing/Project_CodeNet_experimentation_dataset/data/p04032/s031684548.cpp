#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rep1(i, n) for (int i = 1; i < int(n); ++i)
#define repx(i, x, n) for (int i = int(x); i < int(n); ++i)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define ALL(n) begin(n), end(n)
#define IN(a, x, b) ((a) <= (x) && (x) < (b))
#define OUT(a, x, b) ((x) < (a) || (x) < (b))
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const ll MOD = 1000000007;

int main()
{
    string s;
    cin >> s;

    rep(i, s.length() - 1)
    {
        if (s[i] == s[i + 1])
        {
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }
        if (i < s.length() - 1 && s[i] == s[i + 2])
        {
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;

    return 0;
}
