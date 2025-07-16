#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<int> cs(60, 0); // 立っているビットの個数を記録する
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        bitset<60> bs(a);
        for (int j = 0; j < 60; j++)
        {
            if (bs.test(j))
            {
                ++cs[j];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 60; i++)
    {
        ll tmp = pow(2, i);
        tmp %= MOD;
        tmp *= cs[i];
        tmp %= MOD;
        tmp *= (n - cs[i]);
        tmp %= MOD;
        ans += tmp;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
};