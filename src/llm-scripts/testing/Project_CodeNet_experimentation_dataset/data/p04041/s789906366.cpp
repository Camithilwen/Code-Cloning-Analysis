#include "bits/stdc++.h"

using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

template <typename T>
T mypow(T a, T b)
{
    if (b == 0)
        return 1;
    T tmp = mypow(a, b / 2);
    if (b % 2)
        return (((tmp * tmp) % MOD) * a) % MOD;
    else
        return (tmp * tmp) % MOD;
}

int n, x, y, z;

// v が x y z となっているか
bool check(const vector<int> &v)
{
    int sz = v.size();
    if (sz < 3)
        return false;
    vector<int> sum(sz + 1, 0);
    for (int i = 0; i < sz; i++)
    {
        sum[i + 1] = sum[i] + v[i];
    }
    bool f = false;
    for (int k = 0; k <= sz - 3; k++)
    {
        for (int i = k + 1; i <= sz - 2; i++)
        {
            for (int j = i + 1; j <= sz - 1; j++)
            {
                if (sum[i] - sum[k] == x && sum[j] - sum[i] == y && sum[sz] - sum[j] == z)
                    f = true;
            }
        }
    }
    return f;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> x >> y >> z;
    int sum = x + y + z;
    // dp[i][j] := i 番目迄見て, 直近(の符号)が j であり, 575 を含まないものの数
    vector<vector<ll>> dp(n + 1, vector<ll>(1 << sum, 0));
    // valid[i][j] := 直近が i の時に j を置けるか
    vector<vector<int>> valid(1 << sum, vector<int>(11, 0));
    for (int i = 0; i < (1 << sum); i++)
    {
        vector<int> num;
        int v = 0;
        for (int j = sum - 1; j >= 0; j--)
        {
            if ((i >> j) & 1)
            {
                if (v)
                    num.push_back(v);
                v = 1;
            }
            else
            {
                if (v)
                    v++;
            }
        }
        if (v)
            num.push_back(v);
        for (int j = 1; j <= 10; j++)
        {
            vector<int> num2 = num;
            num2.emplace_back(j);
            valid[i][j] = !check(num2);
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << sum); j++)
        {
            for (int k = 1; k <= 10; k++)
            {
                if (!valid[j][k])
                    continue;
                int mask = ((((j << k) & ((1 << sum) - 1)) | (1 << (k - 1)))) & ((1 << sum) - 1);
                dp[i + 1][mask] += dp[i][j];
                dp[i + 1][mask] %= MOD;
            }
        }
    }
    ll ret = 0;
    for (int i = 0; i < (1 << sum); i++)
        ret = (ret + dp[n][i]) % MOD;
    cout << (mypow((ll)10, (ll)n) + MOD - ret) % MOD << endl;
}
