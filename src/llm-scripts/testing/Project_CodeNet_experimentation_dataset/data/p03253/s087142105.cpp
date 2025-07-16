#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

const int MAX = 510'000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

vector<pair<ll, ll>>
factorization(ll num)
{
    map<ll, ll> mp;

    ll tmp = num;
    for (ll i = 2; i * i <= num; i++)
    {
        while (tmp % i == 0)
        {
            mp[i]++;
            tmp /= i;
        }
    }
    if (tmp != 1)
    {
        mp[num]++;
    }
    vector<pair<ll, ll>> ret;
    for (auto m : mp)
    {
        ret.push_back(make_pair(m.first, m.second));
    }
    return ret;
}

int main()
{
    COMinit();
    int n, m;
    cin >> n >> m;

    auto fac = factorization(m);
    ll ans = 1;
    for (int i = 0; i < fac.size(); i++)
    {
        int tmp = fac[i].second;
        ans = (ans * COM(n + tmp - 1, tmp)) % MOD;
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
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
