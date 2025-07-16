#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), per(n);
    rep(i, n) cin >> x[i] >> y[i];

    rep(i, n) per[i] = i;
    double ans = 0;
    int cnt = 0;
    do
    {
        cnt++;
        rep(i, n - 1)
        {
            ans += sqrt(pow(x[per[i + 1]] - x[per[i]], 2.0) + pow(y[per[i + 1]] - y[per[i]], 2.0));
        }

    } while (next_permutation(all(per)));

    printf("%6lf\n", ans / cnt);
    return 0;
}
