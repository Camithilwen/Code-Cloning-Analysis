#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int digit(ll i)
{
    ll r = i;
    int ret = 0;
    while (r != 0)
    {
        r /= 10;
        ret++;
    }
    return ret;
}

int main()
{
    ll N;
    cin >> N;
    int ans = INT32_MAX;
    for (ll i = 1; i <= sqrt(N); i++)
    {
        int f = INT32_MAX;
        if (N == N / i * i)
        {
            f = max(digit(i), digit(N / i));
        }
        ans = min(ans, f);
    }

    cout << ans << endl;

    return 0;
}