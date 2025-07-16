// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
// using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
const int mod = 1e9 + 7;
// --------------------------------------------------------------------------------
void solve()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0;; i++)
    {
        if (b == 1)
        {
            cout << 0 << endl;
            break;
        }
        if (b <= a * (i + 1) - i)
        {
            cout << i + 1 << endl;
            break;
        }
    }
}
// --------------------------------------------------------------------------------
int main()
{
    // srand((unsigned)time(NULL));
    // int bt = clock();
    solve();
    // double et = 1.0 * (clock() - bt) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}