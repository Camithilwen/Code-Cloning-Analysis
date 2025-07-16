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
    int n, y;
    cin >> n >> y;
    rep(i, n + 1)
    {
        rep(j, n + 1)
        {
            if (i + j + (y / 1000 - 10 * i - 5 * j) == n && (y / 1000 - 10 * i - 5 * j) >= 0)
            {
                printf("%d %d %d\n", i, j, y / 1000 - 10 * i - 5 * j);
                return (0);
            }
        }
    }

    printf("-1 -1 -1\n");
    return (0);
}
